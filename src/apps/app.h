#ifndef APP_H
#define APP_H


/*----------HELPERS----------*/
#include "hardware/display/display.h"
#include "media/images.h"
#include "functions/functions.h"

/*----------HARDWARE----------*/
#include "hardware/clock/clock.h"
#include "hardware/power/power.h"
#include "hardware/wifi/wifi.h"
#include "hardware/storage/storage.h"

/*----------MODULES----------*/
//#include "apps/settings/settings.h"
//#include "apps/modules/other/other_apps.h"

/*----------FUNCTIONS----------*/
// Serial
void serial_setup();
void serial_run();

// Settings
void settings_setup();

// App setup
void app_setup();
void app_run();

// Startup
void startup_setup();
void startup_run();

// Menu
void menu_setup();
void menu_run(TouchPoint pressed);
// void menu_backend();

// WIFI
bool wifi_setup();
void api_test();

// Jax
// System/Battery
//Clock/calender
//weather

// Other Apps
void launcher_setup();
void launcher_run(TouchPoint pressed);

#endif