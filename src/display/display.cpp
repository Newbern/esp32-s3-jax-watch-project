
#include "display.h"
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
}

TouchDrvFT6X36 touch;
bool touchReady = false;
unsigned long lastTouch = 0;

void touch_setup() {
    touchReady = touch.begin(Wire);
    

    if (!touchReady) {
        Serial.println("Touch FAILED");
    } else {
        Serial.println("Touch OK");
    }

    gfx->displayOn();
    displayOn = true;
    lastTouch = millis();

}


TouchPoint touch_run(void (*function)())
{
    TouchPoint point = {false, 0, 0};

    if (!touchReady)
        return point;

    if (touch.isPressed())
    {
        int16_t x[1];
        int16_t y[1];

        wake();

        if (touch.getPoint(x, y) > 0)
        {
            point.pressed = true;
            point.x = x[0];
            point.y = y[0];

            lastTouch = millis();

            if (function != nullptr)
            {
                function();
            }
        }
    }

    if (millis() - lastTouch > 5000)
    {
        sleep();
    }

    return point;
}

bool displayOn = true;
void sleep() 
{
    if (!displayOn)
        return;

    gfx->displayOff();
    displayOn = false;
}

void wake()
{
    if (displayOn)
        return;

    gfx->displayOn();
    displayOn = true;
}