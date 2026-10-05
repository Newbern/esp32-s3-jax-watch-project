#include "app.h"

void app_setup(){
    // Display Setup
    display_setup();
    //settings_setup();
    // Custom System setup
    startup_setup();
    // Main Menu Setup
    app_manager_setup();
    //test_setup();
    // Touch Setup
    touch_setup();
    // Running Startup system
    startup_run();
}


void app_run(){
    // Running Main Menu
    TouchPoint pressed = touch_run();
    
    // if (pressed.pressed) {
    //     app_manager_run(pressed);
    // }
    app_manager_run(pressed);
    
    
}