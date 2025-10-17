#pragma once

#include <Arduino.h>

constexpr uint8_t RS485_SYNC_BYTE = 0xAA;
constexpr size_t RS485_MAX_PAYLOAD = 128;

struct Rs485Frame {
    uint8_t msgType;
    uint8_t length;
    uint8_t payload[RS485_MAX_PAYLOAD];
};

void transport_rs485_begin(uint32_t baud);
void transport_rs485_poll();
bool transport_rs485_pop(Rs485Frame &frame);
void transport_rs485_send(uint8_t msg_type, const uint8_t *payload, size_t length);
