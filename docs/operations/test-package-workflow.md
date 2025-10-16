# Hardware Test Package Workflow

## Goals
- Reuse official Waveshare driver demos (`TREIBER/`) together with project-specific firmware to validate each subsystem in isolation.
- Keep every test bundle self-contained (firmware binaries, wiring notes, expected serial output, manifest snapshot).
- Feed test outcomes back into the configuration manifest pipeline so we know which asset combination produced a passing result.

## Directory Layout
```
/tests/
  /rs485-link/
    README.md              <-- wiring + execution steps
    esp32/                 <-- firmware built from TREIBER + project glue
    arduino/
    assets/manifest.json   <-- subset manifest for this test
    expected.log
  /led-ring/
  /display-sync/
  /can-bus/
```
- Existing Waveshare demos from `TREIBER\` should be referenced (or copied with attribution) inside each test bundle to minimise divergence.
- Once a test passes, move the bundle under `/tests/succeeded/` as described in `pitteromat.txt` so future work can rely on the known-good artefacts.

## Manifest & Schema Integration
- Each bundle includes a reduced `manifest.json` validated against `firmware/shared/proto/manifest.schema.json`.
- Game mocks or option overrides use the same schemas (`game.schema.json`, `options.schema.json`) to ensure compatibility mit dem Hauptsystem.
- Regenerate hashes with `python -m firmware.shared.scripts.manifest_tool generate --root tests/<name>/assets --manifest-version 1.0.0 --notes "rs485 smoke test"` whenever assets change; the recorded bundle hash must match the files shipped in the test folder.

## Execution Checklist
1. Flash provided binaries (or rebuild source) onto ESP32/Arduino.
2. Follow wiring instructions – RS485 tests reference the pin assignments confirmed in `pitteromat.txt`.
3. Capture serial output (USB) for both devices; compare with `expected.log`.
4. Record result in `tests/<name>/RESULT.md` (pass/fail, notes). On success, move directory into `/tests/succeeded/`.
5. Update master `manifest.json` for the full system once all prerequisite bundles succeed.

## Next Steps
- Add a helper target (Make/specify) that calls `python -m firmware.shared.scripts.manifest_tool validate tests/<name>/assets/manifest.json --root tests/<name>/assets` during CI.
- Link each test to CI (`specify check` extensions) so content changes trigger the corresponding isolated validation before merging in die kombinierte Firmware.
