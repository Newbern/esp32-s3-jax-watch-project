#include "app.h"


void app_setup(){
    // Hardware setup
    source = "System";
    hardware_settings_setup();

    startup_setup();

    // System startup 
    location = "Storage";
    jax_storage_setup();
    startup_run();

    // Software setup
    location = "Application Manager";
    app_manager_setup();
    wake();
}


void app_run(){
    // Running Main Menu
    TouchPoint pressed = touch_run();
    
    if (pressed.pressed) {
        location = "Application Manager";
        app_manager_run(pressed);
    }
    
}