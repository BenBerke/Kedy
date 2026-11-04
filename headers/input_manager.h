//
// Created by berke on 11/4/2026.
//

#ifndef KEDY_INPUT_MANAGER_H
#define KEDY_INPUT_MANAGER_H

#include "../globals.h"

#define bool _Bool
#define true 1
#define false 0

extern bool has_key;
extern bool prev_key_states[128];
extern bool key_states[128];

#define KEYDOWN key_states[k]
#define PREVKEYDOWN prev_key_states[k]

typedef enum Keycode {
    KC_A = 'A',
    KC_B = 'B',
    KC_C = 'C',
    KC_D = 'D',
    KC_E = 'E',
    KC_F = 'F',
    KC_G = 'G',
    KC_H = 'H',
    KC_I = 'I',
    KC_J = 'J',
    KC_K = 'K',
    KC_L = 'L',
    KC_M = 'M',
    KC_N = 'N',
    KC_O = 'O',
    KC_P = 'P',
    KC_Q = 'Q',
    KC_R = 'R',
    KC_S = 'S',
    KC_T = 'T',
    KC_U = 'U',
    KC_V = 'Y',
    KC_W = 'W',
    KC_X = 'X',
    KC_Y = 'Y',
    KC_Z = 'Z',
    KC_SPACE = ' ',
} Keycode;

FORCE_INLINE void im_update() {
    has_key = false;
    memcpy(prev_key_states, key_states, 128 * sizeof(char));
    for (int i = 0; i < 128; i++) {
        key_states[i] = false;
        if (f.keys[i]) {
            has_key = true;
            key_states[i] = true;
        };
    }
}
FORCE_INLINE bool im_get_key(const Keycode k) { return KEYDOWN; }
FORCE_INLINE bool im_get_key_down(const Keycode k) { return (KEYDOWN && !PREVKEYDOWN); }
FORCE_INLINE bool im_get_key_up(const Keycode k) { return (PREVKEYDOWN && !KEYDOWN); }

#endif //KEDY_INPUT_MANAGER_H