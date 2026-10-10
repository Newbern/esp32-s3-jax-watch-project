#include "startup.h"

void startup_setup() {
    // Wire Setup
    print("System | Startup | Initializing");

    // Running Wire
    if (Wire.begin(I2C_SDA, I2C_SCL))
    {
        print("System | Startup | Wire: Successful\n");
    }

    else
    {
        print("System | Startup | Wire: Failed\n");
    }
    

    

    if (!gfx->begin())
    {
        Serial.println("System | Startup | Error: gfx->begin() failed!");
        while (1);
    }
    
}

// void startup_run(){
//     clear();
//     say("Steven Newbern", 50, 100, RED, 4);
//     delay(2000);
//     clear();
// }

void startup_run() {
    // Getting Screen Dimensions
    int screen_w = gfx->width();
    int screen_h = gfx->height();

    // Getting Spacers & Outside Spaces
    int spacer = 10;
    int outside = 25;

    // Setting Width & Height
    int w = (screen_w - spacer * 2 - outside * 2);
    int h = (screen_h - spacer * 3 - outside * 2);

    // Setting Coordinates
    int x = outside;
    int y = outside;

    clear();

    say("Steven Newbern", x, y, w, h, RED, 4);
    
    if (wifi.setup()) {
    say("WiFi Connected", x, y + 50, w, h, GREEN, 4);
    }
    else {
        say("WiFi Failed", x, y + 50, w, h, RED, 4);
    }

    delay(2000);

    clear();
}