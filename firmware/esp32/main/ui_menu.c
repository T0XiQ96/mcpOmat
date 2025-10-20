#include "ui_menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#include "lvgl.h"
#include "cJSON.h"

#include "ui/ui.h"
#include "ui/screens.h"

#include "storage_config.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef struct {
    char id[64];
    char title[96];
    uint8_t min_players;
    uint8_t max_players;
} menu_game_t;

typedef struct {
    menu_game_t *items;
    size_t count;
    size_t capacity;
} game_list_t;

static menu_game_t s_static_games_storage[32];
static game_list_t s_games = {
    .items = s_static_games_storage,
    .count = 0,
    .capacity = ARRAY_SIZE(s_static_games_storage),
};

static uint8_t s_player_count = 2;
static int s_selected_game_index = -1;

static int s_filtered_indices[32];
static size_t s_filtered_count = 0;

static bool s_callbacks_registered = false;
static bool s_manifest_loaded = false;

static void ensure_callbacks_registered(void);
static void update_game_filter(void);

static void add_game(const char *id, const char *title, uint8_t min_players, uint8_t max_players)
{
    if (s_games.count >= s_games.capacity) {
        return;
    }

    menu_game_t *game = &s_games.items[s_games.count++];
    strncpy(game->id, id ? id : "unknown", sizeof(game->id) - 1);
    game->id[sizeof(game->id) - 1] = '\0';

    const char *fallback_title = id ? id : "Unbenannt";
    const char *src_title = (title && title[0]) ? title : fallback_title;
    strncpy(game->title, src_title, sizeof(game->title) - 1);
    game->title[sizeof(game->title) - 1] = '\0';

    game->min_players = min_players ? min_players : 1;
    game->max_players = max_players ? max_players : 6;
}

