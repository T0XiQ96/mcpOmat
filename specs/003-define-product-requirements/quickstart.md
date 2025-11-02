# Quickstart: PitterOmat v2 product requirements

**Branch**: `003-define-product-requirements`  
**Date**: 2025-10-20  
**Source Spec**: [spec.md](./spec.md)

---

## Prerequisites

- Arduino CLI 0.34+ with ESP32 core 2.x and Arduino AVR core 1.8.x installed.
- Python 3.11 with `firmware.shared.scripts.manifest_tool` installed via `uv`.
- Access to the lab WiFi network reserved for cabinet testing.
- SD card prepared with current manifest structure (`/games`, `/options`, `/themes`, etc.).

## Environment Setup

1. Clone or fetch the latest `003-define-product-requirements` branch.
2. Run `uv tool install specify-cli --from git+https://github.com/github/spec-kit.git` if not already present.
3. Execute `.specify/scripts/powershell/check-prerequisites.ps1` to verify firmware and tooling dependencies.
4. Ensure `.specify/scripts/powershell/update-agent-context.ps1 -AgentType codex` has been executed (already covered during planning).

## Build Targets

### ESP32 master / slave sketches
```powershell
arduino-cli compile --fqbn esp32:esp32:esp32s3touch firmware/esp32
arduino-cli upload   --fqbn esp32:esp32:esp32s3touch -p COM5 firmware/esp32
```

### Arduino Mega (LED controller)
```powershell
arduino-cli compile --fqbn arduino:avr:mega firmware/arduino/mega_led_controller
arduino-cli upload   --fqbn arduino:avr:mega -p COM3 firmware/arduino/mega_led_controller
```

## Test Workflow

1. **Manifest validation**  
   ```powershell
   python -m firmware.shared.scripts.manifest_tool validate --manifest sd/manifest.json
   ```
2. **WiFi sync smoke test**  
   - Deploy master and one slave build.  
   - Upload `firmware/esp32/tests/sync_baseline/sync_baseline.ino` and confirm < 20 ms drift.
3. **LED spin and cap enforcement**  
   - Load Mega firmware.  
   - Run `firmware/esp32/tests/brightness_guard/brightness_guard.ino`; verify clamp at 55% brightness with current meter.
4. **Admin PIN timeout**  
   - Upload `firmware/esp32/tests/admin_timeout/admin_timeout.ino`; confirm auto-lock within 10 +/- 1 seconds.
5. **Idle energy saver**  
   - Upload `firmware/esp32/tests/idle_energy/idle_energy.ino`; confirm displays dim within 10 seconds and return on touch.
6. **Debug diagnostics sweep**  
   - Upload `firmware/esp32/tests/debug_suite/debug_suite.ino`; toggle overlay, run latency probe, execute LED diagnostic, and trigger SD log export.
7. **Quickstart replay**  
   - Complete one LichtLoser session, then choose Quickstart; ensure last configuration restores without re-entering options.

## Manual QA Checklist

- Idle -> Menu transition completes within 3 seconds and Start control is hidden until touched.
- Joker highlight only appears during five-player sessions when enabled.
- News ticker updates via admin controls persist after reboot (confirm `config/admin/news_ticker.json`).
- Quickstart relaunch completes in under 5 seconds with the last option set restored.
- Debug overlay toggles, latency probe, LED diagnostic, and SD export complete without disrupting active gameplay.
- Idle energy saver dims displays within 10 seconds of timeout and restores brightness on interaction.
- Admin/debug messaging review signed off by two venue operators and recorded readability score (FK <= 8).

## Troubleshooting Tips

- If displays desync, check UDP broadcast channel and ensure CBOR payload size < 512 bytes.
- Admin PIN auto-lock failures typically indicate timer not reset on interaction; inspect UI event hooks.
- Quickstart mismatch usually caused by stale `runtime/session_last.json`; clear the file and rerun finalisation flow.
