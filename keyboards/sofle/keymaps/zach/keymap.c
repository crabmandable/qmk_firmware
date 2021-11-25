#include QMK_KEYBOARD_H
#include "oled.c"
#include "encoder.c"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY_LAYER,
    _FN_LAYER,
    _EXTRA_LAYER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LGUI, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(3,KC_QUOT), KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCTL, KC_LALT, TG(2), LALT_T(KC_ENT), OSL(1), KC_SPC, KC_ESC, RGB_TOG, RGB_MOD, KC_CAPS),
	[1] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_CIRC, KC_NO, KC_HASH, KC_ASTR, KC_DLR, KC_HOME, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_AMPR, KC_BSLS, KC_LPRN, KC_RPRN, KC_SLSH, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_GRV, KC_PIPE, KC_TILD, KC_NO, KC_NO, KC_END, KC_PGDN, KC_PGUP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[2] = LAYOUT(RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, KC_NO, KC_NO, KC_NO, KC_NO, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};


/*const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {*/
/*/**/
/* * QWERTY*/
/* * ,-----------------------------------------.                    ,-----------------------------------------.*/
/* * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |*/
/* * |------+------+------+------+------+------|                    |------+------+------+------+------+------|*/
/* * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |*/
/* * |------+------+------+------+------+------|                    |------+------+------+------+------+------|*/
/* * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |*/
/* * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|*/
/* * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|*/
/* * `-----------------------------------------/       /     \      \-----------------------------------------'*/
/* *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |*/
/* *            |      |      |      |      |/       /         \      \ |      |      |      |      |*/
/* *            `----------------------------------'           '------''---------------------------'*/

/*[_QWERTY_LAYER] = LAYOUT( \*/
/*  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV, \*/
/*  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, \*/
/*  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \*/
/*  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \*/
/*                 KC_LGUI,KC_LALT,KC_LCTRL, KC_LOWER, KC_ENT,      KC_SPC,  KC_RAISE, KC_RCTRL, KC_RALT, KC_RGUI \*/
/*),*/
/*/**/
/* * COLEMAK*/
/* * ,-----------------------------------------.                    ,-----------------------------------------.*/
/* * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |*/
/* * |------+------+------+------+------+------|                    |------+------+------+------+------+------|*/
/* * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |*/
/* * |------+------+------+------+------+------|                    |------+------+------+------+------+------|*/
/* * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |*/
/* * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|*/
/* * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|*/
/* * `-----------------------------------------/       /     \      \-----------------------------------------'*/
/* *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |*/
/* *            |      |      |      |      |/       /         \      \ |      |      |      |      |*/
/* *            `----------------------------------'           '------''---------------------------'*/

/*[_FN_LAYER] = LAYOUT( \*/
/*  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV, \*/
/*  KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC, \*/
/*  KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT, \*/
/*  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,      XXXXXXX,KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \*/
/*                 KC_LGUI,KC_LALT,KC_LCTRL,KC_LOWER, KC_ENT,      KC_SPC,  KC_RAISE, KC_RCTRL, KC_RALT, KC_RGUI \*/
/*),*/
/*/* LOWER*/
/* * ,-----------------------------------------.                    ,-----------------------------------------.*/
/* * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |*/
/* * |------+------+------+------+------+------|                    |------+------+------+------+------+------|*/
/* * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |*/
/* * |------+------+------+------+------+------|                    |------+------+------+------+------+------|*/
/* * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |*/
/* * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|*/
/* * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|*/
/* * `-----------------------------------------/       /     \      \-----------------------------------------'*/
/* *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |*/
/* *            |      |      |      |      |/       /         \      \ |      |      |      |      |*/
/* *            `----------------------------------'           '------''---------------------------'*/

/*[_EXTRA_LAYER] = LAYOUT( \*/
/*  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,\*/
/*  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12, \*/
/*  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \*/
/*  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______, \*/
/*                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______\*/
/*),*/
/*/* RAISE*/
/* * ,----------------------------------------.                    ,-----------------------------------------.*/
/* * |      |      |      |      |      |      |                    |      |      |      |      |      |      |*/
/* * |------+------+------+------+------+------|                    |------+------+------+------+------+------|*/
/* * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |*/
/* * |------+------+------+------+------+------|                    |------+------+------+------+------+------|*/
/* * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |*/
/* * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|*/
/* * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|*/
/* * `-----------------------------------------/       /     \      \-----------------------------------------'*/
/* *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |*/
/* *            |      |      |      |      |/       /         \      \ |      |      |      |      |*/
/* *            `----------------------------------'           '------''---------------------------'*/

/*[_RAISE] = LAYOUT( \*/
/*  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______, \*/
/*  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,KC_DLINE, KC_BSPC, \*/
/*  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC, \*/
/*  _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______, \*/
/*                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ \*/
/*),*/
/*/* ADJUST*/
/* * ,-----------------------------------------.                    ,-----------------------------------------.*/
/* * |      |      |      |      |      |      |                    |      |      |      |      |      |      |*/
/* * |------+------+------+------+------+------|                    |------+------+------+------+------+------|*/
/* * | RESET|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |*/
/* * |------+------+------+------+------+------|                    |------+------+------+------+------+------|*/
/* * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |*/
/* * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|*/
/* * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |*/
/* * `-----------------------------------------/       /     \      \-----------------------------------------'*/
/* *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |*/
/* *            |      |      |      |      |/       /         \      \ |      |      |      |      |*/
/* *            `----------------------------------'           '------''---------------------------'*/

/*  [_ADJUST] = LAYOUT( \*/
/*  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \*/
/*  RESET  , XXXXXXX,KC_QWERTY,KC_COLEMAK,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \*/
/*  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \*/
/*  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \*/
/*                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \*/
/*  )*/
/*};*/

