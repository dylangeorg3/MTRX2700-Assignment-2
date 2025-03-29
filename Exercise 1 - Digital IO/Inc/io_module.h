#ifndef IO_MODULE_H
#define IO_MODULE_H

#include <stdint.h>

void io_init(void (*callback)(void));
void io_set_led(uint8_t state);
uint8_t io_get_led(void);

#endif
