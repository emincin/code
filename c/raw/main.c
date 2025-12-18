#if __has_include(<termios.h>)
#include <termios.h>
#endif

#if __has_include(<windows.h>)
#include <windows.h>
#endif

#include <stdbool.h>
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

bool enable_raw_mode(void) {
#if __has_include(<termios.h>)
#elif __has_include(<windows.h>)
  HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
  if (handle == NULL || handle == INVALID_HANDLE_VALUE) {
    return false;
  }
  BOOL ok = false;
  DWORD mode = 0;
  ok = GetConsoleMode(handle, &mode);
  if (!ok) {
    return false;
  }
  mode &= ~ENABLE_PROCESSED_INPUT;
  mode &= ~ENABLE_LINE_INPUT;
  mode &= ~ENABLE_ECHO_INPUT;
  mode |= ENABLE_VIRTUAL_TERMINAL_INPUT;
  ok = SetConsoleMode(handle, mode);
  if (!ok) {
    return false;
  }
  return true;
#endif
  return false;
}

bool disable_raw_mode(void) {
#if __has_include(<termios.h>)
#elif __has_include(<windows.h>)
#endif
  return false;
}

void test(void) {
}

int main(int argc, char** argv) {
  test();
  return 0;
}
