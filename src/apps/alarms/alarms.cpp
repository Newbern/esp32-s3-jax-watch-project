#include "apps/apps.h"

void alarms_setup() {

}

void alarms_run(TouchPoint pressed) {
    
}

// void get_alarms() {
    // HTTPClient http;
// 
    // http.begin("http://10.0.0.168:8000/alarm/get-alarms");
// 
    // String sessiontoken = loadToken();
// 
    // http.addHeader (
        // "Cookie",
        // "session_token=" + sessiontoken
    // )
// 
    // int responseCode = http.GET();
    // String response = http.getString();
// 
    // say(String(responseCode).c_str(), 50, 100, RED, 4);
// 
    // if (responseCode > 0) {
        // say("Response:", 50, 150, RED, 4);
        // say(response.c_str(), 50, 200, RED, 4);
    // }
// 
    // http.end();
// }