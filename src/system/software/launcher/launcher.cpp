#include "launcher.h"
#include "system/software/manager/app_manager.h"


int selected_app = 0;

// Global Buttons
Button* L_Button;
Button* R_Button;

void next_app() {
    selected_app++;
    if (selected_app >= app_count) {
        selected_app = 0;
    }
}
void previous_app() {
    selected_app--;
    if (selected_app < 0) {
        selected_app = app_count - 1;
    }
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
}

void draw_current_app() {
    int screen_w = gfx->width();
    int screen_h = gfx->height();
    int spacer = 5;
    int outside = 10;
    int x = outside;
    int y = screen_h / 2.9;
    int w = screen_w / 5;
    int h = screen_h / 2.4;

    gfx->fillRect(
        x + w + spacer,
        y,
        w * 3 - (spacer * 2),
        h,
        apps_list[selected_app].color
    );

    say(
        apps_list[selected_app].name,
        x + w + spacer,
        y,
        w * 3 - (spacer * 2),
        h,
        BLACK,
        4
    );
}

void open_selected_app() {
    open_app(selected_app);
}

void launcher_run(TouchPoint pressed) {
    // Button Logic
    // Drawing Buttons
    L_Button->draw("LEFT",BLACK,2);
    R_Button->draw("RIGHT",BLACK,2);

    draw_current_app();

    L_Button->hit(pressed, previous_app);
    R_Button->hit(pressed, next_app);

    

    
}

void nothing() {
    print("Nothing to run");
}