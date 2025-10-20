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

static void event_handler_cb_idle_screen_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_menu_screen_start(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_menu_screen_highscore(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_menu_screen_optionen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_choose_player_screen_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_choose_player_screen_obj2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_choose_game_screen_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_choose_game_screen_obj4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_highscore_game_screen_obj5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_highscore_game_screen_obj6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_highscore_screen_obj7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_keyboard_screen_obj8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_numpad_screen_obj9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_okay_screen_obj10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_game1_obj11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 21, 0, e);
    }
}

static void event_handler_cb_game_win_lose_obj12(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_useroptionen1_button_8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_useroptionen1_button_10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_useroptionen1_obj13(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_useroptionen1_spiele_obj14(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_useroptionen1_spiele_obj15(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_useroptionen1_spiele_lichtloser_obj16(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_optionen_quickstart_player_obj17(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_optionen_quickstart_player_obj18(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_optionen_quickstart_game_obj19(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_optionen_quickstart_game_obj20(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_optionen_quickstart_modus_obj21(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_optionen_quickstart_modus_obj22(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_button_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_button_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_button_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_button_6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_button_9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 17, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_obj23(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 19, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_obj24(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_obj25(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_obj26(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_button_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_spiele_lichtloser_joker_obj27(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_button_24(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_button_25(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_button_26(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_obj28(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_winlose_obj29(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_obj30(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_farbeneffekte_grenzfarbe_obj31(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_button_12(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_button_13(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_button_16(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_button_14(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_button_15(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 17, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_obj32(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 19, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_obj33(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 21, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_leds_button_18(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_leds_obj34(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_leds_helligkeit_obj35(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_anzeige_obj36(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
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

static void event_handler_cb_adminoptionen1_system_anzeige_idle_obj37(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_audio_obj38(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_obj39(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_button_19(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_button_22(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_button_23(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_wifi_obj40(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_kommunikation_obj41(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_update_obj42(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_update_button_44(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 16, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_update_button_31(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 19, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_update_manifest_obj43(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_netzwerk_update_firmware_obj44(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_debug_obj45(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_debug_obj46(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 26, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_debug2_obj47(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_debug2_button_46(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system_debug2_tests_obj48(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_button_40(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_button_39(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_obj49(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_profil_obj50(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_profil_button_43(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_profil_button_42(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_profil_profilladen_obj51(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_system2_profil_profilladen_obj52(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_adminoptionen1_bonus_obj53(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_optionen_template_obj54(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 22, 0, e);
    }
}

static void event_handler_cb_optionen_template_obj55(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 25, 0, e);
    }
}

static void event_handler_cb_optionen_template_obj56(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 28, 0, e);
    }
}

static void event_handler_cb_optionen_template_obj57(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 30, 0, e);
    }
}

static void event_handler_cb_optionen_template_2_obj58(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

void create_screen_idle_screen() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.idle_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_1
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_1 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_logo);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 166, 366);
            lv_obj_set_size(obj, 151, 65);
            lv_obj_add_event_cb(obj, event_handler_cb_idle_screen_obj0, LV_EVENT_ALL, flowState);
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
            lv_label_set_text(obj, "version:");
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_IDLE_SCREEN - 1);
    
    tick_screen_idle_screen();
}

void delete_screen_idle_screen() {
    lv_obj_del(objects.idle_screen);
    objects.idle_screen = 0;
    objects.background_panel_1 = 0;
    objects.background_image_1 = 0;
    objects.obj0 = 0;
    objects.start_idle = 0;
    objects.version = 0;
    deletePageFlowState(0);
}

void tick_screen_idle_screen() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
}

void create_screen_loading_screen() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.loading_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_4
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_4 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_4
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_4 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
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
            objects.obj59 = obj;
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
    objects.background_panel_4 = 0;
    objects.background_image_4 = 0;
    objects.logo = 0;
    objects.obj59 = 0;
    deletePageFlowState(1);
}

void tick_screen_loading_screen() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
}

void create_screen_menu_screen() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.menu_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, -16, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_2
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
                    lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
                    lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
                }
            }
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
            lv_obj_set_pos(obj, 100, 119);
            lv_obj_set_size(obj, 280, 121);
            lv_obj_add_event_cb(obj, event_handler_cb_menu_screen_start, LV_EVENT_ALL, flowState);
            add_style_gold(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj60 = obj;
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
            // Highscore
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.highscore = obj;
            lv_obj_set_pos(obj, 134, 273);
            lv_obj_set_size(obj, 212, 63);
            lv_obj_add_event_cb(obj, event_handler_cb_menu_screen_highscore, LV_EVENT_ALL, flowState);
            add_style_braun(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj61 = obj;
                    lv_obj_set_pos(obj, 0, 10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 66);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_point70, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff981313), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff01184a), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "HIGHSCORE");
                }
            }
        }
        {
            // Optionen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.optionen = obj;
            lv_obj_set_pos(obj, 134, 363);
            lv_obj_set_size(obj, 212, 63);
            lv_obj_add_event_cb(obj, event_handler_cb_menu_screen_optionen, LV_EVENT_ALL, flowState);
            add_style_braun(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj62 = obj;
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
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_MENU_SCREEN - 1);
    
    tick_screen_menu_screen();
}

void delete_screen_menu_screen() {
    lv_obj_del(objects.menu_screen);
    objects.menu_screen = 0;
    objects.background_panel_2 = 0;
    objects.background_image_2 = 0;
    objects.news_container = 0;
    objects.news_panel = 0;
    objects.news = 0;
    objects.start = 0;
    objects.obj60 = 0;
    objects.highscore = 0;
    objects.obj61 = 0;
    objects.optionen = 0;
    objects.obj62 = 0;
    deletePageFlowState(2);
}

void tick_screen_menu_screen() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
}

void create_screen_choose_player_screen() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.choose_player_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, -16, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_3
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_3 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
                    lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
                    lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
                }
            }
        }
        {
            // playerRoller
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.player_roller = obj;
            lv_obj_set_pos(obj, 122, 117);
            lv_obj_set_size(obj, 236, 246);
            lv_roller_set_options(obj, "2-Spieler\n3-Spieler\n4-Spieler\n5-Spieler\n6-Spieler", LV_ROLLER_MODE_INFINITE);
            add_style_gold_sel_braun(obj);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_choose_player_screen_obj1, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_choose_player_screen_obj2, LV_EVENT_ALL, flowState);
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
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_CHOOSE_PLAYER_SCREEN - 1);
    
    tick_screen_choose_player_screen();
}

void delete_screen_choose_player_screen() {
    lv_obj_del(objects.choose_player_screen);
    objects.choose_player_screen = 0;
    objects.background_panel_3 = 0;
    objects.background_image_3 = 0;
    objects.player_roller = 0;
    objects.obj1 = 0;
    objects.obj2 = 0;
    deletePageFlowState(3);
}

void tick_screen_choose_player_screen() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
}

void create_screen_choose_game_screen() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.choose_game_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_5
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_5 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, -16, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_5
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_5 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
                    lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
                    lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
                }
            }
        }
        {
            // gameRoller
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.game_roller = obj;
            lv_obj_set_pos(obj, 122, 117);
            lv_obj_set_size(obj, 236, 246);
            lv_roller_set_options(obj, "LichtLoser", LV_ROLLER_MODE_INFINITE);
            add_style_gold_sel_braun(obj);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_choose_game_screen_obj3, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_choose_game_screen_obj4, LV_EVENT_ALL, flowState);
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
    objects.background_panel_5 = 0;
    objects.background_image_5 = 0;
    objects.game_roller = 0;
    objects.obj3 = 0;
    objects.obj4 = 0;
    deletePageFlowState(4);
}

void tick_screen_choose_game_screen() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
}

void create_screen_highscore_game_screen() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.highscore_game_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_6
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_6 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, -16, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_6
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_6 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
                    lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
                    lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
                }
            }
        }
        {
            // highscoreRoller
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.highscore_roller = obj;
            lv_obj_set_pos(obj, 122, 117);
            lv_obj_set_size(obj, 236, 246);
            lv_roller_set_options(obj, "", LV_ROLLER_MODE_INFINITE);
            add_style_gold_sel_braun(obj);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_highscore_game_screen_obj5, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_highscore_game_screen_obj6, LV_EVENT_ALL, flowState);
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
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_HIGHSCORE_GAME_SCREEN - 1);
    
    tick_screen_highscore_game_screen();
}

void delete_screen_highscore_game_screen() {
    lv_obj_del(objects.highscore_game_screen);
    objects.highscore_game_screen = 0;
    objects.background_panel_6 = 0;
    objects.background_image_6 = 0;
    objects.highscore_roller = 0;
    objects.obj5 = 0;
    objects.obj6 = 0;
    deletePageFlowState(5);
}

void tick_screen_highscore_game_screen() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
}

void create_screen_highscore_screen() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.highscore_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_7
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_7 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, -16, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_7
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_7 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
                    lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
                    lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj63 = obj;
            lv_obj_set_pos(obj, 150, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "TOP 10");
        }
        {
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.obj64 = obj;
            lv_obj_set_pos(obj, 10, 105);
            lv_obj_set_size(obj, 460, 350);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_text(obj, "PLATZ       -        DATUM        -        ZEIT\n\n1 -  \n2 -\n3 -\n4 -\n5 -\n6 -\n7 -\n8 -\n9 -\n10 -");
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_WITH_ARROW);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_highscore_screen_obj7, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_HIGHSCORE_SCREEN - 1);
    
    tick_screen_highscore_screen();
}

void delete_screen_highscore_screen() {
    lv_obj_del(objects.highscore_screen);
    objects.highscore_screen = 0;
    objects.background_panel_7 = 0;
    objects.background_image_7 = 0;
    objects.obj63 = 0;
    objects.obj64 = 0;
    objects.obj7 = 0;
    deletePageFlowState(6);
}

void tick_screen_highscore_screen() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
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
            // backgroundPanel_8
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_8 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_8
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_8 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
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
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_keyboard_screen_obj8, LV_EVENT_ALL, flowState);
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
    objects.background_panel_8 = 0;
    objects.background_image_8 = 0;
    objects.keyboard_area = 0;
    objects.keyboard = 0;
    objects.keyboard_title = 0;
    objects.obj8 = 0;
    deletePageFlowState(7);
}

void tick_screen_keyboard_screen() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
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
            // backgroundPanel_9
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_9 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_9
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_9 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
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
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_numpad_screen_obj9, LV_EVENT_ALL, flowState);
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
    objects.background_panel_9 = 0;
    objects.background_image_9 = 0;
    objects.numpad_area = 0;
    objects.numpad = 0;
    objects.numpad_title = 0;
    objects.obj9 = 0;
    deletePageFlowState(8);
}

void tick_screen_numpad_screen() {
    void *flowState = getFlowState(0, 8);
    (void)flowState;
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
            // backgroundPanel_10
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_10 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_10
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_10 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
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
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_okay_screen_obj10, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_OKAY_SCREEN - 1);
    
    tick_screen_okay_screen();
}

void delete_screen_okay_screen() {
    lv_obj_del(objects.okay_screen);
    objects.okay_screen = 0;
    objects.background_panel_10 = 0;
    objects.background_image_10 = 0;
    objects.ja_panel = 0;
    objects.nein_panel = 0;
    objects.obj10 = 0;
    deletePageFlowState(9);
}

void tick_screen_okay_screen() {
    void *flowState = getFlowState(0, 9);
    (void)flowState;
}

void create_screen_game1() {
    void *flowState = getFlowState(0, 10);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.game1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_13
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_13 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_13
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_13 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
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
                    // scorePanel1
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.score_panel1 = obj;
                    lv_obj_set_pos(obj, 210, 418);
                    lv_obj_set_size(obj, 60, 38);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // score1
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.score1 = obj;
                            lv_obj_set_pos(obj, -16, -11);
                            lv_obj_set_size(obj, 56, 35);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "X");
                        }
                    }
                }
                {
                    // scorePlayer2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.score_player2 = obj;
                    lv_obj_set_pos(obj, 353, 312);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "S2");
                }
                {
                    // scorePanel2
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.score_panel2 = obj;
                    lv_obj_set_pos(obj, 331, 270);
                    lv_obj_set_size(obj, 60, 38);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // score2
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.score2 = obj;
                            lv_obj_set_pos(obj, -16, -11);
                            lv_obj_set_size(obj, 56, 35);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "X");
                        }
                    }
                }
                {
                    // scorePlayer3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.score_player3 = obj;
                    lv_obj_set_pos(obj, 353, 215);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "S3");
                }
                {
                    // scorePanel3
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.score_panel3 = obj;
                    lv_obj_set_pos(obj, 331, 174);
                    lv_obj_set_size(obj, 60, 38);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // score3
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.score3 = obj;
                            lv_obj_set_pos(obj, -16, -11);
                            lv_obj_set_size(obj, 56, 35);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "X");
                        }
                    }
                }
                {
                    // scorePlayer4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.score_player4 = obj;
                    lv_obj_set_pos(obj, 232, 60);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "S4");
                }
                {
                    // scorePanel4
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.score_panel4 = obj;
                    lv_obj_set_pos(obj, 210, 18);
                    lv_obj_set_size(obj, 60, 38);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // score4
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.score4 = obj;
                            lv_obj_set_pos(obj, -16, -11);
                            lv_obj_set_size(obj, 56, 35);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "X");
                        }
                    }
                }
                {
                    // scorePlayer5
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.score_player5 = obj;
                    lv_obj_set_pos(obj, 114, 215);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "S5");
                }
                {
                    // scorePanel5
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.score_panel5 = obj;
                    lv_obj_set_pos(obj, 92, 174);
                    lv_obj_set_size(obj, 60, 38);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // score5
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.score5 = obj;
                            lv_obj_set_pos(obj, -16, -11);
                            lv_obj_set_size(obj, 56, 35);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "X");
                        }
                    }
                }
                {
                    // scorePlayer6
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.score_player6 = obj;
                    lv_obj_set_pos(obj, 114, 312);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "S6");
                }
                {
                    // scorePanel6
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.score_panel6 = obj;
                    lv_obj_set_pos(obj, 92, 270);
                    lv_obj_set_size(obj, 60, 38);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // score6
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.score6 = obj;
                            lv_obj_set_pos(obj, -16, -11);
                            lv_obj_set_size(obj, 56, 35);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "X");
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj11 = obj;
            lv_obj_set_pos(obj, -1, 0);
            lv_obj_set_size(obj, 47, 47);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 200);
            lv_obj_add_event_cb(obj, event_handler_cb_game1_obj11, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_GAME1 - 1);
    
    tick_screen_game1();
}

