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
#else
  struct winsize ws = { 0 };
  size.width = ws.ws_col;
  size.height = ws.ws_row;
#endif // _WIN32
  return size;
}

int main(int argc, char** argv) {
  return 0;
}
