#include <Arduino.h>

/**
 * RS485 Link Test – Arduino slave
 * ----------------------------------------------
 * - Listens for manifest hash (msg 0x05) from the ESP32 master.
 * - Echoes the hash back and streams ready-mask steps (msg 0x06).
 */

namespace {

constexpr uint8_t RS485_DE_PIN = 2;
constexpr uint32_t RS485_BAUD = 250000;
constexpr uint8_t RS485_SYNC = 0xAA;
constexpr size_t RS485_MAX_PAYLOAD = 128;
constexpr uint8_t READY_MASK_SEQUENCE[6] = {0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F};

enum class RxState : uint8_t { WaitSync, MsgType, Length, Payload, Crc };

struct FrameBuffer {
  RxState state = RxState::WaitSync;
  uint8_t type = 0;
  uint8_t length = 0;
  uint8_t index = 0;
  uint8_t payload[RS485_MAX_PAYLOAD]{};
} g_rx;

uint8_t g_mappingCount = 0;
bool g_readySequenceSent = false;

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
  if (!enable) {
    Serial1.flush();
  }
  digitalWrite(RS485_DE_PIN, enable ? HIGH : LOW);
}

void sendFrame(uint8_t type, const uint8_t *payload, uint8_t length) {
  if (length > RS485_MAX_PAYLOAD) {
    Serial.print(F("[Arduino] skip tx, payload too large: "));
    Serial.println(length);
    return;
  }
  uint8_t crc = 0;
  crc = crc8Update(crc, type);
  crc = crc8Update(crc, length);
  if (length > 0 && payload != nullptr) {
    crc = crc8Update(crc, payload, length);
  }

  setTransmit(true);
  Serial1.write(RS485_SYNC);
  Serial1.write(type);
  Serial1.write(length);
  if (length > 0 && payload != nullptr) {
    Serial1.write(payload, length);
  }
  Serial1.write(crc);
  Serial1.flush();
  setTransmit(false);
}

void resetReceiver(bool synced) {
  g_rx.state = synced ? RxState::MsgType : RxState::WaitSync;
  g_rx.type = 0;
  g_rx.length = 0;
  g_rx.index = 0;
}

bool pollFrame(uint8_t &type, uint8_t &length, uint8_t *payload) {
  while (Serial1.available() > 0) {
    uint8_t byte = static_cast<uint8_t>(Serial1.read());
    switch (g_rx.state) {
    case RxState::WaitSync:
      if (byte == RS485_SYNC) {
        resetReceiver(true);
      }
      break;
    case RxState::MsgType:
      g_rx.type = byte;
      g_rx.state = RxState::Length;
      break;
    case RxState::Length:
      g_rx.length = byte;
      if (g_rx.length > RS485_MAX_PAYLOAD) {
        Serial.print(F("[Arduino] drop frame len="));
        Serial.println(g_rx.length);
        resetReceiver(false);
      } else if (g_rx.length == 0) {
        g_rx.state = RxState::Crc;
      } else {
        g_rx.index = 0;
        g_rx.state = RxState::Payload;
      }
      break;
    case RxState::Payload:
      g_rx.payload[g_rx.index++] = byte;
      if (g_rx.index >= g_rx.length) {
        g_rx.state = RxState::Crc;
      }
      break;
    case RxState::Crc: {
      uint8_t crc = 0;
      crc = crc8Update(crc, g_rx.type);
      crc = crc8Update(crc, g_rx.length);
      crc = crc8Update(crc, g_rx.payload, g_rx.length);
      bool crcOk = (crc == byte);
      bool treatAsSync = (byte == RS485_SYNC);
      if (crcOk) {
        type = g_rx.type;
        length = g_rx.length;
        if (length > 0 && payload != nullptr) {
          memcpy(payload, g_rx.payload, length);
        }
        resetReceiver(false);
        return true;
      }
      Serial.println(F("[Arduino] crc mismatch"));
      resetReceiver(treatAsSync);
      break;
    }
    }
  }
  return false;
}

void sendReadyMasksOnce() {
  if (g_readySequenceSent) {
    return;
  }
  g_readySequenceSent = true;
  for (uint8_t mask : READY_MASK_SEQUENCE) {
    sendFrame(0x06, &mask, 1);
    Serial.print(F("[Arduino] ready mask tx: 0x"));
    if (mask < 0x10) {
      Serial.print('0');
    }
    Serial.println(mask, HEX);
    delay(200);
  }
}

void handleFrame(uint8_t type, uint8_t length, const uint8_t *payload) {
  switch (type) {
  case 0x05: { // manifest hash from ESP32
    String hash;
    for (uint8_t i = 0; i < length; ++i) {
      hash += static_cast<char>(payload[i]);
    }
    Serial.print(F("[Arduino] manifest hash rx: "));
    Serial.println(hash);
    sendFrame(0x05, payload, length);
    Serial.println(F("[Arduino] manifest hash echo tx"));
    break;
  }
  case 0x02:
    if (length >= 2 && g_mappingCount < 255) {
      ++g_mappingCount;
      if (g_mappingCount >= 6) {
        sendReadyMasksOnce();
      }
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
  Serial.println(F("== RS485 Link Test (Arduino) =="));

  pinMode(RS485_DE_PIN, OUTPUT);
  digitalWrite(RS485_DE_PIN, LOW);
  Serial1.begin(RS485_BAUD);
}

void loop() {
  uint8_t type = 0;
  uint8_t length = 0;
  uint8_t payload[RS485_MAX_PAYLOAD];

  if (pollFrame(type, length, payload)) {
    handleFrame(type, length, payload);
  }
}
