# Aufgaben: PitterOmat Kernerlebnis

**Eingangsdokumente**: Unterlagen aus `/specs/002-clarify-pitteromat/`  
**Voraussetzungen**: plan.md, spec.md, research.md, data-model.md, contracts/

**Tests**: Nur dort, wo Diagnosen oder Manifest-Validierung eine explizite Prüfung benötigen.

**Organisation**: Aufgaben sind nach User Stories gruppiert, damit jede Story unabhängig implementiert und getestet werden kann.

## Format: `[ID] [P?] [Story] Beschreibung`
- **[P]**: Aufgabe kann parallel laufen (unabhängige Dateien, keine offenen Abhängigkeiten).
- **[Story]**: Label der User Story (US1, US2, US3) – nur in Story-Phasen erforderlich.
- Jede Beschreibung enthält den exakten Dateipfad.

## Phase 1: Setup (Gemeinsame Infrastruktur)

**Ziel**: Dokumentationsgrundlagen und SD-Arbeitsbereich für alle Stories bereitstellen.

- [DONE] T001 Dokumentiere aktuelle Hardwareverkabelung in docs/hardware/pitter-o-mat-setup.md
- [DONE] T002 Ergänze in tests/README.md einen Verweis auf die Waveshare-TREIBER-Quellen
- [DONE] T003 [P] Aktualisiere docs/operations/test-package-workflow.md mit Namenskonventionen für neue Bundles
- [DONE] T004 [P] Lege SDCARD/README.md als Anleitung für den Einsatz von manifest_tool an

---

## Phase 2: Fundament (Blockierende Voraussetzungen)

**Ziel**: Manifest-Tooling, gemeinsames RS485-Framing und Basis-Testbundles herstellen.

- [ ] T005 Validiere firmware/shared/proto/manifest.schema.json gegen den JSON-Schema-Standard (Draft-07)
- [ ] T006 Erzeuge Beispiel-Assets in SDCARD/games/sample-game.json und SDCARD/options/sample-options.json
- [ ] T007 [P] Führe python -m firmware.shared.scripts.manifest_tool generate --root SDCARD --output SDCARD/manifest.json aus
- [ ] T008 [P] Dokumentiere python -m firmware.shared.scripts.manifest_tool validate SDCARD/manifest.json --root SDCARD in docs/operations/config-manifest.md
- [ ] T009 Implementiere RS485-Frame-Encoding/Decoding in firmware/esp32/main/transport_rs485.c basierend auf dem gemeinsamen Proto
- [ ] T010 Spiegle die RS485-Frame-Verarbeitung in firmware/arduino/src/transport_rs485.cpp
- [ ] T011 Lege tests/rs485-link Bundle mit adaptiertem TREIBER-RS485-Demo und Hash-Echo an
- [ ] T012 [P] Lege tests/led-ring Bundle mit TREIBER-LED-Demo und Segment-Map-Validierung an
- [ ] T013 Ergänze docs/operations/config-manifest.md um Hinweise zum Manifest-Workflow gemäß research.md

---

## Phase 3: User Story 1 – Geführtes Spiel-Setup (Priorität: P1) – MVP

**Ziel**: Touch-basiertes Setup vom Idle-Screen bis zum Spielstart mit Ready-Checks für 2–6 Spieler.

**Unabhängiger Test**: Vier Spieler auswählen, Spiel starten, Ready-Taster betätigen lassen und automatischen Spielstart ohne Admin-Eingriff beobachten.

### Umsetzung

- [ ] T014 [US1] Prüfe und aktualisiere bei Bedarf firmware/shared/proto/segment_map.json entsprechend der Spezifikation
- [ ] T015 [US1] Implementiere Spielerzahlauswahl und Spielfilter in firmware/esp32/main/ui_menu.c
- [ ] T016 [US1] Sende die Session-Konfiguration (RS485-Nachricht 0x01) über firmware/esp32/main/session_bus.c
- [ ] T017 [US1] Verarbeite den Ready-Button-Maskenwert (Nachricht 0x06) in firmware/esp32/main/session_bus.c
- [ ] T018 [US1] Steuere den ReadyCheck-Zustand in firmware/arduino/src/session_controller.cpp
- [ ] T019 [US1] Speichere letzte Spieleranzahl und Spielwahl in firmware/esp32/main/storage_config.c
- [ ] T020 [US1] Ergänze docs/operations/quickstart.md um den geführten Setup-Ablauf

---

## Phase 4: User Story 2 – LED- & Display-Orchestrierung (Priorität: P2)

**Ziel**: LED-Grenzen, Joker-Verhalten und Sitzanzeigen bleiben konsistent zum Manifest und Sitzplan.

**Unabhängiger Test**: Fünfspieler-Session ohne Joker starten; SpielLED-Gruppe 2 bleibt aus, Grenzen leuchten konstant, Displays zeigen korrekte Sitzlabels.

### Umsetzung