void delete_screen_game1() {
    lv_obj_del(objects.game1);
    objects.game1 = 0;
    objects.background_panel_13 = 0;
    objects.background_image_13 = 0;
    objects.scores = 0;
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
    objects.obj11 = 0;
    deletePageFlowState(10);
}

void tick_screen_game1() {
    void *flowState = getFlowState(0, 10);
    (void)flowState;
}

void create_screen_game_win_lose() {
    void *flowState = getFlowState(0, 11);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.game_win_lose = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc90d0d), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_11
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_11 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_11
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_11 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
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
                    // losePanel
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lose_panel = obj;
                    lv_obj_set_pos(obj, 32, 123);
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
                            lv_obj_set_pos(obj, 32, 135);
                            lv_obj_set_size(obj, 349, 66);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc90d0d), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // loseAnzeigeTitle
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lose_anzeige_title = obj;
                                    lv_obj_set_pos(obj, -2, -7);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                    lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Spieler X hat verloren");
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj12 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_game_win_lose_obj12, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_GAME_WIN_LOSE - 1);
    
    tick_screen_game_win_lose();
}

void delete_screen_game_win_lose() {
    lv_obj_del(objects.game_win_lose);
    objects.game_win_lose = 0;
    objects.background_panel_11 = 0;
    objects.background_image_11 = 0;
    objects.win_lose_container = 0;
    objects.lose_panel = 0;
    objects.win_container = 0;
    objects.win_panel = 0;
    objects.lose_anzeige_panel = 0;
    objects.lose_anzeige_title = 0;
    objects.obj12 = 0;
    deletePageFlowState(11);
}

void tick_screen_game_win_lose() {
    void *flowState = getFlowState(0, 11);
    (void)flowState;
}

void create_screen_useroptionen1() {
    void *flowState = getFlowState(0, 12);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.useroptionen1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_20
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_20 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_20
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_20 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj65 = obj;
            lv_obj_set_pos(obj, 92, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "OPTIONEN");
        }
        {
            // buttonContainer_8
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_8 = obj;
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
                    // button_8
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_8 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_useroptionen1_button_8, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_8
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_8 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "QUICKSTART");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_10
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_10 = obj;
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
            objects.obj13 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_useroptionen1_obj13, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_USEROPTIONEN1 - 1);
    
    tick_screen_useroptionen1();
}

void delete_screen_useroptionen1() {
    lv_obj_del(objects.useroptionen1);
    objects.useroptionen1 = 0;
    objects.background_panel_20 = 0;
    objects.background_image_20 = 0;
    objects.obj65 = 0;
    objects.button_container_8 = 0;
    objects.button_8 = 0;
    objects.button_title_8 = 0;
    objects.button_container_10 = 0;
    objects.button_10 = 0;
    objects.button_title_10 = 0;
    objects.obj13 = 0;
    deletePageFlowState(12);
}

void tick_screen_useroptionen1() {
    void *flowState = getFlowState(0, 12);
    (void)flowState;
}

void create_screen_useroptionen1_spiele() {
    void *flowState = getFlowState(0, 13);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.useroptionen1_spiele = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_18
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_18 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_18
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_18 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj14 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_useroptionen1_spiele_obj14, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // gameRoller_1
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.game_roller_1 = obj;
            lv_obj_set_pos(obj, 122, 117);
            lv_obj_set_size(obj, 236, 246);
            lv_roller_set_options(obj, "LichtLoser", LV_ROLLER_MODE_INFINITE);
            add_style_gold_sel_braun(obj);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj15 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_useroptionen1_spiele_obj15, LV_EVENT_ALL, flowState);
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
    objects.background_panel_18 = 0;
    objects.background_image_18 = 0;
    objects.obj14 = 0;
    objects.game_roller_1 = 0;
    objects.obj15 = 0;
    deletePageFlowState(13);
}

void tick_screen_useroptionen1_spiele() {
    void *flowState = getFlowState(0, 13);
    (void)flowState;
}

