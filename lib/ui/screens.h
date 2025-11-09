#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *idle_screen;
    lv_obj_t *logo_screen;
    lv_obj_t *loading_screen;
    lv_obj_t *menu_screen;
    lv_obj_t *choose_player_screen;
    lv_obj_t *choose_game_screen;
    lv_obj_t *choose_game_mod;
    lv_obj_t *keyboard_screen;
    lv_obj_t *numpad_screen;
    lv_obj_t *okay_screen;
    lv_obj_t *game_lichtloser;
    lv_obj_t *game_win;
    lv_obj_t *game_lose;
    lv_obj_t *useroptionen1;
    lv_obj_t *useroptionen1_spiele;
    lv_obj_t *useroptionen1_spiele_lichtloser;
    lv_obj_t *adminoptionen1;
    lv_obj_t *adminoptionen1_spiele;
    lv_obj_t *adminoptionen1_spiele_lichtloser;
    lv_obj_t *adminoptionen1_spiele_lichtloser_joker;
    lv_obj_t *adminoptionen1_spiele_lichtloser_timings;
    lv_obj_t *adminoptionen1_farbeneffekte;
    lv_obj_t *adminoptionen1_farbeneffekte_winlose;
    lv_obj_t *adminoptionen1_farbeneffekte_spielerfarbe;
    lv_obj_t *adminoptionen1_farbeneffekte_grenzfarbe;
    lv_obj_t *adminoptionen1_system;
    lv_obj_t *adminoptionen1_system_leds;
    lv_obj_t *adminoptionen1_system_leds_helligkeit;
    lv_obj_t *adminoptionen1_system_anzeige;
    lv_obj_t *adminoptionen1_system_anzeige_idle;
    lv_obj_t *adminoptionen1_system_audio;
    lv_obj_t *adminoptionen1_system_netzwerk;
    lv_obj_t *adminoptionen1_system_netzwerk_wifi;
    lv_obj_t *adminoptionen1_system_netzwerk_kommunikation;
    lv_obj_t *adminoptionen1_system_netzwerk_update;
    lv_obj_t *adminoptionen1_system_netzwerk_update_manifest;
    lv_obj_t *adminoptionen1_system_netzwerk_update_firmware;
    lv_obj_t *adminoptionen1_system_debug;
    lv_obj_t *adminoptionen1_system_debug2;
    lv_obj_t *adminoptionen1_system_debug2_tests;
    lv_obj_t *adminoptionen1_system2;
    lv_obj_t *adminoptionen1_system2_profil;
    lv_obj_t *adminoptionen1_system2_profil_profilladen;
    lv_obj_t *adminoptionen1_bonus;
    lv_obj_t *optionen_template;
    lv_obj_t *optionen_template_2;
    lv_obj_t *obj0;
    lv_obj_t *obj0__background_panel_1;
    lv_obj_t *obj1;
    lv_obj_t *obj1__background_panel_1;
    lv_obj_t *obj2;
    lv_obj_t *obj2__background_panel_1;
    lv_obj_t *obj3;
    lv_obj_t *obj3__background_panel_1;
    lv_obj_t *obj4;
    lv_obj_t *obj4__background_panel_1;
    lv_obj_t *obj5;
    lv_obj_t *obj5__background_panel_1;
    lv_obj_t *obj6;
    lv_obj_t *obj6__background_panel_1;
    lv_obj_t *obj7;
    lv_obj_t *obj7__background_panel_1;
    lv_obj_t *obj8;
    lv_obj_t *obj8__background_panel_1;
    lv_obj_t *obj9;
    lv_obj_t *obj9__background_panel_1;
    lv_obj_t *obj10;
    lv_obj_t *obj10__background_panel_1;
    lv_obj_t *obj11;
    lv_obj_t *obj11__background_panel_1;
    lv_obj_t *obj12;
    lv_obj_t *obj12__background_panel_1;
    lv_obj_t *obj13;
    lv_obj_t *obj13__background_panel_1;
    lv_obj_t *obj14;
    lv_obj_t *obj14__background_panel_1;
    lv_obj_t *obj15;
    lv_obj_t *obj15__background_panel_1;
    lv_obj_t *obj16;
    lv_obj_t *obj16__background_panel_1;
    lv_obj_t *obj17;
    lv_obj_t *obj17__background_panel_1;
    lv_obj_t *obj18;
    lv_obj_t *obj18__background_panel_1;
    lv_obj_t *obj19;
    lv_obj_t *obj19__background_panel_1;
    lv_obj_t *obj20;
    lv_obj_t *obj20__background_panel_1;
    lv_obj_t *obj21;
    lv_obj_t *obj21__background_panel_1;
    lv_obj_t *obj22;
    lv_obj_t *obj22__background_panel_1;
    lv_obj_t *obj23;
    lv_obj_t *obj23__background_panel_1;
    lv_obj_t *obj24;
    lv_obj_t *obj24__background_panel_1;
    lv_obj_t *obj25;
    lv_obj_t *obj25__background_panel_1;
    lv_obj_t *obj26;
    lv_obj_t *obj26__background_panel_1;
    lv_obj_t *obj27;
    lv_obj_t *obj27__background_panel_1;
    lv_obj_t *obj28;
    lv_obj_t *obj28__background_panel_1;
    lv_obj_t *obj29;
    lv_obj_t *obj29__background_panel_1;
    lv_obj_t *obj30;
    lv_obj_t *obj30__background_panel_1;
    lv_obj_t *obj31;
    lv_obj_t *obj31__background_panel_1;
    lv_obj_t *obj32;
    lv_obj_t *obj32__background_panel_1;
    lv_obj_t *obj33;
    lv_obj_t *obj33__background_panel_1;
    lv_obj_t *obj34;
    lv_obj_t *obj34__background_panel_1;
    lv_obj_t *obj35;
    lv_obj_t *obj35__background_panel_1;
    lv_obj_t *obj36;
    lv_obj_t *obj36__background_panel_1;
    lv_obj_t *obj37;
    lv_obj_t *obj37__background_panel_1;
    lv_obj_t *obj38;
    lv_obj_t *obj38__background_panel_1;
    lv_obj_t *obj39;
    lv_obj_t *obj39__background_panel_1;
    lv_obj_t *obj40;
    lv_obj_t *obj40__background_panel_1;
    lv_obj_t *obj41;
    lv_obj_t *obj41__background_panel_1;
    lv_obj_t *obj42;
    lv_obj_t *obj42__background_panel_1;
    lv_obj_t *obj43;
    lv_obj_t *obj43__background_panel_1;
    lv_obj_t *obj44;
    lv_obj_t *obj44__background_panel_1;
    lv_obj_t *obj45;
    lv_obj_t *obj45__background_panel_1;
    lv_obj_t *obj46;
    lv_obj_t *start;
    lv_obj_t *optionen;
    lv_obj_t *optionen_1;
    lv_obj_t *player_roller;
    lv_obj_t *obj47;
    lv_obj_t *obj48;
    lv_obj_t *obj49;
    lv_obj_t *game_roller;
    lv_obj_t *obj50;
    lv_obj_t *obj51;
    lv_obj_t *obj52;
    lv_obj_t *obj53;
    lv_obj_t *obj54;
    lv_obj_t *obj55;
    lv_obj_t *obj56;
    lv_obj_t *score_player1;
    lv_obj_t *score_panel1;
    lv_obj_t *score1;
    lv_obj_t *score_player2;
    lv_obj_t *score_panel2;
    lv_obj_t *score2;
    lv_obj_t *score_player3;
    lv_obj_t *score_panel3;
    lv_obj_t *score3;
    lv_obj_t *score_player4;
    lv_obj_t *score_panel4;
    lv_obj_t *score4;
    lv_obj_t *score_player5;
    lv_obj_t *score_panel5;
    lv_obj_t *score5;
    lv_obj_t *score_player6;
    lv_obj_t *score_panel6;
    lv_obj_t *score6;
    lv_obj_t *obj57;
    lv_obj_t *button_game;
    lv_obj_t *obj58;
    lv_obj_t *obj59;
    lv_obj_t *button_10;
    lv_obj_t *obj60;
    lv_obj_t *obj61;
    lv_obj_t *options_game_roller;
    lv_obj_t *obj62;
    lv_obj_t *obj63;
    lv_obj_t *button_3;
    lv_obj_t *button_5;
    lv_obj_t *button_6;
    lv_obj_t *button_9;
    lv_obj_t *obj64;
    lv_obj_t *obj65;
    lv_obj_t *options_game_roller_1;
    lv_obj_t *obj66;
    lv_obj_t *obj67;
    lv_obj_t *slider_lichtloserrounds;
    lv_obj_t *button_1;
    lv_obj_t *button_4;
    lv_obj_t *obj68;
    lv_obj_t *obj69;
    lv_obj_t *obj70;
    lv_obj_t *obj71;
    lv_obj_t *obj72;
    lv_obj_t *button_24;
    lv_obj_t *button_25;
    lv_obj_t *button_26;
    lv_obj_t *obj73;
    lv_obj_t *obj74;
    lv_obj_t *obj75;
    lv_obj_t *obj76;
    lv_obj_t *obj77;
    lv_obj_t *obj78;
    lv_obj_t *obj79;
    lv_obj_t *checkbox_2;
    lv_obj_t *obj80;
    lv_obj_t *obj81;
    lv_obj_t *obj82;
    lv_obj_t *obj83;
    lv_obj_t *obj84;
    lv_obj_t *button_12;
    lv_obj_t *button_13;
    lv_obj_t *button_16;
    lv_obj_t *button_14;
    lv_obj_t *button_15;
    lv_obj_t *obj85;
    lv_obj_t *obj86;
    lv_obj_t *button_18;
    lv_obj_t *obj87;
    lv_obj_t *obj88;
    lv_obj_t *slider_2;
    lv_obj_t *slider_3;
    lv_obj_t *obj89;
    lv_obj_t *slider_4;
    lv_obj_t *button_29;
    lv_obj_t *obj90;
    lv_obj_t *obj91;
    lv_obj_t *obj92;
    lv_obj_t *obj93;
    lv_obj_t *obj94;
    lv_obj_t *checkbox_1;
    lv_obj_t *obj95;
    lv_obj_t *obj96;
    lv_obj_t *button_19;
    lv_obj_t *button_22;
    lv_obj_t *button_23;
    lv_obj_t *obj97;
    lv_obj_t *obj98;
    lv_obj_t *obj99;
    lv_obj_t *button_44;
    lv_obj_t *button_31;
    lv_obj_t *obj100;
    lv_obj_t *obj101;
    lv_obj_t *obj102;
    lv_obj_t *obj103;
    lv_obj_t *obj104;
    lv_obj_t *button_46;
    lv_obj_t *obj105;
    lv_obj_t *button_49;
    lv_obj_t *button_40;
    lv_obj_t *button_39;
    lv_obj_t *obj106;
    lv_obj_t *obj107;
    lv_obj_t *button_43;
    lv_obj_t *button_42;
    lv_obj_t *obj108;
    lv_obj_t *obj109;
    lv_obj_t *button_7;
    lv_obj_t *obj110;
    lv_obj_t *obj111;
    lv_obj_t *obj112;
    lv_obj_t *obj113;
    lv_obj_t *obj114;
    lv_obj_t *obj115;
    lv_obj_t *start_idle;
    lv_obj_t *version;
    lv_obj_t *logo;
    lv_obj_t *obj116;
    lv_obj_t *news_container;
    lv_obj_t *news_panel;
    lv_obj_t *news;
    lv_obj_t *obj117;
    lv_obj_t *obj118;
    lv_obj_t *obj119;
    lv_obj_t *game_roller_5;
    lv_obj_t *keyboard_area;
    lv_obj_t *keyboard;
    lv_obj_t *keyboard_title;
    lv_obj_t *numpad_area;
    lv_obj_t *numpad;
    lv_obj_t *numpad_title;
    lv_obj_t *ja_panel;
    lv_obj_t *nein_panel;
    lv_obj_t *scores;
    lv_obj_t *button_container_2;
    lv_obj_t *button_title_2;
    lv_obj_t *win_lose_container;
    lv_obj_t *win_container;
    lv_obj_t *win_panel;
    lv_obj_t *lose_anzeige_panel;
    lv_obj_t *lose_anzeige_title;
    lv_obj_t *win_lose_container_1;
    lv_obj_t *win_container_1;
    lv_obj_t *lose_panel;
    lv_obj_t *win_anzeige_panel;
    lv_obj_t *lose_anzeige_title_1;
    lv_obj_t *obj120;
    lv_obj_t *button_container_10;
    lv_obj_t *button_title_10;
    lv_obj_t *obj121;
    lv_obj_t *dropdown_container_22;
    lv_obj_t *roller_title_22;
    lv_obj_t *obj122;
    lv_obj_t *button_container_3;
    lv_obj_t *button_title_3;
    lv_obj_t *button_container_5;
    lv_obj_t *button_title_5;
    lv_obj_t *button_container_6;
    lv_obj_t *button_title_6;
    lv_obj_t *button_container_9;
    lv_obj_t *button_title_9;
    lv_obj_t *obj123;
    lv_obj_t *dropdown_container_19;
    lv_obj_t *roller_title_19;
    lv_obj_t *slider_container_1;
    lv_obj_t *slider_title_7;
    lv_obj_t *slider_title_1;
    lv_obj_t *button_container_1;
    lv_obj_t *button_title_1;
    lv_obj_t *button_container_4;
    lv_obj_t *button_title_4;
    lv_obj_t *obj124;
    lv_obj_t *switch_container_1;
    lv_obj_t *switch_title_1;
    lv_obj_t *dropdown_container_3;
    lv_obj_t *roller_title_3;
    lv_obj_t *obj125;
    lv_obj_t *slider_container_7;
    lv_obj_t *slider_title_11;
    lv_obj_t *slider_7;
    lv_obj_t *slider_title_12;
    lv_obj_t *slider_title_13;
    lv_obj_t *slider_title_14;
    lv_obj_t *slider_container_8;
    lv_obj_t *slider_title_15;
    lv_obj_t *slider_8;
    lv_obj_t *slider_title_16;
    lv_obj_t *slider_title_17;
    lv_obj_t *slider_title_18;
    lv_obj_t *slider_container_9;
    lv_obj_t *slider_title_19;
    lv_obj_t *slider_9;
    lv_obj_t *slider_title_20;
    lv_obj_t *slider_title_21;
    lv_obj_t *slider_title_22;
    lv_obj_t *slider_container_10;
    lv_obj_t *slider_title_23;
    lv_obj_t *slider_1;
    lv_obj_t *slider_title_24;
    lv_obj_t *slider_title_25;
    lv_obj_t *obj126;
    lv_obj_t *button_container_24;
    lv_obj_t *button_title_24;
    lv_obj_t *button_container_25;
    lv_obj_t *button_title_25;
    lv_obj_t *button_container_26;
    lv_obj_t *button_title_26;
    lv_obj_t *obj127;
    lv_obj_t *dropdown_container_5;
    lv_obj_t *roller_title_5;
    lv_obj_t *dropdown_container_6;
    lv_obj_t *roller_title_6;
    lv_obj_t *dropdown_container_7;
    lv_obj_t *roller_title_7;
    lv_obj_t *dropdown_container_8;
    lv_obj_t *roller_title_8;
    lv_obj_t *obj128;
    lv_obj_t *dropdown_container_9;
    lv_obj_t *roller_title_9;
    lv_obj_t *dropdown_container_10;
    lv_obj_t *roller_title_10;
    lv_obj_t *checkbox_contatiner_2;
    lv_obj_t *checkbox_title_2;
    lv_obj_t *dropdown_container_17;
    lv_obj_t *roller_title_17;
    lv_obj_t *obj129;
    lv_obj_t *dropdown_container_11;
    lv_obj_t *roller_title_11;
    lv_obj_t *dropdown_container_12;
    lv_obj_t *roller_title_12;
    lv_obj_t *obj130;
    lv_obj_t *button_container_12;
    lv_obj_t *button_title_12;
    lv_obj_t *button_container_13;
    lv_obj_t *button_title_13;
    lv_obj_t *button_container_16;
    lv_obj_t *button_title_16;
    lv_obj_t *button_container_14;
    lv_obj_t *button_title_14;
    lv_obj_t *button_container_15;
    lv_obj_t *button_title_15;
    lv_obj_t *question_container_7;
    lv_obj_t *obj131;
    lv_obj_t *obj132;
    lv_obj_t *button_container_18;
    lv_obj_t *button_title_18;
    lv_obj_t *obj133;
    lv_obj_t *slider_container_2;
    lv_obj_t *slider_title_2;
    lv_obj_t *slider_title_8;
    lv_obj_t *slider_container_3;
    lv_obj_t *slider_title_3;
    lv_obj_t *slider_title_9;
    lv_obj_t *obj134;
    lv_obj_t *slider_container_4;
    lv_obj_t *slider_title_4;
    lv_obj_t *slider_title_10;
    lv_obj_t *button_container_29;
    lv_obj_t *button_title_29;
    lv_obj_t *obj135;
    lv_obj_t *switch_container_2;
    lv_obj_t *switch_title_2;
    lv_obj_t *dropdown_container_4;
    lv_obj_t *roller_title_4;
    lv_obj_t *checkbox_contatiner_1;
    lv_obj_t *checkbox_title_1;
    lv_obj_t *obj136;
    lv_obj_t *switch_container_5;
    lv_obj_t *obj137;
    lv_obj_t *switch_title_5;
    lv_obj_t *slider_container_5;
    lv_obj_t *slider_title_5;
    lv_obj_t *slider_5;
    lv_obj_t *switch_container_6;
    lv_obj_t *obj138;
    lv_obj_t *switch_title_6;
    lv_obj_t *slider_container_6;
    lv_obj_t *slider_title_6;
    lv_obj_t *slider_6;
    lv_obj_t *button_container_17;
    lv_obj_t *button_17;
    lv_obj_t *button_title_17;
    lv_obj_t *obj139;
    lv_obj_t *button_container_19;
    lv_obj_t *button_title_19;
    lv_obj_t *button_container_22;
    lv_obj_t *button_title_22;
    lv_obj_t *button_container_23;
    lv_obj_t *button_title_23;
    lv_obj_t *obj140;
    lv_obj_t *switch_container_3;
    lv_obj_t *obj141;
    lv_obj_t *switch_title_3;
    lv_obj_t *button_container_20;
    lv_obj_t *button_20;
    lv_obj_t *button_title_20;
    lv_obj_t *button_container_21;
    lv_obj_t *button_21;
    lv_obj_t *button_title_21;
    lv_obj_t *button_container_36;
    lv_obj_t *button_36;
    lv_obj_t *button_title_36;
    lv_obj_t *obj142;
    lv_obj_t *dropdown_container_13;
    lv_obj_t *roller_title_13;
    lv_obj_t *dropdown_container_14;
    lv_obj_t *roller_title_14;
    lv_obj_t *dropdown_container_15;
    lv_obj_t *roller_title_15;
    lv_obj_t *obj143;
    lv_obj_t *dropdown_container_16;
    lv_obj_t *roller_title_16;
    lv_obj_t *button_container_27;
    lv_obj_t *button_27;
    lv_obj_t *button_title_27;
    lv_obj_t *button_container_33;
    lv_obj_t *button_33;
    lv_obj_t *button_title_33;
    lv_obj_t *button_container_44;
    lv_obj_t *button_title_44;
    lv_obj_t *button_container_31;
    lv_obj_t *button_title_31;
    lv_obj_t *obj144;
    lv_obj_t *button_container_51;
    lv_obj_t *button_51;
    lv_obj_t *button_title_51;
    lv_obj_t *button_container_52;
    lv_obj_t *button_52;
    lv_obj_t *button_title_52;
    lv_obj_t *button_container_53;
    lv_obj_t *button_53;
    lv_obj_t *button_title_53;
    lv_obj_t *button_container_54;
    lv_obj_t *button_54;
    lv_obj_t *button_title_54;
    lv_obj_t *button_container_55;
    lv_obj_t *button_55;
    lv_obj_t *button_title_55;
    lv_obj_t *button_container_56;
    lv_obj_t *button_56;
    lv_obj_t *button_title_56;
    lv_obj_t *button_container_57;
    lv_obj_t *button_57;
    lv_obj_t *button_title_57;
    lv_obj_t *button_container_58;
    lv_obj_t *button_58;
    lv_obj_t *button_title_58;
    lv_obj_t *obj145;
    lv_obj_t *button_container_32;
    lv_obj_t *button_32;
    lv_obj_t *button_title_32;
    lv_obj_t *obj146;
    lv_obj_t *switch_container_7;
    lv_obj_t *obj147;
    lv_obj_t *switch_title_7;
    lv_obj_t *switch_container_4;
    lv_obj_t *obj148;
    lv_obj_t *switch_title_4;
    lv_obj_t *button_container_28;
    lv_obj_t *button_28;
    lv_obj_t *button_title_28;
    lv_obj_t *button_container_30;
    lv_obj_t *button_30;
    lv_obj_t *button_title_30;
    lv_obj_t *button_container_34;
    lv_obj_t *button_34;
    lv_obj_t *button_title_34;
    lv_obj_t *button_container_37;
    lv_obj_t *button_37;
    lv_obj_t *button_title_37;
    lv_obj_t *question_container_8;
    lv_obj_t *obj149;
    lv_obj_t *obj150;
    lv_obj_t *button_container_46;
    lv_obj_t *button_title_46;
    lv_obj_t *button_container_50;
    lv_obj_t *button_50;
    lv_obj_t *button_title_50;
    lv_obj_t *obj151;
    lv_obj_t *button_container_47;
    lv_obj_t *button_47;
    lv_obj_t *button_title_47;
    lv_obj_t *button_container_48;
    lv_obj_t *button_48;
    lv_obj_t *button_title_48;
    lv_obj_t *button_container_49;
    lv_obj_t *button_title_49;
    lv_obj_t *obj152;
    lv_obj_t *button_container_38;
    lv_obj_t *button_38;
    lv_obj_t *button_title_38;
    lv_obj_t *button_container_40;
    lv_obj_t *button_title_40;
    lv_obj_t *button_container_39;
    lv_obj_t *button_title_39;
    lv_obj_t *obj153;
    lv_obj_t *button_container_41;
    lv_obj_t *button_41;
    lv_obj_t *button_title_41;
    lv_obj_t *button_container_43;
    lv_obj_t *button_title_43;
    lv_obj_t *button_container_42;
    lv_obj_t *button_title_42;
    lv_obj_t *checkbox_contatiner_3;
    lv_obj_t *checkbox_3;
    lv_obj_t *checkbox_title_3;
    lv_obj_t *choose_roller_3;
    lv_obj_t *obj154;
    lv_obj_t *button_container_7;
    lv_obj_t *button_title_7;
    lv_obj_t *switch_container;
    lv_obj_t *obj155;
    lv_obj_t *switch_title;
    lv_obj_t *checkbox_contatiner;
    lv_obj_t *checkbox;
    lv_obj_t *checkbox_title;
    lv_obj_t *slider_container;
    lv_obj_t *slider_title;
    lv_obj_t *slider;
    lv_obj_t *button_container;
    lv_obj_t *button;
    lv_obj_t *button_title;
    lv_obj_t *question_container;
    lv_obj_t *obj156;
    lv_obj_t *obj157;
    lv_obj_t *question_container_1;
    lv_obj_t *obj158;
    lv_obj_t *question_container_2;
    lv_obj_t *obj159;
    lv_obj_t *question_container_6;
    lv_obj_t *obj160;
    lv_obj_t *dropdown_container_2;
    lv_obj_t *roller_title_1;
    lv_obj_t *roller_container_2;
    lv_obj_t *roller_title_2;
    lv_obj_t *roller_2;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_IDLE_SCREEN = 1,
    SCREEN_ID_LOGO_SCREEN = 2,
    SCREEN_ID_LOADING_SCREEN = 3,
    SCREEN_ID_MENU_SCREEN = 4,
    SCREEN_ID_CHOOSE_PLAYER_SCREEN = 5,
    SCREEN_ID_CHOOSE_GAME_SCREEN = 6,
    SCREEN_ID_CHOOSE_GAME_MOD = 7,
    SCREEN_ID_KEYBOARD_SCREEN = 8,
    SCREEN_ID_NUMPAD_SCREEN = 9,
    SCREEN_ID_OKAY_SCREEN = 10,
    SCREEN_ID_GAME_LICHTLOSER = 11,
    SCREEN_ID_GAME_WIN = 12,
    SCREEN_ID_GAME_LOSE = 13,
    SCREEN_ID_USEROPTIONEN1 = 14,
    SCREEN_ID_USEROPTIONEN1_SPIELE = 15,
    SCREEN_ID_USEROPTIONEN1_SPIELE_LICHTLOSER = 16,
    SCREEN_ID_ADMINOPTIONEN1 = 17,
    SCREEN_ID_ADMINOPTIONEN1_SPIELE = 18,
    SCREEN_ID_ADMINOPTIONEN1_SPIELE_LICHTLOSER = 19,
    SCREEN_ID_ADMINOPTIONEN1_SPIELE_LICHTLOSER_JOKER = 20,
    SCREEN_ID_ADMINOPTIONEN1_SPIELE_LICHTLOSER_TIMINGS = 21,
    SCREEN_ID_ADMINOPTIONEN1_FARBENEFFEKTE = 22,
    SCREEN_ID_ADMINOPTIONEN1_FARBENEFFEKTE_WINLOSE = 23,
    SCREEN_ID_ADMINOPTIONEN1_FARBENEFFEKTE_SPIELERFARBE = 24,
    SCREEN_ID_ADMINOPTIONEN1_FARBENEFFEKTE_GRENZFARBE = 25,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM = 26,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM_LEDS = 27,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM_LEDS_HELLIGKEIT = 28,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM_ANZEIGE = 29,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM_ANZEIGE_IDLE = 30,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM_AUDIO = 31,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM_NETZWERK = 32,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM_NETZWERK_WIFI = 33,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM_NETZWERK_KOMMUNIKATION = 34,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM_NETZWERK_UPDATE = 35,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM_NETZWERK_UPDATE_MANIFEST = 36,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM_NETZWERK_UPDATE_FIRMWARE = 37,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM_DEBUG = 38,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM_DEBUG2 = 39,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM_DEBUG2_TESTS = 40,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM2 = 41,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM2_PROFIL = 42,
    SCREEN_ID_ADMINOPTIONEN1_SYSTEM2_PROFIL_PROFILLADEN = 43,
    SCREEN_ID_ADMINOPTIONEN1_BONUS = 44,
    SCREEN_ID_OPTIONEN_TEMPLATE = 45,
    SCREEN_ID_OPTIONEN_TEMPLATE_2 = 46,
};

