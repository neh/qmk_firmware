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

#define CTL_ESC CTL_T(KC_ESC)
#define NMSSPC LT(_NUMS, KC_SPC)
#define NMS_ENT LT(_NUMS, KC_ENT)
#define MOUSTAB LT(_MOUS, KC_TAB)
#define MOUSESC LT(_MOUS, KC_ESC)
#define NUM_ESC LT(_NUMS, KC_ESC)
#define NAVSPC LT(_NAVI, KC_SPC)

#define OK_LSFT OSM(MOD_LSFT)
#define OK_LALT OSM(MOD_LALT)
#define OK_LCTL OSM(MOD_LCTL)
#define OK_LGUI OSM(MOD_LGUI)

#define OK_MOUS OSL(_MOUS)
#define OK_FUNC OSL(_FUNC)

#define OK_GUST OSM(MOD_LGUI | MOD_LSFT)
#define OK_GUCT OSM(MOD_LGUI | MOD_LCTL)


#define _BASE 0
#define _NAVI 1
#define _NUMS 2
#define _MOUS 3
#define _FUNC 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
          DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,    DV_F,    DV_G,    DV_C,    DV_R,    DV_L,
          /* A_GUI,   O_ALT,   E_CTL,   U_SFT,   DV_I,    DV_D,    H_SFT,   T_CTL,   N_ALT,   S_GUI, */
          DV_A,    DV_O,    DV_E,    DV_U,    DV_I,    DV_D,    DV_H,    DV_T,    DV_N,    DV_S,
          DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,    DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,
                   _______, _______,                                     _______, _______,
                            OK_LGUI, OSL(_NAVI),                     KC_SPC, OSL(_NUMS),
                          /* OSL(_NAVI), KC_SPC,                     OSL(_NUMS), OK_LGUI, */
                                     OK_LCTL, OK_MOUS,  OK_FUNC, KC_ENT,
                                     NUM_ESC, KC_ESC,   _______, KC_BSPC
    ),
    [_NAVI] = LAYOUT(
          QK_BOOT, KC_VOLU, KC_VOLD, OK_GUST, _______,  C(DV_R), CS_TAB,  KC_PGDN, KC_PGUP, C_TAB,
          OK_LGUI, OK_LALT, OK_LCTL, OK_LSFT, CAPSWRD,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
          KC_MPRV, KC_MUTE, KC_MPLY, KC_MNXT, _______,  C(DV_L), _______, KC_END,  KC_HOME, _______,
                   _______, _______,                                      _______, _______,
                            _______, _______,                    _______, _______,
                                     _______, _______,  _______, CAPSWRD,
                                     _______, _______,  _______, KC_DEL
    ),
    [_NUMS] = LAYOUT(
          DV_LBRC, KC_9,    KC_8,    KC_7,    DV_RBRC,  _______, OK_GUST, OK_GUCT, _______, QK_BOOT,
          KC_0,    KC_3,    KC_2,    KC_1,    DV_SLSH,  CAPSWRD, OK_LSFT, OK_LCTL, OK_LALT, OK_LGUI,
          DV_EQL,  KC_6,    KC_5,    KC_4,    DV_GRV,   KC_ASTG, _______, _______, _______, _______,
                   _______, _______,                                      _______, _______,
                            DV_BSLS, DV_DOT,                     _______, _______,
                                     DV_MINS, _______,  _______, _______,
                                     _______, _______,  _______, _______
    ),
    [_MOUS] = LAYOUT(
          QK_BOOT, _______, _______, _______, _______,  _______, _______, KC_WH_D, KC_WH_U, _______,
          OK_LGUI, OK_LALT, OK_LCTL, OK_LSFT, CAPSWRD,  _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
          _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
                   _______, _______,                                      _______, _______,
                            _______, _______,                    KC_BTN1, KC_BTN2,
                                     _______, _______,  _______, KC_BTN3,
                                     _______, _______,  _______, _______
    ),
    [_FUNC] = LAYOUT(
          KC_F12,  KC_F9,   KC_F8,   KC_F7,   _______,  _______, _______, _______, _______, QK_BOOT,
          KC_F10,  KC_F3,   KC_F2,   KC_F1,   _______,  CAPSWRD, OK_LSFT, OK_LCTL, OK_LALT, OK_LGUI,
          KC_F11,  KC_F6,   KC_F5,   KC_F4,   _______,  _______, _______, _______, _______, _______,
                   _______, _______,                                      _______, _______,
                            _______, _______,                    _______, _______,
                                     _______, _______,  _______, _______,
                                     _______, _______,  _______, _______
    )
};

uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case DV_QUOT:
        case DV_A:
        case DV_SCLN:
        case DV_L:
        case DV_S:
        case DV_Z:
            return get_generic_autoshift_timeout() + 15;
        /* case AUTO_SHIFT_NUMERIC: */
        /*     return 2 * get_generic_autoshift_timeout(); */
        /* case AUTO_SHIFT_SPECIAL: */
        /*     return get_generic_autoshift_timeout() + 50; */
        /* case AUTO_SHIFT_ALPHA: */
        default:
            return get_generic_autoshift_timeout();
    }
}

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

const uint16_t PROGMEM dash_combo[] = {DV_J, DV_K, COMBO_END};
/* const uint16_t PROGMEM esc_combo[] = {DV_Q, DV_J, COMBO_END}; */
const uint16_t PROGMEM ctl_x_combo[] = {DV_M, DV_W, COMBO_END};
const uint16_t PROGMEM ctl_c_combo[] = {DV_G, DV_C, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {DV_W, DV_V, COMBO_END};
const uint16_t PROGMEM tab2_combo[] = {KC_HOME, KC_END, COMBO_END};
/* const uint16_t PROGMEM lctl_combo[] = {DV_O, DV_E, COMBO_END}; */
/* const uint16_t PROGMEM rctl_combo[] = {DV_T, DV_N, COMBO_END}; */
combo_t key_combos[COMBO_COUNT] = {
    COMBO(dash_combo, DV_MINS),
    /* COMBO(esc_combo, KC_ESC), */
    COMBO(ctl_x_combo, LCTL(DV_X)),
    COMBO(ctl_c_combo, LCTL(DV_C)),
    COMBO(tab_combo, KC_TAB),
    COMBO(tab2_combo, KC_TAB),
    /* COMBO(lctl_combo, OK_LCTL), */
    /* COMBO(rctl_combo, OK_LCTL), */
};
