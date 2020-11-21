 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
  * 
  * This program is free software: you can redistribute it and/or modify 
  * it under the terms of the GNU General Public License as published by 
  * the Free Software Foundation, either version 2 of the License, or 
  * (at your option) any later version. 
  * 
  * This program is distributed in the hope that it will be useful, 
  * but WITHOUT ANY WARRANTY; without even the implied warranty of 
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
  * GNU General Public License for more details. 
  * 
  * You should have received a copy of the GNU General Public License 
  * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
  */ 

#include QMK_KEYBOARD_H
#include "config.h"

//Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.
enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

#include "oled.c"
#include "encoder.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|  MUTE |    | SLEEP |------+------+------+------+------+------|
 * | LCtr |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR | LOWER| / Space /       \ Space\  |RAISE |   `  | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS, \
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT, \
  KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     KC_SLEP,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
                 KC_LGUI,KC_LALT,KC_LCTRL, KC_LOWER, KC_SPC,      KC_SPC,  KC_RAISE, KC_QUOT, KC_RALT, KC_RGUI \
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  | Enter|
 * |------+------+------+------+------+------|  MUTE |    | SLEEP |------+------+------+------+------+------|
 * | LCtr |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR | LOWER| / Space /       \ Space\  |RAISE |   '  | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[_COLEMAK] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC, \
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_ENT, \
  KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    KC_SLEP, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                 KC_LGUI,KC_LALT,KC_LCTRL,KC_LOWER, KC_SPC,      KC_SPC,KC_RAISE, KC_GRV, KC_RALT, KC_RGUI \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |      |      |                    |   7  |   8  |   9  |   -  |   +  |   =  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   ^  |   &  |   *  |   [  |   ]  |-------.    ,-------|   4  |   5  |   6  |   *  |   /  | ENT  |
 * |------+------+------+------+------+------|  MUTE |    | SLEEP |------+------+------+------+------+------|
 * | LCtr |   _  |  +=  |      |   {  |   }  |-------|    |-------|   1  |   2  |   3  |   .  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR | LOWER| / Space /       \ Space\  |RAISE |   0  | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,\
  _______,  KC_EXLM, KC_AT,   KC_HASH, XXXXXXX, XXXXXXX,                         KC_P7, KC_P8, KC_P9, KC_PMNS, KC_PPLS, KC_PEQL, \
  _______,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC,                         KC_P4, KC_P5, KC_P6, KC_PAST, KC_PSLS, KC_PENT, \
  _______,  S(KC_MINS), KC_EQL,  XXXXXXX, KC_LCBR, KC_RCBR, _______,       _______, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_BSLS, _______, \
                       _______, _______, _______, _______, _______,   _______, _______, KC_P0, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |      |      |      |      |      |                    |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      | PREV |MS_UP | NEXT |      |                    |      | PWrd |  Up  | NWrd |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift| Caps |      |      |      | Home |-------.    ,-------|PageUp| Left | Down | Rigth|   |  |      |
 * |------+------+------+------+------+------|  MUTE |    | SLEEP |------+------+------+------+------+------|
 * | LCtr | Undo |  Cut | Copy | Paste| End  |-------|    |-------|PageDn| LStr |      | LEnd |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR | LOWER| / Space /       \ Space\  |RAISE |   '  | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                           _______, _______,  _______, _______,  _______,  KC_DEL, \
  _______, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2,  XXXXXXX,                          XXXXXXX, KC_PRVWD, KC_UP,   KC_NXTWD, KC_DLINE, XXXXXXX, \
  _______, KC_CAPS, KC_MS_L, KC_MS_D, KC_MS_R,  KC_HOME,                          KC_PGUP, KC_LEFT,  KC_DOWN, KC_RGHT,  KC_PIPE,  XXXXXXX, \
  _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, KC_END,  _______,       _______,  KC_PGDN, KC_LSTRT, XXXXXXX, KC_LEND,  KC_BSLS,  _______, \
                  _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|COLEMAK|     |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    | SLEEP |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR | LOWER| / Space /       \ Space\  |RAISE |   '  | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX ,   XXXXXXX,  XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  RESET   , XXXXXXX,  KC_QWERTY, KC_COLEMAK, XXXXXXX,  XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX,  CG_TOGG,   XXXXXXX,    XXXXXXX,  XXXXXXX,                       XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LCTL));
                } else {
                    register_mods(mod_config(MOD_LALT));
                }
                register_code(KC_LEFT);
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                } else {
                    unregister_mods(mod_config(MOD_LALT));
                }
                unregister_code(KC_LEFT);
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                register_mods(mod_config(keymap_config.swap_lctl_lgui?MOD_LCTL:MOD_LALT));
                register_code(KC_RIGHT);
            } else {
                unregister_mods(mod_config(keymap_config.swap_lctl_lgui?MOD_LCTL:MOD_LALT));
                unregister_code(KC_RIGHT);
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_code(KC_HOME);
                } else {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_code(KC_HOME);
                } else {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_code(KC_END);
                } else {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_code(KC_END);
                } else {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(keymap_config.swap_lctl_lgui?MOD_LCTL:MOD_LGUI));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(keymap_config.swap_lctl_lgui?MOD_LCTL:MOD_LGUI));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(keymap_config.swap_lctl_lgui?MOD_LCTL:MOD_LGUI));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(keymap_config.swap_lctl_lgui?MOD_LCTL:MOD_LGUI));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(keymap_config.swap_lctl_lgui?MOD_LCTL:MOD_LGUI));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(keymap_config.swap_lctl_lgui?MOD_LCTL:MOD_LGUI));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(keymap_config.swap_lctl_lgui?MOD_LCTL:MOD_LGUI));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(keymap_config.swap_lctl_lgui?MOD_LCTL:MOD_LGUI));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(keymap_config.swap_lctl_lgui?MOD_LCTL:MOD_LGUI));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(keymap_config.swap_lctl_lgui?MOD_LCTL:MOD_LGUI));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}
