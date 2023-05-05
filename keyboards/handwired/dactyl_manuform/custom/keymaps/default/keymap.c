#include QMK_KEYBOARD_H

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
    TD_SCLN_COLN
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_SCLN_COLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN)
};

// Layers declarations
enum {
    CLMK = 0,
    QWER,
    GAME,
    NVIM,
    NUMK,
    SYMB,
    MOUS,
    SYST
};

/*
The following are some shortcuts definitions:
TD: Tap-Dancing
MT: Mod-Tap
*/
#define TD_EPS TD(TD_ESC_CAPS)   // TD: ESC & CAPS
#define TD_SCL TD(TD_SCLN_COLN)  // TD: ; & :
#define MT_SPF SFT_T(KC_SPC)     // MT: SPACE & SHIFT
#define MT_CTG LCTL_T(KC_GRV)    // MT: CONTROL & `
#define MT_CTD RCTL_T(KC_DLR)    // MT: CONTROL & $ (with SHIFT held)
#define MT_LMH LCMD_T(KC_HASH)   // MT: CMD & # (with SHIFT held)
#define MT_RMH RCMD_T(KC_ASTR)   // MT: CMD & * (with SHIFT held)

// Defines the keycodes used by our macros in process_record_user
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [CLMK] = LAYOUT(
        TD_EPS,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS, \
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                                        KC_J,   KC_L,   KC_U,    KC_Y,   TD_SCL, KC_EQL,  \
        KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                                        KC_H,   KC_N,   KC_E,    KC_I,   KC_O,    KC_QUOT, \
        KC_DEL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                        KC_K,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, TO(SYST),\
                          KC_EXLM, KC_UNDS, KC_ENT,  MT_SPF, MT_LMH,   MT_CTG,   MT_CTD,  MT_RMH, MT_SPF, KC_ENT, TG(MOUS),TG(NUMK), \
                                                             TT(NVIM), KC_LOPT,  KC_ROPT, TT(SYMB) \
    ),

    [QWER] = LAYOUT(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    _______, \
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    _______, \
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, _______, \
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                         KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, _______, \
                          _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, \
                                                              _______, _______,  _______, _______ \
    ),

    [GAME] = LAYOUT(
        KC_ESC,  KC_GRV, KC_1,    KC_2,   KC_3,    KC_4,                                        _______, _______, _______, _______, _______, _______, \
        KC_TAB,  KC_T,   KC_Q,    KC_W,   KC_E,    KC_R,                                        _______, _______, _______, _______, _______, _______, \
        KC_BSPC, KC_G,   KC_A,    KC_S,   KC_D,    KC_F,                                        _______, _______, _______, _______, _______, _______, \
        KC_DEL,  KC_B,   KC_Z,    KC_X,   KC_C,    KC_V,                                        _______, _______, _______, _______, _______, _______, \
                         KC_COMM, KC_DOT, KC_SLSH, KC_SPC, KC_LCTL, KC_LSFT,  _______, _______, _______, _______, _______, _______, \
                                                           KC_QUOT, KC_LALT,  _______, _______ \
    ),

    [NVIM] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,  \
        _______, _______, KC_WH_U, KC_UP,   KC_PGUP, KC_HOME,                                      _______, _______, _______, _______, _______,    _______, \
        _______,C(KC_LEFT),KC_LEFT,KC_DOWN, KC_RGHT, C(KC_RGHT),                                   KC_H,    KC_J,    KC_K,    KC_L,    _______,    _______, \
        _______, _______, KC_WH_D, _______, KC_PGDN, _______,                                      _______, _______, _______, _______, _______,    _______, \
                          XXXXXXX, XXXXXXX, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, \
                                                              _______, _______,  _______, _______ \
    ),

    [NUMK] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                      KC_NO,KC_NUMLOCK, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, \
        _______, _______, _______, _______, _______, _______,                                      KC_COMM, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, XXXXXXX, \
        _______, _______, _______, _______, _______, _______,                                      KC_PDOT, KC_P4,   KC_P5,   KC_P6,   KC_PCMM, XXXXXXX, \
        _______, _______, _______, _______, _______, _______,                                      KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PDOT, _______, \
                          _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, \
                                                              _______, _______,  _______, _______ \
    ),

    [SYMB] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
        KC_GRV,  KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, KC_PLUS,                                      KC_PLUS, KC_RCBR, KC_LCBR, KC_DLR,  KC_HASH, KC_GRV,  \
        KC_ASTR, KC_LABK, KC_RABK, KC_LPRN, KC_RPRN, KC_PIPE,                                      KC_PIPE, KC_RPRN, KC_LPRN, KC_RABK, KC_LABK, KC_ASTR, \
        KC_BSLS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                                      KC_TILD, KC_RBRC, KC_LBRC, KC_CIRC, KC_PERC, KC_BSLS, \
                          _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, \
                                                              _______, _______,  _______, _______ \
    ),

    [MOUS] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                                      _______, KC_WH_U, KC_MS_U, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                                      _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, \
        _______, _______, _______, _______, _______, _______,                                      _______, KC_WH_D, _______, _______, _______, _______, \
                          _______, _______, _______, _______, _______, _______,  _______, KC_ACL0, KC_BTN1, KC_BTN2, _______, _______, \
                                                              _______, _______,  _______, _______ \
    ),

    [SYST] = LAYOUT(
        RESET,   RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  \
        EEP_RST, RGB_VAI, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX,                                      EEP_RST, RGB_VAI, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX,  \
        XXXXXXX, RGB_VAD, RGB_RMOD,XXXXXXX, XXXXXXX, XXXXXXX,                                      XXXXXXX, RGB_VAD, RGB_RMOD,XXXXXXX, XXXXXXX, TO(GAME), \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(GAME),                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(QWER),TO(CLMK), \
                          XXXXXXX, XXXXXXX, TO(QWER),TO(CLMK),XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                                              XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX \
    ),
};
