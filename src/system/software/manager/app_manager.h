#ifndef APP_MANAGER_H
#define APP_MANAGER_H

// UI
#include "system/software/ui/menu/menu.h"
//#include "system/software/launcher/launcher.h"

// Apps
#include "apps/apps.h"

//#pragma once

extern int current_app;

enum AppID {
    APP_MENU = 0,
    APP_LAUNCHER = 1,
    APP_SETTINGS = 2,
    APP_ALARMS = 3,
    APP_CLOCK = 4,
    APP_INTERNET = 5,
    APP_ROKU = 6,
    APP_TEST_APP = 7
};

struct AppEntry {
    int id;
    const char* name;
    uint16_t color;
    void (*setup)();
    void (*run)(TouchPoint pressed);
};

extern AppEntry apps_list[];
extern const int app_count;


void app_manager_setup();
void app_manager_run(TouchPoint pressed);
void open_app(TouchPoint pressed, int app_id);
void return_to_menu();

#endif