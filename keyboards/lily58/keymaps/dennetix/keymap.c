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
    /* COLEMAK
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * | ESC/~|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  `   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Caps |   A  |   R  |   S  |   F  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
    * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   |  GUI |ADJUST|LOWER | /Enter  /       \Space \  |RAISE |GAMING|QWERTY|
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
    [_COLEMAK] = LAYOUT(
    CKC_GESC, KC_1,     CKC_2,        CKC_3,        KC_4,         KC_5,                           CKC_6,      CKC_7,        CKC_8,        CKC_9,         CKC_0,    KC_BSPC,
    KC_TAB,   KC_Q,     LGUI_T(KC_W), KC_F,         KC_P,         KC_B,                           KC_J,       KC_L,         CKC_UMLU,     LGUI_T(CKC_Y), CKC_SCLN, CKC_GRV,
    KC_CAPS,  CKC_UMLA, LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,                           KC_M,       RCTL_T(KC_N), RSFT_T(KC_E), LALT_T(KC_I),  CKC_UMLO, CKC_QUOT,
    KC_LSFT,  CKC_Z,    KC_X,         KC_C,         KC_D,         KC_V,       CKC_LBRC, CKC_RBRC, KC_K,       KC_H,         CKC_COMM,     CKC_DOT,       CKC_SLSH, KC_RSFT,
                                      KC_LGUI,      MO(_ADJUST),   MO(_LOWER), KC_ENT,   KC_SPC,   MO(_RAISE), TG(_GAMING),  TG(_QWERTY)
    ),

    /* QWERTY
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * | ESC/~|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  `   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Caps |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   |  GUI |ADJUST|LOWER | /Enter  /       \Space \  |RAISE |GAMING|QWERTY|
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
    [_QWERTY] = LAYOUT(
    CKC_GESC, KC_1,     CKC_2,        CKC_3,        KC_4,         KC_5,                           CKC_6,      CKC_7,        CKC_8,        CKC_9,        CKC_0,    KC_BSPC,
    KC_TAB,   KC_Q,     LGUI_T(KC_W), KC_E,         KC_R,         KC_T,                           CKC_Y,      CKC_UMLU,     KC_I,         CKC_UMLO,     KC_P,     KC_GRV,
    KC_CAPS,  CKC_UMLA, LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,                           KC_H,       RCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), CKC_SCLN, CKC_QUOT,
    KC_LSFT,  CKC_Z,    KC_X,         KC_C,         KC_V,         KC_B,       CKC_LBRC, CKC_RBRC, KC_N,       KC_M,         CKC_COMM,     CKC_DOT,      CKC_SLSH, KC_RSFT,
                                      KC_LGUI,      MO(_ADJUST),   MO(_LOWER), KC_ENT,   KC_SPC,   MO(_RAISE), TG(_GAMING),  TG(_QWERTY)
    ),

    /* GAMING
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |      |      |      |      |      | Exit |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | LCtl |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|      |      |      |      |      |      |
    * |------+------+------+------+------+------|   H   |    |       |------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|      |      |      |      |      |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   |  GUI | LAlt |Space | /  N    /       \      \  |      |      |      |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
    [_GAMING] = LAYOUT(
    CKC_GESC, KC_1,  CKC_2, CKC_3,   KC_4,    KC_5,               GOFF, GOFF,        GOFF, GOFF, GOFF, GOFF,
    KC_TAB,   KC_Q,  KC_W,  KC_E,    KC_R,    KC_T,               GOFF, GOFF,        GOFF, GOFF, GOFF, GOFF,
    KC_LCTL,  KC_A,  KC_S,  KC_D,    KC_F,    KC_G,               GOFF, GOFF,        GOFF, GOFF, GOFF, GOFF,
    KC_LSFT,  CKC_Z, KC_X,  KC_C,    KC_V,    KC_B,   KC_H, GOFF, GOFF, GOFF,        GOFF, GOFF, GOFF, GOFF,
                            KC_LGUI, KC_LALT, KC_SPC, KC_N, GOFF, GOFF, TG(_GAMING), GOFF
    ),

    /* LOWER
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      | Prev | Play | Next |      |                    |      |PgDown|  Up  | PgUp |  _   | F11  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------.    ,-------|      | Left | Down |Right |  +   | F12  |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |  |   |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   |      |      |      | /       /       \      \ |       |      |      |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
    [_LOWER] = LAYOUT(
    _, KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6, KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_DEL,
    _, _,     KC_MPRV, KC_MPLY, KC_MNXT, _,           _,     KC_PGDN, KC_UP,   KC_PGUP,  CKC_UNDS, KC_F11,
    _, _,     _,       _,       _,       _,           _,     KC_LEFT, KC_DOWN, KC_RIGHT, CKC_PLUS, KC_F12,
    _, _,     _,       _,       _,       _,     _, _, _,     _,       _,       _,        CKC_PIPE, _,
                       _,       _,       _,     _, _, _,     _,       _
    ),

    /* RAISE
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      | Prev | Play | Next |      |                    |      | ScUp |  Up  |ScDown|  -   | F11  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |   ẞ  |   €  |      |      |-------.    ,-------|      | Left | Down |Right |  =   | F12  |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------|    |-------|      |LClick|      |RClick|  \   |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   |      |      |      | /       /       \      \  |      |      |      |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
    [_RAISE] = LAYOUT(
    _, KC_F1, KC_F2,   KC_F3,    KC_F4,  KC_F5,       KC_F6, KC_F7,       KC_F8,      KC_F9,         KC_F10,   KC_DEL,
    _, _,     KC_MPRV, KC_MPLY, KC_MNXT, _,           _,     KC_MS_WH_UP, KC_MS_UP,   KC_MS_WH_DOWN, CKC_MINS, KC_F11,
    _, _,     CKC_SZ,  CKC_EURO, _,      _,           _,     KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,   CKC_EQL,  KC_F12,
    _, _,     _,       _,        _,      _,     _, _, _,     KC_MS_BTN1,  _,          KC_MS_BTN2,    CKC_BSLS, _,
                       _,        _,      _,     _, _, _,     _,           _
    ),

    /* ADJUST
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |Reset |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   |      |      |      | /       /       \      \  |      |      |      |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
    [_ADJUST] = LAYOUT(
    QK_BOOT, _, _, _, _, _,       _, _, _, _, _, _,
    _,     _, _, _, _, _,       _, _, _, _, _, _,
    _,     _, _, _, _, _,       _, _, _, _, _, _,
    _,     _, _, _, _, _, _, _, _, _, _, _, _, _,
                 _, _, _, _, _, _, _, _
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

#ifdef OLED_ENABLE

bool caps = false;

bool led_update_user(led_t state) {
    caps = state.caps_lock;
    return false;
}

const char *read_logo(void);

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_0;
    }
    return OLED_ROTATION_180;
}

#define STATE_LOGO 1
#define STATE_GAMING 2
#define STATE_QWERTY 3
#define STATE_GAMING_QWERTY 4
uint8_t current_display_state = 0;
bool caps_drawn = false;

// 128x32
bool oled_task_user(void) {
    bool did_update = false;
    if (IS_LAYER_ON(_GAMING) && !IS_LAYER_ON(_QWERTY) && current_display_state != STATE_GAMING) {
        oled_clear();
        oled_set_cursor(8,2);
        oled_write("GAMING", false);
        current_display_state = STATE_GAMING;
        did_update = true;
    } else if (!IS_LAYER_ON(_GAMING) && IS_LAYER_ON(_QWERTY) && current_display_state != STATE_QWERTY) {
        oled_clear();
        oled_set_cursor(8,2);
        oled_write("QWERTY", false);
        current_display_state = STATE_QWERTY;
        did_update = true;
    } else if (IS_LAYER_ON(_GAMING) && IS_LAYER_ON(_QWERTY) && current_display_state != STATE_GAMING_QWERTY) {
        oled_clear();
        oled_set_cursor(8,1);
        oled_write("GAMING", false);
        oled_set_cursor(8,2);
        oled_write("QWERTY", false);
        current_display_state = STATE_GAMING_QWERTY;
        did_update = true;
    } else if (!IS_LAYER_ON(_GAMING) && !IS_LAYER_ON(_QWERTY) && current_display_state != STATE_LOGO) {
        oled_clear();
        oled_write(read_logo(), false);
        current_display_state = STATE_LOGO;
        did_update = true;
    }

    if (caps && (!caps_drawn || did_update)) {
        for (uint8_t x = 1; x < 128; x++) {
            oled_write_pixel(x, 1, true);
            oled_write_pixel(x, 31, true);
        }
        for (uint8_t y = 1; y < 32; y++) {
            oled_write_pixel(1, y, true);
            oled_write_pixel(127, y, true);
        }
        caps_drawn = true;
    } else if (!caps && caps_drawn) {
        for (uint8_t x = 1; x < 128; x++) {
            oled_write_pixel(x, 1, false);
            oled_write_pixel(x, 31, false);
        }
        for (uint8_t y = 1; y < 32; y++) {
            oled_write_pixel(1, y, false);
            oled_write_pixel(127, y, false);
        }
        caps_drawn = false;
    }
    
    return false;
}

#endif // OLED_ENABLE
