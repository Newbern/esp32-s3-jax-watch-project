#include "logs.h"

void log(const char* location, const char* app, const char* action, const char* bonus = "") {
    String body = String(location) + " | " + app + " | " + action;

    if (bonus[0] != '\0') {
        body += " -> ";
        body += bonus;
    }

    Serial.println(body);
}