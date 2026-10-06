#include "functions.h"

// Prints Words on Screen
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

// Clears Screen Black
void clear() {
    gfx->fillScreen(BLACK);
}

// Timeout
void timeout() {
    delay(5000); // Wait 5 seconds
}

// Serial printer for monitor view
void print(const char* text) {
    Serial.println(text);
}

// Serial printer that merges text & variables
void merge_print(const char* text, const char* var){
    char message[100];
    snprintf(message, sizeof(message), text, var);
    print(message);
}

// Button Class
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

// Draws Button class Object
void Button::draw(const char* text, uint16_t text_color, uint8_t font_size)
{
    gfx->fillRect(x, y, w, h, color);
    say(text, x, y, w, h, text_color, font_size);
    

}

// Button Logic for when the Button area is pressed with TouchPoint parameter
void Button::hit(TouchPoint pressed, void (*function)(TouchPoint))
{
    if (!pressed.pressed)
        return;

    if (pressed.x >= x &&
        pressed.x <= x + w &&
        pressed.y >= y &&
        pressed.y <= y + h)
    {
        if (function != nullptr)
        {
            function(pressed);
            timeout();

        }
    }
}

// Button Logic for when the Button area is pressed with AppID parameter
void Button::hit(TouchPoint pressed, int app_id)
{
    if (!pressed.pressed)
        return;

    if (pressed.x >= x &&
        pressed.x <= x + w &&
        pressed.y >= y &&
        pressed.y <= y + h)
    {
        open_app(app_id); 
    }
}

void Button::run(TouchPoint pressed, void (*function)())
{
    if (!pressed.pressed)
        return;

    if (pressed.x >= x &&
        pressed.x <= x + w &&
        pressed.y >= y &&
        pressed.y <= y + h)
    {
        if (function != nullptr)
        {
            function();
        }
    }
}
// Button Logic for when swiped
bool Button::swipe(TouchPoint touch, int a, int b, bool x_axis) {
    if (!touch.pressed) {
        return false;
    }

    if (x_axis){
        return touch.x >= a && touch.x <= b;
    }

    return touch.y >= a && touch.y <= b;



}