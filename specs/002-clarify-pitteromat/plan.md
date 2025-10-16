# Implementation Plan: PitterOmat Core Experience

**Branch**: `002-clarify-pitteromat` | **Date**: 2025-10-17 | **Spec**: [specs/002-clarify-pitteromat/spec.md](./spec.md)  
**Input**: Feature specification from `/specs/002-clarify-pitteromat/spec.md`

## Summary

Deliver the end-to-end PitterOmat console experience: touch-driven game setup, manifest-governed LED and display orchestration, and administrator oversight that keeps firmware/content in sync across ESP32 and Arduino nodes. The implementation hinges on schema-validated SD assets, shared RS485 protocols, and hardware tests derived from Waveshare TREIBER demos before integrating composite firmware.

## Technical Context

**Language/Version**: C++ (Arduino core for ESP32-S3 3.x) & AVR-GCC for Arduino Mega 2560  
**Primary Dependencies**: LVGL UI exports from EEZ Studio, Adafruit_NeoPixel/FastLED, shared `manifest_tool`, CRC-8 RS485 framing helpers, Waveshare TREIBER demos  
**Storage**: microSD (FAT32) on master ESP32-S3 for games/options/themes/highscores  
**Testing**: Hardware smoke tests derived from Waveshare TREIBER bundles plus `manifest_tool` generate/validate pipeline (documented in research.md)  
**Target Platform**: Waveshare ESP32-S3 Touch LCD 4 (master + up to 7 mirrored clients), Arduino Mega 2560 (LED ring & inputs)  
**Project Type**: Multi-device embedded system (ESP32 master + Arduino co-processor + SD content)  
**Performance Goals**: Idle-to-gameplay < 90 s; LED refresh latency ≤ 50 ms around the ring; admin diagnostics actionable ≤ 2 min; manifest sync enforced before every session  
**Constraints**: Offline-capable; 5 V/40 A supply; RS485 at 115 200 baud; admin options unlocked by holding the hardware admin button (10 s window)  
**Scale/Scope**: Supports 2–6 concurrent players on a single console; one SD content bundle per release cycle

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

- **Principle I – Manifest Integrity**: Quickstart will mandate `manifest_tool generate/validate` and bundle-hash verification prior to deployment. **PASS** (automation detail captured in research task).
- **Principle II – Schema-Driven Modularity**: Game/option assets remain bound to `game.schema.json` and `options.schema.json`, with validation scripted in Phase 1. **PASS**.
- **Principle III – Hardware Validation with Official Drivers**: Hardware test bundles will extend Waveshare TREIBER demos for RS485, LED, display, and diagnostics before integration firmware is produced, following the workflow captured in `research.md`. **PASS**.
- **Principle IV – LED & Seat Mapping Fidelity**: Design artefacts will align with `segment_map.json` and spec edge cases (incl. Joker handling), and LED smoke tests will enforce compliance. **PASS**.
- **Principle V – Coordinated Update & Sync Discipline**: Plan codifies manifest hash syncing, admin override flow, and gameplay blocking on mismatched nodes. **PASS**.

## Project Structure

### Documentation (this feature)

```
specs/002-clarify-pitteromat/
├── plan.md
├── research.md
├── data-model.md
├── quickstart.md
└── contracts/
```

### Source Code (repository root)

```
firmware/
├── arduino/            # Arduino Mega firmware (LED ring, buttons, RS485)
│   └── src/
├── esp32/              # ESP32-S3 firmware (UI, manifest sync, admin tools)
│   ├── main/
│   ├── tests/
│   └── ui/
└── shared/             # Shared proto/scripts (manifest schemas, RS485 frame helper)

docs/
├── hardware/           # Bring-up checklists
└── operations/         # Manifest + testing workflows

tests/
├── rs485-link/         # TREIBER-derived RS485 validation bundles
├── led-ring/           # LED animation & mapping validation
└── display-sync/       # Display alignment & hashing checks
```

**Structure Decision**: Retain the multi-device firmware separation (`firmware/arduino`, `firmware/esp32`, `firmware/shared`) while expanding `/tests` with TREIBER-based bundles and updating documentation under `docs/operations`. Feature documentation remains co-located in `specs/002-clarify-pitteromat/` for traceability.

## Complexity Tracking

| Violation | Why Needed | Simpler Alternative Rejected Because |
|-----------|------------|--------------------------------------|
| _None_ | – | – |
