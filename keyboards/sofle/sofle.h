#pragma once

#if defined(KEYBOARD_sofle_rev1)
#    include "rev1.h"
#elif defined(KEYBOARD_sofle_keyhive)
#    include "keyhive/config.h"
#endif
#ifdef KEYBOARD_sofle_rev2
    #include "rev2.h"
#endif
