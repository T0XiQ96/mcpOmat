# Implementation Plan: Pitter-o-mat Multiplayer Console

**Branch**: `001-pitter-o-mat` | **Date**: 2025-10-13 | **Spec**: [spec.md](../spec.md)  
**Input**: Feature specification from `/specs/001-pitter-o-mat/spec.md`

## Summary

Deliver the coordinated firmware stack for the Pitter-o-mat console: Arduino Mega 2560 handles the dual LED ring and physical encoders, Waveshare ESP32S3 touch displays provide touch-driven menus and scores, and the system synchronises Joker options, player boundaries, and OTA updates across 2–6 player party modes.

## Technical Context

**Language/Version**: C++17 subset (Arduino AVR core), C++17 (ESP-IDF 5.x / Arduino-ESP32), EEZ Studio UI scripts  
**Primary Dependencies**: Arduino AVR core, FastLED (WS2812 control), ESP-IDF peripherals (SPI, RS485/UART, Wi-Fi, Touch), EEZ Studio runtime, FATFS microSD driver  
**Storage**: microSD (FAT32) on master ESP32S3 for highscores/configuration, AVR EEPROM for encoder calibration tokens  
**Testing**: PlatformIO unit tests (Unity) for logic modules, hardware-in-the-loop regression harness, LED ring simulator scripts  
**Target Platform**: Custom hardware with Arduino Mega 2560 + Waveshare ESP32S3-Touch-LCD-4 (480x480) nodes over RS485 and Wi-Fi  
**Project Type**: Embedded firmware with multi-device coordination and human-machine interface  
**Performance Goals**: 100 Hz Arduino control loop; <150 ms input-to-visual latency; LED animations perceived at 60 FPS; OTA propagation <5 minutes  
**Constraints**: 60 A @5 V LED power budget, offline-first operation, deterministic Joker segmentation, menu flow controlled solely via Touch UI with encoder reserved for in-game use  
**Scale/Scope**: 2-6 concurrent players, up to 8 touch displays, 864 addressable LEDs

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

- Constitution file `.specify/memory/constitution.md` still contains only placeholders with no ratified principles.  
- Gate status: **Pass with caveat** — proceed while flagging the missing constitution for governance follow-up; no explicit constraints present.  
- Post-Phase-1 review: No additional guidance discovered; formal principles should be documented prior to implementation start.

## Project Structure

### Documentation (this feature)

```
specs/001-pitter-o-mat/
├── plan.md
├── research.md
├── data-model.md
├── quickstart.md
├── contracts/
└── tasks.md            # created via /speckit.tasks
```

### Source Code (repository root)

```
firmware/
├── arduino/
│   ├── src/
│   ├── include/
│   └── tests/
├── esp32/
│   ├── main/
│   ├── components/
│   ├── ui/                 # EEZ Studio generated assets
│   └── tests/
└── shared/
    ├── proto/              # RS485 message schemas & helpers
    └── scripts/            # flashing, simulators, diagnostics

docs/
├── hardware/
└── operations/
```

**Structure Decision**: Separate firmware per MCU to keep toolchains isolated while sharing protocol definitions and operational tooling in `shared/`; documentation directories capture wiring, maintenance, and operating procedures referenced by quickstart.

## Complexity Tracking

No constitution violations identified; section intentionally left empty.
