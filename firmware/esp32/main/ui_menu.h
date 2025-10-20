#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initializes menu data and registers LVGL callbacks if the generated UI
 * objects are already created.
 *
 * Safe to call multiple times; additional calls refresh the cached manifest
 * data and re-run the filtering logic.
 */
void ui_menu_init(void);

/**
 * Optional periodic hook (e.g. from main loop) in case the UI is created
 * lazily. Calling this will attempt to register pending callbacks whenever
 * the LVGL objects become available.
 */
void ui_menu_tick(void);

/**
 * Returns the currently selected player count (defaults to 2).
 */
uint8_t ui_menu_get_player_count(void);

/**
 * Returns the manifest ID of the currently selected game or NULL if no game
 * matches the current filter.
 */
const char *ui_menu_get_selected_game_id(void);

#ifdef __cplusplus
}
#endif

