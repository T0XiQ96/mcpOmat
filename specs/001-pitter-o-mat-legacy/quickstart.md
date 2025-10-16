# Quickstart — Pitter-o-mat Multiplayer Console

## 1. Prerequisites
- Install PlatformIO CLI (`pip install platformio`) and ensure `pio --version` >= 6.1.
- Install ESP-IDF 5.x toolchain (via `idf.py tools install`) and add it to `PATH`.
- Install EEZ Studio and export UI project assets to `firmware/esp32/ui/`.
- Ensure Python 3.11+ available for tooling scripts.

## 2. Repository Setup
```bash
git clone <repo-url>
cd mcpOmat
platformio update
```

## 3. Build Firmware
### Arduino (LED + encoder controller)
```bash
cd firmware/arduino
pio run
```

### ESP32 Touch Displays
```bash
cd firmware/esp32
idf.py set-target esp32s3
idf.py build
```

## 4. Flash Devices
- Connect Arduino Mega 2560 via USB and run `pio run -t upload`.
- For each Waveshare ESP32S3 display:
  ```bash
  idf.py -p <PORT> flash monitor
  ```
- After flashing the master ESP32, copy the generated firmware binary to microSD as `ota/latest.bin` for downstream updates.

## 5. Configure LED Segments
- Edit `firmware/shared/proto/segment_map.json` if wiring deviates from the documented 72-group mapping.
- Run `python docs/operations/validate_segments.py` to simulate boundaries per player count.

## 6. Run Hardware-in-the-Loop Tests
```bash
cd firmware/arduino/tests
pio test

cd ../../esp32/tests
idf.py -T hilt test
```
Attach the LED ring and encoders during the test run to validate animations and input latency.

## 7. Wi-Fi & Companion App Integration
- On the master ESP32, open the options menu and configure Wi-Fi SSID/password.
- The API documented in `contracts/device-control.openapi.yaml` becomes accessible at `http://pitter-o-mat.local/api`.
- Use the companion app to assign player profiles and trigger OTA updates.

## 8. MVP Menu Flow Validation (User Story 1)
- Power-cycle the system; wait for ESP32 UI to display the player-count menu.
- Tippe auf `4 Spieler` und bestaetige `LichtLoser` per Touch.
- Toggle Joker an/aus und bestätige: LED-Werte und Anzeige folgen der Auswahl.
- Starte das Spiel; überprüfe, dass andere Encoder bis zum Start gesperrt sind.

## 9. Maintenance
- Re-run `.specify/scripts/powershell/update-agent-context.ps1 codex` after introducing new tooling.
- Keep microSD backups of `highscores/` and `config/` directories before deploying new firmware.

