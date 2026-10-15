#ifndef JAX_STORAGE_H
#define JAX_STORAGE_H

#include <Arduino.h>

// Setup
void jax_storage_setup();

// API KEY
void save_api_key(const String& api_key);
String get_api_key();
void delete_api_key();

// Session_Token
void save_token(const String& token);
String get_token();
void delete_token();


#endif