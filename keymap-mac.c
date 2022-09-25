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
  _DIRECTIONS,
  _PHPSTORM,
  _FUNCTIONS,
  _ADJUST
  
};

#define TAB_LY_NUMPAD LT(_NUMPAD, KC_TAB)
#define WIND_LY_SYSTEM LT(_KEY_SYSTEM, KC_LGUI)
#define ENT_LY_PHPSTORM LT(_PHPSTORM, KC_ENT)
#define APP_CARACTERS LT(_CARACTERS, KC_APP)
#define TAB_COMMAND LT(_DIRECTIONS,KC_TAB)

#define WIND_CTL MT(MOD_LCTL,KC_LGUI)
#define DEL_ALT MT(MOD_LALT,KC_DEL)

#define LA_PIPE KC_GRV
#define LA_EXLM S(KC_1)
#define LA_QUES S(KC_MINS)
#define LA_ASTR S(KC_RBRC)
#define LA_RABK S(KC_NUBS)
#define LA_LCBR KC_QUOT
#define LA_DQUO S(KC_2)
#define LA_EQL  S(KC_0)
#define LA_LPRN S(KC_8)
#define LA_LBRC S(KC_QUOT)
#define LA_DLR  S(KC_4)
#define LA_QUOT KC_MINS
#define LA_AT   A(KC_Q)
#define LA_PPLS KC_RBRC
#define LA_PMNS KC_SLSH
#define LA_SLSH S(KC_7) 
#define LA_BSLS A(KC_MINS)
#define LA_HASH S(KC_3)
#define LA_AMPR S(KC_6)
#define LA_RBRC S(KC_NUHS)
#define LA_RPRN S(KC_9)
#define LA_PERC S(KC_5)
#define LA_ACENT KC_LBRC
#define LA_TILD A(KC_RBRC)
#define LA_LABK KC_NUBS
#define LA_RCBR KC_NUHS
#define LA_IQUE KC_EQL
#define LA_IEXL S(KC_EQL)


