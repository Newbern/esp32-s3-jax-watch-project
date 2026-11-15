#ifndef CLOCK_H
#define CLOCK_H

/*----------LIBS----------*/
// RTC Functions
#include "SensorPCF85063.hpp"
#include "Wire.h"
// System Functions
#include "system/software/run/app.h"


extern SensorPCF85063 rtc;


/*----------FUNCTIONS----------*/
// Time Reset
void clock_reset();
// Setup the RTC
void clock_setup();
// Draw the clock on the screen
const char* clock_run();
const char* date_run();
const char* day_run();
const char* return_time(int time);

#endif