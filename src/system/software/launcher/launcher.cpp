#include "launcher.h"


int selected_app = 0;

// Global Buttons
Button* L_Button;
Button* R_Button;
Button* M_Button;

void next_app() {
    selected_app++;
    if (selected_app >= app_count) {
        selected_app = 0;
    }
    M_Button->color = apps_list[selected_app].color;
}
void previous_app() {
    selected_app--;
    if (selected_app < 0) {
        selected_app = app_count - 1;
    }
    M_Button->color = apps_list[selected_app].color;
}

void launcher_setup() {
    int screen_w = gfx->width(); // -> 410
    int screen_h = gfx->height(); // -> 502
    int spacer = 5;
    int outside = 10;
    int x = outside;
    int y = screen_h / 2.9;
    int w = screen_w / 5;
    int h = screen_h / 2.4;
    L_Button = new Button("Left_Slider", x, y, w, h, YELLOW, epd_bitmap_icons8_home_50);
    R_Button = new Button("Right_Slider", x+(w*4), y, w, h, YELLOW, epd_bitmap_icons8_home_50);
    M_Button = new Button("Open_App", x + w + spacer, y, w * 3 - (spacer * 2), h, apps_list[selected_app].color, epd_bitmap_icons8_home_50);
}


void launcher_run(TouchPoint pressed) {
    // Button Logic
    // Drawing Buttons
    L_Button->draw("LEFT",BLACK,2);
    R_Button->draw("RIGHT",BLACK,2);
    M_Button->draw(apps_list[selected_app].name, BLACK,2);


    L_Button->run(pressed, previous_app);
    R_Button->run(pressed, next_app);
    M_Button->hit(pressed, apps_list[selected_app].id);

    

    
}

void nothing() {
    print("Nothing to run");
}