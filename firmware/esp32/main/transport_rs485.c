#include "transport_rs485.h"

#include <limits.h>
#include <string.h>

#include "driver/gpio.h"
#include "driver/uart.h"
#include "esp_log.h"
#include "freertos/task.h"

static const char *TAG = "transport_rs485";

#define RS485_UART_NUM UART_NUM_1
#define RS485_TXD_PIN GPIO_NUM_17
#define RS485_RXD_PIN GPIO_NUM_16
#define RS485_DE_PIN GPIO_NUM_18

typedef enum {
    RX_STATE_WAIT_SYNC = 0,
    RX_STATE_MSG_TYPE,
    RX_STATE_LENGTH,
    RX_STATE_PAYLOAD,
    RX_STATE_CRC,
} rx_state_t;

typedef struct {
    rx_state_t state;
    uint8_t msg_type;
    uint8_t length;
    uint8_t index;
    uint8_t payload[RS485_MAX_PAYLOAD];
} rx_context_t;

static rx_context_t rx_ctx = {
    .state = RX_STATE_WAIT_SYNC,
    .msg_type = 0,
    .length = 0,
    .index = 0,
    .payload = {0},
};

static inline uint8_t crc8_step(uint8_t crc, uint8_t data)
{
    crc ^= data;
    for (int bit = 0; bit < 8; ++bit) {
        if ((crc & 0x01U) != 0U) {
            crc = (crc >> 1) ^ 0x8CU;
        } else {
            crc >>= 1;
        }
    }
    return crc;
}

static uint8_t crc8_update(uint8_t crc, const uint8_t *data, size_t length)
{
    for (size_t i = 0; i < length; ++i) {
        crc = crc8_step(crc, data[i]);
    }
    return crc;
}

