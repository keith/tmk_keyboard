#include "keymap_common.h"

/* The default Atreus layout. First layer is normal keys, second
   (momentary fn layer) is numbers, most punctuation, and
   arrows. Third (modal, persistent) layer is function keys and other
   rarely-used keys. */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /// Layer 0
  // Q row from Q to P
  // A row from A to ; (no quotes)
  // Z row from Z to /
  /// Bottom Row
  // Ctrl, option/alt, GUI, shift, space
  // ESC, tab
  // Backspace, layer 1, minus, quote, enter
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_SPC, \
         KC_ESC, KC_TAB, \
         KC_BSPC, KC_FN0, KC_MINS, KC_QUOT, KC_ENT), \
  /// Layer 1
  // Numer row from 1 to 0
  // Mixed bag row: grave/tilde, 5 blank, equal, left bracket [, right ], backslash
  // Arrow row: 6 blank, left, down, up, right
  /// Bottom Row
  // Switch to layer 2, option/alt, GUI, shift, space
  // ESC, layer 3 momentary
  // Backspace, blank (holding to get here), minus, quote, enter
  KEYMAP(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, \
         KC_GRAVE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EQUAL, KC_LBRC, KC_RBRC, KC_BSLS, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, \
         KC_FN1, KC_LALT, KC_LGUI, KC_LSFT, KC_SPC, \
         KC_ESC, KC_FN4, \
         KC_BSPC, KC_FN0, KC_MINS, KC_QUOT, KC_ENT), \
  /// Layer 2
  // blank row
  // blank row
  // blank row
  /// Bottom Row
  // 5 blank
  // 2 blank
  // blank, layer 0, blank, blank, bootloader
  KEYMAP(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
         KC_NO, KC_NO, \
         KC_NO, KC_FN2, KC_NO, KC_NO, KC_FN3), \
  /// Layer 3
  // Function row 1 to 10
  // Blank
  // Blank
  /// Bottom Row
  // Ctrl, option/alt, GUI, shift, space
  // ESC, layer 3 momentary
  // Backspace, layer 1, minus, quote, enter
  KEYMAP(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
         KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_SPC, \
         KC_ESC, KC_FN4, \
         KC_BSPC, KC_FN0, KC_MINS, KC_QUOT, KC_ENT)
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER), // toggle bootloader
  [4] = ACTION_LAYER_MOMENTARY(3), // Switch to f keys layer
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
