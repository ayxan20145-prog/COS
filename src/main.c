char *vga = (char *)0xb8000;

void kernel_main(void) {
  vga[0] = 'a';
  vga[1] = 0x0f;

  while(1) {}
}
