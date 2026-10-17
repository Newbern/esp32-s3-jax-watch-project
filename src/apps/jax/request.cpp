#include "apps/jax/jax.h"

bool jax_request(
    const char* endpoint, 
    const String& body, 
    JsonDocument& response, 
    bool post,
    const String& token = ""
) 
    {
        log("HTTP", "Initializing");
        
        // Getting url
        String url = String(JAX_URL);

        // Createing Http connection
        HTTPClient http;

        // Checking endpoint url
        if (!http.begin(url + endpoint)) {
            log("HTTP", "Initialization failed!");
            return false;
        }

        // Createing Header
        http.addHeader("Content-Type", "application/json");

        // TEMPORARY FOR NOW
        if (!token.isEmpty()) {
        http.addHeader("X-Session-Token", token);
    }

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
                log("HTTP" , str(responseCode));
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
            log("HTTP", "Invalid JSON response!\n");
            return false;
        }

        return true;
    }