void create_screen_useroptionen1_spiele_lichtloser() {
    void *flowState = getFlowState(0, 14);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.useroptionen1_spiele_lichtloser = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_48
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_48 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_48
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_48 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj16 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_useroptionen1_spiele_lichtloser_obj16, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj66 = obj;
            lv_obj_set_pos(obj, 90, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "LichtLoser");
        }
        {
            // dropdownContainer_20
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_20 = obj;
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
                            // rollerTitle_20
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_20 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "MODUS");
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
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_USEROPTIONEN1_SPIELE_LICHTLOSER - 1);
    
    tick_screen_useroptionen1_spiele_lichtloser();
}

void delete_screen_useroptionen1_spiele_lichtloser() {
    lv_obj_del(objects.useroptionen1_spiele_lichtloser);
    objects.useroptionen1_spiele_lichtloser = 0;
    objects.background_panel_48 = 0;
    objects.background_image_48 = 0;
    objects.obj16 = 0;
    objects.obj66 = 0;
    objects.dropdown_container_20 = 0;
    objects.roller_title_20 = 0;
    deletePageFlowState(14);
}

void tick_screen_useroptionen1_spiele_lichtloser() {
    void *flowState = getFlowState(0, 14);
    (void)flowState;
}

void create_screen_optionen_quickstart_player() {
    void *flowState = getFlowState(0, 15);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.optionen_quickstart_player = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_14
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_14 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, -16, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_14
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_14 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
                    lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
                    lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
                }
            }
        }
        {
            // playerRoller_1
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.player_roller_1 = obj;
            lv_obj_set_pos(obj, 122, 117);
            lv_obj_set_size(obj, 236, 246);
            lv_roller_set_options(obj, "2-Spieler\n3-Spieler\n4-Spieler\n5-Spieler\n6-Spieler", LV_ROLLER_MODE_INFINITE);
            add_style_gold_sel_braun(obj);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj17 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_optionen_quickstart_player_obj17, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj18 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_optionen_quickstart_player_obj18, LV_EVENT_ALL, flowState);
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
            // buttonContainer_35
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_35 = obj;
            lv_obj_set_pos(obj, 70, 9);
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
                    // button_35
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_35 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    add_style_gold(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // buttonTitle_35
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.button_title_35 = obj;
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "SPIEL WIEDERHOLEN");
                        }
                    }
                }
            }
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_OPTIONEN_QUICKSTART_PLAYER - 1);
    
    tick_screen_optionen_quickstart_player();
}

void delete_screen_optionen_quickstart_player() {
    lv_obj_del(objects.optionen_quickstart_player);
    objects.optionen_quickstart_player = 0;
    objects.background_panel_14 = 0;
    objects.background_image_14 = 0;
    objects.player_roller_1 = 0;
    objects.obj17 = 0;
    objects.obj18 = 0;
    objects.button_container_35 = 0;
    objects.button_35 = 0;
    objects.button_title_35 = 0;
    deletePageFlowState(15);
}

void tick_screen_optionen_quickstart_player() {
    void *flowState = getFlowState(0, 15);
    (void)flowState;
}

void create_screen_optionen_quickstart_game() {
    void *flowState = getFlowState(0, 16);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.optionen_quickstart_game = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_23
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_23 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, -16, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_23
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_23 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
                    lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
                    lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
                }
            }
        }
        {
            // gameRoller_4
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.game_roller_4 = obj;
            lv_obj_set_pos(obj, 122, 117);
            lv_obj_set_size(obj, 236, 246);
            lv_roller_set_options(obj, "LichtLoser", LV_ROLLER_MODE_INFINITE);
            add_style_gold_sel_braun(obj);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj19 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_optionen_quickstart_game_obj19, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj20 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_optionen_quickstart_game_obj20, LV_EVENT_ALL, flowState);
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
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_OPTIONEN_QUICKSTART_GAME - 1);
    
    tick_screen_optionen_quickstart_game();
}

void delete_screen_optionen_quickstart_game() {
    lv_obj_del(objects.optionen_quickstart_game);
    objects.optionen_quickstart_game = 0;
    objects.background_panel_23 = 0;
    objects.background_image_23 = 0;
    objects.game_roller_4 = 0;
    objects.obj19 = 0;
    objects.obj20 = 0;
    deletePageFlowState(16);
}

void tick_screen_optionen_quickstart_game() {
    void *flowState = getFlowState(0, 16);
    (void)flowState;
}

void create_screen_optionen_quickstart_modus() {
    void *flowState = getFlowState(0, 17);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.optionen_quickstart_modus = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_24
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_24 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, -16, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_24
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_24 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
                    lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
                    lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
                }
            }
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
            objects.obj21 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_optionen_quickstart_modus_obj21, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj22 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_optionen_quickstart_modus_obj22, LV_EVENT_ALL, flowState);
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
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_OPTIONEN_QUICKSTART_MODUS - 1);
    
    tick_screen_optionen_quickstart_modus();
}

void delete_screen_optionen_quickstart_modus() {
    lv_obj_del(objects.optionen_quickstart_modus);
    objects.optionen_quickstart_modus = 0;
    objects.background_panel_24 = 0;
    objects.background_image_24 = 0;
    objects.game_roller_5 = 0;
    objects.obj21 = 0;
    objects.obj22 = 0;
    deletePageFlowState(17);
}

void tick_screen_optionen_quickstart_modus() {
    void *flowState = getFlowState(0, 17);
    (void)flowState;
}

void create_screen_adminoptionen1() {
    void *flowState = getFlowState(0, 18);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_15
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_15 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_15
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_15 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj67 = obj;
            lv_obj_set_pos(obj, 92, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "OPTIONEN");
        }
        {
            // buttonContainer_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_2 = obj;
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
                    // button_2
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.button_2 = obj;
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_button_2, LV_EVENT_ALL, flowState);
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
                            lv_obj_set_pos(obj, -11, -7);
                            lv_obj_set_size(obj, 370, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point65, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "QUICKSTART");
                        }
                    }
                }
            }
        }
        {
            // buttonContainer_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.button_container_3 = obj;
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
            objects.obj23 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_obj23, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1 - 1);
    
    tick_screen_adminoptionen1();
}

void delete_screen_adminoptionen1() {
    lv_obj_del(objects.adminoptionen1);
    objects.adminoptionen1 = 0;
    objects.background_panel_15 = 0;
    objects.background_image_15 = 0;
    objects.obj67 = 0;
    objects.button_container_2 = 0;
    objects.button_2 = 0;
    objects.button_title_2 = 0;
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
    objects.obj23 = 0;
    deletePageFlowState(18);
}

void tick_screen_adminoptionen1() {
    void *flowState = getFlowState(0, 18);
    (void)flowState;
}

void create_screen_adminoptionen1_spiele() {
    void *flowState = getFlowState(0, 19);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_spiele = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_19
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_19 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_19
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_19 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj24 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_obj24, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // gameRoller_2
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.game_roller_2 = obj;
            lv_obj_set_pos(obj, 122, 117);
            lv_obj_set_size(obj, 236, 246);
            lv_roller_set_options(obj, "LichtLoser", LV_ROLLER_MODE_INFINITE);
            add_style_gold_sel_braun(obj);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj25 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_obj25, LV_EVENT_ALL, flowState);
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
    objects.background_panel_19 = 0;
    objects.background_image_19 = 0;
    objects.obj24 = 0;
    objects.game_roller_2 = 0;
    objects.obj25 = 0;
    deletePageFlowState(19);
}

void tick_screen_adminoptionen1_spiele() {
    void *flowState = getFlowState(0, 19);
    (void)flowState;
}

void create_screen_adminoptionen1_spiele_lichtloser() {
    void *flowState = getFlowState(0, 20);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_spiele_lichtloser = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_21
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_21 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_21
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_21 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj26 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_obj26, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj68 = obj;
            lv_obj_set_pos(obj, 90, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "LichtLoser");
        }
        {
            // dropdownContainer_18
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_18 = obj;
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
                            // rollerTitle_18
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.roller_title_18 = obj;
                            lv_obj_set_pos(obj, -15, -13);
                            lv_obj_set_size(obj, 197, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_set_style_text_font(obj, &ui_font_point40, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "MODUS");
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
            // dropdownContainer_19
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.dropdown_container_19 = obj;
            lv_obj_set_pos(obj, 35, 178);
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
            lv_obj_set_pos(obj, 35, 269);
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
                    // sliderTitle_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_title_1 = obj;
                    lv_obj_set_pos(obj, 7, 12);
                    lv_obj_set_size(obj, 396, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "RUNDEN (6)");
                }
                {
                    // slider_1
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_1 = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_range(obj, 0, 10);
                    lv_slider_set_value(obj, 6, LV_ANIM_OFF);
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
            lv_obj_set_pos(obj, 35, 359);
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
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SPIELE_LICHTLOSER - 1);
    
    tick_screen_adminoptionen1_spiele_lichtloser();
}

void delete_screen_adminoptionen1_spiele_lichtloser() {
    lv_obj_del(objects.adminoptionen1_spiele_lichtloser);
    objects.adminoptionen1_spiele_lichtloser = 0;
    objects.background_panel_21 = 0;
    objects.background_image_21 = 0;
    objects.obj26 = 0;
    objects.obj68 = 0;
    objects.dropdown_container_18 = 0;
    objects.roller_title_18 = 0;
    objects.dropdown_container_19 = 0;
    objects.roller_title_19 = 0;
    objects.slider_container_1 = 0;
    objects.slider_title_1 = 0;
    objects.slider_1 = 0;
    objects.button_container_1 = 0;
    objects.button_1 = 0;
    objects.button_title_1 = 0;
    deletePageFlowState(20);
}

