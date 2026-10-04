#include "app_manager.h"

AppEntry apps_list[] = {
    {"Launcher", RED, launcher_setup, launcher_run},
    {"Test App", BLUE, nullptr, nullptr},
};

const int app_count = sizeof(apps_list) / sizeof(apps_list[0]);