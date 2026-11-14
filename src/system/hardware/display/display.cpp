#include "display.h"
#include "system/software/run/app.h"
#include "system/software/functions/functions.h"

/*----------SETUP----------*/
Arduino_DataBus *bus = nullptr;
Arduino_GFX *gfx = nullptr;
bool displayOn = true;

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
    log("Initialized");
    
    // Checking if display is running 
    if (!gfx->begin())
    {
        log("Error: gfx->begin() failed!");
        while (1);
    }
}



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



