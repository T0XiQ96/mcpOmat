#include "sync_channel.h"
#include <AsyncUDP.h>

namespace cabinet
{
    namespace
    {
        AsyncUDP udp;
    }

    void beginSyncChannel()
    {
        // TODO: initialise UDP broadcast and bind to the configured port.
    }

    void pumpSyncChannel()
    {
        // TODO: poll incoming packets and dispatch acknowledgements.
    }

    bool sendSyncPacket(const SyncPacket &packet)
    {
        // TODO: publish the packet to all slave displays.
        (void)packet;
        return false;
    }
}
