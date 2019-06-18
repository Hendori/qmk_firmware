/* vim: set fdm=marker */
// Nordic layout for Ergodox infinity

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "action.h"
#include "version.h"
#include "keymap_nordic.h"
#include "keymap_german.h"

// Layer names
#define BASE 0 // default layer
#define NUMP 2 // numpad layer
#define SYMB 3 // number and symbol layer
#define GAME 4 // gaming layer
#define FUNCL 15 // function layer

// mod taps
#define CTRLESC LCTL_T(KC_ESC) // hold esc for ctrl
#define LGUIBSP LGUI_T(KC_BSPC) // hold backspace for super (left hand)
#define RSFTSPC RSFT_T(KC_SPC) // hold space for shift
#define LALTSPC LALT_T(KC_SPC) // hold space for alt (left hand)

#define LSFT_LT LSFT_T(KC_NUBS) // left shift is ISO/ on tap

#define SYMBENT LT(SYMB, KC_ENT) // hold enter for symbol layer (right hand)

// other keys
#define CTRLTAB LCTL(KC_TAB)
#define CSFTTAB LCTL(LSFT(KC_TAB))

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    VRSN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer {{{
 *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ISO/  |   1  |   2  |   3  |   4  |   5  | NUMP |           | NUMP |   6  |   7  |   8  |   9  |   0  |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  ¨^  |           |  Å   |   Y  |   U  |   I  |   O  |   P  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  ESC   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------| DEL  |           | BSPC |------+------+------+------+------+--------|
 * | LShift<|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  -   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  ´`  |  §½  | RBTN | LBTN |                                       | RALT | PRSC | INS  |RCTRL | RGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | HOME | END  |       | PgUp |RCTRL |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 | LATL | LGUI |FUNCL |       | PgDn |  SYMB  | Shift|
 *                                 | Space| BSPC |------|       |------|  Enter | Space|
 *                                 |      |      | LCTRL|       |FUNCL |        |      |
 *                                 `--------------------'       `----------------------'
 */

// layer 0 : default
[BASE] = LAYOUT_ergodox_pretty(

    KC_GRV,   KC_1,   KC_2,   KC_3,    KC_4,    KC_5,    TG(NUMP),  /*****/ TG(NUMP),  KC_6,    KC_7,   KC_8,     KC_9,   KC_0,    KC_MINS,
    KC_TAB,   KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,    KC_RBRC,   /*****/ KC_LBRC,   KC_Y,    KC_U,   KC_I,     KC_O,   KC_P,    KC_NUHS,
    CTRLESC,  KC_A,   KC_S,   KC_D,    KC_F,    KC_G,    /**/       /*****/ /**/       KC_H,    KC_J,   KC_K,     KC_L,   KC_SCLN, KC_QUOT,
    LSFT_LT,  KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,    KC_DELT,   /*****/ KC_BSPC,   KC_N,    KC_M,   KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTRL, KC_EQL, KC_GRV, KC_BTN2, KC_BTN1, /**/     /**/       /*****/ KC_RALT,   KC_PSCR, KC_INS, KC_RCTRL, KC_RGUI,

    /**/      /**/    /**/    /**/     /**/     KC_HOME, KC_END,    /*****/ KC_PGUP,   KC_RCTRL,
    /**/      /**/    /**/    /**/     /**/     /**/     MO(FUNCL), /*****/ KC_PGDN,
    /**/      /**/    /**/    /**/     LALTSPC, LGUIBSP, KC_LCTRL,  /*****/ MO(FUNCL), SYMBENT, RSFTSPC

),
// }}}

/* Keymap 1: Function layer {{{
 *
 *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           | F12  |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | PLAY |      |VOLUP |      | GAME |           |      |BRBAK | CTAB |CSTAB |BRFWD |      | AS_UP  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | PREV | STOP | NEXT |VOLDN |      |------|           |------| LEFT | DOWN |  UP  |RIGHT |      | AS_DN  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | AS_RP  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |       |     |      |                                       |      |      |      |      | AS_T |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |BLTOG |       |      |      |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      | BL+  |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      | BL-  |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */

// layer 1 : functions
[FUNCL] = LAYOUT_ergodox_pretty(

    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,   /*****/ KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  _______,
    _______, _______, KC_MPLY, _______, KC_VOLU, _______, TG(GAME), /*****/ _______, KC_WBAK, CTRLTAB, CSFTTAB, KC_WFWD,  _______, KC_ASUP,
    _______, KC_MPRV, KC_MSTP, KC_MNXT, KC_VOLD, _______, /**/      /*****/ /**/     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, KC_ASDN,
    _______, _______, _______, _______, _______, _______, _______, /*****/ _______, _______, _______, _______, _______,  _______, KC_ASRP,
    _______, _______, _______, _______, _______, /**/     /**/      /*****/ /**/     /**/     _______, _______, _______,  _______, KC_ASTG,

    /**/     /**/     /**/     /**/     /**/     _______, BL_TOGG,  /*****/ _______, _______,
    /**/     /**/     /**/     /**/     /**/     /**/     BL_INC,   /*****/ _______,
    /**/     /**/     /**/     /**/     _______, _______, BL_DEC,   /*****/ _______, _______, _______

),
// }}}

/* Keymap 2: Numpad Layer {{{
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |NUMLCK|  P/  |  P*  |  P-  | RESET  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |  P+  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |  P+  |        |
 * |--------+------+------+------+------+------|      |           | BSPC |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |Penter|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |       |     |      |                                       |      |      |  P.  |Penter|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|Enter |  P0  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// NUMPAD
[NUMP] = LAYOUT_ergodox_pretty(

    RESET,   _______, _______, _______, _______, _______, _______, /*****/ _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, RESET,
    _______, _______, _______, _______, _______, _______, _______, /*****/ _______, _______, KC_7,    KC_8,    KC_9,    KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______, /**/     /*****/ /**/     _______, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______, _______, /*****/ KC_BSPC, _______, KC_1,    KC_2,    KC_3,    KC_PENT, _______,
    _______, _______, _______, _______, _______, /**/     /**/     /*****/ /**/     /**/     _______, _______, KC_PDOT, KC_PENT, _______,

    /**/     /**/     /**/     /**/     /**/     _______, _______, /*****/ _______, _______,
    /**/     /**/     /**/     /**/     /**/     /**/     _______, /*****/ _______,
    /**/     /**/     /**/     /**/     _______, _______, _______, /*****/ _______, KC_ENT,  KC_0

),
// }}}

/* Number and symbol layer {{{
 *
 *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  !   |  "   |  #   |  ¤   |  %   |      |           |      |  &   |  /   |  (   |  )   |  =   |   ?    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  1   |  2   |  3   |  4   |  5   |------|           |------|  6   |  7   |  8   |  9   |  0   |   +    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  @   |  £   |  $   |  ‰   |      |           |      |  ‚   |  {   |  [   |  ]   |  }   |   \    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |       |     |      |                                       |      |      |      |  ´   |  `   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */

// number and symbol layer
[SYMB] = LAYOUT_ergodox_pretty(

    _______,      _______,    _______,    _______,    _______,    _______,    _______, /*****/ _______, _______,    _______,    _______,    _______,    _______,    _______,
    LSFT(KC_GRV), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), _______, /*****/ _______, LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINS),
    KC_GRV,       KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       /**/     /*****/ /**/     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
    LSFT(KC_GRV), RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5), _______, /*****/ _______, RALT(KC_6), RALT(KC_7), RALT(KC_8), RALT(KC_9), RALT(KC_0), RALT(KC_MINS),
    _______,      _______,    _______,    _______,    _______,    /**/        /**/     /*****/ /**/     /**/        _______,    _______,    _______,    KC_EQL,     LSFT(KC_EQL),

    /**/          /**/        /**/        /**/        /**/        _______,    _______, /*****/ _______, _______,
    /**/          /**/        /**/        /**/        /**/        /**/        _______, /*****/ _______,
    /**/          /**/        /**/        /**/        _______,    _______,    _______, /*****/ _______, _______,    _______

),
// }}}

