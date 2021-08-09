#pragma once

#include "config_common.h"

/* USB Device Descriptor Parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0100
#define MANUFACTURER    futurista.com.br
#define PRODUCT         Ghettolinear

// Comunication and Split Detection
#define USE_I2C
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 1000
// p#define EE_HANDS

// Key Matrix Size //
// Rows are Doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

// Wiring of Each Half
#define DIODE_DIRECTION COL2ROW
#define MASTER_RIGHT
// Teensy  Right and Left

// I2C usa D0 e D1
// OLED usa 
#define MATRIX_ROW_PINS { F0, F1, F4, F5, F6 }
#define MATRIX_COL_PINS { F7, B6, B5, B4, D7, D6, D4 }
// #define MATRIX_COL_PINS_RIGHT { B6, B2, B3, B1, F7, F6, F5 }

// Teensy LEFT
// #define MATRIX_ROW_PINS { B2, B3, D3, C7, D5 }
//#ifdef OLED_DRIVER_ENABLE

//// OLED Display Config
#define OLED_DISPLAY_128X64
#define OLED_FONT_HEIGHT 8
#define OLED_FONT_WIDTH 8
#define OLED_FONT_H "ghetto_font.c"
#define OLED_FONT_END 255
// Tap Dance

#define TAPPING_TERM 200

// Other

//#define DEBOUNCE 0

