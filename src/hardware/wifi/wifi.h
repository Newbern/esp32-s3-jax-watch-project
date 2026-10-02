#ifndef WIFI_H
#define WIFI_H

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