#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

// Left-hand home row mods
#define HOME_S LGUI_T(KC_S)
#define HOME_D LALT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K LALT_T(KC_K)
#define HOME_L RGUI_T(KC_L)

enum custom_keycodes {
  MAC_LOCK,
};


// [QWR] = LAYOUT(
//   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
//   KC_A,    HOME_S,  HOME_D,  HOME_F,  HOME_G,                    HOME_H,  HOME_J,  HOME_K,  HOME_L,  KC_QUOT,
//   KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    _______, _______, KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH,
//   _______, _______, _______, LA_EXT,  KC_SPC,  _______, _______, KC_RSFT, LA_SYM,  _______, _______, _______
// ),
//
// [CLM] = LAYOUT(
//   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
//   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
//   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
//   _______, _______, _______, LA_EXT,  kc_a_r,  _______, _______, KC_RSFT, LA_SYM,  _______, _______, _______
// ),
//
// // -----------------------------------------------------------------------------------------
// // |   !   |   @   |   [   |   ]   |   %   | ----- |   +   |   7   |   8   |   9   |   "   |
// // |   \   |   |   |   (   |   )   |   $   | ----- |   -   |   4   |   5   |   6   |   '   |
// // |   _   |  eq   |   {   |   }   |   #   | ----- |   *   |   1   |   2   |   3   |   0   |
// //                         |  ---  |  SYM2 | ----- |  ---  |  xxx  |
// [SYM] = LAYOUT(
//   KC_EXLM, KC_AT,   KC_SCLN, KC_COLN, KC_UNDS,                   KC_PLUS, KC_7,    KC_8,    KC_9,    KC_EQL,
//   KC_BSLS, KC_PIPE, KC_LCBR, KC_LPRN, KC_LBRC,                   KC_MINS, KC_4,    KC_5,    KC_6,    KC_0,
//   KC_GRV,  KC_TILD, KC_RCBR, KC_RPRN, KC_RBRC, _______, _______, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_SLSH,
//   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// ),
//
// // -----------------------------------------------------------------------------------------
// // |       | cm-tb | al-tb |       | reset | ----- |  hom  | pgdwn | pgup  |  end  |  bsp  |
// // |  meh  |  alt  |  sft  |  ctl  |  esc  | ----- |  lft  |  dwn  |  up   |  rht  |  bsp  |
// // |       | sf-tb |  tab  |  cmd  |       | ----- |       |  ent  |       |       |  del  |
// //                         |  xxx  |  fun  | ----- |  ---  |  ---  |
// [EXT] = LAYOUT(
//   XXXXXXX, CMD_TAB, ALT_TAB, XXXXXXX, RESET,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSPC,
//   KC_ESC,  OS_ALT,  OS_SFT,  OS_CTL,  OSM_MEH,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_BSPC,
//   XXXXXXX, S_TAB,   KC_TAB,  OS_CMD,  XXXXXXX, _______, _______, _______, KC_ENT,  _______, _______, KC_DEL,
//   _______, _______, _______, XXXXXXX, LA_FUN,  _______, _______, _______, _______, _______, _______, _______
// ),
//
// // -----------------------------------------------------------------------------------------
// // |  br-  |  br+  |  vl-  |  vl+  |  mut  | ----- |  f12  |  f7   |  f8   |  f9   |       |
// // |       |       |       |       |       | ----- |  f11  |  f4   |  f5   |  f6   |  clm  |
// // |       |       |       |       |       | ----- |  f10  |  f1   |  f2   |  f3   |  qwr  |
// //                         |  ---  |  ---  | ----- |  ---  |  ---  |
// [FUN] = LAYOUT(
//   KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE,                   KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX,
//   _______, _______, _______, _______, _______,                   KC_F11,  KC_F4,   KC_F5,   KC_F6,   DF(CLM),
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   DF(QWR),
//   _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______
// )
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_TRANSPARENT, KC_TRANSPARENT,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,        KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_A,    KC_S,  KC_D,  KC_F,  KC_G,                                KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN,   KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B, KC_TRANSPARENT, KC_TRANSPARENT,  KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_TRANSPARENT,       KC_LALT,
    KC_TRANSPARENT,    KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,        KC_TRANSPARENT, KC_TRANSPARENT,        KC_TRANSPARENT,       KC_TRANSPARENT,        KC_TRANSPARENT,         KC_TRANSPARENT,
                                                                                                    LCTL_T(KC_ESC), KC_TRANSPARENT,        KC_TRANSPARENT,OSM(MOD_LGUI),
                                                                                                                    KC_TRANSPARENT,KC_TRANSPARENT,
                                                                                    MT(MOD_LSFT, KC_ENTER),QK_REP,       KC_TRANSPARENT,       KC_TRANSPARENT,        LT(2, KC_BSPC),      LT(1,KC_SPACE)
  ),
// // -----------------------------------------------------------------------------------------
// // |   !   |   @   |   [   |   ]   |   %   | ----- |   +   |   7   |   8   |   9   |   "   |
// // |   \   |   |   |   (   |   )   |   $   | ----- |   -   |   4   |   5   |   6   |   '   |
// // |   _   |  eq   |   {   |   }   |   #   | ----- |   *   |   1   |   2   |   3   |   0   |
// //                         |  ---  |  SYM2 | ----- |  ---  |  xxx  |
  [1] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_PERC,    KC_TRANSPARENT,KC_TRANSPARENT,          KC_PLUS, KC_7,    KC_8,    KC_9,    KC_DQUO,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_BSLS, KC_GRV, KC_LPRN, KC_RPRN, KC_DLR,                                            KC_MINS, KC_4,    KC_5,    KC_6,    KC_QUOT,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_UNDS,  KC_EQL, KC_LCBR, KC_RCBR, KC_HASH,    KC_TRANSPARENT, KC_TRANSPARENT,         KC_ASTR, KC_1,    KC_2,    KC_3,    KC_0,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, QK_AREP, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSPC,   KC_TRANSPARENT,
    KC_TRANSPARENT, OSM(MOD_LALT),  OSM(MOD_LGUI),  LSFT(KC_TAB),  KC_TAB,  KC_MEH,                                             KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_BSPC,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_DEL,   KC_INS,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ENT,  KC_DEL, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT,MO(3),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT
    ),
  [3] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE,    KC_TRANSPARENT, KC_TRANSPARENT,     KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_TRANSPARENT,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT
        ),
};


// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
