#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: Gold
lv_style_t *get_style_gold_MAIN_DEFAULT();
void add_style_gold(lv_obj_t *obj);
void remove_style_gold(lv_obj_t *obj);

// Style: Braun
lv_style_t *get_style_braun_MAIN_DEFAULT();
void add_style_braun(lv_obj_t *obj);
void remove_style_braun(lv_obj_t *obj);

// Style: GoldSelBraun
lv_style_t *get_style_gold_sel_braun_MAIN_DEFAULT();
lv_style_t *get_style_gold_sel_braun_SELECTED_DEFAULT();
void add_style_gold_sel_braun(lv_obj_t *obj);
void remove_style_gold_sel_braun(lv_obj_t *obj);

// Style: GoldTextArea
lv_style_t *get_style_gold_text_area_MAIN_DEFAULT();
void add_style_gold_text_area(lv_obj_t *obj);
void remove_style_gold_text_area(lv_obj_t *obj);

// Style: GoldKeyboard
lv_style_t *get_style_gold_keyboard_MAIN_DEFAULT();
lv_style_t *get_style_gold_keyboard_ITEMS_DEFAULT();
void add_style_gold_keyboard(lv_obj_t *obj);
void remove_style_gold_keyboard(lv_obj_t *obj);

// Style: goldPanel
lv_style_t *get_style_gold_panel_MAIN_DEFAULT();
void add_style_gold_panel(lv_obj_t *obj);
void remove_style_gold_panel(lv_obj_t *obj);

// Style: GoldDropdown^
lv_style_t *get_style_gold_dropdown__MAIN_DEFAULT();
lv_style_t *get_style_gold_dropdown__SELECTED_DEFAULT();
void add_style_gold_dropdown_(lv_obj_t *obj);
void remove_style_gold_dropdown_(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/