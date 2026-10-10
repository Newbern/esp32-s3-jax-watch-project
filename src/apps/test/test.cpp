#include "apps/apps.h"

void test_setup() {
    clear_print();
    print("System | Test | Setup: Initializing");
}

void test_run(TouchPoint pressed) {
    int screen_w = gfx->width();
    say("TEST", 0, 50, screen_w, 40, WHITE, 4);
    say("Screen is working!", 0, 150, screen_w, 30, GREEN, 2);
    say("Touch to return", 0, 250, screen_w, 30, CYAN, 2);
    timeout();
    if (pressed.pressed) {
        return_to_menu();
    }
}