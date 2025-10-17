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
    rs485_frame_t frame;
    if (transport_rs485_receive(&frame, pdMS_TO_TICKS(5))) {
        ESP_LOGD(TAG, "Received frame type=0x%02X len=%u", frame.msg_type, frame.length);
        // TODO: decode payload and feed session state
        while (transport_rs485_receive(&frame, 0)) {
            ESP_LOGD(TAG, "Received frame type=0x%02X len=%u", frame.msg_type, frame.length);
            // TODO: decode payload and feed session state
        }
    }
}
