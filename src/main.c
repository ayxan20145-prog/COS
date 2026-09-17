#include "vga.h"

void kernel_main(void) {
  clear();
  print_string("hi\nhello");

  while(1) {}
}
