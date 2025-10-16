# RS485 Protocol Contract – PitterOmat Core Experience

## Overview

Communication between the ESP32-S3 master and the Arduino Mega relies on a framed RS485 protocol defined in `firmware/shared/proto/rs485_frame.py`:

- Sync byte: `0xAA`
- Header: `[SYNC][MSG_TYPE][LENGTH]`
- Payload: `LENGTH` bytes
- CRC: `crc-8-maxim` over `[MSG_TYPE][LENGTH][PAYLOAD]`

All frames operate at 115 200 baud, 8N1.

## Message Catalogue

| Msg Type | Direction | Payload Schema | Description |
|----------|-----------|----------------|-------------|
| `0x01` | ESP32 → Arduino | `{ sessionId (uint8), playerCount (uint8), jokerEnabled (bool), jokerColor (uint24) }` | Announces a new session configuration and triggers PlayerSlot allocation on Arduino. |
| `0x02` | ESP32 → Arduino | `[ playerSlotId (uint8), spielStart (uint8), spielEnd (uint8), borderLeft (uint8), borderRight (uint8) ]` repeated for each active slot | Delivers LED mapping details after configuration. |
| `0x03` | Arduino → ESP32 | `{ nodeId (uint8), status (enum: 0=ready,1=syncing,2=fault), errorCode (uint8) }` | Heartbeat plus fault reporting for diagnostics. |
| `0x04` | ESP32 → Arduino | `{ scoreDelta (int16), slotId (uint8) }` | Publishes score updates to animate LED segments. |
| `0x05` | ESP32 ↔ Arduino | `{ manifestHash (bytes[32]) }` | Hash synchronization handshake; Arduino echoes back to confirm match. |
| `0x06` | Arduino → ESP32 | `{ buttonMask (uint8) }` | Ready-check button states; ESP32 waits for mask == all active players. |
| `0x07` | ESP32 → Arduino | `{ animationId (uint8), durationMs (uint16) }` | Signals win/lose/celebration animations. |

Future messages must reserve new type IDs and update this document plus the shared framing helper.

## Error Handling

- Frames failing CRC are discarded; receiver requests resend by sending `0x0F` with no payload.
- If Arduino misses three consecutive configuration frames, it drops into `fault` status and requires admin intervention.
- ESP32 refuses to transition from `ReadyCheck` to `Gameplay` until message types `0x01`, `0x02`, and `0x05` complete successfully.

## Versioning

- Protocol version is implicit in firmware version; update manifests must note protocol changes and bump the major version if backward-incompatible.
- All changes to message payloads require synchronized updates to `firmware/shared/proto/rs485_frame.py`, Arduino parser code, and this contract file.
