# Research Log – PitterOmat Core Experience

## Decision: Hardware smoke-test workflow
- **Rationale**: Reusing Waveshare TREIBER demos keeps low-level drivers aligned with vendor support and shortens bring-up. Each test bundle (RS485, LED ring, display sync, diagnostics) will wrap the official sketch, add project-specific verification (e.g., manifest hash echo, segment map checks), and capture expected serial output for comparison.
- **Alternatives considered**:
  - Building bespoke mocks for every subsystem → rejected; higher maintenance risk and diverges from proven reference code.
  - Relying solely on integration firmware for validation → rejected; debugging composite builds without isolated tests is slow and brittle.

## Decision: Manifest validation pipeline
- **Rationale**: Development machines will run `python -m firmware.shared.scripts.manifest_tool generate --root SDCARD` after content updates, commit the resulting `manifest.json`, and record the bundle hash. At boot and before each session, the master ESP32 recomputes hashes for local files and broadcasts them; clients acknowledge only when hashes match, otherwise gameplay stays locked until `validate` passes.
- **Alternatives considered**:
  - Manual hash tracking or spreadsheets → rejected; error-prone and violates Constitution Principle I.
  - Real-time hash streaming per asset → rejected; unnecessary bandwidth on RS485 and duplicates manifest responsibilities.

## Decision: Admin unlock behaviour
- **Rationale**: Holding the physical admin button unlocks admin options for a 10-second window. This matches user expectation, avoids PIN management overhead in early builds, and still prevents accidental access by requiring deliberate input.
- **Alternatives considered**:
  - Permanent button toggle → rejected; easy to leave console in admin state.
  - PIN challenge on touch UI → deferred; adds friction and UI scope not required for current operators.
