/*
    For mapping ansi keys to their german keycodes.
    So that I can type in an ansi layout but have german layout on the PC for all my keyboards.
*/

#ifndef MAPPING_H
#define MAPPING_H

#define _  KC_TRNS

// Correct ANSI keycode names for existing keycodes from the german layout
#define CKC_Y KC_Z
#define CKC_Z KC_Y
#define CKC_MINS KC_SLSH

// Umlaute
#define CKC_UMLA KC_QUOT
#define CKC_UMLO KC_SCLN
#define CKC_UMLU KC_LBRC

// Implemented in process_record_user
enum Custom {
    CUSTOM_KEYS_START = SAFE_RANGE, // used to initialize an array for storing the state of all custom keys

    // handles shift
    CKC_2,
    CKC_3,
    CKC_6,
    CKC_7,
    CKC_8,
    CKC_9,
    CKC_0,
    CKC_QUOT,
    CKC_COMM,
    CKC_DOT,
    CKC_GESC,

    // ignores shift
    CKC_AT,
    CKC_HASH,
    CKC_AMPR,
    CKC_ASTR,
    CKC_UNDS,
    CKC_EQL,
    CKC_PLUS,
    CKC_SLSH,
    CKC_BSLS,
    CKC_PIPE,
    CKC_DQUO,
    CKC_TILD,
    CKC_COLN,
    CKC_SCLN,
    CKC_QUES,
    CKC_LPRN,
    CKC_RPRN,
    CKC_LBRC,
    CKC_RBRC,
    CKC_LCBR,
    CKC_RCBR,
    CKC_SZ,
    CKC_EURO,

    CUSTOM_KEYS_END,

    // these dont need state
    CKC_CIRC,
    CKC_GRV
};

bool physical_lshift_down = false;
bool physical_rshift_down = false;
bool lshift_down = false;
bool rshift_down = false;
bool alt_down = false;

#define SHIFT_DOWN (lshift_down || rshift_down)
#define PHYSICAL_SHIFT_DOWN (physical_lshift_down || physical_rshift_down)

uint8_t *custom_key_state;

#define PRESSED_WITH_PHYSICAL_SHIFT 0x01
#define RESTORE_SHIFT_STATE         0x02
#define SHIFT_REGISTERED            0x04
#define RESTORE_ALT_STATE           0x08
#define ALT_REGISTERED              0x10

#define KEY_STATE(state, keycode) (custom_key_state[keycode - CUSTOM_KEYS_START - 1] & state)
#define SET_KEY_STATE(state, keycode) (custom_key_state[keycode - CUSTOM_KEYS_START - 1] = custom_key_state[keycode - CUSTOM_KEYS_START - 1] | state)
#define CLEAR_KEY_STATE(state, keycode) (custom_key_state[keycode - CUSTOM_KEYS_START - 1] = custom_key_state[keycode - CUSTOM_KEYS_START - 1] & ~state)

void mapping_keyboard_post_init(void) {
    debug_enable=true;

    uint16_t size = (CUSTOM_KEYS_END - CUSTOM_KEYS_START - 1) * sizeof(uint8_t);
    custom_key_state = (uint8_t*) malloc(size);
    memset(custom_key_state, 0, size);
}

void register_shift(void) {
    if (physical_rshift_down) {
        register_code(KC_RSFT);
        rshift_down = true;
    } else {
        register_code(KC_LSFT);
        lshift_down = true;
    }
}

void unregister_shift(void) {
    if (physical_rshift_down) {
        unregister_code(KC_RSFT);
        rshift_down = false;
    } else {
        unregister_code(KC_LSFT);
        lshift_down = false;
    }
}

void ensure_shift_down(uint16_t keycode) {
    if (SHIFT_DOWN) {
        CLEAR_KEY_STATE(RESTORE_SHIFT_STATE, keycode);
    } else {
        register_shift();
        SET_KEY_STATE(RESTORE_SHIFT_STATE, keycode);
        SET_KEY_STATE(SHIFT_REGISTERED, keycode);
    }
}

void ensure_shift_up(uint16_t keycode) {
    if (SHIFT_DOWN) {
        unregister_shift();
        SET_KEY_STATE(RESTORE_SHIFT_STATE, keycode);
        CLEAR_KEY_STATE(SHIFT_REGISTERED, keycode);
    } else {
        CLEAR_KEY_STATE(RESTORE_SHIFT_STATE, keycode);
    }
}

