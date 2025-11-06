#include <stdio.h>

typedef struct {
  int id;
  int x;
  int y;
} Player;

void convert_test(void) {
  //Player a = (Player)0; // compile-time error: arithmetic or pointer type is required
  Player* b = (Player*)0; // OK
}

void is_same_test(void) {
}

void test(void) {
#ifdef IS_SAME_TEST
  is_same_test();
#endif
}

int main(int argc, char** argv) {
  test();
  return 0;
}
