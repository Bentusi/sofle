#include QMK_KEYBOARD_H

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
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     KC_SLEP,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
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
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS, \
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT, \
  KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    KC_SLEP, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                 KC_LGUI,KC_LALT,KC_LCTRL,KC_LOWER, KC_SPC,      KC_SPC,KC_RAISE, KC_QUOT, KC_RALT, KC_RGUI \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |   _  |   =  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   (  |   )  |                    |   7  |   8  |   9  |   -  |   +  |   =  |
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
  KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6, KC_F7, KC_F8,S(KC_MINS),KC_PEQL,KC_BSPC,\
  _______,  KC_EXLM, KC_AT,   KC_HASH, S(KC_9), S(KC_0),                         KC_P7, KC_P8, KC_P9, KC_PMNS, KC_PPLS, KC_PEQL, \
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
 * |LShift| Caps |      |MS_DN |      | Home |-------.    ,-------|PageUp| Left | Down | Rigth|   |  |      |
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

#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("WIN"), false);
    } else {
        oled_write_ln_P(PSTR("MAC"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(led_usb_state.caps_lock?PSTR("CPSLK"):PSTR("     "), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    //return OLED_ROTATION_270;
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
}

#endif

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

#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_BRIU);
        } else {
            tap_code(KC_BRID);
        }
    }
}

#endif
