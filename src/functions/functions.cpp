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


Button::Button(int x, int y, int w, int h, int color, const uint8_t* img)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->color = color;
    this->img = img;
    this->img_size = 16;
}

void Button::draw()
{
    gfx->fillRect(x, y, w, h, color);

    gfx->drawBitmap(
        x + (w - img_size) / 2,
        y + (h - img_size) / 2,
        img,
        img_size,
        img_size,
        WHITE
    );
}