void tick_screen_adminoptionen1_spiele_lichtloser() {
    void *flowState = getFlowState(0, 20);
    (void)flowState;
}

void create_screen_adminoptionen1_spiele_lichtloser_joker() {
    void *flowState = getFlowState(0, 21);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_spiele_lichtloser_joker = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_22
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_22 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_22
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_22 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj27 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_spiele_lichtloser_joker_obj27, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj69 = obj;
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
                    objects.obj70 = obj;
                    lv_obj_set_pos(obj, 17, 13);
                    lv_obj_set_size(obj, 73, 34);
                    lv_obj_add_state(obj, LV_STATE_CHECKED);
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
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "GOLD\nREGENBOGEN");
                    lv_dropdown_set_selected(obj, 0);
                    add_style_gold_dropdown_(obj);
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
    objects.background_panel_22 = 0;
    objects.background_image_22 = 0;
    objects.obj27 = 0;
    objects.obj69 = 0;
    objects.switch_container_1 = 0;
    objects.obj70 = 0;
    objects.switch_title_1 = 0;
    objects.dropdown_container_3 = 0;
    objects.roller_title_3 = 0;
    deletePageFlowState(21);
}

void tick_screen_adminoptionen1_spiele_lichtloser_joker() {
    void *flowState = getFlowState(0, 21);
    (void)flowState;
}

void create_screen_adminoptionen1_farbeneffekte() {
    void *flowState = getFlowState(0, 22);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_farbeneffekte = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_31
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_31 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_31
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_31 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj71 = obj;
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
            objects.obj28 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_obj28, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_FARBENEFFEKTE - 1);
    
    tick_screen_adminoptionen1_farbeneffekte();
}

void delete_screen_adminoptionen1_farbeneffekte() {
    lv_obj_del(objects.adminoptionen1_farbeneffekte);
    objects.adminoptionen1_farbeneffekte = 0;
    objects.background_panel_31 = 0;
    objects.background_image_31 = 0;
    objects.obj71 = 0;
    objects.button_container_24 = 0;
    objects.button_24 = 0;
    objects.button_title_24 = 0;
    objects.button_container_25 = 0;
    objects.button_25 = 0;
    objects.button_title_25 = 0;
    objects.button_container_26 = 0;
    objects.button_26 = 0;
    objects.button_title_26 = 0;
    objects.obj28 = 0;
    deletePageFlowState(22);
}

void tick_screen_adminoptionen1_farbeneffekte() {
    void *flowState = getFlowState(0, 22);
    (void)flowState;
}

void create_screen_adminoptionen1_farbeneffekte_winlose() {
    void *flowState = getFlowState(0, 23);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_farbeneffekte_winlose = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_33
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_33 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_33
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_33 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj72 = obj;
            lv_obj_set_pos(obj, 106, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "WIN/LOSE");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj29 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_winlose_obj29, LV_EVENT_ALL, flowState);
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
    objects.background_panel_33 = 0;
    objects.background_image_33 = 0;
    objects.obj72 = 0;
    objects.obj29 = 0;
    objects.dropdown_container_5 = 0;
    objects.roller_title_5 = 0;
    objects.dropdown_container_6 = 0;
    objects.roller_title_6 = 0;
    objects.dropdown_container_7 = 0;
    objects.roller_title_7 = 0;
    objects.dropdown_container_8 = 0;
    objects.roller_title_8 = 0;
    deletePageFlowState(23);
}

void tick_screen_adminoptionen1_farbeneffekte_winlose() {
    void *flowState = getFlowState(0, 23);
    (void)flowState;
}

void create_screen_adminoptionen1_farbeneffekte_spielerfarbe() {
    void *flowState = getFlowState(0, 24);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_farbeneffekte_spielerfarbe = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_34
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_34 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_34
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_34 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj73 = obj;
            lv_obj_set_pos(obj, 101, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "SPIELERFARBE");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj30 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_spielerfarbe_obj30, LV_EVENT_ALL, flowState);
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
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "EINE FARBE\nJEDER SPIELER EIGENE\nZUFAELLIG");
                    lv_dropdown_set_selected(obj, 0);
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
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "ZUFALL\nBLAU\nGRUEN\nROT\nREGENBOGEN");
                    lv_dropdown_set_selected(obj, 0);
                    add_style_gold_dropdown_(obj);
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
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 50);
                    add_style_gold_panel(obj);
                }
                {
                    // checkbox_2
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.checkbox_2 = obj;
                    lv_obj_set_pos(obj, 20, 11);
                    lv_obj_set_size(obj, 370, 38);
                    lv_checkbox_set_text(obj, "");
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
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "AUS\nGRAU\nDIMMEN");
                    lv_dropdown_set_selected(obj, 0);
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
    objects.background_panel_34 = 0;
    objects.background_image_34 = 0;
    objects.obj73 = 0;
    objects.obj30 = 0;
    objects.dropdown_container_9 = 0;
    objects.roller_title_9 = 0;
    objects.dropdown_container_10 = 0;
    objects.roller_title_10 = 0;
    objects.checkbox_contatiner_2 = 0;
    objects.checkbox_2 = 0;
    objects.checkbox_title_2 = 0;
    objects.dropdown_container_17 = 0;
    objects.roller_title_17 = 0;
    deletePageFlowState(24);
}

void tick_screen_adminoptionen1_farbeneffekte_spielerfarbe() {
    void *flowState = getFlowState(0, 24);
    (void)flowState;
}

void create_screen_adminoptionen1_farbeneffekte_grenzfarbe() {
    void *flowState = getFlowState(0, 25);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_farbeneffekte_grenzfarbe = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_35
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_35 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_35
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_35 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj74 = obj;
            lv_obj_set_pos(obj, 123, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "GRENZFARBE");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj31 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_farbeneffekte_grenzfarbe_obj31, LV_EVENT_ALL, flowState);
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
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "EINFARBIG\nREGENBOGEN");
                    lv_dropdown_set_selected(obj, 0);
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
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "BRAUN\nGRAU");
                    lv_dropdown_set_selected(obj, 0);
                    add_style_gold_dropdown_(obj);
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
    objects.background_panel_35 = 0;
    objects.background_image_35 = 0;
    objects.obj74 = 0;
    objects.obj31 = 0;
    objects.dropdown_container_11 = 0;
    objects.roller_title_11 = 0;
    objects.dropdown_container_12 = 0;
    objects.roller_title_12 = 0;
    deletePageFlowState(25);
}

void tick_screen_adminoptionen1_farbeneffekte_grenzfarbe() {
    void *flowState = getFlowState(0, 25);
    (void)flowState;
}

void create_screen_adminoptionen1_system() {
    void *flowState = getFlowState(0, 26);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_25
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_25 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_25
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_25 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj75 = obj;
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
            objects.obj32 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_obj32, LV_EVENT_ALL, flowState);
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
                    objects.obj33 = obj;
                    lv_obj_set_pos(obj, 8, 5);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_obj33, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj76 = obj;
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
    objects.background_panel_25 = 0;
    objects.background_image_25 = 0;
    objects.obj75 = 0;
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
    objects.obj32 = 0;
    objects.question_container_7 = 0;
    objects.obj33 = 0;
    objects.obj76 = 0;
    deletePageFlowState(26);
}

void tick_screen_adminoptionen1_system() {
    void *flowState = getFlowState(0, 26);
    (void)flowState;
}

void create_screen_adminoptionen1_system_leds() {
    void *flowState = getFlowState(0, 27);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_leds = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_26
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_26 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_26
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_26 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj77 = obj;
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
            objects.obj34 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_leds_obj34, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM_LEDS - 1);
    
    tick_screen_adminoptionen1_system_leds();
}

void delete_screen_adminoptionen1_system_leds() {
    lv_obj_del(objects.adminoptionen1_system_leds);
    objects.adminoptionen1_system_leds = 0;
    objects.background_panel_26 = 0;
    objects.background_image_26 = 0;
    objects.obj77 = 0;
    objects.button_container_18 = 0;
    objects.button_18 = 0;
    objects.button_title_18 = 0;
    objects.obj34 = 0;
    deletePageFlowState(27);
}

void tick_screen_adminoptionen1_system_leds() {
    void *flowState = getFlowState(0, 27);
    (void)flowState;
}

void create_screen_adminoptionen1_system_leds_helligkeit() {
    void *flowState = getFlowState(0, 28);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_leds_helligkeit = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_29
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_29 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_29
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_29 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj78 = obj;
            lv_obj_set_pos(obj, 78, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "HELLIGKEIT");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj35 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_leds_helligkeit_obj35, LV_EVENT_ALL, flowState);
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
                    lv_obj_set_pos(obj, 7, 12);
                    lv_obj_set_size(obj, 396, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "SPIELLEDS (55%)");
                }
                {
                    // slider_2
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_2 = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_range(obj, 10, 55);
                    lv_slider_set_value(obj, 55, LV_ANIM_OFF);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 130, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffab7c46), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_KNOB | LV_STATE_DEFAULT);
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
                    lv_obj_set_pos(obj, 7, 12);
                    lv_obj_set_size(obj, 396, 49);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                    lv_obj_set_style_text_font(obj, &ui_font_point55, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "GRENZLEDS (55%)");
                }
                {
                    // slider_3
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_3 = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_range(obj, 10, 55);
                    lv_slider_set_value(obj, 100, LV_ANIM_OFF);
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
    objects.background_panel_29 = 0;
    objects.background_image_29 = 0;
    objects.obj78 = 0;
    objects.obj35 = 0;
    objects.slider_container_2 = 0;
    objects.slider_title_2 = 0;
    objects.slider_2 = 0;
    objects.slider_container_3 = 0;
    objects.slider_title_3 = 0;
    objects.slider_3 = 0;
    deletePageFlowState(28);
}