enum {
    TD_CAPLOCK
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for ;, twice for :
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
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
       TAB_LY_NUMPAD    ,   KC_Q  ,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     KC_BSPC  ,
  //|-------------------+---------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+----------|
      TD(TD_CAPLOCK)    ,   KC_A  ,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, ES_NTIL,    KC_LBRC ,
  //|-------------------+---------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+----------|
          KC_LCMD      ,   KC_Z  ,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, ES_COMM,  ES_DOT, ES_MINS,    DEL_ALT ,
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
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS   ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , LCTL(KC_L) , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+------------+------------+------------+------------|                    |-----------+----------+----------+------------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS   , LCTL(KC_C) , LCTL(KC_V) ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS   , KC_TRNS ,  KC_TRNS ,
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
           KC_ESC     ,   KC_TRNS  ,  LA_TILD  ,   LA_ACENT ,   LA_HASH  ,   KC_TRNS ,                         LA_AT   ,  LA_QUOT ,  LA_DQUO , LA_ASTR , LA_PIPE ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   LA_IEXL  ,  LA_LABK  ,   LA_PERC  ,   LA_AMPR  ,   LA_SLSH ,                        LA_PPLS  ,  LA_DLR  ,  LA_EQL  , LA_RABK , LA_EXLM ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   LA_IQUE  ,  LA_RCBR  ,   LA_RPRN  ,   LA_RBRC  ,   LA_BSLS ,                        LA_PMNS  ,  LA_LBRC ,  LA_LPRN , LA_LCBR , LA_QUES ,  KC_TRNS ,
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
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_ASTR  ,   KC_P7  ,   KC_P8  ,  KC_P9  , KC_SLSH ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_PMNS  ,   KC_P4  ,   KC_P5  ,  KC_P6  , ES_PERC ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_PPLS  ,   KC_P1  ,   KC_P2  ,  KC_P3  , KC_PDOT ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
                                                             KC_TRNS  ,   KC_TRNS  ,  KC_TRNS  ,    KC_TRNS ,  KC_P0   , KC_TRNS
                                                           //`---------------------------------'  `------------------------------'

  ),


  //  _DIRECTIONS 
  //,--------------------------------------------------------------------------.                    ,--------------------------------------------------------------.
  //     KC_TRNS   ,  KC_TRNS  ,  KC_TRNS  , KC_TRNS ,  KC_TRNS ,   KC_TRNS    ,                      KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------|                    |----------+---------+---------+---------+---------+-----------|
  //     KC_TRNS   ,  KC_TRNS  ,    SHIFT  , KC_TRNS ,    TAB   ,   KC_TRNS    ,                      KC_TRNS  ,   HOME  ,    UP   ,   END   , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------|                    |----------+---------+---------+---------+---------+-----------|
  //     KC_TRNS   ,  KC_TRNS  ,  KC_TRNS  , KC_TRNS ,  KC_TRNS ,   KC_TRNS    ,                      KC_TRNS  ,   LEFT  ,   DOWN  ,  RIGHT  , KC_TRNS ,  KC_TRNS  ,
  //|--------------+-----------+-----------+---------+----------+--------------+--------|  |-------------------+---------+---------+---------+---------+-----------|
  //                                                             CTL ,   ALT ,   CTL  ,      ENT  ,  0  ,   AWINDOWS
  //                                                        `--------------------------'  `-------------------------------'

  [_DIRECTIONS] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------.                    ,----------------------------------------------------------------.
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_LSFT  ,   KC_TRNS  ,   KC_TAB   ,   KC_TRNS ,                        KC_TRNS  ,  KC_HOME ,   KC_UP  ,  KC_END , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,   KC_TRNS  ,  KC_TRNS  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_LEFT ,  KC_DOWN , KC_RIGHT , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
                                                             KC_TRNS  ,   KC_LALT  ,  KC_LCTL  ,    KC_TRNS ,  KC_TRNS , KC_TRNS
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
  //,---------------------------------------------------------------------------------------------.                    ,-----------------------------------------------------------------------------.
           KC_TRNS    ,   LCA(KC_1)  ,  LCTL(KC_P7)  ,   LCTL(KC_P8)  ,   LCTL(KC_P9)  ,   LCA(KC_4) ,                         LCA(KC_7) ,  A(KC_P7) ,  A(KC_P8) , A(KC_P9) , RCTL(KC_P3) ,  KC_TRNS ,
  //|-----------------+--------------+---------------+----------------+----------------+-------------|                    |--------------+-----------+-----------+----------+-------------+----------|
           KC_TRNS    ,   LCA(KC_2)  ,  LCTL(KC_P4)  ,   LCTL(KC_P5)  ,   LCTL(KC_P6)  ,   LCA(KC_5) ,                        LCA(KC_8)  ,  A(KC_P4) ,  A(KC_P5) , A(KC_P6) , RCTL(KC_P2) ,  KC_TRNS ,
  //|-----------------+--------------+---------------+----------------+----------------+-------------|                    |--------------+-----------+-----------+----------+-------------+----------|
           KC_TRNS    ,   LCA(KC_3)  ,  LCTL(KC_P1)  ,   LCTL(KC_P2)  ,   LCTL(KC_P3)  ,   LCA(KC_6) ,                        LCA(KC_9)  ,  A(KC_P1) ,  A(KC_P2) , A(KC_P3) , RCTL(KC_P1) ,  KC_TRNS ,
  //|-----------------+--------------+---------------+----------------+----------------+----------------------|  |-------+---------------+------------+-----------+----------+------------+----------|
                                                                         KC_TRNS  ,   KC_TRNS  ,  KC_TRNS  ,      KC_TRNS ,  KC_TRNS , KC_TRNS
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
           KC_TRNS    ,    KC_F1   ,   KC_F2   ,    KC_F3   ,    KC_F4   ,    KC_F5   ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,    KC_F6   ,   KC_F7   ,    KC_F8   ,    KC_F9   ,    KC_F10  ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
  //|-----------------+------------+-----------+------------+------------+------------|                    |-----------+----------+----------+---------+---------+----------|
           KC_TRNS    ,    KC_F11  ,   KC_F12  ,   KC_TRNS  ,   KC_TRNS  ,   KC_TRNS ,                        KC_TRNS  ,  KC_TRNS ,  KC_TRNS , KC_TRNS , KC_TRNS ,  KC_TRNS ,
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

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (biton32(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case _KEY_SYSTEM:
            oled_write_ln_P(PSTR("KEY SYSTEM"), false);
        case _CARACTERS:
            oled_write_ln_P(PSTR("CARACTERES"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("NUMPAT"), false);
            break;
        case _DIRECTIONS:
            oled_write_ln_P(PSTR("DIRECCION"), false);
            break;
        case _PHPSTORM:
            oled_write_ln_P(PSTR("PHPSTORM"), false);
            break;
        case _FUNCTIONS:
            oled_write_ln_P(PSTR("FUNTIONS"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("AJUSTES"), false);
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

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }

    return false;
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
    //case _RAISE:
    //  break;

    //case _LOWER:    
    //  break;

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