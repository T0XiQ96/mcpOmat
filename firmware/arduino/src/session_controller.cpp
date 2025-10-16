#include "session_controller.h"

#include "storage_eeprom.h"
#include "transport_rs485.h"

#include <Arduino.h>

static SessionState state = SessionState::Idle;
static uint8_t selected_players = 2;
static bool joker_enabled = false;

static void broadcast_state()
{
    uint8_t payload[2] = {selected_players, static_cast<uint8_t>(joker_enabled)};
    transport_rs485_send(0x01, payload, sizeof(payload));
}

void session_controller_begin()
{
    storage_eeprom_begin();
    // TODO: load persisted config
    state = SessionState::Configuring;
    broadcast_state();
}

void session_controller_tick()
{
    // Future: poll RS485, handle timeouts
}

void session_controller_on_encoder_turn(int delta)
{
    if (state != SessionState::Configuring) {
        return;
    }
    selected_players = constrain<uint8_t>(selected_players + delta, 2, 6);
    broadcast_state();
}

void session_controller_on_encoder_click()
{
    switch (state) {
    case SessionState::Configuring:
        state = SessionState::Armed;
        broadcast_state();
        break;
    case SessionState::Armed:
        state = SessionState::Running;
        broadcast_state();
        break;
    case SessionState::Running:
        state = SessionState::Completed;
        broadcast_state();
        break;
    default:
        break;
    }
}

SessionState session_controller_state()
{
    return state;
}
