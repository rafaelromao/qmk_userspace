#include "select_word.h"

select_word_t select_word = {.state = STATE_NONE};

process_record_result_t process_select_word(uint16_t keycode, keyrecord_t* record) {
    bool isMacOS = is_macos();

    if ((keycode == MC_SELW || keycode == MC_SELL) && record->event.pressed) {
        if (keycode == MC_SELL || select_word.state == STATE_LINE_SELECTED) {
            // Select Line
            if (select_word.state == STATE_NONE) {
                tap_code(KC_HOME);
                tap_code(KC_HOME);
                register_mods(MOD_LSFT);
                wait_ms(30);
                tap_code(KC_DOWN);
                select_word.state = STATE_FIRST_LINE;
            } else {
                register_mods(MOD_LSFT);
                tap_code(KC_DOWN);
                select_word.state = STATE_LINE;
            }
        } else {
            // Select Word
            if (isMacOS) {
                register_code(KC_LALT);
            } else {
                register_code(KC_LCTL);
            }
            if (select_word.state == STATE_NONE) {
                tap_code(KC_LEFT);
                tap_code(KC_RIGHT);
            }
            register_mods(MOD_LSFT);
            register_code(KC_LEFT);
            select_word.state = STATE_WORD;
        }
        return PROCESS_RECORD_RETURN_FALSE;
    }

    switch (select_word.state) {
        case STATE_WORD:
            unregister_code(KC_LEFT);
            unregister_mods(MOD_LSFT);
            if (isMacOS) {
                unregister_code(KC_LALT);
            } else {
                unregister_code(KC_LCTL);
            }
            select_word.state = STATE_WORD_SELECTED;
            break;

        case STATE_FIRST_LINE:
        case STATE_LINE:
            unregister_mods(MOD_LSFT);
            select_word.state = STATE_LINE_SELECTED;
            break;

        case STATE_WORD_SELECTED:
            if (keycode != MC_SELW && record->event.pressed) {
                unregister_mods(MOD_LSFT);
                tap_code(KC_LEFT);
                select_word.state = STATE_NONE;
                return PROCESS_RECORD_CONTINUE;
            }
        case STATE_LINE_SELECTED:
            if (keycode != MC_SELW && record->event.pressed) {
                unregister_mods(MOD_LSFT);
                select_word.state = STATE_NONE;
                return PROCESS_RECORD_CONTINUE;
            }
        default:
            select_word.state = STATE_NONE;
    }

    return PROCESS_RECORD_CONTINUE;
}
