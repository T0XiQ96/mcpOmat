# rs485 link test

## Ziel
- RS485-Verbindung zwischen Master-ESP32 und Arduino prüfen.
- Manifest-Hash (`msg 0x05`) senden und per Echo bestätigen lassen.
- Fehlerfall (CRC, Timeouts) in der seriellen Ausgabe erkennen.

## Vorbereitung
- Verkabelung laut `docs/hardware/pitter-o-mat-setup.md` (RS485: GPIO44→DI, GPIO43→RO, GPIO21→DE/RE, Arduino TX=18, RX=19, DE=Pin2).
- SD-Karte mit `SDCARD/manifest.json` aus diesem Repo bestücken (`python -m firmware.shared.scripts.manifest_tool generate --root SDCARD`).
- Firmware-Binaries für ESP32/Arduino aus diesem Testpaket aufspielen:
  - ESP32-Sketch: `tests/rs485-link/esp32/`
  - Arduino-Sketch: `tests/rs485-link/arduino/`

## Ablauf
1. Beide Geräte via USB anschließen und Terminalfenster mit 115200 Baud öffnen (Master & Arduino separat).
2. ESP32 bootet, lädt Manifest, sendet `msg 0x05` mit Hash `sha256:02130f436c4c10a17b353205ffd3c85eafb40d670eb654abf7e03b849557950d`.
3. Arduino bestätigt Empfang, sendet Echo-Frame zurück (`msg 0x05`), ESP32 quittiert „manifest hash echo ok“.
4. Fehlerfall-Test: RS485-Leitung kurz unterbrechen → ESP32 erwartet Wiederholung, loggt „crc mismatch / requesting resend“.

## Erwartete Ausgabe
- Details siehe `expected.log`. Wichtige Marker:
  - `[ESP32] manifest hash tx: sha256:02130f...`
  - `[Arduino] manifest hash rx: sha256:02130f...`
  - `[ESP32] manifest hash echo ok`
  - Fehlerfall: `[ESP32] crc mismatch` + erneuter Sendeversuch innerhalb 1 s.
