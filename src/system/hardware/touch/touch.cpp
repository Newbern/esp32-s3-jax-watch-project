#include "touch.h"
#include "system/software/run/app.h"
#include "system/software/functions/functions.h"

// Touch Screen Setup
TouchDrvFT6X36 touch;
bool touchReady = true;
unsigned long lastTouch = 0;

// Wire Setup
void wire_setup() {
    log("Initializing");

    // Running Wire
    if (Wire.begin(I2C_SDA, I2C_SCL))
    { 
        log("Wire: Successful\n");
    }
    
    else
    { 
        log("Wire: Failed\n"); 
    }
    
}

// Touch Screen Setup
void touch_setup() {
    log("Initializing");
    // Connecting to the touch screen using the Wire library, this is the bus that the touch screen uses to communicate with the microcontrollar
    touchReady = touch.begin(Wire);
    
    // Checking if the touch screen is ready and printing the result to the serial monitor
    if (!touchReady) {
        log("Touch Ready", "Failed\n");
    } else {
        log("Touch Ready", "Success\n");
    }

    
    wake(); // Wake the display on startup
    lastTouch = millis(); // Record the last time the display was touched

}

// Touch Screen Run Function
TouchPoint touch_run()
{
    // Release pointer 
    static bool waitingForRelease = false;

    // Createing Point
    TouchPoint point = {false, 0, 0};

    // Touch screen is not ready 
    if (!touchReady)
        return point;
    
    // Checking if the touch screen is pressed
    bool pressed = touch.isPressed();

    // Resetting  when point is released
    if (!pressed) {
        waitingForRelease = false;
    }
    
    // Processing only the first touch
    else if (!waitingForRelease)
    {
        // Getting Position
        int16_t x[1];
        int16_t y[1];


        // Returning active postion if its actually being presseed
        if (touch.getPoint(x, y) > 0)
        {   // Ignore if the touch is still being pressed
            waitingForRelease = true;
            // Waking Display Screen
            wake();

            // Returning pressed & pointer positions
            point.pressed = true;
            point.x = x[0];
            point.y = y[0];

            // Recording last time pointer was touched
            lastTouch = millis();
        }
    }

    // Getting curent time and checking with past time
    if (millis() - lastTouch > 5000)
    {
        // Turning Display Off
        sleep();
    }

    // Returning pointer values
    return point;
}

