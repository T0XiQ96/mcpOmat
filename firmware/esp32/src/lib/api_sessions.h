#pragma once

#include <Arduino.h>
#include "session_store.h"

namespace cabinet
{
    void handleSessionPost();
    void handleSessionPatch(const String &body);
}

