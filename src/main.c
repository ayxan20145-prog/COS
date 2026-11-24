#include "vga.h"
#include "shell.h"

void kernel_main(void) {
  clear();
  shell();
}
