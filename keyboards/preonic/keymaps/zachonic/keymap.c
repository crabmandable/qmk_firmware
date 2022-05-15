#include QMK_KEYBOARD_H

#define RGBLIGHT_LAYERS

enum custom_keycodes {
    Z_ARROW = SAFE_RANGE,
    Z_DOLLAR_CURLY,
};

bool lshift = false;
bool rshift = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_LSFT:
        lshift = record->event.pressed;
        break;
    case KC_RSFT:
        rshift = record->event.pressed;
        break;
    case Z_ARROW:
        if (record->event.pressed) {
            SEND_STRING("=>");
        }
        break;
    case Z_DOLLAR_CURLY:
        if (record->event.pressed) {
            SEND_STRING("${}"SS_TAP(X_LEFT));
        }
        break;
    default:
        break;
    }

    if (lshift && rshift) {
        tap_code(KC_CAPS);
    }
    return true;
};

rgblight_config_t current_config;

void cache_rgb_config(void) {
    current_config.enable = rgblight_is_enabled();
    current_config.mode = rgblight_get_mode();
    current_config.hue = rgblight_get_hue();
    current_config.sat = rgblight_get_sat();
    current_config.val = rgblight_get_val();
    current_config.speed = rgblight_get_speed();
}

void restore_rgb_config(void) {
    if (current_config.enable) rgblight_enable_noeeprom();
    else rgblight_disable_noeeprom();
    rgblight_sethsv_noeeprom(current_config.hue, current_config.sat, current_config.val);
    rgblight_set_speed_noeeprom(current_config.speed);
    rgblight_mode_noeeprom(current_config.mode);
}
layer_state_t current_layer = 0; // todo init with the actual eprom default
void keyboard_post_init_user(void) {
    cache_rgb_config();
}

bool layer_lighting = false;
void layer_was_switched(layer_state_t from, layer_state_t to) {
    if (2 == to && !layer_lighting) {
        cache_rgb_config();
        layer_lighting = true;
        rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT);
    }
    if (2 == from) {
        layer_lighting = false;
        restore_rgb_config();
    }
    if (4 == to && !layer_lighting) {
        layer_lighting = true;
        cache_rgb_config();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        // set hue yellow
        rgblight_sethsv_noeeprom(43, current_config.sat, current_config.val);
    }
    if (4 == from) {
        layer_lighting = false;
        restore_rgb_config();
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t top_layer = get_highest_layer(state);
    if (top_layer != current_layer) {
        layer_was_switched(current_layer, top_layer);
        current_layer = top_layer;
    }

    return state;
}

// this is supposed to automatically enable numlock on start
// doesnt work though :(
void matrix_init_user(void) {
    if (!(host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) {
        register_code(KC_NUMLOCK);
        unregister_code(KC_NUMLOCK);
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x12(
            KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,
            KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
            KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(4,KC_QUOT),
            KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
            KC_NO, KC_NO, KC_NO, KC_LGUI, LALT_T(KC_ENT), OSL(1), KC_SPC, KC_ESC, KC_NO, TG(3), TG(2), KC_NO),

    [1] = LAYOUT_ortho_5x12(
            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
            KC_TRNS, KC_CIRC, KC_TRNS, KC_HASH, KC_ASTR, KC_DLR, KC_HOME, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_DEL,
            KC_TRNS, KC_AMPR, KC_BSLS, KC_LPRN, KC_RPRN, KC_SLSH, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV, KC_PIPE, KC_TILD, KC_END, KC_PGDN, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [2] = LAYOUT_ortho_5x12(
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NLCK, KC_NO, KC_NO, KC_MINS, KC_EQL,
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_NO, KC_BSPC,
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P0, KC_P1, KC_P2, KC_P3, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS),

    [3] = LAYOUT_ortho_5x12(
            RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, KC_NO, KC_NO, KC_NO,
            KC_NO, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO),

    [4] = LAYOUT_ortho_5x12(
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_BTN3, KC_BTN4, KC_BTN5, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};


