# PitterOmat Hardware Bring-up Checkliste

## Leistungsbudget
- Sicherstellen, dass das 5 V/60 A-Netzteil mit 10 AWG-Leitungen LED-Ring und Logik versorgt.
- Separaten abgesicherten Zweig für Arduino/ESP32-Elektronik vorsehen (je 5 V/2 A pro Knoten).

## Controller
- Arduino Mega 2560 mit RS485-Transceiver auf Serial1 verkabeln (TX = 18, RX = 19, DE = 2).
- Waveshare ESP32S3-Touch-LCD-4 Einheiten montieren; RS485-A/B-Leitungen in Daisy-Chain verbinden.

## LED-Ring
- SpielLED-Strang auf Arduino-Pin 12 (Daten) prüfen, ggf. Pegelwandler einsetzen.
- GrenzLED-Strang auf Pin 13 verifizieren.
- Alle 144 LEDs Leistung einspeisen, um Spannungsabfall zu vermeiden.

## Encoder
- Spieler 1: CLK = 6, DT = 7, SW = 5.
- Weitere Encoder vorverdrahten, aber in der Firmware deaktiviert lassen, bis einsatzbereit.

## Displays
- ESP32-Displays gemäß Spezifikation je Sitzplatz zuordnen (z.B. 2 Spieler → Screens 1 & 5).
- microSD am Master-ESP32 für Konfiguration und Highscores anschließen.

## Sicherheitsprüfungen
- Isolationsmessung am LED-Ring durchführen.
- Not-Aus-Schalter erreichbar platzieren und eindeutig beschriften.
- Teststart mit reduzierter LED-Helligkeit durchführen, um Logikpfade zu verifizieren.
