#include "apps/apps.h"

String data = "";
JsonDocument data_response;

void alarms_setup() {
    location = "Jax";
    alarms_get();
}

void alarms_get() {
    log("Alarm" , "Initializing");

    // Getting Token
    String token = get_token();

    // Checking if Session Token Exists
    if (token.isEmpty()) {
        log("Storage", "No Session_Token found!");
        return;
    }

    // Createing Json document object
    JsonDocument request;
    request["session_token"] = token;

    // Createing String 
    String body;

    // Turning json document into a string
    serializeJson(request, body);
    
    // Using Jax Http request
    if (!jax_request("alarm/get-alarm-data", body, data_response, false, token)) {
        return;
    }
    
    // Turning JsonDocument into String
    serializeJson(data_response, data);

    // Checking response data
    if (data_response.is<JsonArray>()) {
        log("Alarm", log_merge("data -> %s\n", data.c_str()));
        return;
    }
    
    else {
        log("Alarm", "Failed to load alarms");
        return_to_menu();
        return;
    }
}

void alarm_layout() {
    // Screen size
    int screen_w = gfx->width();
    int screen_h = gfx->height();

    // Getting Alarm card div size
    int w = round(screen_w * 0.9 / 2) * 2;
    int h = round(screen_h * .5 / 2) * 2;

    // Coordinates
    int spacer = 10;
    int x = spacer;
    int y = spacer;
    int new_y = spacer + h;

    // Header
    draw_rect(x, y, w, round(screen_h * 0.1 / 2) * 2, BLUE);
    say(
        "ALARMS", 
        x, 
        y, 
        w, 
        round(screen_h * 0.1 / 2) * 2, 
        WHITE, 
        3
    );

    // Getting Alarm data
    JsonArray alarms = data_response.as<JsonArray>();

    // No Alarms are found in data
    if (alarms.size() == 0) {
        say("No alarms were found", x, new_y, w, h, WHITE, 2);
    }

    // Createing Alarm Objects
    y += round(screen_h * 0.1 / 2) *2;
    for (JsonObject alarm: alarms) {

        // Getting Alarm data
        int time = alarm["time"].as<int>() | 0;
        String message = String(alarm["message"] | "No Name");
        String days = String(alarm["day"] | "None");

        // Div
        draw_rect(x, y, w, h, BLUE);
        int gap = 10;
        int dx = x + gap;
        int dy = y + gap;
        int dw = w - gap*2;
        int dh = (h / 3) - gap*2;
        say (str(message), dx, dy, dw, dh, WHITE, 4, "left");
        say (return_time(time), dx, dy+dh+gap, dw/2, dh, WHITE, 4, "left");
        say ("(_O)", dx+dw/2+gap, dy+dh+gap, dw/2, dh, WHITE, 4, "right");
        say (str(days), dx, dy+dh+gap+dh+gap, dw, dh, WHITE, 4, "left");

        // Setting Y Coordinates
        y += new_y;
    }




}
void alarms_run(TouchPoint pressed) {
    alarm_layout();
}

// void alarms_run(TouchPoint pressed) {
//     // Divider
//     gfx->drawFastHLine(25, 70, 360, WHITE);


//     int y = 90;

//     for (JsonObject alarm : alarms) {
//         int time = alarm["time"] | 0;
//         int hours = (time / 3600) % 24;
//         int minutes = (time % 3600) / 60;

//         time_text = return_time();

//         String message = alarm["message"] | "Alarm";
//         String day = alarm["day"] | "Everyday";

//         // Alarm card
//         gfx->fillRoundRect(20, y, 370, 100, 12, DARKGREY);
//         gfx->drawRoundRect(20, y, 370, 100, 12, CYAN);

//         say(time_text, 30, y + 8, 140, 40, WHITE, 3);
//         say(day.c_str(), 180, y + 8, 195, 30, CYAN, 2);
//         say(message.c_str(), 30, y + 52, 350, 35, WHITE, 2);

//         y += 115;

//         if (y > 380) {
//             break;
//         }
//     }

//     // Back button
//     gfx->fillRoundRect(100, 435, 210, 50, 12, BLUE);
//     say("BACK", 100, 435, 210, 50, WHITE, 2);

//     if (pressed.pressed &&
//         pressed.x >= 100 && pressed.x <= 310 &&
//         pressed.y >= 435 && pressed.y <= 485) {
//         return_to_menu();
//     }
// }
