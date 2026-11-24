#include "shell.h"

void shell(void) {
  print_string("# ");

  char cmd_buffer[256];
  size_t cmd_len = 0;

  while (1) {
    char key = read_key();
    if (key != 0) {
      if (key == '\n') {
        if (cmd_len == 0) {
          print_string("\n\n# ");
        } else {
          cmd_buffer[cmd_len + 1] = '\0';
          if (cmd_len == 5 && strcmp(cmd_buffer, "clear") == 0) {
            clear();
            print_string("# ");
          } else {
            print_string("\nunknown command\n");
            print_string("# ");
          }
        }
        cmd_len = 0;
      } else if (key == '\b') {
        if (cmd_len > 0) {
          cmd_len--;
          print_byte('\b');
        }
      } else {
        if (cmd_len < 256) {
          cmd_buffer[cmd_len] = key;
          cmd_len++;
          print_byte(key);
        }
      }
    }
  }
}
