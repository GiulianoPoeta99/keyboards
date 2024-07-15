#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_keycodes {
    CM_EXC = SAFE_RANGE,
    CM_IEXC,
    CM_AT,
    CM_NMRL,
    CM_DLLR,
    CM_PRCN,
    CM_CRCM,
    CM_ANDP,
    CM_ASTK,
    CM_LPRN,
    CM_RPRN,
    CM_LBRC,
    CM_RBRC,
    CM_LCBR,
    CM_RCBR,
    CM_PLUS,
    CM_EQAL,
    CM_BTCK,
    CM_VIRG,
    CM_QUOT,
    CM_DQUO,
    CM_DIER,
    CM_SLSH,
    CM_QEST,
    CM_IQES,
    CM_BSLS,
    CM_PIPE,
    CM_GRAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //? Capa dvorak: =====================================================================================================================================================
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,     KC_SCLN,    KC_COMM,    KC_DOT,     KC_P,       KC_Y,                            KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       KC_BSPC,
        KC_LSFT,    KC_A,       KC_O,       KC_E,       KC_U,       KC_I,                            KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       KC_LALT,
        KC_LCTL,    KC_MINS,    KC_Q,       KC_J,       KC_K,       KC_X,                            KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,       KC_ESC,
                                                        KC_LGUI,    MO(2),   KC_SPC,         KC_ENT, MO(3),      KC_ALGR
    ),
    //? capa qwerty ======================================================================================================================================================
    [1] = LAYOUT_split_3x6_3(
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                            KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
        KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                            KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_LALT,
        KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                            KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_MINS,    KC_ESC,
                                                        KC_LGUI,    MO(2),   KC_SPC,         KC_ENT, MO(3),      KC_ALGR
    ),
    //? capa movilidad y numeros =========================================================================================================================================
    [2] = LAYOUT_split_3x6_3(
        KC_TAB,     KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    KC_INS,                          CM_PLUS,    KC_7,       KC_8,       KC_9,       CM_SLSH,    KC_DEL,
        KC_LSFT,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,    XXXXXXX,                         CM_EQAL,    KC_4,       KC_5,       KC_6,       CM_ASTK,    KC_LALT,
        KC_LCTL,    KC_CUT,     KC_COPY,    KC_PSTE,    XXXXXXX,    XXXXXXX,                         KC_0,       KC_1,       KC_2,       KC_3,       KC_MINS,    KC_ESC,
                                                        KC_LGUI,    _______, KC_SPC,         KC_ENT, MO(4),      KC_ALGR
    ),
    //? capa simbolos y numeros ==========================================================================================================================================
    [3] = LAYOUT_split_3x6_3(
        KC_TAB,     CM_AT,      CM_DIER,    CM_VIRG,    CM_IEXC,    CM_EXC,                          CM_LPRN,    CM_RPRN,    CM_ANDP,    CM_PIPE,    CM_CRCM,    KC_DEL,
        KC_LSFT,    CM_BTCK,    CM_DQUO,    CM_QUOT,    CM_IQES,    CM_QEST,                         CM_LBRC,    CM_RBRC,    CM_EQAL,    CM_PLUS,    CM_ASTK,    KC_LALT,
        KC_LCTL,    CM_GRAD,    CM_DLLR,    CM_NMRL,    CM_BSLS,    CM_SLSH,                         CM_LCBR,    CM_RCBR,    KC_DOT,     KC_MINS,    CM_PRCN,    KC_ESC,
                                                        KC_LGUI,    MO(4),   KC_SPC,         KC_ENT, _______,    KC_ALGR
    ),
    //? capa de control y funciones ======================================================================================================================================
    [4] = LAYOUT_split_3x6_3(
        TG(1),      XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_BRIU,    KC_VOLU,                         KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,
        KC_RSFT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_BRID,    KC_VOLD,                         KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
        KC_RCTL,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_MUTE,                         KC_PSCR,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_WAKE,    KC_SLEP,
                                                        KC_LGUI,    _______, KC_SPC,         KC_ENT, _______,    KC_ALGR
    ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return rotation;
}

