#include "session_controller.h"
#include "quickstart_store.h"

namespace cabinet
{
    namespace
    {
        SessionState currentState{};
    }

    void beginSessionController()
    {
        loadQuickstart(currentState);
    }

    void updateSessionController()
    {
        // TODO: push state to UI layers and detect transitions triggered by hardware inputs.
    }

    const SessionState &getCurrentSession()
    {
        return currentState;
    }

    void applySyncPacket(const SyncPacket &packet)
    {
        // TODO: map incoming packet fields onto the current session state.
        (void)packet;
    }
}
