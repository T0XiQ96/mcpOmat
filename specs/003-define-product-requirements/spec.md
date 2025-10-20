# Feature Specification: PitterOmat v2 product requirements

**Feature Branch**: `003-define-product-requirements`  
**Created**: 2025-10-20  
**Status**: Draft  
**Input**: User description: "Produktanforderungen (v2) for PitterOmat"

## Vision Alignment *(mandatory)*

- Upholds Principle IV by defining consistent Idle -> Menu -> Game transitions and display roles across all 12 touch screens.
- Reinforces Principle V through coordinated start, synchronization, and post-game status handling governed by the master display.
- Protects hardware per Principles III and IV by enforcing the 55% LED brightness cap and documenting testable spin curves.
- Supports Principle I with deterministic options (Quickstart, player count) that tie back to manifest-backed configurations.
- Enables venue-grade configurability (Principles II and V) via admin-guarded menus while keeping the cabinet venue friendly.

## Assumptions

- Venue operators continue to rely on the documented seat map from `pitteromat.txt`; no new physical layout changes are required.
- Quickstart always replays the most recently completed game mode with the last saved option set unless players adjust the count.
- Debug overlays are limited to information useful during onsite validation and can be toggled off without rebooting the cabinet.

## Clarifications

### Session 2025-10-20

- Q: How is the news ticker content updated day-to-day? → A: Editable directly from the cabinet's admin options menu.

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Launch a game night session (Priority: P1)

Player 1 activates the cabinet from Idle, selects the group size, and starts LichtLoser while everyone sees synchronized displays.

**Principles Covered**: I, IV, V  
**Why this priority**: This is the core gameplay loop that proves the cabinet delivers its primary value in a venue.  
**Independent Test**: Trigger Idle -> Menu -> Game flow on a test rig, verifying synchronized displays and Joker handling in five-player mode.

**Acceptance Scenarios**:

1. **Given** the cabinet is in Idle with the Start control hidden, **When** Player 1 touches the screen, **Then** the Start control appears and all displays transition to the main menu within 3 seconds.
2. **Given** the main menu is visible, **When** Player 1 sets player count between 2 and 6 and starts LichtLoser, **Then** all active displays show the correct seat overlays and inactive displays show the logo.
3. **Given** a five-player game with Joker enabled, **When** the spin completes, **Then** exactly one player is marked as loser, Joker group 2 follows the configured highlight, and results appear simultaneously on every display.

---

### User Story 2 - Repeat play with Quickstart and player options (Priority: P2)

The session host wants to replay LichtLoser quickly while adjusting round count, speed, and Joker settings between games.

**Principles Covered**: I, II, V  
**Why this priority**: Rapid replay keeps players engaged and validates schema-driven configuration across sessions.  
**Independent Test**: After finishing a game, use Quickstart to relaunch with modified options and confirm the cabinet enforces limits without respecifying everything.

**Acceptance Scenarios**:

1. **Given** a game has just ended, **When** the host selects Quickstart, **Then** the cabinet reloads the last mode with prior settings while allowing player count edits before launch.
2. **Given** the options menu is open, **When** the host adjusts round count between 1 and 10 and modifies spin speed, **Then** the UI reflects the change immediately and the next game uses those values.
3. **Given** Joker is disabled in the options, **When** a five-player game runs, **Then** Joker effects never display and the LED logic skips the Joker group gracefully.

---

### User Story 3 - Configure cabinet ambience and protections (Priority: P2)

An administrator authenticates to tune lighting, colors, and energy-saving behaviour without violating safety caps.

**Principles Covered**: III, IV, V  
**Why this priority**: Controlled ambience differentiates the cabinet while maintaining compliance with hardware safeguards.  
**Independent Test**: Enter admin mode with the PIN, adjust brightness and color settings, verify enforcement of limits, and confirm the menu relocks after 10 seconds.

**Acceptance Scenarios**:

