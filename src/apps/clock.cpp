#include "app.h"

void time_setup() {
    clock_setup();
}

void time_run() {
    say(clock_run(), 0, 0, WHITE, 24);
}