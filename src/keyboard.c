#include "keyboard.h"

const char KEYMAP[128] = {
  [0x02] = '1', [0x03] = '2',
};

uint8_t read_scancode(void) {
  while ((inb(0x64) & 1) == 0) {
    continue;
  }
  return inb(0x60);
}

char read_key(void) {
  uint8_t scancode = read_scancode();

  if ((scancode & 0x80) != 0) {
    return 0;
  }

  return KEYMAP[scancode];
}
