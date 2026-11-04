#define FENSTER_IMPL

#include <stdio.h>

#include "../headers/renderer.h"
#include "../headers/input_manager.h"
#include "../headers/simulator.h"

int main(void) {
    fenster_open(&f);

    r_set_pixel(100, 100, rgbcolor(255, 255, 0));

    uint32_t t = 0;
    int64_t now = fenster_time();
    while (!fenster_loop(&f)) {
        im_update();

        if (im_get_key_down(KC_A)) printf("A pressed");

        r_clear();

        r_set_pixel(100, 100, SAND);

        s_run();

        r_present();

        const int64_t time = fenster_time();
        //if (time - now < 1000 / 60) fenster_sleep(1000 / 60 - (time - now));
        now = time;
    }

    fenster_close(&f);
    return 0;
}