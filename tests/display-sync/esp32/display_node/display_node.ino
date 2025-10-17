#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

/*** PitterOmat Wi-Fi Sync Test (UDP Broadcast)
 *  - Ein Sketch für Master & Clients
 *  - Master = DISPLAY_ID 1 → Koordinator
 *  - Transport: UDP Broadcast im gleichen Layer-2 Netz
 *  - Modi:
 *      * SoftAP (ohne Router): Master erstellt AP, Clients verbinden sich daran
 *      * STA   (mit Router):   Alle verbinden sich an vorhandenes WLAN
 */

// ========= USER CONFIG =========
#ifndef DISPLAY_ID
#define DISPLAY_ID 1          // Master = 1, Clients = 2..6
#endif
#ifndef TOTAL_NODES
#define TOTAL_NODES 2         // Anzahl aktiver Displays
#endif

// --- Wi-Fi Mode wählen: ---
// Ohne Router (Master macht eigenes WLAN):
#define WIFI_MODE_SOFTAP
// Mit Router (alle an bestehendes WLAN):
// #undef WIFI_MODE_SOFTAP

// SoftAP (nur verwendet, wenn Master + SOFTAP aktiv):
static const char* AP_SSID = "PitterMesh";
static const char* AP_PASS = "pitteromat";
static const uint8_t AP_CHANNEL = 6; // alle bleiben auf diesem Kanal

// STA (nur wenn Router genutzt wird):
static const char* STA_SSID = "DEIN_ROUTER_SSID";
static const char* STA_PASS = "DEIN_ROUTER_PASS";

// UDP
static const uint16_t UDP_PORT = 25252;

// Timing
static const uint16_t PING_INTERVAL_MS = 2000;
static const uint32_t START_OFFSET_MS  = 300;   // Start in Zukunft (ms) für Sync
// =================================

static_assert(DISPLAY_ID >= 1 && DISPLAY_ID <= TOTAL_NODES,
              "DISPLAY_ID must be within 1..TOTAL_NODES");

WiFiUDP udp;
IPAddress broadcastIP;
IPAddress localIP, netmaskIP;

uint8_t seq = 0;
bool awaiting[TOTAL_NODES + 1] = {false};
unsigned long lastPing = 0;

// Frameformat: [SYNC 0xAA][TYPE][LEN][PAYLOAD..][CRC8]
static const uint8_t SYNC = 0xAA;
enum : uint8_t { T_PING=0x30, T_ACK=0x31, T_TIME=0x40, T_START=0x41 };
static const size_t MAX_PL = 128;

// CRC8 Dallas/Maxim (reflected)
static inline uint8_t crc8_update(uint8_t crc, uint8_t b) {
  crc ^= b;
  for (uint8_t i=0;i<8;i++) crc = (crc & 1) ? (crc>>1) ^ 0x8C : (crc>>1);
  return crc;
}
static inline uint8_t crc8_block(uint8_t crc, const uint8_t* d, size_t n) {
  for (size_t i=0;i<n;i++) crc = crc8_update(crc, d[i]);
  return crc;
}

inline bool isMaster() { return DISPLAY_ID == 1; }

IPAddress calcBroadcast(IPAddress ip, IPAddress mask) {
  IPAddress bc;
  for (int i=0;i<4;i++) bc[i] = (ip[i] & mask[i]) | (~mask[i]);
  return bc;
}

void udpSend(uint8_t type, const uint8_t* payload, uint8_t len) {
  uint8_t crc = 0;
  crc = crc8_update(crc, type);
  crc = crc8_update(crc, len);
  if (len) crc = crc8_block(crc, payload, len);

  udp.beginPacket(broadcastIP, UDP_PORT);
  udp.write(SYNC);
  udp.write(type);
  udp.write(len);
  if (len) udp.write(payload, len);
  udp.write(crc);
  udp.endPacket();
}

