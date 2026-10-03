#include "launcher.h"
// Global Buttons
Button* L_Button;
Button* R_Button;


void launcher_setup() {
    // Getting Screen Dimensions
    int screen_w = gfx->width();
    int screen_h = gfx->height();

    // Getting Spacers & Outside Spaces
    int spacer = 10;
    int outside = 10;

    // Setting Width & Height
    int w = 100;
    int h = 210;

    // Setting Coordinates
    int x = outside;
    int y = 140;
    
    L_Button = new Button("Left_Slider", x, y, w, h, YELLOW, epd_bitmap_icons8_home_50);
    R_Button = new Button("Right_Slider", ((screen_w - outside)-w), y, w, h, YELLOW, epd_bitmap_icons8_home_50);
}

void launcher_run() {

    // Getting Spacers & Outside Spaces
    int spacer = 10;
    int outside = 10;

    // Setting Width & Height
    int w = 100;
    int h = 210;

    // Setting Coordinates
    int x = outside;
    int y = 140;

    // Left Swipe Button
    L_Button->draw(
        "LEFT",
        BLACK,
        2
    );

    // App Viewer
    gfx->fillRect(
        x+w+spacer,
        y,
        359-(w)-(spacer * 2) - (outside *2),
        h,
        GREEN
    );

    // Right Swipe Button
    R_Button->draw(
        "RIGHT",
        BLACK,
        2
    );
}