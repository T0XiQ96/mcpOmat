#pragma once

#include <Arduino.h>

namespace cabinet
{
    struct SyncPacket
    {
        uint32_t sequenceId;
        uint8_t state;
        uint8_t activePlayers;
    };

    struct AckPacket
    {
        uint32_t sequenceId;
        bool accepted;
    };

    String serializeSyncPacket(const SyncPacket &packet);
    bool deserializeSyncPacket(const String &payload, SyncPacket &outPacket);

    String serializeAckPacket(const AckPacket &packet);
    bool deserializeAckPacket(const String &payload, AckPacket &outPacket);
} // namespace cabinet