void tick_screen_adminoptionen1_system_leds_helligkeit() {
    void *flowState = getFlowState(0, 28);
    (void)flowState;
}

void create_screen_adminoptionen1_system_anzeige() {
    void *flowState = getFlowState(0, 29);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_anzeige = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_27
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_27 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_27
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_27 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj79 = obj;
            lv_obj_set_pos(obj, 112, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "ANZEIGE");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj36 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_anzeige_obj36, LV_EVENT_ALL, flowState);
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
                    lv_label_set_text(obj, "HELLIGKEIT (100%)");
                }
                {
                    // slider_4
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.slider_4 = obj;
                    lv_obj_set_pos(obj, 35, 55);
                    lv_obj_set_size(obj, 340, 18);
                    lv_slider_set_range(obj, 10, 100);
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
    objects.background_panel_27 = 0;
    objects.background_image_27 = 0;
    objects.obj79 = 0;
    objects.obj36 = 0;
    objects.slider_container_4 = 0;
    objects.slider_title_4 = 0;
    objects.slider_4 = 0;
    objects.button_container_29 = 0;
    objects.button_29 = 0;
    objects.button_title_29 = 0;
    deletePageFlowState(29);
}

void tick_screen_adminoptionen1_system_anzeige() {
    void *flowState = getFlowState(0, 29);
    (void)flowState;
}

void create_screen_adminoptionen1_system_anzeige_idle() {
    void *flowState = getFlowState(0, 30);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_anzeige_idle = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_30
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_30 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_30
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_30 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj80 = obj;
            lv_obj_set_pos(obj, 188, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "IDLE");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj37 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_anzeige_idle_obj37, LV_EVENT_ALL, flowState);
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
                    objects.obj81 = obj;
                    lv_obj_set_pos(obj, 17, 13);
                    lv_obj_set_size(obj, 73, 34);
                    lv_obj_add_state(obj, LV_STATE_CHECKED);
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
                    lv_obj_set_pos(obj, 105, 5);
                    lv_obj_set_size(obj, 200, 40);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_gold_panel(obj);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                    lv_obj_set_pos(obj, 15, 35);
                    lv_obj_set_size(obj, 380, 50);
                    lv_dropdown_set_options(obj, "5 MINUTEN\n10 MINUTEN\n15 MINUTEN\n30 MINUTEN\n60 MINUTEN");
                    lv_dropdown_set_selected(obj, 1);
                    add_style_gold_dropdown_(obj);
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
                    lv_obj_set_pos(obj, 15, 5);
                    lv_obj_set_size(obj, 380, 50);
                    add_style_gold_panel(obj);
                }
                {
                    // checkbox_1
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.checkbox_1 = obj;
                    lv_obj_set_pos(obj, 20, 11);
                    lv_obj_set_size(obj, 370, 38);
                    lv_checkbox_set_text(obj, "");
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
    objects.background_panel_30 = 0;
    objects.background_image_30 = 0;
    objects.obj80 = 0;
    objects.obj37 = 0;
    objects.switch_container_2 = 0;
    objects.obj81 = 0;
    objects.switch_title_2 = 0;
    objects.dropdown_container_4 = 0;
    objects.roller_title_4 = 0;
    objects.checkbox_contatiner_1 = 0;
    objects.checkbox_1 = 0;
    objects.checkbox_title_1 = 0;
    deletePageFlowState(30);
}

void tick_screen_adminoptionen1_system_anzeige_idle() {
    void *flowState = getFlowState(0, 30);
    (void)flowState;
}

void create_screen_adminoptionen1_system_audio() {
    void *flowState = getFlowState(0, 31);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_audio = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_41
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_41 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_41
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_41 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj82 = obj;
            lv_obj_set_pos(obj, 146, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "AUDIO");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj38 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_audio_obj38, LV_EVENT_ALL, flowState);
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
                    objects.obj83 = obj;
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
                    objects.obj84 = obj;
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
    objects.background_panel_41 = 0;
    objects.background_image_41 = 0;
    objects.obj82 = 0;
    objects.obj38 = 0;
    objects.switch_container_5 = 0;
    objects.obj83 = 0;
    objects.switch_title_5 = 0;
    objects.slider_container_5 = 0;
    objects.slider_title_5 = 0;
    objects.slider_5 = 0;
    objects.switch_container_6 = 0;
    objects.obj84 = 0;
    objects.switch_title_6 = 0;
    objects.slider_container_6 = 0;
    objects.slider_title_6 = 0;
    objects.slider_6 = 0;
    objects.button_container_17 = 0;
    objects.button_17 = 0;
    objects.button_title_17 = 0;
    deletePageFlowState(31);
}

void tick_screen_adminoptionen1_system_audio() {
    void *flowState = getFlowState(0, 31);
    (void)flowState;
}

void create_screen_adminoptionen1_system_netzwerk() {
    void *flowState = getFlowState(0, 32);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_netzwerk = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_36
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_36 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_36
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_36 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj85 = obj;
            lv_obj_set_pos(obj, 78, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "NETZWERK");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj39 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_obj39, LV_EVENT_ALL, flowState);
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
    objects.background_panel_36 = 0;
    objects.background_image_36 = 0;
    objects.obj85 = 0;
    objects.obj39 = 0;
    objects.button_container_19 = 0;
    objects.button_19 = 0;
    objects.button_title_19 = 0;
    objects.button_container_22 = 0;
    objects.button_22 = 0;
    objects.button_title_22 = 0;
    objects.button_container_23 = 0;
    objects.button_23 = 0;
    objects.button_title_23 = 0;
    deletePageFlowState(32);
}

void tick_screen_adminoptionen1_system_netzwerk() {
    void *flowState = getFlowState(0, 32);
    (void)flowState;
}

void create_screen_adminoptionen1_system_netzwerk_wifi() {
    void *flowState = getFlowState(0, 33);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_netzwerk_wifi = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_37
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_37 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_37
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_37 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj86 = obj;
            lv_obj_set_pos(obj, 146, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "WIFI");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj40 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_wifi_obj40, LV_EVENT_ALL, flowState);
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
                    objects.obj87 = obj;
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
    objects.background_panel_37 = 0;
    objects.background_image_37 = 0;
    objects.obj86 = 0;
    objects.obj40 = 0;
    objects.switch_container_3 = 0;
    objects.obj87 = 0;
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
    deletePageFlowState(33);
}

void tick_screen_adminoptionen1_system_netzwerk_wifi() {
    void *flowState = getFlowState(0, 33);
    (void)flowState;
}

void create_screen_adminoptionen1_system_netzwerk_kommunikation() {
    void *flowState = getFlowState(0, 34);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_netzwerk_kommunikation = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_38
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_38 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_38
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_38 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj88 = obj;
            lv_obj_set_pos(obj, 61, 13);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point80, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "KOMMUNIKATION");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj41 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_kommunikation_obj41, LV_EVENT_ALL, flowState);
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
    objects.background_panel_38 = 0;
    objects.background_image_38 = 0;
    objects.obj88 = 0;
    objects.obj41 = 0;
    objects.dropdown_container_13 = 0;
    objects.roller_title_13 = 0;
    objects.dropdown_container_14 = 0;
    objects.roller_title_14 = 0;
    objects.dropdown_container_15 = 0;
    objects.roller_title_15 = 0;
    deletePageFlowState(34);
}

void tick_screen_adminoptionen1_system_netzwerk_kommunikation() {
    void *flowState = getFlowState(0, 34);
    (void)flowState;
}

void create_screen_adminoptionen1_system_netzwerk_update() {
    void *flowState = getFlowState(0, 35);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_netzwerk_update = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_39
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_39 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_39
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_39 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj89 = obj;
            lv_obj_set_pos(obj, 136, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "UPDATE");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj42 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_update_obj42, LV_EVENT_ALL, flowState);
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
    objects.background_panel_39 = 0;
    objects.background_image_39 = 0;
    objects.obj89 = 0;
    objects.obj42 = 0;
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
    deletePageFlowState(35);
}

void tick_screen_adminoptionen1_system_netzwerk_update() {
    void *flowState = getFlowState(0, 35);
    (void)flowState;
}

void create_screen_adminoptionen1_system_netzwerk_update_manifest() {
    void *flowState = getFlowState(0, 36);
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
            // backgroundPanel_47
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_47 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_47
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_47 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj90 = obj;
            lv_obj_set_pos(obj, 85, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "MANIFEST");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj43 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_update_manifest_obj43, LV_EVENT_ALL, flowState);
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
    objects.background_panel_47 = 0;
    objects.background_image_47 = 0;
    objects.obj90 = 0;
    objects.obj43 = 0;
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
    deletePageFlowState(36);
}

void tick_screen_adminoptionen1_system_netzwerk_update_manifest() {
    void *flowState = getFlowState(0, 36);
    (void)flowState;
}

