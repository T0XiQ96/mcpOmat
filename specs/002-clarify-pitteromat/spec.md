# Feature Specification: PitterOmat Core Experience

**Feature Branch**: `002-clarify-pitteromat`  
**Created**: 2025-10-17  
**Status**: Draft  
**Input**: User description: "gucke dir pitteromat.txt an"

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Guided Game Setup (Priority: P1)

Player 1 launches the console from the idle screen, selects the number of participants (2–6), chooses a compatible game, and gathers all players into the ready state using touch inputs and their hardware buttons.

**Why this priority**: Without a dependable setup journey no gameplay can begin; every other capability depends on this flow.

**Independent Test**: Start from idle, select four players, pick an available game, have each player confirm readiness with their button, and verify that gameplay initiates without needing admin interaction.

**Acceptance Scenarios**:

1. **Given** the console shows the idle screen, **When** Player 1 taps Start, chooses a player count, and selects a game, **Then** only games valid for that player count remain selectable and the ready screen appears.
2. **Given** the ready screen is displayed, **When** each participating player presses their hardware button, **Then** their display turns green and the game starts automatically once every player has confirmed.

---

### User Story 2 - LED & Display Orchestration (Priority: P2)

The system maps LED segments, Joker behavior, and seat displays according to the chosen player count, providing continuous boundaries, gameplay feedback, and end-of-game results.

**Why this priority**: Accurate visuals define the physical playfield and scoring feedback; any mismatch undermines gameplay even if setup succeeds.

**Independent Test**: Run a five-player session with Joker disabled, observe LED allocations and score updates, and confirm displays show the correct seat information without relying on admin options.

**Acceptance Scenarios**:

1. **Given** five players are selected with Joker disabled, **When** gameplay starts, **Then** SpielLED group 2 remains inactive, boundary LEDs stay illuminated, and each display shows the correct seat label.
2. **Given** a game reaches its end condition, **When** final scores are available, **Then** ring animations announce winners and all active displays present ranked results and replay options.

---

### User Story 3 - Admin Oversight & Synchronization (Priority: P3)

An administrator opens the options menu to review diagnostics, trigger RS485/Wi-Fi tests, manage firmware and content updates, and confirm that all nodes share the same manifest hash before authorizing new gameplay.

**Why this priority**: Operational readiness requires monitoring and updates; without oversight the system cannot recover from faults or deploy fresh content safely.

**Independent Test**: From the admin options, initiate a manifest verification, run RS485 and LED diagnostics, and ensure status indicators are resolved before approving the next session.

**Acceptance Scenarios**:

1. **Given** a new content bundle is inserted on the SD card, **When** the admin triggers manifest verification, **Then** any hash mismatch is reported with guidance to synchronize before gameplay resumes.
2. **Given** the RS485 link is impaired, **When** the admin runs the communication test, **Then** affected nodes are flagged and the UI provides corrective instructions.

---

### Edge Cases

- Joker toggled during a session: changes must apply only to subsequent games to avoid LED conflicts mid-play.
- Player withdraws after confirming readiness: the session must return to setup, update player count, and reassign LEDs/displays before restarting.
- Client ESP reports manifest hash mismatch: gameplay remains blocked until synchronization or admin-approved override is completed.
- RS485 disturbance during gameplay: Arduino must freeze animations safely and notify the master ESP for recovery handling.

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: The console MUST allow Player 1 to progress from idle to gameplay exclusively through touch navigation and participating player button confirmations.
- **FR-002**: The system MUST load game definitions from SD-card content and present only games whose `min`/`max` player counts match the selected participants.
- **FR-003**: LED segment assignments and seat displays MUST follow the documented mappings, including Joker exclusions for five-player sessions when disabled.
- **FR-004**: Every ready screen MUST require explicit confirmation from each participating player’s hardware button before gameplay can begin.
- **FR-005**: During gameplay, the system MUST capture scores, drive LED animations for real-time feedback, and show ranked results plus replay options upon completion.
- **FR-006**: At startup and before each session, the system MUST validate the SD manifest hash across all ESP/Arduino nodes and block gameplay when mismatches exist.
- **FR-007**: The admin options menu MUST expose diagnostics for RS485, Wi-Fi, LED tests, display tests, and error logs, providing actionable guidance within two minutes.
- **FR-008**: The system MUST log invalid or missing SD files, hardware faults, and synchronization failures to a retrievable diagnostics history for operators.

### Key Entities *(include if feature involves data)*

- **GameDefinition**: Describes a playable mode, including identifier, player range, LED utilization rules, required hardware capabilities, phases, and linked option bundles.
- **OptionBundle**: Groups user or admin configuration fields (e.g., Joker color, countdown style), defines scope, and indicates affected subsystems.
- **PlayerSlot**: Represents a seat around the ring with display ID assignment, SpielLED start/end segments, boundary LEDs, and Joker overrides.
- **HardwareNode**: Tracks each ESP32 or Arduino device, capturing role (master/client), firmware version, heartbeat status, and synchronization state.
- **ManifestEntry**: Records relative file path, semantic version, hash, and compatibility metadata for every SD asset loaded at runtime.

## Assumptions

- The system supports a maximum of six players simultaneously; additional seats are outside current scope.
- Game and option JSON files are authored with the provided schemas and validated before deployment.
- Hardware test bundles derived from Waveshare demos are available for every subsystem before integration builds.
- Connectivity is limited to trusted local Wi-Fi; remote/cloud integrations are future enhancements.

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Players can progress from idle screen to active gameplay in under 90 seconds for any supported player count.
- **SC-002**: LED boundaries and seat displays match the documented mapping in 100% of observed sessions across 2–6 player configurations.
- **SC-003**: 100% of nodes report matching manifest hashes before every authorized gameplay session; any mismatch is resolved or blocked within a single remediation attempt.
- **SC-004**: Administrators diagnose communication or LED issues within 2 minutes using built-in options without external tools.
