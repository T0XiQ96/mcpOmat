#include "session_store.h"
#include "manifest_bridge.h"
#include <ArduinoJson.h>

namespace cabinet
{
    namespace
    {
        constexpr size_t kSessionDocCapacity = JSON_OBJECT_SIZE(5);
    }

    bool loadSession(SessionState &state)
    {
        String payload;
        if (!loadQuickstartManifest(payload))
        {
            return false;
        }

        StaticJsonDocument<kSessionDocCapacity> doc;
        if (deserializeJson(doc, payload))
        {
            state.playerCount = doc["players"] | 2;
            state.rounds = doc["rounds"] | 1;
            state.spinPreset = doc["speed"] | 0;
            state.jokerEnabled = doc["joker"] | false;
            state.jokerColor = doc["jokerColor"].as<String>();
            return true;
        }
        return false;
    }

    bool saveSession(const SessionState &state)
    {
        StaticJsonDocument<kSessionDocCapacity> doc;
        doc["players"] = state.playerCount;
        doc["rounds"] = state.rounds;
        doc["speed"] = state.spinPreset;
        doc["joker"] = state.jokerEnabled;
        doc["jokerColor"] = state.jokerColor;
        String payload;
        serializeJson(doc, payload);
        return storeQuickstartManifest(payload);
    }
}
