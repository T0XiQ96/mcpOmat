#include "quickstart_store.h"

namespace cabinet
{
    bool loadQuickstart(SessionState &state)
    {
        return loadSession(state);
    }

    bool saveQuickstart(const SessionState &state)
    {
        return saveSession(state);
    }
}
