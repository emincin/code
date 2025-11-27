#include <termios.h>
#include <stddef.h>
#include <stdio.h>

int main(int argc, char** argv) {
  printf("Size of termios: %zu bytes\n", sizeof(struct termios));
  printf("Align of termios: %zu bytes\n", _Alignof(struct termios));
  printf("Offset of c_iflag:  %zu\n", offsetof(struct termios, c_iflag));
  printf("Offset of c_oflag:  %zu\n", offsetof(struct termios, c_oflag));
  printf("Offset of c_cflag:  %zu\n", offsetof(struct termios, c_cflag));
  printf("Offset of c_lflag:  %zu\n", offsetof(struct termios, c_lflag));
  printf("Offset of c_cc:     %zu\n", offsetof(struct termios, c_cc));
  printf("Offset of c_ispeed: %zu\n", offsetof(struct termios, c_ispeed));
  printf("Offset of c_ospeed: %zu\n", offsetof(struct termios, c_ospeed));
  return 0;
}
