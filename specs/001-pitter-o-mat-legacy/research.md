# Research Log â€” Pitter-o-mat Multiplayer Console

## Decision: LED ring control architecture
- **Rationale**: The 864 WS2812 LEDs are already wired as two 36-group strings (SpielLED/GrenzLED). FastLED running on Arduino Mega supports parallel outputs using `FastLED.addLeds` on separate pins, keeping 100 Hz refresh achievable while managing memory via PROGMEM patterns. Group-level abstractions map directly to the 72 logical segments described in the spec, minimizing per-frame computations.
- **Alternatives considered**:
  - NeoPixel (Adafruit) library â€” simpler API but higher per-update latency and no native parallel output support on AVR.
  - Offloading to ESP32 â€” would require high-speed RS485 streaming of LED frames, increasing latency and complicating deterministic boundaries.

## Decision: Inter-device protocol over RS485
- **Rationale**: Define a framed binary protocol with a one-byte header (message type), payload length, CRC-8, and reserved firmware version byte. Scheduling a 5 ms polling interval keeps Arduino-to-ESP command latency beneath 50 ms while remaining tolerant to line noise. The shared `proto/` directory will host schema definitions plus Python-based encoders for tests.
- **Alternatives considered**:
  - Modbus RTU â€” well known but adds overhead and unused registers; custom slim framing better matches bespoke commands.
  - Plain-text JSON â€” human-readable but exceeds RS485 bandwidth budget during animation bursts and complicates MCU parsing.

## Decision: Highscore persistence workflow
- **Rationale**: Store highscores per game mode as JSON files on the master ESP32 microSD (`highscores/<mode>.json`) with companion-app-managed player names. ESP32 handles file rotations and shares snapshots with Arduino on request. This keeps Arduino firmware stateless and respects the requirement that highscore UI appears only for modes that support it.
- **Alternatives considered**:
  - SQLite on ESP32 â€” powerful but adds binary footprint and storage complexity for simple leaderboard needs.
  - Storing on Arduino EEPROM â€” insufficient capacity and limited write cycles relative to expected updates.

## Decision: Touch-first menu interaction
- **Rationale**: Zentralisiert Navigation auf den Waveshare ESP32S3 Touchscreens; vermeidet mechanische Encoder-Abhängigkeit und spiegelt den EEZ-Studio-Workflow wider, in dem alle Menüs bereits als Touchscreens modelliert werden. Encoder bleiben für spielinterne Aktionen reserviert.
- **Alternatives considered**:
  - Primäre Encoder-Steuerung für Menüs — inkonsistent mit UI-Design und schwer zu erweitern.
  - Gleichzeitige Nutzung von Touch und Encoder — erhöht Komplexität ohne zusätzlichen Nutzen.

