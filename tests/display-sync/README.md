# display sync test

## Ziel
- Wi-Fi-basierte Kommunikation zwischen bis zu sechs ESP32-S3 Touch LCD 4" Displays pruefen.
- Broadcast-Pings und ACKs ueber UDP sicherstellen (Master <-> Clients).
- Zeitabgleich fuer gleichzeitige Aktionen vorbereiten (Start-Timestamp).

## Vorbereitung
- Fuer jedes Display den Sketch `tests/display-sync/esp32/display_node/display_node.ino` in der Arduino IDE oeffnen.
  - `#define DISPLAY_ID` (1..6) eindeutig setzen; ID 1 ist der Master.
  - `#define TOTAL_NODES` auf allen Displays gleich konfigurieren.
  - WLAN-Modus waehlen:
    - **SoftAP** (Voreinstellung): Master erstellt eigenes Netz (`PitterMesh` / `pitteromat`).
    - **STA** (Router): `#undef WIFI_MODE_SOFTAP` setzen und `STA_SSID/STA_PASS` fuellen.
- Auf jedem Touch-LCD den Sketch flashen (Board: ESP32S3 Touch LCD, 115200 Baud).
- Displays ueber USB versorgen (keine RS485-Verbindung zwischen den Displays erforderlich).

## Ablauf
1. Displays einschalten und ggf. wenige Sekunden warten, bis alle Clients im SoftAP angemeldet sind.
2. Serielle Monitore (115200 Baud) fuer jedes Display oeffnen.
3. ID 1 sendet im Intervall UDP-Pings (`ping -> <id>`), sowie automatische Time-Syncs.
4. Clients loggen eingehende Pings (`ping from 1 seq ...`) und antworten mit `ack -> 1`.
5. Optional `s` im Monitor von ID 1 senden, um ein synchrones `START @ <timestamp>` zu triggern.

## Erwartete Ausgabe
- Beispiele fuer Master (ID 1) und Client (ID 2) stehen in `expected.log`.
- Wichtige Marker:
  - `== Wi-Fi Sync Node (ID=...) ==`
  - `[WiFi] ...` mit IP/Broadcast-Angaben.
  - `[ID 1] ping -> <ziel> seq <n>` sowie `[ID x] ack -> 1 seq <n>`.
  - `[ID x] TIMESYNC recv ...` bzw. `[ID x] START @ ...` nach manuellem Trigger.
