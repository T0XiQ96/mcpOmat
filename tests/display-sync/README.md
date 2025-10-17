# display sync test

## Ziel
- LVGL-Views den korrekten Displays 1-6 zuordnen.
- Sitzplatz-Labels und Ready-Status synchron mit dem ESP32 halten.
- Manifest-Hash auf allen Clients vor Anzeige der Sitzplaetze pruefen.

## Vorbereitung
- Bis zu sechs Displays gemass docs/hardware/pitter-o-mat-setup.md anschliessen.
- RS485-Verbindung zwischen Master-ESP32 und Arduino herstellen.
- Firmware flashen:
  - ESP32-Programm: `tests/display-sync/esp32/`
  - Arduino-Sketch: `tests/display-sync/arduino/`
- Assets validieren: `python -m firmware.shared.scripts.manifest_tool validate tests/display-sync/assets/manifest.json --root tests/display-sync/assets`.

## Ablauf
1. Master bootet, prueft Manifest-Hash (`sha256:02130f436c4c10a17b353205ffd3c85eafb40d670eb654abf7e03b849557950d`).
2. Sitzplatz-Sequenz startet und weist Displays 1-6 die Slots `P1`-`P6` zu.
3. Ready-Maske wird simuliert: Slots 1-6 schalten nacheinander auf "bereit".
4. Abschlussbildschirm zeigt Hash-Status "OK" und Zuordnungstabelle.

## Erwartete Ausgabe
- Serielle Referenz siehe `expected.log` (ESP32 und Arduino zusammengefuehrt).
- Kontrollpunkte:
  - `[SYNC] manifest hash ok`
  - `[SYNC] display <id> -> slot <n>`
  - `[SYNC] ready mask 0x3f`
  - `[SYNC] summary complete`
