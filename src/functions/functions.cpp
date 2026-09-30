#include "functions.h"

// void say(const char* text, int x, int y, uint16_t color, uint8_t size) {
//     gfx->setTextSize(size);
//     gfx->setTextColor(color);
//     gfx->setCursor(x,y);
//     gfx->print(text);
// }

void say(const char* text, int x, int y, int w, int h, uint16_t color, uint8_t size) {

    gfx->setTextSize(size);
    gfx->setTextColor(color);

    int16_t x1, y1;
    uint16_t text_w, text_h;

    gfx->getTextBounds(text, 0, 0, &x1, &y1, &text_w, &text_h);

    int text_x = x + (w - text_w) / 2;
    int text_y = y + (h - text_h) / 2 - y1;

    gfx->setCursor(text_x, text_y);
    gfx->print(text);
}

void clear() {
    gfx->fillScreen(BLACK);
}

void timeout() {
    delay(5000); // Wait 5 seconds
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
    this->img_width = 50;
    this->img_height = 50;
    merge_print("Createing %s Button", name);
}

void Button::draw(const char* text, uint16_t text_color, uint8_t font_size)
{
    gfx->fillRect(x, y, w, h, color);
    say(text, x, y, w, h, text_color, font_size);
    

}

void Button::hit(TouchPoint touch, void (*function)())
{
    if (!touch.pressed)
        return;

    if (touch.x >= x &&
        touch.x <= x + w &&
        touch.y >= y &&
        touch.y <= y + h)
    {
        if (function != nullptr)
        {
            merge_print("Running %s", name);
            clear();
            function();
            timeout();
            clear();

        }
    }
}