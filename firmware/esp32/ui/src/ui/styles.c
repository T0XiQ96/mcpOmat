#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: Gold
//

void init_style_gold_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xfffdd111));
};

lv_style_t *get_style_gold_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_gold_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_gold(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_gold_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_gold(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_gold_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Braun
//

void init_style_braun_MAIN_DEFAULT(lv_style_t *style) {
    init_style_gold_MAIN_DEFAULT(style);
    
    lv_style_set_bg_color(style, lv_color_hex(0xffab7c46));
};

lv_style_t *get_style_braun_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_braun_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_braun(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_braun_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_braun(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_braun_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: GoldSelBraun
//

void init_style_gold_sel_braun_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_point80);
    lv_style_set_bg_color(style, lv_color_hex(0xfffdd111));
    lv_style_set_border_color(style, lv_color_hex(0xffab7c46));
};

lv_style_t *get_style_gold_sel_braun_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_gold_sel_braun_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_gold_sel_braun_SELECTED_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xffab7c46));
};

lv_style_t *get_style_gold_sel_braun_SELECTED_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_gold_sel_braun_SELECTED_DEFAULT(style);
    }
    return style;
};

void add_style_gold_sel_braun(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_gold_sel_braun_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_gold_sel_braun_SELECTED_DEFAULT(), LV_PART_SELECTED | LV_STATE_DEFAULT);
};

void remove_style_gold_sel_braun(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_gold_sel_braun_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_gold_sel_braun_SELECTED_DEFAULT(), LV_PART_SELECTED | LV_STATE_DEFAULT);
};

//
// Style: GoldTextArea
//

void init_style_gold_text_area_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xfffdd111));
    lv_style_set_border_color(style, lv_color_hex(0xffab7c46));
};

lv_style_t *get_style_gold_text_area_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_gold_text_area_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_gold_text_area(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_gold_text_area_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_gold_text_area(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_gold_text_area_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: GoldKeyboard
//

void init_style_gold_keyboard_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_align(style, LV_ALIGN_DEFAULT);
    lv_style_set_bg_color(style, lv_color_hex(0xffab7c46));
};

lv_style_t *get_style_gold_keyboard_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_gold_keyboard_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_gold_keyboard_ITEMS_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xfffdd111));
};

lv_style_t *get_style_gold_keyboard_ITEMS_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_gold_keyboard_ITEMS_DEFAULT(style);
    }
    return style;
};

void add_style_gold_keyboard(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_gold_keyboard_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_gold_keyboard_ITEMS_DEFAULT(), LV_PART_ITEMS | LV_STATE_DEFAULT);
};

void remove_style_gold_keyboard(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_gold_keyboard_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_gold_keyboard_ITEMS_DEFAULT(), LV_PART_ITEMS | LV_STATE_DEFAULT);
};

//
// Style: goldPanel
//

void init_style_gold_panel_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xfffdd111));
    lv_style_set_border_color(style, lv_color_hex(0xffab7c46));
};

lv_style_t *get_style_gold_panel_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_gold_panel_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_gold_panel(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_gold_panel_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_gold_panel(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_gold_panel_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: GoldDropdown^
//

void init_style_gold_dropdown__MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_26);
    lv_style_set_bg_color(style, lv_color_hex(0xfffdd111));
    lv_style_set_border_color(style, lv_color_hex(0xffab7c46));
};

lv_style_t *get_style_gold_dropdown__MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_gold_dropdown__MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_gold_dropdown__SELECTED_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_26);
    lv_style_set_bg_color(style, lv_color_hex(0xffab7c46));
    lv_style_set_border_color(style, lv_color_hex(0xfffdd111));
};

lv_style_t *get_style_gold_dropdown__SELECTED_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_gold_dropdown__SELECTED_DEFAULT(style);
    }
    return style;
};

void add_style_gold_dropdown_(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_gold_dropdown__MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_gold_dropdown__SELECTED_DEFAULT(), LV_PART_SELECTED | LV_STATE_DEFAULT);
};

void remove_style_gold_dropdown_(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_gold_dropdown__MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_gold_dropdown__SELECTED_DEFAULT(), LV_PART_SELECTED | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_gold,
        add_style_braun,
        add_style_gold_sel_braun,
        add_style_gold_text_area,
        add_style_gold_keyboard,
        add_style_gold_panel,
        add_style_gold_dropdown_,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_gold,
        remove_style_braun,
        remove_style_gold_sel_braun,
        remove_style_gold_text_area,
        remove_style_gold_keyboard,
        remove_style_gold_panel,
        remove_style_gold_dropdown_,
    };
    remove_style_funcs[styleIndex](obj);
}