void create_screen_idle_screen();
void delete_screen_idle_screen();
void tick_screen_idle_screen();

void create_screen_logo_screen();
void delete_screen_logo_screen();
void tick_screen_logo_screen();

void create_screen_loading_screen();
void delete_screen_loading_screen();
void tick_screen_loading_screen();

void create_screen_menu_screen();
void delete_screen_menu_screen();
void tick_screen_menu_screen();

void create_screen_choose_player_screen();
void delete_screen_choose_player_screen();
void tick_screen_choose_player_screen();

void create_screen_choose_game_screen();
void delete_screen_choose_game_screen();
void tick_screen_choose_game_screen();

void create_screen_choose_game_mod();
void delete_screen_choose_game_mod();
void tick_screen_choose_game_mod();

void create_screen_keyboard_screen();
void delete_screen_keyboard_screen();
void tick_screen_keyboard_screen();

void create_screen_numpad_screen();
void delete_screen_numpad_screen();
void tick_screen_numpad_screen();

void create_screen_okay_screen();
void delete_screen_okay_screen();
void tick_screen_okay_screen();

void create_screen_game_lichtloser();
void delete_screen_game_lichtloser();
void tick_screen_game_lichtloser();

void create_screen_game_win();
void delete_screen_game_win();
void tick_screen_game_win();

