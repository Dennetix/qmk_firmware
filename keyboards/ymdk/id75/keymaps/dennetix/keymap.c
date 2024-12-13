#include QMK_KEYBOARD_H

#include "mapping.h"

enum layer_number {
    _MAIN = 0,
    _COLEMAK,
    _QWERTY,
    _SYMBOLS,
    _SYMBOLS2,
    _NAVIGATION,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_ortho_5x15(
        CKC_GESC, KC_1, CKC_2, CKC_3, KC_4, KC_5, _, _, _, CKC_6, CKC_7, CKC_8, CKC_9, CKC_0, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, _, _, _, KC_J, KC_L, KC_U, CKC_Y, KC_BSPC, CKC_GRV,
        KC_CAPS, GUI_T(KC_A), ALT_T(KC_R), SFT_T(KC_S), CTL_T(KC_T), KC_G, _, _, _, KC_M, RCTL_T(KC_N), RSFT_T(KC_E), ALT_T(KC_I), GUI_T(KC_O), CKC_QUOT,
        KC_LSFT, CKC_Z, KC_X, KC_C, KC_D, KC_V, _, _, _, KC_K, KC_H, CKC_COMM, CKC_DOT, CKC_QUOT, KC_RSFT,
        _, _, _, _, LT(_NAVIGATION, KC_TAB), OSM(MOD_LSFT), DF(_MAIN), DF(_COLEMAK), DF(_QWERTY), LT(_SYMBOLS, KC_SPC), LT(_SYMBOLS2, KC_ENT), _, _, _, _
    ),

    [_COLEMAK] = LAYOUT_ortho_5x15(
        CKC_GESC, KC_1, CKC_2, CKC_3, KC_4, KC_5, _, _, _, CKC_6, CKC_7, CKC_8, CKC_9, CKC_0, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, _, _, _, KC_J, KC_L, KC_U, CKC_Y, KC_BSPC, CKC_GRV,
        KC_CAPS, KC_A, KC_R, KC_S, KC_T, KC_G, _, _, _, KC_M, KC_N, KC_E, KC_I, KC_O, CKC_QUOT,
        KC_LSFT, CKC_Z, KC_X, KC_C, KC_D, KC_V, _, _, _, KC_K, KC_H, CKC_COMM, CKC_DOT, CKC_QUOT, KC_RSFT,
        _, _, _, _, LT(_NAVIGATION, KC_TAB), OSM(MOD_LSFT), DF(_MAIN), DF(_COLEMAK), DF(_QWERTY), LT(_SYMBOLS, KC_SPC), LT(_SYMBOLS2, KC_ENT), _, _, _, _
    ),

    [_QWERTY] = LAYOUT_ortho_5x15(
        CKC_GESC, KC_1, CKC_2, CKC_3, KC_4, KC_5, _, _, _, CKC_6, CKC_7, CKC_8, CKC_9, CKC_0, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, _, _, _, KC_Y, KC_U, KC_I, KC_O, KC_P, CKC_GRV,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, _, _, _, KC_H, KC_J, KC_K, KC_L, CKC_SCLN, CKC_QUOT,
        KC_LSFT, CKC_Z, KC_X, KC_C, KC_V, KC_B, _, _, _, KC_K, KC_M, CKC_COMM, CKC_DOT, CKC_QUOT, KC_RSFT,
        _, _, _, _, LT(_NAVIGATION, KC_TAB), OSM(MOD_LSFT), DF(_MAIN), DF(_COLEMAK), DF(_QWERTY), LT(_SYMBOLS, KC_SPC), LT(_SYMBOLS2, KC_ENT), _, _, _, _
    ),

    [_SYMBOLS] = LAYOUT_ortho_5x15(
        _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
        _, KC_1, KC_2, KC_3, KC_4, KC_5, _, _, _, KC_6, KC_7, KC_8, KC_9, KC_0, _,
        _, _, CKC_LBRC, CKC_LCBR, CKC_LPRN, _, _, _, _, CKC_QUES, CKC_MINS, CKC_EQL, CKC_SLSH, CKC_SCLN, _,
        _, _, CKC_RBRC, CKC_RCBR, CKC_RPRN, _, _, _, _, _, CKC_UNDS, CKC_PLUS, CKC_BSLS, CKC_COLN, _,
        _, _, _, _, _, _, _, _, _, _, _, _, _, _, _
    ),

    [_SYMBOLS2] = LAYOUT_ortho_5x15(
        _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
        _, KC_EXLM, CKC_AT, CKC_HASH, KC_DLR, KC_PERC, _, _, _, CKC_CIRC, CKC_AMPR, CKC_ASTR, KC_F11, KC_F12, _,
        _, _, CKC_UMLA, CKC_UMLO, CKC_UMLU, _, _, _, _, _, _, _, CKC_PIPE, CKC_TILD, _,
        _, _, _, CKC_EURO, CKC_SZ, _, _, _, _, _, _, _, _, CKC_GRV, _,
        _, _, _, _, MO(_ADJUST), _, _, _, _, _, _, _, _, _, _
    ),

    [_NAVIGATION] = LAYOUT_ortho_5x15(
        _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
        _, _, _, _, _, _, _, _, _, _, KC_PGDN, KC_UP, KC_PGUP, KC_DEL, _,
        _, _, _, _, _, _, _, _, _, _, KC_LEFT, KC_DOWN, KC_RIGHT, KC_LGUI, _,
        _, KC_CAPS, KC_ESC, KC_ENT, _, _, _, _, _, _, KC_PSCR, _, _, _, _,
        _, _, _, _, _, _, _, _, _, KC_ESC, MO(_ADJUST), _, _, _, _
    ),

    [_ADJUST] = LAYOUT_ortho_5x15(
        QK_BOOT, _, _, RGB_TOG, RGB_RMOD, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _, _, _,
        _, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _, _, _, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _,
        _, _, _, _, _, _, _, _, _, _, _, _, _, KC_F11, _,
        _, QK_BOOT, _, _, _, _, _, _, _, _, _, _, _, KC_F12, _,
        _, _, _, _, _, _, _, _, _, _, _, _, _, _, _
    )
};

bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(default_layer_state)) {
        case _MAIN:
            rgb_matrix_set_color(8, 255, 230, 0);
            break; 
        case _COLEMAK:
            rgb_matrix_set_color(7, 255, 230, 0);
            break;
        case _QWERTY:
            rgb_matrix_set_color(6, 255, 230, 0);
            break;
    }
    return false;
}

void keyboard_post_init_user(void) {
    mapping_keyboard_post_init();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return mapping_process_record(keycode, record);
}
