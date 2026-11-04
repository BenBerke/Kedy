#include <stdio.h>

#include "../headers/renderer.h"
#include "../headers/input_manager.h"

int main(void) {
    fenster_open(&f);

    uint32_t t = 0;
    int64_t now = fenster_time();
    while (!fenster_loop(&f)) {
        im_update();

        if (im_get_key_down(KC_A)) printf("A pressed");

        for (int i = 0; i < FW; i++) {
            for (int j = 0; j < FH; j++) {
                r_set_pixel(i, j, COLOR_RED);
            }
        }

        const int64_t time = fenster_time();
        if (time - now < 1000 / 60) fenster_sleep(time - now);
        now = time;
    }

    fenster_close(&f);
    return 0;
}