1. **Given** the admin PIN prompt is displayed, **When** the correct PIN is entered, **Then** admin options unlock for exactly 10 seconds before auto-locking.
2. **Given** admin options are visible, **When** LED brightness sliders are set above 55%, **Then** the cabinet clamps settings to 55% and informs the administrator.
3. **Given** win/lose color presets are changed, **When** a test animation runs, **Then** displays and LED rings use the new palette while inactive seats follow the selected dimming scheme.

---

### Edge Cases

- Start control remains hidden if no interaction occurs, preventing accidental launches during Idle loops.
- Admin session expires mid-configuration; unsaved adjustments revert to the last confirmed state.
- Player count reduced below the number of active displays; extra displays must revert to the logo immediately.
- Joker enabled with fewer than five players must produce a validation warning and block launch until corrected.
- Debug overlay left on during live play must not obstruct scoring or confuse players.

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: Idle mode MUST display the venue logo, configurable LED effects, and keep the Start control hidden until an intentional touch or button press occurs.
- **FR-002**: Transition from Idle to the main menu MUST complete within 3 seconds once activation occurs and keep all displays synchronized.
- **FR-003**: The main menu MUST provide Start and Options actions plus a configurable news ticker editable without code changes through the cabinet admin options menu.
- **FR-004**: Player count selection MUST support 2-6 players, maintain consistent seat overlays across displays, and restrict launch if the selection is outside that range.
- **FR-005**: LichtLoser MUST implement the specified spin curve (accelerate, steady fast loop, decelerate) and guarantee a single loser outcome per round.
- **FR-006**: Scoreboards MUST appear only on displays for active players while inactive displays revert to the logo.
- **FR-007**: Joker logic MUST only activate in five-player sessions when enabled and respect the selected highlight color.
- **FR-008**: Quickstart MUST relaunch the most recent mode with preserved options while allowing player count adjustments before confirmation.
- **FR-009**: The options menu MUST include controls for rounds (1-10), spin speed presets, Joker toggle, and Joker color selection with live feedback.
- **FR-010**: Admin options MUST be gated by a PIN, auto-lock after 10 seconds, and include color/effect presets, LED brightness (10-55%), display brightness (10-100%), idle timeouts, and reset utilities with confirmation prompts.
- **FR-011**: Network information views MUST outline WiFi and RS485 topology, sync timing presets (0/10/20/40/70/100 ms), and clearly mark update-related items as placeholders.
- **FR-012**: Debug tools MUST allow toggling performance overlays, communication latency checks, LED ring tests, and SD log exports without impacting live play.

### Non-Functional Requirements

- **NFR-001**: Brightness clamps and Joker safeguards MUST fail safe, never allowing settings beyond documented limits.
- **NFR-002**: Display transitions MUST appear smooth, with no perceptible desynchronization exceeding 100 ms between any two displays during menu or game updates.
- **NFR-003**: Admin and debug messaging MUST be understandable by venue staff without referencing engineering manuals.
- **NFR-004**: Idle energy saver MUST reduce display brightness according to configuration within 10 seconds of the timeout firing.

### Key Entities *(include if feature involves data)*

- **Display Role State**: Identifier, assigned player seat, visibility mode (idle/logo/menu/game/score), brightness level.
- **Game Session Profile**: Player count, active mode, rounds, spin speed, Joker enabled flag, Joker color, last result.
- **Cabinet Configuration Bundle**: News ticker content, color palette presets, LED and display brightness caps, idle timeout, energy saver setting, admin PIN policy timestamp.

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: 95% of Idle-to-menu activations surface the Start control and transition all displays within 3 seconds of the initial touch.
- **SC-002**: In 100 sample games, the scoreboard and loser notification match the actual outcome with zero discrepancies.
- **SC-003**: Admin menu auto-locks within 10 +/- 1 seconds after PIN entry across 20 consecutive tests, and brightness never exceeds 55%.
- **SC-004**: Quickstart relaunches the last mode with preserved settings in under 5 seconds and accepts player count changes without re-entering other options.
- **SC-005**: Debug overlays can be toggled on or off within 2 seconds and remain off by default during live play sessions.

### Governance & Compliance

- Amendments required? No - behaviour aligns with constitution v1.1.0 and existing governance.
- Exceptions recorded in plan.md Complexity Tracking? No - all flows comply with documented principles.
