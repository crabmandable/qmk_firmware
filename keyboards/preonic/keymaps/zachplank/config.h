#pragma once

#ifdef AUDIO_ENABLE
    #define AUDIO_INIT_DELAY
    #define STARTUP_SONG SONG(PREONIC_SOUND)

    /* #define STARTUP_SONG SONG(\ */
		    /* E__NOTE(_FS3), E__NOTE(_CS4), Q__NOTE(_REST), \ */
		    /* E__NOTE(_B4), E__NOTE(_FS4), Q__NOTE(_REST), \ */
		    /* E__NOTE(_FS3), E__NOTE(_CS4), Q__NOTE(_REST), \ */
		    /* E__NOTE(_B3), E__NOTE(_FS2), Q__NOTE(_REST), \ */
		    /* E__NOTE(_B3), E__NOTE(_B4), E__NOTE(_CS3), E__NOTE(_B4), E__NOTE(_DS3), E__NOTE(_B4), E__NOTE(_E3), E__NOTE(_B4), E__NOTE(_FS3), E__NOTE(_B5), E__NOTE(_GS3), E__NOTE(_B5), E__NOTE(_AS3), E__NOTE(_B4), E__NOTE(_B3), E__NOTE(_B5),\ */
		    /* E__NOTE(_B4), E__NOTE(_B5), E__NOTE(_CS4), E__NOTE(_B5), E__NOTE(_DS4), E__NOTE(_B5), E__NOTE(_E4), E__NOTE(_B5), E__NOTE(_FS4), E__NOTE(_B6), E__NOTE(_GS4), E__NOTE(_B6), E__NOTE(_AS4), E__NOTE(_B5), E__NOTE(_B4), E__NOTE(_B6),\ */
		    /* E__NOTE(_B3), E__NOTE(_B2), E__NOTE(_AS2), E__NOTE(_B3), E__NOTE(_GS2), E__NOTE(_B3), E__NOTE(_FS2), E__NOTE(_B3), E__NOTE(_E2), E__NOTE(_B2), E__NOTE(_DS2), E__NOTE(_B2), E__NOTE(_CS2), E__NOTE(_B2), E__NOTE(_B1), E__NOTE(_B2),\ */
		    /* H__NOTE(_B1),\ */
		    /* ) */

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }

#endif
#define MUSIC_MASK (keycode != KC_NO)

#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
#undef HOLD_ON_OTHER_KEY_PRESS
