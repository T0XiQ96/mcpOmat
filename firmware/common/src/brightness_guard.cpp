#include "brightness_guard.h"

namespace cabinet
{
    uint8_t clampLedPercent(uint8_t requestedPercent)
    {
        if (requestedPercent > kMaxLedBrightnessPercent)
        {
            return kMaxLedBrightnessPercent;
        }
        return requestedPercent;
    }

    void applyBrightnessGuard(uint8_t &spielLedPercent, uint8_t &borderLedPercent)
    {
        spielLedPercent = clampLedPercent(spielLedPercent);
        borderLedPercent = clampLedPercent(borderLedPercent);
    }
} // namespace cabinet
