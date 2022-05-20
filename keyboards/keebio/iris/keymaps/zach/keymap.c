#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                                KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(3, KC_QUOT),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TG(2),             KC_MUTE,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LALT_T(KC_ENT),OSL(1),              KC_SPC,  KC_ESC,   KC_RCTL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [1] = LAYOUT(
            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                     /*|||*/       KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
            KC_TRNS, KC_CIRC, KC_TRNS, KC_HASH, KC_ASTR, KC_DLR,          /*|||*/       KC_HOME, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_DEL,
            KC_TRNS, KC_AMPR, KC_BSLS, KC_LPRN, KC_RPRN, KC_SLSH,         /*|||*/       KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV, KC_PIPE, KC_TILD, KC_TRNS, /*|||*/ KC_TRNS, KC_END, KC_PGDN, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS, KC_TRNS, /*|||*/ KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [2] = LAYOUT(
            RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K,/*||*/       RGB_M_X, RGB_M_G, RGB_M_T, KC_NO, KC_NO, KC_NO,
            KC_NO, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,    /*||*/       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,   /*||*/       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,       /*||*/ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                    KC_TRNS, KC_TRNS, KC_NO,       /*||*/ KC_TRNS, KC_TRNS, KC_TRNS
    ),
  [3] = LAYOUT(
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              /*||*/       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,        /*||*/       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,        /*||*/       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_BTN3, KC_BTN4, KC_BTN5, KC_NO, KC_NO, /*||*/ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                              KC_NO, KC_NO, KC_NO, /*||*/ KC_NO, KC_NO, KC_NO
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
