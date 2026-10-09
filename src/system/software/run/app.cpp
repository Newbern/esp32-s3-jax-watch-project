#include "app.h"

void app_setup(){
    // Hardware setup
    display_setup();
    startup_setup(); // Contains Wire.begin() for I2C communication & other startup hardware setups
    touch_setup();

    // System startup 
    
    startup_run();

    // Software setup
    app_manager_setup();
    wake();
}


void app_run(){
    // Running Main Menu
    TouchPoint pressed = touch_run();
    
    if (pressed.pressed) {
        app_manager_run(pressed);
    }
    // app_manager_run(pressed);
    
    
}