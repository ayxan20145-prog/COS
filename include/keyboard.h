#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>
#include "io.h"

uint8_t read_scancode(void);
char read_key(void);

#endif
