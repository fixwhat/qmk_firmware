#include QMK_KEYBOARD_H
#include "keymap_us_international.h"


// Oled para testes
// Oled para testes
// [Init Variables] ----------------------------------------------------------//

// Tap Dance declarations
enum {
    DOT_COMMA = 0,
    C_C,
    V_P,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [DOT_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMMA),
    [C_C]    = ACTION_TAP_DANCE_DOUBLE(KC_C, C(KC_C)),
    [V_P]   = ACTION_TAP_DANCE_DOUBLE(KC_V, C(KC_V)),

};


// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }

    }
    return true;
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
  * Segunda Linha - Layer Secundario FN*/
 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_NUBS,          KC_1,    KC_2,    KC_3,   KC_4,     KC_5,    KC_6,            KC_7,    KC_8,    KC_9,        KC_0,           KC_MINS,   KC_EQUAL, KC_BSPC,
        KC_TAB,           KC_Q,    KC_W,    KC_E,   KC_R,     KC_T,    KC_LBRC,         KC_Y,    KC_U,    KC_I,        KC_O,           KC_P,      KC_RBRC, KC_BSLS,
        KC_LGUI,          KC_A,    KC_S,    KC_D,   KC_F,     KC_G,    KC_QUOTE,        KC_H,    KC_J,    KC_K,        KC_L,           KC_SCOLON, KC_QUOTE, KC_ENTER,
        LSFT_T(KC_CAPS),  KC_Z,    KC_X,    TD(C_C),   TD(V_P),     KC_B,    KC_LABK,   KC_N,    KC_M,    KC_COMMA,    KC_DOT,         KC_SLASH,  KC_UP,    KC_RSFT,
        KC_LCTRL,  MO(_FC), TO(1),   KC_LALT,KC_BSPC,  XXXXXXX, LCTL_T(KC_SPC),          LGUI_T(KC_SPC),  XXXXXXX, MO(_FC),     KC_LALT,        KC_LEFT,   KC_DOWN,  KC_RGHT
    ),
    [1] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                    KC_F7,   KC_F8,    KC_F9,          KC_KP_MINUS,   KC_F11,     KC_F12, _______,
        _______, _______, _______, _______, KC_PAST, KC_PSLS, _______,                  KC_KP_7, KC_KP_8,  KC_KP_9,        KC_KP_PLUS,    _______,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                  KC_KP_4, KC_KP_5,  KC_KP_6,        KC_PEQL,       _______,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                  KC_KP_1, KC_KP_2,  KC_KP_3,        _______,       _______,    KC_PGUP, RESET,
        _______, _______, TO(0),   _______, _______, XXXXXXX, _______,                  KC_KP_0, XXXXXXX,  TD(DOT_COMMA),  _______,       KC_HOME,    KC_PGDN, KC_END
    )
};

// 

// OLED Rotation enum values are flags

#ifdef OLED_DRIVER_ENABLE   // OLED Functionality
    uint8_t selected_layer = 0;
    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        return OLED_ROTATION_90;    
    }


// se for WIDHT=4 a fonte aqui tem que ser 8 na linha 32
 // used to manage singular screen clears to prevent display glitch
// se for WIDHT=5 a fonte aqui tem que ser 6 na linha 30
 // se for WIDHT=6 a fonte aqui tem que ser 5 na linha 30
// se for WIDHT=7 a fonte aqui tem que ser 4 na linha 28
// se for WIDHT=8 a fonte aqui tem que ser 4 na linha 32
    bool clear_screen = false;          
    static void render_name(void) {     
       static const char PROGMEM ghetto_name[] = {
       0x80,0x81, 0x82,0x83, 0x20,0x20, 0x20,0x20,
       0xA0,0xA1, 0xA2,0xA3, 0x20,0x20, 0x20,0x20, 
       0xC0,0xC1, 0xC2,0xC3, 0x20,0x20, 0x20,0x20, 
       0xE0,0xE1, 0xE2,0xE3, 0x20,0x20, 0x20,0x20, 
       0x84,0x85, 0x86,0x87, 0x20,0x20, 0x20,0x20,
       0xA4,0xA5, 0xA6,0xA7, 0x20,0x20, 0x20,0x20,
       0xc4,0xc5, 0xc6,0xc7, 0x20,0x20, 0x20,0x20,
       0xe4,0xe5, 0xe6,0xe7, 0x20,0x20, 0x20,0x20,
       0x88,0x89, 0x8a,0x8b, 0x8c,0x20, 0x20,0x20,
       0xA8,0xA9, 0xaa,0xab, 0xac,0x20, 0x20,0x20, 
       0xC8,0xC9, 0xCa,0xCb, 0xcc,0x20, 0x20,0x20, 
       0xE8,0xE9, 0xEa,0xEb, 0xEc,0x20, 0x20,0x20, 
       0x8e,0x8f, 0x90,0x91, 0x92,0x93, 0x20,0x20,
       0xAe,0xAf, 0xB0,0xB1, 0xB2,0xB3, 0x20,0x20,
       0xCe,0xCf, 0xD0,0xD1, 0xD2,0xD3, 0x20,0x20,

        };
        oled_write_P(ghetto_name, false);
    }


    void oled_task_user(void) {
        
        if ( IS_HOST_LED_OFF(USB_LED_NUM_LOCK) && IS_HOST_LED_OFF(USB_LED_CAPS_LOCK) && selected_layer == 0 && get_highest_layer(layer_state) == 0 ) {
                       oled_set_cursor(0,0);

            render_name();
            clear_screen = true;
        } else {
            if (clear_screen == true) {
                oled_clear();
                oled_render();
                clear_screen = false;
            }
            
            //render_logo();
            oled_set_cursor(0,13);
            switch(selected_layer){
                case 0:
                    oled_write_P(PSTR("Locked 0"), false);
                    break;
                case 1: 
                    oled_write_P(PSTR("Locked 1"), false);
                    break;
                case 2:
                    oled_write_P(PSTR("Locked 2"), false);
                    break;
                case 3:
                    oled_write_P(PSTR("Locked 3"), false);
                    break;
                default:
                    oled_write_P(PSTR("Locked ?"), false);    // Should never display, here as a catchall
            }
            oled_set_cursor(0,11);
            if (get_highest_layer(layer_state) == selected_layer) {
                oled_write_P(PSTR("        "), false);
            } else {
                switch (get_highest_layer(layer_state)) {
                    case 0:
                        oled_write_P(PSTR("  Temp 0"), false);
                        break;
                    case 1:
                        oled_write_P(PSTR("  Temp 1"), false);
                        break;
                    case 2:
                        oled_write_P(PSTR("  Temp 2"), false);
                        break;
                    case 3:
                        oled_write_P(PSTR("  Temp 3"), false);
                        break;
                    default:
                        oled_write_P(PSTR("  Temp ?"), false);    // Should never display, here as a catchall
                }
            }
            led_t led_state = host_keyboard_led_state();
            oled_set_cursor(0,7);
            oled_write_P(led_state.scroll_lock ? PSTR("SCRL    ") : PSTR("        "), false);
            oled_set_cursor(0,8);
            oled_write_P(led_state.num_lock ? PSTR("NLCK    ") : PSTR("        "), false);
            oled_write_P(led_state.caps_lock ? PSTR("CAPS    ") : PSTR("        "), false);
        }
    }
#endif



	