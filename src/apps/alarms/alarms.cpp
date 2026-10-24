#include "apps/apps.h"

String data = "";
JsonDocument data_response;

Scroll alarm_scroll;

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
    int y = spacer - alarm_scroll.get_position();
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
    int content_h;
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
        content_h = (dy+dh+gap+dh+gap+dh+gap);
        say (str(message), dx, dy, dw, dh, WHITE, 4, "left");
        say (return_time(time), dx, dy+dh+gap, dw/2, dh, WHITE, 4, "left");
        say ("(_O)", dx+dw/2+gap, dy+dh+gap, dw/2, dh, WHITE, 4, "right");
        say (str(days), dx, dy+dh+gap+dh+gap, dw, dh, WHITE, 4, "left");

        // Setting Y Coordinates
        y += new_y;
    }

    // Setting Alarm Scroll
    alarm_scroll.setup(content_h*5, screen_h);




}

void alarms_run(TouchPoint pressed) {
    clear();
    alarm_layout();
    log("Alarm", log_merge("Touch pressed -> %s", str(pressed.y)));
    alarm_scroll.update(pressed.y);
    alarm_scroll.draw(); 
    log("Alarm", log_merge("Scroll Position -> %s", str(alarm_scroll.get_position())));
}
