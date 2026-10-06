#include "menu.h"

// Menu Setup
void menu_setup() {
    battery_setup();
    clock_setup();
    menu_layout();
    launcher_setup();
}

// Menu Buttons
Button* wifiButton = nullptr;
Button* jaxButton = nullptr;
Button* batteryButton = nullptr;
Button* clockButton = nullptr;
Button* weatherButton = nullptr;
Button* appsButton = nullptr;

// Menu Layout
void menu_layout() {
    // Getting Screen Dimensions
    int screen_w = gfx->width();
    int screen_h = gfx->height();

    // Getting Spacers & Outside Spaces
    int spacer = 10;
    int outside = 25;

    // Setting Width & Height
    int w = (screen_w - spacer * 2 - outside * 2) / 3;
    int h = (screen_h - spacer * 3 - outside * 2) / 4;

    // Setting Coordinates
    int x = outside;
    int y = outside;
    
    // Locations
    // App 1 (Wifi Connections)
    int x_app1 = x;
    int y_app1 = y;
    // App 2 (Jax Server Connection)
    int x_app2 = x + w + spacer;
    int y_app2 = y;
    // App 3 (Battery Level)
    int x_app3 = x + w + spacer + w + spacer;
    int y_app3 = y;
    // App 4 (Time, Date)
    int x_app4 = x;
    int y_app4 = y + h + spacer;
    int w_app4 = w * 3 + spacer*2;
    int h_app4 = h * 2;
    // App 5 (Weather)
    int x_app5 = x;
    int y_app5 = y + ((screen_h - spacer * 3 - outside * 2 ) / 4) * 3 + spacer * 2;
    int w_app5 = ((screen_w - spacer * 2 - outside * 2 ) / 2);
    int h_app5 = ((screen_h - spacer * 3 - outside * 2 ) / 4);
    // App 6 (Other Apps)
    int x_app6 = x + ((screen_w - spacer * 2 - outside * 2 ) / 2) + spacer;
    int y_app6 = y + ((screen_h - spacer * 3 - outside * 2 ) / 4) * 3 + spacer * 2;
    int w_app6 = ((screen_w - spacer * 2 - outside * 2 ) / 2);
    int h_app6 = ((screen_h - spacer * 3 - outside * 2 ) / 4);

    // Buttons
    wifiButton = new Button("wifi", x_app1, y_app1, w, h, RED, epd_bitmap_icons8_home_50);
    jaxButton = new Button ("Jax_server", x_app2, y_app2, w, h, PURPLE, epd_bitmap_icons8_home_50);
    batteryButton = new Button("Batter Level", x_app3, y_app3, w, h, GREEN, epd_bitmap_icons8_home_50);
    clockButton = new Button("Clock", x_app4, y_app4, w_app4, h_app4, BLUE, epd_bitmap_icons8_home_50);
    weatherButton = new Button("Weather", x_app5, y_app5, w_app5, h_app5, YELLOW, epd_bitmap_icons8_home_50);
    appsButton = new Button("Other Apps", x_app6, y_app6, w_app6, h_app6, WHITE, epd_bitmap_icons8_home_50);
}

// Clock Date Display
void show_date(const char* text, Button* button) {
    int x = button->x;
    int y = button->y * 2;
    int w = button->w;
    int h = button->h / 2;
    say(text, x, y, w, h, WHITE, 4);
}

// Menu Run 
void menu_run(TouchPoint pressed) {
    // Drawing Buttons
    wifiButton->draw(wifi.name().c_str(), BLACK, 2);
    jaxButton->draw("JAX", BLACK, 2);
    batteryButton->draw(battery_run(), BLACK, 2);
    clockButton->draw(clock_run(), BLACK, 10); // time only -> 10,     time & date -> 4
    show_date(date_run(), clockButton);
    weatherButton->draw("weather", BLACK, 2);
    appsButton->draw("apps", BLACK, 2);

    


    // Button being Pressed
    //wifiButton->hit(pressed, nothing);
    //jaxButton->hit(pressed, nothing);
    //batteryButton->hit(pressed, nothing);
    //clockButton->hit(pressed, nothing);
    //weatherButton->hit(pressed, nothing);
    appsButton->hit(pressed, APP_LAUNCHER);

}