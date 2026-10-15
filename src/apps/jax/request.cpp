#include "apps/jax/jax.h"

bool jax_request(
    const char* endpoint, 
    const String& body, 
    JsonDocument& response, 
    bool post
) 
    {
        print("System | Jax | HTTP: Initializing");
        
        // Getting url
        String url = String(JAX_URL);

        // Createing Http connection
        HTTPClient http;

        // Checking endpoint url
        if (!http.begin(url + endpoint)) {
            print("System | Jax | HTTP: Initialization failed!");
            return false;
        }

        // Createing Header
        http.addHeader("Content-Type", "application/json");

        // Sending body request
        int responseCode;
        
        if (post) {
             responseCode= http.POST(body);
        }
        else {
            responseCode = http.GET();
        }
        
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