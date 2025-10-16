#pragma once

#include <Arduino.h>

enum class SessionState {
    Idle,
    Configuring,
    Armed,
    Running,
    Completed
};

void session_controller_begin();
void session_controller_tick();
void session_controller_on_encoder_turn(int delta);
void session_controller_on_encoder_click();
SessionState session_controller_state();
