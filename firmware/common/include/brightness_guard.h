#pragma once

#include <Arduino.h>

namespace cabinet
{
    constexpr uint8_t kMaxLedBrightnessPercent = 55;

    uint8_t clampLedPercent(uint8_t requestedPercent);
    void applyBrightnessGuard(uint8_t &spielLedPercent, uint8_t &borderLedPercent);
} // namespace cabinet
