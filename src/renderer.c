//
// Created by berke on 11/4/2026.
//

#define FENSTER_HEADER
#include "../headers/renderer.h"

color fb[FW * FH];

fenster f = {
    .title = "Kedy",
    .width = FW,
    .height = FH,
    .buf = fb
};