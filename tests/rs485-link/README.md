# rs485 link test

## Ziel
- RS485-Verbindung zwischen Master-ESP32 und Arduino Mega prüfen.
- Manifest-Hash (`msg 0x05`) senden und per Echo bestätigen lassen.
- Ready-Masken (Msg 0x06) vom Arduino empfangen.

## Vorbereitung
- Verdrahtung gemäß `docs/hardware/pitter-o-mat-setup.md`:
  - ESP32 Touch LCD: RS485-Klemme `A/B/GND`.
  - Arduino Mega plus RS485-Modul (MAX485 o.ä.):
    - A/B ↔ Bus, GND gemeinsam.
    - RO → RX1 (Pin 19), DI → TX1 (Pin 18).
    - DE & RE gebrückt → Pin 2.
- SD-Karte mit `SDCARD/manifest.json` bestücken (`python -m firmware.shared.scripts.manifest_tool generate --root SDCARD`).
- Firmware flashen:
  - ESP32: `tests/rs485-link/esp32/rs485_link_master/rs485_link_master.ino`
  - Arduino: `tests/rs485-link/arduino/rs485_link_slave/rs485_link_slave.ino`

## Ablauf
1. Beide Geräte per USB verbinden, seriellen Monitor je Board auf 115200 Baud öffnen.
2. ESP32 startet, sendet Manifest-Hash `sha256:02130f436c4c10a17b353205ffd3c85eafb40d670eb654abf7e03b849557950d`.
3. Arduino bestätigt Hash (Echo) und sendet nacheinander die Ready-Masken `0x01 … 0x3F`.
4. Optional: Leitung A/B kurz trennen – beide Sketches melden CRC-Fehler.

## Erwartete Ausgabe
- Referenz siehe `expected.log`. Typische Marker:
  - `== RS485 Link Test (ESP32) ==`
  - `[ESP32] manifest hash tx: …`
  - `[Arduino] manifest hash rx: …` / `[Arduino] manifest hash echo tx`
  - `[ESP32] ready mask 0x..`
