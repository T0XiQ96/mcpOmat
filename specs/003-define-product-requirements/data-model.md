# Data Model: PitterOmat v2 product requirements

**Branch**: `003-define-product-requirements`  
**Date**: 2025-10-20  
**Source Spec**: [spec.md](./spec.md)

---

## Entities

### DisplayRoleState
- **Description**: Tracks how each ESP32 display behaves during Idle, Menu, and Game states.
- **Fields**:
  - `displayId` (uint8): 1-12 unique identifier; 1 is master.
  - `seatAssignment` (enum `P1`-`P6` | `Idle`): Logical seat or idle role.
  - `mode` (enum `IDLE`, `MENU`, `GAME`, `SCORE`, `ADMIN`, `DEBUG`): Current render context.
  - `brightness` (uint8): Percentage 0-100; runtime clamp applied when >55 during gameplay.
  - `lastSyncTs` (uint32): Epoch milliseconds of last master sync beat.
  - `inactiveDisplayAsset` (string): Path to logo asset for Idle/inactive mode.
- **Relationships**:
  - Belongs to one `GameSessionProfile` during active play.
- **Validation**:
  - `brightness` must obey LED cap (<=55) outside admin/test states.
  - `seatAssignment` must be `Idle` for displays above the selected player count.
  - `mode` transitions follow `IDLE -> MENU -> GAME -> SCORE -> MENU/IDLE`.

### GameSessionProfile
- **Description**: Captures the configuration and outcome of the most recent or active session.
- **Fields**:
  - `sessionId` (uuid): Generated at session start.
  - `playerCount` (uint8): Range 2-6.
  - `rounds` (uint8): Range 1-10.
  - `spinSpeedPreset` (enum `SLOW`, `MEDIUM`, `FAST`): Maps to quintic easing duration.
  - `jokerEnabled` (bool): True only when `playerCount` = 5.
  - `jokerColor` (enum `GOLD`, `RAINBOW`).
  - `lastLoserSeat` (enum `P1`-`P6` | `NONE`).
  - `completedAt` (uint32, epoch ms): Set on round completion.
- **Relationships**:
  - Owns many `DisplayRoleState` entries during runtime.
  - References one `CabinetConfigurationBundle` for palette defaults.
- **Validation**:
  - `jokerEnabled` must be false unless `playerCount` = 5.
  - `lastLoserSeat` must be within active seats when set.
  - `completedAt` populated only after full spin and result broadcast.

### CabinetConfigurationBundle
- **Description**: Persistent configuration applied across sessions through admin options.
- **Fields**:
  - `newsTickerText` (string, <= 280 chars): Editable via admin menu.
  - `winPalette` (enum `DEFAULT`, `CUSTOM` with color references).
  - `losePalette` (enum `DEFAULT`, `CUSTOM` with color references).
  - `neutralPalette` (enum `DEFAULT`, `CUSTOM`).
  - `inactiveDisplayMode` (enum `OFF`, `DIM`, `LOGO_LOOP`).
  - `ledBrightnessCap` (uint8): 10-55 inclusive.
  - `borderBrightnessCap` (uint8): 10-55 inclusive.
  - `displayBrightness` (uint8): 10-100 inclusive.
  - `idleTimeoutSeconds` (enum 5, 10, 15, 30, 60).
  - `energySaverEnabled` (bool).
  - `adminPinHash` (string, salted SHA-256).
  - `updatedAt` (uint32, epoch ms).
- **Relationships**:
  - Referenced by `GameSessionProfile` and admin UI.
- **Validation**:
  - Brightness fields must respect documented range.
  - `newsTickerText` must strip control characters before persistence.
  - PIN hash must update when the admin changes credentials.

### DebugOverlayState
- **Description**: Tracks debug toggles to ensure they default off during live play.
- **Fields**:
  - `isVisible` (bool).
  - `metricsShown` (set enum `FPS`, `CPU`, `HEAP`, `LATENCY`).
  - `lastToggleTs` (uint32, epoch ms).
  - `autoHideOnGameStart` (bool, default true).
- **Relationships**:
  - One-to-one with the master display; broadcast status to slaves.
- **Validation**:
  - `isVisible` must reset to false when a new session starts.
  - `metricsShown` must be a subset of defined metrics.

## State Transitions

- Cabinet boot -> Load `CabinetConfigurationBundle` -> Enter `DisplayRoleState.mode = IDLE`.
- Player activation -> Transition displays to MENU -> Instantiate `GameSessionProfile`.
- Game start -> `GameSessionProfile.sessionId` issued -> Displays switch to GAME mode.
- Spin resolve -> Update `lastLoserSeat` -> Displays move to SCORE -> Quickstart writes `session_last.json`.
- Return to menu or idle based on inactivity timer.

## Data Volume & Persistence

- `DisplayRoleState`: 12 records in memory, broadcast at 20-100 ms intervals.
- `GameSessionProfile`: Single active record; historical snapshots optionally archived during maintenance.
- `CabinetConfigurationBundle`: Single record persisted on SD and cached in RAM; updates infrequent.
- `DebugOverlayState`: Single record with volatile persistence; resets on reboot.
