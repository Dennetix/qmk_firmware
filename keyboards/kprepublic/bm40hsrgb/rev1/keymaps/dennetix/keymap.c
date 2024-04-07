#include QMK_KEYBOARD_H

#include <string.h>

enum Layers {
    _COLEMAK = 0,
    _QWERTY,
    _GAMING,
    _LOWER,
    _RAISE,
    _ADJUST,
    _EXTRA
};

#define _ KC_TRNS

// Correct ANSI keycode names for existing keycodes from the german layout
#define CKC_Y KC_Z
#define CKC_Z KC_Y
#define CKC_MINS KC_SLSH

// Implemented in process_record_user
enum Custom {
    CKC_SFTENT = SAFE_RANGE,
    CKC_TABEX,
    
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
    CKC_AT,
    CKC_HASH,
    CKC_CIRC,
    CKC_AMPR,
    CKC_ASTR,
    CKC_LPRN,
    CKC_RPRN,
    CKC_UNDS,
    CKC_PLUS,
    CKC_LCBR,
    CKC_RCBR,
    CKC_PIPE,
    CKC_GRV,

    // Special german characters
    CKC_SZ,
    CKC_EURO,

    CUSTOM_KEYS_END
};

// tap/hold Umlaute
#define CKC_UMLA MT(0, KC_A)
#define CKC_UMLO MT(0, KC_O)
#define CKC_UMLU MT(0, KC_U)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Colemak
    * ,-----------------------------------------------------------------------------------.
    * | Esc/~|   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |Tab/Ex|   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |RS/Ent|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | Ctrl |  GUI | Alt  |Lower |    Space    |Raise | Alt  | Menu | Ctrl |Toggle|
    * `-----------------------------------------------------------------------------------'
    */
    [_COLEMAK] = LAYOUT_planck_mit(
        CKC_GESC,  KC_Q,     LGUI_T(KC_W), KC_F,         KC_P,         KC_B,   KC_J,       KC_L,         CKC_UMLU,     LGUI_T(CKC_Y), CKC_SCLN, KC_BSPC,
        CKC_TABEX, CKC_UMLA, LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,   KC_M,       RCTL_T(KC_N), RSFT_T(KC_E), LALT_T(KC_I),  CKC_UMLO, CKC_QUOT,
        KC_LSFT,   CKC_Z,    KC_X,         KC_C,         KC_D,         KC_V,   KC_K,       KC_H,         CKC_COMM,     CKC_DOT,       CKC_SLSH, CKC_SFTENT,
        KC_NO,     KC_LCTL,  KC_LGUI,      KC_LALT,      MO(_LOWER),      KC_SPC,          MO(_RAISE),   KC_RALT,      KC_APP,        KC_RCTL,  TG(_GAMING)
    ),

    /* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * | Esc/~|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |Tab/Ex|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RS/Ent|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | Ctrl |  GUI | Alt  |Lower |    Space    |Raise | Alt  | Menu | Ctrl |Toggle|
    * `-----------------------------------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT_planck_mit(
        CKC_GESC,  KC_Q,     LGUI_T(KC_W), KC_E,         KC_R,         KC_T,    CKC_Y, CKC_UMLU,     KC_I,         CKC_UMLO,     KC_P,     KC_BSPC,
        CKC_TABEX, CKC_UMLA, LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,    KC_H,  RCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), CKC_SCLN, CKC_QUOT,
        KC_LSFT,   CKC_Z,    KC_X,         KC_C,         KC_V,         KC_B,    KC_N,  KC_M,         CKC_COMM,     CKC_DOT,      CKC_SLSH, CKC_SFTENT,
        KC_NO,     KC_LCTL,  KC_LGUI,      KC_LALT,      MO(_LOWER),       KC_SPC,     MO(_RAISE),   KC_RALT,      KC_APP,       KC_RCTL,  TG(_GAMING)
    ),

    /* Gaming
    * ,-----------------------------------------------------------------------------------.
    * | Esc/~|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RS/Ent|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | Ctrl |  GUI | Alt  |Space |    Space    |      | Alt  | Menu | Ctrl |Toggle|
    * `-----------------------------------------------------------------------------------'
    */
    [_GAMING] = LAYOUT_planck_mit(
        CKC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,   KC_T, CKC_Y, KC_U,  KC_I,     KC_O,     KC_P,     KC_BSPC,
        KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,   KC_G, KC_H,  KC_J,  KC_K,     KC_L,     CKC_SCLN, CKC_QUOT,
        KC_LSFT,  CKC_Z,   KC_X,    KC_C,    KC_V,   KC_B, KC_N,  KC_M,  CKC_COMM, CKC_DOT,  CKC_SLSH, CKC_SFTENT,
        KC_NO,    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,   KC_SPC,    KC_NO, KC_RALT,  KC_APP,   KC_RCTL,  TG(_GAMING)
    ),

    /* Lower
    * ,-----------------------------------------------------------------------------------.
    * |      | Prev | Play | Next |      |      |      |PgDown|  Up  | PgUp |  _   | Del  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |  [   |   ]  | Left | Down |Right |  +   |  `   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |  {   |   }  |      |      |      |  |   |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |Adjust|      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT_planck_mit(
        _, KC_MPRV, KC_MPLY, KC_MNXT, _, _,        _,        KC_PGDN,     KC_UP,   KC_PGUP, CKC_UNDS, KC_DEL,
        _, _,       _,       _,       _, CKC_LBRC, CKC_RBRC, KC_LEFT,     KC_DOWN, KC_RGHT, CKC_PLUS, CKC_GRV,
        _, _,       _,       _,       _, CKC_LCBR, CKC_RCBR, _,           _,       _,       CKC_PIPE, _,
        _, _,       _,       _,       _,         _,          MO(_ADJUST), _,       _,       _,        _
    ),

    /* Raise
    * ,-----------------------------------------------------------------------------------.
    * |      | Prev | Play | Next |      |      |      |      |      |      |  -   | Del  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |  ß   |  €   |      |  [   |   ]  |      |      |      |  =   |  F11 |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |  {   |   }  |      |      |      |  \   |  F12 |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |Adjust|             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT_planck_mit(
        _, KC_MPRV, KC_MPLY, KC_MNXT,  _,           _,        _,        _, _, _, CKC_MINS, KC_DEL,
        _, _,       CKC_SZ,  CKC_EURO, _,           CKC_LBRC, CKC_RBRC, _, _, _, CKC_EQL,  KC_F11,
        _, _,       _,       _,        _,           CKC_LCBR, CKC_RCBR, _, _, _, CKC_BSLS, KC_F12,
        _, _,       _,       _,        MO(_ADJUST),          _,         _, _, _, _,        _
    ),

    /*  Adjust (Lower + Raise)
    * ,-----------------------------------------------------------------------------------.
    * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  Del |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  F11 |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_ADJUST] = LAYOUT_planck_mit(
        _, KC_EXLM, CKC_AT, CKC_HASH, KC_DLR, KC_PERC, CKC_CIRC, CKC_AMPR, CKC_ASTR, CKC_LPRN, CKC_RPRN, KC_DEL,
        _, KC_1,    KC_2,   KC_3,     KC_4,   KC_5,    KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_F11,
        _, KC_F1,   KC_F2,  KC_F3,    KC_F4,  KC_F5,   KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,
        _, _,       _,       _,       _,            _,           _,        _,        _,        _,        _ 
    ),

    /* Extra
    * ,-----------------------------------------------------------------------------------.
    * |Reset |      |Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |Toggle|
    * `-----------------------------------------------------------------------------------'
    */
    [_EXTRA] = LAYOUT_planck_mit(
        QK_BOOT, _, _, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _,
        _,       _, _, _,       _,       _,       _,       _,       _,       _,       _,       _,
        _,       _, _, _,       _,       _,       _,       _,       _,       _,       _,       _,
        _,       _, _, _,       _,           _,            _,       _,       _,       _,       TG(_QWERTY)
    )

};

