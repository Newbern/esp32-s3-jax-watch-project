#include "apps/apps.h"

// Setup
int screen_w = gfx->width();
int screen_h = gfx->height();
int margin = 20;
int spacer = 10;

// Main Layout (3 Columns)
int x = margin;
int y = margin;
int w = (screen_w - margin * 2 - spacer * 2) / 3;
int h = (screen_h - margin * 2 - spacer * 3) / 4;

// Quick Buttons (6 Columns)
int quick_w = (screen_w - margin * 2 - spacer * 5) / 6;
int quick_h = h;

// Bottom Navigation
int bottom_y = screen_h - margin - h;

// Home Button
Button* HomeButton = nullptr;
// Remote buttons
Button* upButton = nullptr;
Button* downButton = nullptr;
Button* leftButton = nullptr;
Button* rightButton = nullptr;
Button* okButton = nullptr;
// Volume buttons
Button* volumeUpButton = nullptr;
Button* volumeDownButton = nullptr;
// Bottom section buttons
Button* oneButton = nullptr;
Button* twoButton = nullptr;
Button* threeButton = nullptr;
// Quick buttons
Button* HBOButton = nullptr;
Button* NetflixButton = nullptr;
Button* CrunchyrollButton = nullptr;
Button* DisneyPlusButton = nullptr;
Button* ChosenButton = nullptr;
Button* YoutubeButton = nullptr;
// layout
int layout = 0;

void create_buttons() {
    // Remote Buttons
    upButton = new Button("Up", x+w+spacer, y, w, h, BLUE, epd_bitmap_icons8_home_50);
    leftButton = new Button("Left", x, y+h+spacer, w, h, BLUE, epd_bitmap_icons8_home_50);
    okButton = new Button("OK", x+w+spacer, y+h+spacer, w, h, BLUE, epd_bitmap_icons8_home_50);
    rightButton = new Button("Right", x+w*2+spacer*2, y+h+spacer, w, h, BLUE, epd_bitmap_icons8_home_50);
    downButton = new Button("Down", x+w+spacer, y+h*2+spacer*2, w, h, BLUE, epd_bitmap_icons8_home_50);

    // Home Button
    HomeButton = new Button("Home", x+w+spacer, y+h*3+spacer*3, w, h, BLUE, epd_bitmap_icons8_home_50);

    // Volume Buttons
    volumeUpButton = new Button("Volume Up", x, y, w, h, BLUE, epd_bitmap_icons8_home_50);
    volumeDownButton = new Button("Volume Down", x+w*2+spacer*2, y, w, h, BLUE, epd_bitmap_icons8_home_50);

    // Quick Buttons (3 Columns x 2 Rows)
    int quick_w = w;
    int quick_h = h;
    int quick_y = y+h+spacer;

    HBOButton = new Button("HBO", x, quick_y, quick_w, quick_h, BLUE, epd_bitmap_icons8_home_50);
    NetflixButton = new Button("Netflix", x+w+spacer, quick_y, quick_w, quick_h, BLUE, epd_bitmap_icons8_home_50);
    CrunchyrollButton = new Button("Crunchyroll", x+w*2+spacer*2, quick_y, quick_w, quick_h, BLUE, epd_bitmap_icons8_home_50);
    DisneyPlusButton = new Button("Disney+", x, quick_y+h+spacer, quick_w, quick_h, BLUE, epd_bitmap_icons8_home_50);
    ChosenButton = new Button("Chosen", x+w+spacer, quick_y+h+spacer, quick_w, quick_h, BLUE, epd_bitmap_icons8_home_50);
    YoutubeButton = new Button("YouTube", x+w*2+spacer*2, quick_y+h+spacer, quick_w, quick_h, BLUE, epd_bitmap_icons8_home_50);

    // Bottom Navigation Buttons
    oneButton = new Button("1", x, bottom_y, w, h, BLUE, epd_bitmap_icons8_home_50);
    twoButton = new Button("2", x+w+spacer, bottom_y, w, h, BLUE, epd_bitmap_icons8_home_50);
    threeButton = new Button("3", x+w*2+spacer*2, bottom_y, w, h, BLUE, epd_bitmap_icons8_home_50);
}
void roku_setup() {
    create_buttons();
}

/*----------Layout----------*/


void remote_layout() {
    upButton->draw("^", WHITE, 2);
    leftButton->draw("<", WHITE, 2);
    okButton->draw("OK", WHITE, 2);
    rightButton->draw(">", WHITE, 2);
    downButton->draw("v", WHITE, 2);
    HomeButton->draw("Home", WHITE, 2);
}

void volume_layout() {
    // Drawing Buttons
    volumeUpButton->draw("Volume Up", WHITE, 2);
    volumeDownButton->draw("Volume Down", WHITE, 2);
}

void quick_buttons_layout() {
    // Drawing Buttons
    HBOButton->draw("HBO", WHITE, 2);
    NetflixButton->draw("Netflix", WHITE, 2);
    CrunchyrollButton->draw("Crunchyroll", WHITE, 2);
    DisneyPlusButton->draw("Disney+", WHITE, 2);
    ChosenButton->draw("Chosen", WHITE, 2);
    YoutubeButton->draw("YouTube", WHITE, 2);
}

void bottom_section () {
    // Drawing Buttons
    oneButton->draw("1", WHITE, 2);
    twoButton->draw("2", WHITE, 2);
    threeButton->draw("3", WHITE, 2);
    
}
void layout_one() {
    layout = 0;
    current_layout();
}

void layout_two() {
    layout = 1;
    current_layout();
}

void layout_three() {
    layout = 2;
    current_layout();
}

void current_layout() {
    switch (layout) {
        case 0:
            remote_layout();
            break;
        case 1:
            volume_layout();
            break;
        case 2:
            quick_buttons_layout();
            break;
        default:
            remote_layout();
            break;
    }

}

void roku_run(TouchPoint pressed) {

    // Drawing Current Layout
    current_layout();

    // Bottom Section Buttons
    bottom_section();
    // Button being Pressed
    oneButton->run(pressed, layout_one);
    twoButton->run(pressed, layout_two);
    threeButton->run(pressed, layout_three);

}