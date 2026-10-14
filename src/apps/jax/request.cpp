#include "apps/apps.h"

bool jax_request(
    const char* endpoint, 
    const String& body, 
    JsonDocument& response) 
    {
        print("System | Jax | HTTP: Initializing");
        
        // Getting url
        String url = String(JAX_URL);

        // Createing Http connection
        HTTPClient http;

        // Checking endpoint url
        if (!http.begin(url + endpoint)) {
            print("System | Jax | HTTP: Initialization failed!");
        }

        // Createing Header
        http.addHeader("Content-Type", "application/json");

        // Sending body request
        int responseCode = http.POST(body);
        // merge_print("System | Jax | Login: Request -> %s", body.c_str());

        // Getting Response code errors
        if (responseCode != 200) {
                merge_print("System | Jax | HTTP: Response Code -> %s", str(responseCode));
                http.end();
                return false;
            }

        // Getting Response data
        String responseBody = http.getString();

        // Turning String into json document
        DeserializationError error = deserializeJson(response, responseBody);
        
        // Ending Http connection
        http.end();

        if (error) {
            print("System | Jax | HTTP: Invalid JSON response!\n");
            return false;
        }

        return true;
    }