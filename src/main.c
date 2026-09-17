char *vga = (char *)0xb8000;
int row = 0;
int column = 0;

void print(char byte) {
  int position = row * 80 + column;

  vga[position * 2] = byte;
  vga[position * 2 + 1] = 0x0f;

  column++;
}
void kernel_main(void) {
  print('h');
  print('i');

  while(1) {}
}
