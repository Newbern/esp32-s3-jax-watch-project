#include "apps/apps.h"



// Jax Login
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

void jax_setup() {
    login();
};

void jax_run(TouchPoint pressed) {
    say("JAX SERER", 200,100, 100,100, PURPLE, 8);
    if (pressed.pressed) {
        return_to_menu();
    }
};