void create_screen_adminoptionen1_system_netzwerk_update_firmware() {
    void *flowState = getFlowState(0, 37);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_netzwerk_update_firmware = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_40
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_40 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_40
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_40 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj91 = obj;
            lv_obj_set_pos(obj, 64, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "FIRMWARE");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj44 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_netzwerk_update_firmware_obj44, LV_EVENT_ALL, flowState);
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
    objects.background_panel_40 = 0;
    objects.background_image_40 = 0;
    objects.obj91 = 0;
    objects.obj44 = 0;
    objects.button_container_32 = 0;
    objects.button_32 = 0;
    objects.button_title_32 = 0;
    deletePageFlowState(37);
}

void tick_screen_adminoptionen1_system_netzwerk_update_firmware() {
    void *flowState = getFlowState(0, 37);
    (void)flowState;
}

void create_screen_adminoptionen1_system_debug() {
    void *flowState = getFlowState(0, 38);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_debug = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_28
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_28 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_28
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_28 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj92 = obj;
            lv_obj_set_pos(obj, 145, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "DEBUG");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj45 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_debug_obj45, LV_EVENT_ALL, flowState);
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
                    objects.obj93 = obj;
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
                    objects.obj94 = obj;
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
                    objects.obj46 = obj;
                    lv_obj_set_pos(obj, 8, 5);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_debug_obj46, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj95 = obj;
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
    objects.background_panel_28 = 0;
    objects.background_image_28 = 0;
    objects.obj92 = 0;
    objects.obj45 = 0;
    objects.switch_container_7 = 0;
    objects.obj93 = 0;
    objects.switch_title_7 = 0;
    objects.switch_container_4 = 0;
    objects.obj94 = 0;
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
    objects.obj46 = 0;
    objects.obj95 = 0;
    deletePageFlowState(38);
}

void tick_screen_adminoptionen1_system_debug() {
    void *flowState = getFlowState(0, 38);
    (void)flowState;
}

void create_screen_adminoptionen1_system_debug2() {
    void *flowState = getFlowState(0, 39);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_debug2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_44
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_44 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_44
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_44 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj96 = obj;
            lv_obj_set_pos(obj, 145, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "DEBUG");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj47 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_debug2_obj47, LV_EVENT_ALL, flowState);
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
    objects.background_panel_44 = 0;
    objects.background_image_44 = 0;
    objects.obj96 = 0;
    objects.obj47 = 0;
    objects.button_container_46 = 0;
    objects.button_46 = 0;
    objects.button_title_46 = 0;
    objects.button_container_50 = 0;
    objects.button_50 = 0;
    objects.button_title_50 = 0;
    deletePageFlowState(39);
}

void tick_screen_adminoptionen1_system_debug2() {
    void *flowState = getFlowState(0, 39);
    (void)flowState;
}

void create_screen_adminoptionen1_system_debug2_tests() {
    void *flowState = getFlowState(0, 40);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system_debug2_tests = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_45
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_45 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_45
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_45 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj97 = obj;
            lv_obj_set_pos(obj, 154, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "TESTS");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj48 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system_debug2_tests_obj48, LV_EVENT_ALL, flowState);
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
    objects.background_panel_45 = 0;
    objects.background_image_45 = 0;
    objects.obj97 = 0;
    objects.obj48 = 0;
    objects.button_container_47 = 0;
    objects.button_47 = 0;
    objects.button_title_47 = 0;
    objects.button_container_48 = 0;
    objects.button_48 = 0;
    objects.button_title_48 = 0;
    objects.button_container_49 = 0;
    objects.button_49 = 0;
    objects.button_title_49 = 0;
    deletePageFlowState(40);
}

void tick_screen_adminoptionen1_system_debug2_tests() {
    void *flowState = getFlowState(0, 40);
    (void)flowState;
}

void create_screen_adminoptionen1_system2() {
    void *flowState = getFlowState(0, 41);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_42
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_42 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_42
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_42 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj98 = obj;
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
            objects.obj49 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system2_obj49, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_SYSTEM2 - 1);
    
    tick_screen_adminoptionen1_system2();
}

void delete_screen_adminoptionen1_system2() {
    lv_obj_del(objects.adminoptionen1_system2);
    objects.adminoptionen1_system2 = 0;
    objects.background_panel_42 = 0;
    objects.background_image_42 = 0;
    objects.obj98 = 0;
    objects.button_container_38 = 0;
    objects.button_38 = 0;
    objects.button_title_38 = 0;
    objects.button_container_40 = 0;
    objects.button_40 = 0;
    objects.button_title_40 = 0;
    objects.button_container_39 = 0;
    objects.button_39 = 0;
    objects.button_title_39 = 0;
    objects.obj49 = 0;
    deletePageFlowState(41);
}

void tick_screen_adminoptionen1_system2() {
    void *flowState = getFlowState(0, 41);
    (void)flowState;
}

void create_screen_adminoptionen1_system2_profil() {
    void *flowState = getFlowState(0, 42);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system2_profil = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_43
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_43 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_43
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_43 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj99 = obj;
            lv_obj_set_pos(obj, 129, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 65);
            lv_obj_set_style_text_font(obj, &ui_font_point120, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdd111), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "PROFIL");
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj50 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system2_profil_obj50, LV_EVENT_ALL, flowState);
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
    objects.background_panel_43 = 0;
    objects.background_image_43 = 0;
    objects.obj99 = 0;
    objects.obj50 = 0;
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
    deletePageFlowState(42);
}

void tick_screen_adminoptionen1_system2_profil() {
    void *flowState = getFlowState(0, 42);
    (void)flowState;
}

void create_screen_adminoptionen1_system2_profil_profilladen() {
    void *flowState = getFlowState(0, 43);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_system2_profil_profilladen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_16
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_16 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, -16, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_16
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_16 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
                    lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_NONE);
                    lv_obj_set_scroll_snap_y(obj, LV_SCROLL_SNAP_NONE);
                }
            }
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
            objects.obj51 = obj;
            lv_obj_set_pos(obj, 6, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system2_profil_profilladen_obj51, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj52 = obj;
            lv_obj_set_pos(obj, 130, 380);
            lv_obj_set_size(obj, 221, 55);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_system2_profil_profilladen_obj52, LV_EVENT_ALL, flowState);
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
    objects.background_panel_16 = 0;
    objects.background_image_16 = 0;
    objects.choose_roller_3 = 0;
    objects.obj51 = 0;
    objects.obj52 = 0;
    deletePageFlowState(43);
}

void tick_screen_adminoptionen1_system2_profil_profilladen() {
    void *flowState = getFlowState(0, 43);
    (void)flowState;
}

void create_screen_adminoptionen1_bonus() {
    void *flowState = getFlowState(0, 44);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.adminoptionen1_bonus = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_46
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_46 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_46
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_46 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj100 = obj;
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
            objects.obj53 = obj;
            lv_obj_set_pos(obj, 5, 13);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_adminoptionen1_bonus_obj53, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_ADMINOPTIONEN1_BONUS - 1);
    
    tick_screen_adminoptionen1_bonus();
}

void delete_screen_adminoptionen1_bonus() {
    lv_obj_del(objects.adminoptionen1_bonus);
    objects.adminoptionen1_bonus = 0;
    objects.background_panel_46 = 0;
    objects.background_image_46 = 0;
    objects.obj100 = 0;
    objects.button_container_7 = 0;
    objects.button_7 = 0;
    objects.button_title_7 = 0;
    objects.obj53 = 0;
    deletePageFlowState(44);
}

void tick_screen_adminoptionen1_bonus() {
    void *flowState = getFlowState(0, 44);
    (void)flowState;
}

void create_screen_optionen_template() {
    void *flowState = getFlowState(0, 45);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.optionen_template = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_12
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_12 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_12
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_12 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
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
                    objects.obj101 = obj;
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
                    objects.obj102 = obj;
                    lv_obj_set_pos(obj, 8, 5);
                    lv_obj_set_size(obj, 50, 50);
                    add_style_gold(obj);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj103 = obj;
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
                    objects.obj54 = obj;
                    lv_obj_set_pos(obj, 8, 5);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_optionen_template_obj54, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj104 = obj;
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
                    objects.obj55 = obj;
                    lv_obj_set_pos(obj, 8, 5);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_optionen_template_obj55, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj105 = obj;
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
                    objects.obj56 = obj;
                    lv_obj_set_pos(obj, 8, 5);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_optionen_template_obj56, LV_EVENT_ALL, flowState);
                    add_style_gold(obj);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffab7c46), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj106 = obj;
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
            objects.obj57 = obj;
            lv_obj_set_pos(obj, 418, 418);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_optionen_template_obj57, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
    
    eez_flow_delete_screen_on_unload(SCREEN_ID_OPTIONEN_TEMPLATE - 1);
    
    tick_screen_optionen_template();
}

void delete_screen_optionen_template() {
    lv_obj_del(objects.optionen_template);
    objects.optionen_template = 0;
    objects.background_panel_12 = 0;
    objects.background_image_12 = 0;
    objects.switch_container = 0;
    objects.obj101 = 0;
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
    objects.obj102 = 0;
    objects.obj103 = 0;
    objects.question_container_1 = 0;
    objects.obj54 = 0;
    objects.obj104 = 0;
    objects.question_container_2 = 0;
    objects.obj55 = 0;
    objects.obj105 = 0;
    objects.question_container_6 = 0;
    objects.obj56 = 0;
    objects.obj106 = 0;
    objects.obj57 = 0;
    deletePageFlowState(45);
}

