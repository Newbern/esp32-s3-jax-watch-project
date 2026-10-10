#include "app_manager.h"

int current_app = APP_MENU;

// Getting AppEntry from Addp id
AppEntry* get_app(int app_id)
{
    merge_print("Application Manager | Getting AppEntry | ID: %s\n", str(app_id));
    // Checking through how many apps there are
    for (int i = 0; i < app_count; i++)
    {
        // When the app id matches the data set it will return that app data
        if (apps_list[i].id == app_id)
        {
            // Returning app data & setting current app
            current_app = app_id;
            return &apps_list[i];
        }
    }

    return nullptr;
}

void app_manager_setup()
{

    // Starting on the Menu App
    clear_print();
    print("Application Manager | Setup | Initializing");
    current_app = APP_MENU;

    // Getting the Menu App data
    AppEntry* app = get_app(current_app);

    // Setting up Menu data with menu_setup
    if (app && app->setup)
    {
        merge_print("Application Manager | Setup | Running: %s_setup\n", app->name);
        clear_print();
        app->setup();
    }
}

void open_app(int app_id)
{
    // Getting App Data
    clear_print();
    print("Application Manager | Opening App | Initializing");
    AppEntry* app = get_app(app_id);
    
    // Checking to see if app exists 
    if (!app)
    {
        // If App doesn't exists return to main menu
        print("Application Manager | Opening App | Error: App does not exists\n");
        return_to_menu();
    }

    

    // Running app Setup
    if (app->setup)
    {
        merge_print("Application Manager | Opening App | Running: %s_setup\n", app->name);
        app->setup();
    }

    // Clearing Screen
    clear();
}

void return_to_menu()
{
    clear_print();
    print("Application Manager | Return to Main Menu | Setting: current_app = APP_MENU\n");
    current_app = APP_MENU;
}

void app_manager_run(TouchPoint pressed)
{
    // Getting Current App Data
    clear_print();
    print("Application Manager | Running | Initializing");
    AppEntry* app = get_app(current_app);

    // Runnning Application
    if (app && app->run)
    {
        merge_print("Application Manager | Running | Running: %s_run\n", app->name);
        app->run(pressed);
    }
}