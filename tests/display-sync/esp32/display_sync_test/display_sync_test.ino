#include <Arduino.h>

/**
 * Display Sync Test – ESP32 side
 * ------------------------------------------------------------
 * - Sends manifest hash to the Arduino and waits for echo.
 * - Broadcasts display-to-slot assignments (6 entries).
 * - Waits for ready-mask updates (0x01 -> 0x3F) from Arduino.
 * - Logs progress on USB Serial to compare with expected.log.
 *
 * Hardware (ESP32-S3 Touch LCD):
 *   RS485 TX -> GPIO44, RS485 RX -> GPIO43, DE/RE -> GPIO21
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

enum class SyncStage : uint8_t {
  WaitManifestEcho,
  SendAssignments,
  WaitReadyMasks,
  Done,
};

SyncStage g_stage = SyncStage::WaitManifestEcho;
bool g_assignmentsSent = false;
uint8_t g_nextReadyIndex = 0;

struct FrameBuffer {
  uint8_t type = 0;
  uint8_t length = 0;
  uint8_t index = 0;
  uint8_t payload[RS485_MAX_PAYLOAD]{};
  enum class State : uint8_t { WaitSync, MsgType, Length, Payload, Crc } state =
      State::WaitSync;
} g_rx;

uint8_t crc8Update(uint8_t crc, uint8_t byte) {
  crc ^= byte;
  for (uint8_t i = 0; i < 8; ++i) {
    if (crc & 0x01U) {
      crc = (crc >> 1) ^ 0x8CU;
    } else {
      crc >>= 1;
    }
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
    Serial.printf("[ERR] payload too large (%u bytes)\n", length);
    return;
  }
  uint8_t header[3] = {RS485_SYNC, type, length};
  uint8_t crc = 0;
  crc = crc8Update(crc, type);
  crc = crc8Update(crc, length);
  if (length > 0 && payload != nullptr) {
    crc = crc8Update(crc, payload, length);
  }

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
  g_rx.index = 0;
  g_rx.type = 0;
  g_rx.length = 0;
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
        Serial.printf("[WARN] drop frame len=%u > %u\n", g_rx.length,
                      RS485_MAX_PAYLOAD);
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
      Serial.printf("[WARN] crc mismatch exp=0x%02X got=0x%02X type=0x%02X len=%u\n",
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
  Serial.printf("[SYNC] manifest hash tx: %s\n", kManifestHash);
}

void sendDisplayAssignments() {
  struct Mapping {
    uint8_t displayId;
    uint8_t slot;
  };
  const Mapping table[6] = {
      {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6},
  };
  uint8_t payload[2];
  for (const auto &entry : table) {
    payload[0] = entry.displayId;
    payload[1] = entry.slot;
    sendFrame(0x02, payload, sizeof(payload));
    Serial.printf("[SYNC] display %u -> slot P%u\n", entry.displayId,
                  entry.slot);
    delay(50);
  }
}

void handleFrame(uint8_t type, uint8_t length, const uint8_t *payload) {
  switch (type) {
  case 0x05: { // manifest hash echo from Arduino
    String hash = "";
    for (uint8_t i = 0; i < length; ++i) {
      hash += static_cast<char>(payload[i]);
    }
    if (hash.equals(kManifestHash)) {
      Serial.println("[SYNC] manifest hash ok");
      g_stage = SyncStage::SendAssignments;
    } else {
      Serial.printf("[ERR] manifest hash mismatch: %s\n", hash.c_str());
    }
    break;
  }
  case 0x06: { // ready mask from Arduino
    if (length >= 1 && g_stage == SyncStage::WaitReadyMasks) {
      uint8_t mask = payload[0];
      Serial.printf("[SYNC] ready mask 0x%02X\n", mask);
      if (++g_nextReadyIndex >= 6) {
        Serial.println("[SYNC] summary complete");
        g_stage = SyncStage::Done;
      }
    }
    break;
  }
  default:
    // Ignore other frames for this test
    break;
  }
}

} // namespace

void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println();
  Serial.println("== Display Sync Test (ESP32) ==");

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

  if (g_stage == SyncStage::SendAssignments && !g_assignmentsSent) {
    sendDisplayAssignments();
    g_assignmentsSent = true;
    g_stage = SyncStage::WaitReadyMasks;
    g_nextReadyIndex = 0;
  }

  delay(10);
}
