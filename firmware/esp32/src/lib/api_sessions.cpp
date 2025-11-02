#include "api_sessions.h"
#include "session_controller.h"

namespace cabinet
{
    void handleSessionPost()
    {
        // TODO: start a new game session using the current configuration.
    }

    void handleSessionPatch(const String &body)
    {
        // TODO: parse the request body and update session parameters before saving Quickstart state.
        (void)body;
    }
}
