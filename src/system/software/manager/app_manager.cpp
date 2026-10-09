#include "app_manager.h"

int current_app = APP_MENU;

AppEntry* get_app(int app_id)
{
    for (int i = 0; i < app_count; i++)
    {
        if (apps_list[i].id == app_id)
        {
            return &apps_list[i];
        }
    }

    return nullptr;
}

void app_manager_setup()
{
    print("App Manager Setup Initialized\n");
    current_app = APP_MENU;

    AppEntry* app = get_app(current_app);

    if (app && app->setup)
    {
        app->setup();
    }
}

void open_app(int app_id)
{
    print("Opening app with ID: ");
    print(std::to_string(app_id).c_str());
    AppEntry* app = get_app(app_id);

    if (!app)
    {
        return;
    }

    current_app = app_id;

    print("Opening app: ");
    print(app->name);

    if (app->setup)
    {
        app->setup();
    }

    clear();
}

void return_to_menu()
{
    print("Returning to menu\n");
    current_app = APP_MENU;
}

void app_manager_run(TouchPoint pressed)
{
    print("Running app with ID: ");
    print(std::to_string(current_app).c_str());
    AppEntry* app = get_app(current_app);

    if (app && app->run)
    {
        app->run(pressed);
    }
}