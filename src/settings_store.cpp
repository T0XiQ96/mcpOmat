#include "settings_store.h"

#include <Arduino.h>
#include <Preferences.h>
#include <string.h>

#include "eez-flow.h"
#include "vars.h"

namespace {

constexpr uint32_t SETTINGS_MAGIC = 0x504F4D41;  // 'POMA'
constexpr uint8_t SETTINGS_VERSION = 1;

struct PersistedSettings {
    uint32_t magic;
    uint8_t version;
    PlayerStateSettings player;
    BorderStateSettings border;
    BrightnessSettings brightness;
    SpinSettings spin;
    uint8_t showBorders;
    uint8_t reserved[11];  // alignment / future use
    uint32_t crc32;
};

PersistedSettings g_settings;
Preferences g_prefs;
bool g_prefsOpen = false;
bool g_dirty = false;
uint32_t g_nextFlushMs = 0;

bool assignIfChanged(uint8_t &dst, uint8_t value) {
    if (dst == value) {
        return false;
    }
    dst = value;
    return true;
}

bool assignIfChanged(uint16_t &dst, uint16_t value) {
    if (dst == value) {
        return false;
    }
    dst = value;
    return true;
}

bool assignIfChanged(int16_t &dst, int16_t value) {
    if (dst == value) {
        return false;
    }
    dst = value;
    return true;
}

uint32_t calcCrc(const PersistedSettings &cfg) {
    const uint8_t *ptr = reinterpret_cast<const uint8_t *>(&cfg);
    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < sizeof(PersistedSettings) - sizeof(uint32_t); ++i) {
        crc ^= ptr[i];
        for (int b = 0; b < 8; ++b) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0xEDB88320UL;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc ^ 0xFFFFFFFF;
}

void applyDefaults(PersistedSettings &cfg) {
    memset(&cfg, 0, sizeof(cfg));
    cfg.magic = SETTINGS_MAGIC;
    cfg.version = SETTINGS_VERSION;
    cfg.player = {6, 1, 3, 0, 0};      // 6 Spieler, "Jeder eigene", Rot als Default
    cfg.border = {0, 0};               // Einfarbig, Braun
    cfg.brightness = {80, 60};
    cfg.spin = {5, 12, 5, 12, 8, 14, 30};
    cfg.showBorders = 1;
}

void markDirty() {
    g_dirty = true;
    g_nextFlushMs = millis() + 500;
}

void writeGlobals() {
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_PLAYER_COUNT, eez::IntegerValue(g_settings.player.playerCount));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_PLAYER_COLOR_MODE_INDEX, eez::IntegerValue(g_settings.player.mode));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_PLAYER_SINGLE_COLOR_INDEX, eez::IntegerValue(g_settings.player.singleColor));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_PLAYER_OWN_COLOR_FLAG, eez::IntegerValue(g_settings.player.ownRandom));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_INACTIVE_EFFECT_INDEX, eez::IntegerValue(g_settings.player.inactiveMode));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_BORDER_COLOR_MODE_INDEX, eez::IntegerValue(g_settings.border.mode));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_BORDER_SINGLE_COLOR_INDEX, eez::IntegerValue(g_settings.border.singleColor));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_LED_GAME_BRIGHTNESS, eez::IntegerValue(g_settings.brightness.game));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_LED_BORDER_BRIGHTNESS, eez::IntegerValue(g_settings.brightness.border));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_LL_ACCEL_TURNS_MIN10, eez::IntegerValue(g_settings.spin.accelMin10));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_LL_ACCEL_TURNS_MAX10, eez::IntegerValue(g_settings.spin.accelMax10));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_LL_DECEL_TURNS_MIN10, eez::IntegerValue(g_settings.spin.decelMin10));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_LL_DECEL_TURNS_MAX10, eez::IntegerValue(g_settings.spin.decelMax10));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_LL_MAX_SPEED_TURNS_MIN10, eez::IntegerValue(g_settings.spin.maxMin10));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_LL_MAX_SPEED_TURNS_MAX10, eez::IntegerValue(g_settings.spin.maxMax10));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_LL_STEP_MS, eez::IntegerValue(g_settings.spin.stepMs));
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_LL_SHOW_BORDERS, eez::IntegerValue(g_settings.showBorders ? 1 : 0));
}

}  // namespace

