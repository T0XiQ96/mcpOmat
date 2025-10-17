# Aufgaben: PitterOmat Kernerlebnis

**Eingangsdokumente**: Unterlagen aus /specs/002-clarify-pitteromat/
**Voraussetzungen**: plan.md, spec.md, research.md, data-model.md, contracts/

**Tests**: Nur dort, wo Diagnosen oder Manifest-Validierung explizit gefordert sind.

**Organisation**: Aufgaben sind nach User Story gruppiert, damit jede Story unabhaengig implementiert und getestet werden kann.

## Format: [ID] [P?] [Story] Beschreibung
- **[P]**: Aufgabe kann parallel laufen (keine Abhaengigkeiten, andere Dateien)
- **[Story]**: Label der User Story (US1, US2, US3) – nur in den Story-Phasen erforderlich
- Exakte Dateipfade immer angeben

## Phase 1: Setup (Gemeinsame Infrastruktur)

**Ziel**: Dokumentationsgrundlagen und SD-Arbeitsbereich bereitstellen.

- [x] T001 Dokumentiere Hardwareverkabelung in docs/hardware/pitter-o-mat-setup.md
- [x] T002 Fuege Waveshare-TREIBER-Verweis in tests/README.md hinzu
- [x] T003 [P] Aktualisiere docs/operations/test-package-workflow.md mit Bundlenamen
- [x] T004 [P] Lege SDCARD/README.md fuer manifest_tool Nutzung an

---

## Phase 2: Fundament (Blockierende Voraussetzungen)

**Ziel**: Manifest-Tooling, RS485-Grundlagen und lauffaehige Testbundles erstellen.

- [x] T005 Validiere firmware/shared/proto/manifest.schema.json gegen Draft-07
- [x] T006 Erzeuge Beispiel-Assets in SDCARD/games/sample-game.json und SDCARD/options/sample-options.json
- [x] T007 [P] Fuehre python -m firmware.shared.scripts.manifest_tool generate --root SDCARD --output SDCARD/manifest.json aus
- [x] T008 [P] Dokumentiere python -m firmware.shared.scripts.manifest_tool validate SDCARD/manifest.json --root SDCARD in docs/operations/config-manifest.md
- [x] T009 Implementiere RS485-Frame-Handling in firmware/esp32/main/transport_rs485.c
- [x] T010 Spiegele RS485-Frame-Handling in firmware/arduino/src/transport_rs485.cpp
- [x] T011 Erstelle tests/scripts/generate_bundles.py zum Kopieren der TREIBER-Demos
- [x] T012 [P] Fuehre das Skript aus und pruefe tests/rs485-link, tests/led-ring, tests/display-sync
- [x] T013 Ueberarbeite tests/rs485-link/README.md und expected.log (Hash-Echo)
- [x] T014 [P] Ergaenze tests/led-ring/README.md und expected.log um Joker-/Boundary-Pruefungen
- [x] T015 [P] Ergaenze tests/display-sync/README.md und expected.log um Sitzplatz-/Hash-Checks
- [x] T016 Aktualisiere docs/operations/config-manifest.md mit Verweis auf das Bundleskript

---

## Phase 3: User Story 1 – Gefuehrtes Spiel-Setup (Prioritaet: P1) – MVP

**Ziel**: Touch-basiertes Setup vom Idle-Screen bis zum Spielstart mit Ready-Checks fuer 2-6 Spieler.

**Unabhaengiger Test**: Vier Spieler waehlen, Spiel starten, alle Ready-Taster betaetigen, automatischen Start ohne Admin-Beteiligung beobachten.

### Umsetzung

- [ ] T017 [US1] Pruefe und aktualisiere firmware/shared/proto/segment_map.json bei Bedarf
- [ ] T018 [US1] Implementiere Spielerzahlauswahl + Spielfilter in firmware/esp32/main/ui_menu.c
- [ ] T019 [US1] Sende Session-Konfiguration (Msg 0x01) in firmware/esp32/main/session_bus.c
- [ ] T020 [US1] Verarbeite Ready-Button-Maske (Msg 0x06) in firmware/esp32/main/session_bus.c
- [ ] T021 [US1] Steuere ReadyCheck-Zustaende in firmware/arduino/src/session_controller.cpp
- [ ] T022 [US1] Persistiere letzte Spielerzahl/Spielwahl in firmware/esp32/main/storage_config.c
- [ ] T023 [US1] Ergaenze docs/operations/quickstart.md um Ready-Check Walkthrough
- [ ] T024 [US1] Analysiere exportiertes EEZ-Studio-UI und dokumentiere Variablen/Schnittstellen (z.B. in plan.md)

---

## Phase 4: User Story 2 – LED- & Display-Orchestrierung (Prioritaet: P2)

**Ziel**: LED-Grenzen, Joker-Logik und Sitzanzeigen bleiben konsistent zur Manifest-Zuordnung.

**Unabhaengiger Test**: Fuenfspieler-Runde ohne Joker starten; SpielLED-Gruppe 2 bleibt aus, Grenzen leuchten konstant, Displays zeigen korrekte Sitzlabels.

