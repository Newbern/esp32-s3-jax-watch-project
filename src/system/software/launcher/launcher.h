#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "system/software/run/app.h"

void launcher_setup();
void launcher_run(TouchPoint pressed);
void nothing();

extern int selected_app;

#endif