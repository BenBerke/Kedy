//
// Created by berke on 11/4/2026.
//

#ifndef KEDY_SIMULATOR_H
#define KEDY_SIMULATOR_H

typedef enum PixelColorValues {
    AIR = 0,
    SAND = rgbcolor(255, 255, 0),
    STONE = rgbcolor(120, 120, 120),
} PixelColorValues;

typedef PixelColorValues pcv;

void s_run();

#endif //KEDY_SIMULATOR_H