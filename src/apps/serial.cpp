#include "app.h"

void serial_setup() {
    Serial.begin(115200);
    Serial.println("Serial is working!");
    Serial.println("WATCH STARTED");
}

void serial_run() {
    Serial.println("Hello from watch");
}