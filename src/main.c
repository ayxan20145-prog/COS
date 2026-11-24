#include "vga.h"
#include "keyboard.h"

void kernel_main(void) {
  clear();
  print_string("hi\nhello");

  while(1) {
    char key = read_key();
    if (key != 0) {
      print_byte(key);
    }
  }
}
