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
    int x, y, w, h, color;
    const uint8_t* img;
    int img_size;

    Button(int x, int y, int w, int h, int color, const uint8_t* img);

    void draw();
};

#endif