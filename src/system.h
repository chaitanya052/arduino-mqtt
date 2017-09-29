#ifndef LWMQTT_ARDUINO_H
#define LWMQTT_ARDUINO_H

#include <Arduino.h>
#include <Client.h>

extern "C" {
#include "lwmqtt/lwmqtt.h"
};

typedef struct { uint32_t end; } lwmqtt_arduino_timer_t;

void lwmqtt_arduino_timer_set(lwmqtt_client_t *client, void *ref, uint32_t timeout);

uint32_t lwmqtt_arduino_timer_get(lwmqtt_client_t *client, void *ref);

typedef struct { Client *client; } lwmqtt_arduino_network_t;

lwmqtt_err_t lwmqtt_arduino_network_read(lwmqtt_client_t *client, void *ref, uint8_t *buf, size_t len, size_t *read,
                                         uint32_t timeout);
lwmqtt_err_t lwmqtt_arduino_network_write(lwmqtt_client_t *client, void *ref, uint8_t *buf, size_t len, size_t *sent,
                                          uint32_t timeout);

#endif  // LWMQTT_ARDUINO_H
