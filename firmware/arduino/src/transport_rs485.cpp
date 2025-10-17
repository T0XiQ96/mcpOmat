#include "transport_rs485.h"

#include <HardwareSerial.h>
#include <limits.h>
#include <string.h>

namespace {

HardwareSerial &rs485_serial = Serial1;
constexpr uint8_t RS485_DE_PIN = 2;
constexpr size_t kQueueCapacity = 4;

enum class RxState : uint8_t {
    WaitSync = 0,
    MsgType,
    Length,
    Payload,
    Crc,
};

struct RxContext {
    RxState state = RxState::WaitSync;
    Rs485Frame frame{};
    uint8_t index = 0;
};

RxContext rx_ctx;
Rs485Frame frame_queue[kQueueCapacity];
size_t queue_head = 0;
size_t queue_tail = 0;
size_t queue_count = 0;

uint8_t crc8_step(uint8_t crc, uint8_t data)
{
    crc ^= data;
    for (uint8_t bit = 0; bit < 8; ++bit) {
        if ((crc & 0x01U) != 0U) {
            crc = (crc >> 1) ^ 0x8CU;
        } else {
            crc >>= 1;
        }
    }
    return crc;
}

uint8_t crc8_update(uint8_t crc, const uint8_t *data, size_t length)
{
    for (size_t i = 0; i < length; ++i) {
        crc = crc8_step(crc, data[i]);
    }
    return crc;
}

void reset_state(bool synced)
{
    rx_ctx.state = synced ? RxState::MsgType : RxState::WaitSync;
    rx_ctx.frame.msgType = 0;
    rx_ctx.frame.length = 0;
    rx_ctx.index = 0;
}

void enqueue_frame(const Rs485Frame &frame)
{
    frame_queue[queue_tail] = frame;
    queue_tail = (queue_tail + 1U) % kQueueCapacity;
    if (queue_count < kQueueCapacity) {
        ++queue_count;
    } else {
        queue_head = (queue_head + 1U) % kQueueCapacity;
    }
}

bool dequeue_frame(Rs485Frame &frame)
{
    if (queue_count == 0) {
        return false;
    }
    frame = frame_queue[queue_head];
    queue_head = (queue_head + 1U) % kQueueCapacity;
    --queue_count;
    return true;
}

void set_transmit(bool enable)
{
    if (!enable) {
        rs485_serial.flush();
    }
    digitalWrite(RS485_DE_PIN, enable ? HIGH : LOW);
}

} // namespace

void transport_rs485_begin(uint32_t baud)
{
    pinMode(RS485_DE_PIN, OUTPUT);
    digitalWrite(RS485_DE_PIN, LOW);
    rs485_serial.begin(baud);
    queue_head = queue_tail = queue_count = 0;
    reset_state(false);
}

void transport_rs485_poll()
{
    while (rs485_serial.available() > 0) {
        uint8_t byte = static_cast<uint8_t>(rs485_serial.read());

        switch (rx_ctx.state) {
        case RxState::WaitSync:
            if (byte == RS485_SYNC_BYTE) {
                reset_state(true);
            }
            break;

        case RxState::MsgType:
            rx_ctx.frame.msgType = byte;
            rx_ctx.state = RxState::Length;
            break;

        case RxState::Length:
            rx_ctx.frame.length = byte;
            if (rx_ctx.frame.length > RS485_MAX_PAYLOAD) {
                Serial.print(F("[RS485] drop frame: length "));
                Serial.print(rx_ctx.frame.length);
                Serial.print(F(" exceeds "));
                Serial.println(RS485_MAX_PAYLOAD);
                reset_state(false);
            } else if (rx_ctx.frame.length == 0) {
                rx_ctx.state = RxState::Crc;
            } else {
                rx_ctx.index = 0;
                rx_ctx.state = RxState::Payload;
            }
            break;

        case RxState::Payload:
            rx_ctx.frame.payload[rx_ctx.index++] = byte;
            if (rx_ctx.index >= rx_ctx.frame.length) {
                rx_ctx.state = RxState::Crc;
            }
            break;

        case RxState::Crc: {
            uint8_t crc = 0;
            crc = crc8_step(crc, rx_ctx.frame.msgType);
            crc = crc8_step(crc, rx_ctx.frame.length);
            if (rx_ctx.frame.length > 0) {
                crc = crc8_update(crc, rx_ctx.frame.payload, rx_ctx.frame.length);
            }
            bool crc_ok = (crc == byte);
            bool treat_as_sync = (byte == RS485_SYNC_BYTE);

            if (crc_ok) {
                Rs485Frame completed = rx_ctx.frame;
                enqueue_frame(completed);
            } else {
                Serial.print(F("[RS485] CRC mismatch exp=0x"));
                Serial.print(crc, HEX);
                Serial.print(F(" got=0x"));
                Serial.print(byte, HEX);
                Serial.print(F(" type=0x"));
                Serial.print(rx_ctx.frame.msgType, HEX);
                Serial.print(F(" len="));
                Serial.println(rx_ctx.frame.length);
            }
            reset_state(treat_as_sync);
            break;
        }
        }
    }
}

bool transport_rs485_pop(Rs485Frame &frame)
{
    transport_rs485_poll();
    return dequeue_frame(frame);
}

void transport_rs485_send(uint8_t msg_type, const uint8_t *payload, size_t length)
{
    if (length > RS485_MAX_PAYLOAD || length > UINT8_MAX) {
        Serial.print(F("[RS485] payload too large ("));
        Serial.print(static_cast<unsigned>(length));
        Serial.print(F(" bytes, max "));
        Serial.print(RS485_MAX_PAYLOAD);
        Serial.println(')');
        return;
    }
    if (length > 0 && payload == nullptr) {
        Serial.println(F("[RS485] payload pointer null"));
        return;
    }

    uint8_t len8 = static_cast<uint8_t>(length);
    uint8_t crc = 0;
    crc = crc8_step(crc, msg_type);
    crc = crc8_step(crc, len8);
    if (length > 0) {
        crc = crc8_update(crc, payload, length);
    }

    set_transmit(true);
    rs485_serial.write(RS485_SYNC_BYTE);
    rs485_serial.write(msg_type);
    rs485_serial.write(len8);
    if (length > 0) {
        rs485_serial.write(payload, length);
    }
    rs485_serial.write(crc);
    rs485_serial.flush();
    set_transmit(false);
}