void tick_screen_optionen_template() {
    void *flowState = getFlowState(0, 45);
    (void)flowState;
}

void create_screen_optionen_template_2() {
    void *flowState = getFlowState(0, 46);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.optionen_template_2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_state(obj, LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            // backgroundPanel_32
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_panel_32 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 480);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // backgroundImage_32
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.background_image_32 = obj;
                    lv_obj_set_pos(obj, -18, -18);
                    lv_obj_set_size(obj, 480, 480);
                    lv_img_set_src(obj, &img_background);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.obj58 = obj;
            lv_obj_set_pos(obj, 418, 418);
            lv_obj_set_size(obj, 53, 51);
            lv_img_set_src(obj, &img_exit);
            lv_img_set_zoom(obj, 350);
            lv_obj_add_event_cb(obj, event_handler_cb_optionen_template_2_obj58, LV_EVENT_ALL, flowState);
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
    objects.background_panel_32 = 0;
    objects.background_image_32 = 0;
    objects.obj58 = 0;
    objects.dropdown_container_2 = 0;
    objects.roller_title_1 = 0;
    objects.roller_container_2 = 0;
    objects.roller_title_2 = 0;
    objects.roller_2 = 0;
    deletePageFlowState(46);
}

void tick_screen_optionen_template_2() {
    void *flowState = getFlowState(0, 46);
    (void)flowState;
}


extern void add_style(lv_obj_t *obj, int32_t styleIndex);
extern void remove_style(lv_obj_t *obj, int32_t styleIndex);

static const char *screen_names[] = { "idleScreen", "loadingScreen", "menuScreen", "choosePlayerScreen", "chooseGameScreen", "highscoreGameScreen", "highscoreScreen", "keyboardScreen", "numpadScreen", "okayScreen", "game1", "gameWinLose", "useroptionen1", "useroptionen1_spiele", "useroptionen1_spiele_lichtloser", "optionen_quickstart_player", "optionen_quickstart_game", "optionen_quickstart_modus", "adminoptionen1", "adminoptionen1_spiele", "adminoptionen1_spiele_lichtloser", "adminoptionen1_spiele_lichtloser_joker", "adminoptionen1_farbeneffekte", "adminoptionen1_farbeneffekte_winlose", "adminoptionen1_farbeneffekte_spielerfarbe", "adminoptionen1_farbeneffekte_grenzfarbe", "adminoptionen1_system", "adminoptionen1_system_leds", "adminoptionen1_system_leds_helligkeit", "adminoptionen1_system_anzeige", "adminoptionen1_system_anzeige_idle", "adminoptionen1_system_audio", "adminoptionen1_system_netzwerk", "adminoptionen1_system_netzwerk_wifi", "adminoptionen1_system_netzwerk_kommunikation", "adminoptionen1_system_netzwerk_update", "adminoptionen1_system_netzwerk_update_manifest", "adminoptionen1_system_netzwerk_update_firmware", "adminoptionen1_system_debug", "adminoptionen1_system_debug2", "adminoptionen1_system_debug2_tests", "adminoptionen1_system2", "adminoptionen1_system2_profil", "adminoptionen1_system2_profil_profilladen", "adminoptionen1_bonus", "optionenTemplate", "optionenTemplate_2" };
static const char *object_names[] = { "idle_screen", "loading_screen", "menu_screen", "choose_player_screen", "choose_game_screen", "highscore_game_screen", "highscore_screen", "keyboard_screen", "numpad_screen", "okay_screen", "game1", "game_win_lose", "useroptionen1", "useroptionen1_spiele", "useroptionen1_spiele_lichtloser", "optionen_quickstart_player", "optionen_quickstart_game", "optionen_quickstart_modus", "adminoptionen1", "adminoptionen1_spiele", "adminoptionen1_spiele_lichtloser", "adminoptionen1_spiele_lichtloser_joker", "adminoptionen1_farbeneffekte", "adminoptionen1_farbeneffekte_winlose", "adminoptionen1_farbeneffekte_spielerfarbe", "adminoptionen1_farbeneffekte_grenzfarbe", "adminoptionen1_system", "adminoptionen1_system_leds", "adminoptionen1_system_leds_helligkeit", "adminoptionen1_system_anzeige", "adminoptionen1_system_anzeige_idle", "adminoptionen1_system_audio", "adminoptionen1_system_netzwerk", "adminoptionen1_system_netzwerk_wifi", "adminoptionen1_system_netzwerk_kommunikation", "adminoptionen1_system_netzwerk_update", "adminoptionen1_system_netzwerk_update_manifest", "adminoptionen1_system_netzwerk_update_firmware", "adminoptionen1_system_debug", "adminoptionen1_system_debug2", "adminoptionen1_system_debug2_tests", "adminoptionen1_system2", "adminoptionen1_system2_profil", "adminoptionen1_system2_profil_profilladen", "adminoptionen1_bonus", "optionen_template", "optionen_template_2", "obj0", "start", "highscore", "optionen", "obj1", "obj2", "obj3", "obj4", "obj5", "obj6", "obj7", "obj8", "obj9", "obj10", "obj11", "obj12", "button_8", "button_10", "obj13", "obj14", "obj15", "obj16", "obj17", "obj18", "obj19", "obj20", "obj21", "obj22", "button_2", "button_3", "button_5", "button_6", "button_9", "obj23", "obj24", "obj25", "obj26", "button_1", "obj27", "button_24", "button_25", "button_26", "obj28", "obj29", "obj30", "obj31", "button_12", "button_13", "button_16", "button_14", "button_15", "obj32", "obj33", "button_18", "obj34", "obj35", "obj36", "button_29", "obj37", "obj38", "obj39", "button_19", "button_22", "button_23", "obj40", "obj41", "obj42", "button_44", "button_31", "obj43", "obj44", "obj45", "obj46", "obj47", "button_46", "obj48", "button_40", "button_39", "obj49", "obj50", "button_43", "button_42", "obj51", "obj52", "obj53", "obj54", "obj55", "obj56", "obj57", "obj58", "background_panel_1", "background_image_1", "start_idle", "version", "background_panel_4", "background_image_4", "logo", "obj59", "background_panel_2", "background_image_2", "news_container", "news_panel", "news", "obj60", "obj61", "obj62", "background_panel_3", "background_image_3", "player_roller", "background_panel_5", "background_image_5", "game_roller", "background_panel_6", "background_image_6", "highscore_roller", "background_panel_7", "background_image_7", "obj63", "obj64", "background_panel_8", "background_image_8", "keyboard_area", "keyboard", "keyboard_title", "background_panel_9", "background_image_9", "numpad_area", "numpad", "numpad_title", "background_panel_10", "background_image_10", "ja_panel", "nein_panel", "background_panel_13", "background_image_13", "scores", "score_panel1", "score1", "score_player2", "score_panel2", "score2", "score_player3", "score_panel3", "score3", "score_player4", "score_panel4", "score4", "score_player5", "score_panel5", "score5", "score_player6", "score_panel6", "score6", "background_panel_11", "background_image_11", "win_lose_container", "lose_panel", "win_container", "win_panel", "lose_anzeige_panel", "lose_anzeige_title", "background_panel_20", "background_image_20", "obj65", "button_container_8", "button_title_8", "button_container_10", "button_title_10", "background_panel_18", "background_image_18", "game_roller_1", "background_panel_48", "background_image_48", "obj66", "dropdown_container_20", "roller_title_20", "background_panel_14", "background_image_14", "player_roller_1", "button_container_35", "button_35", "button_title_35", "background_panel_23", "background_image_23", "game_roller_4", "background_panel_24", "background_image_24", "game_roller_5", "background_panel_15", "background_image_15", "obj67", "button_container_2", "button_title_2", "button_container_3", "button_title_3", "button_container_5", "button_title_5", "button_container_6", "button_title_6", "button_container_9", "button_title_9", "background_panel_19", "background_image_19", "game_roller_2", "background_panel_21", "background_image_21", "obj68", "dropdown_container_18", "roller_title_18", "dropdown_container_19", "roller_title_19", "slider_container_1", "slider_title_1", "slider_1", "button_container_1", "button_title_1", "background_panel_22", "background_image_22", "obj69", "switch_container_1", "obj70", "switch_title_1", "dropdown_container_3", "roller_title_3", "background_panel_31", "background_image_31", "obj71", "button_container_24", "button_title_24", "button_container_25", "button_title_25", "button_container_26", "button_title_26", "background_panel_33", "background_image_33", "obj72", "dropdown_container_5", "roller_title_5", "dropdown_container_6", "roller_title_6", "dropdown_container_7", "roller_title_7", "dropdown_container_8", "roller_title_8", "background_panel_34", "background_image_34", "obj73", "dropdown_container_9", "roller_title_9", "dropdown_container_10", "roller_title_10", "checkbox_contatiner_2", "checkbox_2", "checkbox_title_2", "dropdown_container_17", "roller_title_17", "background_panel_35", "background_image_35", "obj74", "dropdown_container_11", "roller_title_11", "dropdown_container_12", "roller_title_12", "background_panel_25", "background_image_25", "obj75", "button_container_12", "button_title_12", "button_container_13", "button_title_13", "button_container_16", "button_title_16", "button_container_14", "button_title_14", "button_container_15", "button_title_15", "question_container_7", "obj76", "background_panel_26", "background_image_26", "obj77", "button_container_18", "button_title_18", "background_panel_29", "background_image_29", "obj78", "slider_container_2", "slider_title_2", "slider_2", "slider_container_3", "slider_title_3", "slider_3", "background_panel_27", "background_image_27", "obj79", "slider_container_4", "slider_title_4", "slider_4", "button_container_29", "button_title_29", "background_panel_30", "background_image_30", "obj80", "switch_container_2", "obj81", "switch_title_2", "dropdown_container_4", "roller_title_4", "checkbox_contatiner_1", "checkbox_1", "checkbox_title_1", "background_panel_41", "background_image_41", "obj82", "switch_container_5", "obj83", "switch_title_5", "slider_container_5", "slider_title_5", "slider_5", "switch_container_6", "obj84", "switch_title_6", "slider_container_6", "slider_title_6", "slider_6", "button_container_17", "button_17", "button_title_17", "background_panel_36", "background_image_36", "obj85", "button_container_19", "button_title_19", "button_container_22", "button_title_22", "button_container_23", "button_title_23", "background_panel_37", "background_image_37", "obj86", "switch_container_3", "obj87", "switch_title_3", "button_container_20", "button_20", "button_title_20", "button_container_21", "button_21", "button_title_21", "button_container_36", "button_36", "button_title_36", "background_panel_38", "background_image_38", "obj88", "dropdown_container_13", "roller_title_13", "dropdown_container_14", "roller_title_14", "dropdown_container_15", "roller_title_15", "background_panel_39", "background_image_39", "obj89", "dropdown_container_16", "roller_title_16", "button_container_27", "button_27", "button_title_27", "button_container_33", "button_33", "button_title_33", "button_container_44", "button_title_44", "button_container_31", "button_title_31", "background_panel_47", "background_image_47", "obj90", "button_container_51", "button_51", "button_title_51", "button_container_52", "button_52", "button_title_52", "button_container_53", "button_53", "button_title_53", "button_container_54", "button_54", "button_title_54", "button_container_55", "button_55", "button_title_55", "button_container_56", "button_56", "button_title_56", "button_container_57", "button_57", "button_title_57", "button_container_58", "button_58", "button_title_58", "background_panel_40", "background_image_40", "obj91", "button_container_32", "button_32", "button_title_32", "background_panel_28", "background_image_28", "obj92", "switch_container_7", "obj93", "switch_title_7", "switch_container_4", "obj94", "switch_title_4", "button_container_28", "button_28", "button_title_28", "button_container_30", "button_30", "button_title_30", "button_container_34", "button_34", "button_title_34", "button_container_37", "button_37", "button_title_37", "question_container_8", "obj95", "background_panel_44", "background_image_44", "obj96", "button_container_46", "button_title_46", "button_container_50", "button_50", "button_title_50", "background_panel_45", "background_image_45", "obj97", "button_container_47", "button_47", "button_title_47", "button_container_48", "button_48", "button_title_48", "button_container_49", "button_49", "button_title_49", "background_panel_42", "background_image_42", "obj98", "button_container_38", "button_38", "button_title_38", "button_container_40", "button_title_40", "button_container_39", "button_title_39", "background_panel_43", "background_image_43", "obj99", "button_container_41", "button_41", "button_title_41", "button_container_43", "button_title_43", "button_container_42", "button_title_42", "checkbox_contatiner_3", "checkbox_3", "checkbox_title_3", "background_panel_16", "background_image_16", "choose_roller_3", "background_panel_46", "background_image_46", "obj100", "button_container_7", "button_7", "button_title_7", "background_panel_12", "background_image_12", "switch_container", "obj101", "switch_title", "checkbox_contatiner", "checkbox", "checkbox_title", "slider_container", "slider_title", "slider", "button_container", "button", "button_title", "question_container", "obj102", "obj103", "question_container_1", "obj104", "question_container_2", "obj105", "question_container_6", "obj106", "background_panel_32", "background_image_32", "dropdown_container_2", "roller_title_1", "roller_container_2", "roller_title_2", "roller_2" };
static const char *style_names[] = { "Gold", "Braun", "GoldSelBraun", "GoldTextArea", "GoldKeyboard", "goldPanel", "GoldDropdown^" };


