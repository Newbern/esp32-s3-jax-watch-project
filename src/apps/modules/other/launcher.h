#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "apps/app.h"

void launcher_setup();
void launcher_run();

struct App {
    const char* name;
    const u_int16_t color;
    void (*run)();
};

App apps[] = {
    {"Alarm", RED, nothing},
    {"Clock", BLUE, nothing},
    {"Weather", GREEN, nothing},
};

int selected_app = 0;

#endif