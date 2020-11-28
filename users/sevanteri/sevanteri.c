#include QMK_KEYBOARD_H
#include "timer.h"
#include "sevanteri.h"
#include "sendstring_finnish.h"
#include "keymap_finnish.h"

#ifdef POINTING_DEVICE_ENABLE
#include "pointing_device.h"
#endif

#ifdef PIMORONI_TRACKBALL_ENABLE
#include "pimoroni_trackball.h"
#endif

#ifdef COMBO_ENABLE
#include "action_tapping.h"
/* #include "combos.h" */
#include "g/keymap_combo.h"
#endif

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }


static uint16_t code_timer;
uint8_t tb_brightness = 32;

static bool alt_sft = false;
static bool alt_sft_state = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) { // {{{
    const bool pressed = record->event.pressed;
    switch (keycode) {
        case CODEBLK:
            if (pressed) {
                code_timer = timer_read();
            } else {
                if (timer_elapsed(code_timer) > TAPPING_TERM) {
                    SEND_STRING(
                        "````````````"
                        SS_TAP(X_LEFT)
                        SS_TAP(X_LEFT)
                        SS_TAP(X_LEFT)
                    );
                } else {
                    SEND_STRING("``" SS_TAP(X_LEFT) "``");
                }
            }
            return false;
        case ALTSHFT:
            if (pressed) return false;
            alt_sft = !alt_sft;
            alt_sft_state = false;
            return false;
#ifdef PIMORONI_TRACKBALL_ENABLE
        case RESET:
            trackball_set_rgbw(tb_brightness, 0, 0, 0);
            return true;
        case KC_SLEP:
            if (!pressed) return true;
            /* trackball_sleep(); */
            /* trackball_set_brightness(0); */
            return true;
        case TB_B_UP:
            if (!pressed) return false;
            tb_brightness = (tb_brightness + 32) % 224;
            trackball_set_brightness(tb_brightness|1);
            /* xprintf("%d\n",  tb_brightness); */
            return false;
        case TB_B_DN:
            if (!pressed) return false;
            tb_brightness = (tb_brightness - 32) % 256;
            trackball_set_brightness(tb_brightness|1);
            /* xprintf("%d\n",  tb_brightness); */
            return false;
        case MY_VIM_V:
            if (!pressed) break;
            tap_code(KC_HOME);
            tap_code16(LSFT(KC_END));
            break;
        case MY_VIM_S:
            if (!pressed) break;
            tap_code(KC_HOME);
            tap_code16(LSFT(KC_END));
            tap_code(KC_BSPC);
            break;
        case MY_VIM_C:
            if (!pressed) break;
            tap_code16(LSFT(KC_END));
            tap_code(KC_BSPC);
            break;
        case MY_VIM_CW:
            if (!pressed) break;
            tap_code16(LCTL(LSFT(KC_RIGHT)));
            tap_code(KC_BSPC);
            break;
        case MY_PARENSBOTH:
            if (!pressed) break;
            tap_code16(FI_LPRN);
            tap_code16(KC_ENT);
            tap_code16(KC_END);
            tap_code16(KC_ENT);
            tap_code16(FI_RPRN);
            tap_code16(KC_UP);
            tap_code16(KC_END);
            break;
        case MY_SQUAREBRACEBOTH:
            if (!pressed) break;
            tap_code16(FI_LBRC);
            tap_code16(KC_ENT);
            tap_code16(KC_END);
            tap_code16(KC_ENT);
            tap_code16(FI_RBRC);
            tap_code16(KC_UP);
            tap_code16(KC_END);
            break;
        case MY_CURLYBRACEBOTH:
            if (!pressed) break;
            tap_code16(FI_LCBR);
            tap_code16(KC_ENT);
            tap_code16(KC_END);
            tap_code16(KC_ENT);
            tap_code16(FI_RCBR);
            tap_code16(KC_UP);
            tap_code16(KC_END);
            break;
#endif
    }

#ifdef POINTING_DEVICE_ENABLE

    report_mouse_t report = pointing_device_get_report();
    switch(keycode) {
        case KC_BTN1:
            if (pressed) report.buttons |= MOUSE_BTN1;
            else report.buttons &= ~MOUSE_BTN1;
            pointing_device_set_report(report);
            pointing_device_send();
            return false;
        case KC_BTN2:
            if (pressed) report.buttons |= MOUSE_BTN2;
            else report.buttons &= ~MOUSE_BTN2;
            pointing_device_set_report(report);
            pointing_device_send();
            return false;
        case KC_BTN3:
            if (pressed) report.buttons |= MOUSE_BTN3;
            else report.buttons &= ~MOUSE_BTN3;
            pointing_device_set_report(report);
            pointing_device_send();
            return false;
    }
#endif

    if (alt_sft) {
        switch (keycode) {
            case FI_ADIA:
            case FI_ODIA:
            case KC_A...KC_Z:
                if (pressed && !get_mods()) {
                    if (!alt_sft_state) {
                        set_oneshot_mods(get_oneshot_mods() | MOD_MASK_SHIFT);
                    }
                    alt_sft_state = !alt_sft_state;
                }
        }
    }
    return process_record_keymap(keycode, record);
} // }}}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) { // {{{
    switch (keycode) {
        case LSFT_T(KC_X):
        case LT(_FUNC, KC_X):
        case LCTL_T(KC_ESC):
        case MY_THL1:
        case MY_THL2:
        case MY_THL3:
        case MY_THR2:
            return false;
        default:
            return true;
    }
}
// }}}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { // {{{
    switch (keycode) {
        case MY_A:
        case MY_S:
        case MY_D:
        case MY_F:
        case MY_G:
        case MY_J:
        case MY_K:
        case MY_L:
        case MY_OE:
        case MY_AE:
            return false;
        default:
            return true;
    }
}
// }}}

