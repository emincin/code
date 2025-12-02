#include <stdio.h>

#define let auto

struct { int x; int y; } make_xy(int x, int y) {
  return (typeof(make_xy(0, 0))){ x, y };
}

int main(int argc, char** argv) {
  let pos = make_xy(2, 1);
  printf("[x: %d, y: %d]\n", pos.x, pos.y);
  return 0;
}
