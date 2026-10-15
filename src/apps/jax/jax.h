#ifndef JAX_H
#define JAX_H

#pragma once

#include "apps/apps.h"
#include "jax_credentials.h"
#include "system/hardware/storage/jax_storage/jax_stoarge.h"

void jax_setup();
void jax_run(TouchPoint pressed);

bool jax_request(
    const char* endpoint, 
    const String& body, 
    JsonDocument& response,
    bool post
);



#endif