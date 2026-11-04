//
// Created by berke on 11/4/2026.
//

#include "../globals.h"
#include "../headers/simulator.h"

#include "../headers/renderer.h"

#define get_n bb[(x) + (y - 1) * FW]
#define get_s bb[(x) + (y + 1) * FW]
#define get_w bb[(x - 1) + (y) * FW]
#define get_e bb[(x + 1) + (y) * FW]
#define get_nw bb[(x - 1) + (y - 1) * FW]
#define get_ne bb[(x + 1) + (y - 1) * FW]
#define get_sw bb[(x - 1) + (y + 1) * FW]
#define get_se bb[(x + 1) + (y + 1) * FW]

#define ex_s (y + 1 < FH) // exists south
#define ex_n (y - 1 >= 0)
#define ex_e (x + 1 < FW)
#define ex_w (x - 1 >= 0)

#define mov_n mov_pixel(x, y, x, y - 1)
#define mov_s mov_pixel(x, y, x, y + 1)
#define mov_e mov_pixel(x, y, x + 1, y)
#define mov_w mov_pixel(x, y, x - 1, y)

#define mov_nw mov_pixel(x, y, x - 1, y - 1)
#define mov_ne mov_pixel(x, y, x + 1, y - 1)
#define mov_sw mov_pixel(x, y, x - 1, y + 1)
#define mov_se mov_pixel(x, y, x + 1, y + 1)

#define randd ((x + y) & 1)

FORCE_INLINE bool pix_free(const color c) {
    return c == AIR;
}

FORCE_INLINE void mov_pixel(const int src_x, const int src_y, const int dest_x, const int dest_y) {
    bb[dest_x + dest_y * FW] = bb[src_x + src_y * FW];
    bb[src_x + src_y * FW] = AIR;
}

FORCE_INLINE void sim_sand(const int x, const int y) {
    if (ex_s) {
        if (get_s == AIR) mov_s;
        else {
            bool left_free = ex_w && pix_free(get_sw);
            bool right_free = ex_e && pix_free(get_se);

            if (left_free && right_free) {
                if (randd) mov_sw;
                else mov_se;
            }
            else if (right_free) mov_se;
            else if (left_free) mov_sw;
        }
    }
}

void s_run() {
    for (int y = FH - 1; y >= 0; y--) {
        for (int x = 0; x < FW; x++) {
            switch (bbcord) {
                case AIR: break;
                case SAND: sim_sand(x, y); break;
                case STONE: break;
                default: break;;
            }
        }
    }
}