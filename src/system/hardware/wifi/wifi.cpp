#include "wifi.h"
#include "wifi_credentials.h"


Wifi wifi;

bool Wifi::setup() {

    for (int i = 0; i < wifi_count; i++) {

        clear_print();
        log("Connecting", ssids[i]);

        WiFi.begin(ssids[i], passwords[i]);

        for (int attempt = 0; attempt < 5; attempt++) {

            if (WiFi.status() == WL_CONNECTED) {
                log(ssids[i], "Connected");
                log("Local IP", str(WiFi.localIP()));

                return true;
            }

            delay(500);
            print(".");
        }
        print("");
        log("Connection", "Failed\n");

        WiFi.disconnect();
    }

    log("Connection", "Not Available\n");
    return false;
}

bool Wifi::connected() {
    return WiFi.status() == WL_CONNECTED;
}

String Wifi::name(){
    if (!connected()){
        return "No Wifi Name";
    }
    return WiFi.SSID();
}

String Wifi::password(){
    if (!connected()){
        return "No Wifi Password";
    }
    return WiFi.psk();
}

String Wifi::ip(){
    if (!connected()){
        return "No Wifi connected, No IP_Address.";
    }
    return WiFi.localIP().toString();
}

