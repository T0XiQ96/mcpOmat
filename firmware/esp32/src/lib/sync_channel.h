#pragma once

#include <Arduino.h>
#include "cabinet_protocol.h"

namespace cabinet
{
    void beginSyncChannel();
    void pumpSyncChannel();
    bool sendSyncPacket(const SyncPacket &packet);
}

