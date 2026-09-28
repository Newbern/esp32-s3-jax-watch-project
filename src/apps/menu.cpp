#include "app.h"

void menu_setup() {
    battery_setup();
    clock_setup();
}

void nothing() {
    print("hit");
}

void show(const char* name, int x, int y){
    say(name, x, y, WHITE, 8);
}

void menu_run(TouchPoint pressed) {

    if (pressed.pressed) {
        // Drawing Buttons
        wifiButton->draw(nullptr);//(show("Wifi", wifiButton.x, wifiButton.y));
        jaxButton->draw(nullptr);//(show("JAX", jaxButton.x, jaxButton.y));
        batteryButton->draw(nullptr);//(show("BAT", batteryButton.x, batteryButton.y));
        clockButton->draw(nullptr);//(show("10:30AM", clockButton.x, clockButton.y));
        weatherButton->draw(nullptr);//(show("weather", weatherButton.x, weatherButton.y));
        appsButton->draw(nullptr);//(show("apps", appsButton.x, appsButton.y));

        // show("Wifi", wifiButton.x, wifiButton.y);
        // show("JAX", jaxButton.x, jaxButton.y);
        // show("BAT", batteryButton.x, batteryButton.y);
        // show("10:30AM", clockButton.x, clockButton.y);
        // show("weather", weatherButton.x, weatherButton.y);
        // show("apps", appsButton.x, appsButton.y);
    }

    // Button being Pressed
    wifiButton->hit(pressed, nothing);
    jaxButton->hit(pressed, nothing);
    batteryButton->hit(pressed, nothing);
    clockButton->hit(pressed, nothing);
    weatherButton->hit(pressed, nothing);
    appsButton->hit(pressed, nothing);

}