# Tasks: Pitter-o-mat Multiplayer Console

**Input**: Design documents from `/specs/001-pitter-o-mat/`  
**Prerequisites**: plan.md, spec.md, research.md, data-model.md, contracts/

**Tests**: Nicht explizit gefordert – Validierung erfolgt per Hardware-in-the-loop und manuellen Checks aus quickstart.md.

**Organisation**: Aufgaben sind nach User Stories gruppiert, damit jede Story unabhängig implementier- und testbar bleibt.

## Format: `[ID] [P?] [Story] Beschreibung`
- **[P]** kennzeichnet parallel ausführbare Tasks (verschiedene Dateien, keine Abhängigkeiten).
- **[Story]** verweist auf die zugehörige User Story (US1, US2, …).
- Alle Pfadangaben relativ zum Repository-Wurzelverzeichnis.

---

## Phase 1: Setup (Shared Infrastructure)

**Ziel**: Grundstruktur, Toolchains und Skriptabhängigkeiten anlegen.

- [ ] T001 [P] Lege Verzeichnisstruktur an (`firmware/arduino`, `firmware/esp32`, `firmware/shared`, `docs/hardware`, `docs/operations`).
- [ ] T002 Initialisiere PlatformIO-Projekt für Arduino Mega 2560 in `firmware/arduino/platformio.ini` inkl. FastLED-Abhängigkeit und serieller Monitor-Konfiguration.
- [ ] T003 [P] Richte ESP-IDF-Projekt in `firmware/esp32` ein (`CMakeLists.txt`, `idf.py set-target esp32s3`, minimaler `main/app_main.c`).
- [ ] T004 Dokumentiere EEZ-Studio-Exportprozess in `firmware/esp32/ui/README.md` (Touchscreen als primäre Navigation).
- [ ] T005 Erfasse Python-Tooling-Abhängigkeiten in `firmware/shared/scripts/requirements.txt` (CRC, RS485-Test, CLI-Tools).

---

## Phase 2: Foundational (Blocking Prerequisites)

**Ziel**: Basiskomponenten, die vor Story-Arbeit stehen müssen.

- [ ] T006 Erstelle LED-Segment-Mapping `firmware/shared/proto/segment_map.json` (Spiel-/GrenzLEDs inkl. Joker-Regel).
- [ ] T007 Implementiere RS485-Framing-Helfer `firmware/shared/proto/rs485_frame.py` (SYNC, Länge, CRC-8).
- [ ] T008 Baue Arduino-RS485-Treiber (`firmware/arduino/include/transport_rs485.h`, `src/transport_rs485.cpp`) für Halbduplex-Steuerung.
- [ ] T009 Implementiere ESP32-RS485-Treiber (`firmware/esp32/main/transport_rs485.c/.h`) inklusive DE-Pin-Steuerung.
- [ ] T010 Richte Konfigurationsspeicher ein (`firmware/arduino/src/storage_eeprom.cpp`, `firmware/esp32/main/storage_config.c`) für Joker/Optionen.
- [ ] T011 Lege HTTP-/status-Skeleton in `firmware/esp32/main/http_status_handler.c` an (JSON-Stub, später zu erweitern).
- [ ] T012 Dokumentiere Hardware-Bring-up in `docs/hardware/pitter-o-mat-setup.md` (Leistungsbudget, Verkabelung, Sicherheit).

**Checkpoint**: Transport, Storage und Dokumentation stehen → User Stories können starten.

---

## Phase 3: User Story 1 – Touch-Menü startet Spiel (Priority: P1) 🎯 MVP

**Ziel**: Touch-geführte Menüführung (Spieleranzahl, Spielauswahl, Joker) bis zum Spielstart, Encoder bleiben für Spiele reserviert.

**Independent Test**: Power-On → Touch-Auswahl `4 Spieler` + `LichtLoser` → Joker toggeln → Spiel starten; andere Encoder bleiben bis Start gesperrt.

