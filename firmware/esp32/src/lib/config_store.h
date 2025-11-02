#pragma once

#include <Arduino.h>

namespace cabinet
{
    struct AmbienceConfig
    {
        uint8_t spielLedPercent;
        uint8_t borderLedPercent;
        uint8_t displayBrightness;
        uint32_t idleTimeoutSeconds;
    };

    bool loadAmbience(AmbienceConfig &config);
    bool saveAmbience(const AmbienceConfig &config);
}

