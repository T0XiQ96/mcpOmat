#pragma once

#include <Arduino.h>

namespace cabinet
{
    struct SessionState
    {
        uint8_t playerCount;
        uint8_t rounds;
        uint8_t spinPreset;
        bool jokerEnabled;
        String jokerColor;
    };

    bool loadSession(SessionState &state);
    bool saveSession(const SessionState &state);
}

