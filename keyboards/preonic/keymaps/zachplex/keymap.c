#include QMK_KEYBOARD_H

#include "muse.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
float tone_startup[][2] = SONG(STARTUP_SOUND);
#endif

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_startup);
    #endif
}

enum custom_keycodes {
    Z_GUITAB = SAFE_RANGE,
    Z_GUI1,
    Z_GUI2,
    Z_GUI3,
    Z_GUI4,
    Z_GUI5,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed && keycode >= SAFE_RANGE) {
        register_code(KC_LGUI);
        switch (keycode) {
            case Z_GUITAB: {
                tap_code(KC_TAB);
                break;
            };
            case Z_GUI5: {
                tap_code(KC_5);
                break;
            };
            case Z_GUI4: {
                tap_code(KC_4);
                break;
            };
            case Z_GUI3: {
                tap_code(KC_3);
                break;
            };
            case Z_GUI2: {
                tap_code(KC_2);
                break;
            };
            case Z_GUI1: {
                tap_code(KC_1);
                break;
            };
            default: break;
        }
        unregister_code(KC_LGUI);
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x12(
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_MOD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO, KC_NO, KC_Y, KC_U, KC_I, KC_O, KC_P,
            LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G, KC_NO, KC_NO, KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L),  RGUI_T(KC_SCLN),
            KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
            KC_NO, KC_NO, KC_NO, KC_NO, LT(2, KC_ENT), OSL(1), KC_SPC, LT(2, KC_BSPC), KC_NO, KC_NO, KC_NO, KC_NO),

    [1] = LAYOUT_ortho_5x12(
            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
            KC_CIRC, KC_EXLM, KC_HASH, KC_ASTR, KC_DLR, KC_NO, KC_NO, KC_AT, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,
            KC_AMPR, KC_BSLS, KC_LPRN, KC_RPRN, KC_SLSH, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_QUOT,
            KC_ESC, KC_PERC, KC_GRV, KC_PIPE, KC_TILD, KC_NO, KC_NO, KC_EQL, KC_UNDS, KC_MINS, KC_PLUS, KC_DQUO,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, Z_GUITAB, KC_ESC, KC_TAB, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [2] = LAYOUT_ortho_5x12(
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_PGDN, KC_PGUP, KC_UNDS, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO,
            KC_LGUI, KC_LALT, LSFT_T(KC_CAPS_LOCK), KC_LCTL, KC_HOME, KC_NO, KC_NO, KC_NO, RCTL_T(KC_4), RSFT_T(KC_5), RALT_T(KC_6), KC_TRNS,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_END, KC_NO, KC_NO, KC_0, KC_1, KC_2, KC_3, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSL(3), KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS),

    [3] = LAYOUT_ortho_5x12(
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            TO(4), KC_NO, KC_NO, KC_NO, KC_UNDS, KC_NO, KC_NO, KC_F11, KC_F7, KC_F8, KC_F9, KC_NO,
            KC_NO, KC_NO, KC_BTN4, KC_BTN5, KC_PLUS, KC_NO, KC_NO, KC_F12, KC_F4, KC_F5, KC_F6, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS),

    /* [4] = LAYOUT_ortho_5x12( */
    /*         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, */
    /*         RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, */
    /*         KC_NO, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, */
    /*         RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, KC_NO, KC_NO, KC_NO, */
    /*         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_NO, KC_NO, KC_NO), */
    [4] = LAYOUT_ortho_5x12(
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_NO, KC_NO, KC_NO),
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
    if (4 == to && !layer_lighting) {
        cache_rgb_config();
        layer_lighting = true;
        rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT);
    }
    if (4 == from) {
        layer_lighting = false;
        restore_rgb_config();
    }
    if (2 == to && !layer_lighting) {
        layer_lighting = true;
        cache_rgb_config();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        // set hue yellow
        rgblight_sethsv_noeeprom(43, current_config.sat, current_config.val);
    }
    if (2 == from) {
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
