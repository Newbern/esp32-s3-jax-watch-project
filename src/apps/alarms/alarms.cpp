#include "apps/apps.h"

String data = "";

void alarms_setup() {
    alarms_get();
}

void alarms_get() {
    print("System | Jax | Alarm: Initializing");

    // Getting Token
    String token = get_token();

    // Checking if Session Token Exists
    if (token.isEmpty()) {
        print("System | Jax | Storage: No Session_Token found!");
        return;
    }

    // Createing Json document object
    JsonDocument request;
    request["session_token"] = token;

    // Createing String 
    String body;

    // Turning json document into a string
    serializeJson(request, body);

    // Creating Json Response object
    JsonDocument response;
    
    // Using Jax Http request
    if (!jax_request("alarm/get-alarm-data", body, response, false)) {
        return;
    }

    // Request sent successfully
    if (response["success"].as<bool>())
    {
        // Getting data
        String data = response["session"].as<String>();
        
        merge_print("System | Jax | Alarm: data ->%s\n", data.c_str());
    }
    // Incorrect Login data
    else
    {
        print("System | Jax | Alarm: Failed");
        String message = response["message"].as<String>();
        merge_print("System | Jax | Message: %s\n", message.c_str());
    } 

}

void alarms_run(TouchPoint pressed) {
    say(data.c_str(), 100, 100, 100, 100, BLUE, 8);

    if (pressed.pressed) {
        return_to_menu();
    }
}

