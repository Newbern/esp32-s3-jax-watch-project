#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*----------LIBS----------*/
//#include "display/display.h"
#include "system/software/run/app.h"

/*----------Global----------*/

/*----------FUNCTIONS----------*/
void say(const char* text, int x, int y, int w, int h, uint16_t color, uint8_t size);
void clear();
void timeout();
void print(const char* text);

/*----------CLASSES----------*/
class Button {
public:
    const char* name;
    int x, y, w, h;
    int a, b;
    bool x_asis;
    uint16_t color;
    const uint8_t* img;
    // int img_size;
    int img_width;
    int img_height;

    Button(const char* name, int x, int y, int w, int h, int color, const uint8_t* img);

    void draw(const char* text, uint16_t text_color, uint8_t font_size);
    void hit(TouchPoint touch, void (*function)(TouchPoint));
    void hit(TouchPoint touch, void (*function)());
    bool swipe(TouchPoint touch, int a, int b, bool x_asis);
};

#endif