#include <stdio.h>

#define is_c_str(expr) _Generic((expr), \
  char*: 1, \
  const char*: 1, \
  default: 0)

void test(void) {
}

int main(int argc, char** argv) {
  test();
  return 0;
}
