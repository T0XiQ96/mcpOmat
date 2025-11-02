#pragma once

#include <Arduino.h>

namespace cabinet
{
    void setupAdminPinGate();
    void tickAdminPinGate();
    bool isAdminUnlocked();
    void recordAdminInteraction();
    void lockAdmin();
}