typedef void (*create_screen_func_t)();
create_screen_func_t create_screen_funcs[] = {
    create_screen_idle_screen,
    create_screen_loading_screen,
    create_screen_menu_screen,
    create_screen_choose_player_screen,
    create_screen_choose_game_screen,
    create_screen_highscore_game_screen,
    create_screen_highscore_screen,
    create_screen_keyboard_screen,
    create_screen_numpad_screen,
    create_screen_okay_screen,
    create_screen_game1,
    create_screen_game_win_lose,
    create_screen_useroptionen1,
    create_screen_useroptionen1_spiele,
    create_screen_useroptionen1_spiele_lichtloser,
    create_screen_optionen_quickstart_player,
    create_screen_optionen_quickstart_game,
    create_screen_optionen_quickstart_modus,
    create_screen_adminoptionen1,
    create_screen_adminoptionen1_spiele,
    create_screen_adminoptionen1_spiele_lichtloser,
    create_screen_adminoptionen1_spiele_lichtloser_joker,
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
    delete_screen_loading_screen,
    delete_screen_menu_screen,
    delete_screen_choose_player_screen,
    delete_screen_choose_game_screen,
    delete_screen_highscore_game_screen,
    delete_screen_highscore_screen,
    delete_screen_keyboard_screen,
    delete_screen_numpad_screen,
    delete_screen_okay_screen,
    delete_screen_game1,
    delete_screen_game_win_lose,
    delete_screen_useroptionen1,
    delete_screen_useroptionen1_spiele,
    delete_screen_useroptionen1_spiele_lichtloser,
    delete_screen_optionen_quickstart_player,
    delete_screen_optionen_quickstart_game,
    delete_screen_optionen_quickstart_modus,
    delete_screen_adminoptionen1,
    delete_screen_adminoptionen1_spiele,
    delete_screen_adminoptionen1_spiele_lichtloser,
    delete_screen_adminoptionen1_spiele_lichtloser_joker,
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
    tick_screen_loading_screen,
    tick_screen_menu_screen,
    tick_screen_choose_player_screen,
    tick_screen_choose_game_screen,
    tick_screen_highscore_game_screen,
    tick_screen_highscore_screen,
    tick_screen_keyboard_screen,
    tick_screen_numpad_screen,
    tick_screen_okay_screen,
    tick_screen_game1,
    tick_screen_game_win_lose,
    tick_screen_useroptionen1,
    tick_screen_useroptionen1_spiele,
    tick_screen_useroptionen1_spiele_lichtloser,
    tick_screen_optionen_quickstart_player,
    tick_screen_optionen_quickstart_game,
    tick_screen_optionen_quickstart_modus,
    tick_screen_adminoptionen1,
    tick_screen_adminoptionen1_spiele,
    tick_screen_adminoptionen1_spiele_lichtloser,
    tick_screen_adminoptionen1_spiele_lichtloser_joker,
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
    create_screen_loading_screen();
    create_screen_menu_screen();
    create_screen_choose_player_screen();
    create_screen_choose_game_screen();
    create_screen_highscore_game_screen();
    create_screen_highscore_screen();
    create_screen_keyboard_screen();
    create_screen_numpad_screen();
    create_screen_okay_screen();
    create_screen_game1();
    create_screen_game_win_lose();
    create_screen_useroptionen1();
    create_screen_useroptionen1_spiele();
    create_screen_useroptionen1_spiele_lichtloser();
    create_screen_optionen_quickstart_player();
    create_screen_optionen_quickstart_game();
    create_screen_optionen_quickstart_modus();
    create_screen_adminoptionen1();
    create_screen_adminoptionen1_spiele();
    create_screen_adminoptionen1_spiele_lichtloser();
    create_screen_adminoptionen1_spiele_lichtloser_joker();
    create_screen_adminoptionen1_farbeneffekte();
    create_screen_adminoptionen1_farbeneffekte_winlose();
    create_screen_adminoptionen1_farbeneffekte_spielerfarbe();
    create_screen_adminoptionen1_farbeneffekte_grenzfarbe();
    create_screen_adminoptionen1_system();
    create_screen_adminoptionen1_system_leds();
    create_screen_adminoptionen1_system_leds_helligkeit();
    create_screen_adminoptionen1_system_anzeige();
    create_screen_adminoptionen1_system_anzeige_idle();
    create_screen_adminoptionen1_system_audio();
    create_screen_adminoptionen1_system_netzwerk();
    create_screen_adminoptionen1_system_netzwerk_wifi();
    create_screen_adminoptionen1_system_netzwerk_kommunikation();
    create_screen_adminoptionen1_system_netzwerk_update();
    create_screen_adminoptionen1_system_netzwerk_update_manifest();
    create_screen_adminoptionen1_system_netzwerk_update_firmware();
    create_screen_adminoptionen1_system_debug();
    create_screen_adminoptionen1_system_debug2();
    create_screen_adminoptionen1_system_debug2_tests();
    create_screen_adminoptionen1_system2();
    create_screen_adminoptionen1_system2_profil();
    create_screen_adminoptionen1_system2_profil_profilladen();
    create_screen_adminoptionen1_bonus();
    create_screen_optionen_template();
    create_screen_optionen_template_2();
}
