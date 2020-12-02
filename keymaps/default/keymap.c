/**
 * Copyright 2020 Alexander Lomachenko
 */

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names { _BASE, _FN };

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    oled_write_P(PSTR("Encoder: Volume\n"), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT( \
        KC_MUTE, MO(1), LGUI(KC_L), KC_SLEP, \
		LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RGHT)), KC_MPRV, KC_MPLY, KC_MNXT, \
		LGUI(KC_D), LGUI(KC_TAB), LALT(KC_TAB), LCTL(LALT(KC_SPC)), KC_MUTE \
    ),
    /* FN */
    [_FN] = LAYOUT( \
        KC_TRNS, MO(0), KC_TRNS, RESET, \
		KC_F22, KC_F21, KC_F20, KC_F19, KC_F18, \
		KC_F17, KC_F16, KC_F15, KC_F14, KC_F13 \
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_AUDIO_VOL_UP);
    } else {
        tap_code(KC_AUDIO_VOL_DOWN);
    }
}
