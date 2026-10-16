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
    if (!jax_request("alarm/get-alarm-data", body, response, false, token)) {
        return;
    }

    // // Request sent successfully
    // if (response["success"].as<bool>())
    // {
    //     // Getting data
    //     serializeJson(response, data);
        
    //     merge_print("System | Jax | Alarm: data ->%s\n", data.c_str());
    // }
    // // Incorrect Login data
    // else
    // {
    //     print("System | Jax | Alarm: Failed");
    //     String message = response["message"].as<String>();
    //     merge_print("System | Jax | Message: %s\n", message.c_str());
    // } 





    serializeJson(response, data);
    merge_print("System | Jax | Alarm: data -> %s\n", data.c_str());















}

// void alarms_run(TouchPoint pressed) {
//     say(data.c_str(), 100, 100, 100, 100, BLUE, 8);

//     if (pressed.pressed) {
//         return_to_menu();
//     }
// }

void alarms_run(TouchPoint pressed) {
    clear();

    // Header
    say("ALARMS", 20, 15, 370, 45, CYAN, 3);

    // Divider
    gfx->drawFastHLine(25, 70, 360, WHITE);

    // Display alarms
    JsonDocument response;

    DeserializationError error = deserializeJson(response, data);

    if (error || !response.is<JsonArray>()) {
        say("Failed to load alarms", 20, 200, 370, 50, RED, 2);
        return_to_menu();
        return;
    }

    JsonArray alarms = response.as<JsonArray>();

    if (alarms.size() == 0) {
        say("No alarms found", 20, 180, 370, 50, WHITE, 2);
    }

    int y = 90;

    for (JsonObject alarm : alarms) {
        int time = alarm["time"] | 0;
        int hours = (time / 3600) % 24;
        int minutes = (time % 3600) / 60;

        char time_text[10];
        snprintf(
            time_text,
            sizeof(time_text),
            "%02d:%02d",
            hours,
            minutes
        );

        String message = alarm["message"] | "Alarm";
        String day = alarm["day"] | "Everyday";

        // Alarm card
        gfx->fillRoundRect(20, y, 370, 100, 12, DARKGREY);
        gfx->drawRoundRect(20, y, 370, 100, 12, CYAN);

        say(time_text, 30, y + 8, 140, 40, WHITE, 3);
        say(day.c_str(), 180, y + 8, 195, 30, CYAN, 2);
        say(message.c_str(), 30, y + 52, 350, 35, WHITE, 2);

        y += 115;

        if (y > 380) {
            break;
        }
    }

    // Back button
    gfx->fillRoundRect(100, 435, 210, 50, 12, BLUE);
    say("BACK", 100, 435, 210, 50, WHITE, 2);

    if (pressed.pressed &&
        pressed.x >= 100 && pressed.x <= 310 &&
        pressed.y >= 435 && pressed.y <= 485) {
        return_to_menu();
    }
}
