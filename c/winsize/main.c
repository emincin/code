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

Size term_get_window_size(void) {
  Size size = { 0 };
#if defined(_WIN32)
#else
#endif // _WIN32
  return size;
}

int main(int argc, char** argv) {
  return 0;
}
