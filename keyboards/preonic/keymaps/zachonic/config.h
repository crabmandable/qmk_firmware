#pragma once

#ifdef AUDIO_ENABLE
    //#define STARTUP_SONG SONG(PREONIC_SOUND)

    #define STARTUP_SONG SONG(\
		    E__NOTE(_FS3), E__NOTE(_CS4), Q__NOTE(_REST), \
		    E__NOTE(_B4), E__NOTE(_FS4), Q__NOTE(_REST), \
		    E__NOTE(_FS3), E__NOTE(_CS4), Q__NOTE(_REST), \
		    E__NOTE(_B3), E__NOTE(_FS2), Q__NOTE(_REST), \
		    E__NOTE(_B3), E__NOTE(_B4), E__NOTE(_CS3), E__NOTE(_B4), E__NOTE(_DS3), E__NOTE(_B4), E__NOTE(_E3), E__NOTE(_B4), E__NOTE(_FS3), E__NOTE(_B5), E__NOTE(_GS3), E__NOTE(_B5), E__NOTE(_AS3), E__NOTE(_B4), E__NOTE(_B3), E__NOTE(_B5),\
		    E__NOTE(_B4), E__NOTE(_B5), E__NOTE(_CS4), E__NOTE(_B5), E__NOTE(_DS4), E__NOTE(_B5), E__NOTE(_E4), E__NOTE(_B5), E__NOTE(_FS4), E__NOTE(_B6), E__NOTE(_GS4), E__NOTE(_B6), E__NOTE(_AS4), E__NOTE(_B5), E__NOTE(_B4), E__NOTE(_B6),\
		    E__NOTE(_B3), E__NOTE(_B2), E__NOTE(_AS2), E__NOTE(_B3), E__NOTE(_GS2), E__NOTE(_B3), E__NOTE(_FS2), E__NOTE(_B3), E__NOTE(_E2), E__NOTE(_B2), E__NOTE(_DS2), E__NOTE(_B2), E__NOTE(_CS2), E__NOTE(_B2), E__NOTE(_B1), E__NOTE(_B2),\
		    H__NOTE(_B1),\
		    )

    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2
