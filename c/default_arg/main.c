#include <stdio.h>

#define SELECT_1(_1, ...) _1
#define SELECT_2(_1, _2, ...) _2
#define SELECT_3(_1, _2, _3, ...) _3
#define SELECT_4(_1, _2, _3, _4, ...) _4
#define SELECT_5(_1, _2, _3, _4, _5, ...) _5
#define SELECT_6(_1, _2, _3, _4, _5, _6, ...) _6
#define SELECT_7(_1, _2, _3, _4, _5, _6, _7, ...) _7
#define SELECT_8(_1, _2, _3, _4, _5, _6, _7, _8, ...) _8
#define SELECT_9(_1, _2, _3, _4, _5, _6, _7, _8, _9, ...) _9
#define SELECT_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) _10
#define SELECT_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, ...) _11
#define SELECT_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, ...) _12
#define SELECT_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, ...) _13
#define SELECT_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, ...) _14
#define SELECT_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, ...) _15
#define SELECT_16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, ...) _16
#define SELECT_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, ...) _17

#define NO_ARG(...) SELECT_2(__VA_OPT__(,) 0, 1)
#define HAS_ARG(...) SELECT_2(__VA_OPT__(,) 1, 0)

#define COUNT_ARGS(...) __VA_OPT__( SELECT_17(__VA_ARGS__, \
  16, 15, 14, 13, \
  12, 11, 10, 9, \
  8, 7, 6, 5, \
  4, 3, 2, 1 \
  ))

#define ARGS_COUNT(...) (0 __VA_OPT__(+ COUNT_ARGS(__VA_ARGS__)))

#define static_assert_expr(expr, msg) \
  (sizeof( struct { static_assert(expr, msg); char c; } ) > 0)

void print_abc_func(int a, int b, int c) {
  printf("%d %d %d\n", a, b, c);
}

void print_info_func(const char* name, int age) {
  printf("[Name:\"%s\" Age:%d]\n", name, age);
}

#define print_abc(...) SELECT_4(__VA_OPT__(__VA_ARGS__,) \
  print_abc_func(__VA_ARGS__), \
  print_abc_func(__VA_ARGS__, 3), \
  print_abc_func(__VA_ARGS__, 2, 3), \
  print_abc_func(1, 2, 3))

#define print_info(...) SELECT_3(__VA_OPT__(__VA_ARGS__,) \
  print_info_func(__VA_ARGS__), \
  print_info_func(__VA_ARGS__, 0), \
  print_info_func("Unknown", 0))

void print_abc_test(void) {
  print_abc(1, 2, 3);
  print_abc(1, 2);
  print_abc(1);
  print_abc();
}

void print_info_test(void) {
  print_info("Emin", 42);
  print_info("Emin");
  print_info();
}

void test(void) {
#ifdef TEST_1
  print_abc_test();
#endif
#ifdef TEST_2
  print_info_test();
#endif
}

int main(int argc, char** argv) {
  test();
  return 0;
}
