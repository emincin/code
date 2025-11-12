#include <stdio.h>

#define is_same(T1, T2) _Generic((T1){ 0 }, \
  typeof_unqual(T2): 1, \
  default: 0)

#define print_is_same(T1, T2) \
  printf("(%s) = (%s) : %d\n", #T1, #T2, is_same(T1, T2))

#define print_is(a, b) printf("%s is %s\n", #a, #b)

typedef struct {
  int id;
  int x;
  int y;
} Player;

#define make_player(id, x, y) ((Player){ id, x, y })

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

void test_3(void) {
  print_is_same(int*, const int *);
  print_is_same(int*, int const *);
  print_is_same(int*, int * const);
  print_is_same(const int *, int const *);
}

void test_4(void) {
  auto a = 0;
  if (is_same(typeof(a), int)) {
    print_is(a, int);
  } else if (is_same(typeof(a), double)) {
    print_is(a, double);
  } else if (is_same(typeof(a), char*)) {
    print_is(a, char*);
  } else if (is_same(typeof(a), Player)) {
    print_is(a, Player);
  }
}

void test(void) {
#ifdef IS_SAME_TEST
  is_same_test();
#endif
#ifdef CONST_TEST
  const_test();
#endif
#ifdef TEST_3
  test_3();
#endif
#ifdef TEST_4
  test_4();
#endif
}

int main(int argc, char** argv) {
  test();
  return 0;
}
