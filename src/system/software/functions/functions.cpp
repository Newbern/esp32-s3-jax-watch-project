#include "functions.h"

// Prints Words on Screen
void say(const char* text, int x, int y, int w, int h, uint16_t color, uint8_t size, const char* justify) {

    // TESTING ONLY
    //gfx->fillRect(x, y, w, h, RED);

    // Setting Text to Size
    gfx->setTextSize(size);
    // Setting Text color
    gfx->setTextColor(color);

    // Creating Variables for TextBounds
    int16_t x1, y1;
    uint16_t text_w, text_h;

    // Getting Text Variables
    gfx->getTextBounds(text, 0, 0, &x1, &y1, &text_w, &text_h);
    int text_x;
    int text_y = y + (h - text_h) / 2 - y1;;

    // Justifying Text
    if (justify == "center") {
        text_x = x + (w - text_w) / 2;
    }
    else if (justify == "left") {
        text_x = x;
    }
    else if (justify = "right") {
        text_x = x + w - text_w;
    }

    // Setting Coordinates
    gfx->setCursor(text_x, text_y);

    // Displaying Text
    gfx->print(text);
}

// Clears Screen Black
void clear() {
    print("System | Display | Clear: Screen");
    gfx->fillScreen(BLACK);
}

void clear_print() {
    //Serial.print("\033[2J\033[H");
    print("\n------------------------------------------\n\n\n\n\n------------------------------------------\n");
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

const char* log_merge(const char* text, const char* var){
    static char message[100];
    snprintf(message, sizeof(message), text, var);
    return message;
}

const char* str(int text)
{
    static String result;
    result = String(text);
    return result.c_str();
}

const char* str(String text) {
    return text.c_str();
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

    
    log(log_merge("%s_Button", name));
    
}

// Draws Button class Object
void Button::draw(const char* text, uint16_t text_color, uint8_t font_size)
{
    gfx->fillRect(x, y, w, h, BLACK);
    say(text, x, y, w, h, WHITE, font_size);
    

}

void Button::toggle_draw(uint16_t text_color, uint8_t font_size)
{
    int toggle_height = h / 2;
    int tx = x + toggle_height;
    int ty = y + toggle_height;
    int tw = w + toggle_height;
    int th = h + toggle_height;
    gfx->fillRoundRect(x, y, w, h, toggle_height, text_color);
    gfx->fillCircle(tx, ty, toggle_height - 3, text_color);
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
        //clear();
        open_app(pressed, app_id); 
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

void draw_rect(int x, int y, int w, int h, uint16_t color) {
    gfx->fillRect(x, y, w, h, color);
}


// Scroll
void Scroll::setup(int content_height, int screen_height) {
    max_position = content_height - screen_height;

    if (max_position < 0 ) {
        max_position = 0;
    }

    position = 0;
}

void Scroll::update(int new_position) {
    position += new_position;

    if (position < 0 ) {
        position = 0;
    }

    if (position > max_position) {
        position = max_position;
    }
}

void Scroll::reset() {
    position = 0;
}

int Scroll::get_position() {
    return position;
}

void Scroll::draw() {
    int screen_w = gfx->width();
    int screen_h = gfx->height();

    int x = screen_w - 10;
    int y = 10;

    // Map scroll position to screen position
    int indicator_y = y;

    if (max_position > 0) {
        indicator_y += (position * (screen_h - 20)) / max_position;
    }

    gfx->drawCircle(x, indicator_y, 5, RED);
}