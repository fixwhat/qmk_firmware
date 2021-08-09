#include QMK_KEYBOARD_H

// [Init Variables] ----------------------------------------------------------//

// Tap Dance declarations
enum {
    DOT_COMMA = 0
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [DOT_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMMA)
};


// Preenchimento para facilitar legibilidade 
// Just for legibility 
#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

// [Layer Keymaps] -----------------------------------------------------------//

//Layers
enum layers {
  _BA = 0,
  _FC
};


//13 characters max without re-writing the "Layer: " format in iota_gfx_task_user()
//static char layer_lookup[][14] = {"Base","Funcoes"};

/* ghettolinear - Default
  * Primeira Linha - Layer Principal ML 
  * Segunda Linha - Layer Secundario FN
      * ,------------------------------------------------\          /------------------------------------------------.
      * |  ESC  |  1  |   2  |   3  |   4  |   5  |   6  |          |   7  |   8  |   9  |   0  |   -  |  =   | Bksp |
      * |       |  F1 |   F2 |   F3 |   F4 |   F5 |      |          |   7  |   8  |   9  |      |  F10 | F11  |Delete|
      * |-------------+------+------+------+------+------+          +------+------+------+------+------+------+------+
      * | Tab   |  Q  |   W  |   E  |   R  |   T  |  [{  |          |   Y  |   U  |   I  |   O  |   P  |  '"  |   |  |
      * |       |     |      |      |      |      |      |          |   4  |   5  |   6  |      |      |      |   \  |
      * |-------+-----+------+------+------+-------------+          +------+------+------+------+------+------+------+
      * | CAPS  |  A  |   S  |   D  |   F  |   G  | '  " |          |   H  |   J  |   K  |   L  |  :;  |      | Enter|
      * |       |     |      |      |      |      |      |          |   1  |   2  |   3  |   +  |      |      |      |
      * |-------+-----+------+------+------+------|------+          +------+------+------+------+------+------+------+
      * | Shift |  Z  |   X  |   C  |   V  |   B  |   <  |          |   N  |   M  |  <,  |  .>  |  /?  |  UP  |  /?  |
      * |       |     |      |      |      |      |      |          |   0  |   .  |  ,   |      |      | PGUp |      |
      * |-------+-----+------+------+------+------+------+          +------+------+------+------+------+------+------+
      * | Lctrl | _FC | LAlt | DEL  | BKSP |    Space    |          |    Space    | Ralt | _FN  | Left | Down | Right|
      * |       |     |      |      |      |             |          |    BKSP     |      |      |      | PGDw |      |
      * `------------------------------------------------/          \------------------------------------------------/
      */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,   KC_4,     KC_5,    KC_6,             KC_7,    KC_8,    KC_9,        KC_0,           KC_MINS,   KC_EQUAL, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,     KC_T,    KC_LBRC,          KC_Y,    KC_U,    KC_I,        KC_O,           KC_P,      KC_QUOTE, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,     KC_G,    KC_QUOTE,         KC_H,    KC_J,    KC_K,        KC_L,           KC_SCOLON,  KC_ENTER, KC_ENTER,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,     KC_B,    KC_LABK,          KC_N,    KC_M,    KC_COMMA,    KC_DOT,         KC_SLASH,   KC_UP,    KC_RSFT,
        KC_LCTL, MO(_FC), KC_LALT, KC_DEL, KC_BSPC,  XXXXXXX, KC_SPC,           KC_SPC,  XXXXXXX, MO(_FC),     KC_LALT,        KC_LEFT,   KC_DOWN,  KC_RGHT
    ),
    [1] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_KP_7, KC_KP_8, KC_KP_9,      KC_KP_MINUS,   KC_F11,     KC_F12, KC_DEL,
        _______, _______, _______, _______, KC_PAST, KC_PSLS, _______,          KC_KP_4, KC_KP_5, KC_KP_6,      KC_KP_PLUS,    _______,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          KC_KP_1, KC_KP_2, KC_KP_3,      KC_PEQL,       _______,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          KC_KP_0, KC_KP_0, TD(DOT_COMMA), KC_KP_ENTER,   _______,    KC_PGUP, RESET,
        _______, _______, _______, _______, _______, XXXXXXX, _______,          KC_BSPC, XXXXXXX, _______,      _______,       KC_HOME,    KC_PGDN, KC_END
    )
};


