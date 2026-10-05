#ifndef MENU_H
#define MENU_H

// ----------HELPERS----------//
#include "system/software/run/app.h"

// ----------BUTTONS----------//
#include "system/software/launcher/launcher.h"

void menu_setup();
void menu_layout();
void menu_run(TouchPoint pressed);
void show_date(const char* text, Button* button);

#endif