void settings_init() {
    g_prefsOpen = g_prefs.begin("lichtlos", false);
    if (!g_prefsOpen) {
        applyDefaults(g_settings);
        return;
    }
    size_t stored = g_prefs.getBytesLength("cfg");
    if (stored != sizeof(PersistedSettings)) {
        applyDefaults(g_settings);
        return;
    }
    g_prefs.getBytes("cfg", &g_settings, sizeof(g_settings));
    if (g_settings.magic != SETTINGS_MAGIC || g_settings.version != SETTINGS_VERSION ||
        g_settings.crc32 != calcCrc(g_settings)) {
        applyDefaults(g_settings);
    }
}

void settings_factory_reset() {
    applyDefaults(g_settings);
    g_settings.crc32 = calcCrc(g_settings);
    if (!g_prefsOpen) {
        g_prefsOpen = g_prefs.begin("lichtlos", false);
    }
    if (g_prefsOpen) {
        g_prefs.putBytes("cfg", &g_settings, sizeof(g_settings));
    }
    writeGlobals();
}

void settings_apply_to_flow() {
    writeGlobals();
}

void settings_schedule_flush() {
    markDirty();
}

void settings_process() {
    if (!g_dirty) {
        return;
    }
    if (millis() < g_nextFlushMs) {
        return;
    }
    g_settings.crc32 = calcCrc(g_settings);
    if (!g_prefsOpen) {
        g_prefsOpen = g_prefs.begin("lichtlos", false);
    }
    if (g_prefsOpen) {
        g_prefs.putBytes("cfg", &g_settings, sizeof(g_settings));
        g_dirty = false;
    }
}

void settings_set_player_state(const PlayerStateSettings &state) {
    bool changed = false;
    changed |= assignIfChanged(g_settings.player.playerCount, state.playerCount);
    changed |= assignIfChanged(g_settings.player.mode, state.mode);
    changed |= assignIfChanged(g_settings.player.singleColor, state.singleColor);
    changed |= assignIfChanged(g_settings.player.ownRandom, state.ownRandom);
    changed |= assignIfChanged(g_settings.player.inactiveMode, state.inactiveMode);
    if (changed) {
        markDirty();
    }
}

void settings_set_border_state(const BorderStateSettings &state) {
    bool changed = false;
    changed |= assignIfChanged(g_settings.border.mode, state.mode);
    changed |= assignIfChanged(g_settings.border.singleColor, state.singleColor);
    if (changed) {
        markDirty();
    }
}

void settings_set_brightness(const BrightnessSettings &state) {
    bool changed = false;
    changed |= assignIfChanged(g_settings.brightness.game, state.game);
    changed |= assignIfChanged(g_settings.brightness.border, state.border);
    if (changed) {
        markDirty();
    }
}

void settings_set_spin(const SpinSettings &state) {
    bool changed = false;
    changed |= assignIfChanged(g_settings.spin.accelMin10, state.accelMin10);
    changed |= assignIfChanged(g_settings.spin.accelMax10, state.accelMax10);
    changed |= assignIfChanged(g_settings.spin.decelMin10, state.decelMin10);
    changed |= assignIfChanged(g_settings.spin.decelMax10, state.decelMax10);
    changed |= assignIfChanged(g_settings.spin.maxMin10, state.maxMin10);
    changed |= assignIfChanged(g_settings.spin.maxMax10, state.maxMax10);
    changed |= assignIfChanged(g_settings.spin.stepMs, state.stepMs);
    if (changed) {
        markDirty();
    }
}

void settings_set_show_borders(bool enable) {
    if (g_settings.showBorders == static_cast<uint8_t>(enable)) {
        return;
    }
    g_settings.showBorders = enable ? 1 : 0;
    markDirty();
}

const PlayerStateSettings &settings_get_player() {
    return g_settings.player;
}

const BorderStateSettings &settings_get_border() {
    return g_settings.border;
}

const BrightnessSettings &settings_get_brightness() {
    return g_settings.brightness;
}

const SpinSettings &settings_get_spin() {
    return g_settings.spin;
}

bool settings_get_show_borders() {
    return g_settings.showBorders != 0;
}
