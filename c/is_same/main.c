#include <stdio.h>

#define is_same(T1, T2) _Generic(*(T1*)0, \
  typeof_unqual(T2): 1, \
  default: 0)

#define print_is_same(T1, T2) \
  printf("(%s) = (%s) : %d\n", #T1, #T2, is_same(T1, T2))

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
  print_is_same(int, int);
  print_is_same(Player, Player);
  print_is_same(int, Player);
  print_is_same(Player, int);
}

void const_test(void) {
  print_is_same(int, const int);
  print_is_same(const int, int);
  print_is_same(char*, const char*);
  print_is_same(const char*, char*);
}

void test(void) {
#ifdef IS_SAME_TEST
  is_same_test();
#endif
#ifdef CONST_TEST
  const_test();
#endif
}

int main(int argc, char** argv) {
  test();
  return 0;
}
