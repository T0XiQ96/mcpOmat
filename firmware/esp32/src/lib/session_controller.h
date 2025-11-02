#pragma once

#include "session_store.h"
#include "cabinet_protocol.h"

namespace cabinet
{
    void beginSessionController();
    void updateSessionController();
    const SessionState &getCurrentSession();
    void applySyncPacket(const SyncPacket &packet);
}

