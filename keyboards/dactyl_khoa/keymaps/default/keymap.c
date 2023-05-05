#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_5x7(KC_TILDE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,

                     KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,

                     KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, TAB_RO)};
