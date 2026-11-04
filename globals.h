//
// Created by berke on 11/4/2026.
//

#ifndef KEDY_GLOBALS_H
#define KEDY_GLOBALS_H

#ifndef FENSTER_IMPL
#define FENSTER_HEADER
#endif
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

#define FW 960
#define FH 600
#define SS (FW * FH)

#define bufcord f.buf[x + y * FW]
#define bbcord bb[x + y * FW]
#define rgbcolor(r, g, b) (0xFF000000 | ((r) << 16) | ((g) << 8) | (b))

#define printl(fmt,...) printf(fmt "\n", ##__VA_ARGS__);

#endif //KEDY_GLOBALS_H