# led ring test

## Ziel
- Sämtliche LEDs des Spiel- und Grenzsegments nacheinander durchschalten.
- Test bei reduzierter Helligkeit (~10 %) durchführen, um Netzteil und Ring zu schonen.

## Vorbereitung
- LED-Ring gemäß `docs/hardware/pitter-o-mat-setup.md` an den Arduino Mega anschließen:
  - SpielLED-Datenleitung → Pin 12
  - GrenzLED-Datenleitung → Pin 13
  - 5 V / GND entsprechend einspeisen
- Bibliothek `Adafruit NeoPixel` in der Arduino IDE installieren (Werkzeuge → Bibliotheken verwalten).
- Sketch `tests/led-ring/arduino/led_ring_sequential/led_ring_sequential.ino` öffnen (Board: *Arduino Mega 2560*, 115200 Baud) und flashen.
- Manifest optional prüfen: `python -m firmware.shared.scripts.manifest_tool validate tests/led-ring/assets/manifest.json --root tests/led-ring/assets`.

## Ablauf
1. Arduino mit USB verbinden und seriellen Monitor (115200 Baud) öffnen.
2. Nach dem Reset werden zuerst alle SpielLEDs (Pin 12), danach alle GrenzLEDs (Pin 13) in derselben Laufrichtung (Innen → Außen) einzeln in weißer Farbe bei ~10 % Helligkeit angesteuert.
3. Nach Abschluss meldet der Sketch `[LED] sweep finished` und bleibt im Idle.

## Erwartete Ausgabe
- Siehe `expected.log` (Serielle Ausgabe des Arduino).
- Wichtige Marker:
  - `== LED Ring Sequential Test ==`
  - `[LED] sweep game strip (432 LEDs)`
  - `[LED] sweep border strip (432 LEDs)`
  - `[LED] sweep finished`
