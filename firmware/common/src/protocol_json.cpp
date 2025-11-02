#include "cabinet_protocol.h"
#include <ArduinoJson.h>

namespace cabinet
{
    namespace
    {
        constexpr size_t kSyncCapacity = JSON_OBJECT_SIZE(4);
        constexpr size_t kAckCapacity = JSON_OBJECT_SIZE(2);
    } // namespace

    String serializeSyncPacket(const SyncPacket &packet)
    {
        StaticJsonDocument<kSyncCapacity> doc;
        doc["seq"] = packet.sequenceId;
        doc["state"] = packet.state;
        doc["players"] = packet.activePlayers;
        String output;
        serializeJson(doc, output);
        return output;
    }

    bool deserializeSyncPacket(const String &payload, SyncPacket &outPacket)
    {
        StaticJsonDocument<kSyncCapacity> doc;
        DeserializationError err = deserializeJson(doc, payload);
        if (err)
        {
            return false;
        }

        outPacket.sequenceId = doc["seq"] | 0u;
        outPacket.state = doc["state"] | 0u;
        outPacket.activePlayers = doc["players"] | 0u;
        return true;
    }

    String serializeAckPacket(const AckPacket &packet)
    {
        StaticJsonDocument<kAckCapacity> doc;
        doc["seq"] = packet.sequenceId;
        doc["ok"] = packet.accepted;
        String output;
        serializeJson(doc, output);
        return output;
    }

    bool deserializeAckPacket(const String &payload, AckPacket &outPacket)
    {
        StaticJsonDocument<kAckCapacity> doc;
        DeserializationError err = deserializeJson(doc, payload);
        if (err)
        {
            return false;
        }

        outPacket.sequenceId = doc["seq"] | 0u;
        outPacket.accepted = doc["ok"] | false;
        return true;
    }
} // namespace cabinet
