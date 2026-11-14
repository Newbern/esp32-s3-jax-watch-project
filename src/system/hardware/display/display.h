#ifndef DISPLAY_H
#define DISPLAY_H

/*----------LIBS----------*/
#include <Arduino.h>
#include "Arduino_GFX_Library.h"
#include "pin_config.h"





/*----------GLOBAL----------*/
extern Arduino_DataBus *bus;
extern Arduino_GFX *gfx;

/*----------FUNCTIONS----------*/
void display_setup();
void sleep();
void wake();

#endif 