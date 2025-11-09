#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_idle_screen_idle_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 70, e);
    }
}

static void event_handler_cb_idle_screen_obj46(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_logo_screen_logo_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 70, e);
    }
}

static void event_handler_cb_menu_screen_menu_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_UNLOADED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 59, e);
    }
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 1, 1, e);
    }
}

static void event_handler_cb_menu_screen_start(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_menu_screen_optionen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 56, e);
    }
}

static void event_handler_cb_menu_screen_optionen_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 58, e);
    }
}

static void event_handler_cb_choose_player_screen_choose_player_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 49, e);
    }
}

static void event_handler_cb_choose_player_screen_player_roller(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_roller_get_selected(ta);
            assignIntegerProperty(flowState, 2, 3, value, "Failed to assign Selected in Roller widget");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 49, e);
    }
}

static void event_handler_cb_choose_player_screen_obj47(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_choose_player_screen_obj48(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_choose_player_screen_obj49(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_choose_game_screen_choose_game_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_LOAD_START) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 50, e);
    }
}

static void event_handler_cb_choose_game_screen_game_roller(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_roller_get_selected(ta);
            assignIntegerProperty(flowState, 2, 4, value, "Failed to assign Selected in Roller widget");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 50, e);
    }
}

static void event_handler_cb_choose_game_screen_obj50(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_choose_game_screen_obj51(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 52, e);
    }
}

static void event_handler_cb_choose_game_mod_obj52(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_choose_game_mod_obj53(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_keyboard_screen_obj54(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_numpad_screen_obj55(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_okay_screen_obj56(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_game_lichtloser_game_lichtloser(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_LOAD_START) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 75, e);
    }
}

static void event_handler_cb_game_lichtloser_score_player1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score_panel1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score_player2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score_panel2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score_player3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score_panel3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score_player4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score_panel4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score_player5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score_panel5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score_player6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score_panel6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_score6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_game_lichtloser_obj57(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 21, 0, e);
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_cmd_send_game_end(e);
    }
}

static void event_handler_cb_game_lichtloser_button_game(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 23, 0, e);
    }
}

static void event_handler_cb_game_win_obj58(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_game_lose_obj59(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_useroptionen1_button_10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_useroptionen1_obj60(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_useroptionen1_spiele_useroptionen1_spiele(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_LOAD_START) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 51, e);
    }
}

static void event_handler_cb_useroptionen1_spiele_obj61(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_useroptionen1_spiele_options_game_roller(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_roller_get_selected(ta);
            assignIntegerProperty(flowState, 3, 4, value, "Failed to assign Selected in Roller widget");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 51, e);
    }
}

static void event_handler_cb_useroptionen1_spiele_obj62(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 53, e);
    }
}

static void event_handler_cb_useroptionen1_spiele_lichtloser_obj63(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_button_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_button_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_button_6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_button_9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_obj64(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_adminoptionen1_spiele(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_LOAD_START) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 51, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_obj65(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_options_game_roller_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_roller_get_selected(ta);
            assignIntegerProperty(flowState, 3, 4, value, "Failed to assign Selected in Roller widget");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 51, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_obj66(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 54, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_obj67(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_slider_lichtloserrounds(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            assignIntegerProperty(flowState, 12, 3, value, "Failed to assign Value in Slider widget");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 72, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_button_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_button_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 17, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_joker_adminoptionen1_spiele_lichtloser_joker(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 60, e);
    }
    if (event == LV_EVENT_SCREEN_UNLOADED) {
        e->user_data = (void *)0;
        action_cmd_send_joker_stop_to_arduino(e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_joker_obj68(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_joker_obj69(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 6, 3, value, "Failed to assign Checked state");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_cmd_send_borders_state_to_arduino(e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_joker_obj70(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_joker_obj71(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            assignIntegerProperty(flowState, 11, 5, value, "Failed to assign Selected in Dropdown widget");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 60, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_timings_adminoptionen1_spiele_lichtloser_timings(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 60, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_timings_obj72(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_timings_slider_7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            assignIntegerProperty(flowState, 7, 4, value, "Failed to assign Value in Slider widget");
        }
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_left_value(ta);
            assignIntegerProperty(flowState, 7, 3, value, "Failed to assign Value left in Slider widget");
        }
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_timings_slider_8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            assignIntegerProperty(flowState, 14, 4, value, "Failed to assign Value in Slider widget");
        }
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_left_value(ta);
            assignIntegerProperty(flowState, 14, 3, value, "Failed to assign Value left in Slider widget");
        }
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_timings_slider_9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            assignIntegerProperty(flowState, 21, 4, value, "Failed to assign Value in Slider widget");
        }
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_left_value(ta);
            assignIntegerProperty(flowState, 21, 3, value, "Failed to assign Value left in Slider widget");
        }
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_timings_slider_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            assignIntegerProperty(flowState, 28, 3, value, "Failed to assign Value in Slider widget");
        }
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_button_24(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_button_25(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_button_26(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_obj73(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_winlose_obj74(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_adminoptionen1_farbeneffekte_spielerfarbe(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_LOAD_START) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 65, e);
    }
    if (event == LV_EVENT_SCREEN_UNLOADED) {
        e->user_data = (void *)0;
        action_cmd_send_preview_clear(e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_obj75(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_obj76(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            assignIntegerProperty(flowState, 7, 4, value, "Failed to assign Selected in Dropdown widget");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 61, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_obj77(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_obj78(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            assignIntegerProperty(flowState, 11, 5, value, "Failed to assign Selected in Dropdown widget");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 62, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_obj79(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_checkbox_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 14, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_obj80(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            assignIntegerProperty(flowState, 19, 4, value, "Failed to assign Selected in Dropdown widget");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 63, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_grenzfarbe_adminoptionen1_farbeneffekte_grenzfarbe(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_LOAD_START) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 64, e);
    }
    if (event == LV_EVENT_SCREEN_UNLOADED) {
        e->user_data = (void *)0;
        action_cmd_send_preview_clear(e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_grenzfarbe_obj81(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_grenzfarbe_obj82(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            assignIntegerProperty(flowState, 7, 4, value, "Failed to assign Selected in Dropdown widget");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 66, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_grenzfarbe_obj83(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_adminoptionen1_farbeneffekte_grenzfarbe_obj84(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            assignIntegerProperty(flowState, 11, 5, value, "Failed to assign Selected in Dropdown widget");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 67, e);
    }
}

static void event_handler_cb_adminoptionen1_system_button_12(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_button_13(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_button_16(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_button_14(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_button_15(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 16, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_obj85(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_obj86(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_leds_button_18(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_leds_obj87(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_leds_helligkeit_adminoptionen1_system_leds_helligkeit(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_UNLOADED) {
        e->user_data = (void *)0;
        action_cmd_send_preview_clear(e);
    }
}

static void event_handler_cb_adminoptionen1_system_leds_helligkeit_obj88(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_leds_helligkeit_slider_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            assignIntegerProperty(flowState, 7, 3, value, "Failed to assign Value in Slider widget");
        }
    }
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_cmd_send_led_game_brightness(e);
    }
}

static void event_handler_cb_adminoptionen1_system_leds_helligkeit_slider_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            assignIntegerProperty(flowState, 13, 3, value, "Failed to assign Value in Slider widget");
        }
    }
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_cmd_send_led_border_brightness(e);
    }
}

static void event_handler_cb_adminoptionen1_system_anzeige_obj89(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_anzeige_slider_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            assignIntegerProperty(flowState, 8, 3, value, "Failed to assign Value in Slider widget");
        }
    }
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_cmd_set_display_brightness(e);
    }
}

static void event_handler_cb_adminoptionen1_system_anzeige_button_29(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_anzeige_idle_adminoptionen1_system_anzeige_idle(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 68, e);
    }
}

static void event_handler_cb_adminoptionen1_system_anzeige_idle_obj90(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_anzeige_idle_obj91(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 6, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_adminoptionen1_system_anzeige_idle_obj92(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_adminoptionen1_system_anzeige_idle_obj93(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            assignIntegerProperty(flowState, 11, 5, value, "Failed to assign Selected in Dropdown widget");
        }
    }
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 68, e);
    }
}

static void event_handler_cb_adminoptionen1_system_anzeige_idle_obj94(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
}

static void event_handler_cb_adminoptionen1_system_anzeige_idle_checkbox_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 14, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_adminoptionen1_system_audio_obj95(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_obj96(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_button_19(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_button_22(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_button_23(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_wifi_obj97(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_kommunikation_obj98(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_update_obj99(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_update_button_44(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_update_button_31(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_update_manifest_obj100(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_update_firmware_obj101(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_debug_obj102(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_debug_obj103(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 25, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_debug2_obj104(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_debug2_button_46(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_debug2_tests_obj105(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_debug2_tests_button_49(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        action_cmd_led_ring_test(e);
    }
}

static void event_handler_cb_adminoptionen1_system2_button_40(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_button_39(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_obj106(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_profil_obj107(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_profil_button_43(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_profil_button_42(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_profil_profilladen_obj108(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_profil_profilladen_obj109(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_bonus_adminoptionen1_bonus(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 69, e);
    }
}

static void event_handler_cb_adminoptionen1_bonus_button_7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 69, e);
    }
}

static void event_handler_cb_adminoptionen1_bonus_obj110(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_optionen_template_obj111(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 21, 0, e);
    }
}

static void event_handler_cb_optionen_template_obj112(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 24, 0, e);
    }
}

static void event_handler_cb_optionen_template_obj113(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 27, 0, e);
    }
}

static void event_handler_cb_optionen_template_obj114(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 29, 0, e);
    }
}

static void event_handler_cb_optionen_template_2_obj115(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

void create_screen_idle_screen() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.idle_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_idle_screen_idle_screen, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 47);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_logo);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj46 = obj;
            lv_obj_set_pos(obj, 166, 366);
            lv_obj_set_size(obj, 151, 65);
            lv_obj_add_event_cb(obj, event_handler_cb_idle_screen_obj46, LV_EVENT_ALL, flowState);
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // startIdle
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.start_idle = obj;
                    lv_obj_set_pos(obj, -16, -8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
                    lv_obj_set_style_text_font(obj, &ui_font_point100, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "START");
                }
            }
        }
        {
            // version
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.version = obj;
            lv_obj_set_pos(obj, 3, 465);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "version: 0.1");
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_IDLE_SCREEN - 1);
    
    tick_screen_idle_screen();
}

void delete_screen_idle_screen() {
    lv_obj_del(objects.idle_screen);
    objects.idle_screen = 0;
    objects.obj0 = 0;
    objects.obj46 = 0;
    objects.start_idle = 0;
    objects.version = 0;
    deletePageFlowState(0);
}

void tick_screen_idle_screen() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 47);
}

void create_screen_logo_screen() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.logo_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_logo_screen_logo_screen, LV_EVENT_ALL, flowState);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 49);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 42);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_logo);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_LOGO_SCREEN - 1);
    
    tick_screen_logo_screen();
}

void delete_screen_logo_screen() {
    lv_obj_del(objects.logo_screen);
    objects.logo_screen = 0;
    objects.obj1 = 0;
    deletePageFlowState(1);
}

void tick_screen_logo_screen() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 49);
}

void create_screen_loading_screen() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.loading_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 51);
        }
        {
            // logo
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.logo = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_logo);
            lv_img_set_zoom(obj, 255);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj116 = obj;
            lv_obj_set_pos(obj, 153, 366);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "LADEN...");
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_LOADING_SCREEN - 1);
    
    tick_screen_loading_screen();
}

void delete_screen_loading_screen() {
    lv_obj_del(objects.loading_screen);
    objects.loading_screen = 0;
    objects.obj2 = 0;
    objects.logo = 0;
    objects.obj116 = 0;
    deletePageFlowState(2);
}

void tick_screen_loading_screen() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 51);
}

void create_screen_menu_screen() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.menu_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_menu_screen_menu_screen, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 53);
        }
        {
            // newsContainer
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.news_container = obj;
            lv_obj_set_pos(obj, 0, 20);
            lv_obj_set_size(obj, 480, 40);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // newsPanel
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.news_panel = obj;
                    lv_obj_set_pos(obj, -5, 0);
                    lv_obj_set_size(obj, 490, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // news
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.news = obj;
                    lv_obj_set_pos(obj, 0, 8);
                    lv_obj_set_size(obj, 480, 30);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "NEWS: hier kann Gerd reinschreiben was er will. Fuer ein Einmal-FreiBIER-Code: \"GIBSmir\" an der Kasse! ");
                }
            }
        }
        {
            // Start
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.start = obj;
            lv_obj_set_pos(obj, 100, 150);
            lv_obj_set_size(obj, 280, 121);
            lv_obj_add_event_cb(obj, event_handler_cb_menu_screen_start, LV_EVENT_ALL, flowState);
            add_style_gold(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj117 = obj;
                    lv_obj_set_pos(obj, 1, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 95);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_point160, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff981313), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff01184a), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "START");
                }
            }
        }
        {
            // Optionen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.optionen = obj;
            lv_obj_set_pos(obj, 134, 310);
            lv_obj_set_size(obj, 212, 63);
            lv_obj_add_event_cb(obj, event_handler_cb_menu_screen_optionen, LV_EVENT_ALL, flowState);
            add_style_braun(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj118 = obj;
                    lv_obj_set_pos(obj, 0, 10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 66);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_point70, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff981313), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff01184a), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OPTIONEN");
                }
            }
        }
        {
            // Optionen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.optionen_1 = obj;
            lv_obj_set_pos(obj, 23, 310);
            lv_obj_set_size(obj, 50, 63);
            lv_obj_add_event_cb(obj, event_handler_cb_menu_screen_optionen_1, LV_EVENT_ALL, flowState);
            add_style_braun(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj119 = obj;
                    lv_obj_set_pos(obj, 0, 10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 66);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_point70, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff981313), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff01184a), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "A");
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_MENU_SCREEN - 1);
    
    tick_screen_menu_screen();
}

void delete_screen_menu_screen() {
    lv_obj_del(objects.menu_screen);
    objects.menu_screen = 0;
    objects.obj3 = 0;
    objects.news_container = 0;
    objects.news_panel = 0;
    objects.news = 0;
    objects.start = 0;
    objects.obj117 = 0;
    objects.optionen = 0;
    objects.obj118 = 0;
    objects.optionen_1 = 0;
    objects.obj119 = 0;
    deletePageFlowState(3);
}

void tick_screen_menu_screen() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 53);
}

void create_screen_choose_player_screen() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.choose_player_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_choose_player_screen_choose_player_screen, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 55);
        }
        {
            // playerRoller
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.player_roller = obj;
            lv_obj_set_pos(obj, 122, 117);
            lv_obj_set_size(obj, 236, 246);
            lv_roller_set_options(obj, "2-Spieler\n3-Spieler\n4-Spieler\n5-Spieler\n6-Spieler", LV_ROLLER_MODE_INFINITE);
            lv_obj_add_event_cb(obj, event_handler_cb_choose_player_screen_player_roller, LV_EVENT_ALL, flowState);
            add_style_gold_sel_braun(obj);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj47 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_choose_player_screen_obj47, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj48 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_choose_player_screen_obj48, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "AUSWAEHLEN");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj49 = obj;
            lv_obj_set_pos(obj, 135, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_add_event_cb(obj, event_handler_cb_choose_player_screen_obj49, LV_EVENT_ALL, flowState);
            lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
            lv_label_set_text(obj, "");
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_CHOOSE_PLAYER_SCREEN - 1);
    
    tick_screen_choose_player_screen();
}

void delete_screen_choose_player_screen() {
    lv_obj_del(objects.choose_player_screen);
    objects.choose_player_screen = 0;
    objects.obj4 = 0;
    objects.player_roller = 0;
    objects.obj47 = 0;
    objects.obj48 = 0;
    objects.obj49 = 0;
    deletePageFlowState(4);
}

void tick_screen_choose_player_screen() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 55);
    {
        if (!(lv_obj_get_state(objects.player_roller) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 2, 3, "Failed to evaluate Selected in Roller widget");
            int32_t cur_val = lv_roller_get_selected(objects.player_roller);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.player_roller;
                lv_roller_set_selected(objects.player_roller, new_val, LV_ANIM_OFF);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 6, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj49, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj49;
            if (new_val) lv_obj_add_state(objects.obj49, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj49, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 6, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj49);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj49;
            lv_label_set_text(objects.obj49, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_choose_game_screen() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.choose_game_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_choose_game_screen_choose_game_screen, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 57);
        }
        {
            // gameRoller
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.game_roller = obj;
            lv_obj_set_pos(obj, 122, 117);
            lv_obj_set_size(obj, 236, 246);
            lv_roller_set_options(obj, "", LV_ROLLER_MODE_INFINITE);
            lv_obj_add_event_cb(obj, event_handler_cb_choose_game_screen_game_roller, LV_EVENT_ALL, flowState);
            add_style_gold_sel_braun(obj);
            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj50 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_choose_game_screen_obj50, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj51 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_choose_game_screen_obj51, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "AUSWAEHLEN");
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_CHOOSE_GAME_SCREEN - 1);
    
    tick_screen_choose_game_screen();
}

void delete_screen_choose_game_screen() {
    lv_obj_del(objects.choose_game_screen);
    objects.choose_game_screen = 0;
    objects.obj5 = 0;
    objects.game_roller = 0;
    objects.obj50 = 0;
    objects.obj51 = 0;
    deletePageFlowState(5);
}

