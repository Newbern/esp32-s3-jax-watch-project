#include "storage.h"

Preferences preferences;

void saveToken(String token)
{
    preferences.begin("jax", false);

    preferences.putString("token", token);

    preferences.end();
}

String loadToken()
{
    preferences.begin("jax", true);

    String token = preferences.getString("token", "");

    preferences.end();

    return token;
}

void deleteToken()
{
    preferences.begin("jax", false);

    preferences.remove("token");

    preferences.end();
}