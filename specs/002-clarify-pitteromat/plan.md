# Implementierungsplan: PitterOmat Kernerlebnis

**Branch**: `002-clarify-pitteromat` | **Datum**: 17.10.2025 | **Spec**: [specs/002-clarify-pitteromat/spec.md](./spec.md)  
**Eingabe**: Funktionsspezifikation aus `/specs/002-clarify-pitteromat/spec.md`

## Zusammenfassung

Wir liefern das komplette PitterOmat-Erlebnis: Touch-gestütztes Spiel-Setup, Manifest-gesteuerte LED- und Display-Orchestrierung sowie Admin-Kontrollen, die Firmware und Inhalte zwischen ESP32- und Arduino-Knoten synchron halten. Grundlage sind schema-validierte SD-Assets, ein gemeinsames RS485-Protokoll und Hardwaretests auf Basis der Waveshare-TREIBER-Demos, bevor eine Gesamtfirmware entsteht.

## Technischer Kontext

**Sprache/Version**: C++ (Arduino Core für ESP32-S3 3.x) & AVR-GCC für Arduino Mega 2560  
**Hauptabhängigkeiten**: LVGL-UI-Exporte aus EEZ Studio, Adafruit_NeoPixel/FastLED, gemeinsames `manifest_tool`, CRC-8-RS485-Framing-Helfer, Waveshare-TREIBER-Demos  
**Speicher**: microSD (FAT32) auf dem Master-ESP32-S3 für Spiele/Optionen/Themes/Highscores  
**Tests**: Hardware-Smoke-Tests aus Waveshare-TREIBER-Bundles plus `manifest_tool` (Generate/Validate) – dokumentiert in research.md  
**Zielplattform**: Waveshare ESP32-S3 Touch LCD 4 (Master + bis zu 7 Spiegel-Clients), Arduino Mega 2560 (LED-Ring & Eingaben)  
**Projekttyp**: Mehrgeräte-Embedded-System (ESP32-Master + Arduino-Co-Prozessor + SD-Inhalte)  
**Performanceziele**: Idle → Gameplay < 90 s; LED-Aktualisierung ≤ 50 ms rund um den Ring; Admin-Diagnosen ≤ 2 min; Manifest-Sync vor jeder Sitzung  
**Randbedingungen**: Offline-fähig; 5 V/40 A Stromversorgung; RS485 bei 115 200 Baud; Admin-Optionen per 10 s Button-Hold freigeschaltet  
**Skalierung/Scope**: Unterstützt 2–6 gleichzeitige Spieler auf einem Gerät; ein SD-Content-Bundle pro Release-Zyklus

## Verfassungs-Check

*Gate: Muss vor Phase-0-Recherche erfüllt sein; nach Phase 1 erneut prüfen.*

- **Prinzip I – Manifest-Integrität**: Quickstart verlangt `manifest_tool generate/validate` sowie Bundle-Hash-Prüfung vor Deployments. **ERFÜLLT** (Automatisierungsdetails in research.md).  
- **Prinzip II – Schema-basierte Modularität**: Spiele/Optionen bleiben an `game.schema.json` und `options.schema.json` gebunden; Validierung ist in Phase 1 verankert. **ERFÜLLT**.  
- **Prinzip III – Hardwarevalidierung mit offiziellen Treibern**: Test-Bundles erweitern die Waveshare-TREIBER-Demos (RS485, LED, Displays, Diagnosen) vor einem Integrations-Build. **ERFÜLLT**.  
- **Prinzip IV – LED- & Sitz-Mapping-Fidelity**: Design-Artefakte folgen `segment_map.json` und den Randfällen aus der Spec; LED-Smoke-Tests sichern die Umsetzung. **ERFÜLLT**.  
- **Prinzip V – Koordinierte Updates & Sync**: Manifest-Hash-Abgleich, Admin-Override-Fluss und Spielsperre bei Abweichungen sind im Plan verankert. **ERFÜLLT**.

## Projektstruktur

### Dokumentation (dieses Feature)

```
specs/002-clarify-pitteromat/
├── plan.md
├── research.md
├── data-model.md
├── quickstart.md
└── contracts/
```

### Quellcode (Repository-Wurzel)

```
firmware/
├── arduino/            # Arduino-Mega-Firmware (LED-Ring, Buttons, RS485)
│   └── src/
├── esp32/              # ESP32-S3-Firmware (UI, Manifest-Sync, Admin-Tools)
│   ├── main/
│   ├── tests/
│   └── ui/
└── shared/             # Gemeinsame Protos/Skripte (Manifest-Schemata, RS485-Frame-Helfer)

docs/
├── hardware/           # Bring-up-Checklisten
└── operations/         # Manifest- und Test-Workflows

tests/
├── rs485-link/         # TREIBER-basierte RS485-Validierungspakete
├── led-ring/           # LED-Animations- und Mapping-Validierung
└── display-sync/       # Display-Ausrichtung & Hash-Prüfungen
```

**Strukturentscheidung**: Die bestehende Aufteilung (`firmware/arduino`, `firmware/esp32`, `firmware/shared`) bleibt bestehen; `/tests` wird mit TREIBER-basierten Bundles ausgebaut und die Betriebshandbücher unter `docs/operations` werden erweitert. Die Feature-Dokumentation bleibt aus Gründen der Nachvollziehbarkeit unter `specs/002-clarify-pitteromat/`.

## Komplexitätstracking

| Verstoß | Begründung | Einfachere Alternative verwarf man, weil |
|---------|-----------|------------------------------------------|
| _Keine_ | – | – |
