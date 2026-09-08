#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*----------LIBS----------*/
#include "display/display.h"

/*----------Global----------*/

/*----------FUNCTIONS----------*/
void say(const char* text, int x, int y, uint16_t color, uint8_t size);
void clear();

void print(const char* text);

#endif