void create_screen_game_lose();
void delete_screen_game_lose();
void tick_screen_game_lose();

void create_screen_useroptionen1();
void delete_screen_useroptionen1();
void tick_screen_useroptionen1();

void create_screen_useroptionen1_spiele();
void delete_screen_useroptionen1_spiele();
void tick_screen_useroptionen1_spiele();

void create_screen_useroptionen1_spiele_lichtloser();
void delete_screen_useroptionen1_spiele_lichtloser();
void tick_screen_useroptionen1_spiele_lichtloser();

void create_screen_adminoptionen1();
void delete_screen_adminoptionen1();
void tick_screen_adminoptionen1();

void create_screen_adminoptionen1_spiele();
void delete_screen_adminoptionen1_spiele();
void tick_screen_adminoptionen1_spiele();

void create_screen_adminoptionen1_spiele_lichtloser();
void delete_screen_adminoptionen1_spiele_lichtloser();
void tick_screen_adminoptionen1_spiele_lichtloser();

void create_screen_adminoptionen1_spiele_lichtloser_joker();
void delete_screen_adminoptionen1_spiele_lichtloser_joker();
void tick_screen_adminoptionen1_spiele_lichtloser_joker();

void create_screen_adminoptionen1_spiele_lichtloser_timings();
void delete_screen_adminoptionen1_spiele_lichtloser_timings();
void tick_screen_adminoptionen1_spiele_lichtloser_timings();