#define L_DVORAK 0
#define L_QWERTY 2
#define L_NAVIGATE 4
#define L_SYMBOLS 8
#define L_CONTROLS 16

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_DVORAK:
            oled_write_ln_P(PSTR("Dvorak"), false);
            break;
        case L_QWERTY:
            oled_write_ln_P(PSTR("Qwerty"), false);
            break;
        case L_NAVIGATE:
        case L_NAVIGATE|L_QWERTY:
            oled_write_ln_P(PSTR("Navigate"), false);
            break;
        case L_SYMBOLS:
        case L_SYMBOLS|L_QWERTY:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case L_CONTROLS:
        case L_CONTROLS|L_NAVIGATE:
        case L_CONTROLS|L_SYMBOLS:
        case L_CONTROLS|L_NAVIGATE|L_SYMBOLS:
        case L_CONTROLS|L_NAVIGATE|L_QWERTY:
        case L_CONTROLS|L_SYMBOLS|L_QWERTY:
        case L_CONTROLS|L_NAVIGATE|L_SYMBOLS|L_QWERTY:
            oled_write_ln_P(PSTR("Controls"), false);
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
            set_keylog(keycode, record);
    }
    switch (keycode) {
        case CM_EXC:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_1);
            } else {
                unregister_code(KC_1);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_IEXC:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_ALGR);
                register_code(KC_1);
            } else {
                unregister_code(KC_1);
                register_code(KC_ALGR);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_AT:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_2);
            } else {
                unregister_code(KC_2);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_NMRL:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_3);
            } else {
                unregister_code(KC_3);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_DLLR:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_4);
            } else {
                unregister_code(KC_4);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_PRCN:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_5);
            } else {
                unregister_code(KC_5);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_CRCM:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_6);
            } else {
                unregister_code(KC_6);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_ANDP:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_7);
            } else {
                unregister_code(KC_7);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_ASTK:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_8);
            } else {
                unregister_code(KC_8);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_LPRN:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_9);
            } else {
                unregister_code(KC_9);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_RPRN:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_0);
            } else {
                unregister_code(KC_0);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_LBRC:
            if (record->event.pressed) {
                register_code(KC_LBRC);
            } else {
                unregister_code(KC_LBRC);
            }
            return false;
        case CM_RBRC:
            if (record->event.pressed) {
                register_code(KC_RBRC);
            } else {
                unregister_code(KC_RBRC);
            }
            return false;
        case CM_LCBR:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LBRC);
            } else {
                unregister_code(KC_LBRC);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_RCBR:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_RBRC);
            } else {
                unregister_code(KC_RBRC);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_PLUS:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_EQL);
            } else {
                unregister_code(KC_EQL);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_EQAL:
            if (record->event.pressed) {
                register_code(KC_EQL);
            } else {
                unregister_code(KC_EQL);
            }
            return false;
        case CM_BTCK:
            if (record->event.pressed) {
                register_code(KC_GRV);
            } else {
                unregister_code(KC_GRV);
            }
            return false;
        case CM_VIRG:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_GRV);
            } else {
                unregister_code(KC_GRV);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_QUOT:
            if (record->event.pressed) {
                register_code(KC_QUOT);
            } else {
                unregister_code(KC_QUOT);
            }
            return false;
        case CM_DQUO:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_QUOT);
            } else {
                unregister_code(KC_QUOT);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_DIER:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_ALGR);
                register_code(KC_QUOT);
            } else {
                unregister_code(KC_QUOT);
                unregister_code(KC_ALGR);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_SLSH:
            if (record->event.pressed) {
                register_code(KC_SLSH);
            } else {
                unregister_code(KC_SLSH);
            }
            return false;
        case CM_QEST:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_SLSH);
            } else {
                unregister_code(KC_SLSH);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_IQES:
            if (record->event.pressed) {
                register_code(KC_ALGR);
                register_code(KC_SLSH);
            } else {
                unregister_code(KC_SLSH);
                unregister_code(KC_ALGR);
            }
            return false;
        case CM_BSLS:
            if (record->event.pressed) {
                register_code(KC_NUBS);
            } else {
                unregister_code(KC_NUBS);
            }
            return false;
        case CM_PIPE:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_NUBS);
            } else {
                unregister_code(KC_NUBS);
                unregister_code(KC_LSFT);
            }
            return false;
        case CM_GRAD:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_ALGR);
                register_code(KC_SCLN);
            } else {
                unregister_code(KC_SCLN);
                unregister_code(KC_ALGR);
                unregister_code(KC_LSFT);
            }
            return false;
        default:
            return true;
    }
    return true;
}
#endif