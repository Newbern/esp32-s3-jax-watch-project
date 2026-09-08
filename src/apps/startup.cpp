#include "app.h"
#include "media/logo.h"

void startup_setup() {
    // Wire Setup
    Wire.begin(I2C_SDA, I2C_SCL);

    Serial.println("Starting Display...");

    if (!gfx->begin())
    {
        Serial.println("gfx->begin() failed!");
        while (1);
    }
    
}

void startup_run(){
    clear();
    say("Steven Newbern", 50, 100, RED, 4);
    delay(2000);
}