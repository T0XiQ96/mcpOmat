#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_act_player_roller_value_changed(lv_event_t * e);
extern void action_cmd_led_ring_test(lv_event_t * e);
extern void action_cmd_send_spin_start_to_arduino(lv_event_t * e);
extern void action_cmd_send_joker_start_to_arduino(lv_event_t * e);
extern void action_cmd_send_joker_stop_to_arduino(lv_event_t * e);
extern void action_cmd_send_joker_preview(lv_event_t * e);
extern void action_cmd_send_borders_state_to_arduino(lv_event_t * e);
extern void action_cmd_send_player_colors_preview(lv_event_t * e);
extern void action_cmd_send_border_colors_preview(lv_event_t * e);
extern void action_cmd_send_led_game_brightness(lv_event_t * e);
extern void action_cmd_send_led_border_brightness(lv_event_t * e);
extern void action_cmd_set_display_brightness(lv_event_t * e);
extern void action_cmd_send_game_end(lv_event_t * e);
extern void action_cmd_send_preview_clear(lv_event_t * e);
extern void action_cmd_send_spin_params_to_arduino(lv_event_t * e);
extern void action_settings_load(lv_event_t * e);
extern void action_settings_factory_reset(lv_event_t * e);
extern void action_send_player_state(lv_event_t * e);
extern void action_send_border_state(lv_event_t * e);
extern void action_settings_mark_dirty(lv_event_t * e);
extern void action_settings_apply_to_flow(lv_event_t * e);
extern void action_settings_schedule_flush(lv_event_t * e);
extern void action_settings_set__(lv_event_t * e);
extern void action_send_all_settings_to_arduino(lv_event_t * e);
extern void action_cmd_send_cfg_joker(lv_event_t * e);
extern void action_send_cfg_players(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/