/* Keymap 3: Gaming {{{
 *
 *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCTRL  |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |       |     |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 | Space| Space|      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */

// gaming layer
[GAME] = LAYOUT_ergodox_pretty(

    KC_ESC,   _______, _______, _______, _______, _______, _______, /*****/ _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, /*****/ _______, _______, _______, _______, _______, _______, _______,
    KC_LCTRL, _______, _______, _______, _______, _______, /**/     /*****/ /**/     _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, /*****/ _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, /**/     /**/     /*****/ /**/     /**/     _______, _______, _______, _______, _______,

    /**/      /**/     /**/     /**/     /**/     _______, _______, /*****/ _______, _______,
    /**/      /**/     /**/     /**/     /**/     /**/     _______, /*****/ _______,
    /**/      /**/     /**/     /**/     KC_SPC,  KC_SPC,  _______, /*****/ _______, _______, _______

)
// }}}

};

bool ignore_mod_tap_interrupt(keyrecord_t *record) {
    // copy paste code from tmk_core/common/action.c:197
    keyevent_t event = record->event;
    action_t action = store_or_get_action(record->event.pressed, record->event.key);
    uint8_t tap_count = record->tap.count;

    switch (action.kind.id) {
        case ACT_RMODS_TAP:
        case ACT_LMODS_TAP:
            {
                uint8_t mods = (action.kind.id == ACT_LMODS_TAP) ?
                                action.key.mods :
                                action.key.mods<<4;
                if (event.pressed) {
                    if (tap_count > 0) {
                        {
                            dprint("MODS_TAP: Tap: register_code\n");
                            register_code(action.key.code);
                        }
                    } else {
                        dprint("MODS_TAP: No tap: add_mods\n");
                        register_mods(mods);
                    }
                } else {
                    if (tap_count > 0) {
                        dprint("MODS_TAP: Tap: unregister_code\n");
                        unregister_code(action.key.code);
                    } else {
                        dprint("MODS_TAP: No tap: add_mods\n");
                        unregister_mods(mods);
                    }
                }
                return false;
            }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // dynamically generate these.
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
        case RSFTSPC:
        case SYMBENT:
            // ignore MT interrupt for some of my MT keys
            return ignore_mod_tap_interrupt(record);
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case FUNCL:
            ergodox_right_led_1_on();
            break;
        case NUMP:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};

// custom tapping terms for keys
uint16_t get_tapping_term(uint16_t keycode) {
    switch (keycode) {
        case RSFTSPC:
        case SYMBENT:
            return TAPPING_TERM + 350;
        default:
            return TAPPING_TERM;
    }
}