void restore_shift_state(uint16_t keycode) {
    if (KEY_STATE(RESTORE_SHIFT_STATE, keycode)) {
        CLEAR_KEY_STATE(RESTORE_SHIFT_STATE, keycode);

        if (KEY_STATE(SHIFT_REGISTERED, keycode) && !PHYSICAL_SHIFT_DOWN) {
            unregister_shift();
        } else if (!KEY_STATE(SHIFT_REGISTERED, keycode) && PHYSICAL_SHIFT_DOWN) {
            register_shift();
        }
    }
}

void register_alt(void) {
    register_code(KC_RALT);
    alt_down = true;
}

void unregister_alt(void) {
    unregister_code(KC_RALT);
    alt_down = false;
}

void ensure_alt_down(uint16_t keycode) {
    if (alt_down) {
        CLEAR_KEY_STATE(RESTORE_ALT_STATE, keycode);
    } else {
        register_alt();
        SET_KEY_STATE(RESTORE_ALT_STATE, keycode);
        SET_KEY_STATE(ALT_REGISTERED, keycode);
    }
}

void ensure_alt_up(uint16_t keycode) {
    if (alt_down) {
        unregister_alt();
        SET_KEY_STATE(RESTORE_ALT_STATE, keycode);
        CLEAR_KEY_STATE(ALT_REGISTERED, keycode);
    } else {
        CLEAR_KEY_STATE(RESTORE_ALT_STATE, keycode);
    }
}

void restore_alt_state(uint16_t keycode) {
    if (KEY_STATE(RESTORE_ALT_STATE, keycode)) {
        CLEAR_KEY_STATE(RESTORE_ALT_STATE, keycode);

        if (KEY_STATE(ALT_REGISTERED, keycode)) {
            unregister_alt();
        } else if (!KEY_STATE(ALT_REGISTERED, keycode)) {
            register_alt();
        }
    }
}

void handle_key(
    uint16_t keycode,
    bool pressed, 
    uint16_t key,
    bool key_shift, 
    bool key_alt,
    uint16_t shifted_key,
    bool shifted_key_shift,
    bool shifted_key_alt
) {
    if (pressed) {
        if (PHYSICAL_SHIFT_DOWN) {
            SET_KEY_STATE(PRESSED_WITH_PHYSICAL_SHIFT, keycode);
            if (shifted_key_shift) { ensure_shift_down(keycode); } else { ensure_shift_up(keycode); }
            if (shifted_key_alt) { ensure_alt_down(keycode); } else { ensure_alt_up(keycode); }
            register_code(shifted_key);
        } else {
            CLEAR_KEY_STATE(PRESSED_WITH_PHYSICAL_SHIFT, keycode);
            if (key_shift) { ensure_shift_down(keycode); } else { ensure_shift_up(keycode); }
            if (key_alt) { ensure_alt_down(keycode); } else { ensure_alt_up(keycode); }
            register_code(key);
        }
    } else {
        if (KEY_STATE(PRESSED_WITH_PHYSICAL_SHIFT, keycode)) {
            unregister_code(shifted_key);
        } else {
            unregister_code(key);
        }
        restore_alt_state(keycode);
        restore_shift_state(keycode);
    }
}

#define HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, key, shift, alt) (handle_key(keycode, pressed, key, shift, alt, key, shift, alt))

void oneshot_mods_changed_user(uint8_t mods) {
    physical_lshift_down = mods & MOD_MASK_SHIFT;
    lshift_down = mods & MOD_MASK_SHIFT;
}

