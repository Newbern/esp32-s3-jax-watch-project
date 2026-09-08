#ifndef POWER_H
#define POWER_H

/*----------LIBS----------*/
#include "display/display.h"
#include <XPowersLib.h>
#include "Wire.h"

/*----------Global----------*/
extern XPowersAXP2101 PMU;

/*----------FUNCTIONS----------*/
void battery_setup();
const char* battery_run();

#endif