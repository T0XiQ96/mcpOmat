#pragma once

#include <Arduino.h>

namespace cabinet
{
    bool loadQuickstartManifest(String &jsonOut);
    bool storeQuickstartManifest(const String &jsonIn);
} // namespace cabinet