void create_screen_adminoptionen1_farbeneffekte();
void delete_screen_adminoptionen1_farbeneffekte();
void tick_screen_adminoptionen1_farbeneffekte();

void create_screen_adminoptionen1_farbeneffekte_winlose();
void delete_screen_adminoptionen1_farbeneffekte_winlose();
void tick_screen_adminoptionen1_farbeneffekte_winlose();

void create_screen_adminoptionen1_farbeneffekte_spielerfarbe();
void delete_screen_adminoptionen1_farbeneffekte_spielerfarbe();
void tick_screen_adminoptionen1_farbeneffekte_spielerfarbe();

void create_screen_adminoptionen1_farbeneffekte_grenzfarbe();
void delete_screen_adminoptionen1_farbeneffekte_grenzfarbe();
void tick_screen_adminoptionen1_farbeneffekte_grenzfarbe();

void create_screen_adminoptionen1_system();
void delete_screen_adminoptionen1_system();
void tick_screen_adminoptionen1_system();

void create_screen_adminoptionen1_system_leds();
void delete_screen_adminoptionen1_system_leds();
void tick_screen_adminoptionen1_system_leds();

void create_screen_adminoptionen1_system_leds_helligkeit();
void delete_screen_adminoptionen1_system_leds_helligkeit();
void tick_screen_adminoptionen1_system_leds_helligkeit();

