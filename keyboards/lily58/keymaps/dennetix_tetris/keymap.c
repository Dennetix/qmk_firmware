#include QMK_KEYBOARD_H

#include <string.h>

enum layer_number {
    _COLEMAK = 0,
    _QWERTY,
    _GAMING,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define _ KC_TRNS

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

    // Tetris navigation keys
    CKC_TETRIS_LEFT,
    CKC_TETRIS_RIGHT,
    CKC_TETRIS_ROTATE,
    CKC_TETRIS_DROP
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
    * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |      |      |Rotate|      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | LCtl |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|      | Left | Drop |Right |      |      |
    * |------+------+------+------+------+------| Exit  |    |       |------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|      |      |      |      |      |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   | LAlt | LGUI |Space | /  N    /       \      \  |RAISE | RCtl | RAlt |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
    [_GAMING] = LAYOUT(
    CKC_GESC,   KC_1,   CKC_2,    CKC_3,    KC_4,    KC_5,                     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_NO,    KC_NO,    CKC_TETRIS_ROTATE,    KC_NO,    KC_NO,    KC_NO,
    KC_LCTL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_NO,    CKC_TETRIS_LEFT,    CKC_TETRIS_DROP,    CKC_TETRIS_RIGHT,    KC_NO, KC_NO,
    KC_LSFT,  CKC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_H,  KC_NO,  KC_NO,    KC_NO,    KC_NO, KC_NO,  KC_NO,  KC_NO,
                            KC_LALT, KC_LGUI, KC_SPC, KC_N, KC_NO, KC_NO, TG(_GAMING), KC_NO
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
    * |      |      | Prev | Play | Next |      |                    |      |      |      |      |  -   | F11  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |   ẞ  |   €  |      |      |-------.    ,-------|      |      |      |      |  =   | F12  |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |  \   |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   |      |      |      | /       /       \      \  |      |      |      |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
    [_RAISE] = LAYOUT(
    _, KC_F1, KC_F2,   KC_F3,    KC_F4,  KC_F5,       KC_F6, KC_F7,    KC_F8, KC_F9,    KC_F10, KC_DEL,
    _, _,     KC_MPRV, KC_MPLY, KC_MNXT, _,           _,     _,     _, _,     CKC_MINS, KC_F11,
    _, _,     CKC_SZ,  CKC_EURO, _,      _,           _,     _,     _, _,     CKC_EQL,  KC_F12,
    _, _,     _,       _,        _,      _,     _, _, _,     _,     _, _,     CKC_BSLS, _,
                       _,        _,      _,     _, _, _,     _,     _
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

// Tetris key states
bool tetris_left_down = false;
bool tetris_right_down = false;
bool tetris_rotate_down = false;
bool tetris_drop_down = false;

bool tetris_left_pressed = false;
bool tetris_right_pressed = false;
bool tetris_rotate_pressed = false;
bool tetris_drop_pressed = false;

bool tetris_left_held = false;
bool tetris_right_held = false;
bool tetris_drop_held = false;

uint16_t tetris_left_timer = 0;
uint16_t tetris_right_timer = 0;
uint16_t tetris_drop_timer = 0;

#define SHIFT_DOWN (lshift_down || rshift_down)
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

    // Tetris navigation keys

    case CKC_TETRIS_LEFT:
        tetris_left_down = record->event.pressed;
        if (record->event.pressed) {
            tetris_left_pressed = true;
        } else {
            tetris_left_held = false;
        }
        tetris_left_timer = timer_read();
        break;
    case CKC_TETRIS_RIGHT:
        tetris_right_down = record->event.pressed;
        if (record->event.pressed) {
            tetris_right_pressed = true;
        } else {
            tetris_right_held = false;
        }
        tetris_right_timer = timer_read();
        break;
    case CKC_TETRIS_ROTATE:
        tetris_rotate_down = record->event.pressed;
        if (record->event.pressed) {
            tetris_rotate_pressed = true;
        }
        break;
    case CKC_TETRIS_DROP:
        tetris_drop_down = record->event.pressed;
        if (record->event.pressed) {
            tetris_drop_pressed = true;
        } else {
            tetris_drop_held = false;
        }
        tetris_drop_timer = timer_read();
        break;

    default:
        if (record->event.pressed && !PHYSICAL_SHIFT_DOWN && SHIFT_DOWN) {
            unregister_shift();
        }
        return true;
    }

    return false;
}

#ifdef OLED_ENABLE

const char *read_logo(void);

#define TETRIS_INTERVAL_MAX 48 // About the same speed as the staarting speed on tetris.com
#define TETRIS_INTERVAL_MIN 36 // Shortest interval that still leaves enough time for the display to update

#define TETRIS_MENU_INTERVAL 5000
#define TETRIS_GAME_OVER_INTERVAL 300
#define TETRIS_GAME_OVER_TIMEOUT 20000

#define TETRIS_BUTTON_HOLD 150

#define TETRIS_DIGIT_SEGMENT_LENGTH 2
#define TETRIS_NUMBER_SPACING 1

#define TETRIS_CELL_BLOCK_SIZE 2
#define TETRIS_CELL_SPACING 1
#define TETRIS_CELL_SIZE (TETRIS_CELL_BLOCK_SIZE + TETRIS_CELL_SPACING)
#define TETRIS_FIELD_WIDTH 10
#define TETRIS_FIELD_HEIGHT 20

#define TETRIS_FIELD_START_X 1
#define TETRIS_FIELD_START_Y 29
#define TETRIS_FIELD_END_X (TETRIS_FIELD_START_X + TETRIS_CELL_SIZE * TETRIS_FIELD_WIDTH - 1)
#define TETRIS_FIELD_END_Y (TETRIS_FIELD_START_Y + TETRIS_CELL_SIZE * TETRIS_FIELD_HEIGHT - 1)

const uint8_t piece_o[4] = {
    1, 1,
    1, 1
};

const uint8_t piece_s[9] = {
    0, 1, 1,
    1, 1, 0,
    0, 0, 0
};

const uint8_t piece_z[9] = {
    1, 1, 0,
    0, 1, 1,
    0, 0, 0
};

const uint8_t piece_t[9] = {
    0, 1, 0,
    1, 1, 1,
    0, 0, 0
};

const uint8_t piece_l[9] = {
    0, 0, 1,
    1, 1, 1,
    0, 0, 0
};

const uint8_t piece_j[9] = {
    1, 0, 0,
    1, 1, 1,
    0, 0, 0
};

const uint8_t piece_i[16] = {
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0
};

typedef struct Piece {
    const uint8_t* piece;
    uint8_t size:4;
} Piece;

enum TetrisState {
    DISABLED = 0,
    MENU,
    GAME_OVER,
    PLAYING,
};

uint8_t tetris_state = DISABLED;

uint32_t tetris_score;
bool tetris_score_dirty;
uint16_t tetris_lines;
bool tetris_lines_dirty;

uint16_t tetris_timer;
uint16_t tetris_gravity_timer;

uint8_t tetris_field[TETRIS_FIELD_WIDTH * TETRIS_FIELD_HEIGHT];
bool tetris_field_dirty;

Piece current_piece;
int8_t current_x;
int8_t current_y;
int8_t ghost_y;
uint8_t current_rot;
bool current_should_lock;
uint16_t current_lock_timer;

Piece next_piece;

bool animating;
uint8_t animation_frame;
int8_t animate_lines[4];

uint8_t pieces_bag;

uint8_t get_random(uint8_t max) {
    return (TCNT0 + TCNT1 + TCNT3 + TCNT4) % (max + 1);
}

// As described in https://tetris.fandom.com/wiki/Random_Generator
Piece get_random_piece(void) {
    if (pieces_bag >= 0b1111111) { // If all pieces are used, reset
        pieces_bag = 0;
    }

    uint8_t piece;
    do {
        piece = get_random(6);
    } while (pieces_bag & (1 << piece));
    pieces_bag = pieces_bag | (1 << piece);

    switch (piece) {
        case 0: return (Piece) { piece_o, 2 };
        case 1: return (Piece) { piece_s, 3 };
        case 2: return (Piece) { piece_z, 3 };
        case 3: return (Piece) { piece_t, 3 };
        case 4: return (Piece) { piece_l, 3 };
        case 5: return (Piece) { piece_j, 3 };
        default: return (Piece) { piece_i, 4 };
    }
}

uint8_t get_piece_rotated_at(const Piece* piece, uint8_t x, uint8_t y, uint8_t rotation) {
    switch (rotation % 4) {
        case 0: return piece->piece[y * piece->size + x];
        case 1: return piece->piece[(piece->size * piece->size - piece->size) + y - (x * piece->size)];
        case 2: return piece->piece[(piece->size * piece->size - 1) - (y * piece->size) - x];
        default: return piece->piece[(piece->size - 1) - y + (x * piece->size)];
    }
}

uint8_t get_field_at(int8_t x, int8_t y) {
    if (x >= 0 && x < TETRIS_FIELD_WIDTH && y < TETRIS_FIELD_HEIGHT) {
        if (y < 0) {
            return 0;
        }
        return tetris_field[y * TETRIS_FIELD_WIDTH + x];
    }
    return 1;
}

uint8_t get_interval(void) {
    switch (tetris_lines / 10 + 1) {
        case 1: 
            return TETRIS_INTERVAL_MAX;
        case 2:
        case 3: 
            return (TETRIS_INTERVAL_MAX * 2 + TETRIS_INTERVAL_MIN) / 3;
        case 4: 
            return (TETRIS_INTERVAL_MAX + TETRIS_INTERVAL_MIN * 3) / 4;
        default:
            return TETRIS_INTERVAL_MIN;
    }
}

// As described in https://tetris.fandom.com/wiki/Tetris_Worlds#Gravity
uint16_t get_gravity_interval(void) {
    switch (tetris_lines / 10 + 1) {
        case 1: return 1000;
        case 2: return 793;
        case 3: return 617;
        case 4: return 472;
        case 5: return 355;
        case 6: return 262;
        case 7: return 189;
        case 8: return 134;
        case 9: return 93;
        case 10: return 64;
        case 11: return 42;
        default: return TETRIS_INTERVAL_MIN;
    }
}

void render_digit(uint8_t x, uint8_t y, uint8_t d) {
    for (uint8_t i = 0; i < TETRIS_DIGIT_SEGMENT_LENGTH; i++) {
        // Top segment
        oled_write_pixel(x + i + 1, y, d != 1 && d != 4);
        // Middle segment
        oled_write_pixel(x + i + 1, y + TETRIS_DIGIT_SEGMENT_LENGTH + 1, d != 0 && d != 1 && d != 7);
        // Bottom segment
        oled_write_pixel(x + i + 1, y + (TETRIS_DIGIT_SEGMENT_LENGTH + 1) * 2, d != 1 && d != 4 && d != 7);

        // Top left segment
        oled_write_pixel(x, y + i + 1, d != 1 && d != 2 && d != 3 && d != 7);
        // Bottom left segment
        oled_write_pixel(x, y + i + TETRIS_DIGIT_SEGMENT_LENGTH + 2, d == 0 || d == 2 || d == 6 || d == 8);
    
        // Top right segment
        oled_write_pixel(x + TETRIS_DIGIT_SEGMENT_LENGTH + 1, y + i + 1, d != 5 && d != 6);
        // Bottom right segment
        oled_write_pixel(x + TETRIS_DIGIT_SEGMENT_LENGTH + 1, y + i + TETRIS_DIGIT_SEGMENT_LENGTH + 2, d != 2);
    }
}

void render_number(uint8_t x, uint8_t y, uint16_t num) {
    if (num == 0) {
        render_digit(x, y, 0);
        return;
    }

    int8_t buffer[5] = { -1, -1, -1, -1, -1 };
    for (uint8_t i = 0; num != 0; i++) {
        buffer[i] = num % 10;
        num /= 10;
    }
    for (int8_t i = 4; i >= 0; i--) {
        if (buffer[i] > -1) {
            render_digit(x, y, buffer[i]);
            x += 2 + TETRIS_DIGIT_SEGMENT_LENGTH + TETRIS_NUMBER_SPACING;
        }
    }
}

void render_tetris_cell(int8_t x, int8_t y, bool on) {
    x = TETRIS_FIELD_START_X + x * TETRIS_CELL_SIZE + 1;
    y = TETRIS_FIELD_START_Y + y * TETRIS_CELL_SIZE + 1;
    for (uint8_t sx = 0; sx < TETRIS_CELL_BLOCK_SIZE; sx++) {
        for (uint8_t sy = 0; sy < TETRIS_CELL_BLOCK_SIZE; sy++) {
            oled_write_pixel(x + sx, y + sy, on);
        }
    }
}

void render_tetris_cell_dot(int8_t x, int8_t y, bool on) {
    x = TETRIS_FIELD_START_X + x * TETRIS_CELL_SIZE + 1;
    y = TETRIS_FIELD_START_Y + y * TETRIS_CELL_SIZE + 1;
    oled_write_pixel(x, y, on);
    oled_write_pixel(x + TETRIS_CELL_SIZE / 2, y + TETRIS_CELL_SIZE / 2, on);
}

void render_tetris_piece(const Piece* piece, int8_t x, int8_t y, uint8_t rotation, bool fill, bool render_above_field, bool first_row_only, bool on) {
    for (uint8_t px = 0; px < piece->size; px++) {
        for (uint8_t py = 0; py < (first_row_only ? 1 : piece->size); py++) {
            if (get_piece_rotated_at(piece, px, py, rotation) != 0 && (render_above_field || y + py >= 0)) {
                fill ? render_tetris_cell(x + px, y + py, on) : render_tetris_cell_dot(x + px, y + py, on);
            }
        }
    }
}

void render_tetris_outlines(void) {
    for (uint8_t x = TETRIS_FIELD_START_X; x < TETRIS_FIELD_END_X + 1; x++) {
        oled_write_pixel(x, 0, true);
        oled_write_pixel(x, TETRIS_FIELD_START_Y - 1, true);
        oled_write_pixel(x, TETRIS_FIELD_END_Y + 2, true);
    }
    for (uint8_t y = 0; y < TETRIS_FIELD_END_Y + 3; y++) {
        oled_write_pixel(TETRIS_FIELD_START_X - 1, y, true);
        oled_write_pixel(TETRIS_FIELD_END_X + 1, y, true);
    }

    for (uint8_t x = TETRIS_FIELD_END_X - TETRIS_CELL_SIZE * 6 + 1; x < TETRIS_FIELD_END_X + 1; x++) {
        oled_write_pixel(x, TETRIS_FIELD_START_Y - TETRIS_CELL_SIZE * 4 + 2, true);
    }
    for (uint8_t y = TETRIS_FIELD_START_Y - TETRIS_CELL_SIZE * 4 + 3; y < TETRIS_FIELD_START_Y; y++) {
        oled_write_pixel(TETRIS_FIELD_END_X - TETRIS_CELL_SIZE * 6 + 1, y, true);
    }
}

bool does_piece_fit(const Piece* piece, int8_t x, int8_t y, uint8_t rotation) {
    for (uint8_t px = 0; px < piece->size; px++) {
        for (uint8_t py = 0; py < piece->size; py++) {
            if (get_piece_rotated_at(piece, px, py, rotation) && get_field_at(x + px, y + py)) {
                return false;
            }
        }
    }
    return true;
}

void switch_to_next_piece(void) {
    tetris_gravity_timer = timer_read();

    current_piece = next_piece;
    current_x = TETRIS_FIELD_WIDTH / 2 - (current_piece.size != 3 ? current_piece.size / 2 : 2);
    current_y = -2;
    ghost_y = -6;
    current_rot = 0;
    current_should_lock = false;
    current_lock_timer = timer_read();

    render_tetris_piece(&next_piece, TETRIS_FIELD_WIDTH - next_piece.size - (next_piece.size == 2 ? 2 : 1), -3, 0, true, true, false, false);
    next_piece = get_random_piece();
    render_tetris_piece(&next_piece, TETRIS_FIELD_WIDTH - next_piece.size - (next_piece.size == 2 ? 2 : 1), -3, 0, true, true, false, true);

    // Try to move piece down two times
    for (uint8_t i = 0; i < 2; i++) {
        if (does_piece_fit(&current_piece, current_x, current_y + 1, current_rot)) {
            current_y++;
        }
    }

    // If piece couldn't move down at least once, game over
    if (current_y == -2) {
        tetris_state = GAME_OVER;
        tetris_gravity_timer = timer_read();
        current_lock_timer = timer_read() - TETRIS_GAME_OVER_INTERVAL;
    }
}

void rotate_current_piece(void) {
    // FIXME: Rotate as described in https://tetris.fandom.com/wiki/SRS#Wall_Kicks
    // Current (wrong) rotation system tries to move the piece up and left or right to find the closest fitting position
    uint8_t counter = 0;
    int8_t x_offset = 0;
    int8_t y_offset = 0;
    while (!does_piece_fit(&current_piece, current_x + x_offset, current_y + y_offset, current_rot + 1) && counter < 15) {
        counter++;
        switch (counter % 5) {
            case 1:
                x_offset = -1;
                break;
            case 2:
                x_offset = 1;
                break;
            case 3:
                x_offset = -2;
                break;
            case 4:
                x_offset = 2;
                break;
            default:
                x_offset = 0;
                y_offset--;
                break;
        }
    }
    if (counter < 15) {
        current_rot++;
        current_x += x_offset;
        current_y += y_offset;
    }
}

void lock_current_piece(void) {
    tetris_field_dirty = true;

    uint8_t lines_count = 0;
    for (uint8_t py = 0; py < current_piece.size; py++) {
        if (current_y + py >= 0 && current_y + py < TETRIS_FIELD_HEIGHT) {
            // Write one line of the piece to the field
            for (uint8_t px = 0; px < current_piece.size; px++) {
                if (get_piece_rotated_at(&current_piece, px, py, current_rot)) {
                    tetris_field[(current_y + py) * TETRIS_FIELD_WIDTH + (current_x + px)] = 1;
                }
            }

            // Check if the line is completed and if it is, save the position for animation
            bool line = true;
            for (uint8_t fx = 0; fx < TETRIS_FIELD_WIDTH; fx++) {
                if (!get_field_at(fx, current_y + py)) {
                    line = false;
                    break;
                }
            }
            if (line) {
                lines_count++;
                tetris_lines++;
                tetris_score_dirty = true;
                tetris_lines_dirty = true;
                animating = true;
                animation_frame = 0;
                animate_lines[py] = current_y + py;
            }
        }
    }

    switch (lines_count) {
        case 1:
            tetris_score += 100 * (tetris_lines / 10 + 1);
            break;
        case 2: 
            tetris_score += 300 * (tetris_lines / 10 + 1);
            break;
        case 3:
            tetris_score += 500 * (tetris_lines / 10 + 1);
            break;
        case 4:
            tetris_score += 800 * (tetris_lines / 10 + 1);
            break;
    }
}

void clear_pieces(void) {
    render_tetris_piece(&current_piece, current_x, current_y, current_rot, true, false, false, false);
    render_tetris_piece(&current_piece, current_x, ghost_y, current_rot, false, false, false, false);
}

void tetris_render(void) {
    if (tetris_score_dirty) {
        tetris_score_dirty = false;
        render_number(2, 2, tetris_score);
    }
    if (tetris_lines_dirty) {
        tetris_lines_dirty = false;
        render_number(2, 11, tetris_lines);
        render_number(2, 20, tetris_lines / 10 + 1);
    }

    if (animating) {
        tetris_field_dirty = true;
        if (animation_frame < TETRIS_FIELD_WIDTH) {
            // Remove one vertical line of all horizontal full lines each frame
            for (uint8_t i = 0; i < 4; i++) {
                if (animate_lines[i] > -1) {
                    tetris_field[animate_lines[i] * TETRIS_FIELD_WIDTH + animation_frame] = 0;
                }
            }
        } else {
            for (uint8_t i = 0; i < 4; i++) {
                if (animate_lines[i] > -1) {
                    wait_ms(35);
                    memmove(tetris_field + TETRIS_FIELD_WIDTH, tetris_field, animate_lines[i] * TETRIS_FIELD_WIDTH); // Move all lines above animate_lines[i] down by one
                    memset(tetris_field, 0, TETRIS_FIELD_WIDTH); // Remove top line
                    animate_lines[i] = -1;
                    break;
                }
                if (i >= 3) { // All lines moved, end animation
                    animating = false;
                    switch_to_next_piece();
                }
            }
        }
        animation_frame++;
    } else {
        // Render the current piece and its ghost only when not animating
        ghost_y = current_y;
        while (does_piece_fit(&current_piece, current_x, ghost_y + 1, current_rot)) {
            ghost_y++;
        }
        render_tetris_piece(&current_piece, current_x, current_y, current_rot, true, false, false, true);
        render_tetris_piece(&current_piece, current_x, ghost_y, current_rot, false, false, false, true);
    }

    // Render the field
    if (tetris_field_dirty) {
        for (uint8_t fx = 0; fx < TETRIS_FIELD_WIDTH; fx++) {
            for (uint8_t fy = 0; fy < TETRIS_FIELD_HEIGHT; fy++) {
                render_tetris_cell(fx, fy, get_field_at(fx, fy));
            }
        }
        tetris_field_dirty = false;
    }
}

void tetris_gameloop(void) {
    if ((tetris_left_pressed || tetris_left_held) && does_piece_fit(&current_piece, current_x - 1, current_y, current_rot)) {
        current_x--;
    }
    if ((tetris_right_pressed || tetris_right_held) && does_piece_fit(&current_piece, current_x + 1, current_y, current_rot)) {
        current_x++;
    }
    if (tetris_rotate_pressed) {
        rotate_current_piece();
    }
    if (current_should_lock) {
        // FIXME: Spamming the rotate button on the ground prevents the pieces (except o-piece) from locking
        if (does_piece_fit(&current_piece, current_x, current_y + 1, current_rot)) {
            current_should_lock = false;
        } else if (timer_elapsed(current_lock_timer) > 500) {
            current_should_lock = false;
            lock_current_piece(); 
            if (!animating) {
                switch_to_next_piece();
            }
        }
    } else {
        if ((tetris_drop_pressed || tetris_drop_held || timer_elapsed(tetris_gravity_timer) > get_gravity_interval()) &&
            !does_piece_fit(&current_piece, current_x, current_y + 1, current_rot)) {
            current_should_lock = true;
            current_lock_timer = timer_read();
            tetris_gravity_timer = timer_read();
        } else if (timer_elapsed(tetris_gravity_timer) > get_gravity_interval()) {
            current_y++;
            tetris_gravity_timer = timer_read();
            if (!does_piece_fit(&current_piece, current_x, current_y + 1, current_rot)) {
                current_should_lock = true;
                current_lock_timer = timer_read();
            }
        } else if (tetris_drop_pressed || tetris_drop_held) {
            current_y++;
            tetris_score++;
            tetris_score_dirty = true;
        } 
    }
}

void init_tetris(void) {
    oled_clear();

    tetris_score = 0;
    tetris_score_dirty = true;
    tetris_lines = 0;
    tetris_lines_dirty = true; 

    tetris_timer = timer_read();
    tetris_gravity_timer = timer_read();

    memset(tetris_field, 0, sizeof(tetris_field));
    tetris_field_dirty = true;

    pieces_bag = 0;

    next_piece = get_random_piece();
    switch_to_next_piece();

    animating = false;
    animation_frame = 0;
    memset(animate_lines, -1, sizeof(animate_lines));

    render_tetris_outlines();
}

void update_tetris(void) {
    if (tetris_left_down && timer_elapsed(tetris_left_timer) >= TETRIS_BUTTON_HOLD) {
        tetris_left_held = true;
    }
    if (tetris_right_down && timer_elapsed(tetris_right_timer) >= TETRIS_BUTTON_HOLD) {
        tetris_right_held = true;
    }
    if (tetris_drop_down && timer_elapsed(tetris_drop_timer) >= TETRIS_BUTTON_HOLD) {
        tetris_drop_held = true;
    }

    if (timer_elapsed(tetris_timer) >= (animating ? TETRIS_INTERVAL_MIN : get_interval())) {
        if (tetris_state == PLAYING) {
            clear_pieces();
            if (!animating) {
                tetris_gameloop();
            }
            tetris_render();
        } else if (tetris_state == GAME_OVER) {
            if (tetris_left_pressed || tetris_right_pressed || tetris_rotate_pressed || tetris_drop_pressed ||
                timer_elapsed(tetris_gravity_timer) > TETRIS_GAME_OVER_TIMEOUT) {
                tetris_state = MENU;
                tetris_gravity_timer = timer_read() - TETRIS_MENU_INTERVAL;
            }

            if (timer_elapsed(current_lock_timer) > TETRIS_GAME_OVER_INTERVAL) {
                oled_set_cursor(1, 6);
                oled_write("GAME", false);        
                oled_set_cursor(1, 7);
                oled_write("OVER", false);
                current_lock_timer = timer_read();
            }
        } else {
            if (tetris_left_pressed || tetris_right_pressed || tetris_rotate_pressed || tetris_drop_pressed) {
                tetris_state = PLAYING;
                init_tetris();
            }

            if (timer_elapsed(tetris_gravity_timer) > TETRIS_MENU_INTERVAL) {
                oled_clear();

                uint8_t line_offset = get_random(8);

                oled_set_cursor(0, line_offset);
                oled_write("PRESS", false);        
                oled_set_cursor(1, 1 + line_offset);
                oled_write("TO", false);
                oled_set_cursor(0, 2 + line_offset);
                oled_write("PLAY", false);

                tetris_gravity_timer = timer_read();
            }
        }

        tetris_left_pressed = false;
        tetris_right_pressed = false;
        tetris_rotate_pressed = false;
        tetris_drop_pressed = false;

        tetris_timer = timer_read();
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master() && IS_LAYER_ON(_GAMING)) {
        return OLED_ROTATION_270;
    } else if (is_keyboard_master()) {
        return OLED_ROTATION_0;
    }
    return OLED_ROTATION_180;
}

// 32x128
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        if (IS_LAYER_ON(_GAMING)) {
            if (tetris_state == DISABLED) {
                tetris_state = MENU;
                tetris_gravity_timer = timer_read() - TETRIS_MENU_INTERVAL;
                oled_init(OLED_ROTATION_270);
            } else {
                update_tetris();
            }
        } else {
            if (tetris_state != DISABLED) {
                tetris_state = DISABLED;
                oled_init(OLED_ROTATION_0);
            }
            oled_write(read_logo(), SHIFT_DOWN);
        }
    } else { 
        oled_write(read_logo(), false);
    }
    return false;
}
#endif // OLED_ENABLE
