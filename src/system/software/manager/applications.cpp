#include "app_manager.h"

AppEntry apps_list[] = {
    {APP_MENU, "Menu", WHITE, menu_setup, menu_run},
    {APP_LAUNCHER, "Launcher", WHITE, launcher_setup, launcher_run},
    {APP_SETTINGS, "Settings", WHITE, nullptr, nullptr},
    {APP_ALARMS, "Alarms", RED, alarms_setup, alarms_run},
    {APP_CLOCK, "Clock", GREEN, time_setup, time_run},
    {APP_INTERNET, "Internet", BLUE, internet_setup, internet_run},
    {APP_ROKU, "Roku", YELLOW, roku_setup, roku_run},
    {APP_TEST, "Test", BLUE, test_setup, test_run}
};

const int app_count = sizeof(apps_list) / sizeof(apps_list[0]);