void tick_screen_choose_game_screen() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 57);
    {
        const char *new_val = evalStringArrayPropertyAndJoin(flowState, 2, 3, "Failed to evaluate Options in Roller widget", "\n");
        const char *cur_val = lv_roller_get_options(objects.game_roller);
        if (compareRollerOptions((lv_roller_t *)objects.game_roller, new_val, cur_val, LV_ROLLER_MODE_INFINITE) != 0) {
            tick_value_change_obj = objects.game_roller;
            lv_roller_set_options(objects.game_roller, new_val, LV_ROLLER_MODE_INFINITE);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.game_roller) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 2, 4, "Failed to evaluate Selected in Roller widget");
            int32_t cur_val = lv_roller_get_selected(objects.game_roller);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.game_roller;
                lv_roller_set_selected(objects.game_roller, new_val, LV_ANIM_OFF);
                tick_value_change_obj = NULL;
            }
        }
    }
}

void create_screen_choose_game_mod() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.choose_game_mod = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 59);
        }
        {
            // gameRoller_5
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.game_roller_5 = obj;
            lv_obj_set_pos(obj, 122, 117);
            lv_obj_set_size(obj, 236, 246);
            lv_roller_set_options(obj, "STANDARD", LV_ROLLER_MODE_INFINITE);
            add_style_gold_sel_braun(obj);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj52 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_choose_game_mod_obj52, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj53 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_choose_game_mod_obj53, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "AUSWAEHLEN");
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_CHOOSE_GAME_MOD - 1);
    
    tick_screen_choose_game_mod();
}

void delete_screen_choose_game_mod() {
    lv_obj_del(objects.choose_game_mod);
    objects.choose_game_mod = 0;
    objects.obj6 = 0;
    objects.game_roller_5 = 0;
    objects.obj52 = 0;
    objects.obj53 = 0;
    deletePageFlowState(6);
}

void tick_screen_choose_game_mod() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 59);
}

void create_screen_keyboard_screen() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.keyboard_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 61);
        }
        {
            // keyboardArea
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.keyboard_area = obj;
            lv_obj_set_pos(obj, 5, 85);
            lv_obj_set_size(obj, 470, 130);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_WITH_ARROW);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff959595), LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
        }
        {
            // keyboard
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.keyboard = obj;
            lv_obj_set_pos(obj, 5, 225);
            lv_obj_set_size(obj, 470, 250);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdd111), LV_PART_ITEMS | LV_STATE_DEFAULT);
        }
        {
            // keyboardTitle
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.keyboard_title = obj;
            lv_obj_set_pos(obj, 137, 11);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_point70, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "keyboardTitle");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj54 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_keyboard_screen_obj54, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    lv_keyboard_set_textarea(objects.keyboard, objects.keyboard_area);
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_KEYBOARD_SCREEN - 1);
    
    tick_screen_keyboard_screen();
}

void delete_screen_keyboard_screen() {
    lv_obj_del(objects.keyboard_screen);
    objects.keyboard_screen = 0;
    objects.obj7 = 0;
    objects.keyboard_area = 0;
    objects.keyboard = 0;
    objects.keyboard_title = 0;
    objects.obj54 = 0;
    deletePageFlowState(7);
}

void tick_screen_keyboard_screen() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 61);
}

void create_screen_numpad_screen() {
    void *flowState = getFlowState(0, 8);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.numpad_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 63);
        }
        {
            // numpadArea
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.numpad_area = obj;
            lv_obj_set_pos(obj, 5, 85);
            lv_obj_set_size(obj, 470, 130);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_WITH_ARROW);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff959595), LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
        }
        {
            // numpad
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.numpad = obj;
            lv_obj_set_pos(obj, 0, -5);
            lv_obj_set_size(obj, 470, 250);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            add_style_gold_keyboard(obj);
        }
        {
            // numpadTitle
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.numpad_title = obj;
            lv_obj_set_pos(obj, 137, 11);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_point70, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "numpadTitle");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj55 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_numpad_screen_obj55, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    lv_keyboard_set_textarea(objects.numpad, objects.numpad_area);
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_NUMPAD_SCREEN - 1);
    
    tick_screen_numpad_screen();
}

void delete_screen_numpad_screen() {
    lv_obj_del(objects.numpad_screen);
    objects.numpad_screen = 0;
    objects.obj8 = 0;
    objects.numpad_area = 0;
    objects.numpad = 0;
    objects.numpad_title = 0;
    objects.obj55 = 0;
    deletePageFlowState(8);
}

void tick_screen_numpad_screen() {
    void *flowState = getFlowState(0, 8);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 63);
}

void create_screen_okay_screen() {
    void *flowState = getFlowState(0, 9);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.okay_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 65);
        }
        {
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            lv_obj_set_pos(obj, 5, 120);
            lv_obj_set_size(obj, 470, 59);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_text(obj, "Willst du das wirklich tun?");
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_WITH_ARROW);
            add_style_gold_text_area(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // jaPanel
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ja_panel = obj;
            lv_obj_set_pos(obj, 25, 289);
            lv_obj_set_size(obj, 164, 132);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff13c90d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 27, 22);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OK");
                }
            }
        }
        {
            // neinPanel
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.nein_panel = obj;
            lv_obj_set_pos(obj, 290, 289);
            lv_obj_set_size(obj, 164, 132);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc90d0d), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -10, 36);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "ABBRECHEN");
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj56 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_okay_screen_obj56, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_OKAY_SCREEN - 1);
    
    tick_screen_okay_screen();
}

void delete_screen_okay_screen() {
    lv_obj_del(objects.okay_screen);
    objects.okay_screen = 0;
    objects.obj9 = 0;
    objects.ja_panel = 0;
    objects.nein_panel = 0;
    objects.obj56 = 0;
    deletePageFlowState(9);
}

void tick_screen_okay_screen() {
    void *flowState = getFlowState(0, 9);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 65);
}

void create_screen_game_lichtloser() {
    void *flowState = getFlowState(0, 10);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.game_lichtloser = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_game_lichtloser, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 67);
        }
        {
            // scores
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.scores = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // scorePlayer1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.score_player1 = obj;
                    lv_obj_set_pos(obj, 230, 456);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score_player1, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    lv_label_set_text(obj, "");
                }
                {
                    // scorePanel1
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.score_panel1 = obj;
                    lv_obj_set_pos(obj, 210, 418);
                    lv_obj_set_size(obj, 60, 38);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score_panel1, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // score1
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.score1 = obj;
                            lv_obj_set_pos(obj, -16, -11);
                            lv_obj_set_size(obj, 56, 35);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score1, LV_EVENT_ALL, flowState);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                            lv_label_set_text(obj, "");
                        }
                    }
                }
                {
                    // scorePlayer2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.score_player2 = obj;
                    lv_obj_set_pos(obj, 349, 308);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score_player2, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    lv_label_set_text(obj, "");
                }
                {
                    // scorePanel2
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.score_panel2 = obj;
                    lv_obj_set_pos(obj, 331, 270);
                    lv_obj_set_size(obj, 60, 38);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score_panel2, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // score2
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.score2 = obj;
                            lv_obj_set_pos(obj, -16, -11);
                            lv_obj_set_size(obj, 56, 35);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score2, LV_EVENT_ALL, flowState);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                            lv_label_set_text(obj, "");
                        }
                    }
                }
                {
                    // scorePlayer3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.score_player3 = obj;
                    lv_obj_set_pos(obj, 350, 212);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score_player3, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    lv_label_set_text(obj, "");
                }
                {
                    // scorePanel3
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.score_panel3 = obj;
                    lv_obj_set_pos(obj, 331, 174);
                    lv_obj_set_size(obj, 60, 38);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score_panel3, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // score3
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.score3 = obj;
                            lv_obj_set_pos(obj, -16, -11);
                            lv_obj_set_size(obj, 56, 35);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score3, LV_EVENT_ALL, flowState);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                            lv_label_set_text(obj, "");
                        }
                    }
                }
                {
                    // scorePlayer4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.score_player4 = obj;
                    lv_obj_set_pos(obj, 228, 56);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score_player4, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    lv_label_set_text(obj, "");
                }
                {
                    // scorePanel4
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.score_panel4 = obj;
                    lv_obj_set_pos(obj, 210, 18);
                    lv_obj_set_size(obj, 60, 38);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score_panel4, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // score4
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.score4 = obj;
                            lv_obj_set_pos(obj, -16, -11);
                            lv_obj_set_size(obj, 56, 35);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score4, LV_EVENT_ALL, flowState);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                            lv_label_set_text(obj, "");
                        }
                    }
                }
                {
                    // scorePlayer5
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.score_player5 = obj;
                    lv_obj_set_pos(obj, 110, 212);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score_player5, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    lv_label_set_text(obj, "");
                }
                {
                    // scorePanel5
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.score_panel5 = obj;
                    lv_obj_set_pos(obj, 92, 174);
                    lv_obj_set_size(obj, 60, 38);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score_panel5, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // score5
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.score5 = obj;
                            lv_obj_set_pos(obj, -16, -11);
                            lv_obj_set_size(obj, 56, 35);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score5, LV_EVENT_ALL, flowState);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                            lv_label_set_text(obj, "");
                        }
                    }
                }
                {
                    // scorePlayer6
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.score_player6 = obj;
                    lv_obj_set_pos(obj, 110, 308);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score_player6, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    lv_label_set_text(obj, "");
                }
                {
                    // scorePanel6
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.score_panel6 = obj;
                    lv_obj_set_pos(obj, 92, 270);
                    lv_obj_set_size(obj, 60, 38);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score_panel6, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // score6
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.score6 = obj;
                            lv_obj_set_pos(obj, -16, -11);
                            lv_obj_set_size(obj, 56, 35);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_score6, LV_EVENT_ALL, flowState);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
                            lv_label_set_text(obj, "");
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj57 = obj;
            lv_obj_set_pos(obj, -1, 0);
            lv_obj_set_size(obj, 47, 47);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 200);
            lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_obj57, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // buttonContainer_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_2 = obj;
            lv_obj_set_pos(obj, 190, 190);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_game
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_game = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 100, 100);
                    lv_obj_add_event_cb(obj, event_handler_cb_game_lichtloser_button_game, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_2
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_2 = obj;
                            lv_obj_set_pos(obj, -15, 20);
                            lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "CLICK");
                        }
                    }
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_GAME_LICHTLOSER - 1);
    
    tick_screen_game_lichtloser();
}

void delete_screen_game_lichtloser() {
    lv_obj_del(objects.game_lichtloser);
    objects.game_lichtloser = 0;
    objects.obj10 = 0;
    objects.scores = 0;
    objects.score_player1 = 0;
    objects.score_panel1 = 0;
    objects.score1 = 0;
    objects.score_player2 = 0;
    objects.score_panel2 = 0;
    objects.score2 = 0;
    objects.score_player3 = 0;
    objects.score_panel3 = 0;
    objects.score3 = 0;
    objects.score_player4 = 0;
    objects.score_panel4 = 0;
    objects.score4 = 0;
    objects.score_player5 = 0;
    objects.score_panel5 = 0;
    objects.score5 = 0;
    objects.score_player6 = 0;
    objects.score_panel6 = 0;
    objects.score6 = 0;
    objects.obj57 = 0;
    objects.button_container_2 = 0;
    objects.button_game = 0;
    objects.button_title_2 = 0;
    deletePageFlowState(10);
}

void tick_screen_game_lichtloser() {
    void *flowState = getFlowState(0, 10);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 67);
    {
        bool new_val = evalBooleanProperty(flowState, 3, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score_player1, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score_player1;
            if (new_val) lv_obj_add_state(objects.score_player1, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score_player1, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 3, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.score_player1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.score_player1;
            lv_label_set_text(objects.score_player1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 4, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score_panel1, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score_panel1;
            if (new_val) lv_obj_add_state(objects.score_panel1, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score_panel1, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 5, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score1, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score1;
            if (new_val) lv_obj_add_state(objects.score1, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score1, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 5, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.score1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.score1;
            lv_label_set_text(objects.score1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 6, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score_player2, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score_player2;
            if (new_val) lv_obj_add_state(objects.score_player2, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score_player2, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 6, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.score_player2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.score_player2;
            lv_label_set_text(objects.score_player2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 7, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score_panel2, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score_panel2;
            if (new_val) lv_obj_add_state(objects.score_panel2, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score_panel2, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 8, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score2, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score2;
            if (new_val) lv_obj_add_state(objects.score2, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score2, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.score2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.score2;
            lv_label_set_text(objects.score2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 9, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score_player3, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score_player3;
            if (new_val) lv_obj_add_state(objects.score_player3, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score_player3, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 9, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.score_player3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.score_player3;
            lv_label_set_text(objects.score_player3, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 10, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score_panel3, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score_panel3;
            if (new_val) lv_obj_add_state(objects.score_panel3, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score_panel3, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 11, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score3, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score3;
            if (new_val) lv_obj_add_state(objects.score3, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score3, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 11, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.score3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.score3;
            lv_label_set_text(objects.score3, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 12, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score_player4, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score_player4;
            if (new_val) lv_obj_add_state(objects.score_player4, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score_player4, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.score_player4);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.score_player4;
            lv_label_set_text(objects.score_player4, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 13, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score_panel4, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score_panel4;
            if (new_val) lv_obj_add_state(objects.score_panel4, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score_panel4, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 14, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score4, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score4;
            if (new_val) lv_obj_add_state(objects.score4, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score4, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 14, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.score4);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.score4;
            lv_label_set_text(objects.score4, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 15, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score_player5, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score_player5;
            if (new_val) lv_obj_add_state(objects.score_player5, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score_player5, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 15, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.score_player5);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.score_player5;
            lv_label_set_text(objects.score_player5, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 16, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score_panel5, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score_panel5;
            if (new_val) lv_obj_add_state(objects.score_panel5, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score_panel5, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 17, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score5, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score5;
            if (new_val) lv_obj_add_state(objects.score5, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score5, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 17, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.score5);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.score5;
            lv_label_set_text(objects.score5, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 18, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score_player6, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score_player6;
            if (new_val) lv_obj_add_state(objects.score_player6, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score_player6, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 18, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.score_player6);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.score_player6;
            lv_label_set_text(objects.score_player6, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 19, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score_panel6, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score_panel6;
            if (new_val) lv_obj_add_state(objects.score_panel6, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score_panel6, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 20, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.score6, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.score6;
            if (new_val) lv_obj_add_state(objects.score6, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.score6, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 20, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.score6);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.score6;
            lv_label_set_text(objects.score6, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_game_win() {
    void *flowState = getFlowState(0, 11);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.game_win = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc90d0d), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj11 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 69);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 5, 5);
            lv_obj_set_size(obj, 70, 70);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
        }
        {
            // winLoseContainer
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.win_lose_container = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // winContainer
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.win_container = obj;
                    lv_obj_set_pos(obj, 32, 123);
                    lv_obj_set_size(obj, 413, 218);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // winPanel
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.win_panel = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 413, 127);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff13c90d), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, -7, 23);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                    lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "DU HAST GEWONNEN!");
                                }
                            }
                        }
                        {
                            // loseAnzeigePanel
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.lose_anzeige_panel = obj;
                            lv_obj_set_pos(obj, 47, 135);
                            lv_obj_set_size(obj, 320, 66);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc90d0d), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // loseAnzeigeTitle
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lose_anzeige_title = obj;
                                    lv_obj_set_pos(obj, 7, -7);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "");
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj58 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_game_win_obj58, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_GAME_WIN - 1);
    
    tick_screen_game_win();
}

void delete_screen_game_win() {
    lv_obj_del(objects.game_win);
    objects.game_win = 0;
    objects.obj11 = 0;
    objects.win_lose_container = 0;
    objects.win_container = 0;
    objects.win_panel = 0;
    objects.lose_anzeige_panel = 0;
    objects.lose_anzeige_title = 0;
    objects.obj58 = 0;
    deletePageFlowState(11);
}

void tick_screen_game_win() {
    void *flowState = getFlowState(0, 11);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 69);
    {
        const char *new_val = evalTextProperty(flowState, 8, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.lose_anzeige_title);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.lose_anzeige_title;
            lv_label_set_text(objects.lose_anzeige_title, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_game_lose() {
    void *flowState = getFlowState(0, 12);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.game_lose = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc90d0d), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj12 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 71);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 5, 5);
            lv_obj_set_size(obj, 70, 70);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
        }
        {
            // winLoseContainer_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.win_lose_container_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // winContainer_1
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.win_container_1 = obj;
                    lv_obj_set_pos(obj, 32, 123);
                    lv_obj_set_size(obj, 413, 218);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // losePanel
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.lose_panel = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 413, 127);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc90d0d), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 3, 23);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                    lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "DU HAST VERLOREN!");
                                }
                            }
                        }
                        {
                            // winAnzeigePanel
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.win_anzeige_panel = obj;
                            lv_obj_set_pos(obj, 47, 135);
                            lv_obj_set_size(obj, 320, 66);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff13c90d), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // loseAnzeigeTitle_1
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lose_anzeige_title_1 = obj;
                                    lv_obj_set_pos(obj, -5, -7);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "");
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj59 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_game_lose_obj59, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_GAME_LOSE - 1);
    
    tick_screen_game_lose();
}

void delete_screen_game_lose() {
    lv_obj_del(objects.game_lose);
    objects.game_lose = 0;
    objects.obj12 = 0;
    objects.win_lose_container_1 = 0;
    objects.win_container_1 = 0;
    objects.lose_panel = 0;
    objects.win_anzeige_panel = 0;
    objects.lose_anzeige_title_1 = 0;
    objects.obj59 = 0;
    deletePageFlowState(12);
}

void tick_screen_game_lose() {
    void *flowState = getFlowState(0, 12);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 71);
    {
        const char *new_val = evalTextProperty(flowState, 8, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.lose_anzeige_title_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.lose_anzeige_title_1;
            lv_label_set_text(objects.lose_anzeige_title_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_useroptionen1() {
    void *flowState = getFlowState(0, 13);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.useroptionen1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj13 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 73);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj120 = obj;
            lv_obj_set_pos(obj, 92, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "OPTIONEN");
        }
        {
            // buttonContainer_10
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_10 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_10
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_10 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_useroptionen1_button_10, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_10
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_10 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "SPIELE");
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj60 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_useroptionen1_obj60, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_USEROPTIONEN1 - 1);
    
    tick_screen_useroptionen1();
}

void delete_screen_useroptionen1() {
    lv_obj_del(objects.useroptionen1);
    objects.useroptionen1 = 0;
    objects.obj13 = 0;
    objects.obj120 = 0;
    objects.button_container_10 = 0;
    objects.button_10 = 0;
    objects.button_title_10 = 0;
    objects.obj60 = 0;
    deletePageFlowState(13);
}

void tick_screen_useroptionen1() {
    void *flowState = getFlowState(0, 13);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 73);
}

void create_screen_useroptionen1_spiele() {
    void *flowState = getFlowState(0, 14);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.useroptionen1_spiele = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_useroptionen1_spiele_useroptionen1_spiele, LV_EVENT_ALL, flowState);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj14 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 75);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj61 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_useroptionen1_spiele_obj61, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // optionsGameRoller
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.options_game_roller = obj;
            lv_obj_set_pos(obj, 122, 117);
            lv_obj_set_size(obj, 236, 246);
            lv_roller_set_options(obj, "", LV_ROLLER_MODE_INFINITE);
            lv_obj_add_event_cb(obj, event_handler_cb_useroptionen1_spiele_options_game_roller, LV_EVENT_ALL, flowState);
            add_style_gold_sel_braun(obj);
            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj62 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_useroptionen1_spiele_obj62, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "AUSWAEHLEN");
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_USEROPTIONEN1_SPIELE - 1);
    
    tick_screen_useroptionen1_spiele();
}

