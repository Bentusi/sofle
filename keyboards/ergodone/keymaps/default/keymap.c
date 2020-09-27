#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  ~`  |           |  "'  |   6  |   7  |   8  |   9  |   0  |Backspac|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Mute |           |SLEEP |   Y  |   U  |   I  |   O  |   P  |   |\   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  :;  | Enter  |
 * |--------+------+------+------+------+------| Ins  |           |Scrprt|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  <,  |  >.  |  ?/  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | LGui | LAlt |   _  |  Del |                                       |  {[  |  ]}  |  -_  |  +=  | RGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Home | End  |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       | Up   |        |      |
 *                                 | Space| SYMB |------|       |------|  MEDA  |Space |
 *                                 |      |      | PgDn |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,     KC_3,     KC_4,    KC_5,   KC_GRV,
        KC_TAB,         KC_Q,         KC_W,     KC_E,     KC_R,    KC_T,   KC_MUTE,
        KC_LCTL,        KC_A,         KC_S,     KC_D,     KC_F,    KC_G,
        KC_LSFT,        KC_Z,         KC_X,     KC_C,     KC_V,    KC_B,   KC_INS,
        KC_LCTL,        KC_LGUI,      KC_LALT,  S(KC_MINS),  KC_DEL,
                                                                   KC_HOME,  KC_END,
                                                                             KC_PGUP,
                                                          KC_SPC,  MO(SYMB), KC_PGDN,
        // right hand
             KC_QUOT,     KC_6,       KC_7,     KC_8,     KC_9,    KC_0,     KC_BSPC,
             KC_SLEP,     KC_Y,       KC_U,     KC_I,     KC_O,    KC_P,     KC_BSLS,
                          KC_H,       KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_ENT,
             KC_PSCR,     KC_N,       KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
                                      KC_LBRC,  KC_RBRC,  KC_MINS, KC_EQL,   KC_RGUI,
             KC_LEFT,     KC_RGHT,
             KC_UP,
             KC_DOWN,     MO(MDIA), KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   #  |   $  |   %  |      |           |      |   7  |   8  |   9  |   -  |   +  |   =    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   ~  |   ^  |   &  |      |      |------|           |------|   4  |   5  |   6  |   *  |   /  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |   1  |   2  |   3  |   .  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   0  |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Home | End  |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       | Up   |        |      |
 *                                 | Space| SYMB |------|       |------|  MEDA  |Space |
 *                                 |      |      | PgDn |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       _______,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       _______,   KC_EXLM,KC_AT,  KC_HASH,KC_DLR,KC_PERC,_______,
       _______,   KC_TILD,KC_CIRC, KC_AMPR,XXXXXXX,XXXXXXX,
       _______,   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
          _______,_______,_______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,
       _______, KC_7,   KC_8,    KC_9,    KC_MINS,  KC_PLUS, KC_EQL,
                KC_4,   KC_5,    KC_6,    KC_PAST,  KC_SCLN, _______,
       _______, KC_1,   KC_2,    KC_3,    KC_DOT,   KC_BSLS, _______,
                        KC_0,    _______, _______,  _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),


/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       _______, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, _______,
       _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_VOLU,
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
       _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                 KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
       _______,  KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_board_led_on();
            break;
        case 2:
            ergodox_board_led_on();
            break;
        default:
            // none
            break;
    }

};
