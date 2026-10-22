#ifndef APPS_H
#define APPS_H

#include "system/software/run/app.h"
#include "system/hardware/wifi/wifi.h"
#include "apps/jax/jax.h"


// Alarms
void alarms_setup();
void alarms_get();
void alarm_layout();
void alarms_run(TouchPoint pressed);

// Clock
void time_setup();
void time_run(TouchPoint pressed);

// Internet
void internet_setup();
void internet_run(TouchPoint pressed);

// Roku
void roku_setup();
void roku_run(TouchPoint pressed);

// Test
void test_setup();
void test_run(TouchPoint pressed);


#endif