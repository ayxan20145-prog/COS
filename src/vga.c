#include "vga.h"

uint8_t *vga = (uint8_t *)0xb8000;
uint8_t row = 0;
uint8_t column = 0;

void print_byte(char byte) {
  if(byte == '\n') {
    column = 0;
    row++;
    return;
  }

  if(column >= 80) {
    column = 0;
    row++;
  }

  int position = row * 80 + column;

  vga[position * 2] = byte;
  vga[position * 2 + 1] = 0x0f;

  column++;
}
void print_string(char str[]) {
  for(int i = 0; str[i] != '\0'; i++) {
    print_byte(str[i]);
  }
}
void clear(void) {
  for(int i = 0; i < 2000; i++) {
    vga[i * 2] = ' ';
    vga[i * 2 + 1] = 0x0f;
  }
}