bool mapping_process_record(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;

#ifdef CONSOLE_ENABLE
    uprintf("kc: 0x%04X, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 

    switch (keycode) {
        case OSM(MOD_LSFT):
        case SFT_T(KC_S):
            physical_lshift_down = pressed;
            lshift_down = pressed;
            return true;
        case RSFT_T(KC_E):
            physical_rshift_down = pressed;
            rshift_down = pressed;
            return true;

        // 2 @
        case CKC_2:
            handle_key(keycode, pressed, KC_2, false, false, KC_Q, false, true);
            return false;
        // 3 #
        case CKC_3:
            handle_key(keycode, pressed, KC_3, false, false, KC_BSLS, false, true);
            return false;
        // 6 ^
        case CKC_6:
            if (pressed) {
                if (PHYSICAL_SHIFT_DOWN) {
                    unregister_shift();
                    tap_code(KC_GRV);
                    tap_code(KC_GRV);
                    register_shift();
                } else {
                    register_code(KC_6);
                }
            }
            return false;
        // 7 &
        case CKC_7:
            handle_key(keycode, pressed, KC_7, false, false, KC_6, true, false);
            return false;
        // 8 *
        case CKC_8:
            handle_key(keycode, pressed, KC_8, false, false, KC_RBRC, true, false);
            return false;
        // 9 (
        case CKC_9:
            handle_key(keycode, pressed, KC_9, false, false, KC_8, true, false);
            return false;
        // 0 )
        case CKC_0:
            handle_key(keycode, pressed, KC_0, false, false, KC_9, true, false);
            return false;
        // ' "
        case CKC_QUOT:
            handle_key(keycode, pressed, KC_BSLS, true, false, KC_2, true, false);
            return false;
        // , <
        case CKC_COMM:
            handle_key(keycode, pressed, KC_COMM, false, false, KC_NUBS, false, false);
            return false;
        // . >
        case CKC_DOT:
            handle_key(keycode, pressed, KC_DOT, false, false, KC_NUBS, true, false);
            return false;
        // Esc ~
        case CKC_GESC:
            handle_key(keycode, pressed, KC_ESC, false, false, KC_RBRC, true, false);
            return false;

        // @
        case CKC_AT:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_Q, false, true);
            return false;
        // #
        case CKC_HASH:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_BSLS, false, false);
            return false;
        // &
        case CKC_AMPR:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_6, true, false);
            return false;
        // *
        case CKC_ASTR:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_RBRC, true, false);
            return false;
        // _
        case CKC_UNDS:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_SLSH, true, false);
            return false;
        // =
        case CKC_EQL:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_0, true, false);
            return false;
        // +
        case CKC_PLUS:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_RBRC, false, false);
            return false;
        // /
        case CKC_SLSH:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_7, true, false);
            return false;
        // "\"
        case CKC_BSLS:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_MINS, false, true);
            return false;
        // |
        case CKC_PIPE:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_NUBS, false, true);
            return false;
        // "
        case CKC_DQUO:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_2, true, false);
            return false;
        // ~
        case CKC_TILD:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_RBRC, false, true);
            return false;
        // :
        case CKC_COLN:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_DOT, true, false);
            return false;
        // ;
        case CKC_SCLN:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_COMM, true, false);
            return false;
        // ?
        case CKC_QUES:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_MINS, true, false);
            return false;
        // (
        case CKC_LPRN:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_8, true, false);
            return false;
        // )
        case CKC_RPRN:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_9, true, false);
            return false;
        // [
        case CKC_LBRC:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_8, false, true);
            return false;
        // ]
        case CKC_RBRC:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_9, false, true);
            return false;
        // {
        case CKC_LCBR:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_7, false, true);
            return false;
        // }
        case CKC_RCBR:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_0, false, true);
            return false;
        // ß
        case CKC_SZ:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_MINS, false, false);
            return false;
        // €
        case CKC_EURO:
            HANDLE_KEY_IGNORE_SHIFT(keycode, pressed, KC_E, false, true);
            return false;

        // ^
        case CKC_CIRC:
            if (pressed) {
                if (PHYSICAL_SHIFT_DOWN) {
                    unregister_shift();
                }
                tap_code(KC_GRV);
                tap_code(KC_GRV);
                if (PHYSICAL_SHIFT_DOWN) {
                    register_shift();
                }
            }
            return false;
        // `
        case CKC_GRV:
            if (pressed) {
                if (!PHYSICAL_SHIFT_DOWN) {
                    register_shift();
                }
                tap_code(KC_EQL);
                tap_code(KC_EQL);
                if (!PHYSICAL_SHIFT_DOWN) {
                    unregister_shift();
                }
            }
            return false;

        default:
            if (pressed) {
                if (!PHYSICAL_SHIFT_DOWN && SHIFT_DOWN) {
                    unregister_shift();
                }
                if (alt_down) {
                    unregister_alt();
                }
            }
            return true;
    }
}

#endif // MAPPING_H