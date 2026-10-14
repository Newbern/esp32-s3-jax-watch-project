#include "system/hardware/storage/jax_storage/jax_stoarge.h"
#include <Preferences.h>

// Creating storage object
static Preferences preferences;

// Setting up jax storage
void jax_storage_setup() {
    // Creates namespace folder called "jax" & enables write mode (to read only use true)
    preferences.begin("jax", false);
}

void save_api_key(const String& api_key) {
    // Creating Storage String for api key & Saving
    preferences.putString("api_key", api_key);
}

String get_api_key() {
    // Returning api key, if the api_key doesn't exist it will return nothing as the api_key
    return preferences.getString("api_key", "");
}

String get_token() {
    // Returning Session token for applications
    return preferences.getString("token", "");
}

void delete_api_key() {
    // Removing api key
    preferences.remove("api_key");
}