#include "display.h"
#include "system/software/run/app.h"
#include "system/software/functions/functions.h"
/*----------HERE----------*/
/*----------SETUP----------*/
Arduino_DataBus *bus = nullptr;
Arduino_GFX *gfx = nullptr;
void display_setup() {
    // Create an instance of the Arduino_ESP32QSPI class for the display on the screen, this is the bus that the display uses to communicate with the microcontrollar
    bus = new Arduino_ESP32QSPI(
      LCD_CS /* CS */, 
      QSPI_SCL /* SCK */, 
      QSPI_SIO0 /* SDIO0 */, 
      QSPI_SI1 /* SDIO1 */,
      QSPI_SI2 /* SDIO2 */, 
      QSPI_SI3 /* SDIO3 */
    );

    // Create an instance of the Arduino_CO5300 class for the display on the screen, this is the display that is used to display graphics and text on the screen
    gfx = new Arduino_CO5300(
      bus, 
      LCD_RESET, // RST 
      0, // rotation 
      false, // IPS 
      LCD_WIDTH, // Width 
      LCD_HEIGHT, // Height
      22, // col_offset1 
      0, // row_offset1 
      0, // col_offset2 
      0 // row_offset2
    );
    print("------------------SYSTEM-RUNNING-----------------------\n\n\n\n-------------------------------------------------------\n");
    print("System | Display | Initialized");
}

// Touch Screen Setup
TouchDrvFT6X36 touch;
bool touchReady = true;
unsigned long lastTouch = 0;
bool displayOn = true;

// Display Sleep Function
void sleep() 
{
    // If the display is already off, return
    if (!displayOn)
        return;

    // Turn off the display
    gfx->displayOff();
    displayOn = false;
}

// Display Wake Function
void wake()
{
    // If the display is already on, return
    if (displayOn)
        return;

    // Turn on the display
    gfx->displayOn();
    displayOn = true;
}

// Touch Screen Setup
void touch_setup() {
    print(" System | Touch | Initializing");
    // Connecting to the touch screen using the Wire library, this is the bus that the touch screen uses to communicate with the microcontrollar
    touchReady = touch.begin(Wire);
    
    // Checking if the touch screen is ready and printing the result to the serial monitor
    if (!touchReady) {
        print("System | Touch | Touch Ready: Failed\n");
    } else {
        print("System | Touch | Touch Ready: Success\n");
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


