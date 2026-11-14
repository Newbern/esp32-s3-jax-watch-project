#ifndef TOUCH_H
#define TOUCH_H


/*---------LIBS----------*/
#include <SensorLib.h>
#include "TouchDrvFT6X36.hpp"

/*----------STRUCTS----------*/
struct TouchPoint
{
    bool pressed;
    int16_t x;
    int16_t y;
};

/*-----------GLOBAL-----------*/
extern TouchDrvFT6X36 touch;
extern bool displayOn;
extern bool touchReady;
extern unsigned long lastTouch;

/*----------FUNCTIONS----------*/
void touch_setup();
void wire_setup();
TouchPoint touch_run();

#endif