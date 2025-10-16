#include "transport_rs485.h"

#include "driver/gpio.h"
#include "driver/uart.h"
#include "esp_log.h"

static const char *TAG = "transport_rs485";

#define RS485_UART_NUM UART_NUM_1
#define RS485_TXD_PIN GPIO_NUM_17
#define RS485_RXD_PIN GPIO_NUM_16
#define RS485_DE_PIN GPIO_NUM_18

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
}

void transport_rs485_init(uint32_t baud)
{
    configure_uart(baud);
    gpio_set_level(RS485_DE_PIN, 0); // receive mode default
    ESP_LOGI(TAG, "RS485 initialized at %u baud", (unsigned)baud);
}

void transport_rs485_send(uint8_t msg_type, const uint8_t *payload, size_t length)
{
    uint8_t header[3] = {0xAA, msg_type, (uint8_t)length};
    uint8_t crc = msg_type ^ (uint8_t)length;
    for (size_t i = 0; i < length; ++i) {
        crc ^= payload[i];
    }
    uart_write_bytes(RS485_UART_NUM, (const char *)header, sizeof(header));
    if (length > 0) {
        uart_write_bytes(RS485_UART_NUM, (const char *)payload, length);
    }
    uart_write_bytes(RS485_UART_NUM, (const char *)&crc, 1);
}

int transport_rs485_receive(uint8_t *buffer, size_t max_len, TickType_t timeout_ticks)
{
    int total = uart_read_bytes(RS485_UART_NUM, buffer, max_len, timeout_ticks);
    return total;
}
