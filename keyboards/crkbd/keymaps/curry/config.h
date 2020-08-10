#pragma once

#define EE_HANDS

#define OLED_DISABLE_TIMEOUT
#define TAPPING_TERM_PER_KEY

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 5
#    define RGB_MATRIX_SPD_STEP 10
#endif
