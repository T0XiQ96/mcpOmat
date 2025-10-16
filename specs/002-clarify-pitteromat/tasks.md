# Tasks: PitterOmat Core Experience

**Input**: Design documents from `/specs/002-clarify-pitteromat/`
**Prerequisites**: plan.md, spec.md, research.md, data-model.md, contracts/

**Tests**: Included only where diagnostics or manifest validation require explicit verification.

**Organization**: Tasks are grouped by user story to enable independent implementation and testing of each story.

## Format: `[ID] [P?] [Story] Description`
- **[P]**: Task can run in parallel (different files, no dependencies)
- **[Story]**: User story label (US1, US2, US3) for story phases
- Every description includes exact file paths

## Phase 1: Setup (Shared Infrastructure)

**Purpose**: Establish documentation references and SD workspace needed across stories.

- [ ] T001 Document current hardware wiring assumptions in docs/hardware/pitter-o-mat-setup.md
- [ ] T002 Add TREIBER source reference to tests/README.md for hardware bundles
- [ ] T003 [P] Update docs/operations/test-package-workflow.md with naming guidance for new bundles
- [ ] T004 [P] Create placeholder SDCARD/README.md describing manifest_tool usage workflow

---

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Implement manifest tooling, shared RS485 framing, and baseline hardware bundles required before story work.

- [ ] T005 Validate firmware/shared/proto/manifest.schema.json against JSON Schema draft-07 rules
- [ ] T006 Create sample SD assets in SDCARD/games/sample-game.json and SDCARD/options/sample-options.json following schemas
- [ ] T007 [P] Run python -m firmware.shared.scripts.manifest_tool generate --root SDCARD --output SDCARD/manifest.json
- [ ] T008 [P] Run python -m firmware.shared.scripts.manifest_tool validate SDCARD/manifest.json --root SDCARD and capture output in docs/operations/config-manifest.md
- [ ] T009 Implement RS485 frame encode/decode in firmware/esp32/main/transport_rs485.c using shared proto
- [ ] T010 Mirror RS485 frame parsing in firmware/arduino/src/transport_rs485.cpp
- [ ] T011 Seed tests/rs485-link bundle by adapting TREIBER RS485 demo with manifest hash echo and expected.log
- [ ] T012 [P] Seed tests/led-ring bundle by adapting TREIBER LED demo with segment map verification script
- [ ] T013 Add manifest workflow note to docs/operations/config-manifest.md referencing research decisions

---

## Phase 3: User Story 1 - Guided Game Setup (Priority: P1) - MVP

**Goal**: Touch-driven setup flow from idle to gameplay with ready checks for 2-6 players.

**Independent Test**: Select four players, choose a valid game, have each player confirm readiness, and observe gameplay start without admin intervention.

### Implementation Tasks

- [ ] T014 [US1] Ensure firmware/shared/proto/segment_map.json reflects spec PlayerSlot seating (update if mismatched)
- [ ] T015 [US1] Implement player count selection and game filtering in firmware/esp32/main/ui_menu.c
- [ ] T016 [US1] Broadcast session configuration (RS485 msg 0x01) via firmware/esp32/main/session_bus.c
- [ ] T017 [US1] Handle ready button mask (msg 0x06) intake in firmware/esp32/main/session_bus.c
- [ ] T018 [US1] Manage ReadyCheck state transitions in firmware/arduino/src/session_controller.cpp
- [ ] T019 [US1] Persist last player count/game choice in firmware/esp32/main/storage_config.c
- [ ] T020 [US1] Append guided setup walkthrough to docs/operations/quickstart.md

---

## Phase 4: User Story 2 - LED & Display Orchestration (Priority: P2)

**Goal**: Keep LED boundaries, Joker rules, and seat displays aligned with manifest mappings.

**Independent Test**: Run a five-player session with Joker disabled and confirm SpielLED group 2 stays off, boundaries remain lit, and displays show correct seat labels.

### Implementation Tasks