// OLED Rotation enum values are flags

#ifdef OLED_DRIVER_ENABLE   // OLED Functionality
    uint8_t selected_layer = 0;
    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        return OLED_ROTATION_0;       // flips the display 180 degrees if offhand
    }

    bool clear_screen = false;          // used to manage singular screen clears to prevent display glitch
    static void render_name(void) {     // Render Mercutio Script Text
        static const char PROGMEM mercutio_name[] = {
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    
  
        };
        oled_write_P(mercutio_name, false);
    }

    static void render_logo(void) {     // Logo feio a esquerda win e android
        static const char PROGMEM logo_1[] = {0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0x00};
        static const char PROGMEM logo_2[] = {0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0x00};
        static const char PROGMEM logo_3[] = {0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xB6, 0x00};
       static const char PROGMEM logo_4[] = {0xB6, 0xB6, 0xB6, 0x9B, 0x9C, 0x9D, 0x9E, 0x00};
        oled_set_cursor(1,0);
       oled_write_P(logo_1, false);
       oled_set_cursor(0,1);
       oled_write_P(logo_2, false);
       oled_set_cursor(0,2);
       oled_write_P(logo_3, false);
       oled_set_cursor(0,3);
       oled_write_P(logo_4, false);
    }

    void oled_task_user(void) {
        
        if ( IS_HOST_LED_OFF(USB_LED_NUM_LOCK) && IS_HOST_LED_OFF(USB_LED_CAPS_LOCK) && selected_layer == 0 && get_highest_layer(layer_state) == 0 ) {
            render_name();
            clear_screen = true;
        } else {
            if (clear_screen == true) {
                oled_clear();
                oled_render();
                clear_screen = false;
            }
            
            render_logo();
            oled_set_cursor(8,2);
            switch(selected_layer){
                case 0:
                    oled_write_P(PSTR("Lock Layer 0"), false);
                    break;
                case 1: 
                    oled_write_P(PSTR("Lock Layer 1"), false);
                    break;
                case 2:
                    oled_write_P(PSTR("Lock Layer 2"), false);
                    break;
                case 3:
                    oled_write_P(PSTR("Lock Layer 3"), false);
                    break;
                default:
                    oled_write_P(PSTR("Lock Layer ?"), false);    // Should never display, here as a catchall
            }
            oled_set_cursor(8,3);
            if (get_highest_layer(layer_state) == selected_layer) {
                oled_write_P(PSTR("            "), false);
            } else {
                switch (get_highest_layer(layer_state)) {
                    case 0:
                        oled_write_P(PSTR("Temp Layer 0"), false);
                        break;
                    case 1:
                        oled_write_P(PSTR("Temp Layer 1"), false);
                        break;
                    case 2:
                        oled_write_P(PSTR("Temp Layer 2"), false);
                        break;
                    case 3:
                        oled_write_P(PSTR("Temp Layer 3"), false);
                        break;
                    default:
                        oled_write_P(PSTR("Temp Layer ?"), false);    // Should never display, here as a catchall
                }
            }
            led_t led_state = host_keyboard_led_state();
            oled_set_cursor(8,0);
            oled_write_P(led_state.scroll_lock ? PSTR("SCRLK") : PSTR("     "), false);
            oled_set_cursor(8,1);
            oled_write_P(led_state.num_lock ? PSTR("NLCK ") : PSTR("     "), false);
            oled_write_P(led_state.caps_lock ? PSTR("CAPS ") : PSTR("     "), false);
        }
    }
#endif




	