void delete_screen_useroptionen1_spiele() {
    lv_obj_del(objects.useroptionen1_spiele);
    objects.useroptionen1_spiele = 0;
    objects.obj14 = 0;
    objects.obj61 = 0;
    objects.options_game_roller = 0;
    objects.obj62 = 0;
    deletePageFlowState(14);
}

void tick_screen_useroptionen1_spiele() {
    void *flowState = getFlowState(0, 14);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 75);
    {
        const char *new_val = evalStringArrayPropertyAndJoin(flowState, 3, 3, "Failed to evaluate Options in Roller widget", "\n");
        const char *cur_val = lv_roller_get_options(objects.options_game_roller);
        if (compareRollerOptions((lv_roller_t *)objects.options_game_roller, new_val, cur_val, LV_ROLLER_MODE_INFINITE) != 0) {
            tick_value_change_obj = objects.options_game_roller;
            lv_roller_set_options(objects.options_game_roller, new_val, LV_ROLLER_MODE_INFINITE);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.options_game_roller) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 3, 4, "Failed to evaluate Selected in Roller widget");
            int32_t cur_val = lv_roller_get_selected(objects.options_game_roller);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.options_game_roller;
                lv_roller_set_selected(objects.options_game_roller, new_val, LV_ANIM_OFF);
                tick_value_change_obj = NULL;
            }
        }
    }
}

void create_screen_useroptionen1_spiele_lichtloser() {
    void *flowState = getFlowState(0, 15);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.useroptionen1_spiele_lichtloser = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj15 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 77);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj63 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_useroptionen1_spiele_lichtloser_obj63, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj121 = obj;
            lv_obj_set_pos(obj, 90, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "LichtLoser");
        }
        {
            // dropdownContainer_22
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_22 = obj;
            lv_obj_set_pos(obj, 35, 88);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_22
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_22 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "SPIELGESCHW.");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "LANGSAM\nNORMAL\nSCHNELL");
                    lv_dropdown_set_selected(obj, 1);
                    add_style_gold_dropdown_(obj);
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_USEROPTIONEN1_SPIELE_LICHTLOSER - 1);
    
    tick_screen_useroptionen1_spiele_lichtloser();
}

void delete_screen_useroptionen1_spiele_lichtloser() {
    lv_obj_del(objects.useroptionen1_spiele_lichtloser);
    objects.useroptionen1_spiele_lichtloser = 0;
    objects.obj15 = 0;
    objects.obj63 = 0;
    objects.obj121 = 0;
    objects.dropdown_container_22 = 0;
    objects.roller_title_22 = 0;
    deletePageFlowState(15);
}

void tick_screen_useroptionen1_spiele_lichtloser() {
    void *flowState = getFlowState(0, 15);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 77);
}

void create_screen_adminoptionen1() {
    void *flowState = getFlowState(0, 16);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj16 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 79);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj122 = obj;
            lv_obj_set_pos(obj, 92, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "OPTIONEN");
        }
        {
            // buttonContainer_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_3 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_3
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_3 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_button_3, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_3
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_3 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "SPIELE");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_5
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_5 = obj;
            lv_obj_set_pos(obj, 35, 147);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_5
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_5 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_button_5, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_5
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_5 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "FARBEN/EFFEKTE");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_6
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_6 = obj;
            lv_obj_set_pos(obj, 35, 207);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_6
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_6 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_button_6, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_6
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_6 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "SYSTEM");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_9
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_9 = obj;
            lv_obj_set_pos(obj, 35, 420);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_9
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_9 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_button_9, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_9
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_9 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "BONUS");
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj64 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_obj64, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1 - 1);
    
    tick_screen_adminoptionen1();
}

void delete_screen_adminoptionen1() {
    lv_obj_del(objects.adminoptionen1);
    objects.adminoptionen1 = 0;
    objects.obj16 = 0;
    objects.obj122 = 0;
    objects.button_container_3 = 0;
    objects.button_3 = 0;
    objects.button_title_3 = 0;
    objects.button_container_5 = 0;
    objects.button_5 = 0;
    objects.button_title_5 = 0;
    objects.button_container_6 = 0;
    objects.button_6 = 0;
    objects.button_title_6 = 0;
    objects.button_container_9 = 0;
    objects.button_9 = 0;
    objects.button_title_9 = 0;
    objects.obj64 = 0;
    deletePageFlowState(16);
}

void tick_screen_adminoptionen1() {
    void *flowState = getFlowState(0, 16);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 79);
}

void create_screen_adminoptionen1_spiele() {
    void *flowState = getFlowState(0, 17);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_spiele = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_adminoptionen1_spiele, LV_EVENT_ALL, flowState);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj17 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 81);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj65 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_obj65, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // optionsGameRoller_1
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.options_game_roller_1 = obj;
            lv_obj_set_pos(obj, 122, 117);
            lv_obj_set_size(obj, 236, 246);
            lv_roller_set_options(obj, "", LV_ROLLER_MODE_INFINITE);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_options_game_roller_1, LV_EVENT_ALL, flowState);
            add_style_gold_sel_braun(obj);
            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj66 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_obj66, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "AUSWAEHLEN");
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SPIELE - 1);
    
    tick_screen_adminoptionen1_spiele();
}

void delete_screen_adminoptionen1_spiele() {
    lv_obj_del(objects.adminoptionen1_spiele);
    objects.adminoptionen1_spiele = 0;
    objects.obj17 = 0;
    objects.obj65 = 0;
    objects.options_game_roller_1 = 0;
    objects.obj66 = 0;
    deletePageFlowState(17);
}

void tick_screen_adminoptionen1_spiele() {
    void *flowState = getFlowState(0, 17);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 81);
    {
        const char *new_val = evalStringArrayPropertyAndJoin(flowState, 3, 3, "Failed to evaluate Options in Roller widget", "\n");
        const char *cur_val = lv_roller_get_options(objects.options_game_roller_1);
        if (compareRollerOptions((lv_roller_t *)objects.options_game_roller_1, new_val, cur_val, LV_ROLLER_MODE_INFINITE) != 0) {
            tick_value_change_obj = objects.options_game_roller_1;
            lv_roller_set_options(objects.options_game_roller_1, new_val, LV_ROLLER_MODE_INFINITE);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.options_game_roller_1) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 3, 4, "Failed to evaluate Selected in Roller widget");
            int32_t cur_val = lv_roller_get_selected(objects.options_game_roller_1);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.options_game_roller_1;
                lv_roller_set_selected(objects.options_game_roller_1, new_val, LV_ANIM_OFF);
                tick_value_change_obj = NULL;
            }
        }
    }
}

void create_screen_adminoptionen1_spiele_lichtloser() {
    void *flowState = getFlowState(0, 18);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_spiele_lichtloser = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj18 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 83);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj67 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_obj67, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj123 = obj;
            lv_obj_set_pos(obj, 90, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "LichtLoser");
        }
        {
            // dropdownContainer_19
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_19 = obj;
            lv_obj_set_pos(obj, 35, 88);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_19
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_19 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "SPIELGESCHW.");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "LANGSAM\nNORMAL\nSCHNELL");
                    lv_dropdown_set_selected(obj, 1);
                    add_style_gold_dropdown_(obj);
                }
            }
        }
        {
            // sliderContainer_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.slider_container_1 = obj;
            lv_obj_set_pos(obj, 35, 179);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 80);
                    add_style_gold_panel(obj);
                }
                {
                    // sliderTitle_7
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_7 = obj;
                    lv_obj_set_pos(obj, 5, 12);
                    lv_obj_set_size(obj, 396, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "RUNDEN");
                }
                {
                    // sliderTitle_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_1 = obj;
                    lv_obj_set_pos(obj, 280, 12);
                    lv_obj_set_size(obj, 50, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // slider_lichtloserrounds
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_lichtloserrounds = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_range(obj, 1, 10);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_slider_lichtloserrounds, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // buttonContainer_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_1 = obj;
            lv_obj_set_pos(obj, 35, 269);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_1
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_1 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_button_1, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_1
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_1 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "JOKER");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_4
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_4 = obj;
            lv_obj_set_pos(obj, 35, 329);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_4
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_4 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_button_4, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_4
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_4 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "TIMINGS");
                        }
                    }
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SPIELE_LICHTLOSER - 1);
    
    tick_screen_adminoptionen1_spiele_lichtloser();
}

void delete_screen_adminoptionen1_spiele_lichtloser() {
    lv_obj_del(objects.adminoptionen1_spiele_lichtloser);
    objects.adminoptionen1_spiele_lichtloser = 0;
    objects.obj18 = 0;
    objects.obj67 = 0;
    objects.obj123 = 0;
    objects.dropdown_container_19 = 0;
    objects.roller_title_19 = 0;
    objects.slider_container_1 = 0;
    objects.slider_title_7 = 0;
    objects.slider_title_1 = 0;
    objects.slider_lichtloserrounds = 0;
    objects.button_container_1 = 0;
    objects.button_1 = 0;
    objects.button_title_1 = 0;
    objects.button_container_4 = 0;
    objects.button_4 = 0;
    objects.button_title_4 = 0;
    deletePageFlowState(18);
}

void tick_screen_adminoptionen1_spiele_lichtloser() {
    void *flowState = getFlowState(0, 18);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 83);
    {
        const char *new_val = evalTextProperty(flowState, 11, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.slider_title_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.slider_title_1;
            lv_label_set_text(objects.slider_title_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 12, 3, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.slider_lichtloserrounds);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_lichtloserrounds;
            lv_slider_set_value(objects.slider_lichtloserrounds, new_val, LV_ANIM_ON);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_adminoptionen1_spiele_lichtloser_joker() {
    void *flowState = getFlowState(0, 19);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_spiele_lichtloser_joker = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_joker_adminoptionen1_spiele_lichtloser_joker, LV_EVENT_ALL, flowState);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj19 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 85);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj68 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_joker_obj68, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj124 = obj;
            lv_obj_set_pos(obj, 150, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "JOKER");
        }
        {
            // switchContainer_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.switch_container_1 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 50);
                    add_style_gold_panel(obj);
                }
                {
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.obj69 = obj;
                    lv_obj_set_pos(obj, 17, 13);
                    lv_obj_set_size(obj, 73, 34);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_joker_obj69, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
                }
                {
                    // switchTitle_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.switch_title_1 = obj;
                    lv_obj_set_pos(obj, 86, 11);
                    lv_obj_set_size(obj, 319, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "JOKER");
                }
            }
        }
        {
            // dropdownContainer_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_3 = obj;
            lv_obj_set_pos(obj, 35, 147);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj70 = obj;
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_joker_obj70, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff747474), LV_PART_MAIN | LV_STATE_DISABLED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_3
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_3 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "FARBE");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    objects.obj71 = obj;
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "");
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_joker_obj71, LV_EVENT_ALL, flowState);
                    add_style_gold_dropdown_(obj);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff747474), LV_PART_MAIN | LV_STATE_DISABLED);
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SPIELE_LICHTLOSER_JOKER - 1);
    
    tick_screen_adminoptionen1_spiele_lichtloser_joker();
}

void delete_screen_adminoptionen1_spiele_lichtloser_joker() {
    lv_obj_del(objects.adminoptionen1_spiele_lichtloser_joker);
    objects.adminoptionen1_spiele_lichtloser_joker = 0;
    objects.obj19 = 0;
    objects.obj68 = 0;
    objects.obj124 = 0;
    objects.switch_container_1 = 0;
    objects.obj69 = 0;
    objects.switch_title_1 = 0;
    objects.dropdown_container_3 = 0;
    objects.obj70 = 0;
    objects.roller_title_3 = 0;
    objects.obj71 = 0;
    deletePageFlowState(19);
}