void create_screen_adminoptionen1_system_anzeige();
void delete_screen_adminoptionen1_system_anzeige();
void tick_screen_adminoptionen1_system_anzeige();

void create_screen_adminoptionen1_system_anzeige_idle();
void delete_screen_adminoptionen1_system_anzeige_idle();
void tick_screen_adminoptionen1_system_anzeige_idle();

void create_screen_adminoptionen1_system_audio();
void delete_screen_adminoptionen1_system_audio();
void tick_screen_adminoptionen1_system_audio();

void create_screen_adminoptionen1_system_netzwerk();
void delete_screen_adminoptionen1_system_netzwerk();
void tick_screen_adminoptionen1_system_netzwerk();

void create_screen_adminoptionen1_system_netzwerk_wifi();
void delete_screen_adminoptionen1_system_netzwerk_wifi();
void tick_screen_adminoptionen1_system_netzwerk_wifi();

void create_screen_adminoptionen1_system_netzwerk_kommunikation();
void delete_screen_adminoptionen1_system_netzwerk_kommunikation();
void tick_screen_adminoptionen1_system_netzwerk_kommunikation();

void create_screen_adminoptionen1_system_netzwerk_update();
void delete_screen_adminoptionen1_system_netzwerk_update();
void tick_screen_adminoptionen1_system_netzwerk_update();

