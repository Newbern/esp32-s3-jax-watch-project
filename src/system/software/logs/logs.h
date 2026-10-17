#ifndef LOGS_H
#define LOGS_H

#include "system/software/run/app.h"

#pragma once
extern const char* source;
extern const char* location;
void log(const char* action, const char* bonus = "");

#endif