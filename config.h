/**
 * Copyright 2020 Alexander Lomachenko
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0000
#define DEVICE_VER 0x0001
#define MANUFACTURER BFK
#define PRODUCT Pad
#define DESCRIPTION A custom keyboard

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 5

/**
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_COL_PINS \
    { F0, F1, F4, F5, F6 }
#define MATRIX_ROW_PINS \
    { B4, B5, B6 }
#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* QMK ESC for entering bootloader */
#define QMK_ESC_OUTPUT F4  // usually COL
#define QMK_ESC_INPUT B4   // usually ROW

/* Encoder support */
#define ENCODERS_PAD_A { C6 }
#define ENCODERS_PAD_B { C7 }
#define ENCODER_RESOLUTION 4
