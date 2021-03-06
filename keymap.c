/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keymap_spanish.h"


enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD,
  _PHPSTORM
};

#define TAB_NUM LT(_NUMPAD, KC_TAB)
#define TAB_LOWER LT(_LOWER, KC_ESC)
#define LY_PHPSTORM LT(_PHPSTORM, KC_ENT)
#define LY_ADJUST LT(_ADJUST, KC_ENT)
#define LY_RAISE LT(_RAISE, KC_TAB)


enum {
    TD_CAPLOCK,
    TD_MENU,
    TD_PHPSTORM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //     TAB ,    Q   ,    W   ,   E    ,   R    ,   T    ,                         Y   ,    U   ,    I   ,   O    ,   P    ,  DELET ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  // LSFT / MAYUS ,    A   ,    S   ,   D    ,   F    ,   G    ,                H   ,   J    ,    K   ,   L    ,   Ñ    ,   SUPR ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //  KC_LGUI ,    Z   ,    X   ,    C   ,    V   ,    B   ,                         N   ,   M    ,    ,   ,   .    ,   -    ,  ESC   ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                      CTL,  MO(1),   SPC   ,         ENT  ,   MO(2),     AWINDOWS
  //                                    `--------------------------'  `--------------------------'

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------.                    ,-------------------------------------------------------.
           TAB_NUM    ,   KC_Q  ,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC ,
  //|-----------------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+----------|
      TD(TD_CAPLOCK)  ,   KC_A  ,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, ES_NTIL, ES_ACUT ,
  //|-----------------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+----------|
          KC_LCTL     ,   KC_Z  ,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, ES_COMM,  ES_DOT, ES_MINS, KC_DEL  ,
  //|-----------------+---------+--------+--------+--------+--------+----------|  |--------+--------+--------+--------+--------+--------+--------|
                                                   KC_LALT, LY_RAISE , KC_SPC,    LY_PHPSTORM, TAB_LOWER , TD(TD_MENU)
                                                //`----------------------------'  `------------------------------'

  ),

  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //    TAB,      1   ,    2   ,   3    ,    4   ,    5   ,                         6   ,    7   ,    8   ,    9   ,    0   ,   BSPC ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //    LSFT , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //    LCTL , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                        LALT , _______,  KC_SPC,     KC_ENT,   MO(3), KC_LGUI

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------------------.                    ,-------------------------------------------------------------------.
          KC_TAB     ,  KC_F1   ,   KC_F2  ,   KC_F3  ,   KC_F4  ,   KC_F5  ,                         XXXXXXX  ,  XXXXXXX ,  XXXXXXX   ,  XXXXXXX  ,  XXXXXXX , KC_BSPC,
  //|--------+--------+--------+--------+--------+----------------------------|                    |--------+--------+--------+--------+--------+-----------------------|
      TD(TD_CAPLOCK) ,  KC_F6   ,   KC_F7  ,   KC_F8  ,   KC_F9  ,   KC_F10 ,                         XXXXXXX  ,  KC_HOME ,   KC_UP    ,  KC_END   ,  XXXXXXX , XXXXXXX,
  //|--------+--------+--------+--------+--------+----------------------------|                    |----------+---------+------------+----------+---------+-------------|
          KC_LCTL    ,  KC_F11  ,   KC_F12 ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,                         XXXXXXX  ,  KC_LEFT ,   KC_DOWN  ,  KC_RIGHT ,  XXXXXXX , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+---------------------------|  |--------+--------+--------+--------+--------+--------+------------------------|
                                                        KC_LALT, MO(_ADJUST),  KC_SPC,     KC_ENT, _______  , KC_LGUI
                                                         //`--------------------------'  `--------------------------'
  ),


  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //     TAB ,    !   ,   @    ,    #   ,    $   ,   %    ,                         '   ,   "    ,   (    ,    )   ,   /    ,   *   ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //    LSFT , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         $   ,    =   ,   [    ,   ]    ,    \   ,   `    ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //    LCTL , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        <    ,   >    ,    {   ,    }   ,    |   ,    &   ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                        KC_LGUI,  MO(3), KC_SPC,    KC_ENT, _______, KC_LGUI
                                      //`--------------------------'  `--------------------------'

  [_RAISE] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------.                    ,-----------------------------------------------------.
         KC_TAB      , ES_EXLM ,  ES_AT , ES_HASH ,  ES_DLR, ES_PERC ,                     ES_QUOT , ES_DQUO ,  ES_LPRN, ES_RPRN, ES_SLSH , ES_ASTR ,
  //|--------+--------+------- -+--------+--------+-----------------|                    |--------+--------+--------+--------+--------+--------|
      TD(TD_CAPLOCK) , XXXXXXX, XXXXXXX, XXXXXXX, ES_IQUE , ES_QUES ,                      ES_DLR ,  ES_EQL, ES_LBRC, ES_RBRC, ES_BSLS,  ES_GRV,
  //|--------+--------+--------+--------+--------+-----------------|                     |--------+--------+--------+--------+--------+--------|
         KC_LCTL     , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LY_ADJUST,                      ES_LABK , ES_RABK , ES_LCBR , ES_RCBR , ES_PIPE, ES_AMPR,
  //|-------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             KC_LALT,  _______, KC_SPC,     KC_ENT, MO(_ADJUST), KC_LGUI
                                           //`--------------------------'  `--------------------------'
  ),
  
  // numpad
	[_NUMPAD] = LAYOUT(
	//,------------------------------------------------------------------.                    ,-----------------------------------------------------.
	      _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, 					   KC_PAST,   KC_P7,   KC_P8,   KC_P9, KC_ASTR, KC_BSPC,
	//|--------+--------+--------+--------+----------------------+--------|                    |--------+--------+--------+--------+--------+--------|
	      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 					   KC_PMNS,   KC_P4,   KC_P5,   KC_P6,  KC_EQL,  XXXXXXX,
	//|--------+--------+--------+--------+--------+----------------------|                    |--------+--------+--------+--------+--------+--------|
		  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 					   KC_PPLS,   KC_P1,   KC_P2,   KC_P3, KC_SLSH,   KC_DEL,
	//|--------+--------+--------+--------+--------+--------+---------------------|  |--------+--------+--------+--------+--------+--------+--------|
							               		    XXXXXXX,   XXXXXXX,   KC_TRNS,     KC_ENT,   KC_P0,  KC_PDOT
										             //`--------------------------'  `--------------------------'
	),


  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______,  KC_SPC,     KC_ENT, _______, KC_LGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [_PHPSTORM] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, LALT(ES_1) , XXXXXXX,   XXXXXXX     ,   XXXXXXX     ,  LCTL(LSFT(KC_PMNS)) ,                       LCTL(LSFT(KC_PPLS))   ,     XXXXXXX         , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-----------------------------------------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  XXXXXXX   , XXXXXXX,   XXXXXXX     ,   LCA(KC_L)    ,    LCTL(KC_PMNS)    ,                          LCTL(KC_PPLS)      , LCTL(LSFT(KC_PSLS)) , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-----------------------------------------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  XXXXXXX   , XXXXXXX,   XXXXXXX     ,  LALT(KC_F12)  ,    LCA(KC_PMNS)     ,                           LCA(KC_PPLS)      ,    LCTL(KC_PSLS)    , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+------------------------------------|  |--------+--------+--------+--------+--------+--------+--------|
                                                               KC_LALT, XXXXXXX,  KC_SPC,     _______, XXXXXXX, KC_LGUI
                                                            //`--------------------------'  `--------------------------'
  )
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for ;, twice for :
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_MENU] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_APP),
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

//#define L_BASE 0
//#define L_LOWER 2
//#define L_RAISE 4
//#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (biton32(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("NUMPAD"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOWER"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("RAISE"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJUST"), false);
            break;
        case _PHPSTORM:
            oled_write_ln_P(PSTR("PHPSTORM"), false);
            break;
            
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE


#ifdef RGB_MATRIX_ENABLE


void rgb_matrix_indicators_user(void) {
  #ifdef RGB_MATRIX_ENABLE
  switch (biton32(layer_state)) {
    case _RAISE:
      break;

    case _LOWER:    
      break;

    default:
        if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
            rgb_matrix_set_color(21, 0, 255, 0);
            rgb_matrix_set_color(22, 0, 255, 0);
            rgb_matrix_set_color(23, 0, 255, 0);
            rgb_matrix_set_color(24, 0, 255, 0);
            rgb_matrix_set_color(25, 0, 255, 0);
            rgb_matrix_set_color(26, 0, 255, 0);
            rgb_matrix_set_color(27, 0, 255, 0);
            rgb_matrix_set_color(28, 0, 255, 0);
            rgb_matrix_set_color(29, 0, 255, 0);
            rgb_matrix_set_color(30, 0, 255, 0);
        }
      break;
  }
  #endif
}

#endif