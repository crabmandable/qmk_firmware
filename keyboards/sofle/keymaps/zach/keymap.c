#include QMK_KEYBOARD_H
#include "oled.c"
#include "encoder.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
            KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,
            KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO,
            KC_NO, LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G, KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L),  RGUI_T(KC_SCLN), KC_NO,
            KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
                           TG(2), KC_LALT, KC_LGUI, LT(2, KC_ENT), OSL(1),
                           KC_SPC, LT(2, KC_BSPC), KC_RGUI, KC_RCTL, KC_CAPS
    ),

    [1] = LAYOUT(
            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
            KC_NO, KC_CIRC, KC_EXLM, KC_HASH, KC_ASTR, KC_DLR, KC_AT, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_NO,
            KC_NO, KC_AMPR, KC_BSLS, KC_LPRN, KC_RPRN, KC_SLSH, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_QUOT, KC_NO,
            KC_NO, KC_NO, KC_PERC, KC_GRV, KC_PIPE, KC_TILD, KC_TRNS, KC_TRNS, KC_EQL, KC_UNDS, KC_MINS, KC_PLUS, KC_DQUO, KC_NO,
                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC,
                              KC_TAB, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT(
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_NO, KC_NO, KC_NO, KC_PGDN, KC_PGUP, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO,
            KC_NO, KC_LGUI, KC_LALT, LSFT_T(KC_CAPS_LOCK), KC_LCTL, KC_HOME, KC_NO, RCTL_T(KC_4), RSFT_T(KC_5), RALT_T(KC_6), KC_TRNS, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_END, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_TRNS, KC_NO,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO
    ),
};