void tick_screen_adminoptionen1_spiele_lichtloser_joker() {
    void *flowState = getFlowState(0, 19);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 85);
    {
        bool new_val = evalBooleanProperty(flowState, 6, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj69, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj69;
            if (new_val) lv_obj_add_state(objects.obj69, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj69, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 9, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj70, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj70;
            if (new_val) lv_obj_add_state(objects.obj70, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj70, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 11, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj71, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj71;
            if (new_val) lv_obj_add_state(objects.obj71, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj71, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalStringArrayPropertyAndJoin(flowState, 11, 4, "Failed to evaluate Options in Dropdown widget", "\n");
        const char *cur_val = lv_dropdown_get_options(objects.obj71);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj71;
            lv_dropdown_set_options(objects.obj71, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.obj71) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 11, 5, "Failed to evaluate Selected in Dropdown widget");
            int32_t cur_val = lv_dropdown_get_selected(objects.obj71);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.obj71;
                lv_dropdown_set_selected(objects.obj71, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
}

void create_screen_adminoptionen1_spiele_lichtloser_timings() {
    void *flowState = getFlowState(0, 20);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_spiele_lichtloser_timings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_timings_adminoptionen1_spiele_lichtloser_timings, LV_EVENT_ALL, flowState);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj20 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 87);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj72 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_timings_obj72, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj125 = obj;
            lv_obj_set_pos(obj, 91, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "TIMINGS");
        }
        {
            // sliderContainer_7
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.slider_container_7 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 80);
                    add_style_gold_panel(obj);
                }
                {
                    // sliderTitle_11
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_11 = obj;
                    lv_obj_set_pos(obj, 18, 12);
                    lv_obj_set_size(obj, 235, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "ACCEL. RUNDEN");
                }
                {
                    // slider_7
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_7 = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_range(obj, 5, 30);
                    lv_slider_set_mode(obj, LV_SLIDER_MODE_RANGE);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_timings_slider_7, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // sliderTitle_12
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_12 = obj;
                    lv_obj_set_pos(obj, 253, 12);
                    lv_obj_set_size(obj, 45, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // sliderTitle_13
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_13 = obj;
                    lv_obj_set_pos(obj, 293, 12);
                    lv_obj_set_size(obj, 30, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "-");
                }
                {
                    // sliderTitle_14
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_14 = obj;
                    lv_obj_set_pos(obj, 317, 12);
                    lv_obj_set_size(obj, 45, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // sliderContainer_8
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.slider_container_8 = obj;
            lv_obj_set_pos(obj, 35, 177);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 80);
                    add_style_gold_panel(obj);
                }
                {
                    // sliderTitle_15
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_15 = obj;
                    lv_obj_set_pos(obj, 18, 12);
                    lv_obj_set_size(obj, 235, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "DECEL. RUNDEN");
                }
                {
                    // slider_8
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_8 = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_range(obj, 5, 30);
                    lv_slider_set_mode(obj, LV_SLIDER_MODE_RANGE);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_timings_slider_8, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // sliderTitle_16
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_16 = obj;
                    lv_obj_set_pos(obj, 253, 12);
                    lv_obj_set_size(obj, 45, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // sliderTitle_17
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_17 = obj;
                    lv_obj_set_pos(obj, 293, 12);
                    lv_obj_set_size(obj, 30, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "-");
                }
                {
                    // sliderTitle_18
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_18 = obj;
                    lv_obj_set_pos(obj, 317, 12);
                    lv_obj_set_size(obj, 45, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // sliderContainer_9
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.slider_container_9 = obj;
            lv_obj_set_pos(obj, 35, 267);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 80);
                    add_style_gold_panel(obj);
                }
                {
                    // sliderTitle_19
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_19 = obj;
                    lv_obj_set_pos(obj, 18, 12);
                    lv_obj_set_size(obj, 235, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "MAXSP. RUNDEN");
                }
                {
                    // slider_9
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_9 = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_range(obj, 5, 40);
                    lv_slider_set_mode(obj, LV_SLIDER_MODE_RANGE);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_timings_slider_9, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // sliderTitle_20
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_20 = obj;
                    lv_obj_set_pos(obj, 253, 12);
                    lv_obj_set_size(obj, 45, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // sliderTitle_21
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_21 = obj;
                    lv_obj_set_pos(obj, 293, 12);
                    lv_obj_set_size(obj, 30, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "-");
                }
                {
                    // sliderTitle_22
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_22 = obj;
                    lv_obj_set_pos(obj, 317, 12);
                    lv_obj_set_size(obj, 45, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // sliderContainer_10
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.slider_container_10 = obj;
            lv_obj_set_pos(obj, 35, 357);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 80);
                    add_style_gold_panel(obj);
                }
                {
                    // sliderTitle_23
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_23 = obj;
                    lv_obj_set_pos(obj, 18, 12);
                    lv_obj_set_size(obj, 235, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "STEP MS");
                }
                {
                    // slider_1
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_1 = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_range(obj, 10, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_timings_slider_1, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // sliderTitle_24
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_24 = obj;
                    lv_obj_set_pos(obj, 253, 12);
                    lv_obj_set_size(obj, 50, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // sliderTitle_25
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_25 = obj;
                    lv_obj_set_pos(obj, 303, 12);
                    lv_obj_set_size(obj, 40, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "ms");
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SPIELE_LICHTLOSER_TIMINGS - 1);
    
    tick_screen_adminoptionen1_spiele_lichtloser_timings();
}

void delete_screen_adminoptionen1_spiele_lichtloser_timings() {
    lv_obj_del(objects.adminoptionen1_spiele_lichtloser_timings);
    objects.adminoptionen1_spiele_lichtloser_timings = 0;
    objects.obj20 = 0;
    objects.obj72 = 0;
    objects.obj125 = 0;
    objects.slider_container_7 = 0;
    objects.slider_title_11 = 0;
    objects.slider_7 = 0;
    objects.slider_title_12 = 0;
    objects.slider_title_13 = 0;
    objects.slider_title_14 = 0;
    objects.slider_container_8 = 0;
    objects.slider_title_15 = 0;
    objects.slider_8 = 0;
    objects.slider_title_16 = 0;
    objects.slider_title_17 = 0;
    objects.slider_title_18 = 0;
    objects.slider_container_9 = 0;
    objects.slider_title_19 = 0;
    objects.slider_9 = 0;
    objects.slider_title_20 = 0;
    objects.slider_title_21 = 0;
    objects.slider_title_22 = 0;
    objects.slider_container_10 = 0;
    objects.slider_title_23 = 0;
    objects.slider_1 = 0;
    objects.slider_title_24 = 0;
    objects.slider_title_25 = 0;
    deletePageFlowState(20);
}

void tick_screen_adminoptionen1_spiele_lichtloser_timings() {
    void *flowState = getFlowState(0, 20);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 87);
    {
        int32_t new_val = evalIntegerProperty(flowState, 7, 4, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.slider_7);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_7;
            lv_slider_set_value(objects.slider_7, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 7, 3, "Failed to evaluate Value left in Slider widget");
        int32_t cur_val = lv_slider_get_left_value(objects.slider_7);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_7;
            lv_slider_set_left_value(objects.slider_7, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.slider_title_12);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.slider_title_12;
            lv_label_set_text(objects.slider_title_12, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 10, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.slider_title_14);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.slider_title_14;
            lv_label_set_text(objects.slider_title_14, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 14, 4, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.slider_8);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_8;
            lv_slider_set_value(objects.slider_8, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 14, 3, "Failed to evaluate Value left in Slider widget");
        int32_t cur_val = lv_slider_get_left_value(objects.slider_8);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_8;
            lv_slider_set_left_value(objects.slider_8, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 15, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.slider_title_16);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.slider_title_16;
            lv_label_set_text(objects.slider_title_16, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 17, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.slider_title_18);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.slider_title_18;
            lv_label_set_text(objects.slider_title_18, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 21, 4, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.slider_9);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_9;
            lv_slider_set_value(objects.slider_9, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 21, 3, "Failed to evaluate Value left in Slider widget");
        int32_t cur_val = lv_slider_get_left_value(objects.slider_9);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_9;
            lv_slider_set_left_value(objects.slider_9, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 22, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.slider_title_20);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.slider_title_20;
            lv_label_set_text(objects.slider_title_20, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 24, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.slider_title_22);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.slider_title_22;
            lv_label_set_text(objects.slider_title_22, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 28, 3, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.slider_1);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_1;
            lv_slider_set_value(objects.slider_1, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 29, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.slider_title_24);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.slider_title_24;
            lv_label_set_text(objects.slider_title_24, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_adminoptionen1_farbeneffekte() {
    void *flowState = getFlowState(0, 21);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_farbeneffekte = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj21 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 89);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj126 = obj;
            lv_obj_set_pos(obj, 81, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "FARBEN/EFFEKTE");
        }
        {
            // buttonContainer_24
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_24 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_24
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_24 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_button_24, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_24
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_24 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "WIN/LOSE");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_25
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_25 = obj;
            lv_obj_set_pos(obj, 35, 147);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_25
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_25 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_button_25, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_25
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_25 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "SPIELERFARBE");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_26
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_26 = obj;
            lv_obj_set_pos(obj, 35, 207);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_26
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_26 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_button_26, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_26
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_26 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "GRENZFARBE");
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj73 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_obj73, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_FARBENEFFEKTE - 1);
    
    tick_screen_adminoptionen1_farbeneffekte();
}

void delete_screen_adminoptionen1_farbeneffekte() {
    lv_obj_del(objects.adminoptionen1_farbeneffekte);
    objects.adminoptionen1_farbeneffekte = 0;
    objects.obj21 = 0;
    objects.obj126 = 0;
    objects.button_container_24 = 0;
    objects.button_24 = 0;
    objects.button_title_24 = 0;
    objects.button_container_25 = 0;
    objects.button_25 = 0;
    objects.button_title_25 = 0;
    objects.button_container_26 = 0;
    objects.button_26 = 0;
    objects.button_title_26 = 0;
    objects.obj73 = 0;
    deletePageFlowState(21);
}

void tick_screen_adminoptionen1_farbeneffekte() {
    void *flowState = getFlowState(0, 21);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 89);
}

void create_screen_adminoptionen1_farbeneffekte_winlose() {
    void *flowState = getFlowState(0, 22);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_farbeneffekte_winlose = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj22 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 91);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj127 = obj;
            lv_obj_set_pos(obj, 106, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "WIN/LOSE");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj74 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_winlose_obj74, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // dropdownContainer_5
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_5 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_5
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_5 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "WIN");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "STANDARD");
                    lv_dropdown_set_selected(obj, 0);
                    add_style_gold_dropdown_(obj);
                }
            }
        }
        {
            // dropdownContainer_6
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_6 = obj;
            lv_obj_set_pos(obj, 35, 177);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_6
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_6 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "LOSE");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "STANDARD");
                    lv_dropdown_set_selected(obj, 0);
                    add_style_gold_dropdown_(obj);
                }
            }
        }
        {
            // dropdownContainer_7
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_7 = obj;
            lv_obj_set_pos(obj, 35, 267);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_7
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_7 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "WIN NEUTRAL");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "WIE LOSE\nSTANDARD");
                    lv_dropdown_set_selected(obj, 0);
                    add_style_gold_dropdown_(obj);
                }
            }
        }
        {
            // dropdownContainer_8
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_8 = obj;
            lv_obj_set_pos(obj, 35, 357);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_8
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_8 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "LOSE NEUTRAL");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "WIE WIN\nSTANDARD");
                    lv_dropdown_set_selected(obj, 0);
                    add_style_gold_dropdown_(obj);
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_FARBENEFFEKTE_WINLOSE - 1);
    
    tick_screen_adminoptionen1_farbeneffekte_winlose();
}

void delete_screen_adminoptionen1_farbeneffekte_winlose() {
    lv_obj_del(objects.adminoptionen1_farbeneffekte_winlose);
    objects.adminoptionen1_farbeneffekte_winlose = 0;
    objects.obj22 = 0;
    objects.obj127 = 0;
    objects.obj74 = 0;
    objects.dropdown_container_5 = 0;
    objects.roller_title_5 = 0;
    objects.dropdown_container_6 = 0;
    objects.roller_title_6 = 0;
    objects.dropdown_container_7 = 0;
    objects.roller_title_7 = 0;
    objects.dropdown_container_8 = 0;
    objects.roller_title_8 = 0;
    deletePageFlowState(22);
}

void tick_screen_adminoptionen1_farbeneffekte_winlose() {
    void *flowState = getFlowState(0, 22);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 91);
}

void create_screen_adminoptionen1_farbeneffekte_spielerfarbe() {
    void *flowState = getFlowState(0, 23);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_farbeneffekte_spielerfarbe = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_adminoptionen1_farbeneffekte_spielerfarbe, LV_EVENT_ALL, flowState);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj23 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 93);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj128 = obj;
            lv_obj_set_pos(obj, 101, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "SPIELERFARBE");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj75 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_obj75, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // dropdownContainer_9
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_9 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_9
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_9 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "SPIELERFARBEN");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    objects.obj76 = obj;
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "");
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_obj76, LV_EVENT_ALL, flowState);
                    add_style_gold_dropdown_(obj);
                }
            }
        }
        {
            // dropdownContainer_10
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_10 = obj;
            lv_obj_set_pos(obj, 35, 177);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj77 = obj;
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_obj77, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff747474), LV_PART_MAIN | LV_STATE_DISABLED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_10
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_10 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "EINFARBIG");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    objects.obj78 = obj;
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "");
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_obj78, LV_EVENT_ALL, flowState);
                    add_style_gold_dropdown_(obj);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff747474), LV_PART_MAIN | LV_STATE_DISABLED);
                }
            }
        }
        {
            // checkboxContatiner_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.checkbox_contatiner_2 = obj;
            lv_obj_set_pos(obj, 35, 267);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj79 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_obj79, LV_EVENT_ALL, flowState);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff747474), LV_PART_MAIN | LV_STATE_DISABLED);
                }
                {
                    // checkbox_2
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.checkbox_2 = obj;
                    lv_obj_set_pos(obj, 20, 11);
                    lv_obj_set_size(obj, 36, 38);
                    lv_checkbox_set_text(obj, "");
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_checkbox_2, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffff2bc), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 150, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdd111), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_CHECKED);
                }
                {
                    // checkboxTitle_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.checkbox_title_2 = obj;
                    lv_obj_set_pos(obj, 56, 11);
                    lv_obj_set_size(obj, 348, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "ZUFALL - JEDER SPIELER EIGEN");
                }
            }
        }
        {
            // dropdownContainer_17
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_17 = obj;
            lv_obj_set_pos(obj, 35, 327);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_17
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_17 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "INAKTIV");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    objects.obj80 = obj;
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "");
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_obj80, LV_EVENT_ALL, flowState);
                    add_style_gold_dropdown_(obj);
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_FARBENEFFEKTE_SPIELERFARBE - 1);
    
    tick_screen_adminoptionen1_farbeneffekte_spielerfarbe();
}

void delete_screen_adminoptionen1_farbeneffekte_spielerfarbe() {
    lv_obj_del(objects.adminoptionen1_farbeneffekte_spielerfarbe);
    objects.adminoptionen1_farbeneffekte_spielerfarbe = 0;
    objects.obj23 = 0;
    objects.obj128 = 0;
    objects.obj75 = 0;
    objects.dropdown_container_9 = 0;
    objects.roller_title_9 = 0;
    objects.obj76 = 0;
    objects.dropdown_container_10 = 0;
    objects.obj77 = 0;
    objects.roller_title_10 = 0;
    objects.obj78 = 0;
    objects.checkbox_contatiner_2 = 0;
    objects.obj79 = 0;
    objects.checkbox_2 = 0;
    objects.checkbox_title_2 = 0;
    objects.dropdown_container_17 = 0;
    objects.roller_title_17 = 0;
    objects.obj80 = 0;
    deletePageFlowState(23);
}

void tick_screen_adminoptionen1_farbeneffekte_spielerfarbe() {
    void *flowState = getFlowState(0, 23);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 93);
    {
        const char *new_val = evalStringArrayPropertyAndJoin(flowState, 7, 3, "Failed to evaluate Options in Dropdown widget", "\n");
        const char *cur_val = lv_dropdown_get_options(objects.obj76);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj76;
            lv_dropdown_set_options(objects.obj76, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.obj76) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 7, 4, "Failed to evaluate Selected in Dropdown widget");
            int32_t cur_val = lv_dropdown_get_selected(objects.obj76);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.obj76;
                lv_dropdown_set_selected(objects.obj76, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 9, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj77, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj77;
            if (new_val) lv_obj_add_state(objects.obj77, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj77, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 11, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj78, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj78;
            if (new_val) lv_obj_add_state(objects.obj78, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj78, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalStringArrayPropertyAndJoin(flowState, 11, 4, "Failed to evaluate Options in Dropdown widget", "\n");
        const char *cur_val = lv_dropdown_get_options(objects.obj78);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj78;
            lv_dropdown_set_options(objects.obj78, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.obj78) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 11, 5, "Failed to evaluate Selected in Dropdown widget");
            int32_t cur_val = lv_dropdown_get_selected(objects.obj78);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.obj78;
                lv_dropdown_set_selected(objects.obj78, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 13, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj79, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj79;
            if (new_val) lv_obj_add_state(objects.obj79, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj79, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 14, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.checkbox_2, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.checkbox_2;
            if (new_val) lv_obj_add_state(objects.checkbox_2, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.checkbox_2, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 14, 4, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.checkbox_2, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.checkbox_2;
            if (new_val) lv_obj_add_state(objects.checkbox_2, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.checkbox_2, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalStringArrayPropertyAndJoin(flowState, 19, 3, "Failed to evaluate Options in Dropdown widget", "\n");
        const char *cur_val = lv_dropdown_get_options(objects.obj80);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj80;
            lv_dropdown_set_options(objects.obj80, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.obj80) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 19, 4, "Failed to evaluate Selected in Dropdown widget");
            int32_t cur_val = lv_dropdown_get_selected(objects.obj80);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.obj80;
                lv_dropdown_set_selected(objects.obj80, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
}

void create_screen_adminoptionen1_farbeneffekte_grenzfarbe() {
    void *flowState = getFlowState(0, 24);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_farbeneffekte_grenzfarbe = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_grenzfarbe_adminoptionen1_farbeneffekte_grenzfarbe, LV_EVENT_ALL, flowState);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj24 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 95);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj129 = obj;
            lv_obj_set_pos(obj, 123, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "GRENZFARBE");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj81 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_grenzfarbe_obj81, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // dropdownContainer_11
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_11 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_11
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_11 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "GRENZFARBE");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    objects.obj82 = obj;
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "");
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_grenzfarbe_obj82, LV_EVENT_ALL, flowState);
                    add_style_gold_dropdown_(obj);
                }
            }
        }
        {
            // dropdownContainer_12
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_12 = obj;
            lv_obj_set_pos(obj, 35, 177);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj83 = obj;
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_grenzfarbe_obj83, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff747474), LV_PART_MAIN | LV_STATE_DISABLED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_12
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_12 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "EINFARBIG");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    objects.obj84 = obj;
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "");
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_grenzfarbe_obj84, LV_EVENT_ALL, flowState);
                    add_style_gold_dropdown_(obj);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff747474), LV_PART_MAIN | LV_STATE_DISABLED);
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_FARBENEFFEKTE_GRENZFARBE - 1);
    
    tick_screen_adminoptionen1_farbeneffekte_grenzfarbe();
}

void delete_screen_adminoptionen1_farbeneffekte_grenzfarbe() {
    lv_obj_del(objects.adminoptionen1_farbeneffekte_grenzfarbe);
    objects.adminoptionen1_farbeneffekte_grenzfarbe = 0;
    objects.obj24 = 0;
    objects.obj129 = 0;
    objects.obj81 = 0;
    objects.dropdown_container_11 = 0;
    objects.roller_title_11 = 0;
    objects.obj82 = 0;
    objects.dropdown_container_12 = 0;
    objects.obj83 = 0;
    objects.roller_title_12 = 0;
    objects.obj84 = 0;
    deletePageFlowState(24);
}

void tick_screen_adminoptionen1_farbeneffekte_grenzfarbe() {
    void *flowState = getFlowState(0, 24);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 95);
    {
        const char *new_val = evalStringArrayPropertyAndJoin(flowState, 7, 3, "Failed to evaluate Options in Dropdown widget", "\n");
        const char *cur_val = lv_dropdown_get_options(objects.obj82);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj82;
            lv_dropdown_set_options(objects.obj82, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.obj82) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 7, 4, "Failed to evaluate Selected in Dropdown widget");
            int32_t cur_val = lv_dropdown_get_selected(objects.obj82);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.obj82;
                lv_dropdown_set_selected(objects.obj82, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 9, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj83, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj83;
            if (new_val) lv_obj_add_state(objects.obj83, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj83, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 11, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj84, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj84;
            if (new_val) lv_obj_add_state(objects.obj84, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj84, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalStringArrayPropertyAndJoin(flowState, 11, 4, "Failed to evaluate Options in Dropdown widget", "\n");
        const char *cur_val = lv_dropdown_get_options(objects.obj84);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj84;
            lv_dropdown_set_options(objects.obj84, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.obj84) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 11, 5, "Failed to evaluate Selected in Dropdown widget");
            int32_t cur_val = lv_dropdown_get_selected(objects.obj84);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.obj84;
                lv_dropdown_set_selected(objects.obj84, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
}

void create_screen_adminoptionen1_system() {
    void *flowState = getFlowState(0, 25);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj25 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 97);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj130 = obj;
            lv_obj_set_pos(obj, 129, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "SYSTEM");
        }
        {
            // buttonContainer_12
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_12 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_12
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_12 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_button_12, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_12
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_12 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "LEDS");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_13
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_13 = obj;
            lv_obj_set_pos(obj, 35, 147);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_13
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_13 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_button_13, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_13
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_13 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "ANZEIGE");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_16
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_16 = obj;
            lv_obj_set_pos(obj, 35, 207);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_16
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_16 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_button_16, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_16
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_16 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "AUDIO");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_14
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_14 = obj;
            lv_obj_set_pos(obj, 35, 267);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_14
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_14 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_button_14, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_14
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_14 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "NETZWERK");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_15
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_15 = obj;
            lv_obj_set_pos(obj, 35, 327);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_15
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_15 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_button_15, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_15
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_15 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "DEBUG");
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj85 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_obj85, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // questionContainer_7
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.question_container_7 = obj;
            lv_obj_set_pos(obj, 410, 9);
            lv_obj_set_size(obj, 70, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj86 = obj;
                    lv_obj_set_pos(obj, 8, 5);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_obj86, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj131 = obj;
                            lv_obj_set_pos(obj, -1, 10);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "->");
                        }
                    }
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM - 1);
    
    tick_screen_adminoptionen1_system();
}

