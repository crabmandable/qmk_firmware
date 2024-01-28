/* Copyright 2021 weteor
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers
{
    _ALPHA_QWERTY = 0,
    _SYMBOLS,
    _NUMBERS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_ALPHA_QWERTY] = LAYOUT_split_3x5_3(
KC_Q        , KC_W        , KC_E           , KC_R          , KC_T,
         KC_Y        , KC_U        , KC_I           , KC_O          , KC_P,

         LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,
         KC_H,     RCTL_T(KC_J), RSFT_T(KC_K)     , RALT_T(KC_L)    , RGUI_T(KC_SCLN),

         KC_Z        , KC_X,       KC_C,     KC_V          , KC_B,
         KC_N        , KC_M        , KC_COMM, KC_DOT, KC_SLSH,

         TG(2), LT(2, KC_ENT), OSL(1),
         KC_SPC,  LT(2, KC_BSPC), KC_CAPS

    ),
    [_SYMBOLS] = LAYOUT_split_3x5_3(
KC_CIRC     , KC_EXLM     , KC_HASH        , KC_ASTR       , KC_DLR,
         KC_AT     , KC_LBRC     , KC_RBRC        , KC_LCBR       , KC_RCBR,

         KC_AMPR     , KC_BSLS     , KC_LPRN          , KC_RPRN       , KC_SLSH,
         KC_LEFT     , KC_DOWN     , KC_UP        , KC_RGHT       , KC_QUOT,

         KC_NO     , KC_PERC     , KC_GRV        , KC_PIPE       , KC_TILD,
         KC_EQL     , KC_UNDS     , KC_MINS        , KC_PLUS       , KC_DQUO,

         KC_TRNS,    KC_TRNS     , KC_ESC,
         KC_TAB     , KC_DEL, KC_TRNS
    ),
    [_NUMBERS] = LAYOUT_split_3x5_3(
KC_NO     , KC_NO     , KC_PGUP        , KC_PGDN       , KC_NO,
         KC_NO     , KC_7     , KC_8        , KC_9       , KC_NO,

         KC_LGUI     , KC_LALT       , LSFT_T(KC_CAPS)        , KC_LCTL       , KC_HOME,
         KC_NO     , RCTL_T(KC_4)     , RSFT_T(KC_5)          , RALT_T(KC_6) , KC_RGUI,

         KC_NO     , KC_NO     , KC_NO        , KC_NO        , KC_END,
         KC_0     , KC_1     , KC_2        , KC_3       , KC_NO,

         KC_TRNS     ,KC_TRNS     , KC_TRNS,
         KC_TRNS     , KC_TRNS, KC_TRNS

    ),
};
