#include QMK_KEYBOARD_H

#include <string.h>

enum layer_number {
    _COLEMAK = 0,
    _QWERTY,
    _GAMING,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define _  KC_TRNS

// Correct ANSI keycode names for existing keycodes from the german layout
#define CKC_Y KC_Z
#define CKC_Z KC_Y
#define CKC_MINS KC_SLSH

// Implemented in process_record_user
enum Custom {
    CKC_GAMINGOFF_TRANS = SAFE_RANGE,

    CUSTOM_KEYS_START, // used to initialize an array for storing the state of all custom keys

    // ANSI keycodes for use with german layout
    CKC_EQL,
    CKC_LBRC,
    CKC_RBRC,
    CKC_BSLS,
    CKC_SCLN,
    CKC_QUOT,
    CKC_COMM,
    CKC_DOT,
    CKC_SLSH,
    CKC_GESC,

    // Shifted Symbols
    CKC_UNDS,
    CKC_PLUS,
    CKC_PIPE,
    CKC_GRV,

    // Numbers
    CKC_2,
    CKC_3,
    CKC_6,
    CKC_7,
    CKC_8,
    CKC_9,
    CKC_0,

    // Special german characters
    CKC_SZ,
    CKC_EURO,

    CUSTOM_KEYS_END,
};

#define GOFF CKC_GAMINGOFF_TRANS

// tap/hold Umlaute
#define CKC_UMLA MT(0, KC_A)
#define CKC_UMLO MT(0, KC_O)
#define CKC_UMLU MT(0, KC_U)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_ortho_5x15(
        CKC_GESC, KC_1,     CKC_2,        CKC_3,        KC_4,         KC_5,    KC_P7,    KC_P8,   KC_P9,    CKC_6,  CKC_7,        CKC_8,        CKC_9,         CKC_0,       KC_BSPC,
        KC_TAB,   KC_Q,     LGUI_T(KC_W), KC_F,         KC_P,         KC_B,    KC_P4,    KC_P5,   KC_P6,    KC_J,   KC_L,         CKC_UMLU,     LGUI_T(CKC_Y), CKC_SCLN,    CKC_GRV,
        KC_CAPS,  CKC_UMLA, LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,    KC_P1,    KC_P2,   KC_P3,    KC_M,   RCTL_T(KC_N), RSFT_T(KC_E), LALT_T(KC_I),  CKC_UMLO,    CKC_QUOT,
        KC_LSFT,  CKC_Z,    KC_X,         KC_C,         KC_D,         KC_V,    CKC_LBRC, KC_P0,   CKC_RBRC, KC_K,   KC_H,         CKC_COMM,     CKC_DOT,       CKC_SLSH,    KC_RSFT,
        KC_NUM,   KC_LCTL,  KC_LGUI,      KC_LALT,      MO(_LOWER),   KC_ENT,  KC_MPRV,  KC_MPLY, KC_MNXT,  KC_SPC, MO(_RAISE),   _,            _,             TG(_GAMING), TG(_QWERTY)
    ),

    [_QWERTY] = LAYOUT_ortho_5x15(
        CKC_GESC, KC_1,     CKC_2,        CKC_3,        KC_4,         KC_5,    KC_P7,    KC_P8,   KC_P9,    CKC_6,  CKC_7,        CKC_8,        CKC_9,         CKC_0,       KC_BSPC,
        KC_TAB,   KC_Q,     LGUI_T(KC_W), KC_E,         KC_R,         KC_T,    KC_P4,    KC_P5,   KC_P6,    CKC_Y,  CKC_UMLU,     KC_I,         CKC_UMLO,      KC_P,        CKC_GRV,
        KC_CAPS,  CKC_UMLA, LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,    KC_P1,    KC_P2,   KC_P3,    KC_H,   RCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L),  CKC_SCLN,    CKC_QUOT,
        KC_LSFT,  CKC_Z,    KC_X,         KC_C,         KC_V,         KC_B,    CKC_LBRC, KC_P0,   CKC_RBRC, KC_N,   KC_M,         CKC_COMM,     CKC_DOT,       CKC_SLSH,    KC_RSFT,
        KC_NUM,   KC_LCTL,  KC_LGUI,      KC_LALT,      MO(_LOWER),   KC_ENT,  KC_MPRV,  KC_MPLY, KC_MNXT,  KC_SPC, MO(_RAISE),   _,            _,             TG(_QWERTY), TG(_QWERTY)
    ),


    [_GAMING] = LAYOUT_ortho_5x15(
        CKC_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    GOFF, GOFF, GOFF, GOFF, GOFF,        GOFF,        GOFF,        GOFF,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    GOFF, GOFF, GOFF, GOFF, GOFF,        GOFF,        GOFF,        GOFF,
        KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    GOFF, GOFF, GOFF, GOFF, GOFF,        GOFF,        GOFF,        GOFF,
        KC_LSFT,  CKC_Z,   KC_X,    KC_C,    KC_V,   KC_B,    KC_N,    GOFF, GOFF, GOFF, GOFF, GOFF,        GOFF,        GOFF,        GOFF,
        KC_NUM,   KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC,  KC_SPC,  GOFF, GOFF, GOFF, GOFF, TG(_GAMING), TG(_GAMING), TG(_GAMING), TG(_GAMING)
    ),

    [_LOWER] = LAYOUT_ortho_5x15(
        _, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, PB_1, PB_2,  PB_3, KC_F6, KC_F7,       KC_F8,   KC_F9,    KC_F10,   KC_DEL,
        _, _,     _,     _,     _,     _,     PB_4, PB_5,  PB_6, _,     KC_PGDN,     KC_UP,   KC_PGUP,  CKC_UNDS, KC_F11,
        _, _,     _,     _,     _,     _,     PB_7, PB_8,  PB_9, _,     KC_LEFT,     KC_DOWN, KC_RIGHT, CKC_PLUS, KC_F12,
        _, _,     _,     _,     _,     _,     _,    PB_10, _,    _,     _,           _,       _,        CKC_PIPE, _,
        _, _,     _,     _,     _,     _,     _,    _,     _,    _,     MO(_ADJUST), _,       _,        _,        _
    ),

    [_RAISE] = LAYOUT_ortho_5x15(
        _, KC_F1, KC_F2,  KC_F3,    KC_F4,       KC_F5, PB_1, PB_2,  PB_3, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,   KC_DEL,
        _, _,     _,      _,        _,           _,     PB_4, PB_5,  PB_6, _,     _,     _,     _,     CKC_MINS, KC_F11,
        _, _,     CKC_SZ, CKC_EURO, _,           _,     PB_7, PB_8,  PB_9, _,     _,     _,     _,     CKC_EQL,  KC_F12,
        _, _,     _,      _,        _,           _,     _,    PB_10, _,    _,     _,     _,     _,     CKC_BSLS, _,
        _, _,     _,      _,        MO(_ADJUST), _,     _,    _,     _,    _,     _,     _,     _,     _,        _
    ),

    [_ADJUST] = LAYOUT_ortho_5x15(
        QK_BOOT, _, _, RGB_TOG, RGB_RMOD, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _, _, _,
        _,       _, _, _,       _,        _,       _,       _,       _,       _,       _,       _,       _, _, _,
        _,       _, _, _,       _,        _,       _,       _,       _,       _,       _,       _,       _, _, _,
        _,       _, _, _,       _,        _,       _,       _,       _,       _,       _,       _,       _, _, _,
        _,       _, _, _,       _,        _,       _,       _,       _,       _,       _,       _,       _, _, _
    )

};

