#include "app.h"

void app_setup(){
    // Serial Setup
    serial_setup();
    // Display Setup
    display_setup();
    
    // Custom System setup
    startup_setup();
    // Main Menu Setup
    menu_setup();
    // Touch Setup
    touch_setup();
    // WIFI Setup
    //wifi_setup();
    // Running Startup system
    startup_run();
}


void app_run(){
    // Running Main Menu
    //touch_run(menu_run);
    //touch_run(test_run);
    test_run();

}