static void configure_uart(uint32_t baud)
{
    uart_config_t uart_config = {
        .baud_rate = (int)baud,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };
    ESP_ERROR_CHECK(uart_driver_install(RS485_UART_NUM, 1024, 1024, 0, NULL, 0));
    ESP_ERROR_CHECK(uart_param_config(RS485_UART_NUM, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(RS485_UART_NUM, RS485_TXD_PIN, RS485_RXD_PIN, RS485_DE_PIN, UART_PIN_NO_CHANGE));
    ESP_ERROR_CHECK(uart_set_mode(RS485_UART_NUM, UART_MODE_RS485_HALF_DUPLEX));
    ESP_ERROR_CHECK(gpio_set_direction(RS485_DE_PIN, GPIO_MODE_OUTPUT));
}

static inline void set_transmit(bool enable)
{
    gpio_set_level(RS485_DE_PIN, enable ? 1 : 0);
}

static bool uart_write_all(const void *data, size_t length)
{
    int written = uart_write_bytes(RS485_UART_NUM, (const char *)data, length);
    if (written < 0 || (size_t)written != length) {
        ESP_LOGE(TAG, "UART write failed (len=%u, written=%d)", (unsigned)length, written);
        return false;
    }
    return true;
}

static inline void rx_reset(bool synced)
{
    rx_ctx.state = synced ? RX_STATE_MSG_TYPE : RX_STATE_WAIT_SYNC;
    rx_ctx.msg_type = 0;
    rx_ctx.length = 0;
    rx_ctx.index = 0;
}

void transport_rs485_init(uint32_t baud)
{
    configure_uart(baud);
    rx_reset(false);
    set_transmit(false);
    ESP_LOGI(TAG, "RS485 initialized at %u baud", (unsigned)baud);
}

void transport_rs485_send(uint8_t msg_type, const uint8_t *payload, size_t length)
{
    if (length > RS485_MAX_PAYLOAD || length > UINT8_MAX) {
        ESP_LOGE(TAG, "Payload too large: %u bytes (max=%u)", (unsigned)length, (unsigned)RS485_MAX_PAYLOAD);
        return;
    }
    if (length > 0 && payload == NULL) {
        ESP_LOGE(TAG, "Payload pointer is NULL for length %u", (unsigned)length);
        return;
    }

    uint8_t len8 = (uint8_t)length;
    uint8_t crc = 0;
    crc = crc8_step(crc, msg_type);
    crc = crc8_step(crc, len8);
    if (length > 0) {
        crc = crc8_update(crc, payload, length);
    }

    uint8_t header[3] = {RS485_SYNC_BYTE, msg_type, len8};

    set_transmit(true);
    bool ok = uart_write_all(header, sizeof(header));
    if (ok && length > 0) {
        ok = uart_write_all(payload, length);
    }
    if (ok) {
        ok = uart_write_all(&crc, 1);
    }
    if (!ok) {
        set_transmit(false);
        return;
    }
    ESP_ERROR_CHECK(uart_wait_tx_done(RS485_UART_NUM, pdMS_TO_TICKS(20)));
    set_transmit(false);
    ESP_LOGD(TAG, "TX frame type=0x%02X len=%u crc=0x%02X", msg_type, (unsigned)length, crc);
}

bool transport_rs485_receive(rs485_frame_t *frame, TickType_t timeout_ticks)
{
    if (frame == NULL) {
        return false;
    }

    TickType_t start = xTaskGetTickCount();
    TickType_t remaining = timeout_ticks;

    while (true) {
        uint8_t byte = 0;
        TickType_t wait = (timeout_ticks == portMAX_DELAY) ? portMAX_DELAY : remaining;
        int read = uart_read_bytes(RS485_UART_NUM, &byte, 1, wait);
        if (read <= 0) {
            return false;
        }

        switch (rx_ctx.state) {
        case RX_STATE_WAIT_SYNC:
            if (byte == RS485_SYNC_BYTE) {
                rx_reset(true);
            }
            break;

        case RX_STATE_MSG_TYPE:
            rx_ctx.msg_type = byte;
            rx_ctx.state = RX_STATE_LENGTH;
            break;

        case RX_STATE_LENGTH:
            rx_ctx.length = byte;
            if (rx_ctx.length > RS485_MAX_PAYLOAD) {
                ESP_LOGW(TAG, "Dropping frame: payload length %u exceeds max %u", rx_ctx.length, RS485_MAX_PAYLOAD);
                rx_reset(false);
            } else if (rx_ctx.length == 0) {
                rx_ctx.state = RX_STATE_CRC;
            } else {
                rx_ctx.index = 0;
                rx_ctx.state = RX_STATE_PAYLOAD;
            }
            break;

        case RX_STATE_PAYLOAD:
            rx_ctx.payload[rx_ctx.index++] = byte;
            if (rx_ctx.index >= rx_ctx.length) {
                rx_ctx.state = RX_STATE_CRC;
            }
            break;

        case RX_STATE_CRC: {
            uint8_t crc = 0;
            crc = crc8_step(crc, rx_ctx.msg_type);
            crc = crc8_step(crc, rx_ctx.length);
            if (rx_ctx.length > 0) {
                crc = crc8_update(crc, rx_ctx.payload, rx_ctx.length);
            }
            bool crc_ok = (crc == byte);
            bool byte_is_sync = (byte == RS485_SYNC_BYTE);

            if (crc_ok) {
                frame->msg_type = rx_ctx.msg_type;
                frame->length = rx_ctx.length;
                if (rx_ctx.length > 0) {
                    memcpy(frame->payload, rx_ctx.payload, rx_ctx.length);
                }
                ESP_LOGD(TAG, "RX frame type=0x%02X len=%u crc=0x%02X", frame->msg_type, frame->length, crc);
                rx_reset(false);
                return true;
            }

            ESP_LOGW(TAG, "CRC mismatch: expected 0x%02X, got 0x%02X (type=0x%02X len=%u)",
                     crc, byte, rx_ctx.msg_type, rx_ctx.length);
            rx_reset(byte_is_sync);
            break;
        }
        }

        if (timeout_ticks != portMAX_DELAY) {
            TickType_t now = xTaskGetTickCount();
            TickType_t elapsed = now - start;
            if (elapsed >= timeout_ticks) {
                return false;
            }
            remaining = timeout_ticks - elapsed;
        }
    }
}