// custom tapping terms for keys {{{
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* case MY_THR2: */
        /*     return 70; */
    }
    return TAPPING_TERM;
}
// }}}

#ifdef COMBO_ENABLE
// custom combo terms {{{
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    if (KEYCODE_IS_MOD(combo->keycode)) return COMBO_MOD_TERM;

    /* switch(combo->keycode) { */
    /*     case RESET: */
    /*         return COMBO_MOD_TERM; */
    /* } */

    /* switch(index) { */
    /*     case C_QUOT: */
    /*     case C_ACUT: */
    /*         return 20; */
    /* } */

    // Longer term for THUMB+alpha
    /* if (combo->keys[0] == MY_THR3 || */
    /*     combo->keys[0] == MY_THR2) { */
    /*     return 100; */
    /* } */

    return COMBO_TERM;
}
// }}}

bool get_combo_must_hold(uint16_t index, combo_t *combo) { // {{{
    switch(combo->keycode) {
        case RESET:
            return true;
    }
    if (KEYCODE_IS_MOD(combo->keycode)) return true;

    return false;
} // }}}


#ifdef COMBO_PROCESS_KEY_RELEASE
bool process_combo_key_release(uint16_t combo_index, combo_t *combo, uint8_t key_index, keypos_t *keypos) {
    switch (combo_index) {
        case C_THUMB_CTL_SFT:
        case C_THUMB_ALT_SFT:
        case C_THUMB_ALT_CTL:
            if(KEYEQ(*keypos, POS_A) ||
               KEYEQ(*keypos, POS_THL1)) {
                    unregister_mods(MOD_MASK_CTRL);
            } else if (KEYEQ(*keypos, POS_S)) {
                    unregister_mods(MOD_MASK_SHIFT);
            } else if (KEYEQ(*keypos, POS_THL2)) {
                    unregister_mods(MOD_MASK_ALT);
            }
            break;
        /* case C_GMAIL: */
        /*     // true releases the combo immediately. */
        /*     return true; */
    }
    return false;
}
#endif

#endif

void trigger_tapping(void) {
    action_tapping_process((keyrecord_t){});
}


/* enum myCombos { */
/*     C_FOO, */
/*     COMBO_LENGTH */
/* }; */
/* uint16_t COMBO_LEN = COMBO_LENGTH; */

/* const keypos_t foo_combo[] = {POS_A, POS_S, KPOS(255,255)}; */
/* combo_t key_combos[] ={ */
/*     [C_FOO] = COMBO(foo_combo, KC_X), */
/* }; */
