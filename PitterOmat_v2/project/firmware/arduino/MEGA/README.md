# MEGA — RS-485 & Buttons

- Verdrahten: MAX485 (DE/RE an `DE_PIN`), `Serial2` (RX/TX), Buttons an D22..D25 (Pull‑Up).
- Sketch: `button_bridge_rs485.ino` — sendet Eventpakete bei Button‑Down, echo't empfangene Bytes.
- Baudrate: 115200. Abschlusswiderstand & Fail‑safe ggf. vorsehen.
