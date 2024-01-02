#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#define EE_HANDS

#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE

#define TAPPING_TERM 200
#define OLED_UPDATE_INTERVAL 10

//Add RGB underglow
#define RGB_DI_PIN D3
#define RGBLED_NUM 74
#define RGBLED_SPLIT {37,37}
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LIMIT_VAL 96

#define LAYER_STATE_8BIT
