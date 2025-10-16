# PitterOmat Hardware-Setup (Aufgabe T001)

Diese Checkliste fasst alle Verkabelungs- und Ausgangsannahmen zusammen, die für den Bring-up relevant sind. Sie orientiert sich direkt an `pitteromat.txt` und der aktuellen Spezifikation.

## Leistungsversorgung
- Hauptnetzteil: 5 V / 60 A, mit 10 AWG-Leitungen zum LED-Ring und zu den Logik-Schienen.
- Logikzweige separat absichern (z.B. 5 V / 2 A pro Controller).
- Spannungsabfall vermeiden: Strominjektion spätestens alle 144 LEDs rund um den Ring.

## Steuergeräte & Kommunikation
- **Arduino Mega 2560** steuert LED-Ring (SpielLED + GrenzLED) sowie Spieler-Buttons/Encoder.
  - RS485-Transceiver an Serial1: TX = 18, RX = 19, DE/RE = Pin 2 (gemeinsam schaltbar).
  - SpielLED-Datenleitung: Pin 12; GrenzLED-Datenleitung: Pin 13.
- **Master-ESP32-S3 (Waveshare Touch LCD 4")** übernimmt Touch-Menü, Manifest-Logik, Admin-Funktionen.
  - RS485 UART2: GPIO 44 (TXD) → DI des Transceivers, GPIO 43 (RXD) ← RO, GPIO 21 als DE/RE (HIGH = senden).
  - Onboard-SP3485 nutzen; A/B-Leitungen mit dem Arduino-Transceiver verbinden.
- **Weitere ESP32-Displays** als Client-Knoten: per RS485-Daisy-Chain, identische A/B-Verbindung, Masse mitführen.
- RS485-Bus jeweils mit 120 Ω Abschlusswiderstand an den Enden, Bias-Widerstände am Master (z.B. 10 kΩ Pull-up A / Pull-down B).

## LED-Ring (72 Gruppen à 12 LEDs)
- Zwei Stränge à 36 Gruppen (SpielLED, GrenzLED); insgesamt 864 LEDs.
- Standardzuordnung:
  - SpielLED-Gruppen 1–36 → Spielfeldsegmente für Spiele.
  - GrenzLED-Gruppen 1–36 → Grenzen zwischen Spielern bzw. Joker.
- Für fünf Spieler ist SpielLED-Gruppe 2 reserviert (Joker); bei deaktiviertem Joker bleibt sie ausgeschaltet.
- Joker-Farbe und -Status werden über Admin-Optionen konfiguriert.

## Buttons & Encoder
- Spieler-Taster: je Spieler ein eigener Button, mit Arduino-Eingängen verbunden (mit Pull-down/-up entsprechend dem Schaltplan).
- Encoder mit Druck für Spieler 1 (Menüsteuerung):
  - CLK → Pin 6
  - DT → Pin 7
  - SW → Pin 5
- Weitere Encoder vorbereiten, aber erst aktivieren, wenn Firmware-Unterstützung vorliegt.

## Display-Zuordnung (nach Spieleranzahl)
- 2 Spieler: Screen 1 → Spieler 1, Screen 5 → Spieler 2
- 3 Spieler: Screen 8 → Spieler 1, Screen 3 → Spieler 2, Screen 6 → Spieler 3
- 4 Spieler: Screen 1 → Spieler 1, Screen 3 → Spieler 2, Screen 5 → Spieler 3, Screen 7 → Spieler 4
- 5 Spieler: Screen 8 → Spieler 1, Screen 2 → Spieler 2, Screen 3 → Spieler 3, Screen 5 → Spieler 4, Screen 7 → Spieler 5
- 6 Spieler: Screen 8 → Spieler 1, Screen 2 → Spieler 2, Screen 3 → Spieler 3, Screen 4 → Spieler 4, Screen 6 → Spieler 5, Screen 7 → Spieler 6
- Jeder aktive Screen spiegelt initial das Hauptmenü; während des Spiels zeigen die Displays Sitz-/Score-Informationen entsprechend der Zuordnung.
- microSD (FAT32) am Master-ESP32: Verzeichnisstruktur `/games`, `/options`, `/themes`, `/profiles`, `/music`, `/logos`, `/updates`, Manifest im Root.

## Besonderheiten & Betriebsannahmen
- Admin-Zugriff: Längerer Druck auf den dedizierten Admin-Button schaltet das Menü für 10 s frei; danach automatische Sperre.
- Netzwerk: Vorläufig lokales WLAN (falls aktiviert) und RS485; keine Cloud-Anbindung eingeplant.
- Manifest-Validierung: Master-ESP32 vergleicht Hashes beim Boot und vor jeder Session; Abweichungen blockieren den Spielstart.

## Sicherheit & Tests
- Isolationsmessung am LED-Ring vornehmen, bevor die volle Spannung anliegt.
- Not-Aus-Schalter sichtbar montieren und beschriften.
- Erstinbetriebnahme mit reduzierter LED-Helligkeit; RS485- und LED-Testbundles aus `/tests` ausführen, bevor die integrierte Firmware installiert wird.