void create_screen_adminoptionen1_system_netzwerk_update_manifest();
void delete_screen_adminoptionen1_system_netzwerk_update_manifest();
void tick_screen_adminoptionen1_system_netzwerk_update_manifest();

void create_screen_adminoptionen1_system_netzwerk_update_firmware();
void delete_screen_adminoptionen1_system_netzwerk_update_firmware();
void tick_screen_adminoptionen1_system_netzwerk_update_firmware();

void create_screen_adminoptionen1_system_debug();
void delete_screen_adminoptionen1_system_debug();
void tick_screen_adminoptionen1_system_debug();

void create_screen_adminoptionen1_system_debug2();
void delete_screen_adminoptionen1_system_debug2();
void tick_screen_adminoptionen1_system_debug2();

void create_screen_adminoptionen1_system_debug2_tests();
void delete_screen_adminoptionen1_system_debug2_tests();
void tick_screen_adminoptionen1_system_debug2_tests();

void create_screen_adminoptionen1_system2();
void delete_screen_adminoptionen1_system2();
void tick_screen_adminoptionen1_system2();

void create_screen_adminoptionen1_system2_profil();
void delete_screen_adminoptionen1_system2_profil();
void tick_screen_adminoptionen1_system2_profil();

void create_screen_adminoptionen1_system2_profil_profilladen();
void delete_screen_adminoptionen1_system2_profil_profilladen();
void tick_screen_adminoptionen1_system2_profil_profilladen();

void create_screen_adminoptionen1_bonus();
void delete_screen_adminoptionen1_bonus();
void tick_screen_adminoptionen1_bonus();

void create_screen_optionen_template();
void delete_screen_optionen_template();
void tick_screen_optionen_template();

void create_screen_optionen_template_2();
void delete_screen_optionen_template_2();
void tick_screen_optionen_template_2();

void create_user_widget_background(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_background(void *flowState, int startWidgetIndex);

void create_user_widget_button(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_button(void *flowState, int startWidgetIndex);

void create_user_widget_info_widget(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_info_widget(void *flowState, int startWidgetIndex);

void create_screen_by_id(enum ScreensEnum screenId);
void delete_screen_by_id(enum ScreensEnum screenId);
void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/