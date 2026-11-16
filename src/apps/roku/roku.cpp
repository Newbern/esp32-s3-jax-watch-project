#include "apps/apps.h"


void roku_setup() {

}

/*----------Layout----------*/
Button* upButton = nullptr;
Button* downButton = nullptr;
Button* leftButton = nullptr;
Button* rightButton = nullptr;
Button* okButton = nullptr;

void remote_layout() {
    // Screen size
    int screen_w = gfx->width();
    int screen_h = gfx->height();

    int margin = 20;
    int spacer = 10;

    // Coordinates
    int x = margin;
    int y = margin;
    int w = (screen_w - margin * 2 + spacer * 2) / 3;
    int h = (screen_h - margin * 2 + spacer *3) / 4;

    // Buttons
    upButton = new Button("Up", x+w+spacer, y, w, h, BLUE, epd_bitmap_icons8_home_50);
    leftButton = new Button("Left", x, y+h+spacer, w, h, BLUE, epd_bitmap_icons8_home_50);
    okButton = new Button("OK", x+w+spacer, y+h+spacer, w, h, BLUE, epd_bitmap_icons8_home_50);
    rightButton = new Button("Right", x+w*2+spacer*2, y+h+spacer, w, h, BLUE, epd_bitmap_icons8_home_50);
    downButton = new Button("Down", x+w+spacer, y+h*2+spacer*2, w, h, BLUE, epd_bitmap_icons8_home_50);

}
Button* oneButton = nullptr;
Button* twoButton = nullptr;
Button* threeButton = nullptr;
void bottom_section () {
    // Screen size
    int screen_w = gfx->width();
    int screen_h = gfx->height();

    int margin = 20;
    int spacer = 10;

    // Coordinates
    int x = margin;
    int y = margin;
    int w = (screen_w - margin * 2 + spacer * 2) / 3;
    int h = (screen_h - margin * 2 + spacer *3) / 4;

    // Buttons
    oneButton = new Button("1", x, y+h*3+spacer*3, w, h, BLUE, epd_bitmap_icons8_home_50);
    twoButton = new Button("2", x+w+spacer, y+h*3+spacer*3, w, h, BLUE, epd_bitmap_icons8_home_50);
    threeButton = new Button("3", x+w*2+spacer*2, y+h*3+spacer*3, w, h, BLUE, epd_bitmap_icons8_home_50);

    
}
void roku_run(TouchPoint pressed) {
    
}