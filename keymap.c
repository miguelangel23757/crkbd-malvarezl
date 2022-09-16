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
  _KEY_SYSTEM,
  _CARACTERS,
  _NUMPAD,
  _COMANDS,
  _PHPSTORM,
  _FUNCTIONS,
  _ADJUST
  
};

#define TAB_LY_NUMPAD LT(_NUMPAD, KC_TAB)
#define WIND_LY_SYSTEM LT(_KEY_SYSTEM, KC_LGUI)
#define ENT_LY_PHPSTORM LT(_PHPSTORM, KC_ENT)
#define APP_CARACTERS LT(_CARACTERS, KC_APP)
#define TAB_COMMAND LT(_COMANDS,KC_TAB)

#define LY_COMMANDS MO(_COMANDS)
#define LY_CARACTERS MO(_CARACTERS)
#define TAB_LOWER LT(_LOWER, KC_ESC)
#define LY_PHPSTORM LT(_PHPSTORM, KC_ENT)
#define LY_ADJUST LT(_ADJUST, KC_ENT)
#define LY_RAISE LT(_RAISE, KC_TAB)



enum {
    TD_CAPLOCK,
    TD_MENU
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for ;, twice for :
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_MENU] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_APP),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // QWERTY
  //,-----------------------------------------------------------.                    ,-----------------------------------------------------.
  //     KC_TAB    ,    Q   ,    W   ,   E    ,   R    ,   T    ,                         Y   ,    U   ,    I   ,   O    ,   P    ,  DELET ,
  //|--------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //  LSFT / MAYUS ,    A   ,    S   ,   D    ,   F    ,   G    ,                         H   ,   J    ,    K   ,   L    ,   Ñ    ,  ACUT  ,
  //|--------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //  _KEY_SYSTEM  ,    Z   ,    X   ,    C   ,    V   ,    B   ,                         N   ,   M    ,    ,   ,   .    ,   -    ,  SUPR  ,
  //|--------------+--------+--------+--------+--------+--------+-----------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                          CTL ,  APP_CARACTERS , SPC  ,      ENT  ,  _COMANDS ,   AWINDOWS
  //                                             `--------------------------'  `-------------------------------'

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------.                        ,-------------------------------------------------------.
       TAB_LY_NUMPAD    ,   KC_Q  ,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     KC_DEL  ,
  //|-------------------+---------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+----------|
      TD(TD_CAPLOCK)    ,   KC_A  ,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, ES_NTIL,    ES_ACUT ,
  //|-------------------+---------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+----------|
      WIND_LY_SYSTEM    ,   KC_Z  ,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, ES_COMM,  ES_DOT, ES_MINS,    KC_BSPC ,
  //|-------------------+---------+--------+--------+--------+--------+----------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(_ADJUST), APP_CARACTERS , KC_SPC,       ENT_LY_PHPSTORM  , TAB_COMMAND  , MO(_FUNCTIONS)
                                                  //`----------------------------'  `------------------------------'

  ),

    //  _KEY_SYSTEM 
  //,--------------------------------------------------------------------------.                    ,--------------------------------------------------------------.
  //     KC_TRNS   ,  KC_TRNS  ,  KC_TRNS  , KC_TRNS ,  KC_TRNS ,   KC_TRNS    ,                      KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------|                    |----------+---------+---------+---------+---------+-----------|
  //     KC_TRNS   ,  KC_TRNS  ,  KC_TRNS  , KC_TRNS ,  KC_TRNS ,   KC_TRNS    ,                      KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------|                    |----------+---------+---------+---------+---------+-----------|
  //     KC_TRNS   ,  KC_TRNS  ,  KC_TRNS  , KC_TRNS ,  KC_TRNS ,   KC_TRNS    ,                      KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------+--------|  |-------------------+---------+---------+---------+---------+-----------|
  //                                                             CTL ,   ALT ,   CTL  ,      ENT  ,  0  ,   AWINDOWS
  //                                                        `--------------------------'  `-------------------------------'

  [_KEY_SYSTEM] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------.                    ,----------------------------------------------------------------.
           KC_TRNS    , LCTL(KC_Q) , LCTL(KC_W) , LWIN(KC_E) ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS    , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+------------+------------+------------+------------|                    |-----------+----------+----------+------------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS   ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , LWIN(KC_L) , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+------------+------------+------------+------------|                    |-----------+----------+----------+------------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS   , LCTL(KC_C) , LCTL(KC_v) ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS   , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+------------+------------+------------+------------|                    |-----------+----------+----------+------------+---------+----------|
                                                             KC_TRNS  ,   KC_TRNS  ,  KC_TRNS  ,    KC_TRNS ,  KC_TRNS , KC_TRNS
                                                           //`---------------------------------'  `------------------------------'

  ),


  // CARACTERS  
  //,--------------------------------------------------------------------.                    ,--------------------------------------------------------.
  //        ESC    ,  KC_TRNS  ,    ~   ,   `    ,   #    ,   KC_TRNS    ,                         @   ,    '   ,    "   ,   *    ,   |    ,  KC_TRNS  ,
  //|--------------+-----------+--------+--------+--------+--------------|                    |--------+--------+--------+--------+--------+-----------|
  //     KC_TRNS   ,     ¡     ,    <   ,   %    ,   &    ,      /       ,                         +   ,   $    ,    =   ,   >    ,   !    ,  KC_TRNS  ,
  //|--------------+-----------+--------+--------+--------+--------------|                    |--------+--------+--------+--------+--------+-----------|
  //     KC_TRNS   ,     ?     ,    }   ,   )    ,   ]    ,      \       ,                         -   ,   [    ,    (   ,   {    ,   ¿    ,  KC_TRNS   ,
  //|--------------+-----------+--------+--------+--------+--------------+--------|  |-----------------+--------+--------+--------+--------+------------|
  //                                                  CTL ,  _CARACTERS ,   SPC  ,      ENT  ,  KC_TRNS  ,   AWINDOWS
  //                                                   `--------------------------'  `-------------------------------'

  [_CARACTERS] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------.                    ,----------------------------------------------------------------.
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
                                                             KC_TRNS  ,   KC_TRNS  ,  KC_TRNS  ,    KC_TRNS ,  KC_TRNS , KC_TRNS
                                                           //`---------------------------------'  `------------------------------'
  ),

  //  _NUMPAD 
  //,--------------------------------------------------------------------------.                    ,--------------------------------------------------------.
  //     KC_TRNS   ,  KC_TRNS  ,  KC_TRNS  , KC_TRNS ,  KC_TRNS ,   KC_TRNS    ,                         *   ,    7   ,    8   ,   9    ,   /    ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------|                    |--------+--------+--------+--------+--------+-----------|
  //     KC_TRNS   ,  KC_TRNS  ,  KC_TRNS  , KC_TRNS ,  KC_TRNS ,   KC_TRNS    ,                         +   ,   4    ,    5   ,   6    ,   %    ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------|                    |--------+--------+--------+--------+--------+-----------|
  //     KC_TRNS   ,  KC_TRNS  ,  KC_TRNS  , KC_TRNS ,  KC_TRNS ,   KC_TRNS    ,                         -   ,   1    ,    2   ,   3    ,   .    ,  KC_TRNS   ,
  //|--------------+-----------+-----------+---------+----------+--------------+--------|  |-----------------+--------+--------+--------+--------+------------|
  //                                                        CTL ,  _CARACTERS ,   SPC  ,      ENT  ,  0  ,   AWINDOWS
  //                                                        `--------------------------'  `-------------------------------'

  [_NUMPAD] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------.                    ,----------------------------------------------------------------.
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
                                                             KC_TRNS  ,   KC_TRNS  ,  KC_TRNS  ,    KC_TRNS ,  KC_TRNS , KC_TRNS
                                                           //`---------------------------------'  `------------------------------'

  ),


  //  _COMANDS 
  //,--------------------------------------------------------------------------.                    ,--------------------------------------------------------------.
  //     KC_TRNS   ,  KC_TRNS  ,  KC_TRNS  , KC_TRNS ,  KC_TRNS ,   KC_TRNS    ,                      KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------|                    |----------+---------+---------+---------+---------+-----------|
  //     KC_TRNS   ,  KC_TRNS  ,    SHIFT  , KC_TRNS ,    TAB   ,   KC_TRNS    ,                      KC_TRNS  ,   HOME  ,    UP   ,   END   , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------|                    |----------+---------+---------+---------+---------+-----------|
  //     KC_TRNS   ,  KC_TRNS  ,  KC_TRNS  , KC_TRNS ,  KC_TRNS ,   KC_TRNS    ,                      KC_TRNS  ,   LEFT  ,   DOWN  ,  RIGHT  , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------+--------|  |-------------------+---------+---------+---------+---------+-----------|
  //                                                             CTL ,   ALT ,   CTL  ,      ENT  ,  0  ,   AWINDOWS
  //                                                        `--------------------------'  `-------------------------------'

  [_COMANDS] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------.                    ,----------------------------------------------------------------.
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
                                                             KC_TRNS  ,   KC_TRNS  ,  KC_TRNS  ,    KC_TRNS ,  KC_TRNS , KC_TRNS
                                                           //`---------------------------------'  `------------------------------'

  ),

  
  //  _PHPSTORM 
  //,--------------------------------------------------------------------------.                    ,--------------------------------------------------------------.
  //     KC_TRNS   ,  KC_TRNS  ,  KC_TRNS  , KC_TRNS ,  KC_TRNS ,   KC_TRNS    ,                      KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------|                    |----------+---------+---------+---------+---------+-----------|
  //     KC_TRNS   ,  KC_TRNS  ,  KC_TRNS  , KC_TRNS ,  KC_TRNS ,   KC_TRNS    ,                      KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------|                    |----------+---------+---------+---------+---------+-----------|
  //     KC_TRNS   ,  KC_TRNS  ,  KC_TRNS  , KC_TRNS ,  KC_TRNS ,   KC_TRNS    ,                      KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------+--------|  |-------------------+---------+---------+---------+---------+-----------|
  //                                                             CTL ,   ALT ,   CTL  ,      ENT  ,  0  ,   AWINDOWS
  //                                                        `--------------------------'  `-------------------------------'

  [_PHPSTORM] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------.                    ,----------------------------------------------------------------.
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
                                                             KC_TRNS  ,   KC_TRNS  ,  KC_TRNS  ,    KC_TRNS ,  KC_TRNS , KC_TRNS
                                                           //`---------------------------------'  `------------------------------'
  ),

  //  _FUNCTIONS 
  //,--------------------------------------------------------------------------.                    ,--------------------------------------------------------------.
  //     KC_TRNS   ,     F1    ,     F2    ,    F3   ,     F4   ,      F5      ,                      KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------|                    |----------+---------+---------+---------+---------+-----------|
  //     KC_TRNS   ,     F6    ,     F7    ,    F8   ,     F9   ,      F10     ,                      KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------|                    |----------+---------+---------+---------+---------+-----------|
  //     KC_TRNS   ,     F11   ,    F12    , KC_TRNS ,  KC_TRNS ,   KC_TRNS    ,                      KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------+--------|  |-------------------+---------+---------+---------+---------+-----------|
  //                                                             CTL ,   ALT ,   CTL  ,      ENT  ,  0  ,   AWINDOWS
  //                                                        `--------------------------'  `-------------------------------'

  [_FUNCTIONS] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------.                    ,----------------------------------------------------------------.
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
                                                             KC_TRNS  ,   KC_TRNS  ,  KC_TRNS  ,    KC_TRNS ,  KC_TRNS , KC_TRNS
                                                           //`---------------------------------'  `------------------------------'
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
  )
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