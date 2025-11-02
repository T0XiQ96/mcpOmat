#include "debug_overlay.h"

namespace cabinet
{
    namespace
    {
        bool overlayVisible = false;
    }

    void setupDebugOverlay()
    {
        // TODO: initialise LVGL elements for the overlay layer.
    }

    void updateDebugOverlay()
    {
        // TODO: refresh overlay content if visible.
    }

    void setOverlayVisible(bool visible)
    {
        overlayVisible = visible;
    }
}
