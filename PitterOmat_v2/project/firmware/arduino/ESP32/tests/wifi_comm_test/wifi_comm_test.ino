/* ESP32 WiFi Ping/Pong Latenztest (Arduino IDE)
   - Verbindet zu SSID/PASS, Master sendet Broadcast-Pings, Slaves antworten.
   - Serial Monitor: Durchschnittslatenz.
   NOTE: Setze ROLE_MASTER auf true NUR auf einem Gerät.
*/
#include <WiFi.h>
#include <WiFiUdp.h>

// ---- Konfig ----
const char* WIFI_SSID = "Pittermesh";
const char* WIFI_PASS = "Pitteromat2025";
const bool  ROLE_MASTER = true;        // genau 1x true, rest false
const uint16_t UDP_PORT = 42100;
const unsigned long PING_INTERVAL_MS = 1000;

// ---- State ----
WiFiUDP udp;
IPAddress bcast;
unsigned long lastPing = 0;
uint32_t seq = 0;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.printf("Connecting to %s", WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.printf("\nIP: %s\n", WiFi.localIP().toString().c_str());
  bcast = ~WiFi.subnetMask() | WiFi.gatewayIP(); // simple broadcast calc
  udp.begin(UDP_PORT);
  Serial.printf("UDP %u ready, broadcast %s\n", UDP_PORT, bcast.toString().c_str());
}

void loop() {
  // recv
  int len = udp.parsePacket();
  if (len > 0) {
    uint8_t buf[64];
    len = udp.read(buf, sizeof(buf));
    if (len >= 12 && buf[0]=='P'&&buf[1]=='I'&&buf[2]=='N'&&buf[3]=='G') {
      // PING packet: [PING][seq u32][tSend u32]
      uint32_t rxSeq = *(uint32_t*)&buf[4];
      uint32_t tSend = *(uint32_t*)&buf[8];
      if (!ROLE_MASTER) {
        // reply PONG
        udp.beginPacket(udp.remoteIP(), udp.remotePort());
        udp.write((const uint8_t*)"PONG",4);
        udp.write((const uint8_t*)&rxSeq,4);
        uint32_t tNow = millis();
        udp.write((const uint8_t*)&tNow,4);
        udp.endPacket();
      }
    } else if (len >= 12 && buf[0]=='P'&&buf[1]=='O'&&buf[2]=='N'&&buf[3]=='G') {
      // PONG packet
      uint32_t rxSeq = *(uint32_t*)&buf[4];
      uint32_t tResp = *(uint32_t*)&buf[8];
      uint32_t rtt = millis() - tResp;
      Serial.printf("seq=%u RTT~%ums\n", rxSeq, rtt);
    }
  }

  // send pings
  if (ROLE_MASTER && millis() - lastPing >= PING_INTERVAL_MS) {
    lastPing = millis();
    udp.beginPacket(bcast, UDP_PORT);
    udp.write((const uint8_t*)"PING",4);
    udp.write((const uint8_t*)&seq,4);
    uint32_t tSend = millis();
    udp.write((const uint8_t*)&tSend,4);
    udp.endPacket();
    seq++;
  }
}
