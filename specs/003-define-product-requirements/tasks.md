---
description: "Task list for implementing PitterOmat v2 product requirements (Arduino Core workflow)"
---

# Tasks: PitterOmat v2 product requirements

**Input**: Design documents from `/specs/003-define-product-requirements/`  
**Prerequisites**: plan.md (completed), spec.md (completed), research.md, data-model.md, contracts/cabinet-api.yaml, quickstart.md

**Tests**: Bench diagnostic sketches uploaded via Arduino CLI/IDE as specified.

**Organization**: Tasks are grouped by user story to enable independent implementation and testing.

## Format: `[ID] [P?] [Story] Description`
- `[P]`: Parallel-safe (different files, no shared state)
- `[Story]`: User story label (e.g., US1, US2, US3)
- Include concrete file paths in descriptions and cite the constitution principle satisfied where relevant.

## Phase 1: Setup (Shared Infrastructure)

**Purpose**: Prepare shared Arduino build configuration and folder scaffold before feature work begins.

- [ ] T001 Create `firmware/arduino/arduino-cli.yaml` with ESP32-S3 Touch LCD and Mega 2560 board definitions
- [ ] T002 Add board install script `scripts/setup/install-arduino-cores.ps1` invoking `arduino-cli core install` (Principle III)
- [ ] T003 Scaffold shared include/lib folders (`firmware/common/include`, `firmware/common/src`) with placeholder README files

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Core infrastructure that MUST be complete before any user story can start.

- [ ] T004 Define protocol constants in `firmware/common/include/cabinet_protocol.h`
- [ ] T005 Implement ArduinoJson packet helpers in `firmware/common/src/protocol_json.cpp`
- [ ] T006 Build AsyncUDP sync handler in `firmware/esp32/src/lib/sync_channel.cpp` (Principle V)
- [ ] T007 Implement brightness clamp utility in `firmware/common/src/brightness_guard.cpp` (Principle IV)
- [ ] T008 Integrate clamp utility in Mega loop `firmware/arduino/mega_led_controller/PitterOmatMega.ino`
- [ ] T009 Add session persistence using SPIFFS in `firmware/esp32/src/lib/session_store.cpp`
- [ ] T010 Create Quickstart manifest bridge in `firmware/esp32/src/lib/manifest_bridge.cpp`
- [ ] T011 [P] Add bench sketch `firmware/esp32/tests/sync_baseline/sync_baseline.ino` checking broadcast/ack timing
- [ ] T012 [P] Add bench sketch `firmware/esp32/tests/brightness_guard/brightness_guard.ino` verifying the 55 percent clamp
- [ ] T013 [P] Add bench sketch `firmware/esp32/tests/idle_energy/idle_energy.ino` verifying dimming within 10 seconds

**Checkpoint**: Foundation ready - user story implementation can begin.

## Phase 3: User Story 1 - Launch a game night session (Priority: P1)

**Goal**: Players move from Idle to Menu to LichtLoser with synchronized displays and deterministic loser selection.  
**Independent Test**: Bench setup: upload master sketch, run sync and brightness diagnostics, verify Idle -> Menu -> Game transition stays under 3 seconds and Joker effects trigger correctly.

### Implementation
- [ ] T014 [US1] Implement master sketch `firmware/esp32/src/PitterOmatMaster.ino` (setup/loop scaffold)
- [ ] T015 [P] [US1] Update LVGL Idle/Menu screens in `firmware/esp32/ui/src/idle_menu_screens.cpp`
- [ ] T016 [US1] Broadcast seat overlays from `firmware/esp32/src/lib/session_controller.cpp`
- [ ] T017 [US1] Implement `/sessions` handling inside `firmware/esp32/src/lib/api_sessions.cpp`
- [ ] T018 [US1] Aggregate cabinet state for `/state` view in `firmware/esp32/src/lib/api_state.cpp`
- [ ] T019 [US1] Add quintic spin routine in `firmware/arduino/mega_led_controller/src/spin_engine.cpp`
- [ ] T020 [US1] Render Joker highlight and skip logic in `firmware/esp32/src/lib/joker_controller.cpp`
- [ ] T021 [US1] Update scoreboard rendering in `firmware/esp32/ui/src/score_screen.cpp`
- [ ] T022 [P] [US1] Document bench validation steps in `firmware/esp32/tests/sync_baseline/README.md`

**Checkpoint**: User Story 1 delivers the MVP gameplay loop and passes the bench validation.

## Phase 4: User Story 2 - Quickstart replay and player options (Priority: P2)

**Goal**: Hosts replay LichtLoser rapidly while adjusting rounds, speed, and Joker settings.  
**Independent Test**: Finish a session, trigger Quickstart, edit options, and confirm relaunch under 5 seconds with the updated configuration.

