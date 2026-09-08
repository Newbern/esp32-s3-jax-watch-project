#ifndef DISPLAY_H
#define DISPLAY_H

/*----------LIBS----------*/
// #include "HWCDC.h"
#include <Arduino.h>
#include "Arduino_GFX_Library.h"
#include "pin_config.h"
#include <SensorLib.h>
#include "TouchDrvFT6X36.hpp"

/*----------STRUCTS----------*/
struct TouchPoint
{
    bool pressed;
    int16_t x;
    int16_t y;
};

/*----------Global----------*/
extern Arduino_DataBus *bus;
extern Arduino_GFX *gfx;
extern TouchDrvFT6X36 touch;
extern bool displayOn;
/*----------FUNCTIONS----------*/
void display_setup();
void touch_setup();
TouchPoint touch_run(void (*function)());
void sleep();
void wake();

#endif 