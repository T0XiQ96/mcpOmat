# Research Findings: PitterOmat v2 product requirements

**Branch**: `003-define-product-requirements`  
**Date**: 2025-10-20  
**Source Spec**: [spec.md](./spec.md)

---

## Decision 1: WiFi synchronization protocol

- **Decision**: Use Arduino AsyncUDP broadcast frames with ArduinoJson payloads for state fan-out, paired with a simple UDP ack channel for critical actions (game start, admin changes).
- **Rationale**: AsyncUDP keeps latency under 20 ms without the ESP-IDF toolchain and ArduinoJson keeps payloads compact while remaining easy to debug. A lightweight ack channel avoids dropped critical events with minimal overhead.
- **Alternatives considered**:
  - *Pure TCP*: Guarantees delivery but increases connection management overhead across 12 nodes.
  - *ESP-NOW*: Lower latency but conflicts with the WiFi requirement and complicates coexistence with existing infrastructure.

## Decision 2: Persisting and editing the news ticker

- **Decision**: Store ticker text inside `config/admin/news_ticker.json` on the SD card and expose edit controls inside the admin options menu with live preview.
- **Rationale**: Aligns with the clarification outcome (admin-managed) and avoids requiring external tools. SD persistence keeps content through reboots.
- **Alternatives considered**:
  - *Remote CMS*: Adds scope and reliability risk beyond v2 goals.
  - *Hard-coded strings*: Requires firmware rebuilds for small updates.

## Decision 3: Game session state retention for Quickstart

- **Decision**: Persist the last completed session parameters to `runtime/session_last.json` and mirror them to SPIFFS on the master ESP32, syncing back to SD during maintenance.
- **Rationale**: Keeps Quickstart data available after power cycles while limiting flash writes to end-of-session events.
- **Alternatives considered**:
  - *RAM-only caching*: Loses data on reboot; unreliable for venues.
  - *Full manifest regeneration*: Overkill for single-session metadata.

## Decision 4: Spin curve implementation

- **Decision**: Implement the LichtLoser spin using a quintic ease-in/ease-out profile sampled at a fixed 10 ms tick, with configurable duration matching rounds and speed presets.
- **Rationale**: Quintic easing gives smooth acceleration without abrupt LED changes and respects the timing constraints in the spec.
- **Alternatives considered**:
  - *Linear acceleration*: Appears jerky and fails the desired arcade feel.
  - *Physics-based simulation*: Adds complexity without clear benefit.

## Decision 5: Admin auto-lock enforcement

- **Decision**: Enforce the 10-second admin window via a monotonic countdown timer reset on interaction; once expired, the UI closes admin panes and requires PIN re-entry.
- **Rationale**: Matches success criteria (10 +/- 1 seconds) and ensures compliance with Principle V by preventing long-lived privileged sessions.
- **Alternatives considered**:
  - *Manual exit only*: Risks unattended access.
  - *Fixed time from entry without activity monitoring*: Allows idle stay without tracking interactions.
