#include "app_manager.h"

int current_app = -1;

void app_manager_setup() {
    for (int i = 0; i < app_count; i++) {
        if (apps_list[i].setup) {
            apps_list[i].setup();
        }
    }
}

void open_app(int app_id) {
    if (app_id < 0 || app_id >= app_count) {
        return;
    }

    current_app = app_id;

    if (apps_list[current_app].setup) {
        apps_list[current_app].setup();
    }
}

void return_to_menu() {
    current_app = -1;
}

void app_manager_run(TouchPoint pressed) {
    if (current_app >= 0 && current_app < app_count) {
        if (apps_list[current_app].run) {
            apps_list[current_app].run(pressed);
        }
    } else {
        menu_run(pressed);
    }
}