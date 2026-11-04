//
// Created by berke on 11/4/2026.
//

#ifndef KEDY_GLOBALS_H
#define KEDY_GLOBALS_H

#include "headers/fenster.h"

typedef struct fenster fenster;

extern fenster f;

#if defined(_MSC_VER)
#define FORCE_INLINE __forceinline
#elif defined(__GNUC__) || defined(__clang__)
#define FORCE_INLINE inline __attribute__((always_inline))
#else
#define FORCE_INLINE inline
#endif

#define bool _Bool
#define true 1
#define false 0

#endif //KEDY_GLOBALS_H