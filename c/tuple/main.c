#include <stdio.h>

#define let auto

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
