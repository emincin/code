#include <stdio.h>

#define is_c_str(expr) _Generic((expr), \
  char*: 1, \
  const char*: 1, \
  default: 0)

#define is_signed_type(T) ((T)(-1) < 0)

#define is_unsigned_type(T) ((T)(-1) > 0)

#define is_signed(expr) _Generic((expr), \
  char: is_signed_type(char), \
  default: 0)

#define is_unsigned(expr) _Generic((expr), \
  char: is_unsigned_type(char), \
  default: 0)

void test(void) {
}

int main(int argc, char** argv) {
  test();
  return 0;
}
