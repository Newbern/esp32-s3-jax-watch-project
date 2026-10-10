#include "wifi.h"
#include "wifi_credentials.h"





Wifi wifi;

bool Wifi::setup() {

    for (int i = 0; i < wifi_count; i++) {

        clear_print();
        merge_print("System | Wifi | Connecting: %s", ssids[i]);

        WiFi.begin(ssids[i], passwords[i]);

        for (int attempt = 0; attempt < 5; attempt++) {

            if (WiFi.status() == WL_CONNECTED) {
                merge_print("\nSystem | Wifi | %s: Connected", ssids[i]);
                merge_print("System | Wifi | Local IP: %s", str(WiFi.localIP()));

                return true;
            }

            delay(500);
            Serial.print(".");
        }

        Serial.println("\nSystem | Wifi | Connection: Failed\n");

        WiFi.disconnect();
    }

    Serial.println("System | Wifi | Connection: Not Available\n");
    return false;
}

bool Wifi::connected() {
    return WiFi.status() == WL_CONNECTED;
}

String Wifi::name(){
    if (!connected()){
        return "No Wifi Name";
    }
    return WiFi.SSID();
}

String Wifi::password(){
    if (!connected()){
        return "No Wifi Password";
    }
    return WiFi.psk();
}

String Wifi::ip(){
    if (!connected()){
        return "No Wifi connected, No IP_Address.";
    }
    return WiFi.localIP().toString();
}


// void login()
// {
//     HTTPClient http;

//     http.begin("http://10.0.0.168:8000/auth/login");
//     http.addHeader("Content-Type", "application/json");

//     String body = R"({
//         "device_id": "1",
//         "api_key": "abc123"
//     })";

//     int responseCode = http.POST(body);

//     String response = http.getString();

//     Serial.println(responseCode);
//     Serial.println(response);

//     if (responseCode == 200)
//     {
//         JsonDocument doc;

//         DeserializationError error = deserializeJson(doc, response);

//         if (error)
//         {
//             Serial.println("JSON parsing failed");
//             http.end();
//             return;
//         }

//         bool success = doc["success"];

//         if (success)
//         {
//             String token = doc["session"].as<String>();

//             saveToken(token);

//             Serial.println("Login successful");
//         }
//         else
//         {
//             Serial.println(doc["message"].as<String>());
//         }
//     }

//     http.end();
// }

// void get_alarms() {
//     HTTPClient http;

//     http.begin("http://10.0.0.168:8000/alarm/get-alarms");

//     String sessiontoken = loadToken();

//     http.addHeader (
//         "Cookie",
//         "session_token=" + sessiontoken
//     )

//     int responseCode = http.GET();
//     String response = http.getString();

//     say(String(responseCode).c_str(), 50, 100, RED, 4);

//     if (responseCode > 0) {
//         say("Response:", 50, 150, RED, 4);
//         say(response.c_str(), 50, 200, RED, 4);
//     }

//     http.end();
// }