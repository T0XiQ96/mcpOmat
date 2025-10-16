#pragma once

#include <Arduino.h>

void encoder_manager_begin();
void encoder_manager_tick();
void encoder_manager_process_turn(uint8_t encoder_id, int delta);
void encoder_manager_process_click(uint8_t encoder_id);
