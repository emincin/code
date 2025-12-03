#include <stdio.h>

#define is_same(T1, T2) _Generic((typeof_unqual(T1)*){ 0 }, \
  typeof_unqual(T2)*: 1, \
  default: 0)

#define is_same_strict(T1, T2) _Generic((typeof(T1)*){ 0 }, \
  typeof(T2)*: 1, \
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

void test_1(void) {
  print_is_same(int, int);
  print_is_same(Player, Player);
  print_is_same(int, Player);
  print_is_same(Player, int);
}

void test_2(void) {
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
