#include "functions.h"

void say(const char* text, int x, int y, uint16_t color, uint8_t size) {
    gfx->setTextSize(size);
    gfx->setTextColor(color);
    gfx->setCursor(x,y);
    gfx->print(text);
}

void clear() {
    gfx->fillScreen(BLACK);
}

void print(const char* text) {
    Serial.println(text);
}

void merge_print(const char* text, const char* var){
    char message[100];
    snprintf(message, sizeof(message), text, var);
    print(message);
}

Button::Button(const char* name, int x, int y, int w, int h, int color, const uint8_t* img)
{
    this->name = name;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->color = color;
    this->img = img;
    this->img_size = 16;
    merge_print("Createing %s Button", name);
}

void Button::draw()
{
    gfx->fillRect(x, y, w, h, color);
    merge_print("%s is on Display", name);

    // gfx->drawBitmap(
    //     x + (w - img_size) / 2,
    //     y + (h - img_size) / 2,
    //     img,
    //     img_size,
    //     img_size,
    //     WHITE
    // );
}

void Button::hit(TouchPoint touch, void (*function)())
{
    merge_print("%s Touching Logic", name);
    if (!touch.pressed)
        return;

    if (touch.x >= x &&
        touch.x <= x + w &&
        touch.y >= y &&
        touch.y <= y + h)
    {
        if (function != nullptr)
        {
            clear();
            function();
        }
    }
}