void delete_screen_adminoptionen1_system() {
    lv_obj_del(objects.adminoptionen1_system);
    objects.adminoptionen1_system = 0;
    objects.obj25 = 0;
    objects.obj130 = 0;
    objects.button_container_12 = 0;
    objects.button_12 = 0;
    objects.button_title_12 = 0;
    objects.button_container_13 = 0;
    objects.button_13 = 0;
    objects.button_title_13 = 0;
    objects.button_container_16 = 0;
    objects.button_16 = 0;
    objects.button_title_16 = 0;
    objects.button_container_14 = 0;
    objects.button_14 = 0;
    objects.button_title_14 = 0;
    objects.button_container_15 = 0;
    objects.button_15 = 0;
    objects.button_title_15 = 0;
    objects.obj85 = 0;
    objects.question_container_7 = 0;
    objects.obj86 = 0;
    objects.obj131 = 0;
    deletePageFlowState(25);
}

void tick_screen_adminoptionen1_system() {
    void *flowState = getFlowState(0, 25);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 97);
}

void create_screen_adminoptionen1_system_leds() {
    void *flowState = getFlowState(0, 26);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_leds = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj26 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 99);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj132 = obj;
            lv_obj_set_pos(obj, 171, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "LEDS");
        }
        {
            // buttonContainer_18
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_18 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_18
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_18 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_leds_button_18, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_18
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_18 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "HELLIGKEIT");
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj87 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_leds_obj87, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_LEDS - 1);
    
    tick_screen_adminoptionen1_system_leds();
}

void delete_screen_adminoptionen1_system_leds() {
    lv_obj_del(objects.adminoptionen1_system_leds);
    objects.adminoptionen1_system_leds = 0;
    objects.obj26 = 0;
    objects.obj132 = 0;
    objects.button_container_18 = 0;
    objects.button_18 = 0;
    objects.button_title_18 = 0;
    objects.obj87 = 0;
    deletePageFlowState(26);
}

void tick_screen_adminoptionen1_system_leds() {
    void *flowState = getFlowState(0, 26);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 99);
}

void create_screen_adminoptionen1_system_leds_helligkeit() {
    void *flowState = getFlowState(0, 27);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_leds_helligkeit = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_leds_helligkeit_adminoptionen1_system_leds_helligkeit, LV_EVENT_ALL, flowState);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj27 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 101);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj133 = obj;
            lv_obj_set_pos(obj, 78, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "HELLIGKEIT");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj88 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_leds_helligkeit_obj88, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // sliderContainer_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.slider_container_2 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 80);
                    add_style_gold_panel(obj);
                }
                {
                    // sliderTitle_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_2 = obj;
                    lv_obj_set_pos(obj, 18, 12);
                    lv_obj_set_size(obj, 396, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "SPIELLEDS                 %");
                }
                {
                    // slider_2
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_2 = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_range(obj, 13, 140);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_leds_helligkeit_slider_2, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // sliderTitle_8
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_8 = obj;
                    lv_obj_set_pos(obj, 225, 12);
                    lv_obj_set_size(obj, 130, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // sliderContainer_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.slider_container_3 = obj;
            lv_obj_set_pos(obj, 35, 177);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 80);
                    add_style_gold_panel(obj);
                }
                {
                    // sliderTitle_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_3 = obj;
                    lv_obj_set_pos(obj, 18, 12);
                    lv_obj_set_size(obj, 396, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "GRENZLEDS                 %");
                }
                {
                    // sliderTitle_9
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_9 = obj;
                    lv_obj_set_pos(obj, 225, 12);
                    lv_obj_set_size(obj, 130, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // slider_3
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_3 = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_range(obj, 13, 140);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_leds_helligkeit_slider_3, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_LEDS_HELLIGKEIT - 1);
    
    tick_screen_adminoptionen1_system_leds_helligkeit();
}

void delete_screen_adminoptionen1_system_leds_helligkeit() {
    lv_obj_del(objects.adminoptionen1_system_leds_helligkeit);
    objects.adminoptionen1_system_leds_helligkeit = 0;
    objects.obj27 = 0;
    objects.obj133 = 0;
    objects.obj88 = 0;
    objects.slider_container_2 = 0;
    objects.slider_title_2 = 0;
    objects.slider_2 = 0;
    objects.slider_title_8 = 0;
    objects.slider_container_3 = 0;
    objects.slider_title_3 = 0;
    objects.slider_title_9 = 0;
    objects.slider_3 = 0;
    deletePageFlowState(27);
}

void tick_screen_adminoptionen1_system_leds_helligkeit() {
    void *flowState = getFlowState(0, 27);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 101);
    {
        int32_t new_val = evalIntegerProperty(flowState, 7, 3, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.slider_2);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_2;
            lv_slider_set_value(objects.slider_2, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.slider_title_8);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.slider_title_8;
            lv_label_set_text(objects.slider_title_8, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.slider_title_9);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.slider_title_9;
            lv_label_set_text(objects.slider_title_9, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 13, 3, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.slider_3);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_3;
            lv_slider_set_value(objects.slider_3, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_adminoptionen1_system_anzeige() {
    void *flowState = getFlowState(0, 28);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_anzeige = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj28 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 103);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj134 = obj;
            lv_obj_set_pos(obj, 112, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "ANZEIGE");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj89 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_anzeige_obj89, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // sliderContainer_4
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.slider_container_4 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 80);
                    add_style_gold_panel(obj);
                }
                {
                    // sliderTitle_4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_4 = obj;
                    lv_obj_set_pos(obj, 7, 12);
                    lv_obj_set_size(obj, 396, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "HELLIGKEIT       %");
                }
                {
                    // sliderTitle_10
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_10 = obj;
                    lv_obj_set_pos(obj, 263, 12);
                    lv_obj_set_size(obj, 52, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // slider_4
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_4 = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_range(obj, 10, 100);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_anzeige_slider_4, LV_EVENT_ALL, flowState);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // buttonContainer_29
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_29 = obj;
            lv_obj_set_pos(obj, 35, 177);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_29
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_29 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_anzeige_button_29, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_29
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_29 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "IDLE");
                        }
                    }
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_ANZEIGE - 1);
    
    tick_screen_adminoptionen1_system_anzeige();
}

void delete_screen_adminoptionen1_system_anzeige() {
    lv_obj_del(objects.adminoptionen1_system_anzeige);
    objects.adminoptionen1_system_anzeige = 0;
    objects.obj28 = 0;
    objects.obj134 = 0;
    objects.obj89 = 0;
    objects.slider_container_4 = 0;
    objects.slider_title_4 = 0;
    objects.slider_title_10 = 0;
    objects.slider_4 = 0;
    objects.button_container_29 = 0;
    objects.button_29 = 0;
    objects.button_title_29 = 0;
    deletePageFlowState(28);
}

void tick_screen_adminoptionen1_system_anzeige() {
    void *flowState = getFlowState(0, 28);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 103);
    {
        const char *new_val = evalTextProperty(flowState, 7, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.slider_title_10);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.slider_title_10;
            lv_label_set_text(objects.slider_title_10, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 8, 3, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.slider_4);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_4;
            lv_slider_set_value(objects.slider_4, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_adminoptionen1_system_anzeige_idle() {
    void *flowState = getFlowState(0, 29);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_anzeige_idle = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_anzeige_idle_adminoptionen1_system_anzeige_idle, LV_EVENT_ALL, flowState);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj29 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 105);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj135 = obj;
            lv_obj_set_pos(obj, 188, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "IDLE");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj90 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_anzeige_idle_obj90, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // switchContainer_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.switch_container_2 = obj;
            lv_obj_set_pos(obj, 35, 82);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 50);
                    add_style_gold_panel(obj);
                }
                {
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.obj91 = obj;
                    lv_obj_set_pos(obj, 17, 13);
                    lv_obj_set_size(obj, 73, 34);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_anzeige_idle_obj91, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
                }
                {
                    // switchTitle_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.switch_title_2 = obj;
                    lv_obj_set_pos(obj, 86, 11);
                    lv_obj_set_size(obj, 319, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "IDLE");
                }
            }
        }
        {
            // dropdownContainer_4
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_4 = obj;
            lv_obj_set_pos(obj, 35, 142);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj92 = obj;
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_anzeige_idle_obj92, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff747474), LV_PART_MAIN | LV_STATE_DISABLED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_4
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_4 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "IDLE NACH..");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    objects.obj93 = obj;
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "");
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_anzeige_idle_obj93, LV_EVENT_ALL, flowState);
                    add_style_gold_dropdown_(obj);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff747474), LV_PART_MAIN | LV_STATE_DISABLED);
                }
            }
        }
        {
            // checkboxContatiner_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.checkbox_contatiner_1 = obj;
            lv_obj_set_pos(obj, 35, 232);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj94 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_anzeige_idle_obj94, LV_EVENT_ALL, flowState);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff747474), LV_PART_MAIN | LV_STATE_DISABLED);
                }
                {
                    // checkbox_1
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.checkbox_1 = obj;
                    lv_obj_set_pos(obj, 20, 11);
                    lv_obj_set_size(obj, 370, 38);
                    lv_checkbox_set_text(obj, "");
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_anzeige_idle_checkbox_1, LV_EVENT_ALL, flowState);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffff2bc), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 150, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdd111), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_CHECKED);
                }
                {
                    // checkboxTitle_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.checkbox_title_1 = obj;
                    lv_obj_set_pos(obj, 56, 11);
                    lv_obj_set_size(obj, 348, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "ENERGIESPARMODUS");
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_ANZEIGE_IDLE - 1);
    
    tick_screen_adminoptionen1_system_anzeige_idle();
}

void delete_screen_adminoptionen1_system_anzeige_idle() {
    lv_obj_del(objects.adminoptionen1_system_anzeige_idle);
    objects.adminoptionen1_system_anzeige_idle = 0;
    objects.obj29 = 0;
    objects.obj135 = 0;
    objects.obj90 = 0;
    objects.switch_container_2 = 0;
    objects.obj91 = 0;
    objects.switch_title_2 = 0;
    objects.dropdown_container_4 = 0;
    objects.obj92 = 0;
    objects.roller_title_4 = 0;
    objects.obj93 = 0;
    objects.checkbox_contatiner_1 = 0;
    objects.obj94 = 0;
    objects.checkbox_1 = 0;
    objects.checkbox_title_1 = 0;
    deletePageFlowState(29);
}

void tick_screen_adminoptionen1_system_anzeige_idle() {
    void *flowState = getFlowState(0, 29);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 105);
    {
        bool new_val = evalBooleanProperty(flowState, 6, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj91, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj91;
            if (new_val) lv_obj_add_state(objects.obj91, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj91, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 9, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj92, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj92;
            if (new_val) lv_obj_add_state(objects.obj92, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj92, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 11, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj93, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj93;
            if (new_val) lv_obj_add_state(objects.obj93, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj93, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalStringArrayPropertyAndJoin(flowState, 11, 4, "Failed to evaluate Options in Dropdown widget", "\n");
        const char *cur_val = lv_dropdown_get_options(objects.obj93);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj93;
            lv_dropdown_set_options(objects.obj93, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.obj93) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 11, 5, "Failed to evaluate Selected in Dropdown widget");
            int32_t cur_val = lv_dropdown_get_selected(objects.obj93);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.obj93;
                lv_dropdown_set_selected(objects.obj93, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 13, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj94, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj94;
            if (new_val) lv_obj_add_state(objects.obj94, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj94, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 14, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.checkbox_1, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.checkbox_1;
            if (new_val) lv_obj_add_state(objects.checkbox_1, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.checkbox_1, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 14, 4, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.checkbox_1, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.checkbox_1;
            if (new_val) lv_obj_add_state(objects.checkbox_1, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.checkbox_1, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_adminoptionen1_system_audio() {
    void *flowState = getFlowState(0, 30);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_audio = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj30 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 107);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj136 = obj;
            lv_obj_set_pos(obj, 146, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "AUDIO");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj95 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_audio_obj95, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // switchContainer_5
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.switch_container_5 = obj;
            lv_obj_set_pos(obj, 35, 82);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 50);
                    add_style_gold_panel(obj);
                }
                {
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.obj137 = obj;
                    lv_obj_set_pos(obj, 17, 13);
                    lv_obj_set_size(obj, 73, 34);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
                }
                {
                    // switchTitle_5
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.switch_title_5 = obj;
                    lv_obj_set_pos(obj, 86, 11);
                    lv_obj_set_size(obj, 319, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "SOUNDEFFEKTE");
                }
            }
        }
        {
            // sliderContainer_5
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.slider_container_5 = obj;
            lv_obj_set_pos(obj, 35, 142);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 80);
                    add_style_gold_panel(obj);
                }
                {
                    // sliderTitle_5
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_5 = obj;
                    lv_obj_set_pos(obj, 7, 12);
                    lv_obj_set_size(obj, 396, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "LAUTSTAERKE");
                }
                {
                    // slider_5
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_5 = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_value(obj, 50, LV_ANIM_OFF);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // switchContainer_6
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.switch_container_6 = obj;
            lv_obj_set_pos(obj, 35, 232);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 50);
                    add_style_gold_panel(obj);
                }
                {
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.obj138 = obj;
                    lv_obj_set_pos(obj, 17, 13);
                    lv_obj_set_size(obj, 73, 34);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
                }
                {
                    // switchTitle_6
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.switch_title_6 = obj;
                    lv_obj_set_pos(obj, 86, 11);
                    lv_obj_set_size(obj, 319, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "MUSIK");
                }
            }
        }
        {
            // sliderContainer_6
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.slider_container_6 = obj;
            lv_obj_set_pos(obj, 35, 292);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 80);
                    add_style_gold_panel(obj);
                }
                {
                    // sliderTitle_6
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_6 = obj;
                    lv_obj_set_pos(obj, 7, 12);
                    lv_obj_set_size(obj, 396, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "LAUTSTAERKE");
                }
                {
                    // slider_6
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_6 = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_value(obj, 50, LV_ANIM_OFF);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // buttonContainer_17
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_17 = obj;
            lv_obj_set_pos(obj, 35, 420);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_17
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_17 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_17
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_17 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "TEST");
                        }
                    }
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_AUDIO - 1);
    
    tick_screen_adminoptionen1_system_audio();
}

void delete_screen_adminoptionen1_system_audio() {
    lv_obj_del(objects.adminoptionen1_system_audio);
    objects.adminoptionen1_system_audio = 0;
    objects.obj30 = 0;
    objects.obj136 = 0;
    objects.obj95 = 0;
    objects.switch_container_5 = 0;
    objects.obj137 = 0;
    objects.switch_title_5 = 0;
    objects.slider_container_5 = 0;
    objects.slider_title_5 = 0;
    objects.slider_5 = 0;
    objects.switch_container_6 = 0;
    objects.obj138 = 0;
    objects.switch_title_6 = 0;
    objects.slider_container_6 = 0;
    objects.slider_title_6 = 0;
    objects.slider_6 = 0;
    objects.button_container_17 = 0;
    objects.button_17 = 0;
    objects.button_title_17 = 0;
    deletePageFlowState(30);
}

void tick_screen_adminoptionen1_system_audio() {
    void *flowState = getFlowState(0, 30);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 107);
}

void create_screen_adminoptionen1_system_netzwerk() {
    void *flowState = getFlowState(0, 31);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_netzwerk = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj31 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 109);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj139 = obj;
            lv_obj_set_pos(obj, 78, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "NETZWERK");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj96 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_obj96, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // buttonContainer_19
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_19 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_19
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_19 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_button_19, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_19
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_19 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "WIFI");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_22
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_22 = obj;
            lv_obj_set_pos(obj, 35, 147);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_22
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_22 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_button_22, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_22
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_22 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "KOMMUNIKATION");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_23
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_23 = obj;
            lv_obj_set_pos(obj, 35, 207);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_23
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_23 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_button_23, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_23
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_23 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "UPDATE");
                        }
                    }
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_NETZWERK - 1);
    
    tick_screen_adminoptionen1_system_netzwerk();
}

