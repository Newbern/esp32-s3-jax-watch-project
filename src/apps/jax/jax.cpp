#include "apps/apps.h"
#include "system/hardware/wifi/wifi.h"
#include "jax_credentials.h"
#include "system/hardware/storage/jax_storage/jax_stoarge.h"


// Jax Login
void login()
{
    // Getting API_KEY
    String key = get_api_key();
    // Getting URL
    String url = String(JAX_URL);

    // Checking if API_KEY exists
    if (key.isEmpty()) {
        print("System | Jax | Storage: No API_KEY found!");
        return;
    }

    // Creating Http Request Object
    HTTPClient http;

    // Checking URL
    if (!http.begin(url + "/auth/login")) {
        print("System | Jax | HTTP: Initialization failed!");
        return;
    }


    // Sending API_KEY 
    http.addHeader("Content-Type", "application/json");

    // Createing Json document object
    JsonDocument doc;
    doc["device_id"] = JAX_ID;
    doc["api_key"] = key;

    // Createing String 
    String body;

    // Turning json document into a string
    serializeJson(doc, body);
    
    // Sending Login Request
    int responseCode = http.POST(body);

    // Getting Response data
    String response = http.getString();

    merge_print("System | Jax | Login: Response-> %s", str(responseCode));
    merge_print("System | Jax | Login: Response-> %s", response.c_str());

    // If login Request is incorrect
    if (responseCode == 200)
    {
        // Createing Json document object
        JsonDocument doc;

        // Turning string into json document
        DeserializationError error = deserializeJson(doc, response);

        // Getting Error
        if (error)
        {
            print("JSON parsing failed");
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

void jax_setup() {
    
};

void jax_run(TouchPoint pressed) {};









void get_alarms() {
    HTTPClient http;

    http.begin("http://10.0.0.168:8000/alarm/get-alarms");

    String sessiontoken = loadToken();

    http.addHeader (
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