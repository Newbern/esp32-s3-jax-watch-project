#include "logs.h"

const char* source = "LOG";
const char* location = "LOG";

void log(const char* action, const char* bonus) {
    String body = String(source) + " | " + String(location) + " | " + action;

    if (bonus[0] != '\0') {
        body += ": ";
        body += bonus;
    }

    print(body.c_str());
}