// CKC_SFTETN
bool keys_pressed_while_rshift = false;
uint16_t rshift_timer = 0;

// CKC_TABEX
bool tab_down = false;
bool keys_pressed_while_tab = false;
uint16_t tab_timer = 0;

// All other custom keys
uint8_t* custom_key_state;

bool lshift_down = false;
bool rshift_down = false;

bool physical_lshift_down = false;
bool physical_rshift_down = false;

#define MAX_ENTER_TAB_TIME 300

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
        if (RESTORE_SHIFT_REGISTER(keycode)) {
            unregister_shift();
        } else {
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
    if (physical_rshift_down && keycode != CKC_SFTENT) {
        keys_pressed_while_rshift = true;
    }

    if (tab_down && keycode != CKC_TABEX) {
        keys_pressed_while_tab = true;
    }

    switch (keycode) {
        case KC_LSFT:
            physical_lshift_down = record->event.pressed;
            lshift_down = record->event.pressed;
            return true;
        case CKC_SFTENT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
                physical_rshift_down = true;
                rshift_down = true;
                keys_pressed_while_rshift = false;
                rshift_timer = timer_read();
            } else {
                unregister_code(KC_RSFT);
                physical_rshift_down = false;
                rshift_down = false;
                if (!keys_pressed_while_rshift && timer_elapsed(rshift_timer) <= MAX_ENTER_TAB_TIME) {
                    tap_code(KC_ENT);
                }
            }
            break;
        case CKC_TABEX:
            if (record->event.pressed) {
                layer_on(_EXTRA);
                tab_down = true;
                keys_pressed_while_tab = false;
                tab_timer = timer_read();
            } else {
                layer_off(_EXTRA);
                tab_down = false;
                if (!keys_pressed_while_tab && timer_elapsed(tab_timer) <= MAX_ENTER_TAB_TIME) {
                    tap_code(KC_TAB);
                }
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

        case CKC_AT:
            handle_key(keycode, record->event.pressed, KC_Q, KC_Q, false, false, true, true);
            break;
        case CKC_HASH:
            handle_key(keycode, record->event.pressed, KC_BSLS, KC_BSLS, false, false, false, false);
            break;
        case CKC_CIRC:
            if (record->event.pressed) {
                tap_code(KC_GRV);
                tap_code(KC_GRV);
            }
            break;
        case CKC_AMPR:
            handle_key(keycode, record->event.pressed, KC_6, KC_6, true, true, false, false);
            break;
        case CKC_ASTR:
            handle_key(keycode, record->event.pressed, KC_RBRC, KC_RBRC, true, true, false, false);
            break;
        case CKC_LPRN:
            handle_key(keycode, record->event.pressed, KC_8, KC_8, true, true, false, false);
            break;
        case CKC_RPRN:
            handle_key(keycode, record->event.pressed, KC_9, KC_9, true, true, false, false);
            break;
        case CKC_UNDS:
            handle_key(keycode, record->event.pressed, KC_SLSH, KC_SLSH, true, true, false, false);
            break;
        case CKC_PLUS:
            handle_key(keycode, record->event.pressed, KC_RBRC, KC_RBRC, false, false, false, false);
            break;
        case CKC_LCBR:
            handle_key(keycode, record->event.pressed, KC_7, KC_7, false, false, true, true);
            break;
        case CKC_RCBR:
            handle_key(keycode, record->event.pressed, KC_0, KC_0, false, false, true, true);
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
