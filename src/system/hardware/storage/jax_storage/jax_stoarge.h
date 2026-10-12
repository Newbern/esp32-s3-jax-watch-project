#ifndef JAX_STORAGE_H
#define JAX_STORAGE_H

#include <Arduino.h>

void jax_storage_setup();
void save_api_key(const String& api_key);
String get_api_key();
void delete_api_key();

#endif