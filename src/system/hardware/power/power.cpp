#include "power.h"

/*----------GESTURES----------*/
XPowersAXP2101 PMU;

void battery_setup()
{
    if (!PMU.begin(Wire, AXP2101_SLAVE_ADDRESS, I2C_SDA, I2C_SCL)) {
        log("Error: AXP2101 Not Found");
        while(1);
    }

    log("Battery", "Initializing");
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
            "%d%%",
            battery
        );
    }

    return batteryBuffer;
}