/* Copyright 2020 GhostSeven <work@ghost7.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum encoder_names { _ENCODER };

enum my_keycodes { MY_KEY_1 = SAFE_RANGE, MY_KEY_2, MY_KEY_3, MY_KEY_4, MY_KEY_5 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        |                   |      | Knob 1: Vol Dn/Up  |
        | Hold: Layer 2     | Up   | Press: Mute        |
        | Left              | Down | Right              |
     */
    [0] = LAYOUT(MY_KEY_1, MY_KEY_2, KC_MUTE, MY_KEY_3, MY_KEY_4, MY_KEY_5),
    /*
        | Held: Layer 2  | Home | QK_BOOT      |
        | Media Previous | End  | Media Next |
     */
    // [1] = LAYOUT(_______, KC_HOME, QK_BOOT, KC_MPRV, KC_END, KC_MNXT),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _ENCODER) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_KEY_1:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LCTL(SS_LSFT(SS_LALT("1")))));
            }
            return false; // Skip all further processing of this key
        case MY_KEY_2:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LCTL(SS_LSFT(SS_LALT("2")))));
            }
            return false; // Skip all further processing of this key
        case MY_KEY_3:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LCTL(SS_LSFT(SS_LALT("3")))));
            }
            return false; // Skip all further processing of this key
        case MY_KEY_4:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LCTL(SS_LSFT(SS_LALT("4")))));
            }
            return false; // Skip all further processing of this key
        case MY_KEY_5:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LCTL(SS_LSFT(SS_LALT("5")))));
            }
            return false; // Skip all further processing of this key
    }
    return true;
}