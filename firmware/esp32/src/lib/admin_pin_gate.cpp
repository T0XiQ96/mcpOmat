#include "admin_pin_gate.h"

namespace cabinet
{
    namespace
    {
        unsigned long unlockTimestamp = 0;
        constexpr unsigned long kWindowMillis = 10000;
        bool unlocked = false;
    }

    void setupAdminPinGate()
    {
        lockAdmin();
    }

    void tickAdminPinGate()
    {
        if (unlocked && (millis() - unlockTimestamp) > kWindowMillis)
        {
            lockAdmin();
        }
    }

    bool isAdminUnlocked()
    {
        return unlocked;
    }

    void recordAdminInteraction()
    {
        unlocked = true;
        unlockTimestamp = millis();
    }

    void lockAdmin()
    {
        unlocked = false;
        unlockTimestamp = millis();
    }
}
