#include <termios.h>
#include <stddef.h>
#include <stdio.h>

int main(int argc, char** argv) {
  printf("Size of termios: %zu bytes\n", sizeof(struct termios));
  printf("Align of termios: %zu bytes\n", _Alignof(struct termios));
  return 0;
}
