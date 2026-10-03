#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "apps/app.h"

void launcher_setup();
void launcher_run(TouchPoint pressed);
void nothing();

struct App {
    const char* name;
    const u_int16_t color;
    void (*run)();
};

extern App apps[];
extern int selected_app;

#endif