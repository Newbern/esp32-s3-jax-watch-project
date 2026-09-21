#include "app.h"
#include "media/images.h"


/*----------TEST----------*/
// void test_setup() {
//     display_setup();
//     startup_setup();
//     startup_run();
//     clear();
// }





void top (uint16_t color, int spacer, int outside) {
    int screen_w = gfx->width();
    int screen_h = gfx->height();
    //int spacer = spacer;
    int x = outside;
    int y = outside;
    int w = (screen_w - spacer * 2 - outside*2 ) / 3;
    int h = (screen_h - spacer * 3- outside*2 ) /4;

    // TOP
    gfx->fillRect(
        x,
        y,
        w,
        h,
        color
    );

    gfx->fillRect(
        x + w + spacer,
        y,
        w,
        h,
        color
    );
    
    gfx->fillRect(
        x + w + spacer + w + spacer,
        y,
        w,
        h,
        color
    );
}

void middle(uint16_t color, int spacer, int outside) {
    int screen_w = gfx->width();
    int screen_h = gfx->height();
    //int spacer = spacer;
    int x = outside;
    int y = outside;
    int w = (screen_w - spacer*2 -outside*2 ) / 3;
    int h = (screen_h - spacer * 3- outside*2 ) /4;
    gfx->fillRect(
        x,
        y + h + spacer,
        w * 3 + spacer*2,
        h * 2,
        color
    );
}

void bottom(uint16_t color, int spacer, int outside) {
    int screen_w = gfx->width();
    int screen_h = gfx->height();
    //int spacer = spacer;
    int x = outside;
    int y = outside;
    int w = (screen_w - spacer*2- outside*2  ) / 2;
    int h = (screen_h - spacer * 3- outside*2 ) /4;
    gfx->fillRect(
        x,
        y + h*3 + spacer*2,
        w,
        h,
        color
    );
    gfx->fillRect(
        x + w + spacer,
        y + h*3 + spacer*2,
        w,
        h,
        color
    );
}

void screen1() {
    gfx->fillScreen(WHITE);
    int spacer = 2;
    int outside = 0;
    top(BLACK, spacer, outside);
    middle(BLACK, spacer, outside);
    bottom(BLACK, spacer, outside);
}

void screen2() {
    // Button app1;
    
    // app1.x = 100;
    // app1.y = 100;
    // app1.w = 100;
    // app1.h = 100;
    // app1.padding = 10;
    
}

// void test_run() {
//     screen1();
    


// }

void test_run3() {
    gfx->fillRect(
        100,
        100,
        100,
        100,
        RED
    );
}

void test_run1() {
    Button alarmButton("menu", 100, 100, 100, 100, RED, epd_bitmap_icons8_home_50);
    alarmButton.draw();
    TouchPoint point = touch_run(nullptr);
    alarmButton.hit(point, menu_run);
}
void test_app() {
    say("Hello world", 100, 100, RED, 10);
}

void test_run() {
    
    // Drawing Buttons
    wifiButton.draw();
    jaxButton.draw();
    batteryButton.draw();
    clockButton.draw();
    weatherButton.draw();
    appsButton.draw();

    // Button being Pressed
    wifiButton.hit(pressed, menu_run);
    jaxButton.hit(pressed, menu_run);
    batteryButton.hit(pressed, menu_run);
    clockButton.hit(pressed, menu_run);
    weatherButton.hit(pressed, menu_run);
    appsButton.hit(pressed, menu_run);

}

