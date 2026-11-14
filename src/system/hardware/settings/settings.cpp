#include "settings.h"

void hardware_settings_setup() {
    // Serial Setup
    Serial.begin(115200);
    delay(500);

    // Display Setup
    location = "Display";
    display_setup();

    // Wire Setup
    location = "Wire";
    wire_setup();

    // Touch Setup
    location = "Touch";
    touch_setup();

}