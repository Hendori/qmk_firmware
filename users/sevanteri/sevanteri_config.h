#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define TAPPING_TERM 200
/* #define TAPPING_TERM_PER_KEY */
#define TAPPING_FORCE_HOLD

#ifdef PERMISSIVE_HOLD
#undef PERMISSIVE_HOLD
#endif
#define PERMISSIVE_HOLD_PER_KEY

#ifdef IGNORE_MOD_TAP_INTERRUPT
#undef IGNORE_MOD_TAP_INTERRUPT
#endif
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define LAYER_STATE_8BIT

// COMBOS
#ifdef COMBO_TERM
#undef COMBO_TERM
#undef COMBO_MOD_TERM
#endif

#define COMBO_STRICT_TIMER
#define COMBO_TERM 25
#define COMBO_HOLD_TERM 200
#define COMBO_PROCESS_KEY_RELEASE

#define COMBO_VARIABLE_LEN
#define COMBO_PERMISSIVE_HOLD
#define COMBO_TERM_PER_COMBO
#define COMBO_MUST_TAP_PER_COMBO
/* #define COMBO_MUST_HOLD_MODS */
#define COMBO_MUST_HOLD_PER_COMBO
#define COMBO_BUFFER_LENGTH 5
#define COMBO_ONLY_FROM_LAYER 0
