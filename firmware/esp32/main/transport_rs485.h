#pragma once

#include <stdint.h>
#include <stddef.h>

#include "freertos/FreeRTOS.h"

void transport_rs485_init(uint32_t baud);
void transport_rs485_send(uint8_t msg_type, const uint8_t *payload, size_t length);
int transport_rs485_receive(uint8_t *buffer, size_t max_len, TickType_t timeout_ticks);
