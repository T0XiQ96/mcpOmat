#pragma once

#include <stdbool.h>
#include <stdint.h>

void session_bus_init();
void session_bus_broadcast_state(uint8_t state, bool joker_enabled);
void session_bus_poll();
