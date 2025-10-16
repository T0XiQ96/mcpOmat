#pragma once

#include <Arduino.h>

void transport_rs485_begin(uint32_t baud);
void transport_rs485_poll();
void transport_rs485_send(uint8_t msg_type, const uint8_t *payload, size_t length);
