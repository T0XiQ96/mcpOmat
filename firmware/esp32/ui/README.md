# EEZ Studio Asset Export

This directory stores UI assets generated from the EEZ Studio project for the Pitter-o-mat touchscreen interface.

## Export workflow

1. Open the EEZ Studio project on your development machine.
2. Ensure the target device is set to **Waveshare ESP32S3-Touch-LCD-4 (480x480)**.
3. Use *Project → Export → ESP-IDF* and select this folder (`firmware/esp32/ui/`) as the output destination.
4. Commit the exported source files, assets, and resource descriptors alongside firmware changes.

## Conventions

- Keep EEZ-generated files under version control so that the ESP32 build remains reproducible.
- Manual edits belong in `firmware/esp32/components/` or `main/`; do not modify generated files directly.
- When updating UI resources, include a short changelog entry in the feature branch description.
