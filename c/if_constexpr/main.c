#include <assert.h>
#include <stdio.h>

#define let auto

#define comptime_bool(expr) _Generic(&(char[1 + !!(expr)]){ 0 }, \
  char (*)[2]: 1, \
  char (*)[1]: 0)

#define if_constexpr(expr) if (comptime_bool(expr))

#define elif_constexpr(expr) else if (comptime_bool(expr))

#define get_if_type(expr, T) _Generic((expr), \
  T: (expr), \
  default: (T){ 0 })

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define is_array(x) _Generic(&(x), \
  typeof(*(x)) (*)[ARRAY_SIZE(x)]: 1, \
  default: 0)

#define is_same(T1, T2) _Generic(*(T1*)0, \
  typeof_unqual(T2): 1, \
  default: 0)

void if_vs_if_constexpr(void) {
  int x = 42;
  if (0) {} // OK
  if (x) {} // OK
  if_constexpr (0) {} // OK
  //if_constexpr (x) {} // compile-time error: compound literal cannot be of variable-length array type
}

typedef struct {
  int width;
  int height;
} Size;

#define make_size(w, h) ((Size){ w, h })

void print_size(Size size) {
  printf("[width: %d, height: %d]\n", size.width, size.height);
}

void sfinae_test(void) {
#if SFINAE_TEST_1
  let a = 42;
#elif SFINAE_TEST_2
  int id = 100;
  let a = &id;
#elif SFINAE_TEST_3
  let a = make_size(80, 24);
#else
  void* a = NULL;
#endif
  if_constexpr (is_same(typeof(a), int)) {
    int value = get_if_type(a, int);
    printf("%d\n", value);
  }
  if_constexpr (is_same(typeof(a), int*)) {
    int* value = get_if_type(a, int*);
    printf("%d\n", *value);
  }
  if_constexpr (is_same(typeof(a), Size)) {
    Size value = get_if_type(a, Size);
    print_size(value);
  }
}

void test(void) {
  sfinae_test();
}

int main(int argc, char** argv) {
  test();
  return 0;
}
