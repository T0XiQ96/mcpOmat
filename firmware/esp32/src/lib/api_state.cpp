#include "api_state.h"
#include "session_controller.h"
#include "cabinet_protocol.h"
#include <ArduinoJson.h>

namespace cabinet
{
    String buildStateDocument()
    {
        StaticJsonDocument<JSON_OBJECT_SIZE(4)> doc;
        const SessionState &state = getCurrentSession();
        doc["players"] = state.playerCount;
        doc["rounds"] = state.rounds;
        doc["joker"] = state.jokerEnabled;
        doc["jokerColor"] = state.jokerColor;
        String output;
        serializeJson(doc, output);
        return output;
    }
}
