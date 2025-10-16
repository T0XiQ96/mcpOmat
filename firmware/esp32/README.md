# ESP32 Firmware Scaffold

This directory contains the ESP-IDF workspace for the Waveshare ESP32S3 touch displays.

## Quick bootstrap

1. Install the ESP-IDF 5.x toolchain and export the environment so that `idf.py` is on `PATH`.
2. From this directory, run:

   ```bash
   idf.py set-target esp32s3
   idf.py menuconfig   # optional, to customize defaults
   idf.py build
   ```

3. Generated binaries will reside in `build/`. Use `idf.py -p <PORT> flash monitor` to flash a device.

The project currently contains only a minimal `app_main.c` loop and is ready for feature-specific components.