### Umsetzung

- [ ] T025 [P] [US2] Generiere LED-Mapping-Payload (Msg 0x02) in firmware/esp32/main/led_mapper.c
- [ ] T026 [US2] Uebernehme das Mapping in firmware/arduino/src/led_boundary_renderer.cpp
- [ ] T027 [US2] Implementiere Joker-Hervorhebung in firmware/arduino/src/led_boundary_renderer.cpp
- [ ] T028 [US2] Synchronisiere Sitzanzeigen in firmware/esp32/main/ui_player_rings.c
- [ ] T029 [US2] Loese Sieger-/Verlierer-Animationen (Msg 0x07) in firmware/esp32/main/gameplay_events.c aus
- [ ] T030 [US2] Ergaenze docs/operations/config-manifest.md um LED-Pruefliste
- [ ] T031 [US2] Aktualisiere tests/led-ring/expected.log mit Joker-/Boundary-Pruefungen

---

## Phase 5: User Story 3 – Admin-Ueberwachung & Synchronisation (Prioritaet: P3)

**Ziel**: Diagnosen, Manifest-Sync und zeitgesteuerte Admin-Freigabe abbilden.

**Unabhaengiger Test**: Admin-Button halten, Manifest-Abgleich und RS485/LED-Tests ausfuehren, innerhalb von 10 s zuruecksperren, Statusanzeigen pruefen.

### Umsetzung

- [ ] T032 [P] [US3] Implementiere Admin-Freigabetimer in firmware/esp32/main/admin_controls.c
- [ ] T033 [US3] Binde Manifest-Hash-Status in firmware/esp32/ui/options_admin.eezi ein
- [ ] T034 [US3] Sende Manifest-Hash (Msg 0x05) in firmware/esp32/main/manifest_sync.c
- [ ] T035 [US3] Bestaetige Manifest-Hash in firmware/arduino/src/manifest_sync.cpp
- [ ] T036 [US3] Verknuepfe RS485/WLAN-Diagnosen in firmware/esp32/main/admin_diagnostics.c
- [ ] T037 [US3] Schreibe Diagnoseprotokolle in firmware/esp32/main/log_store.c
- [ ] T038 [US3] Messe den Diagnoseablauf (<= 2 min) und dokumentiere in docs/operations/performance-results.md
- [ ] T039 [US3] Aktualisiere docs/operations/ota-playbook.md und docs/operations/test-package-workflow.md

---

## Phase N: Feinschliff & Querschnitt

**Ziel**: Endgueltige Dokumentation, End-to-End-Validierung und Aufraeumen.

- [ ] T040 [P] Ergaenze docs/operations/quickstart.md um finale Screenshots/Logs
- [ ] T041 Ergaenze docs/operations/config-manifest.md um FAQ zur Manifest-Wiederherstellung
- [ ] T042 [P] Pruefe, dass alle Bundles in tests/succeeded/ aktuelle README und expected.log besitzen
- [ ] T043 Fuehre den kompletten Smoke-Test (Quickstart) aus und protokolliere in docs/operations/performance-results.md
- [ ] T044 Bereinige TODO/FIXME-Kommentare im Firmware-Code und ueberfuehre offene Punkte in den Backlog

---

## Abhaengigkeiten & Reihenfolge

- **Phase 1 -> Phase 2**: Setup liefert Grundlagen; Fundament setzt darauf auf.
- **Phase 2 -> User Stories**: RS485, Manifest und Testbundles muessen abgeschlossen sein, bevor Stories umgesetzt werden.
- **User Stories**: Reihenfolge nach Prioritaet (US1 MVP -> US2 Visuals -> US3 Admin). Jede Story wird danach eigenstaendig testbar.
- **Feinschliff**: Nach Abschluss der Stories.

### User-Story-Abhaengigkeitsgraph
`
US1 (Setup)  --> ermoeglicht LED-Mapping (US2)
US1 (Setup)  --> ermoeglicht Admin-Ueberwachung (US3)
US2 und US3 koennen parallel umgesetzt werden
`

### Parallelisierung
- Phase 1: T002/T003/T004 parallel zu T001
- Phase 2: T007/T008 nach T006; T012 parallel zu T009/T010; T014/T015 parallel
- US2: T025 und T028 koennen parallel starten
- US3: T032 und T034 parallel, Zusammenfuehrung bei UI/Logs

---

## Umsetzungsstrategie

### MVP zuerst (User Story 1)
1. Phasen 1 und 2 abschliessen.
2. US1-Aufgaben (T017–T024) erledigen.
3. Gefuehrten Setup-Test laut Quickstart ausfuehren.

### Inkrementelle Lieferung
1. US1 als MVP liefern.
2. US2 ergaenzen und Joker-/Display-Pruefung fahren.
3. US3 ergaenzen und Diagnoserunde fahren.

### Parallelteam
- Entwickler A: RS485 + Session (Phase 2 + US1)
- Entwickler B: LED/Display (US2)
- Entwickler C: Admin/Manifest (US3)