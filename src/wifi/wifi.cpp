#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "storage/storage.h"
#include "functions/functions.h"

const char* ssid = "Newbern";
const char* password = "Milo2025!";

void wifi_setup() {
    WiFi.begin(ssid, password);

    Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi connected!");
    say("WiFi connected!", 50, 100, RED, 4);
    say(WiFi.localIP().toString().c_str(), 50, 150, RED, 2);
    delay(2000);
}



void login()
{
    HTTPClient http;

    http.begin("http://10.0.0.168:8000/auth/login");
    http.addHeader("Content-Type", "application/json");

    String body = R"({
        "device_id": "1",
        "api_key": "abc123"
    })";

    int responseCode = http.POST(body);

    String response = http.getString();

    Serial.println(responseCode);
    Serial.println(response);

    if (responseCode == 200)
    {
        JsonDocument doc;

        DeserializationError error = deserializeJson(doc, response);

        if (error)
        {
            Serial.println("JSON parsing failed");
            http.end();
            return;
        }

        bool success = doc["success"];

        if (success)
        {
            String token = doc["session"].as<String>();

            saveToken(token);

            Serial.println("Login successful");
        }
        else
        {
            Serial.println(doc["message"].as<String>());
        }
    }

    http.end();
}

void get_alarms() {
    HTTPClient http;

    http.begin("http://10.0.0.168:8000/alarm/get-alarms");

    String sessiontoken = loadToken();

    https.addHeader (
        "Cookie",
        "session_token=" + sessiontoken
    )

    int responseCode = http.GET();
    String response = http.getString();

    say(String(responseCode).c_str(), 50, 100, RED, 4);

    if (responseCode > 0) {
        say("Response:", 50, 150, RED, 4);
        say(response.c_str(), 50, 200, RED, 4);
    }

    http.end();
}