// Custom keys
uint8_t* custom_key_state;

bool lshift_down = false;
bool rshift_down = false;

bool physical_lshift_down = false;
bool physical_rshift_down = false;

#define SHIFT_DOWN ( lshift_down || rshift_down)
#define PHYSICAL_SHIFT_DOWN (physical_lshift_down || physical_rshift_down)

#define KEY_STATE(x) custom_key_state[x - CUSTOM_KEYS_START - 1]

#define WAS_KEY_PRESSED_WITH_PHYSICAL_SHIFT(x) (KEY_STATE(x) & 0x01)
#define SET_WAS_KEY_PRESSED_WITH_PHYSICAL_SHIFT(x) (KEY_STATE(x) = KEY_STATE(x) | 0x01)
#define CLEAR_WAS_KEY_PRESSED_WITH_PHYSICAL_SHIFT(x) (KEY_STATE(x) = KEY_STATE(x) & ~0x01)

#define SHOULD_SHIFT_STATE_BE_RESTORED(x) (KEY_STATE(x) & 0x02)
#define SET_SHOULD_SHIFT_STATE_BE_RESTORED(x) (KEY_STATE(x) = KEY_STATE(x) | 0x02)
#define CLEAR_SHOULD_SHIFT_STATE_BE_RESTORED(x) (KEY_STATE(x) = KEY_STATE(x) & ~0x02)

