#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*----------LIBS----------*/
#include "display/display.h"

/*----------Global----------*/

/*----------FUNCTIONS----------*/
void say(const char* text, int x, int y, uint16_t color, uint8_t size);
void clear();

void print(const char* text);

class Button {
public:
    const char* name;
    int x, y, w, h, color;
    const uint8_t* img;
    int img_size;

    Button(const char* name, int x, int y, int w, int h, int color, const uint8_t* img);

    void draw();
    void hit(TouchPoint touch, void (*function)());
};

#endif