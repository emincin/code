#include <stdio.h>

#define let auto

#define SELECT( \
  _1, _2, _3, _4, \
  _5, _6, _7, _8, \
  _9, _10, _11, _12, \
  _13, _14, _15, _16, \
  _17, _18, _19, _20, \
  _21, _22, _23, _24, \
  _25, _26, _27, _28, \
  _29, _30, _31, _32, \
  name, ...) name

#define COUNT_ARGS(...) __VA_OPT__( SELECT(__VA_ARGS__, \
  32, 31, 30, 29, \
  28, 27, 26, 25, \
  24, 23, 22, 21, \
  20, 19, 18, 17, \
  16, 15, 14, 13, \
  12, 11, 10, 9, \
  8, 7, 6, 5, \
  4, 3, 2, 1 \
  ))

#define ARGS_COUNT(...) (0 __VA_OPT__(+ COUNT_ARGS(__VA_ARGS__)))

#define CONCAT_IMPL(a, b) a##b

#define CONCAT(a, b) CONCAT_IMPL(a, b)

#define make_tuple(...) { ARGS_COUNT(__VA_ARGS__) __VA_OPT__(, __VA_ARGS__) }

struct { int x; int y; } make_xy(int x, int y) {
  return (typeof(make_xy(0, 0))){ x, y };
}

void test_1(void) {
  let pos = make_xy(2, 1);
  printf("[x: %d, y: %d]\n", pos.x, pos.y);
}

void test(void) {
#ifdef TEST_1
  test_1();
#endif
}

int main(int argc, char** argv) {
  test();
  return 0;
}
