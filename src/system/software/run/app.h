#ifndef APP_H
#define APP_H


/*----------HELPERS----------*/
#include "system/hardware/display/display.h"
#include "media/images.h"
#include "system/software/functions/functions.h"

/*----------HARDWARE----------*/
#include "system/hardware/clock/clock.h"
#include "system/hardware/power/power.h"
#include "system/hardware/wifi/wifi.h"
#include "system/hardware/storage/storage.h"

/*----------MODULES----------*/
//#include "apps/settings/settings.h"
//#include "apps/modules/other/other_apps.h"
//#include "system/software/launcher/launcher.h"

/*----------FUNCTIONS----------*/
// Settings
//void settings_setup();

// App setup
void app_setup();
void app_run();

// Startup
void startup_setup();
void startup_run();

// WIFI
bool wifi_setup();

// Application Manager
void app_manager_setup();
void app_manager_run(TouchPoint pressed);
void open_app(int app_id);
void return_to_menu();


#endif