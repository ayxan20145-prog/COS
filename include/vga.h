#ifndef VGA_H
#define VGA_H

#include <stdint.h>
#include "io.h"

void print_byte(char byte);
void print_string(char str[]);
void clear(void);
void update_cursor(uint8_t column, uint8_t row);

#endif
