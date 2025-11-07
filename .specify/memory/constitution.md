<!--
Sync Impact Report
Version change: 1.0.0 -> 1.1.0
Modified principles: I. Manifest Integrity Is Non-Negotiable, II. Schema-Driven Modularity, III. Hardware Validation with Official Drivers, IV. LED and Seat Mapping Fidelity, V. Coordinated Update and Sync Discipline
Added sections: Vision
Removed sections: none
Templates requiring updates:
- done: .specify/templates/plan-template.md
- done: .specify/templates/spec-template.md
- done: .specify/templates/tasks-template.md
Follow-up TODOs: none
-->

# PitterOmat Constitution

## Vision

Deliver a bar-ready multiplayer light game cabinet with twelve ESP32 touch displays and an Arduino
Mega driving LEDs and buttons. The platform must move deterministically through Idle, Menu, and
Game states, launch the first playable experience "LichtLoser," and enforce LED brightness caps that
protect hardware and players while keeping the machine venue friendly.

## Core Principles

### I. Manifest Integrity Is Non-Negotiable
- All SD-card content (games, options, themes, profiles, media) MUST be declared in `manifest.json`
  generated with `python -m firmware.shared.scripts.manifest_tool`.
- Every manifest entry MUST include a `sha256:` hash, and bundle hashes MUST be verified before
  updates or deployments.
- Firmware drops MUST ship with matching manifest metadata; mismatches block release until resolved.

**Rationale**: Deterministic manifests keep every ESP and Arduino node in lockstep and prevent stale
assets from entering play.

### II. Schema-Driven Modularity
- Game and option definitions MUST conform to `firmware/shared/proto/game.schema.json` and
  `options.schema.json`; ad-hoc JSON is prohibited.
- New modes or option bundles MUST declare compatibility (player counts, Joker usage, hardware
  dependencies) so the UI and LED engine can enforce constraints.
- Modular assets belong on the SD card; firmware only contains runtime engines and shared protocols.

**Rationale**: Enforced schemas keep gameplay modular, enable dynamic loading, and let future chats
extend content safely.

### III. Hardware Validation with Official Drivers
- Waveshare demo packages in `TREIBER/` MUST seed every hardware test bundle; deviations require
  written justification.
- Each subsystem (RS485 link, LED ring, displays, CAN, SD, RTC) MUST have a self-contained test
  package with wiring notes, expected serial output, and manifest snapshot.
- Successful tests MUST be archived under `tests/succeeded/` with captured logs before composite
  firmware is produced.

**Rationale**: Reusing vendor-proven drivers accelerates bring-up and ensures failures surface before
integration builds.

### IV. LED and Seat Mapping Fidelity
- LED group allocations, boundary markers, and Joker behavior MUST match
  `firmware/shared/proto/segment_map.json` and the mappings set out in `pitteromat.txt`.
- Display-seat assignments (per player count) MUST remain consistent with the documented seat map;
  UI variations require simultaneous LED updates.
- Joker-disabled flows MUST skip SpielLED group 2 in five-player mode; Joker-enabled flows MUST
  render the group with the configured highlight color.
- Global LED brightness MUST clamp to 55 percent unless a governance-approved exception is recorded.

**Rationale**: Consistent spatial mapping preserves player orientation, meets thermal constraints, and
prevents gameplay imbalance.

### V. Coordinated Update and Sync Discipline
- The Waveshare ESP32-S3 designated as master MUST orchestrate firmware and asset distribution,
  announcing bundle hashes over RS485 or WiFi before clients update.
- Client devices MUST refuse gameplay when their local hash diverges from the master's `bundleHash`
  until synchronization completes.
- Update controls in the admin menu MUST wire to manifest validation and provide clear status
  (pending, syncing, succeeded, failed).
- Admin PIN workflows MUST guard maintenance actions and automatically relock after the configured
  timeout.

**Rationale**: Centralized coordination avoids desynchronized gameplay logic across displays, LEDs,
and control surfaces.

## System Architecture Directives
- Hardware baseline consists of the Waveshare ESP32-S3-Touch-LCD-4 (UART2 on GPIO44/43) linked via
  RS485 to an Arduino Mega 2560 that drives SpielLED (pin 12) and GrenzLED (pin 13).
- Touch interaction on the ESP32S3 is mandatory for menu navigation; rotary encoders remain reserved
  for in-game mechanics.
- LED ring wiring follows the documented 72-group structure (36 SpielLED and 36 GrenzLED) with power
  injection every 144 LEDs; Joker logic remains configurable via admin options.
- SD-card hierarchy MUST match the manifest conventions (`/games`, `/options`, `/themes`,
  `/profiles`, `/music`, `/logos`, `/updates`).
- LVGL UI exports from EEZ Studio belong under `firmware/esp32/ui/`; runtime code MUST bridge UI
  events to manifest-backed gameplay data.
- WiFi is the only allowed inter-ESP transport; RS485 links the master ESP to the Arduino. ESP-NOW
  and ESP-to-ESP RS485 are explicitly out of scope for v2.

## Development Workflow and Test Lifecycle
- Before planning (Phase 0), teams MUST confirm a manifest generation strategy, schema-compliant
  asset plan, and hardware test bundles covering new functionality.
- Implementation phases MUST run hardware smoke tests from `TREIBER/`-based packages before
  combining firmware; failures block progression.
- After validating a subsystem, the corresponding bundle MUST move to `tests/succeeded/` with serial
  logs and hash snapshot to create an auditable trail.
- Final integration releases require a regenerated manifest, `manifest_tool validate` run against
  deployment assets, and confirmation that all mandatory bundles sit in `tests/succeeded/`.
- Plans and tasks MUST cite which principle(s) they satisfy within the Constitution Check and record
  any required exceptions under Complexity Tracking.
- Idle mode, energy saver dimming, and Joker workflows MUST be exercised in smoke tests before
  release candidates are approved.

## Governance
- This constitution supersedes conflicting guidance; deviations require prior approval documented in
  specs and tracked to resolution.
- Amendments demand: (1) drafted updates referencing impacted manifests or tests, (2) review
  alignment with `pitteromat.txt`, (3) updated version tag, (4) announcement in the next plan or
  spec cycle.
- Versioning follows SemVer: MAJOR for principle changes or removals, MINOR for new principles or
  sections, PATCH for clarifications; amend the header comment and metadata accordingly.
- Every `/speckit.plan` output MUST document how the feature honors Principles I through V and list
  pertinent hardware bundles.
- Compliance reviews occur at plan approval, pre-merge code review, and release candidate validation.
  Non-compliance blocks progression until remedied.

**Version**: 1.1.0 | **Ratified**: 2025-10-17 | **Last Amended**: 2025-10-20
