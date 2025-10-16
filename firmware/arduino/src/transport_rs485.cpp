#include "transport_rs485.h"

#include <HardwareSerial.h>

static HardwareSerial &rs485_serial = Serial1;
static constexpr uint8_t RS485_DE_PIN = 2;

void transport_rs485_begin(uint32_t baud)
{
    pinMode(RS485_DE_PIN, OUTPUT);
    digitalWrite(RS485_DE_PIN, LOW); // receive by default
    rs485_serial.begin(baud);
}

static void set_transmit(bool enable)
{
    digitalWrite(RS485_DE_PIN, enable ? HIGH : LOW);
    if (enable) {
        rs485_serial.flush();
    }
}

void transport_rs485_poll()
{
    while (rs485_serial.available() > 0) {
        // TODO: buffer incoming bytes and pass to session controller
        (void)rs485_serial.read();
    }
}

void transport_rs485_send(uint8_t msg_type, const uint8_t *payload, size_t length)
{
    set_transmit(true);
    rs485_serial.write(0xAA);
    rs485_serial.write(msg_type);
    rs485_serial.write(static_cast<uint8_t>(length));
    rs485_serial.write(payload, length);
    uint8_t crc = 0;
    crc ^= msg_type;
    crc ^= static_cast<uint8_t>(length);
    for (size_t i = 0; i < length; ++i) {
        crc ^= payload[i];
    }
    rs485_serial.write(crc);
    rs485_serial.flush();
    set_transmit(false);
}