#define RESTORE_SHIFT_REGISTER(x) (KEY_STATE(x) & 0x04)
#define SET_RESTORE_SHIFT_REGISTER(x) (KEY_STATE(x) = KEY_STATE(x) | 0x04)
#define CLEAR_RESTORE_SHIFT_REGISTER(x) (KEY_STATE(x) = KEY_STATE(x) & ~0x04)

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
    if (!SHIFT_DOWN) {
        register_shift();
        SET_RESTORE_SHIFT_REGISTER(keycode);
        SET_SHOULD_SHIFT_STATE_BE_RESTORED(keycode);
    } else {
        CLEAR_SHOULD_SHIFT_STATE_BE_RESTORED(keycode);
    }
}

void ensure_shift_up(uint16_t keycode) {
    if (SHIFT_DOWN) {
        unregister_shift();
        CLEAR_RESTORE_SHIFT_REGISTER(keycode);
        SET_SHOULD_SHIFT_STATE_BE_RESTORED(keycode);
    } else {
        CLEAR_SHOULD_SHIFT_STATE_BE_RESTORED(keycode);
    }
}

void restore_shift_state(uint16_t keycode) {
    if (SHOULD_SHIFT_STATE_BE_RESTORED(keycode)) {  
        if (RESTORE_SHIFT_REGISTER(keycode) && !PHYSICAL_SHIFT_DOWN) {
            unregister_shift();
        } else if (!RESTORE_SHIFT_REGISTER(keycode) && PHYSICAL_SHIFT_DOWN) {
            register_shift();
        }
        CLEAR_SHOULD_SHIFT_STATE_BE_RESTORED(keycode);
    }
}

void handle_key(uint16_t keycode, bool pressed, uint16_t shiftedKey, uint16_t key, bool shiftedShift, bool shift, bool shiftedAlt, bool alt) {
    if (pressed) {
        if (PHYSICAL_SHIFT_DOWN) {
            SET_WAS_KEY_PRESSED_WITH_PHYSICAL_SHIFT(keycode);
            if (shiftedShift) {
                ensure_shift_down(keycode);
            } else {
                ensure_shift_up(keycode);
            }
            if (shiftedAlt) {
                register_code(KC_RALT);
            }
            register_code(shiftedKey);
        } else {
            CLEAR_WAS_KEY_PRESSED_WITH_PHYSICAL_SHIFT(keycode);
            if (shift) {
                ensure_shift_down(keycode);
            } else {
                ensure_shift_up(keycode);
            }
            if (alt) {
                register_code(KC_RALT);
            }
            register_code(key);
        }
    } else {
        if (WAS_KEY_PRESSED_WITH_PHYSICAL_SHIFT(keycode)) {
            unregister_code(shiftedKey);
            if (shiftedAlt) {
                unregister_code(KC_RALT);
            }
        } else {
            unregister_code(key);
            if (alt) {
                unregister_code(KC_RALT);
            }
        }
        restore_shift_state(keycode);
    }
}

