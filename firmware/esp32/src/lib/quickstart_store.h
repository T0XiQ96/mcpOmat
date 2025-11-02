#pragma once

#include "session_store.h"

namespace cabinet
{
    bool loadQuickstart(SessionState &state);
    bool saveQuickstart(const SessionState &state);
}