### Implementation
- [ ] T013 [US1] Implementiere Session-State-Machine `firmware/arduino/src/session_controller.cpp` (Zustände Idle–Running, Joker-Flag, Broadcast).
- [ ] T014 [US1] Exportiere EEZ-Studio-Menü (`firmware/esp32/ui/menu_flow.eezi` + generierte Dateien) und binde Touch-Ereignisse in `firmware/esp32/main/ui_menu.c`.
- [ ] T015 [US1] Verkabele RS485-Kommandos (`firmware/arduino/src/session_commands.cpp`, `firmware/esp32/main/session_bus.c`) inkl. ACK/Fehlerbehandlung.
- [ ] T016 [US1] Implementiere `/game/session` POST/PATCH in `firmware/esp32/main/http_session.c` gemäss OpenAPI.
- [ ] T017 [US1] Blockiere Nicht-Spieler-Encoder bis zum Zustandswechsel Running in `firmware/arduino/src/encoder_manager.cpp`.
- [ ] T018 [P] [US1] Persiste Joker- und Modus-Config MikroSD↔EEPROM (`storage_config.c`, `storage_eeprom.cpp`) beim Boot/Änderung.
- [ ] T019 [US1] Aktualisiere quickstart (`specs/001-pitter-o-mat/quickstart.md`) mit Touch-MVP-Checkliste.

**Checkpoint**: Story 1 funktionsfähig → MVP vorhanden.

---

## Phase 4: User Story 2 – Sitzplätze & Grenzen visualisieren (Priority: P2)

**Ziel**: Displays und LED-Ring zeigen pro Spielerbereich korrekte Zuweisungen incl. Joker-Ausnahme.

**Independent Test**: Für 2–6 Spieler Touch-Auswahl durchspielen, LED/Grenz-Layout mit Prüftabelle abgleichen.

### Implementation
- [ ] T020 [US2] Erzeuge Mapping-Loader `firmware/arduino/src/segment_mapper.cpp`, generiere Spiel-/Grenzbereiche + Joker.
- [ ] T021 [US2] Implementiere GrenzLED-Renderer `firmware/arduino/src/led_boundary_renderer.cpp` (FastLED, dauerhafte Grenzen).
- [ ] T022 [US2] Aktualisiere Touch-UI für Sitzzuordnung `firmware/esp32/main/ui_player_rings.c` (Highlight aktiver Slots).
- [ ] T023 [US2] Erweitere `/status`-Antwort um Spielerbereiche (`http_status_handler.c`).
- [ ] T024 [P] [US2] Schreibe Diagnoseskript `firmware/shared/scripts/print_segments.py` zur CLI-Visualisierung.
- [ ] T025 [US2] Dokumentiere Prüfablauf in `docs/operations/seating-validation.md`.

**Checkpoint**: Story 1 + 2 unabhängig prüfbar.

---

## Phase 5: User Story 3 – Echtzeit-Gameplay-Feedback (Priority: P2)

**Ziel**: Score-Updates und Animationen reagieren <150 ms, SessionEventLog zeichnet Abläufe auf.

**Independent Test**: Simulation von Score-Events → Displays/LEDs aktualisieren, Event-Log enthält Einträge.

### Implementation
- [ ] T026 [US3] Ergänze Gameplay-Controller `firmware/arduino/src/gameplay_controller.cpp` (Scoring, Event-Publishing).
- [ ] T027 [US3] Implementiere ESP32-Event-Consumer `firmware/esp32/main/gameplay_events.c` (Display-/Animationstrigger).
- [ ] T028 [US3] Pflege Highscore-Speicher `firmware/esp32/main/highscore_store.c` (JSON pro Modus, Companion-App-Namen).
- [ ] T029 [US3] Erweitere `/game/session/current` PATCH für Laufzeitoptionen (Helligkeit, Joker) in `http_session.c`.
- [ ] T030 [P] [US3] Hinterlege LED-Animationen in `firmware/arduino/src/animations/` (Sieg/Wellen, Verlust/Fades).
- [ ] T031 [US3] CLI-Tool `firmware/shared/scripts/log_session_events.py` zum Auslesen/Archivieren von SessionEventLog.

**Checkpoint**: Spiel-Feedback voll funktionsfähig.

---

