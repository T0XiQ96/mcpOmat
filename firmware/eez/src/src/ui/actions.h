#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_cmd_led_ring_test(lv_event_t * e);
extern void action_cmd_send_spin_start_to_arduino(lv_event_t * e);
extern void action_cmd_send_joker_start_to_arduino(lv_event_t * e);
extern void action_cmd_send_joker_stop_to_arduino(lv_event_t * e);
extern void action_cmd_send_joker_preview(lv_event_t * e);
extern void action_cmd_send_joker_hit_to_arduino(lv_event_t * e);
extern void action_cmd_send_borders_state_to_arduino(lv_event_t * e);
extern void action_cmd_send_player_colors_preview(lv_event_t * e);
extern void action_cmd_send_border_colors_preview(lv_event_t * e);
extern void action_cmd_send_led_game_brightness(lv_event_t * e);
extern void action_cmd_send_led_border_brightness(lv_event_t * e);
extern void action_cmd_set_display_brightness(lv_event_t * e);
extern void action_cmd_send_game_end(lv_event_t * e);
extern void action_cmd_send_preview_clear(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/