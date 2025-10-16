"""RS485 framing helpers shared by Arduino and ESP32 nodes."""

from __future__ import annotations

from dataclasses import dataclass

import crcmod


CRC8 = crcmod.predefined.mkPredefinedCrcFun("crc-8-maxim")
SYNC_BYTE = 0xAA


@dataclass
class Frame:
    """Represents a single RS485 frame with message type and payload."""

    msg_type: int
    payload: bytes

    def encode(self) -> bytes:
        if not 0 <= self.msg_type <= 0xFF:
            raise ValueError("msg_type must fit in one byte")
        length = len(self.payload)
        header = bytes([SYNC_BYTE, self.msg_type, length])
        crc = CRC8(header[1:] + self.payload)
        return header + self.payload + bytes([crc])

    @staticmethod
    def decode(buffer: bytes) -> "Frame":
        if len(buffer) < 4:
            raise ValueError("frame too short")
        if buffer[0] != SYNC_BYTE:
            raise ValueError("invalid sync byte")
        msg_type = buffer[1]
        length = buffer[2]
        if len(buffer) != length + 4:
            raise ValueError("length mismatch")
        payload = buffer[3:-1]
        crc_expected = buffer[-1]
        crc_actual = CRC8(buffer[1:-1])
        if crc_actual != crc_expected:
            raise ValueError("CRC mismatch")
        return Frame(msg_type=msg_type, payload=payload)
