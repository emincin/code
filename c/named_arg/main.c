#include <stdio.h>

#define CONCAT_IMPL(a, b) a##b

#define CONCAT(a, b) CONCAT_IMPL(a, b)

#define SELECT( \
  _1, _2, _3, _4, \
  _5, _6, _7, _8, \
  _9, _10, _11, _12, \
  _13, _14, _15, _16, \
  _17, _18, _19, _20, \
  _21, _22, _23, _24, \
  _25, _26, _27, _28, \
  _29, _30, _31, _32, \
  name, ...) name

#define COUNT_ARGS(...) __VA_OPT__( SELECT(__VA_ARGS__, \
  32, 31, 30, 29, \
  28, 27, 26, 25, \
  24, 23, 22, 21, \
  20, 19, 18, 17, \
  16, 15, 14, 13, \
  12, 11, 10, 9, \
  8, 7, 6, 5, \
  4, 3, 2, 1 \
  ))

#define EXPAND_1(func, var) func(var)
#define EXPAND_2(func, var, ...) func(var), EXPAND_1(func, __VA_ARGS__)
#define EXPAND_3(func, var, ...) func(var), EXPAND_2(func, __VA_ARGS__)
#define EXPAND_4(func, var, ...) func(var), EXPAND_3(func, __VA_ARGS__)
#define EXPAND_5(func, var, ...) func(var), EXPAND_4(func, __VA_ARGS__)
#define EXPAND_6(func, var, ...) func(var), EXPAND_5(func, __VA_ARGS__)
#define EXPAND_7(func, var, ...) func(var), EXPAND_6(func, __VA_ARGS__)
#define EXPAND_8(func, var, ...) func(var), EXPAND_7(func, __VA_ARGS__)
#define EXPAND_9(func, var, ...) func(var), EXPAND_8(func, __VA_ARGS__)
#define EXPAND_10(func, var, ...) func(var), EXPAND_9(func, __VA_ARGS__)
#define EXPAND_11(func, var, ...) func(var), EXPAND_10(func, __VA_ARGS__)
#define EXPAND_12(func, var, ...) func(var), EXPAND_11(func, __VA_ARGS__)
#define EXPAND_13(func, var, ...) func(var), EXPAND_12(func, __VA_ARGS__)
#define EXPAND_14(func, var, ...) func(var), EXPAND_13(func, __VA_ARGS__)
#define EXPAND_15(func, var, ...) func(var), EXPAND_14(func, __VA_ARGS__)
#define EXPAND_16(func, var, ...) func(var), EXPAND_15(func, __VA_ARGS__)
#define EXPAND_17(func, var, ...) func(var), EXPAND_16(func, __VA_ARGS__)
#define EXPAND_18(func, var, ...) func(var), EXPAND_17(func, __VA_ARGS__)
#define EXPAND_19(func, var, ...) func(var), EXPAND_18(func, __VA_ARGS__)
#define EXPAND_20(func, var, ...) func(var), EXPAND_19(func, __VA_ARGS__)
#define EXPAND_21(func, var, ...) func(var), EXPAND_20(func, __VA_ARGS__)
#define EXPAND_22(func, var, ...) func(var), EXPAND_21(func, __VA_ARGS__)
#define EXPAND_23(func, var, ...) func(var), EXPAND_22(func, __VA_ARGS__)
#define EXPAND_24(func, var, ...) func(var), EXPAND_23(func, __VA_ARGS__)
#define EXPAND_25(func, var, ...) func(var), EXPAND_24(func, __VA_ARGS__)
#define EXPAND_26(func, var, ...) func(var), EXPAND_25(func, __VA_ARGS__)
#define EXPAND_27(func, var, ...) func(var), EXPAND_26(func, __VA_ARGS__)
#define EXPAND_28(func, var, ...) func(var), EXPAND_27(func, __VA_ARGS__)
#define EXPAND_29(func, var, ...) func(var), EXPAND_28(func, __VA_ARGS__)
#define EXPAND_30(func, var, ...) func(var), EXPAND_29(func, __VA_ARGS__)
#define EXPAND_31(func, var, ...) func(var), EXPAND_30(func, __VA_ARGS__)
#define EXPAND_32(func, var, ...) func(var), EXPAND_31(func, __VA_ARGS__)

#define EXPAND(func, ...) __VA_OPT__(CONCAT(EXPAND_, COUNT_ARGS(__VA_ARGS__))(func, __VA_ARGS__))

#define dot(x) .x

#define make(type, ...) ((type){ EXPAND(dot, __VA_ARGS__) })

int main(int argc, char** argv) {
  return 0;
}
