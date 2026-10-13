#include "apps/apps.h"
#include "system/hardware/wifi/wifi.h"
#include "jax_credentials.h"
#include "system/hardware/storage/jax_storage/jax_stoarge.h"


// Jax Login
void login()
{
    print("System | Jax | Login: Initializing");
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
    if (!http.begin(url + "/auth/device-login")) {
        print("System | Jax | HTTPS: Initialization failed!");
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

    merge_print("System | Jax | Login: Response Code-> %s", str(responseCode));
    merge_print("System | Jax | Login: Response Body-> %s", response.c_str());

    // Request sent successfully
    if (responseCode == 200)
    {
        // Createing Json document object
        JsonDocument doc;

        // Turning string into json document
        DeserializationError error = deserializeJson(doc, response);

        // JSON Error
        if (error)
        {
            print("Systm | Jax | Login: Could not properly read json data\n");
            
            // Closing Http Connection
            http.end();
            return;
        }

        // Getting data
        bool success = doc["success"];

        // Saving correct login data
        if (success)
        {
            String token = doc["session"].as<String>();

            saveToken(token);

            print("System | Jax | Login: Successful\n");
        }
        // Incorrect Login data
        else
        {
            print("System | Jax | Login: Failed");
            String message = doc["message"].as<String>();
            merge_print("System | Jax | Message: %s\n", message.c_str());
        }
    }

    // Closing Http Connection
    http.end();
}

void jax_setup() {
    jax_storage_setup();
    login();
};

void jax_run(TouchPoint pressed) {
    say("JAX SERER", 200,100, 100,100, PURPLE, 8);
    if (pressed.pressed) {
        return_to_menu();
    }
};

