#include "settings.h"

// Getting Screen Dimensions
int screen_w = gfx->width();
int screen_h = gfx->height();

// Getting Spacers & Outside Spaces
int spacer = 10;
int outside = 25;

// Setting Width & Height
int w = (screen_w - spacer * 2 - outside*2 ) / 3;
int h = (screen_h - spacer * 3- outside*2 ) /4;

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
// App 3 (Batter Level)
int x_app3 = x + w + spacer + w + spacer;
int y_app3 = y;
// App 4 (Time, Date)
int x_app4 = x;
int y_app4 = y + h + spacer;
int w_app4 = w * 3 + spacer*2;
int h_app4 = h * 2;
// App 5 (Weather)
int x_app5 = x;
int y_app5 = y + ((screen_h - spacer * 3- outside*2 ) /4)*3 + spacer*2;
int w_app5 = ((screen_w - spacer*2- outside*2  ) / 2);
int h_app5 = ((screen_h - spacer * 3- outside*2 ) /4);
// App 6 (Other Apps)
int x_app6 = x + ((screen_w - spacer*2- outside*2  ) / 2) + spacer;
int y_app6 = y + ((screen_h - spacer * 3- outside*2 ) /4)*3 + spacer*2;
int w_app6 = ((screen_w - spacer*2- outside*2  ) / 2);
int h_app6 = ((screen_h - spacer * 3- outside*2 ) /4);





Button wifiButton("wifi", x_app1, y_app1, w, h, RED, epd_bitmap_icons8_home_50);
Button jaxButton("Jax_server", x_app2, y_app2, w, h, PURPLE, epd_bitmap_icons8_home_50);
Button batteryButton("Batter Level", x_app3, y_app3, w, h, GREEN, epd_bitmap_icons8_home_50);
Button clockButton("Clock", x_app4, y_app4, w_app4, h_app4, BLUE, epd_bitmap_icons8_home_50);
Button weatherButton("Weather", x_app5, y_app5, w_app5, h_app5, YELLOW, epd_bitmap_icons8_home_50);
Button appsButton("Other Apps", x_app6, y_app6, w_app6, h_app6, WHITE, epd_bitmap_icons8_home_50);

TouchPoint pressed = touch_run(nullptr);