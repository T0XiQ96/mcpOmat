#include "session_commands.h"

#include "session_controller.h"
#include "transport_rs485.h"

void session_commands_send_config()
{
    uint8_t payload[2] = {
        static_cast<uint8_t>(session_controller_state()),
        0 // placeholder for flags (joker, etc.)
    };
    transport_rs485_send(0x10, payload, sizeof(payload));
}

void session_commands_process()
{
    Rs485Frame frame;
    while (transport_rs485_pop(frame)) {
        (void)frame;
        // TODO: parse incoming frames and forward to controller as needed
    }
}
