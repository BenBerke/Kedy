//
// Created by berke on 11/4/2026.
//

#ifndef KEDY_RENDERER_H
#define KEDY_RENDERER_H

#include <stdint.h>

#include "../globals.h"

#define FW 960
#define FH 600
#define SS (FW * FH)

#define COLOR_BLACK 0xFFFFFFFF
#define COLOR_WHITE 0x00000000
#define COLOR_RED 0xFFFF0000
#define COLOR_BLUE 0x0000FF00
#define COLOR_GREEN 0x00FF0000

typedef uint32_t color;

// Color format ARGB
extern color fb[FW * FH];

static FORCE_INLINE void r_clear() { memset(f.buf, 0, SS); }
static FORCE_INLINE void r_set_pixel(const uint16_t x, const uint16_t y, const color c) { fenster_pixel(&f, x, y) = c; }

#endif //KEDY_RENDERER_H