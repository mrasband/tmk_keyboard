static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0 (Default, Main Keymap)
    KEYMAP(
        // Left
        ESC,    1,      2,      3,      4,      5,      6,
        BSLS,   QUOT,   COMM,   DOT,    P,      Y,      FN1, 
        TAB,    A,      O,      E,      U,      I,
        LSFT,   SCLN,   Q,      J,      K,      X,      FN2,
        LCTL,   GRV,    BSLS,   LEFT,   RGHT,
                                                LALT,   LGUI,
                                                        END,
                                        BSPC,   SPC,    DEL,
        // Right
        7,      8,      9,      0,      MINS,   EQL,    BSLS,
        RBRC,   F,      G,      C,      R,      L,      SLSH,
                D,      H,      T,      N,      S,      MINS,
        FN3,    B,      M,      W,      V,      Z,      RSFT,
        LEFT,   UP,     DOWN,   RGHT,   RCTL,
        RGUI,   RALT,
        PGUP,
        PGDN,   ENT,    SPC
    ),

    // Layer 1 (Function Keys and Media Keys)
    KEYMAP(
        // Left
        ESC,    F1,     F2,     F3,     F4,     F5,     F6,
        NO,     NO,     NO,     NO,     NO,     NO,     FN0, 
        NO,     NO,     NO,     NO,     NO,     NO,
        NO,     NO,     NO,     NO,     NO,     NO,     NO,
        NO,     NO,     NO,     NO,     NO,
                                                NO,     HOME,
                                                        END,
                                        BSPC,   DEL,    SPC,
        // Right
        F7,     F8,     F9,     F10,    F11,    F12,    PSCR,
        NO,     NO,     NO,     NO,     NO,     NO,     VOLU,
                NO,     NO,     NO,     NO,     NO,     VOLD,
        NO,     NO,     NO,     NO,     NO,     NO,     MUTE,
                        MPRV,   MSTP,   MPLY,   MNXT,   RGUI,
        RALT,   RCTL,
        PGUP,
        PGDN,   ENT,    SPC
    ),

    // Layer 2 (Programming Keys)
    KEYMAP(
        // Left
        ESC,    F1,     F2,     F3,     F4,     F5,     F6,
        NO,     NO,     NO,     NO,     NO,     NO,     FN0, 
        NO,     NO,     NO,     NO,     NO,     NO,
        NO,     NO,     NO,     NO,     NO,     NO,     NO,
        NO,     NO,     NO,     NO,     NO,
                                                NO,     HOME,
                                                        END,
                                        BSPC,   DEL,    SPC,
        // Right
        F7,     F8,     F9,     F10,    F11,    F12,    PSCR,
        NO,     NO,     NO,     NO,     NO,     NO,     VOLU,
                NO,     NO,     NO,     NO,     NO,     VOLD,
        NO,     NO,     NO,     NO,     NO,     NO,     MUTE,
                        MPRV,   MSTP,   MPLY,   MNXT,   RGUI,
        RALT,   RCTL,
        PGUP,
        PGDN,   ENT,    SPC
    ),

    // Layer 3 (Numpad)
    KEYMAP(
        // Left
        NO,     NO,     NO,     NO,     NO,     NO,     NO,
        NO,     NO,     UP,     NO,     NO,     NO,     NO, 
        NO,     LEFT,   DOWN,   RIGHT,  NO,     NO,
        NO,     NO,     NO,     NO,     NO,     NO,     NO,
        NO,     NO,     NO,     NO,     NO,
                                                NO,     HOME,
                                                        END,
                                        BSPC,   DEL,    SPC,
        // Right
        NO,     NO,     NLCK,   PSLS,   PAST,   NO,     NO,
        NO,     NO,     P7,     P8,     P9,     PMNS,   NO,
                NO,     P4,     P5,     P6,     PPLS,   NO,
        NO,     NO,     P1,     P2,     P3,     PENT,   NO,
                        P0,     NO,     PDOT,   NO,     RGUI,
        RALT,   RCTL,
        PGUP,
        PGDN,   ENT,    SPC
    ),
    
    // Layer 4 (Routing)
    KEYMAP(
        // Left
        NO,     NO,     NO,     NO,     NO,     NO,     NO,
        NO,     NO,     UP,     NO,     NO,     NO,     NO, 
        NO,     NO,     NO,     NO,     NO,     NO,
        NO,     NO,     NO,     NO,     NO,     NO,     NO,
        NO,     NO,     NO,     NO,     NO,
                                                NO,     NO,
                                                        NO,
                                        NO,     NO,     NO,
        // Right
        NO,     NO,     NO,     NO,     NO,     NO,   NO,
        NO,     NO,     NO,     NO,     NO,     NO,   NO,
                NO,     NO,     NO,     NO,     NO,   NO,
        NO,     NO,     NO,     NO,     NO,     NO,   NO,
                        NO,     NO,     NO,     NO,   NO,
        NO,     NO,
        NO,
        NO,     NO,    NO
    )
};

enum function_id
{
    TEENSY_KEY
};

const uint16_t PROGMEM fn_actions[] =
{
    ACTION_LAYER_MOMENTARY(1),   // FN0
    ACTION_LAYER_TAP_KEY(1, KC_LBRC), 
    ACTION_MODS_KEY(MOD_LSFT, KC_9), // Left Paren
    ACTION_MODS_KEY(MOD_LSFT, KC_0), // Right Paren
    ACTION_FUNCTION(TEENSY_KEY)
};

void action_function(keyrecord_t *event, const uint8_t id, const uint8_t opt)
{
    if (id == TEENSY_KEY)
    {
        clear_keyboard();
        _delay_ms(250);
        bootloader_jump();
    }
}
