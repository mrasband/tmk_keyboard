static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0 (Default, Main Keymap)
    KEYMAP(
        // Left
        ESC,    1,      2,      3,      4,      5,      MINS,
        GRV,    Q,      W,      E,      R,      T,      FN1, 
        FN4,    A,      S,      D,      F,      G,
        FN5,    Z,      X,      C,      V,      B,      FN2,
        LCTL,   LALT,   BSLS,   LEFT,   RGHT,
                                                LGUI,   HOME,
                                                        END,
                                        BSPC,   SPC,    FN0,
        // Right
        EQL,    6,      7,      8,      9,      0,      BSLS,
        RBRC,   Y,      U,      I,      O,      P,      QUOT,
                H,      J,      K,      L,      SCLN,   MINS,
        FN3,    N,      M,      COMM,   DOT,    SLSH,   RSFT,
                        LEFT,   UP,     DOWN,   RGHT,   RCTL,
        RGUI,   RALT,
        PGUP,
        PGDN,   ENT,    SPC
    ),

    // Layer 1 (Function and Media Keys)
    KEYMAP(
        // Left
        ESC,    F1,     F2,     F3,     F4,     F5,     F6,
        NO,     NO,     NO,     NO,     NO,     NO,     TRNS, 
        NO,     NO,     NO,     NO,     NO,     NO,
        TRNS,   NO,     NO,     NO,     NO,     NO,     NO,
        NO,     NO,     NO,     NO,     NO,
                                                NO,     HOME,
                                                        END,
                                        BSPC,   DEL,    TRNS,
        // Right
        F7,     F8,     F9,     F10,    F11,    F12,    PSCR,
        NO,     NO,     NO,     NO,     NO,     NO,     VOLU,
                NO,     NO,     UP,     NO,     NO,     VOLD,
        NO,     NO,     LEFT,   DOWN,   RIGHT,  NO,     MUTE,
                        MPRV,   MSTP,   MPLY,   MNXT,   NO,
        RALT,   RCTL,
        PGUP,
        PGDN,   ENT,    SPC
    ),

    // Layer 2 (Programming Keys)
    KEYMAP(
        // Left
        ESC,    F1,     F2,     F3,     F4,     F5,     F6,
        NO,     NO,     NO,     NO,     NO,     NO,     NO, 
        NO,     NO,     NO,     NO,     NO,     NO,
        TRNS,   NO,     NO,     NO,     NO,     NO,     NO,
        NO,     NO,     NO,     NO,     NO,
                                                NO,     HOME,
                                                        END,
                                        BSPC,   DEL,    TRNS,
        // Right
        F7,     F8,     F9,     F10,    F11,    F12,    NO,
        NO,     EQL,    LBRC,   RBRC,   FN6,    FN7,    NO,
                MINS,   FN2,    FN3,    SLSH,   BSLS,   NO,
        NO,     NO,     NO,     NO,     NO,     NO,     NO,
                        NO,     NO,     NO,     NO,     NO,
        RALT,   RCTL,
        PGUP,
        PGDN,   ENT,    SPC
    )
};

enum function_id
{
    TEENSY_KEY
};

const uint16_t PROGMEM fn_actions[] =
{
    ACTION_LAYER_TAP_KEY(2, KC_DEL),        // Layer2 on hold, del on tap
    ACTION_LAYER_TAP_KEY(1, KC_LBRC),       // Layer1 on Hold, Left Bracket on Tap
    ACTION_MODS_KEY(MOD_LSFT, KC_9),        // Open Paren
    ACTION_MODS_KEY(MOD_LSFT, KC_0),        // Close Paren
    ACTION_MODS_TAP_KEY(MOD_LCTL, KC_TAB),  // Control on hold, Tab on tap
    ACTION_MODS_ONESHOT(MOD_LSFT),          // Normal shift on hold, toggle on for 1 sequential key on tap
    ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),     // Open Brace
    ACTION_MODS_KEY(MOD_LSFT, KC_RBRC)      // Close Brace
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
