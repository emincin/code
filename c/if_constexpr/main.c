#include <stdio.h>

#define comptime_bool(expr) _Generic(&(char[1 + !!(expr)]){ 0 }, \
  char (*)[2]: 1, \
  char (*)[1]: 0)

#define if_constexpr(expr) if (comptime_bool(expr))

#define elif_constexpr(expr) else if (comptime_bool(expr))

void if_vs_if_constexpr(void) {
  int x = 42;
  if (0) {} // OK
  if (x) {} // OK
  if_constexpr (0) {} // OK
  //if_constexpr (x) {} // compile-time error: compound literal cannot be of variable-length array type
}

int main(int argc, char** argv) {
  return 0;
}