- [ ] T021 [P] [US2] Generate LED mapping payload (msg 0x02) in firmware/esp32/main/led_mapper.c
- [ ] T022 [US2] Apply LED mapping payload in firmware/arduino/src/led_boundary_renderer.cpp
- [ ] T023 [US2] Implement Joker highlight toggling in firmware/arduino/src/led_boundary_renderer.cpp
- [ ] T024 [US2] Sync display seat labels in firmware/esp32/main/ui_player_rings.c using PlayerSlot data
- [ ] T025 [US2] Trigger win/lose animations (msg 0x07) in firmware/esp32/main/gameplay_events.c
- [ ] T026 [US2] Update docs/operations/config-manifest.md with LED verification checklist
- [ ] T027 [US2] Extend tests/led-ring/expected.log to capture Joker and boundary assertions

---

## Phase 5: User Story 3 - Admin Oversight & Synchronization (Priority: P3)

**Goal**: Provide diagnostics, manifest synchronization, and timed admin unlock for operators.

**Independent Test**: Hold the admin button, enter admin mode, validate manifest hashes, run RS485 and LED diagnostics, and exit to relock within 10 seconds.

### Implementation Tasks

- [ ] T028 [P] [US3] Implement admin unlock timer logic in firmware/esp32/main/admin_controls.c
- [ ] T029 [US3] Surface manifest hash status UI in firmware/esp32/ui/options_admin.eezi integration
- [ ] T030 [US3] Broadcast manifest hash (msg 0x05) in firmware/esp32/main/manifest_sync.c
- [ ] T031 [US3] Echo manifest ack in firmware/arduino/src/manifest_sync.cpp
- [ ] T032 [US3] Wire RS485/Wi-Fi diagnostics actions in firmware/esp32/main/admin_diagnostics.c
- [ ] T033 [US3] Persist diagnostics logs in firmware/esp32/main/log_store.c
- [ ] T034 [US3] Time the diagnostics workflow, targeting <=2 minutes, and log results in docs/operations/performance-results.md
- [ ] T035 [US3] Document admin workflow updates in docs/operations/ota-playbook.md and docs/operations/test-package-workflow.md

---

## Phase N: Polish & Cross-Cutting Concerns

**Purpose**: Final documentation, validation, and cleanup once all stories are implemented.

- [ ] T036 [P] Update docs/operations/quickstart.md with screenshots or annotated logs from final test run
- [ ] T037 Add manifest mismatch recovery FAQ entry to docs/operations/config-manifest.md
- [ ] T038 [P] Verify tests/succeeded bundles contain latest expected.log and README guidance
- [ ] T039 Execute end-to-end smoke test (quickstart steps) and record results in docs/operations/performance-results.md
- [ ] T040 Sweep firmware/ for TODO/FIXME comments and convert to tracked backlog items

---

## Dependencies & Execution Order

- **Phase 1 -> Phase 2**: Setup tasks establish documentation and placeholders; Foundational tasks depend on sample assets and manifest tooling readiness.
- **Phase 2 -> User Stories**: RS485 framing, manifest validation, and test bundles must be complete before any story work begins.
- **User Stories**: Execute in priority order (US1 MVP -> US2 visuals -> US3 admin). Each story is independently testable after its tasks.
- **Polish**: Runs after desired story phases conclude.

### User Story Dependency Graph

```
US1 (Guided Setup) --> enables LED mapping (US2)
US1 --> enables Admin oversight (US3)
US2, US3 do not depend on each other directly
```

### Parallel Opportunities

- Phase 1: T002/T003/T004 can proceed while T001 is being documented.
- Phase 2: T007 and T008 (manifest commands) can run once sample assets (T006) exist; T011 and T012 can be developed in parallel.
- US2: T021 (payload generation) and T024 (display sync) can progress concurrently before integration in T022.
- US3: T028 (unlock timer) and T030 (hash broadcast) can proceed in parallel, merging for UI tasks later.

---

## Implementation Strategy

### MVP First (User Story 1)
1. Complete Phase 1 and Phase 2 tasks.
2. Implement US1 tasks (T014-T020).
3. Execute guided setup test flow from quickstart.

### Incremental Delivery
1. Deliver US1 (MVP).
2. Add US2 LED/display orchestration; run five-player Joker-disabled scenario.
3. Add US3 admin oversight; run full diagnostics cycle.

### Parallel Team Strategy
- Developer A: Focus on RS485 framing and session control (Phase 2 + US1).
- Developer B: Handle LED mapping and display orchestration (US2).
- Developer C: Implement admin diagnostics and manifest sync (US3).