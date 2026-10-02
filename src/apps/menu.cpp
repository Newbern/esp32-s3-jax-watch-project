#include "app.h"

void menu_setup() {
    battery_setup();
    clock_setup();
}

void show_date(const char* text, Button* button) {
    int x = button->x;
    int y = button->y * 2;
    int w = button->w;
    int h = button->h / 2;
    say(text, x, y, w, h, WHITE, 4);
}

void menu_run(TouchPoint pressed) {

    if (pressed.pressed) {

        // Drawing Buttons
        wifiButton->draw(wifi.name().c_str(), BLACK, 2);
        jaxButton->draw("JAX", BLACK, 2);
        batteryButton->draw(battery_run(), BLACK, 2);
        clockButton->draw(clock_run(), BLACK, 10); // time only -> 10,     time & date -> 4
        show_date(date_run(), clockButton);
        weatherButton->draw("weather", BLACK, 2);
        appsButton->draw("apps", BLACK, 2);

    }


    // Button being Pressed
    wifiButton->hit(pressed, nothing);
    //jaxButton->hit(pressed, nothing);
    //batteryButton->hit(pressed, nothing);
    //clockButton->hit(pressed, nothing);
    //weatherButton->hit(pressed, nothing);
    //appsButton->hit(pressed, nothing);

}