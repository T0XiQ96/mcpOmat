#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "freertos/FreeRTOS.h"

#define RS485_SYNC_BYTE 0xAA
#define RS485_MAX_PAYLOAD 128U

typedef struct {
    uint8_t msg_type;
    uint8_t length;
    uint8_t payload[RS485_MAX_PAYLOAD];
} rs485_frame_t;

void transport_rs485_init(uint32_t baud);
void transport_rs485_send(uint8_t msg_type, const uint8_t *payload, size_t length);
bool transport_rs485_receive(rs485_frame_t *frame, TickType_t timeout_ticks);
