#include "manifest_bridge.h"
#include <FS.h>
#include <SPIFFS.h>

namespace cabinet
{
    namespace
    {
        constexpr char kManifestPath[] = "/quickstart_manifest.json";
    } // namespace

    bool ensureSpiffs()
    {
        static bool mounted = false;
        if (!mounted)
        {
            mounted = SPIFFS.begin(true);
        }
        return mounted;
    }

    bool loadQuickstartManifest(String &jsonOut)
    {
        if (!ensureSpiffs())
        {
            return false;
        }

        File file = SPIFFS.open(kManifestPath, "r");
        if (!file)
        {
            return false;
        }
        jsonOut = file.readString();
        return true;
    }

    bool storeQuickstartManifest(const String &jsonIn)
    {
        if (!ensureSpiffs())
        {
            return false;
        }

        File file = SPIFFS.open(kManifestPath, "w");
        if (!file)
        {
            return false;
        }
        file.print(jsonIn);
        return true;
    }
} // namespace cabinet
