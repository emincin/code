#include <stdio.h>

#define let auto

#define is_same(X, Y) _Generic((typeof_unqual(X)*)0, \
  typeof_unqual(Y)*: 1, \
  default: 0)

#define is_same_strict(X, Y) _Generic((typeof(X)*)0, \
  typeof(Y)*: 1, \
  default: 0)

#define print_is_same(a, b) \
  printf("%s %s %s\n", #a, is_same(a, b) ? "=" : "!", #b)

#define print_is_same_strict(a, b) \
  printf("%s %s %s\n", #a, is_same_strict(a, b) ? "=" : "!", #b)

#define print_is(a, b) printf("%s is %s\n", #a, #b)

typedef struct {
  int id;
  int x;
  int y;
} Player;

#define make_player(id, x, y) ((Player){ id, x, y })

void test_1(void) {
  print_is_same(int, int);
  print_is_same(Player, Player);
  print_is_same(int, Player);
  print_is_same(Player, int);
}

void test_2(void) {
  print_is_same(int, const int);
  print_is_same_strict(int, const int);
  print_is_same(const int, int);
  print_is_same_strict(const int, int);
}

void test_3(void) {
  print_is_same(int*, const int *);
  print_is_same(int*, int const *);
  print_is_same(int*, int * const);
  print_is_same(const int *, int const *);
}

void test_4(void) {
  let a = 0;
  if (is_same(a, int)) {
    print_is(a, int);
  } else if (is_same(a, double)) {
    print_is(a, double);
  } else if (is_same(a, char*)) {
    print_is(a, char*);
  } else if (is_same(a, Player)) {
    print_is(a, Player);
  }
}

void test(void) {
#ifdef TEST_1
  test_1();
#endif
#ifdef TEST_2
  test_2();
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