void delete_screen_adminoptionen1_system_netzwerk() {
    lv_obj_del(objects.adminoptionen1_system_netzwerk);
    objects.adminoptionen1_system_netzwerk = 0;
    objects.obj31 = 0;
    objects.obj139 = 0;
    objects.obj96 = 0;
    objects.button_container_19 = 0;
    objects.button_19 = 0;
    objects.button_title_19 = 0;
    objects.button_container_22 = 0;
    objects.button_22 = 0;
    objects.button_title_22 = 0;
    objects.button_container_23 = 0;
    objects.button_23 = 0;
    objects.button_title_23 = 0;
    deletePageFlowState(31);
}

void tick_screen_adminoptionen1_system_netzwerk() {
    void *flowState = getFlowState(0, 31);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 109);
}

void create_screen_adminoptionen1_system_netzwerk_wifi() {
    void *flowState = getFlowState(0, 32);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_netzwerk_wifi = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj32 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 111);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj140 = obj;
            lv_obj_set_pos(obj, 146, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "WIFI");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj97 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_wifi_obj97, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // switchContainer_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.switch_container_3 = obj;
            lv_obj_set_pos(obj, 35, 85);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 50);
                    add_style_gold_panel(obj);
                }
                {
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.obj141 = obj;
                    lv_obj_set_pos(obj, 17, 13);
                    lv_obj_set_size(obj, 73, 34);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
                }
                {
                    // switchTitle_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.switch_title_3 = obj;
                    lv_obj_set_pos(obj, 86, 11);
                    lv_obj_set_size(obj, 319, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "WIFI AP");
                }
            }
        }
        {
            // buttonContainer_20
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_20 = obj;
            lv_obj_set_pos(obj, 35, 145);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_20
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_20 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_20
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_20 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "SSID: pitterMesh");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_21
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_21 = obj;
            lv_obj_set_pos(obj, 35, 205);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_21
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_21 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_21
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_21 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "PW: pitteromat2025");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_36
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_36 = obj;
            lv_obj_set_pos(obj, 35, 420);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_36
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_36 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_36
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_36 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "QR-CODE APP");
                        }
                    }
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_NETZWERK_WIFI - 1);
    
    tick_screen_adminoptionen1_system_netzwerk_wifi();
}

void delete_screen_adminoptionen1_system_netzwerk_wifi() {
    lv_obj_del(objects.adminoptionen1_system_netzwerk_wifi);
    objects.adminoptionen1_system_netzwerk_wifi = 0;
    objects.obj32 = 0;
    objects.obj140 = 0;
    objects.obj97 = 0;
    objects.switch_container_3 = 0;
    objects.obj141 = 0;
    objects.switch_title_3 = 0;
    objects.button_container_20 = 0;
    objects.button_20 = 0;
    objects.button_title_20 = 0;
    objects.button_container_21 = 0;
    objects.button_21 = 0;
    objects.button_title_21 = 0;
    objects.button_container_36 = 0;
    objects.button_36 = 0;
    objects.button_title_36 = 0;
    deletePageFlowState(32);
}

void tick_screen_adminoptionen1_system_netzwerk_wifi() {
    void *flowState = getFlowState(0, 32);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 111);
}

void create_screen_adminoptionen1_system_netzwerk_kommunikation() {
    void *flowState = getFlowState(0, 33);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_netzwerk_kommunikation = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj33 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 113);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj142 = obj;
            lv_obj_set_pos(obj, 61, 13);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "KOMMUNIKATION");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj98 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_kommunikation_obj98, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // dropdownContainer_13
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_13 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_13
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_13 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "ESP <-> ESP");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "WIFI\nESPnow");
                    lv_dropdown_set_selected(obj, 0);
                    add_style_gold_dropdown_(obj);
                }
            }
        }
        {
            // dropdownContainer_14
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_14 = obj;
            lv_obj_set_pos(obj, 35, 177);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_14
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_14 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "ESP <-> ARDUINO");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "RS485");
                    lv_dropdown_set_selected(obj, 0);
                    add_style_gold_dropdown_(obj);
                }
            }
        }
        {
            // dropdownContainer_15
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_15 = obj;
            lv_obj_set_pos(obj, 35, 267);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_15
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_15 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "SYNC TIME");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "0ms\n10ms\n20ms\n40ms\n70ms\n100ms");
                    lv_dropdown_set_selected(obj, 1);
                    add_style_gold_dropdown_(obj);
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_NETZWERK_KOMMUNIKATION - 1);
    
    tick_screen_adminoptionen1_system_netzwerk_kommunikation();
}

void delete_screen_adminoptionen1_system_netzwerk_kommunikation() {
    lv_obj_del(objects.adminoptionen1_system_netzwerk_kommunikation);
    objects.adminoptionen1_system_netzwerk_kommunikation = 0;
    objects.obj33 = 0;
    objects.obj142 = 0;
    objects.obj98 = 0;
    objects.dropdown_container_13 = 0;
    objects.roller_title_13 = 0;
    objects.dropdown_container_14 = 0;
    objects.roller_title_14 = 0;
    objects.dropdown_container_15 = 0;
    objects.roller_title_15 = 0;
    deletePageFlowState(33);
}

void tick_screen_adminoptionen1_system_netzwerk_kommunikation() {
    void *flowState = getFlowState(0, 33);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 113);
}

void create_screen_adminoptionen1_system_netzwerk_update() {
    void *flowState = getFlowState(0, 34);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_netzwerk_update = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj34 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 115);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj143 = obj;
            lv_obj_set_pos(obj, 136, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "UPDATE");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj99 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_update_obj99, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // dropdownContainer_16
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_16 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_16
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_16 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "ESP-UPDATE SYNC");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "AUTO\nMANUELL");
                    lv_dropdown_set_selected(obj, 0);
                    add_style_gold_dropdown_(obj);
                }
            }
        }
        {
            // buttonContainer_27
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_27 = obj;
            lv_obj_set_pos(obj, 35, 177);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_27
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_27 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_27
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_27 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "ESP-UPDATE SYNC");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_33
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_33 = obj;
            lv_obj_set_pos(obj, 35, 237);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_33
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_33 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_33
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_33 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "ARDUINO-UPDATE SYNC");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_44
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_44 = obj;
            lv_obj_set_pos(obj, 35, 360);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_44
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_44 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_update_button_44, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_44
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_44 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "MANIFEST");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_31
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_31 = obj;
            lv_obj_set_pos(obj, 35, 420);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_31
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_31 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_update_button_31, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_31
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_31 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "FIRMWARE");
                        }
                    }
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_NETZWERK_UPDATE - 1);
    
    tick_screen_adminoptionen1_system_netzwerk_update();
}

void delete_screen_adminoptionen1_system_netzwerk_update() {
    lv_obj_del(objects.adminoptionen1_system_netzwerk_update);
    objects.adminoptionen1_system_netzwerk_update = 0;
    objects.obj34 = 0;
    objects.obj143 = 0;
    objects.obj99 = 0;
    objects.dropdown_container_16 = 0;
    objects.roller_title_16 = 0;
    objects.button_container_27 = 0;
    objects.button_27 = 0;
    objects.button_title_27 = 0;
    objects.button_container_33 = 0;
    objects.button_33 = 0;
    objects.button_title_33 = 0;
    objects.button_container_44 = 0;
    objects.button_44 = 0;
    objects.button_title_44 = 0;
    objects.button_container_31 = 0;
    objects.button_31 = 0;
    objects.button_title_31 = 0;
    deletePageFlowState(34);
}

void tick_screen_adminoptionen1_system_netzwerk_update() {
    void *flowState = getFlowState(0, 34);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 115);
}

void create_screen_adminoptionen1_system_netzwerk_update_manifest() {
    void *flowState = getFlowState(0, 35);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_netzwerk_update_manifest = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj35 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 117);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj144 = obj;
            lv_obj_set_pos(obj, 85, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "MANIFEST");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj100 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_update_manifest_obj100, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // buttonContainer_51
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_51 = obj;
            lv_obj_set_pos(obj, 35, 71);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_51
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_51 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_51
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_51 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "M:");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_52
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_52 = obj;
            lv_obj_set_pos(obj, 35, 121);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_52
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_52 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_52
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_52 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "2:");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_53
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_53 = obj;
            lv_obj_set_pos(obj, 35, 171);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_53
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_53 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_53
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_53 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "3:");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_54
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_54 = obj;
            lv_obj_set_pos(obj, 35, 221);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_54
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_54 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_54
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_54 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "4:");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_55
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_55 = obj;
            lv_obj_set_pos(obj, 35, 271);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_55
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_55 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_55
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_55 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "5:");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_56
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_56 = obj;
            lv_obj_set_pos(obj, 35, 321);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_56
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_56 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_56
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_56 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "6:");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_57
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_57 = obj;
            lv_obj_set_pos(obj, 35, 371);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_57
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_57 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_57
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_57 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "7:");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_58
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_58 = obj;
            lv_obj_set_pos(obj, 35, 421);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_58
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_58 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_58
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_58 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "8:");
                        }
                    }
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_NETZWERK_UPDATE_MANIFEST - 1);
    
    tick_screen_adminoptionen1_system_netzwerk_update_manifest();
}

void delete_screen_adminoptionen1_system_netzwerk_update_manifest() {
    lv_obj_del(objects.adminoptionen1_system_netzwerk_update_manifest);
    objects.adminoptionen1_system_netzwerk_update_manifest = 0;
    objects.obj35 = 0;
    objects.obj144 = 0;
    objects.obj100 = 0;
    objects.button_container_51 = 0;
    objects.button_51 = 0;
    objects.button_title_51 = 0;
    objects.button_container_52 = 0;
    objects.button_52 = 0;
    objects.button_title_52 = 0;
    objects.button_container_53 = 0;
    objects.button_53 = 0;
    objects.button_title_53 = 0;
    objects.button_container_54 = 0;
    objects.button_54 = 0;
    objects.button_title_54 = 0;
    objects.button_container_55 = 0;
    objects.button_55 = 0;
    objects.button_title_55 = 0;
    objects.button_container_56 = 0;
    objects.button_56 = 0;
    objects.button_title_56 = 0;
    objects.button_container_57 = 0;
    objects.button_57 = 0;
    objects.button_title_57 = 0;
    objects.button_container_58 = 0;
    objects.button_58 = 0;
    objects.button_title_58 = 0;
    deletePageFlowState(35);
}

void tick_screen_adminoptionen1_system_netzwerk_update_manifest() {
    void *flowState = getFlowState(0, 35);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 117);
}

void create_screen_adminoptionen1_system_netzwerk_update_firmware() {
    void *flowState = getFlowState(0, 36);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_netzwerk_update_firmware = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj36 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 119);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj145 = obj;
            lv_obj_set_pos(obj, 64, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "FIRMWARE");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj101 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_update_firmware_obj101, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // buttonContainer_32
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_32 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_32
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_32 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_32
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_32 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "ONLINE-UPDATE");
                        }
                    }
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_NETZWERK_UPDATE_FIRMWARE - 1);
    
    tick_screen_adminoptionen1_system_netzwerk_update_firmware();
}

void delete_screen_adminoptionen1_system_netzwerk_update_firmware() {
    lv_obj_del(objects.adminoptionen1_system_netzwerk_update_firmware);
    objects.adminoptionen1_system_netzwerk_update_firmware = 0;
    objects.obj36 = 0;
    objects.obj145 = 0;
    objects.obj101 = 0;
    objects.button_container_32 = 0;
    objects.button_32 = 0;
    objects.button_title_32 = 0;
    deletePageFlowState(36);
}

void tick_screen_adminoptionen1_system_netzwerk_update_firmware() {
    void *flowState = getFlowState(0, 36);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 119);
}

void create_screen_adminoptionen1_system_debug() {
    void *flowState = getFlowState(0, 37);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_debug = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj37 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 121);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj146 = obj;
            lv_obj_set_pos(obj, 145, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "DEBUG");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj102 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_debug_obj102, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // switchContainer_7
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.switch_container_7 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 50);
                    add_style_gold_panel(obj);
                }
                {
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.obj147 = obj;
                    lv_obj_set_pos(obj, 17, 13);
                    lv_obj_set_size(obj, 73, 34);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
                }
                {
                    // switchTitle_7
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.switch_title_7 = obj;
                    lv_obj_set_pos(obj, 86, 11);
                    lv_obj_set_size(obj, 319, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "PERF. OVERLAY");
                }
            }
        }
        {
            // switchContainer_4
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.switch_container_4 = obj;
            lv_obj_set_pos(obj, 35, 147);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 50);
                    add_style_gold_panel(obj);
                }
                {
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.obj148 = obj;
                    lv_obj_set_pos(obj, 17, 13);
                    lv_obj_set_size(obj, 73, 34);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
                }
                {
                    // switchTitle_4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.switch_title_4 = obj;
                    lv_obj_set_pos(obj, 86, 11);
                    lv_obj_set_size(obj, 319, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "SERIELLE AUSGABE");
                }
            }
        }
        {
            // buttonContainer_28
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_28 = obj;
            lv_obj_set_pos(obj, 35, 207);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_28
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_28 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_28
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_28 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "SPI TEST");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_30
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_30 = obj;
            lv_obj_set_pos(obj, 35, 267);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_30
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_30 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_30
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_30 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "I2C SCAN");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_34
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_34 = obj;
            lv_obj_set_pos(obj, 35, 327);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_34
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_34 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_34
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_34 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "EEPROM CHECK");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_37
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_37 = obj;
            lv_obj_set_pos(obj, 35, 420);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_37
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_37 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_37
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_37 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "SYSTEMDIAGNOSE");
                        }
                    }
                }
            }
        }
        {
            // questionContainer_8
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.question_container_8 = obj;
            lv_obj_set_pos(obj, 410, 9);
            lv_obj_set_size(obj, 70, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj103 = obj;
                    lv_obj_set_pos(obj, 8, 5);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_debug_obj103, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj149 = obj;
                            lv_obj_set_pos(obj, -1, 10);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "->");
                        }
                    }
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_DEBUG - 1);
    
    tick_screen_adminoptionen1_system_debug();
}

void delete_screen_adminoptionen1_system_debug() {
    lv_obj_del(objects.adminoptionen1_system_debug);
    objects.adminoptionen1_system_debug = 0;
    objects.obj37 = 0;
    objects.obj146 = 0;
    objects.obj102 = 0;
    objects.switch_container_7 = 0;
    objects.obj147 = 0;
    objects.switch_title_7 = 0;
    objects.switch_container_4 = 0;
    objects.obj148 = 0;
    objects.switch_title_4 = 0;
    objects.button_container_28 = 0;
    objects.button_28 = 0;
    objects.button_title_28 = 0;
    objects.button_container_30 = 0;
    objects.button_30 = 0;
    objects.button_title_30 = 0;
    objects.button_container_34 = 0;
    objects.button_34 = 0;
    objects.button_title_34 = 0;
    objects.button_container_37 = 0;
    objects.button_37 = 0;
    objects.button_title_37 = 0;
    objects.question_container_8 = 0;
    objects.obj103 = 0;
    objects.obj149 = 0;
    deletePageFlowState(37);
}

void tick_screen_adminoptionen1_system_debug() {
    void *flowState = getFlowState(0, 37);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 121);
}

void create_screen_adminoptionen1_system_debug2() {
    void *flowState = getFlowState(0, 38);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_debug2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj38 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 123);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj150 = obj;
            lv_obj_set_pos(obj, 145, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "DEBUG");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj104 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_debug2_obj104, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // buttonContainer_46
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_46 = obj;
            lv_obj_set_pos(obj, 35, 92);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_46
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_46 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_debug2_button_46, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_46
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_46 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "TESTS");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_50
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_50 = obj;
            lv_obj_set_pos(obj, 35, 152);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_50
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_50 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_50
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_50 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "LOG - SD EXPORT");
                        }
                    }
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_DEBUG2 - 1);
    
    tick_screen_adminoptionen1_system_debug2();
}

void delete_screen_adminoptionen1_system_debug2() {
    lv_obj_del(objects.adminoptionen1_system_debug2);
    objects.adminoptionen1_system_debug2 = 0;
    objects.obj38 = 0;
    objects.obj150 = 0;
    objects.obj104 = 0;
    objects.button_container_46 = 0;
    objects.button_46 = 0;
    objects.button_title_46 = 0;
    objects.button_container_50 = 0;
    objects.button_50 = 0;
    objects.button_title_50 = 0;
    deletePageFlowState(38);
}

void tick_screen_adminoptionen1_system_debug2() {
    void *flowState = getFlowState(0, 38);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 123);
}

void create_screen_adminoptionen1_system_debug2_tests() {
    void *flowState = getFlowState(0, 39);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_debug2_tests = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj39 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 125);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj151 = obj;
            lv_obj_set_pos(obj, 154, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "TESTS");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj105 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_debug2_tests_obj105, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // buttonContainer_47
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_47 = obj;
            lv_obj_set_pos(obj, 35, 92);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_47
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_47 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_47
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_47 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "DISPLAYS/ESP");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_48
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_48 = obj;
            lv_obj_set_pos(obj, 35, 152);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_48
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_48 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_48
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_48 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "RS485/ARDUINO");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_49
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_49 = obj;
            lv_obj_set_pos(obj, 35, 212);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_49
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_49 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_debug2_tests_button_49, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_49
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_49 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "LED RING");
                        }
                    }
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_DEBUG2_TESTS - 1);
    
    tick_screen_adminoptionen1_system_debug2_tests();
}

void delete_screen_adminoptionen1_system_debug2_tests() {
    lv_obj_del(objects.adminoptionen1_system_debug2_tests);
    objects.adminoptionen1_system_debug2_tests = 0;
    objects.obj39 = 0;
    objects.obj151 = 0;
    objects.obj105 = 0;
    objects.button_container_47 = 0;
    objects.button_47 = 0;
    objects.button_title_47 = 0;
    objects.button_container_48 = 0;
    objects.button_48 = 0;
    objects.button_title_48 = 0;
    objects.button_container_49 = 0;
    objects.button_49 = 0;
    objects.button_title_49 = 0;
    deletePageFlowState(39);
}

