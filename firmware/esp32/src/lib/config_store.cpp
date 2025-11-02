#include "config_store.h"
#include "manifest_bridge.h"
#include <ArduinoJson.h>

namespace cabinet
{
    namespace
    {
        constexpr size_t kConfigCapacity = JSON_OBJECT_SIZE(4);
    }

    bool loadAmbience(AmbienceConfig &config)
    {
        String payload;
        if (!loadQuickstartManifest(payload))
        {
            return false;
        }

        StaticJsonDocument<kConfigCapacity> doc;
        if (deserializeJson(doc, payload))
        {
            config.spielLedPercent = doc["spielBrightness"] | 40;
            config.borderLedPercent = doc["borderBrightness"] | 40;
            config.displayBrightness = doc["displayBrightness"] | 60;
            config.idleTimeoutSeconds = doc["idleTimeout"] | 30;
            return true;
        }
        return false;
    }

    bool saveAmbience(const AmbienceConfig &config)
    {
        StaticJsonDocument<kConfigCapacity> doc;
        doc["spielBrightness"] = config.spielLedPercent;
        doc["borderBrightness"] = config.borderLedPercent;
        doc["displayBrightness"] = config.displayBrightness;
        doc["idleTimeout"] = config.idleTimeoutSeconds;
        String payload;
        serializeJson(doc, payload);
        return storeQuickstartManifest(payload);
    }
}
