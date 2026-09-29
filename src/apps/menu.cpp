#include "app.h"

void menu_setup() {
    battery_setup();
    clock_setup();
}

void show(const char* name, Button* button) {
    say(name, button->x, button->y, button->w, button->h, BLACK, 2);
}

void menu_run(TouchPoint pressed) {

    if (pressed.pressed) {

        // Drawing Buttons
        wifiButton->draw(nullptr);
        jaxButton->draw(nullptr);
        batteryButton->draw(nullptr);
        clockButton->draw(nullptr);
        weatherButton->draw(nullptr);
        appsButton->draw(nullptr);

        // Drawing Button Names
        show("Wifi", wifiButton);
        show("JAX", jaxButton);
        show("BAT", batteryButton);
        show("10:30AM", clockButton);
        show("weather", weatherButton);
        show("apps", appsButton);
    }


    // Button being Pressed
    //wifiButton->hit(pressed, nothing);
    //jaxButton->hit(pressed, nothing);
    //batteryButton->hit(pressed, nothing);
    //clockButton->hit(pressed, nothing);
    //weatherButton->hit(pressed, nothing);
    //appsButton->hit(pressed, nothing);

}