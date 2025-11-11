#include <assert.h>
#include <stdio.h>

#define let auto

#define comptime_bool(expr) _Generic(&(char[1 + !!(expr)]){ 0 }, \
  char (*)[2]: 1, \
  char (*)[1]: 0)

#define if_constexpr(expr) if (comptime_bool(expr))

#define elif_constexpr(expr) else if (comptime_bool(expr))

#define get_if_type(expr, T) _Generic((expr), \
  T: (expr), \
  default: (T){ 0 })

void if_vs_if_constexpr(void) {
  int x = 42;
  if (0) {} // OK
  if (x) {} // OK
  if_constexpr (0) {} // OK
  //if_constexpr (x) {} // compile-time error: compound literal cannot be of variable-length array type
}

void test(void) {
}

int main(int argc, char** argv) {
  test();
  return 0;
}
