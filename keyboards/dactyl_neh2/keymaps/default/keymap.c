#include QMK_KEYBOARD_H
#include "keymap_dvorak.h"

#define C_TAB  C(KC_TAB)
#define CS_TAB C(S(KC_TAB))

#define A_GUI LGUI_T(DV_A)
#define O_ALT LALT_T(DV_O)
#define E_CTL LCTL_T(DV_E)
#define U_SFT LGUI_T(DV_U)
#define H_SFT RGUI_T(DV_H)
#define T_CTL RCTL_T(DV_T)
#define N_ALT RALT_T(DV_N)
#define S_GUI LGUI_T(DV_S)

/* #define LN_V LT(4, KC_V) */
/* #define LN_M LT(4, KC_M) */

#define CTLESC CTL_T(KC_ESC)
#define NMSSPC LT(_NUMSYM, KC_SPC)
#define MOUSTAB LT(_MOUSE, KC_TAB)


#define _BASE 0
#define _NAV 1
#define _NUMSYM 2
#define _MOUSE 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
          DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,    DV_F,    DV_G,    DV_C,    DV_R,    DV_L,
          /* A_GUI,   O_ALT,   E_CTL,   U_SFT,   DV_I,    DV_D,    H_SFT,   T_CTL,   N_ALT,   S_GUI, */
          DV_A,    DV_O,    DV_E,    DV_U,    DV_I,    DV_D,    DV_H,    DV_T,    DV_N,    DV_S,
          DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,    DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,
                   _______, _______,                                     _______, _______,
                            MOUSTAB, MO(_NAV),                   NMSSPC, KC_LGUI,
                                     CTLESC,  KC_LSFT,  _______, KC_ENT,
                                     KC_LALT, _______,  _______, KC_BSPC
    ),
    [_NAV] = LAYOUT(
          QK_BOOT, _______, _______, _______, _______,  C(DV_R), CS_TAB,  KC_PGDN, KC_PGUP, C_TAB,
          KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,  CAPSWRD, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
          KC_MPRV, KC_MUTE, KC_MPLY, KC_MNXT, KC_VOLD,  C(DV_L), _______, KC_END,  KC_HOME, _______,
                   _______, _______,                                      _______, _______,
                            _______, _______,                    _______, LGUI(KC_TAB),
                                     _______, _______,  _______, CAPSWRD,
                                     _______, _______,  _______, KC_DEL
    ),
    [_NUMSYM] = LAYOUT(
          DV_LBRC, KC_4,    KC_5,    KC_6,    DV_RBRC,  _______, _______, _______, _______, QK_BOOT,
          KC_0,    KC_1,    KC_2,    KC_3,    DV_SLSH,  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
          DV_EQL,  KC_7,    KC_8,    KC_9,    DV_GRV,   _______, _______, _______, _______, _______,
                   _______, _______,                                      _______, _______,
                            DV_BSLS, DV_DOT,                     _______, _______,
                                     DV_MINS, _______,  _______, _______,
                                     _______, _______,  _______, _______
    ),
    [_MOUSE] = LAYOUT(
          QK_BOOT, _______, _______, _______, _______,  _______, _______, KC_WH_D, KC_WH_U, _______,
          KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,  _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
          _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
                   _______, _______,                                      _______, _______,
                            _______, _______,                    KC_BTN1, KC_BTN2,
                                     _______, _______,  _______, KC_BTN3,
                                     _______, _______,  _______, _______
    ),
    [4] = LAYOUT(
          KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______,  _______, _______, _______, _______, QK_BOOT,
          KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______,  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
          KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______,  _______, _______, _______, _______, _______,
                   _______, _______,                                      _______, _______,
                            _______, _______,                    _______, _______,
                                     _______, _______,  _______, _______,
                                     _______, _______,  _______, _______
    )
};

/* uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) { */
/*     switch(keycode) { */
/*         case AUTO_SHIFT_NUMERIC: */
/*             return 2 * get_generic_autoshift_timeout(); */
/*         case AUTO_SHIFT_SPECIAL: */
/*             return get_generic_autoshift_timeout() + 50; */
/*         case AUTO_SHIFT_ALPHA: */
/*         default: */
/*             return get_generic_autoshift_timeout(); */
/*     } */
/* } */

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_SCLN:
        case KC_COMM:
        case KC_DOT:
        case KC_SLSH:
        case KC_QUOT:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_SPC:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
