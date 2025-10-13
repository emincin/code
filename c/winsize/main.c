#if defined(_WIN32)
#include <windows.h>
#else
#include <sys/ioctl.h>
#endif // _WIN32
#include <stdio.h>

typedef struct {
  int width;
  int height;
} Size;

void print_size(Size size) {
  printf("[width: %d, height: %d]\n", size.width, size.height);
}

Size term_get_window_size(void) {
  Size size = { 0 };
#if defined(_WIN32)
  HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
  if (output == NULL || output == INVALID_HANDLE_VALUE) {
    return size;
  }
  CONSOLE_SCREEN_BUFFER_INFO csbi = { 0 };
  BOOL ok = GetConsoleScreenBufferInfo(output, &csbi);
  if (!ok) {
    return size;
  }
  size.width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  size.height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#else
  struct winsize ws = { 0 };
  // STDIN_FILENO/STDOUT_FILENO/STDERR_FILENO: 0/1/2
  // TIOCGWINSZ: Terminal I/O Control Get Window Size
  int ret = ioctl(1, TIOCGWINSZ, &ws);
  if (ret == -1) {
    return size;
  }
  size.width = ws.ws_col;
  size.height = ws.ws_row;
#endif // _WIN32
  return size;
}

void test_1(void) {
  while (1) {
    print_size(term_get_window_size());
  }
}

int main(int argc, char** argv) {
  return 0;
}
