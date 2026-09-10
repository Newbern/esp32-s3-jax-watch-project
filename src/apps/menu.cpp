#include "app.h"



/*----------MAIN MENU----------*/
void menu_setup() {
    battery_setup();
    clock_setup();
    //touch_setup();
}

void menu_run() {
    say(battery_run(), 50, 50, WHITE, 2);
    say("Main Menu", 50,100, RED, 4);
    say(clock_run(), 50, 220, WHITE, 4);
    say(date_run(), 50, 340, WHITE, 4);
}

