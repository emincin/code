#include <stdio.h>

#define comptime_bool(expr) _Generic(&(char[1 + !!(expr)]){ 0 }, \
  char (*)[2]: 1, \
  char (*)[1]: 0)

#define if_constexpr(expr) if (comptime_bool(expr))

#define elif_constexpr(expr) else if (comptime_bool(expr))

int main(int argc, char** argv) {
  return 0;
}
