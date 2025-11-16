#pragma once

#include <stdint.h>

struct PlayerStateSettings {
    uint8_t playerCount;
    uint8_t mode;
    uint8_t singleColor;
    uint8_t ownRandom;
    uint8_t inactiveMode;
};

struct BorderStateSettings {
    uint8_t mode;
    uint8_t singleColor;
};

struct BrightnessSettings {
    uint16_t game;
    uint16_t border;
};

struct SpinSettings {
    int16_t accelMin10;
    int16_t accelMax10;
    int16_t decelMin10;
    int16_t decelMax10;
    int16_t maxMin10;
    int16_t maxMax10;
    int16_t stepMs;
};

void settings_init();
void settings_factory_reset();
void settings_apply_to_flow();
void settings_process();

void settings_set_player_state(const PlayerStateSettings &state);
void settings_set_border_state(const BorderStateSettings &state);
void settings_set_brightness(const BrightnessSettings &state);
void settings_set_spin(const SpinSettings &state);
void settings_set_show_borders(bool enable);

const PlayerStateSettings &settings_get_player();
const BorderStateSettings &settings_get_border();
const BrightnessSettings &settings_get_brightness();
const SpinSettings &settings_get_spin();
bool settings_get_show_borders();

void settings_schedule_flush();
