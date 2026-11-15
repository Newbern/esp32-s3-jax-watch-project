#ifndef APP_H
#define APP_H

/*----------HARDWARE DRIVERS----------*/
#include "system/hardware/display/display.h"
#include "system/hardware/touch/touch.h"

/*----------HARDWARE INITIALIZATION---------- 
This setups the hardware settings for the system, 
Includes: -> Serial, Display, Wire, and Touch.
*/
#include "system/hardware/settings/settings.h"

/*----------SYSTEM HARDWARE----------*/
#include "system/hardware/clock/clock.h"
#include "system/hardware/power/power.h"
#include "system/hardware/wifi/wifi.h"  


/*----------SOFTWARE MODULES----------*/
#include "system/software/functions/functions.h"
#include "system/software/logs/logs.h"
#include "media/images.h"


/*----------FUNCTIONS----------*/


// Settings
void hardware_settings_setup();

// App setup
void app_setup();
void app_run();

// Storage
void jax_storage_setup();

// Startup
void startup_setup();
void startup_run();

// WIFI
bool wifi_setup();

// Application Manager
void app_manager_setup();
void app_manager_run(TouchPoint pressed);
void open_app(TouchPoint pressed, int app_id);
void return_to_menu();


#endif