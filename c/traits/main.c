#include <stdio.h>

#define is_c_str(expr) _Generic((expr), \
  char*: 1, \
  const char*: 1, \
  default: 0)

#define is_signed_type(T) ((T)(-1) < 0)

#define is_unsigned_type(T) ((T)(-1) > 0)

#define is_signed(expr) _Generic((expr), \
  char: is_signed_type(char), \
  signed char: 1, \
  short: 1, \
  int: 1, \
  long: 1, \
  long long: 1, \
  default: 0)

#define is_unsigned(expr) _Generic((expr), \
  char: is_unsigned_type(char), \
  _Bool: 1, \
  unsigned char: 1, \
  unsigned short: 1, \
  unsigned int: 1, \
  unsigned long: 1, \
  unsigned long long: 1, \
  default: 0)

#define is_integral(expr) (is_signed(expr) || is_unsigned(expr))

#define is_floating_point(expr) _Generic((expr), \
  float: 1, \
  double: 1, \
  long double: 1, \
  default: 0)

#define is_arithmetic(expr) (is_integral(expr) || is_floating_point(expr))

void test(void) {
}

int main(int argc, char** argv) {
  test();
  return 0;
}
