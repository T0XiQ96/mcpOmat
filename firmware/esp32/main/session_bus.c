#include "session_bus.h"

#include "esp_log.h"
#include "transport_rs485.h"

static const char *TAG = "session_bus";

void session_bus_init()
{
    transport_rs485_init(250000);
}

void session_bus_broadcast_state(uint8_t state, bool joker_enabled)
{
    uint8_t payload[2] = {state, (uint8_t)(joker_enabled ? 1 : 0)};
    transport_rs485_send(0x10, payload, sizeof(payload));
}

void session_bus_poll()
{
    uint8_t buffer[64];
    int len = transport_rs485_receive(buffer, sizeof(buffer), pdMS_TO_TICKS(5));
    if (len > 0) {
        ESP_LOGI(TAG, "Received %d bytes", len);
        // TODO: parse frames and notify UI/state machine
    }
}
