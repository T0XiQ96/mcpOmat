#include <Arduino.h>

/**
 * RS485 Link Test – ESP32 master
 * ----------------------------------------------
 * - Sends manifest hash (msg 0x05) to the Arduino.
 * - Logs echoes and ready-mask responses.
 * - Uses the onboard RS485 transceiver (GPIO43/44, GPIO21 DE/RE).
 */

namespace {

constexpr uint8_t RS485_TX_PIN = 44;
constexpr uint8_t RS485_RX_PIN = 43;
constexpr uint8_t RS485_DE_PIN = 21;
constexpr uint32_t RS485_BAUD = 250000;
constexpr uint8_t RS485_SYNC = 0xAA;
constexpr size_t RS485_MAX_PAYLOAD = 128;

HardwareSerial &rs485 = Serial1;

const char *kManifestHash =
    "sha256:02130f436c4c10a17b353205ffd3c85eafb40d670eb654abf7e03b849557950d";

struct FrameBuffer {
  enum class State : uint8_t { WaitSync, MsgType, Length, Payload, Crc };
  State state = State::WaitSync;
  uint8_t type = 0;
  uint8_t length = 0;
  uint8_t index = 0;
  uint8_t payload[RS485_MAX_PAYLOAD]{};
} g_rx;

uint8_t crc8Update(uint8_t crc, uint8_t byte) {
  crc ^= byte;
  for (uint8_t i = 0; i < 8; ++i) {
    crc = (crc & 0x01U) ? (crc >> 1) ^ 0x8CU : crc >> 1;
  }
  return crc;
}

uint8_t crc8Update(uint8_t crc, const uint8_t *data, size_t length) {
  for (size_t i = 0; i < length; ++i) {
    crc = crc8Update(crc, data[i]);
  }
  return crc;
}

void setTransmit(bool enable) {
  digitalWrite(RS485_DE_PIN, enable ? HIGH : LOW);
  if (!enable) {
    rs485.flush();
  }
}

void sendFrame(uint8_t type, const uint8_t *payload, uint8_t length) {
  if (length > RS485_MAX_PAYLOAD) {
    Serial.printf("[ESP32] payload too large (%u bytes)\n", length);
    return;
  }
  uint8_t crc = 0;
  crc = crc8Update(crc, type);
  crc = crc8Update(crc, length);
  if (length > 0 && payload != nullptr) {
    crc = crc8Update(crc, payload, length);
  }

  uint8_t header[3] = {RS485_SYNC, type, length};
  setTransmit(true);
  rs485.write(header, sizeof(header));
  if (length > 0 && payload != nullptr) {
    rs485.write(payload, length);
  }
  rs485.write(crc);
  rs485.flush();
  setTransmit(false);
}

void resetReceiver(bool synced) {
  g_rx.state = synced ? FrameBuffer::State::MsgType : FrameBuffer::State::WaitSync;
  g_rx.type = 0;
  g_rx.length = 0;
  g_rx.index = 0;
}

bool pollFrame(uint8_t &type, uint8_t &length, uint8_t *payload) {
  while (rs485.available() > 0) {
    uint8_t byte = static_cast<uint8_t>(rs485.read());
    switch (g_rx.state) {
    case FrameBuffer::State::WaitSync:
      if (byte == RS485_SYNC) {
        resetReceiver(true);
      }
      break;
    case FrameBuffer::State::MsgType:
      g_rx.type = byte;
      g_rx.state = FrameBuffer::State::Length;
      break;
    case FrameBuffer::State::Length:
      g_rx.length = byte;
      if (g_rx.length > RS485_MAX_PAYLOAD) {
        Serial.printf("[ESP32] drop frame len=%u > %u\n", g_rx.length, RS485_MAX_PAYLOAD);
        resetReceiver(false);
      } else if (g_rx.length == 0) {
        g_rx.state = FrameBuffer::State::Crc;
      } else {
        g_rx.index = 0;
        g_rx.state = FrameBuffer::State::Payload;
      }
      break;
    case FrameBuffer::State::Payload:
      g_rx.payload[g_rx.index++] = byte;
      if (g_rx.index >= g_rx.length) {
        g_rx.state = FrameBuffer::State::Crc;
      }
      break;
    case FrameBuffer::State::Crc: {
      uint8_t crc = 0;
      crc = crc8Update(crc, g_rx.type);
      crc = crc8Update(crc, g_rx.length);
      crc = crc8Update(crc, g_rx.payload, g_rx.length);
      bool crcOk = (crc == byte);
      bool byteIsSync = (byte == RS485_SYNC);
      if (crcOk) {
        type = g_rx.type;
        length = g_rx.length;
        if (length > 0 && payload != nullptr) {
          memcpy(payload, g_rx.payload, length);
        }
        resetReceiver(false);
        return true;
      }
      Serial.printf("[ESP32] crc mismatch exp=0x%02X got=0x%02X type=0x%02X len=%u\n",
                    crc, byte, g_rx.type, g_rx.length);
      resetReceiver(byteIsSync);
      break;
    }
    }
  }
  return false;
}

void sendManifestHash() {
  const uint8_t *payload =
      reinterpret_cast<const uint8_t *>(kManifestHash);
  uint8_t length = static_cast<uint8_t>(strlen(kManifestHash));
  sendFrame(0x05, payload, length);
  Serial.printf("[ESP32] manifest hash tx: %s\n", kManifestHash);
}

void handleFrame(uint8_t type, uint8_t length, const uint8_t *payload) {
  switch (type) {
  case 0x05: {
    String hash;
    for (uint8_t i = 0; i < length; ++i) {
      hash += static_cast<char>(payload[i]);
    }
    Serial.printf("[ESP32] manifest hash rx: %s\n", hash.c_str());
    if (hash.equals(kManifestHash)) {
      Serial.println("[ESP32] manifest hash echo ok");
    } else {
      Serial.println("[ESP32] manifest hash mismatch");
    }
    break;
  }
  case 0x06:
    if (length >= 1) {
      Serial.printf("[ESP32] ready mask 0x%02X\n", payload[0]);
    }
    break;
  default:
    break;
  }
}

} // namespace

void setup() {
  Serial.begin(115200);
  unsigned long startWait = millis();
  while (!Serial && (millis() - startWait) < 3000) {
    delay(10);
  }
  Serial.println();
  Serial.println("== RS485 Link Test (ESP32) ==");

  pinMode(RS485_DE_PIN, OUTPUT);
  digitalWrite(RS485_DE_PIN, LOW);
  rs485.begin(RS485_BAUD, SERIAL_8N1, RS485_RX_PIN, RS485_TX_PIN);
  delay(50);

  sendManifestHash();
}

void loop() {
  uint8_t type = 0;
  uint8_t length = 0;
  uint8_t payload[RS485_MAX_PAYLOAD];

  if (pollFrame(type, length, payload)) {
    handleFrame(type, length, payload);
  }

  delay(10);
}
