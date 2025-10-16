# Quickstart – PitterOmat Core Experience

## Prerequisites

- Waveshare ESP32-S3 Touch LCD 4 (master) plus up to seven mirror displays connected via RS485.
- Arduino Mega 2560 wired to the LED ring (SpielLED pin 12, GrenzLED pin 13) and player buttons/encoder.
- Shared RS485 bus (A/B lines, DE/RE control) with 120 Ω termination and common ground.
- microSD card (FAT32) containing `/games`, `/options`, `/themes`, `/profiles`, `/music`, `/logos`, `/updates`.
- Python 3.11+ with project tooling: `pip install -r firmware/shared/scripts/requirements.txt`.
- `TREIBER/` folder from Waveshare cloned into the repository root.

## 1. Prepare SD Content

1. Populate `/games/*.json` and `/options/*.json` using the schemas in `firmware/shared/proto/`.
2. Run the manifest generator:
   ```bash
   python -m firmware.shared.scripts.manifest_tool generate --root SDCARD --manifest-version 1.0.0 --firmware-version <current-tag> --notes "core experience bundle"
   ```
3. Validate hashes to ensure content integrity:
   ```bash
   python -m firmware.shared.scripts.manifest_tool validate SDCARD/manifest.json --root SDCARD
   ```
4. Copy the entire `SDCARD/` directory to the microSD card and insert it into the master ESP32-S3.

## 2. Flash Hardware Test Bundles

1. Choose the subsystem to verify (e.g., RS485, LED ring, display sync).
2. From `tests/<bundle>/`, flash the ESP32 and Arduino sketches derived from the corresponding Waveshare TREIBER demo.
3. Follow the README wiring instructions, observe serial logs, and compare with `expected.log`.
4. On success, move the bundle directory into `tests/succeeded/` and archive the serial output for future reference.

## 3. Deploy Runtime Firmware

1. Flash the consolidated Arduino firmware from `firmware/arduino/`.
2. Flash the ESP32-S3 firmware from `firmware/esp32/` (LVGL UI + manifest sync logic).
3. Confirm both nodes boot and report `ready` status over the RS485 diagnostics view.

## 4. Run Functional Smoke Test

1. Boot the console to the idle screen.
2. Hold the hardware admin button to enter admin mode and verify:
   - Manifest hash matches across all nodes.
   - RS485, LED, display, and Wi-Fi diagnostics report “OK”.
3. Exit admin mode. Start a four-player session:
   - Select 4 players and verify only compatible games appear.
   - Start gameplay, confirm LED allocations and display seat labels.
4. Finish the game, review win/lose animations, and inspect logged results in the highscore view (if applicable).

## 5. Operational Checklist

- Run `manifest_tool validate` before every deployment to ensure SD content matches the committed manifest.
- Ensure the latest hardware test bundles remain in `tests/succeeded/`; rerun tests whenever wiring or firmware changes.
- During events, keep admin access limited: holding the button grants a 10 s window; release to relock immediately.
- Capture diagnostics logs (`docs/operations/test-package-workflow.md`) whenever faults occur to aid troubleshooting.
