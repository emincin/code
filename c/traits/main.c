#include <stdio.h>

#define let auto

#define auto_var(name, expr) typeof(expr) name = (expr)

#define comptime_bool(expr) _Generic(&(char[1 + !!(expr)]){ 0 }, \
  char (*)[2]: 1, \
  char (*)[1]: 0)

#define constexpr(expr) (comptime_bool(expr))

#define is_c_str(expr) _Generic((expr), \
  char*: 1, \
  const char*: 1, \
  default: 0)

#define is_char_array(X) _Generic((typeof(X)*){ 0 }, \
  char (*)[sizeof(X)]: 1, \
  const char (*)[sizeof(X)]: 1, \
  default: 0)

#define is_char_pointer(expr) (is_c_str(expr) && !is_char_array(expr))

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

#define is_same(T1, T2) _Generic((typeof_unqual(T1)*){ 0 }, \
  typeof_unqual(T2)*: 1, \
  default: 0)

#define is_same_strict(T1, T2) _Generic((typeof(T1)*){ 0 }, \
  typeof(T2)*: 1, \
  default: 0)

#define is_pointer_of(T, X) _Generic((typeof(X)*){ 0 }, \
  typeof(T)**: 1, \
  default: 0)

void test(void) {
}

int main(int argc, char** argv) {
  test();
  return 0;
}