## Phase 6: User Story 4 – OTA-Updates verwalten (Priority: P3)

**Ziel**: Master-ESP verteilt Firmware an Clients, überwacht Status und pausiert Spielbetrieb.

**Independent Test**: Neue Firmware auf Master → Update anstoßen → alle Clients melden Erfolg oder Wiederholbedarf.

### Implementation
- [ ] T032 [US4] Implementiere OTA-Manager `firmware/esp32/main/ota_manager.c` (Broadcast + Downloadkoordination).
- [ ] T033 [US4] Schreibe Client-OTA-Komponente `firmware/esp32/components/client_fw/ota_client.c`.
- [ ] T034 [US4] Ergänze Arduino-Schutzlogik `firmware/arduino/src/ota_guard.cpp` (Pause/Resume).
- [ ] T035 [US4] Implementiere `/firmware/update` Endpoint `firmware/esp32/main/http_firmware.c`.
- [ ] T036 [US4] UI-Anzeige für Update-Status (`firmware/esp32/ui/options_update.eezi` + Binding).
- [ ] T037 [US4] Dokumentiere OTA-Playbook `docs/operations/ota-playbook.md`.

**Checkpoint**: OTA-Governance abgeschlossen; alle Stories umgesetzt.

---

## Phase 7: Polish & Cross-Cutting Concerns

- [ ] T038 [P] LED-Leistungsprofil testen (`firmware/shared/scripts/power_profile.py`) und Standardhelligkeit anpassen.
- [ ] T039 [P] Logging/Monitoring-Toggles in `firmware/esp32/main/logging.c` implementieren (Debug, Performance Overlay).
- [ ] T040 Quickstart & Operator-Dokumentation finalisieren (`quickstart.md`, `docs/operations`).
- [ ] T041 Messe Latenzen & halte Ergebnisse in `docs/operations/performance-results.md` fest.
- [ ] T042 Code-Style-Checks (clang-format, `idf.py format`, `pio check`) und Refactoring aufräumen.

---

## Dependencies & Execution Order

- **Phase 1 → Phase 2**: Aufbau & Infrastruktur vorbereiten.
- **Phase 2 → Story-Phasen**: RS485, Storage, Docs fertig → Stories können parallel starten.
- **US1 (P1)**: Basis für MVP – muss zuerst abgeschlossen werden.
- **US2 (P2)**: Benötigt Mapping (T006) und US1-Session-Kontext.
- **US3 (P2)**: Abhängig von RS485/Session aus US1 und LED-Mapping aus US2.
- **US4 (P3)**: Benötigt Transport/Session aus US1, ansonsten unabhängig.
- **Polish**: Nach gewünschter Story-Kombination abschließen.

---

## Parallel Execution Examples

- **Setup**: T001–T005 können parallel erledigt werden (getrennte Verzeichnisse/Tools).
- **US1**: T014 (EEZ-Export) kann parallel zu T013 (Arduino-State-Machine) laufen; T018 (Persistenz) parallel zu HTTP-Implementierung.
- **US2**: T024 (Diagnoseskript) parallel zu T021 (Renderer).
- **US3**: T030 (Animationen) parallel zu T027 (Event-Consumer).
- **Polish**: T038 und T039 adressieren unterschiedliche Bestandteile und blockieren sich nicht.

---

## Implementation Strategy

### MVP First
1. Phasen 1 & 2 abschließen.  
2. Phase 3 (US1) liefern → Touch-Menü & Spielstart lauffähig.  
3. Mit Quickstart-MVP-Checkliste validieren.

### Incremental Delivery
- Nach MVP: US2 (Sitzvisualisierung) hinzufügen → Testen → ggf. deployen.  
- Danach US3 (Realtime-Feedback) → testen → deployen.  
- Zuletzt US4 (OTA) für vollständige Betreiber-Funktionalität.

### Teamverteilung
- Firmware A: Arduino-Kern (T013, T020, T026, T034).  
- Firmware B: ESP32 UI/API (T014, T016, T022, T027, T035).  
- Tooling C: Skripte & Dokumentation (T005, T024, T031, T038–T041).

