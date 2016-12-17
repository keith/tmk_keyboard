#include "keymap_common.h"

/*
 * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
 *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
 * mouse volup             reset      ||             F1    F2    F3   F12
 *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
 */
#define LAYER_TWO KEYMAP(KC_INS, KC_HOME, KC_UP, KC_END, KC_PGUP, \
                           KC_UP, KC_F7, KC_F8, KC_F9, KC_F10, \
                         KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, \
                           KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11,          \
                         KC_NO, KC__VOLUP, KC_NO, KC_NO, KC_FN3, \
                           KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,            \
                         KC_NO, KC__VOLDOWN, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, \
                           KC_LALT, KC_SPC, KC_FN2, KC_PSCREEN, KC_SLCK, KC_PAUSE)

/* The default Atreus layout. First layer is normal keys, second
   (momentary fn layer) is numbers, most punctuation, and
   arrows. Third (modal, persistent) layer is function keys and other
   rarely-used keys. */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /// Layer 0
  // Q row from Q to P
  // A row from A to ; (no '/")
  // Z row from Z to /
  /// Bottom Row
  // Ctrl, option/alt, GUI, shift, space
  // ESC, tab
  // Backspace, layer, minus, quote, enter
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_SPC,                         \
         KC_ESC, KC_TAB,                                                     \
         KC_BSPC, KC_FN0, KC_MINS, KC_QUOT, KC_ENT),                         \
  /// Layer 1
  // Numer row from 1 to 0
  // Mixed bag row: grave/tilde, 5 blank, equal, left bracket [, right ], backslash
  // Arrow row: 6 blank, left, down, up, right
  /*
  * L2  insert super shift bksp ctrl || alt space   fn    .     0    =
  */
  KEYMAP(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, \
         KC_GRAVE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EQUAL, KC_LBRC, KC_RBRC, KC_BSLS, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, \
         KC_FN1, SHIFT(KC_INS), KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, \
         KC_LALT, KC_SPC, KC_FN0, KC_DOT, KC_0, KC_EQUAL) \
  /* 2: arrows and function keys */
  LAYER_TWO
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
