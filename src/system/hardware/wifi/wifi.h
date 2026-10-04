#ifndef WIFI_H
#define WIFI_H

// Wifi Setup
#include <WiFi.h>

// Getting Wifi Credentials
extern const char* ssids[];
extern const char* passwords[];
extern const int wifi_count;

// Request
#include <HTTPClient.h>
#include <ArduinoJson.h>
// #include "storage/storage.h"
// #include "functions/functions.h"
#include "system/software/run/app.h"

class Wifi {
public:
    bool  setup();
    bool connected();
    String name();
    String password();
    String ip();

};

extern Wifi wifi;

#endif