void tick_screen_adminoptionen1_system_debug2_tests() {
    void *flowState = getFlowState(0, 39);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 125);
}

void create_screen_adminoptionen1_system2() {
    void *flowState = getFlowState(0, 40);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj40 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 127);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj152 = obj;
            lv_obj_set_pos(obj, 129, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "SYSTEM");
        }
        {
            // buttonContainer_38
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_38 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_38
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_38 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_38
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_38 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "NEUSTART");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_40
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_40 = obj;
            lv_obj_set_pos(obj, 35, 360);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_40
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_40 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system2_button_40, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_40
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_40 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "PROFIL");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_39
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_39 = obj;
            lv_obj_set_pos(obj, 35, 420);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_39
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_39 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system2_button_39, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_39
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_39 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "WERKEINSTELLUNG");
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj106 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system2_obj106, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM2 - 1);
    
    tick_screen_adminoptionen1_system2();
}

void delete_screen_adminoptionen1_system2() {
    lv_obj_del(objects.adminoptionen1_system2);
    objects.adminoptionen1_system2 = 0;
    objects.obj40 = 0;
    objects.obj152 = 0;
    objects.button_container_38 = 0;
    objects.button_38 = 0;
    objects.button_title_38 = 0;
    objects.button_container_40 = 0;
    objects.button_40 = 0;
    objects.button_title_40 = 0;
    objects.button_container_39 = 0;
    objects.button_39 = 0;
    objects.button_title_39 = 0;
    objects.obj106 = 0;
    deletePageFlowState(40);
}

void tick_screen_adminoptionen1_system2() {
    void *flowState = getFlowState(0, 40);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 127);
}

void create_screen_adminoptionen1_system2_profil() {
    void *flowState = getFlowState(0, 41);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system2_profil = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj41 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 129);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj153 = obj;
            lv_obj_set_pos(obj, 129, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "PROFIL");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj107 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system2_profil_obj107, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // buttonContainer_41
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_41 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_41
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_41 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_41
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_41 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "PROFIL:");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_43
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_43 = obj;
            lv_obj_set_pos(obj, 35, 147);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_43
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_43 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system2_profil_button_43, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_43
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_43 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "PROFIL LADEN");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_42
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_42 = obj;
            lv_obj_set_pos(obj, 35, 207);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_42
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_42 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system2_profil_button_42, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_42
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_42 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "PROFIL SPEICHERN");
                        }
                    }
                }
            }
        }
        {
            // checkboxContatiner_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.checkbox_contatiner_3 = obj;
            lv_obj_set_pos(obj, 35, 420);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 50);
                    add_style_gold_panel(obj);
                }
                {
                    // checkbox_3
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.checkbox_3 = obj;
                    lv_obj_set_pos(obj, 20, 11);
                    lv_obj_set_size(obj, 370, 38);
                    lv_checkbox_set_text(obj, "");
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffff2bc), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 150, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdd111), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_CHECKED);
                }
                {
                    // checkboxTitle_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.checkbox_title_3 = obj;
                    lv_obj_set_pos(obj, 56, 11);
                    lv_obj_set_size(obj, 348, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "BACKUP BEI NEUSTART");
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM2_PROFIL - 1);
    
    tick_screen_adminoptionen1_system2_profil();
}

void delete_screen_adminoptionen1_system2_profil() {
    lv_obj_del(objects.adminoptionen1_system2_profil);
    objects.adminoptionen1_system2_profil = 0;
    objects.obj41 = 0;
    objects.obj153 = 0;
    objects.obj107 = 0;
    objects.button_container_41 = 0;
    objects.button_41 = 0;
    objects.button_title_41 = 0;
    objects.button_container_43 = 0;
    objects.button_43 = 0;
    objects.button_title_43 = 0;
    objects.button_container_42 = 0;
    objects.button_42 = 0;
    objects.button_title_42 = 0;
    objects.checkbox_contatiner_3 = 0;
    objects.checkbox_3 = 0;
    objects.checkbox_title_3 = 0;
    deletePageFlowState(41);
}

void tick_screen_adminoptionen1_system2_profil() {
    void *flowState = getFlowState(0, 41);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 129);
}

void create_screen_adminoptionen1_system2_profil_profilladen() {
    void *flowState = getFlowState(0, 42);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system2_profil_profilladen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj42 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 131);
        }
        {
            // chooseRoller_3
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.choose_roller_3 = obj;
            lv_obj_set_pos(obj, 122, 117);
            lv_obj_set_size(obj, 236, 246);
            lv_roller_set_options(obj, "", LV_ROLLER_MODE_INFINITE);
            add_style_gold_sel_braun(obj);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj108 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system2_profil_profilladen_obj108, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj109 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system2_profil_profilladen_obj109, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 3);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "AUSWAEHLEN");
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM2_PROFIL_PROFILLADEN - 1);
    
    tick_screen_adminoptionen1_system2_profil_profilladen();
}

void delete_screen_adminoptionen1_system2_profil_profilladen() {
    lv_obj_del(objects.adminoptionen1_system2_profil_profilladen);
    objects.adminoptionen1_system2_profil_profilladen = 0;
    objects.obj42 = 0;
    objects.choose_roller_3 = 0;
    objects.obj108 = 0;
    objects.obj109 = 0;
    deletePageFlowState(42);
}

void tick_screen_adminoptionen1_system2_profil_profilladen() {
    void *flowState = getFlowState(0, 42);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 131);
}

void create_screen_adminoptionen1_bonus() {
    void *flowState = getFlowState(0, 43);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_bonus = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_bonus_adminoptionen1_bonus, LV_EVENT_ALL, flowState);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj43 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 133);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj154 = obj;
            lv_obj_set_pos(obj, 149, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "BONUS");
        }
        {
            // buttonContainer_7
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_7 = obj;
            lv_obj_set_pos(obj, 35, 87);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_7
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_7 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_bonus_button_7, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_7
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_7 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "JOKER TREFFEN");
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj110 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_bonus_obj110, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_BONUS - 1);
    
    tick_screen_adminoptionen1_bonus();
}

void delete_screen_adminoptionen1_bonus() {
    lv_obj_del(objects.adminoptionen1_bonus);
    objects.adminoptionen1_bonus = 0;
    objects.obj43 = 0;
    objects.obj154 = 0;
    objects.button_container_7 = 0;
    objects.button_7 = 0;
    objects.button_title_7 = 0;
    objects.obj110 = 0;
    deletePageFlowState(43);
}

void tick_screen_adminoptionen1_bonus() {
    void *flowState = getFlowState(0, 43);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 133);
}

void create_screen_optionen_template() {
    void *flowState = getFlowState(0, 44);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.optionen_template = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj44 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 135);
        }
        {
            // switchContainer
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.switch_container = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 50);
                    add_style_gold_panel(obj);
                }
                {
                    lv_obj_t *obj = lv_switch_create(parent_obj);
                    objects.obj155 = obj;
                    lv_obj_set_pos(obj, 17, 13);
                    lv_obj_set_size(obj, 73, 34);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
                }
                {
                    // switchTitle
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.switch_title = obj;
                    lv_obj_set_pos(obj, 86, 11);
                    lv_obj_set_size(obj, 319, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "switchTitle");
                }
            }
        }
        {
            // checkboxContatiner
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.checkbox_contatiner = obj;
            lv_obj_set_pos(obj, 0, 60);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 50);
                    add_style_gold_panel(obj);
                }
                {
                    // checkbox
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.checkbox = obj;
                    lv_obj_set_pos(obj, 20, 11);
                    lv_obj_set_size(obj, 370, 38);
                    lv_checkbox_set_text(obj, "");
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffff2bc), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 150, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdd111), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_INDICATOR | LV_STATE_CHECKED);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_CHECKED);
                }
                {
                    // checkboxTitle
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.checkbox_title = obj;
                    lv_obj_set_pos(obj, 56, 11);
                    lv_obj_set_size(obj, 348, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "checkboxTitle");
                }
            }
        }
        {
            // sliderContainer
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.slider_container = obj;
            lv_obj_set_pos(obj, 0, 120);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 80);
                    add_style_gold_panel(obj);
                }
                {
                    // sliderTitle
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title = obj;
                    lv_obj_set_pos(obj, 7, 12);
                    lv_obj_set_size(obj, 396, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "sliderTitle");
                }
                {
                    // slider
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_value(obj, 100, LV_ANIM_OFF);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_KNOB | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // buttonContainer
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container = obj;
            lv_obj_set_pos(obj, 0, 210);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "buttonTitle");
                        }
                    }
                }
            }
        }
        {
            // questionContainer
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.question_container = obj;
            lv_obj_set_pos(obj, 410, 0);
            lv_obj_set_size(obj, 70, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj156 = obj;
                    lv_obj_set_pos(obj, 8, 5);
                    lv_obj_set_size(obj, 50, 50);
                    add_style_gold(obj);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj157 = obj;
                            lv_obj_set_pos(obj, -1, 10);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "?");
                        }
                    }
                }
            }
        }
        {
            // questionContainer_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.question_container_1 = obj;
            lv_obj_set_pos(obj, 410, 60);
            lv_obj_set_size(obj, 70, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj111 = obj;
                    lv_obj_set_pos(obj, 8, 5);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_optionen_template_obj111, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj158 = obj;
                            lv_obj_set_pos(obj, -1, 10);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "1");
                        }
                    }
                }
            }
        }
        {
            // questionContainer_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.question_container_2 = obj;
            lv_obj_set_pos(obj, 410, 125);
            lv_obj_set_size(obj, 70, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj112 = obj;
                    lv_obj_set_pos(obj, 8, 5);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_optionen_template_obj112, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj159 = obj;
                            lv_obj_set_pos(obj, -1, 10);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "2");
                        }
                    }
                }
            }
        }
        {
            // questionContainer_6
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.question_container_6 = obj;
            lv_obj_set_pos(obj, 408, 345);
            lv_obj_set_size(obj, 70, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.obj113 = obj;
                    lv_obj_set_pos(obj, 8, 5);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_optionen_template_obj113, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj160 = obj;
                            lv_obj_set_pos(obj, -1, 10);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "->");
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj114 = obj;
            lv_obj_set_pos(obj, 418, 418);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_optionen_template_obj114, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_OPTIONEN_TEMPLATE - 1);
    
    tick_screen_optionen_template();
}

void delete_screen_optionen_template() {
    lv_obj_del(objects.optionen_template);
    objects.optionen_template = 0;
    objects.obj44 = 0;
    objects.switch_container = 0;
    objects.obj155 = 0;
    objects.switch_title = 0;
    objects.checkbox_contatiner = 0;
    objects.checkbox = 0;
    objects.checkbox_title = 0;
    objects.slider_container = 0;
    objects.slider_title = 0;
    objects.slider = 0;
    objects.button_container = 0;
    objects.button = 0;
    objects.button_title = 0;
    objects.question_container = 0;
    objects.obj156 = 0;
    objects.obj157 = 0;
    objects.question_container_1 = 0;
    objects.obj111 = 0;
    objects.obj158 = 0;
    objects.question_container_2 = 0;
    objects.obj112 = 0;
    objects.obj159 = 0;
    objects.question_container_6 = 0;
    objects.obj113 = 0;
    objects.obj160 = 0;
    objects.obj114 = 0;
    deletePageFlowState(44);
}

void tick_screen_optionen_template() {
    void *flowState = getFlowState(0, 44);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 135);
}

void create_screen_optionen_template_2() {
    void *flowState = getFlowState(0, 45);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.optionen_template_2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj45 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_background(obj, getFlowState(flowState, 0), 137);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj115 = obj;
            lv_obj_set_pos(obj, 418, 418);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_optionen_template_2_obj115, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // dropdownContainer_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 410, 90);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_1
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_1 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "rollerTitle");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "Option 1\nOption 2\nOption 3");
                    lv_dropdown_set_selected(obj, 0);
                    add_style_gold_dropdown_(obj);
                }
            }
        }
        {
            // rollerContainer_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.roller_container_2 = obj;
            lv_obj_set_pos(obj, 0, 90);
            lv_obj_set_size(obj, 410, 150);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // rollerTitle_2
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_2 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "rollerTitle");
                        }
                    }
                }
                {
                    // roller_2
                    lv_obj_t *obj = lv_roller_create(parent_obj);
                    objects.roller_2 = obj;
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 110);
                    lv_roller_set_options(obj, "Option 1\nOption 2\nOption 3", LV_ROLLER_MODE_NORMAL);
                    add_style_gold_sel_braun(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_OPTIONEN_TEMPLATE_2 - 1);
    
    tick_screen_optionen_template_2();
}

void delete_screen_optionen_template_2() {
    lv_obj_del(objects.optionen_template_2);
    objects.optionen_template_2 = 0;
    objects.obj45 = 0;
    objects.obj115 = 0;
    objects.dropdown_container_2 = 0;
    objects.roller_title_1 = 0;
    objects.roller_container_2 = 0;
    objects.roller_title_2 = 0;
    objects.roller_2 = 0;
    deletePageFlowState(45);
}

void tick_screen_optionen_template_2() {
    void *flowState = getFlowState(0, 45);
    (void)flowState;
    tick_user_widget_background(getFlowState(flowState, 0), 137);
}

void create_user_widget_background(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -29, -18);
                    lv_obj_set_size(obj, 262, 480);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    add_style_bg_left(obj);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 222, -18);
                    lv_obj_set_size(obj, 251, 480);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    add_style_bg_right(obj);
                }
            }
        }
    }
}

void tick_user_widget_background(void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
}

void create_user_widget_button(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // buttonContainer
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 410, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_user_widget_button(void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
}

void create_user_widget_info_widget(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // newsContainer_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 40);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // newsPanel_1
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                    lv_obj_set_pos(obj, -5, 0);
                    lv_obj_set_size(obj, 490, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // news_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                    lv_obj_set_pos(obj, 3, 4);
                    lv_obj_set_size(obj, 475, 36);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
    }
}

void tick_user_widget_info_widget(void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    {
        bool new_val = evalBooleanProperty(flowState, 1, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 0], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 0];
            if (new_val) lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 0], LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(((lv_obj_t **)&objects)[startWidgetIndex + 0], LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 2, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 2]);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 2];
            lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 2], new_val);
            tick_value_change_obj = NULL;
        }
    }
}


extern void add_style(lv_obj_t *obj, int32_t styleIndex);
extern void remove_style(lv_obj_t *obj, int32_t styleIndex);

