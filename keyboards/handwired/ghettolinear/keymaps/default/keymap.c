#include QMK_KEYBOARD_H
#include "oled.c"

// [Init Variables] ----------------------------------------------------------//

// Special portuguese letters
enum unicode_names {
    CEDILHA_B,
    CEDILHA_A,
    SNEK
};

const uint32_t PROGMEM unicode_map[] = {
    [CEDILHA_B]  = 0x00E7,  // ç U+00E7
    [CEDILHA_A] = 0x00C7,  // Ç 00C7
    [SNEK]  = 0x1F40D, // 🐍
};

#define BR_CEDILHA XP(0, 1)


// Tap Dance declarations
enum {
    TD_DOT_COMMA = 0
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_DOT_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMMA),
};

//



// Preenchimento para facilitar legibilidade 
// Just for legibility 
#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

// [Layer Keymaps] -----------------------------------------------------------//

//Layers
enum {
  _BA = 0,
  _FC
};

//13 characters max without re-writing the "Layer: " format in iota_gfx_task_user()
//static char layer_lookup[][14] = {"Base","Funcoes"};

/* ghettolinear - Default
  * Primeira Linha - Layer Principal ML 
  * Segunda Linha - Layer Secundario FN
      * ,------------------------------------------------\		    /------------------------------------------------.
      * |  ESC  |  1  |   2  |   3  |   4  |   5  |   6  |		    |   7  |   8  |   9  |   0  |   -  |  =   | Bksp |
      * |       |  F1 |   F2 |   F3 |   F4 |   F5 |      |		    |   7  |   8  |   9  |      |  F10 | F11  |Delete|
      * |-------------+------+------+------+------+------+		  	+------+------+------+------+------+------+------+
      * | Tab   |  Q  |   W  |   E  |   R  |   T  |	 [{  |		  	|   Y  |   U  |   I  |   O  |   P  |  '"  |   |  |
      * |       |     |      |      |      |      |	  	 |		  	|   4  |   5  |   6  |      |      |      |   \  |
      * |-------+-----+------+------+------+-------------+		    +------+------+------+------+------+------+------+
      * | CAPS  |  A  |   S  |   D  |   F  |   G  |	'  " |		  	|   H  |   J  |   K  |   L  |   ç  |      | Enter|
      * |       |     |      |      |      |      |		   |		    |	  1  |   2  |   3  |   +  |      |      |      |
      * |-------+-----+------+------+------+------|------+		  	+------+------+------+------+------+------+------+
      * | Shift |  Z  |   X  |   C  |   V  |   B  |   <  |        |   N  |   M  |  .;  |  .>  |  :;  |  UP  |  /?  |
      * |       |     |      |      |      |      |	  	 |			  |   0  |   .  |  ,   |      |      | PGUp |      |
      * |-------+-----+------+------+------+------+------+		   	+------+------+------+------+------+------+------+
      * | Lctrl | _FC | LAlt | DEL  | BKSP |    Space    |        |    Space    | Ralt | _FN  | Left | Down | Right|
      * |       |     |      |      |      |             |        |    BKSP     |      |      |      | PGDw |      |
      * `------------------------------------------------/			  \------------------------------------------------/
      */



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BA] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,     KC_5,    KC_6,             KC_7,    KC_8,    KC_9,        KC_0,           KC_MINS,   KC_EQUAL, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,     KC_T,    KC_LBRC,          KC_Y,    KC_U,    KC_I,        KC_O,           KC_P,      KC_QUOTE, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,     KC_G,    KC_QUOTE,         KC_H,    KC_J,    KC_K,        KC_L,           BR_CEDILHA,KC_ENTER, KC_ENTER,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,     KC_B,    KC_LABK,          KC_N,    KC_M,    KC_SCOLON,   TD_DOT_COMMA,   KC_SLSH,   KC_UP,    KC_SLASH,
        KC_LCTL, MO(_FC), KC_LALT, KC_DEL, KC_BSPC,  XXXXXXX, KC_SPC,           KC_SPC,  XXXXXXX, MO(_FC),     KC_LALT,        KC_LEFT,   KC_DOWN,  KC_RGHT
    ),
    [_FC] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  			    KC_TAB, KC_SLASH, KC_PAST,      KC_KP_MINUS,   KC_F11,     KC_F12, KC_DEL,
        _______, _______, _______, _______, KC_PAST, KC_PSLS, _______,          KC_KP_4, KC_KP_5, KC_KP_6,      KC_KP_PLUS,    _______,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          KC_KP_1, KC_KP_2, KC_KP_3,      KC_PEQL,       _______,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          KC_KP_0, KC_KP_0, TD_DOT_COMMA, KC_KP_ENTER,   _______,    KC_PGUP, _______,
        _______, _______, _______, _______, _______, XXXXXXX, _______,          KC_BSPC, XXXXXXX, _______,      _______,       KC_HOME,    KC_PGDN, KC_END
    )
};


	