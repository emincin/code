#if __has_include(<termios.h>)
#include <termios.h>
#endif

#if __has_include(<windows.h>)
#include <windows.h>
#endif

#include <stddef.h>
#include <stdio.h>

void show_termios_info(void) {
#if __has_include(<termios.h>)
  struct termios term = { 0 };
  printf("Size of termios: %zu bytes\n", sizeof(struct termios));
  printf("Align of termios: %zu bytes\n", _Alignof(struct termios));
  printf("Size of c_iflag:  %zu\n", sizeof(term.c_iflag));
  printf("Size of c_oflag:  %zu\n", sizeof(term.c_oflag));
  printf("Size of c_cflag:  %zu\n", sizeof(term.c_cflag));
  printf("Size of c_lflag:  %zu\n", sizeof(term.c_lflag));
  printf("Size of c_cc:     %zu\n", sizeof(term.c_cc));
  printf("Size of c_ispeed: %zu\n", sizeof(term.c_ispeed));
  printf("Size of c_ospeed: %zu\n", sizeof(term.c_ospeed));
  printf("Offset of c_iflag:  %zu\n", offsetof(struct termios, c_iflag));
  printf("Offset of c_oflag:  %zu\n", offsetof(struct termios, c_oflag));
  printf("Offset of c_cflag:  %zu\n", offsetof(struct termios, c_cflag));
  printf("Offset of c_lflag:  %zu\n", offsetof(struct termios, c_lflag));
  printf("Offset of c_cc:     %zu\n", offsetof(struct termios, c_cc));
  printf("Offset of c_ispeed: %zu\n", offsetof(struct termios, c_ispeed));
  printf("Offset of c_ospeed: %zu\n", offsetof(struct termios, c_ospeed));
#endif
}

void test(void) {
}

int main(int argc, char** argv) {
  test();
  return 0;
}