static const char *screen_names[] = { "idleScreen", "logoScreen", "loadingScreen", "menuScreen", "choosePlayerScreen", "chooseGameScreen", "chooseGameMod", "keyboardScreen", "numpadScreen", "okayScreen", "game_lichtloser", "gameWin", "gameLose", "useroptionen1", "useroptionen1_spiele", "useroptionen1_spiele_lichtloser", "adminoptionen1", "adminoptionen1_spiele", "adminoptionen1_spiele_lichtloser", "adminoptionen1_spiele_lichtloser_joker", "adminoptionen1_spiele_lichtloser_timings", "adminoptionen1_farbeneffekte", "adminoptionen1_farbeneffekte_winlose", "adminoptionen1_farbeneffekte_spielerfarbe", "adminoptionen1_farbeneffekte_grenzfarbe", "adminoptionen1_system", "adminoptionen1_system_leds", "adminoptionen1_system_leds_helligkeit", "adminoptionen1_system_anzeige", "adminoptionen1_system_anzeige_idle", "adminoptionen1_system_audio", "adminoptionen1_system_netzwerk", "adminoptionen1_system_netzwerk_wifi", "adminoptionen1_system_netzwerk_kommunikation", "adminoptionen1_system_netzwerk_update", "adminoptionen1_system_netzwerk_update_manifest", "adminoptionen1_system_netzwerk_update_firmware", "adminoptionen1_system_debug", "adminoptionen1_system_debug2", "adminoptionen1_system_debug2_tests", "adminoptionen1_system2", "adminoptionen1_system2_profil", "adminoptionen1_system2_profil_profilladen", "adminoptionen1_bonus", "optionenTemplate", "optionenTemplate_2" };
static const char *object_names[] = { "idle_screen", "logo_screen", "loading_screen", "menu_screen", "choose_player_screen", "choose_game_screen", "choose_game_mod", "keyboard_screen", "numpad_screen", "okay_screen", "game_lichtloser", "game_win", "game_lose", "useroptionen1", "useroptionen1_spiele", "useroptionen1_spiele_lichtloser", "adminoptionen1", "adminoptionen1_spiele", "adminoptionen1_spiele_lichtloser", "adminoptionen1_spiele_lichtloser_joker", "adminoptionen1_spiele_lichtloser_timings", "adminoptionen1_farbeneffekte", "adminoptionen1_farbeneffekte_winlose", "adminoptionen1_farbeneffekte_spielerfarbe", "adminoptionen1_farbeneffekte_grenzfarbe", "adminoptionen1_system", "adminoptionen1_system_leds", "adminoptionen1_system_leds_helligkeit", "adminoptionen1_system_anzeige", "adminoptionen1_system_anzeige_idle", "adminoptionen1_system_audio", "adminoptionen1_system_netzwerk", "adminoptionen1_system_netzwerk_wifi", "adminoptionen1_system_netzwerk_kommunikation", "adminoptionen1_system_netzwerk_update", "adminoptionen1_system_netzwerk_update_manifest", "adminoptionen1_system_netzwerk_update_firmware", "adminoptionen1_system_debug", "adminoptionen1_system_debug2", "adminoptionen1_system_debug2_tests", "adminoptionen1_system2", "adminoptionen1_system2_profil", "adminoptionen1_system2_profil_profilladen", "adminoptionen1_bonus", "optionen_template", "optionen_template_2", "obj0", "obj0__background_panel_1", "obj1", "obj1__background_panel_1", "obj2", "obj2__background_panel_1", "obj3", "obj3__background_panel_1", "obj4", "obj4__background_panel_1", "obj5", "obj5__background_panel_1", "obj6", "obj6__background_panel_1", "obj7", "obj7__background_panel_1", "obj8", "obj8__background_panel_1", "obj9", "obj9__background_panel_1", "obj10", "obj10__background_panel_1", "obj11", "obj11__background_panel_1", "obj12", "obj12__background_panel_1", "obj13", "obj13__background_panel_1", "obj14", "obj14__background_panel_1", "obj15", "obj15__background_panel_1", "obj16", "obj16__background_panel_1", "obj17", "obj17__background_panel_1", "obj18", "obj18__background_panel_1", "obj19", "obj19__background_panel_1", "obj20", "obj20__background_panel_1", "obj21", "obj21__background_panel_1", "obj22", "obj22__background_panel_1", "obj23", "obj23__background_panel_1", "obj24", "obj24__background_panel_1", "obj25", "obj25__background_panel_1", "obj26", "obj26__background_panel_1", "obj27", "obj27__background_panel_1", "obj28", "obj28__background_panel_1", "obj29", "obj29__background_panel_1", "obj30", "obj30__background_panel_1", "obj31", "obj31__background_panel_1", "obj32", "obj32__background_panel_1", "obj33", "obj33__background_panel_1", "obj34", "obj34__background_panel_1", "obj35", "obj35__background_panel_1", "obj36", "obj36__background_panel_1", "obj37", "obj37__background_panel_1", "obj38", "obj38__background_panel_1", "obj39", "obj39__background_panel_1", "obj40", "obj40__background_panel_1", "obj41", "obj41__background_panel_1", "obj42", "obj42__background_panel_1", "obj43", "obj43__background_panel_1", "obj44", "obj44__background_panel_1", "obj45", "obj45__background_panel_1", "obj46", "start", "optionen", "optionen_1", "player_roller", "obj47", "obj48", "obj49", "game_roller", "obj50", "obj51", "obj52", "obj53", "obj54", "obj55", "obj56", "score_player1", "score_panel1", "score1", "score_player2", "score_panel2", "score2", "score_player3", "score_panel3", "score3", "score_player4", "score_panel4", "score4", "score_player5", "score_panel5", "score5", "score_player6", "score_panel6", "score6", "obj57", "button_game", "obj58", "obj59", "button_10", "obj60", "obj61", "options_game_roller", "obj62", "obj63", "button_3", "button_5", "button_6", "button_9", "obj64", "obj65", "options_game_roller_1", "obj66", "obj67", "slider_lichtloserrounds", "button_1", "button_4", "obj68", "obj69", "obj70", "obj71", "obj72", "button_24", "button_25", "button_26", "obj73", "obj74", "obj75", "obj76", "obj77", "obj78", "obj79", "checkbox_2", "obj80", "obj81", "obj82", "obj83", "obj84", "button_12", "button_13", "button_16", "button_14", "button_15", "obj85", "obj86", "button_18", "obj87", "obj88", "slider_2", "slider_3", "obj89", "slider_4", "button_29", "obj90", "obj91", "obj92", "obj93", "obj94", "checkbox_1", "obj95", "obj96", "button_19", "button_22", "button_23", "obj97", "obj98", "obj99", "button_44", "button_31", "obj100", "obj101", "obj102", "obj103", "obj104", "button_46", "obj105", "button_49", "button_40", "button_39", "obj106", "obj107", "button_43", "button_42", "obj108", "obj109", "button_7", "obj110", "obj111", "obj112", "obj113", "obj114", "obj115", "start_idle", "version", "logo", "obj116", "news_container", "news_panel", "news", "obj117", "obj118", "obj119", "game_roller_5", "keyboard_area", "keyboard", "keyboard_title", "numpad_area", "numpad", "numpad_title", "ja_panel", "nein_panel", "scores", "button_container_2", "button_title_2", "win_lose_container", "win_container", "win_panel", "lose_anzeige_panel", "lose_anzeige_title", "win_lose_container_1", "win_container_1", "lose_panel", "win_anzeige_panel", "lose_anzeige_title_1", "obj120", "button_container_10", "button_title_10", "obj121", "dropdown_container_22", "roller_title_22", "obj122", "button_container_3", "button_title_3", "button_container_5", "button_title_5", "button_container_6", "button_title_6", "button_container_9", "button_title_9", "obj123", "dropdown_container_19", "roller_title_19", "slider_container_1", "slider_title_7", "slider_title_1", "button_container_1", "button_title_1", "button_container_4", "button_title_4", "obj124", "switch_container_1", "switch_title_1", "dropdown_container_3", "roller_title_3", "obj125", "slider_container_7", "slider_title_11", "slider_7", "slider_title_12", "slider_title_13", "slider_title_14", "slider_container_8", "slider_title_15", "slider_8", "slider_title_16", "slider_title_17", "slider_title_18", "slider_container_9", "slider_title_19", "slider_9", "slider_title_20", "slider_title_21", "slider_title_22", "slider_container_10", "slider_title_23", "slider_1", "slider_title_24", "slider_title_25", "obj126", "button_container_24", "button_title_24", "button_container_25", "button_title_25", "button_container_26", "button_title_26", "obj127", "dropdown_container_5", "roller_title_5", "dropdown_container_6", "roller_title_6", "dropdown_container_7", "roller_title_7", "dropdown_container_8", "roller_title_8", "obj128", "dropdown_container_9", "roller_title_9", "dropdown_container_10", "roller_title_10", "checkbox_contatiner_2", "checkbox_title_2", "dropdown_container_17", "roller_title_17", "obj129", "dropdown_container_11", "roller_title_11", "dropdown_container_12", "roller_title_12", "obj130", "button_container_12", "button_title_12", "button_container_13", "button_title_13", "button_container_16", "button_title_16", "button_container_14", "button_title_14", "button_container_15", "button_title_15", "question_container_7", "obj131", "obj132", "button_container_18", "button_title_18", "obj133", "slider_container_2", "slider_title_2", "slider_title_8", "slider_container_3", "slider_title_3", "slider_title_9", "obj134", "slider_container_4", "slider_title_4", "slider_title_10", "button_container_29", "button_title_29", "obj135", "switch_container_2", "switch_title_2", "dropdown_container_4", "roller_title_4", "checkbox_contatiner_1", "checkbox_title_1", "obj136", "switch_container_5", "obj137", "switch_title_5", "slider_container_5", "slider_title_5", "slider_5", "switch_container_6", "obj138", "switch_title_6", "slider_container_6", "slider_title_6", "slider_6", "button_container_17", "button_17", "button_title_17", "obj139", "button_container_19", "button_title_19", "button_container_22", "button_title_22", "button_container_23", "button_title_23", "obj140", "switch_container_3", "obj141", "switch_title_3", "button_container_20", "button_20", "button_title_20", "button_container_21", "button_21", "button_title_21", "button_container_36", "button_36", "button_title_36", "obj142", "dropdown_container_13", "roller_title_13", "dropdown_container_14", "roller_title_14", "dropdown_container_15", "roller_title_15", "obj143", "dropdown_container_16", "roller_title_16", "button_container_27", "button_27", "button_title_27", "button_container_33", "button_33", "button_title_33", "button_container_44", "button_title_44", "button_container_31", "button_title_31", "obj144", "button_container_51", "button_51", "button_title_51", "button_container_52", "button_52", "button_title_52", "button_container_53", "button_53", "button_title_53", "button_container_54", "button_54", "button_title_54", "button_container_55", "button_55", "button_title_55", "button_container_56", "button_56", "button_title_56", "button_container_57", "button_57", "button_title_57", "button_container_58", "button_58", "button_title_58", "obj145", "button_container_32", "button_32", "button_title_32", "obj146", "switch_container_7", "obj147", "switch_title_7", "switch_container_4", "obj148", "switch_title_4", "button_container_28", "button_28", "button_title_28", "button_container_30", "button_30", "button_title_30", "button_container_34", "button_34", "button_title_34", "button_container_37", "button_37", "button_title_37", "question_container_8", "obj149", "obj150", "button_container_46", "button_title_46", "button_container_50", "button_50", "button_title_50", "obj151", "button_container_47", "button_47", "button_title_47", "button_container_48", "button_48", "button_title_48", "button_container_49", "button_title_49", "obj152", "button_container_38", "button_38", "button_title_38", "button_container_40", "button_title_40", "button_container_39", "button_title_39", "obj153", "button_container_41", "button_41", "button_title_41", "button_container_43", "button_title_43", "button_container_42", "button_title_42", "checkbox_contatiner_3", "checkbox_3", "checkbox_title_3", "choose_roller_3", "obj154", "button_container_7", "button_title_7", "switch_container", "obj155", "switch_title", "checkbox_contatiner", "checkbox", "checkbox_title", "slider_container", "slider_title", "slider", "button_container", "button", "button_title", "question_container", "obj156", "obj157", "question_container_1", "obj158", "question_container_2", "obj159", "question_container_6", "obj160", "dropdown_container_2", "roller_title_1", "roller_container_2", "roller_title_2", "roller_2" };
static const char *style_names[] = { "Gold", "Braun", "GoldSelBraun", "GoldTextArea", "GoldKeyboard", "goldPanel", "GoldDropdown^", "BG-left", "BG-right" };


typedef void (*create_screen_func_t)();
create_screen_func_t create_screen_funcs[] = {
    create_screen_idle_screen,
    create_screen_logo_screen,
    create_screen_loading_screen,
    create_screen_menu_screen,
    create_screen_choose_player_screen,
    create_screen_choose_game_screen,
    create_screen_choose_game_mod,
    create_screen_keyboard_screen,
    create_screen_numpad_screen,
    create_screen_okay_screen,
    create_screen_game_lichtloser,
    create_screen_game_win,
    create_screen_game_lose,
    create_screen_useroptionen1,
    create_screen_useroptionen1_spiele,
    create_screen_useroptionen1_spiele_lichtloser,
    create_screen_adminoptionen1,
    create_screen_adminoptionen1_spiele,
    create_screen_adminoptionen1_spiele_lichtloser,
    create_screen_adminoptionen1_spiele_lichtloser_joker,
    create_screen_adminoptionen1_spiele_lichtloser_timings,
    create_screen_adminoptionen1_farbeneffekte,
    create_screen_adminoptionen1_farbeneffekte_winlose,
    create_screen_adminoptionen1_farbeneffekte_spielerfarbe,
    create_screen_adminoptionen1_farbeneffekte_grenzfarbe,
    create_screen_adminoptionen1_system,
    create_screen_adminoptionen1_system_leds,
    create_screen_adminoptionen1_system_leds_helligkeit,
    create_screen_adminoptionen1_system_anzeige,
    create_screen_adminoptionen1_system_anzeige_idle,
    create_screen_adminoptionen1_system_audio,
    create_screen_adminoptionen1_system_netzwerk,
    create_screen_adminoptionen1_system_netzwerk_wifi,
    create_screen_adminoptionen1_system_netzwerk_kommunikation,
    create_screen_adminoptionen1_system_netzwerk_update,
    create_screen_adminoptionen1_system_netzwerk_update_manifest,
    create_screen_adminoptionen1_system_netzwerk_update_firmware,
    create_screen_adminoptionen1_system_debug,
    create_screen_adminoptionen1_system_debug2,
    create_screen_adminoptionen1_system_debug2_tests,
    create_screen_adminoptionen1_system2,
    create_screen_adminoptionen1_system2_profil,
    create_screen_adminoptionen1_system2_profil_profilladen,
    create_screen_adminoptionen1_bonus,
    create_screen_optionen_template,
    create_screen_optionen_template_2,
};
void create_screen(int screen_index) {
    create_screen_funcs[screen_index]();
}
void create_screen_by_id(enum ScreensEnum screenId) {
    create_screen_funcs[screenId - 1]();
}

typedef void (*delete_screen_func_t)();
delete_screen_func_t delete_screen_funcs[] = {
    delete_screen_idle_screen,
    delete_screen_logo_screen,
    delete_screen_loading_screen,
    delete_screen_menu_screen,
    delete_screen_choose_player_screen,
    delete_screen_choose_game_screen,
    delete_screen_choose_game_mod,
    delete_screen_keyboard_screen,
    delete_screen_numpad_screen,
    delete_screen_okay_screen,
    delete_screen_game_lichtloser,
    delete_screen_game_win,
    delete_screen_game_lose,
    delete_screen_useroptionen1,
    delete_screen_useroptionen1_spiele,
    delete_screen_useroptionen1_spiele_lichtloser,
    delete_screen_adminoptionen1,
    delete_screen_adminoptionen1_spiele,
    delete_screen_adminoptionen1_spiele_lichtloser,
    delete_screen_adminoptionen1_spiele_lichtloser_joker,
    delete_screen_adminoptionen1_spiele_lichtloser_timings,
    delete_screen_adminoptionen1_farbeneffekte,
    delete_screen_adminoptionen1_farbeneffekte_winlose,
    delete_screen_adminoptionen1_farbeneffekte_spielerfarbe,
    delete_screen_adminoptionen1_farbeneffekte_grenzfarbe,
    delete_screen_adminoptionen1_system,
    delete_screen_adminoptionen1_system_leds,
    delete_screen_adminoptionen1_system_leds_helligkeit,
    delete_screen_adminoptionen1_system_anzeige,
    delete_screen_adminoptionen1_system_anzeige_idle,
    delete_screen_adminoptionen1_system_audio,
    delete_screen_adminoptionen1_system_netzwerk,
    delete_screen_adminoptionen1_system_netzwerk_wifi,
    delete_screen_adminoptionen1_system_netzwerk_kommunikation,
    delete_screen_adminoptionen1_system_netzwerk_update,
    delete_screen_adminoptionen1_system_netzwerk_update_manifest,
    delete_screen_adminoptionen1_system_netzwerk_update_firmware,
    delete_screen_adminoptionen1_system_debug,
    delete_screen_adminoptionen1_system_debug2,
    delete_screen_adminoptionen1_system_debug2_tests,
    delete_screen_adminoptionen1_system2,
    delete_screen_adminoptionen1_system2_profil,
    delete_screen_adminoptionen1_system2_profil_profilladen,
    delete_screen_adminoptionen1_bonus,
    delete_screen_optionen_template,
    delete_screen_optionen_template_2,
};
void delete_screen(int screen_index) {
    delete_screen_funcs[screen_index]();
}
void delete_screen_by_id(enum ScreensEnum screenId) {
    delete_screen_funcs[screenId - 1]();
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_idle_screen,
    tick_screen_logo_screen,
    tick_screen_loading_screen,
    tick_screen_menu_screen,
    tick_screen_choose_player_screen,
    tick_screen_choose_game_screen,
    tick_screen_choose_game_mod,
    tick_screen_keyboard_screen,
    tick_screen_numpad_screen,
    tick_screen_okay_screen,
    tick_screen_game_lichtloser,
    tick_screen_game_win,
    tick_screen_game_lose,
    tick_screen_useroptionen1,
    tick_screen_useroptionen1_spiele,
    tick_screen_useroptionen1_spiele_lichtloser,
    tick_screen_adminoptionen1,
    tick_screen_adminoptionen1_spiele,
    tick_screen_adminoptionen1_spiele_lichtloser,
    tick_screen_adminoptionen1_spiele_lichtloser_joker,
    tick_screen_adminoptionen1_spiele_lichtloser_timings,
    tick_screen_adminoptionen1_farbeneffekte,
    tick_screen_adminoptionen1_farbeneffekte_winlose,
    tick_screen_adminoptionen1_farbeneffekte_spielerfarbe,
    tick_screen_adminoptionen1_farbeneffekte_grenzfarbe,
    tick_screen_adminoptionen1_system,
    tick_screen_adminoptionen1_system_leds,
    tick_screen_adminoptionen1_system_leds_helligkeit,
    tick_screen_adminoptionen1_system_anzeige,
    tick_screen_adminoptionen1_system_anzeige_idle,
    tick_screen_adminoptionen1_system_audio,
    tick_screen_adminoptionen1_system_netzwerk,
    tick_screen_adminoptionen1_system_netzwerk_wifi,
    tick_screen_adminoptionen1_system_netzwerk_kommunikation,
    tick_screen_adminoptionen1_system_netzwerk_update,
    tick_screen_adminoptionen1_system_netzwerk_update_manifest,
    tick_screen_adminoptionen1_system_netzwerk_update_firmware,
    tick_screen_adminoptionen1_system_debug,
    tick_screen_adminoptionen1_system_debug2,
    tick_screen_adminoptionen1_system_debug2_tests,
    tick_screen_adminoptionen1_system2,
    tick_screen_adminoptionen1_system2_profil,
    tick_screen_adminoptionen1_system2_profil_profilladen,
    tick_screen_adminoptionen1_bonus,
    tick_screen_optionen_template,
    tick_screen_optionen_template_2,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    eez_flow_init_styles(add_style, remove_style);
    
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    eez_flow_init_style_names(style_names, sizeof(style_names) / sizeof(const char *));
    
    eez_flow_set_create_screen_func(create_screen);
    eez_flow_set_delete_screen_func(delete_screen);
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_idle_screen();
}
