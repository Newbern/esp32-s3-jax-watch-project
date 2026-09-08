#include "power.h"

/*----------GESTURES----------*/
XPowersAXP2101 PMU;

void battery_setup()
{
    if (!PMU.begin(Wire, AXP2101_SLAVE_ADDRESS, I2C_SDA, I2C_SCL)) {
        Serial.println("AXP2101 not found");
        while(1);
    }

    Serial.println("AXP2101 OK");
}

const char* battery_run() {

    static char batteryBuffer[20];
    static int lastBattery = -1;

    int battery = PMU.getBatteryPercent();

    if(battery != lastBattery)
    {
        lastBattery = battery;

        sprintf(
            batteryBuffer,
            "Battery: %d%%",
            battery
        );
    }

    return batteryBuffer;
}