bool udpRecv(uint8_t &type, uint8_t &len, uint8_t *payload) {
  int pktSize = udp.parsePacket();
  if (pktSize <= 0) return false;
  uint8_t buf[1 + 1 + 1 + MAX_PL + 1]; // sync+type+len+pl+crc
  int r = udp.read(buf, sizeof(buf));
  if (r < 4) return false;
  if (buf[0] != SYNC) return false;
  type = buf[1];
  len  = buf[2];
  if (len > MAX_PL) return false;
  if (r < 1+1+1+len+1) return false;
  uint8_t crcGot = buf[1+1+1+len];
  uint8_t crc = 0;
  crc = crc8_update(crc, type);
  crc = crc8_update(crc, len);
  if (len) crc = crc8_block(crc, &buf[3], len);
  if (crc != crcGot) return false;
  if (len && payload) memcpy(payload, &buf[3], len);
  return true;
}

void sendPing(uint8_t target) {
  uint8_t pl[3] = {(uint8_t)DISPLAY_ID, target, seq};
  udpSend(T_PING, pl, 3);
  Serial.printf("[ID %u] ping -> %u seq %u\n", DISPLAY_ID, target, seq);
}
void sendAck(uint8_t target, uint8_t s) {
  uint8_t pl[3] = {(uint8_t)DISPLAY_ID, target, s};
  udpSend(T_ACK, pl, 3);
  Serial.printf("[ID %u] ack -> %u seq %u\n", DISPLAY_ID, target, s);
}

// Zeit-Sync: Master sendet lokale millis() + Offset
void sendTimeSync() {
  uint32_t tNow = millis();
  uint32_t tStart = tNow + START_OFFSET_MS;
  uint8_t pl[8];
  memcpy(pl,     &tNow,   4);
  memcpy(pl + 4, &tStart, 4);
  udpSend(T_TIME, pl, 8);
  Serial.printf("[ID %u] TIMESYNC now=%lu start=%lu\n", DISPLAY_ID, (unsigned long)tNow, (unsigned long)tStart);
}

// Start-Command (separat, falls manuell ausgelöst)
void sendStartAt(uint32_t tStart) {
  uint8_t pl[4];
  memcpy(pl, &tStart, 4);
  udpSend(T_START, pl, 4);
  Serial.printf("[ID %u] START @ %lu\n", DISPLAY_ID, (unsigned long)tStart);
}

void handleFrame(uint8_t type, uint8_t len, const uint8_t* pl) {
  if (type == T_PING && len >= 3) {
    uint8_t origin = pl[0], target = pl[1], s = pl[2];
    if (target == DISPLAY_ID) {
      Serial.printf("[ID %u] ping from %u seq %u\n", DISPLAY_ID, origin, s);
      delay(2); // Mini-Lücke
      sendAck(origin, s);
    }
  } else if (type == T_ACK && len >= 3) {
    uint8_t origin = pl[0], target = pl[1], s = pl[2];
    if (target == DISPLAY_ID) {
      Serial.printf("[ID %u] ack <- %u seq %u\n", DISPLAY_ID, origin, s);
      if (isMaster() && origin <= TOTAL_NODES && s == seq) awaiting[origin] = false;
    }
  } else if (type == T_TIME && len >= 8) {
    uint32_t tNow, tStart;
    memcpy(&tNow,   pl,     4);
    memcpy(&tStart, pl + 4, 4);
    // Simple „start at time“ – hier nur Log + optional LED/Effekt:
    Serial.printf("[ID %u] TIMESYNC recv now=%lu start=%lu (local now=%lu, delta=%ld)\n",
      DISPLAY_ID, (unsigned long)tNow, (unsigned long)tStart, (unsigned long)millis(), (long)((int32_t)tStart - (int32_t)millis()));
  } else if (type == T_START && len >= 4) {
    uint32_t tStart;
    memcpy(&tStart, pl, 4);
    Serial.printf("[ID %u] START @ %lu (local now=%lu, wait=%ld ms)\n",
      DISPLAY_ID, (unsigned long)tStart, (unsigned long)millis(), (long)((int32_t)tStart - (int32_t)millis()));
    // Hier würdest du dein „gleichzeitig starten“ triggern:
    // z.B. warten bis millis() >= tStart, dann Spielstart
  }
}

