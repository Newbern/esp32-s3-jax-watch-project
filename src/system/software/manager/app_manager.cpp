#include "app_manager.h"

int current_app = APP_MENU;

void app_manager_setup() {
    current_app = APP_MENU;


    if (apps_list[current_app].setup) {
        apps_list[current_app].setup();
    }
}

void open_app(TouchPoint pressed, int app_id) {
    if (app_id < 0 || app_id >= app_count) {
        return;
    }

    current_app = app_id;
    
    if (apps_list[app_id].setup) {
        apps_list[app_id].setup();
    }

    if (apps_list[app_id].run) {
        apps_list[app_id].run(pressed);
    }
}

void return_to_menu() {
    current_app = APP_MENU;
}

void app_manager_run(TouchPoint pressed) {
    if (current_app >= 0 && current_app < app_count) {
        if (apps_list[current_app].run) {
            apps_list[current_app].run(pressed);
        }
    }
}