#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6062
#define DEVICE_VER      0x0001
#define MANUFACTURER    timal
#define PRODUCT         crimson pad

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 7

/* key matrix pins */
#define MATRIX_ROW_PINS { B6 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 2
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

// OLED 
#ifdef OLED_DRIVER_ENABLE
#define OLED_BRIGHTNESS 90
#define OLED_TIMEOUT 60000
#endif

//RGB lights
#define RGB_DI_PIN B5
#ifdef RGB_DI_PIN
#define RGBLED_NUM 5
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

#endif