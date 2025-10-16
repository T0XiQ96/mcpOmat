#include "encoder_manager.h"

#include "session_controller.h"

void encoder_manager_begin()
{
    // TODO: configure hardware encoders
}

void encoder_manager_tick()
{
    // poll hardware
}

void encoder_manager_process_turn(uint8_t encoder_id, int delta)
{
    if (encoder_id != 1) {
        if (session_controller_state() != SessionState::Running) {
            return;
        }
    }
    session_controller_on_encoder_turn(delta);
}

void encoder_manager_process_click(uint8_t encoder_id)
{
    if (encoder_id != 1) {
        if (session_controller_state() != SessionState::Running) {
            return;
        }
    }
    session_controller_on_encoder_click();
}
