---
description: "Task list template for feature implementation"
---

# Tasks: [FEATURE NAME]

**Input**: Design documents from `/specs/[###-feature-name]/`  
**Prerequisites**: plan.md (required), spec.md (required for user stories), research.md, data-model.md, contracts/

**Tests**: Add dedicated tasks only when the spec or constitution mandates them (Principles III and V).

**Organization**: Tasks are grouped by user story to enable independent implementation and testing.

## Format: `[ID] [P?] [Story] Description`
- `[P]`: Parallel-safe (different files, no shared state)
- `[Story]`: User story label (e.g., US1, US2, US3)
- Include concrete file paths in descriptions and cite the constitution principle satisfied.

## Phase 1: Setup (Shared Infrastructure)

**Purpose**: Environment and tooling required before feature work begins.

- [ ] T001 [P] Initialize manifest tooling (`manifest_tool`) and schema validators (Principle I and II)
- [ ] T002 [P] Stage hardware test harness or simulator hooks aligned with `TREIBER/` packages (Principle III)
- [ ] T003 Configure `/specs/[###-feature-name]/` documentation structure and reference the updated constitution check

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Core infrastructure that MUST be complete before any user story can start.

- [ ] T010 Validate seat and LED mappings or reference existing assets in `pitteromat.txt` (Principle IV)
- [ ] T011 Implement sync safeguards or telemetry hooks required for Principle V compliance
- [ ] T012 Confirm System Architecture Directives (hardware routing, directory locations) are satisfied or documented

**Checkpoint**: Foundation ready - user story implementation can begin.

## Phase 3+: User Story Implementation

Repeat the following block for each user story.

### Phase N: User Story [#] - [Title] (Priority: Px)

**Goal**: [Describe the outcome this story delivers]  
**Independent Test**: [Describe how this story is validated end-to-end]

#### Tests (if mandated)
- [ ] T1NN [P] [US#] Add or extend test covering Principle III hardware validation or Principle V sync flow

#### Implementation
- [ ] T1NN [P] [US#] Update source files under `src/` (or relevant package) referencing manifest and schema rules
- [ ] T1NN [US#] Wire UI flows to respect seat map and brightness constraints (Principle IV)
- [ ] T1NN [US#] Update documentation or admin workflows to record sync status (Principle V)

**Checkpoint**: User story delivers deployable value and passes the Constitution Check.

## Final Phase: Polish and Cross-Cutting Concerns

- [ ] T9NN [P] Documentation updates in `docs/` or `/specs/[###-feature-name]/quickstart.md`
- [ ] T9NN Run `manifest_tool validate` against assembled assets (Principle I)
- [ ] T9NN Confirm `tests/succeeded/` bundles or archive new hardware logs (Principle III)
- [ ] T9NN Verify brightness clamps and Joker flows in integration tests (Principle IV)
- [ ] T9NN Record sync status screens or admin PIN timeout coverage (Principle V)

## Dependencies and Execution Order

- Setup precedes Foundational; Foundational gates all user stories.
- User stories run sequentially or in parallel once Foundational completes; respect `[P]` indicators.
- Polish tasks wrap up documentation, compliance verifications, and release readiness.

## Notes

- Track any Constitution exceptions under Complexity Tracking in plan.md.
- Link each task back to the relevant user story and constitution principle.
- Ensure tests fail before implementation when added to catch regressions early.
