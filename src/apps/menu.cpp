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

void menu_run() {
    // Drawing Buttons
    wifiButton.draw();//(show("Wifi", wifiButton.x, wifiButton.y));
    jaxButton.draw();//(show("JAX", jaxButton.x, jaxButton.y));
    batteryButton.draw();//(show("BAT", batteryButton.x, batteryButton.y));
    clockButton.draw();//(show("10:30AM", clockButton.x, clockButton.y));
    weatherButton.draw();//(show("weater", weatherButton.x, weatherButton.y));
    appsButton.draw();//(show("apps", appsButton.x, appsButton.y));

    show("Wifi", wifiButton.x, wifiButton.y);
    show("JAX", jaxButton.x, jaxButton.y);
    show("BAT", batteryButton.x, batteryButton.y);
    show("10:30AM", clockButton.x, clockButton.y);
    show("weater", weatherButton.x, weatherButton.y);
    show("apps", appsButton.x, appsButton.y);

    // Button being Pressed
    wifiButton.hit(pressed, nothing);
    jaxButton.hit(pressed, nothing);
    batteryButton.hit(pressed, nothing);
    clockButton.hit(pressed, nothing);
    weatherButton.hit(pressed, nothing);
    appsButton.hit(pressed, nothing);

}