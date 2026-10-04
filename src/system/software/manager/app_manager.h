#ifndef APP_MANAGER_H
#define APP_MANAGER_H

#pragma once

#include "system/software/launcher/launcher.h"


struct AppEntry {
    const char* name;
    uint16_t color;
    void (*setup)();
    void (*run)(TouchPoint pressed);
};

extern AppEntry apps_list[];
extern const int app_count;


void app_manager_setup();
void app_manager_run(TouchPoint pressed);
void open_app(int app_id);
void return_to_menu();

#endif