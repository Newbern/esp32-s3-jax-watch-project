#include "settings.h"

// Getting Screen Dimensions
int screen_w;
int screen_h;
// Getting Spacers & Outside Spaces
int spacer = 10;
int outside = 25;
// Setting Width & Height
int w;
int h;
// Setting Coordinates
int x;
int y;
// Locations
// App 1 (Wifi Connections)
int x_app1;
int y_app1;
// App 2 (Jax Server Connection)
int x_app2;
int y_app2;
// App 3 (Batter Level)
int x_app3;
int y_app3;
// App 4 (Time, Date)
int x_app4;
int y_app4;
int w_app4;
int h_app4;
// App 5 (Weather)
int x_app5;
int y_app5;
int w_app5;
int h_app5;
// App 6 (Other Apps)
int x_app6;
int y_app6;
int w_app6;
int h_app6;

// Global Buttons
Button* wifiButton;
Button* jaxButton;
Button* batteryButton;
Button* clockButton;
Button* weatherButton;
Button* appsButton;


void settings_setup() {
    // Getting Screen Dimensions
    screen_w = gfx->width();
    screen_h = gfx->height();

    // Getting Spacers & Outside Spaces
    spacer = 10;
    outside = 25;

    // Setting Width & Height
    w = (screen_w - spacer * 2 - outside*2 ) / 3;
    h = (screen_h - spacer * 3- outside*2 ) /4;

    // Setting Coordinates
    x = outside;
    y = outside;

    // Locations
    // App 1 (Wifi Connections)
    x_app1 = x;
    y_app1 = y;
    // App 2 (Jax Server Connection)
    x_app2 = x + w + spacer;
    y_app2 = y;
    // App 3 (Batter Level)
    x_app3 = x + w + spacer + w + spacer;
    y_app3 = y;
    // App 4 (Time, Date)
    x_app4 = x;
    y_app4 = y + h + spacer;
    w_app4 = w * 3 + spacer*2;
    h_app4 = h * 2;
    // App 5 (Weather)
    x_app5 = x;
    y_app5 = y + ((screen_h - spacer * 3- outside*2 ) /4)*3 + spacer*2;
    w_app5 = ((screen_w - spacer*2- outside*2  ) / 2);
    h_app5 = ((screen_h - spacer * 3- outside*2 ) /4);
    // App 6 (Other Apps)
    x_app6 = x + ((screen_w - spacer*2- outside*2  ) / 2) + spacer;
    y_app6 = y + ((screen_h - spacer * 3- outside*2 ) /4)*3 + spacer*2;
    w_app6 = ((screen_w - spacer*2- outside*2  ) / 2);
    h_app6 = ((screen_h - spacer * 3- outside*2 ) /4);

    // Buttons
    wifiButton = new Button("wifi", x_app1, y_app1, w, h, RED, epd_bitmap_icons8_home_50);
    jaxButton = new Button ("Jax_server", x_app2, y_app2, w, h, PURPLE, epd_bitmap_icons8_home_50);
    batteryButton = new Button("Batter Level", x_app3, y_app3, w, h, GREEN, epd_bitmap_icons8_home_50);
    clockButton = new Button("Clock", x_app4, y_app4, w_app4, h_app4, BLUE, epd_bitmap_icons8_home_50);
    weatherButton = new Button("Weather", x_app5, y_app5, w_app5, h_app5, YELLOW, epd_bitmap_icons8_home_50);
    appsButton = new Button("Other Apps", x_app6, y_app6, w_app6, h_app6, WHITE, epd_bitmap_icons8_home_50);
}