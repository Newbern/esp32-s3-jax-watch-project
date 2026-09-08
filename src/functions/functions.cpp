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


// class Button {
//     public:
//     int x, y, w, h, color, img;

//     Button(int x, int y, int w, int h, int color, int img) {
//         this->x = x;
//         this->y = y;
//         this->w = w;
//         this->h = h;
//         this->color = color;
//         this->img = img;
//         this->img_size = 16; // Assuming the image size is 16x16 pixels
//     }

//     void draw() {
//         gfx->fillRect(x, y, w, h, color);
//         // Draw the image at the center of the button
//         display.drawBitmap(x + (w - img_size) / 2, y + (h - img_size) / 2, img, img_size, img_size, WHITE);
//     }

    

// };