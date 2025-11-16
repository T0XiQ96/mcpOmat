# Repository Guidelines

## Project Structure & Module Organization
- `platformio.ini` keeps the lone `ws-esp32s3` environment plus the matching board JSON in `boards/`.
- `src/main.cpp` drives LVGL, RS485, and settings; `src/settings_store.*` hides NVS details and must mirror EEZ globals.
- `lib/` contains generated UI code, the LVGL fork, IO helpers, etc.; keep each module in `lib/<name>/src` so PlatformIO links it automatically.
- `firmware/eez/` stores `.eez-project` assets, while `firmware/arduino/MEGA/` holds supporting sketches; version these whenever protocol fields or layouts move.
- Treat `.pio/` as disposable output and keep calibration JSON or archives (e.g., `mcpOmat*.zip`) outside `src/`.

## Build, Test, and Development Commands
- `pio run` builds the firmware; rerun after altering board options, partitions, or LVGL flags.
- `pio run -t upload -e ws-esp32s3 -p <port>` flashes via USB CDC with explicit port selection.
- `pio device monitor -b 115200 --filter direct` mirrors the serial monitor settings from `platformio.ini` and is the standard log/RS485 console.
- `pio run -t clean` removes stale objects before switching pin maps or display timing constants.
- `pio check` runs cppcheck/clang-tidy; keep it warning-free for touched files.

## Coding Style & Naming Conventions
- Use two-space indentation, braces on the same line, and wrap argument lists the same way as the LVGL buffer setup.
- Prefer camelCase for functions or members, snake_case only for LVGL callback hooks, and SCREAMING_SNAKE_CASE for pins, macros, or feature flags.
- Introduce `constexpr` IDs instead of repeating literals, and guard hardware-specific blocks with existing macros (`USE_NATIVE_USB`, `LV_USE_LOG`, etc.).
- Declare helpers inside headers such as `settings_store.h` and include them explicitly; do not rely on Arduino’s implicit prototypes.

## Testing Guidelines
- Place Unity-based unit tests under `test/<feature>/test_main.cpp` and run them with `pio test -e ws-esp32s3`.
- Exercise integrations on hardware: flash, then observe `usbPoll` output with `pio device monitor --echo` while sending RS485 frames; describe manual steps in the PR.
- Prioritize automated coverage for deterministic code (settings caching, RS485 parsing, UI flag bookkeeping) so only touch and timing paths stay manual.

## Commit & Pull Request Guidelines
- Keep commits short, imperative, and capitalized like `Serial Monitor + FullScreen Buf`; avoid punctuation past the title.
- PRs should link issues, summarize functional impact, list build/test commands, and attach screenshots or serial logs for UI or protocol changes.
- State the hardware revision, EEZ project touched, and any calibration files affected so reviewers can repeat your process quickly.