static void load_games_from_manifest(void)
{
    s_games.count = 0;

    const char *root = storage_config_root();
    char manifest_path[256];
    snprintf(manifest_path, sizeof(manifest_path), "%s/manifest.json", root);

    FILE *fp = fopen(manifest_path, "rb");
    if (!fp) {
        fp = fopen("SDCARD/manifest.json", "rb");
    }
    if (!fp) {
        // Fallback to demo game if manifest missing
        add_game("sample-rotation", "Demo-Setup Rotation", 2, 4);
        s_manifest_loaded = false;
        return;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (size <= 0 || size > 512 * 1024) {
        fclose(fp);
        add_game("sample-rotation", "Demo-Setup Rotation", 2, 4);
        s_manifest_loaded = false;
        return;
    }

    char *buffer = (char *)malloc((size_t)size + 1);
    if (!buffer) {
        fclose(fp);
        add_game("sample-rotation", "Demo-Setup Rotation", 2, 4);
        s_manifest_loaded = false;
        return;
    }

    size_t read = fread(buffer, 1, (size_t)size, fp);
    fclose(fp);
    buffer[read] = '\0';

    cJSON *root_json = cJSON_Parse(buffer);
    free(buffer);

    if (!root_json) {
        add_game("sample-rotation", "Demo-Setup Rotation", 2, 4);
        s_manifest_loaded = false;
        return;
    }

    cJSON *content = cJSON_GetObjectItem(root_json, "content");
    if (!cJSON_IsArray(content)) {
        cJSON_Delete(root_json);
        add_game("sample-rotation", "Demo-Setup Rotation", 2, 4);
        s_manifest_loaded = false;
        return;
    }

    cJSON *category = NULL;
    cJSON_ArrayForEach(category, content) {
        cJSON *type = cJSON_GetObjectItem(category, "type");
        cJSON *entries = cJSON_GetObjectItem(category, "entries");
        if (!cJSON_IsString(type) || strcmp(type->valuestring, "game") != 0 || !cJSON_IsArray(entries)) {
            continue;
        }

        cJSON *entry = NULL;
        cJSON_ArrayForEach(entry, entries) {
            cJSON *id = cJSON_GetObjectItem(entry, "id");
            cJSON *title = cJSON_GetObjectItem(entry, "title");
            cJSON *players = cJSON_GetObjectItem(entry, "players");
            uint8_t min_players = 1;
            uint8_t max_players = 6;
            if (cJSON_IsObject(players)) {
                cJSON *min = cJSON_GetObjectItem(players, "min");
                cJSON *max = cJSON_GetObjectItem(players, "max");
                if (cJSON_IsNumber(min)) {
                    min_players = (uint8_t)min->valuedouble;
                }
                if (cJSON_IsNumber(max)) {
                    max_players = (uint8_t)max->valuedouble;
                }
            }
            add_game(
                cJSON_IsString(id) ? id->valuestring : "game",
                cJSON_IsString(title) ? title->valuestring : NULL,
                min_players,
                max_players
            );
        }
    }

    cJSON_Delete(root_json);

    if (s_games.count == 0) {
        add_game("sample-rotation", "Demo-Setup Rotation", 2, 4);
        s_manifest_loaded = false;
        return;
    }

    s_manifest_loaded = true;
}

static bool game_supports_player_count(const menu_game_t *game, uint8_t players)
{
    return players >= game->min_players && players <= game->max_players;
}

static void append_text(char *buffer, size_t buffer_len, const char *text)
{
    size_t used = strlen(buffer);
    if (used >= buffer_len) {
        return;
    }
    size_t remaining = buffer_len - used;
    if (remaining == 0) {
        return;
    }
    int written = snprintf(buffer + used, remaining, "%s", text);
    if (written < 0) {
        return;
    }
}

static void update_game_filter(void)
{
    s_filtered_count = 0;
    s_selected_game_index = -1;

    for (size_t i = 0; i < s_games.count; ++i) {
        if (game_supports_player_count(&s_games.items[i], s_player_count)) {
            if (s_filtered_count < ARRAY_SIZE(s_filtered_indices)) {
                s_filtered_indices[s_filtered_count++] = (int)i;
            }
        }
    }

    if (s_filtered_count > 0) {
        s_selected_game_index = s_filtered_indices[0];
    }

    if (objects.game_roller) {
        char options[512];
        options[0] = '\0';
        if (s_filtered_count == 0) {
            append_text(options, sizeof(options), "Keine Spiele verfügbar");
        } else {
            for (size_t i = 0; i < s_filtered_count; ++i) {
                const menu_game_t *game = &s_games.items[s_filtered_indices[i]];
                if (options[0] != '\0') {
                    append_text(options, sizeof(options), "\n");
                }
                append_text(options, sizeof(options), game->title);
            }
        }

        lv_roller_set_options(objects.game_roller, options, LV_ROLLER_MODE_INFINITE);
        lv_roller_set_selected(objects.game_roller, 0, LV_ANIM_OFF);
    }
}

static void on_player_roller_changed(lv_event_t *e)
{
    if (lv_event_get_code(e) != LV_EVENT_VALUE_CHANGED) {
        return;
    }
    if (!objects.player_roller) {
        return;
    }

    int selected = lv_roller_get_selected(objects.player_roller);
    if (selected < 0) {
        selected = 0;
    }
    s_player_count = (uint8_t)(selected + 2); // options start at 2 Spieler
    update_game_filter();
}

static void on_player_confirm(lv_event_t *e)
{
    if (lv_event_get_code(e) != LV_EVENT_CLICKED && lv_event_get_code(e) != LV_EVENT_RELEASED) {
        return;
    }

    update_game_filter();
#if !defined(EEZ_FOR_LVGL)
    loadScreen(SCREEN_ID_CHOOSE_GAME_SCREEN);
#endif
}

static void on_game_screen_loaded(lv_event_t *e)
{
    if (lv_event_get_code(e) == LV_EVENT_SCREEN_LOAD_START) {
        update_game_filter();
    }
}

static void on_game_roller_changed(lv_event_t *e)
{
    if (lv_event_get_code(e) != LV_EVENT_VALUE_CHANGED) {
        return;
    }
    if (!objects.game_roller || s_filtered_count == 0) {
        s_selected_game_index = -1;
        return;
    }

    int selected = lv_roller_get_selected(objects.game_roller);
    if (selected < 0) {
        selected = 0;
    }
    if ((size_t)selected >= s_filtered_count) {
        selected = (int)(s_filtered_count - 1);
    }
    s_selected_game_index = s_filtered_indices[selected];
}

static void ensure_callbacks_registered(void)
{
    if (s_callbacks_registered) {
        return;
    }

    if (!objects.choose_player_screen || !objects.player_roller || !objects.obj2) {
        return;
    }

    lv_obj_add_event_cb(objects.player_roller, on_player_roller_changed, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(objects.obj2, on_player_confirm, LV_EVENT_CLICKED, NULL);

    if (objects.choose_game_screen) {
        lv_obj_add_event_cb(objects.choose_game_screen, on_game_screen_loaded, LV_EVENT_ALL, NULL);
    }
    if (objects.game_roller) {
        lv_obj_add_event_cb(objects.game_roller, on_game_roller_changed, LV_EVENT_VALUE_CHANGED, NULL);
    }

    s_callbacks_registered = true;
}

void ui_menu_init(void)
{
    load_games_from_manifest();
    update_game_filter();
    ensure_callbacks_registered();
}

void ui_menu_tick(void)
{
    // During lazy screen creation we may need to re-attempt callback registration.
    if (!s_callbacks_registered) {
        ensure_callbacks_registered();
    }
}

uint8_t ui_menu_get_player_count(void)
{
    return s_player_count;
}

const char *ui_menu_get_selected_game_id(void)
{
    if (s_selected_game_index < 0 || (size_t)s_selected_game_index >= s_games.count) {
        return NULL;
    }
    return s_games.items[s_selected_game_index].id;
}
