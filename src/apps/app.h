#ifndef APP_H
#define APP_H

/*----------LIBS----------*/
#include "functions/functions.h"
#include "clock/clock.h"
#include "power/power.h"
//#include "wifi/wifi.h"
#include "settings/settings.h"

/*----------FUNCTIONS----------*/
// Serial
void serial_setup();
void serial_run();

// App setup
void app_setup();
void app_run();

// Startup
void startup_setup();
void startup_run();

// Menu
void menu_setup();
void menu_run();
void menu_backend();

// WIFI
void wifi_setup();
void api_test();

// Test
void test_setup();
void test_run();

#endif