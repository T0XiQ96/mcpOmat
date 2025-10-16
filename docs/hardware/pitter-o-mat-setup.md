# Pitter-o-mat Hardware Bring-up Checklist

## Power Budget
- Verify 5V 60A supply connected with 10AWG wiring to LED ring and logic rails.
- Ensure separate fused branch for Arduino/ESP32 electronics (5V/2A per node).

## Controllers
- Mount Arduino Mega 2560 with RS485 transceiver wired to Serial1 (TX=18, RX=19, DE=2).
- Install Waveshare ESP32S3-Touch-LCD-4 units; connect RS485 A/B lines in daisy chain.

## LED Ring
- Confirm SpielLED strand on Arduino pin 12 (data) with level shifting if required.
- Confirm GrenzLED strand on Arduino pin 13.
- Inject power every 144 LEDs around the ring to prevent voltage drop.

## Encoders
- Player 1 encoder: CLK=6, DT=7, SW=5.
- Remaining encoders: wire but disable until firmware ready.

## Displays
- Assign ESP32 screens per seat following spec (2-player -> screens 1 & 5, etc.).
- Connect microSD to master ESP32 for config/highscores.

## Safety Checks
- Perform insulation resistance test on LED ring.
- Validate emergency cut-off accessible and labelled.
- Boot test without LEDs at full brightness to confirm logic paths.
