#include <assert.h>
#include <stdio.h>

#define let auto

#define comptime_bool(expr) _Generic(&(char[1 + !!(expr)]){ 0 }, \
  char (*)[2]: 1, \
  char (*)[1]: 0)

#define constexpr(expr) (comptime_bool(expr))

#define get_if_type(expr, T) _Generic((expr), \
  T: (expr), \
  default: (T){ 0 })

#define is_same(X, Y) _Generic((typeof_unqual(X)*)0, \
  typeof_unqual(Y)*: 1, \
  default: 0)

#define is_same_strict(X, Y) _Generic((typeof(X)*)0, \
  typeof(Y)*: 1, \
  default: 0)

typedef struct {
  int width;
  int height;
} Size;

#define make_size(w, h) ((Size){ w, h })

void if_vs_if_constexpr(void) {
  int x = 42;
  if (x) {} // OK
  //if constexpr (x) {} // compile-time error: compound literal cannot be of variable-length array type
}

void test_1(void) {
  let a = 42;
  if constexpr (is_same(a, int)) {
    int value = get_if_type(a, int);
    printf("1: %d\n", value);
  }
  if constexpr (is_same(a, int*)) {
    int* value = get_if_type(a, int*);
    assert(value != NULL);
    printf("2: %d\n", *value);
  }
  if constexpr (is_same(a, Size)) {
    Size value = get_if_type(a, Size);
    printf("3: [width: %d, height: %d]\n", value.width, value.height);
  }
}

void test_2(void) {
}

void test(void) {
#ifdef TEST_1
  test_1();
#endif
#ifdef TEST_2
  test_2();
#endif
}

int main(int argc, char** argv) {
  test();
  return 0;
}