### Implementation
- [ ] T023 [US2] Persist session parameters via `firmware/esp32/src/lib/quickstart_store.cpp`
- [ ] T024 [P] [US2] Add LVGL options screen in `firmware/esp32/ui/src/options_screen.cpp`
- [ ] T025 [US2] Implement PATCH logic in `firmware/esp32/src/lib/api_sessions.cpp`
- [ ] T026 [US2] Wire Quickstart button handler in `firmware/esp32/src/lib/quickstart_button.cpp`
- [ ] T027 [P] [US2] Create bench checklist `firmware/esp32/tests/quickstart/quickstart.md` (steps + expected timings)

**Checkpoint**: User Story 2 enables rapid replay with full option control.

## Phase 5: User Story 3 - Admin ambience and protection (Priority: P2)

**Goal**: Administrators adjust lighting, brightness, energy saver, and diagnostics with PIN protection.  
**Independent Test**: Enter admin mode, change settings, verify the 55 percent clamp and 10 +/- 1 second auto-lock, and confirm diagnostics run without affecting gameplay.

### Implementation
- [ ] T028 [US3] Implement PIN timer and relock in `firmware/esp32/src/lib/admin_pin_gate.cpp`
- [ ] T029 [P] [US3] Persist ambience settings in `firmware/esp32/src/lib/config_store.cpp`
- [ ] T030 [US3] Add LVGL admin screens in `firmware/esp32/ui/src/admin_settings_screen.cpp`
- [ ] T031 [US3] Implement `/admin/settings` handler in `firmware/esp32/src/lib/api_admin.cpp`
- [ ] T032 [US3] Implement `/admin/ticker` handler writing `config/admin/news_ticker.json`
- [ ] T033 [US3] Roll back pending admin changes on timeout in `firmware/esp32/src/lib/admin_pin_gate.cpp`
- [ ] T034 [P] [US3] Implement debug overlay toggles in `firmware/esp32/src/lib/debug_overlay.cpp`
- [ ] T035 [P] [US3] Implement latency probe view in `firmware/esp32/src/lib/debug_latency.cpp`
- [ ] T036 [P] [US3] Implement LED diagnostic routine in `firmware/arduino/mega_led_controller/src/led_diagnostic.cpp`
- [ ] T037 [US3] Implement SD log export workflow in `firmware/esp32/src/lib/debug_log_export.cpp`
- [ ] T038 [P] [US3] Create bench sketch `firmware/esp32/tests/admin_timeout/admin_timeout.ino` verifying PIN auto-lock
- [ ] T039 [P] [US3] Create bench sketch `firmware/esp32/tests/debug_suite/debug_suite.ino` covering overlay toggles, latency probe, LED diagnostic, and SD export

**Checkpoint**: User Story 3 fulfils safety and diagnostic requirements.

## Final Phase: Polish and cross-cutting concerns

- [ ] T040 Update `specs/003-define-product-requirements/quickstart.md` (add sections for debug diagnostics sweep and idle energy saver)
- [ ] T041 Update manifest entries for new assets in `sd/manifest.json`
- [ ] T042 Archive bench logs (sync, clamp, energy saver, debug) in `tests/succeeded/README.md`
- [ ] T043 Capture readability scores and operator approvals in `docs/release-notes/pitteromat_v2.md` (store evidence in `docs/reviews/operator-approval.md`)
- [ ] T044 Run end-to-end operator dry run and extend `docs/release-notes/pitteromat_v2.md` (add "Field validation" section)

## Dependencies and execution order

- Foundational tasks (T004-T013) depend on Setup (T001-T003) and block all user stories.
- User Story 1 (T014-T022) depends on Foundational completion.
- User Story 2 (T023-T027) depends on Quickstart storage and APIs delivered in User Story 1.
- User Story 3 (T028-T039) depends on Foundational tasks plus shared state from User Story 1.
- Polish tasks (T040-T044) depend on completion of the relevant user stories and bench evidence.

## Parallel execution examples

- After T006 finishes, T015 and T016 can run in parallel (UI vs. session controller).
- T019 (spin engine) and T020 (Joker logic) can proceed together once T007 is complete.
- In User Story 2, T024 (UI) and T025 (API) can run in parallel once T023 is done.
- In User Story 3, T034-T036 can progress simultaneously after T033 finalises rollback logic.
- Bench sketches T011-T013 and T038-T039 can be created independently.

## Implementation strategy

### MVP first (User Story 1)
1. Complete Setup and Foundational phases.
2. Deliver User Story 1 tasks (T014-T021).
3. Execute the bench checklist (T022) and confirm Quickstart prerequisites are ready.

### Incremental delivery
- Flash MVP (US1) to the test cabinet.
- Add Quickstart (US2) and verify timing metrics.
- Layer admin controls and diagnostics (US3), then finish documentation and evidence tasks.

### Parallel team strategy
- Developer A: Sync and protocol layer (T004-T006, T016-T018).
- Developer B: LVGL screens (T015, T024, T030, T021).
- Developer C: Admin/debug logic (T028-T037) and bench sketches (T011-T013, T038-T039).
- Developer D: Arduino Mega firmware (T007-T008, T019, T036) plus documentation tasks (T040-T044).