- [ ] T021 [P] [US2] Generiere LED-Mapping-Payload (Nachricht 0x02) in firmware/esp32/main/led_mapper.c
- [ ] T022 [US2] Übernimm das Mapping in firmware/arduino/src/led_boundary_renderer.cpp
- [ ] T023 [US2] Implementiere Joker-Hervorhebung in firmware/arduino/src/led_boundary_renderer.cpp
- [ ] T024 [US2] Synchronisiere Sitzanzeigen in firmware/esp32/main/ui_player_rings.c anhand der PlayerSlot-Daten
- [ ] T025 [US2] Löse Sieger-/Verlierer-Animationen (Nachricht 0x07) in firmware/esp32/main/gameplay_events.c aus
- [ ] T026 [US2] Ergänze docs/operations/config-manifest.md um eine LED-Prüfliste
- [ ] T027 [US2] Aktualisiere tests/led-ring/expected.log mit Joker- und Grenzprüfungen

---

## Phase 5: User Story 3 – Admin-Überwachung & Synchronisation (Priorität: P3)

**Ziel**: Diagnosen, Manifest-Sync und zeitgesteuerte Admin-Freigabe für Operatoren bereitstellen.

**Unabhängiger Test**: Admin-Button halten, Manifest-Abgleich und RS485/LED-Diagnosen ausführen, innerhalb von 10 Sekunden zurücksperren und Statusmeldungen prüfen.

### Umsetzung

- [ ] T028 [P] [US3] Implementiere den Admin-Freigabetimer in firmware/esp32/main/admin_controls.c
- [ ] T029 [US3] Binde Manifest-Hash-Status in firmware/esp32/ui/options_admin.eezi ein
- [ ] T030 [US3] Sende Manifest-Hash (Nachricht 0x05) in firmware/esp32/main/manifest_sync.c
- [ ] T031 [US3] Bestätige Manifest-Hash in firmware/arduino/src/manifest_sync.cpp
- [ ] T032 [US3] Verknüpfe RS485/WLAN-Diagnosen in firmware/esp32/main/admin_diagnostics.c
- [ ] T033 [US3] Schreibe Diagnoseprotokolle in firmware/esp32/main/log_store.c
- [ ] T034 [US3] Messe den Diagnoseablauf (≤ 2 Minuten) und notiere Ergebnisse in docs/operations/performance-results.md
- [ ] T035 [US3] Aktualisiere docs/operations/ota-playbook.md und docs/operations/test-package-workflow.md mit dem Admin-Prozess

---

## Phase N: Feinschliff & Querschnitt

**Ziel**: Abschlussdokumentation, End-to-End-Validierung und Aufräumarbeiten nach allen Stories.

- [ ] T036 [P] Ergänze docs/operations/quickstart.md um Screenshots oder annotierte Logs aus dem finalen Testlauf
- [ ] T037 Ergänze in docs/operations/config-manifest.md einen FAQ-Eintrag zur Manifest-Wiederherstellung
- [ ] T038 [P] Prüfe, dass alle Bundles in tests/succeeded/ ein aktuelles expected.log und README besitzen
- [ ] T039 Führe den vollständigen Smoke-Test (Quickstart) aus und protokolliere die Ergebnisse in docs/operations/performance-results.md
- [ ] T040 Bereinige TODO/FIXME-Kommentare im Firmware-Code und überführe offene Punkte in den Backlog

---

## Abhängigkeiten & Reihenfolge

- **Phase 1 → Phase 2**: Setup liefert Grundlagen; Fundament baut auf vorhandenen Assets/Tooling auf.
- **Phase 2 → User Stories**: RS485, Manifest und Testbundles müssen stehen, bevor Stories beginnen.
- **User Stories**: Reihenfolge nach Priorität (US1 MVP → US2 Visuals → US3 Admin). Jede Story ist danach eigenständig testbar.
- **Feinschliff**: Läuft nach Abschluss der gewünschten Stories.

### User-Story-Abhängigkeitsgraph

```
US1 (Setup)  --> ermöglicht LED-Mapping (US2)
US1 (Setup)  --> ermöglicht Admin-Überwachung (US3)
US2 und US3 können unabhängig voneinander umgesetzt werden
```

### Parallelisierungsmöglichkeiten

- Phase 1: T002, T003 und T004 parallel zu T001.
- Phase 2: T007 und T008 nach T006; T011 und T012 parallel.
- US2: T021 und T024 parallel, vor Integration in T022.
- US3: T028 und T030 parallel, Zusammenführung bei UI-Aufgaben.

---

## Umsetzungsstrategie

### MVP zuerst (User Story 1)
1. Phasen 1 und 2 abschließen.  
2. US1-Aufgaben (T014–T020) erledigen.  
3. Geführten Setup-Test gemäß Quickstart durchführen.

### Inkrementelle Lieferung
1. US1 als MVP abschließen.  
2. US2 hinzufügen und Fünfspieler-/Joker-Szenario testen.  
3. US3 hinzufügen und vollständigen Diagnosedurchlauf ausführen.

### Parallelstrategie im Team
- Entwickler A: RS485 + Session-Kontrolle (Phase 2 + US1).  
- Entwickler B: LED-Mapping & Display (US2).  
- Entwickler C: Admin-Diagnosen & Manifest-Sync (US3).
