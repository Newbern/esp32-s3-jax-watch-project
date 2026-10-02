#ifndef STORAGE_H
#define STORAGE_H

#include <Arduino.h>
#include <Preferences.h>

void saveToken(String token);
String loadToken();
void deleteToken();

#endif