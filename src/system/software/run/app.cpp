#include "app.h"


void app_setup(){
    // Serial Setup
    Serial.begin(115200);
    delay(500);

    // Hardware setup
    source = "System";
    location = "Display";
    display_setup();
    location = "Startup";
    startup_setup(); // Contains Wire.begin() for I2C communication & other startup hardware setups
    location = "Touch";
    touch_setup();

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