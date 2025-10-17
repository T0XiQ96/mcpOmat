# led ring test

## Ziel
- Mapping der Spiel- und Grenzsegmente fuer 2-6 Spieler bestaetigen.
- Joker-Gruppe 2 bei fuenf Spielern deaktiviert halten.
- Helligkeits- und Farbverlauf laut `segment_map.json` pruefen.

## Vorbereitung
- LED-Ring an den Arduino Mega anschliessen (siehe docs/hardware/pitter-o-mat-setup.md).
- ESP32-Client fuer LED-Steuerung nach Plan verbinden (RS485, 5 V Versorgung).
- Firmware flashen:
  - ESP32-Programm: `tests/led-ring/esp32/`
  - Arduino-Sketch: `tests/led-ring/arduino/`
- Manifest aus dem Testpaket mit `python -m firmware.shared.scripts.manifest_tool validate tests/led-ring/assets/manifest.json --root tests/led-ring/assets` pruefen.

## Ablauf
1. Testskript startet automatisch nach Reset: Spielerzahl 5, Joker deaktiviert.
2. ESP32 sendet LED-Mapping (msg 0x02) fuer Slots 1-5.
3. Arduino rendert Segment-Gruppen:
   - Grenzsegmente bleiben konstant weiss.
   - Spieler-Segmente rotieren in einer blau gefaerbten Animation.
   - Joker-Gruppe 2 bleibt dunkel.
4. Nach 10 s wechselt der Test auf Spielerzahl 3 mit aktiviertem Joker -> Joker-Segment pulsiert gruen.

## Erwartete Ausgabe
- Serielle Logs siehe `expected.log` (Arduino-Seite).
- Wichtige Marker:
  - `[LED] boundary check ok`
  - `[LED] joker group 2 OFF` (Phase 1)
  - `[LED] joker group 2 pulse` (Phase 2)
  - `[LED] slot <n> gradient ok`
