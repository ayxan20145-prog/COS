char *vga = (char *)0xb8000;
int row = 0;
int column = 0;

void print(char byte) {
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
void clear(void) {
  for(int i = 0; i < 2000; i++) {
    vga[i * 2] = ' ';
    vga[i * 2 + 1] = 0x0f;
  }
}
void kernel_main(void) {
  clear();
  print('h');
  print('i');

  while(1) {}
}
