#include "apps/apps.h"



/*----------JAX LOGIN----------*/
void login()
{
    log("Login", "Initializing");
    // Getting API_KEY
    String key = get_api_key();

    // Checking if API_KEY exists
    if (key.isEmpty()) {
        log("Storage", "No API_KEY found!");
        return;
    }

    // Createing Json document object
    JsonDocument request;
    request["device_id"] = JAX_ID;
    request["api_key"] = key;

    // Createing String 
    String body;

    // Turning json document into a string
    serializeJson(request, body);

    // Creating Json Response object
    JsonDocument response;
    
    // Using Jax Http request
    if (!jax_request("auth/device-login", body, response, true, get_token())) {
        return;
    }

    // Request sent successfully
    if (response["success"].as<bool>())
    {
        // Getting data
        String session_token = response["session"].as<String>();

        // Saving session_token to storage
        log("Storage", log_merge("Saved -> %s", str(session_token)));
        save_token(session_token);
        log("Login", "Successful\n");
    }
    // Incorrect Login data
    else
    {
        log("Login", "Failed");
        String message = response["message"].as<String>();
        log("Message", message.c_str());
    }


}

/*----------Roku IP---------- */
void get_roku_ip() {
    //??
}

/*----------Turn on PC----------*/
void turn_on_pc() {
    return_to_menu();
}
/*----------JAX SETUP----------*/
void jax_setup() {
    //login();
};

/*----------JAX LAYOUT---------*/
// Jax Buttons
Button* resetButton = nullptr;
Button* rokuButton = nullptr;
Button* pcButton = nullptr;
void layout() {
    // Screen size
    int screen_w = gfx->width();
    int screen_h = gfx->height();

    int margin = 20;
    int spacer = 10;

    // Coordinates
    int x = margin;
    int y = margin;
    int w = screen_w - margin * 2;
    int h = (screen_h - margin * 2 + spacer *4) / 4;

    // Heading
    say ("JAX", x, y, w, h, PURPLE, 8);
    
    h = (screen_h - margin * 2 + spacer *4) / 8;

    // Last Login
    say ("Last Login: 11/1/2026", x, y+h*2+spacer, w, h, WHITE, 2);
    // Server Status
    say("Server Status:", x, y+h*3+spacer, w/2, h, WHITE, 2);
    say("Online", x/2+w/2, y+h*3+spacer, w/2, h, GREEN, 2);
    // PC Status
    say("PC Status:", x, y+h*4+spacer*2, w/2, h, WHITE, 2);
    say("Offline", x/2+w/2, y+h*4+spacer*2, w/2, h, RED, 2);

    // Jax Login Button
    resetButton = new Button("Reset", x/3, y+h*5+spacer*3, w/3, h, BLUE, epd_bitmap_icons8_home_50);
    // Roku Button
    rokuButton = new Button("Roku", x/3+w/3, y+h*5+spacer*3, w/3, h, PURPLE, epd_bitmap_icons8_home_50);
    // PC Button
    pcButton = new Button("PC", x/3+w/3*2, y+h*5+spacer*3, w/3, h, GREEN, epd_bitmap_icons8_home_50);
}

/*----------JAX RUN----------*/
void jax_run(TouchPoint pressed) {
    layout();
    resetButton->draw("Reset", WHITE, 3);
    rokuButton->draw("Roku", WHITE, 3);
    pcButton->draw("PC", WHITE, 3);
    
    resetButton->run(pressed, login);
    rokuButton->run(pressed, get_roku_ip);
    pcButton->run(pressed, turn_on_pc);


};