void keyboard_post_init_user(void) {
    uint16_t size = (CUSTOM_KEYS_END - CUSTOM_KEYS_START - 1) * sizeof(uint8_t);
    custom_key_state = (uint8_t*) malloc(size);
    memset(custom_key_state, 0, size);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_LSFT:
        physical_lshift_down = record->event.pressed;
        lshift_down = record->event.pressed;
        return true;
    case KC_RSFT:
        physical_rshift_down = record->event.pressed;
        rshift_down = record->event.pressed;
        return true;

    case CKC_GAMINGOFF_TRANS:
        uint32_t state = (layer_state | default_layer_state);
        uint8_t next_active_layer = biton32(state ^ (1Ul<<biton32(state)));
        uint16_t fallthrough = keymap_key_to_keycode(next_active_layer, record->event.key);
        if (record->event.pressed) {
            layer_off(_GAMING);
            register_code(fallthrough);
        } else {
            unregister_code(fallthrough);
        }
        break;
    
    // ANSI keycodes for use with german layout

    // + =
    case CKC_EQL:
        handle_key(keycode, record->event.pressed, KC_RBRC, KC_0, false, true, false, false);
        break;
    // { [
    case CKC_LBRC:
        handle_key(keycode, record->event.pressed, KC_7, KC_8, false, false, true, true);
        break;
    // } ]
    case CKC_RBRC:
        handle_key(keycode, record->event.pressed, KC_0, KC_9, false, false, true, true);
        break;
    // | '\'
    case CKC_BSLS:
        handle_key(keycode, record->event.pressed, KC_NUBS, KC_MINS, false, false, true, true);
        break;
    // : ;
    case CKC_SCLN:
        handle_key(keycode, record->event.pressed, KC_DOT, KC_COMM, true, true, false, false);
        break;
    // " '
    case CKC_QUOT:
        handle_key(keycode, record->event.pressed, KC_2, KC_BSLS, true, true, false, false);
        break;
    // < ,
    case CKC_COMM:
        handle_key(keycode, record->event.pressed, KC_NUBS, KC_COMM, false, false, false, false);
        break;
    // > .
    case CKC_DOT:
        handle_key(keycode, record->event.pressed, KC_NUBS, KC_DOT, true, false, false, false);
        break;
    // ? /
    case CKC_SLSH:
        handle_key(keycode, record->event.pressed, KC_MINS, KC_7, true, true, false, false);
        break;
    // ~ Esc
    case CKC_GESC:
        handle_key(keycode, record->event.pressed, KC_RBRC, KC_ESC, false, false, true, false);
        break;


    // Shifted Symbols

    case CKC_UNDS:
        handle_key(keycode, record->event.pressed, KC_SLSH, KC_SLSH, true, true, false, false);
        break;
    case CKC_PLUS:
        handle_key(keycode, record->event.pressed, KC_RBRC, KC_RBRC, false, false, false, false);
        break;
    case CKC_PIPE:
        handle_key(keycode, record->event.pressed, KC_NUBS, KC_NUBS, false, false, true, true);
        break;
    case CKC_GRV:
        if (record->event.pressed) {
            if (!PHYSICAL_SHIFT_DOWN) {
                register_shift();
            }
            tap_code(KC_EQL);
            tap_code(KC_EQL);
            if (!PHYSICAL_SHIFT_DOWN) {
                unregister_shift();
            }
        }
        break;

    // Numbers

    case CKC_2:
        handle_key(keycode, record->event.pressed, KC_Q, KC_2, false, false, true, false);
        break;
    case CKC_3:
        handle_key(keycode, record->event.pressed, KC_BSLS, KC_3, false, false, false, false);
        break;
    case CKC_6:
        if (record->event.pressed) {
            if (PHYSICAL_SHIFT_DOWN) {
                unregister_shift();
                tap_code(KC_GRV);
                tap_code(KC_GRV);
                register_shift();
            } else { 
                register_code(KC_6);
            }
        } else {
            unregister_code(KC_6);
        }
        break;
    case CKC_7:
        handle_key(keycode, record->event.pressed, KC_6, KC_7, true, false, false, false);
        break;
    case CKC_8:
        handle_key(keycode, record->event.pressed, KC_RBRC, KC_8, true, false, false, false);
        break;
    case CKC_9:
        handle_key(keycode, record->event.pressed, KC_8, KC_9, true, false, false, false);
        break;
    case CKC_0:
        handle_key(keycode, record->event.pressed, KC_9, KC_0, true, false, false, false);
        break;


    // Special german characters
    case CKC_SZ:
        if (record->event.pressed) {
            register_code(KC_MINS);
        } else {
            unregister_code(KC_MINS);
        }
        break;
    case CKC_EURO:
        handle_key(keycode, record->event.pressed, KC_E, KC_E, false, false, true, true);
        break;

    // Umlaute
    case CKC_UMLA:
        if (record->tap.count == 0 && record->event.pressed) {
            tap_code(KC_QUOT);
            break;
        }
        return true;
    case CKC_UMLO:
        if (record->tap.count == 0 && record->event.pressed) {
            tap_code(KC_SCLN);
            break;
        }
        return true;
    case CKC_UMLU:
        if (record->tap.count == 0 && record->event.pressed) {
            tap_code(KC_LBRC);
            break;
        }
        return true;

    default:
        if (record->event.pressed && !PHYSICAL_SHIFT_DOWN && SHIFT_DOWN) {
            unregister_shift();
        }
        return true;
    }

    return false;
}