void coordinatorLoop() {
  if (millis() - lastPing >= PING_INTERVAL_MS) {
    lastPing = millis();
    seq = (uint8_t)(seq + 1); if (!seq) seq = 1;
    // Timesync + Pings
    sendTimeSync();
    delay(10);
    for (uint8_t id = 2; id <= TOTAL_NODES; ++id) {
      awaiting[id] = true;
      sendPing(id);
      delay(10);
    }
  }
}

void connectWiFi() {
#ifdef WIFI_MODE_SOFTAP
  if (isMaster()) {
    WiFi.mode(WIFI_AP);
    bool ok = WiFi.softAP(AP_SSID, AP_PASS, AP_CHANNEL, 0, TOTAL_NODES+2);
    localIP  = WiFi.softAPIP();      // typ. 192.168.4.1
    netmaskIP = IPAddress(255,255,255,0);
    broadcastIP = calcBroadcast(localIP, netmaskIP); // typ. 192.168.4.255
    Serial.printf("[WiFi] SoftAP %s ch%d %s → IP %s, BCast %s\n",
      AP_SSID, AP_CHANNEL, ok?"OK":"FAIL",
      localIP.toString().c_str(), broadcastIP.toString().c_str());
  } else {
    WiFi.mode(WIFI_STA);
    WiFi.begin(AP_SSID, AP_PASS);
    Serial.printf("[WiFi] STA join %s ...\n", AP_SSID);
    uint32_t t0=millis(); while (WiFi.status()!=WL_CONNECTED && millis()-t0<10000) delay(100);
    localIP = WiFi.localIP();
    netmaskIP = WiFi.subnetMask();
    broadcastIP = calcBroadcast(localIP, netmaskIP);
    Serial.printf("[WiFi] STA IP %s, BCast %s\n",
      localIP.toString().c_str(), broadcastIP.toString().c_str());
  }
#else
  WiFi.mode(WIFI_STA);
  WiFi.begin(STA_SSID, STA_PASS);
  Serial.printf("[WiFi] STA join %s ...\n", STA_SSID);
  uint32_t t0=millis(); while (WiFi.status()!=WL_CONNECTED && millis()-t0<15000) delay(100);
  localIP = WiFi.localIP();
  netmaskIP = WiFi.subnetMask();
  broadcastIP = calcBroadcast(localIP, netmaskIP);
  Serial.printf("[WiFi] STA IP %s, BCast %s\n",
    localIP.toString().c_str(), broadcastIP.toString().c_str());
#endif
  udp.begin(UDP_PORT);
  Serial.printf("[UDP] Listening on %u\n", UDP_PORT);
}

void setup() {
  Serial.begin(115200);
  unsigned long t0=millis(); while(!Serial && millis()-t0<2000) delay(10);
  Serial.printf("\n== Wi-Fi Sync Node (ID=%u / TOTAL=%u) ==\n", DISPLAY_ID, TOTAL_NODES);
  connectWiFi();
  if (isMaster()) { memset(awaiting, 0, sizeof(awaiting)); lastPing = millis(); }
  Serial.println("Tippe 's' im Serial-Monitor → Master sendet START @ T");
}

void loop() {
  // Manuelles Startsignal per Konsole:
  if (isMaster() && Serial.available()) {
    int c = Serial.read();
    if (c=='s' || c=='S') {
      uint32_t tStart = millis() + START_OFFSET_MS;
      sendStartAt(tStart);
    }
  }

  // Frames empfangen
  uint8_t type=0,len=0,pl[MAX_PL];
  if (udpRecv(type, len, pl)) handleFrame(type, len, pl);

  // Master: regelmäßig Timesync + Pings
  if (isMaster()) coordinatorLoop();

  delay(2);
}
