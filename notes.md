# Projektnotizen – PitterOmat Kernerlebnis

## Allgemeiner Stand (17.10.2025)
- Aktives Feature: specs/002-clarify-pitteromat
- Spezifikation, Plan, Datenmodell, Quickstart und Tasks liegen komplett in Deutsch vor.
- Globale Verfassung (.specify/memory/constitution.md) greift für alle Features; gilt auch für dieses.

## Phasenfortschritt
- **Phase 1 (Setup)**: Erledigt (T001–T004 abgehakt)
- **Phase 2 (Fundament)**: In Arbeit (T005–T016 offen)
- **User Stories & Feinschliff**: Noch offen

## Checklistenstatus
- specs/002-clarify-pitteromat/checklists/anforderungen.md (17.10.2025) → Formaler Gate, alle 23 Punkte noch zu beantworten (kein Häkchen gesetzt).
- Vor Implementierung muss die Checkliste abgearbeitet werden.

## Technischer Kontext
- Sprache/Plattform: C++ (ESP32-S3), AVR-GCC (Arduino Mega 2560)
- RS485: UART2 (GPIO44→DI, GPIO43←RO, GPIO21 DE/RE), Arduino Serial1 (TX=18, RX=19, DE=Pin2)
- LED-Ring: Spiel/Grenz-LED-Stränge, Joker-Gruppe 2 bei fünf Spielern, Segment-Map in irmware/shared/proto/segment_map.json
- Manifest-Tool: irmware/shared/scripts/manifest_tool.py
- Hardware-Testpakete: 	ests/rs485-link, 	ests/led-ring, 	ests/display-sync; Skript zum Generieren (	ests/scripts/generate_bundles.py)

## Dokumentation & Ressourcen
- docs/hardware/pitter-o-mat-setup.md: komplette Verkabelung und Annahmen
- docs/operations/config-manifest.md: Manifest-/SD-Workflow (inkl. Bundleskript-Verweis)
- docs/operations/test-package-workflow.md: Aufbau & Ausführung der Testpakete
- 	ests/README.md: Überblick + Hinweis auf Generatorskript

## Tasks (Kurzüberblick)
- T005–T016: Manifest-Validierung, Testbundle-Feinschliff, Doku-Verweise
- T017–T024 (US1): Setup-Flow + Analyse EEZ-Studio-UI
- T025–T031 (US2): LED/Display-Logik & Dokumentation
- T032–T039 (US3): Admin-Diagnosen & Logik
- T040–T044: Feinschliff (Screenshots, FAQ, Smoke-Test, TODO-Bereinigung)

## Empfehlung für neue Sitzung
- Hinweise aus dieser 
notes.md angeben
- Aufgabenliste specs/002-clarify-pitteromat/tasks.md nutzen
- Checkliste checklists/anforderungen.md als Gate beachten
