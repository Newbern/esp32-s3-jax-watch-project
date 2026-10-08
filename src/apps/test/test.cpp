#include "apps/apps.h"

void test_setup() {
    print("Test App Setup\n");
}

void test_run(TouchPoint pressed) {
    int screen_w = gfx->width();
    say("TEST APP", 0, 50, screen_w, 40, WHITE, 4);
    say("Screen is working!", 0, 150, screen_w, 30, GREEN, 2);
    say("Touch to return", 0, 250, screen_w, 30, CYAN, 2);
    // if (pressed.pressed) {
    //     return_to_menu();
    // }
}