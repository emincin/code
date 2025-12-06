#include <stdio.h>

#define let auto

#define DEF_1(var) typeof(var) item1;
#define DEF_2(var, ...) DEF_1(__VA_ARGS__) typeof(var) item2;
#define DEF_3(var, ...) DEF_2(__VA_ARGS__) typeof(var) item3;
#define DEF_4(var, ...) DEF_3(__VA_ARGS__) typeof(var) item4;
#define DEF_5(var, ...) DEF_4(__VA_ARGS__) typeof(var) item5;
#define DEF_6(var, ...) DEF_5(__VA_ARGS__) typeof(var) item6;
#define DEF_7(var, ...) DEF_6(__VA_ARGS__) typeof(var) item7;
#define DEF_8(var, ...) DEF_7(__VA_ARGS__) typeof(var) item8;
#define DEF_9(var, ...) DEF_8(__VA_ARGS__) typeof(var) item9;
#define DEF_10(var, ...) DEF_9(__VA_ARGS__) typeof(var) item10;
#define DEF_11(var, ...) DEF_10(__VA_ARGS__) typeof(var) item11;
#define DEF_12(var, ...) DEF_11(__VA_ARGS__) typeof(var) item12;
#define DEF_13(var, ...) DEF_12(__VA_ARGS__) typeof(var) item13;
#define DEF_14(var, ...) DEF_13(__VA_ARGS__) typeof(var) item14;
#define DEF_15(var, ...) DEF_14(__VA_ARGS__) typeof(var) item15;
#define DEF_16(var, ...) DEF_15(__VA_ARGS__) typeof(var) item16;
#define DEF_17(var, ...) DEF_16(__VA_ARGS__) typeof(var) item17;
#define DEF_18(var, ...) DEF_17(__VA_ARGS__) typeof(var) item18;
#define DEF_19(var, ...) DEF_18(__VA_ARGS__) typeof(var) item19;
#define DEF_20(var, ...) DEF_19(__VA_ARGS__) typeof(var) item20;
#define DEF_21(var, ...) DEF_20(__VA_ARGS__) typeof(var) item21;
#define DEF_22(var, ...) DEF_21(__VA_ARGS__) typeof(var) item22;
#define DEF_23(var, ...) DEF_22(__VA_ARGS__) typeof(var) item23;
#define DEF_24(var, ...) DEF_23(__VA_ARGS__) typeof(var) item24;
#define DEF_25(var, ...) DEF_24(__VA_ARGS__) typeof(var) item25;
#define DEF_26(var, ...) DEF_25(__VA_ARGS__) typeof(var) item26;
#define DEF_27(var, ...) DEF_26(__VA_ARGS__) typeof(var) item27;
#define DEF_28(var, ...) DEF_27(__VA_ARGS__) typeof(var) item28;
#define DEF_29(var, ...) DEF_28(__VA_ARGS__) typeof(var) item29;
#define DEF_30(var, ...) DEF_29(__VA_ARGS__) typeof(var) item30;
#define DEF_31(var, ...) DEF_30(__VA_ARGS__) typeof(var) item31;
#define DEF_32(var, ...) DEF_31(__VA_ARGS__) typeof(var) item32;

#define REVERSE_1(x) x
#define REVERSE_2(x, ...) REVERSE_1(__VA_ARGS__), x
#define REVERSE_3(x, ...) REVERSE_2(__VA_ARGS__), x
#define REVERSE_4(x, ...) REVERSE_3(__VA_ARGS__), x
#define REVERSE_5(x, ...) REVERSE_4(__VA_ARGS__), x
#define REVERSE_6(x, ...) REVERSE_5(__VA_ARGS__), x
#define REVERSE_7(x, ...) REVERSE_6(__VA_ARGS__), x
#define REVERSE_8(x, ...) REVERSE_7(__VA_ARGS__), x
#define REVERSE_9(x, ...) REVERSE_8(__VA_ARGS__), x
#define REVERSE_10(x, ...) REVERSE_9(__VA_ARGS__), x
#define REVERSE_11(x, ...) REVERSE_10(__VA_ARGS__), x
#define REVERSE_12(x, ...) REVERSE_11(__VA_ARGS__), x
#define REVERSE_13(x, ...) REVERSE_12(__VA_ARGS__), x
#define REVERSE_14(x, ...) REVERSE_13(__VA_ARGS__), x
#define REVERSE_15(x, ...) REVERSE_14(__VA_ARGS__), x
#define REVERSE_16(x, ...) REVERSE_15(__VA_ARGS__), x
#define REVERSE_17(x, ...) REVERSE_16(__VA_ARGS__), x
#define REVERSE_18(x, ...) REVERSE_17(__VA_ARGS__), x
#define REVERSE_19(x, ...) REVERSE_18(__VA_ARGS__), x
#define REVERSE_20(x, ...) REVERSE_19(__VA_ARGS__), x
#define REVERSE_21(x, ...) REVERSE_20(__VA_ARGS__), x
#define REVERSE_22(x, ...) REVERSE_21(__VA_ARGS__), x
#define REVERSE_23(x, ...) REVERSE_22(__VA_ARGS__), x
#define REVERSE_24(x, ...) REVERSE_23(__VA_ARGS__), x
#define REVERSE_25(x, ...) REVERSE_24(__VA_ARGS__), x
#define REVERSE_26(x, ...) REVERSE_25(__VA_ARGS__), x
#define REVERSE_27(x, ...) REVERSE_26(__VA_ARGS__), x
#define REVERSE_28(x, ...) REVERSE_27(__VA_ARGS__), x
#define REVERSE_29(x, ...) REVERSE_28(__VA_ARGS__), x
#define REVERSE_30(x, ...) REVERSE_29(__VA_ARGS__), x
#define REVERSE_31(x, ...) REVERSE_30(__VA_ARGS__), x
#define REVERSE_32(x, ...) REVERSE_31(__VA_ARGS__), x

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

#define ARGS_COUNT(...) (0 __VA_OPT__(+ COUNT_ARGS(__VA_ARGS__)))

#define CONCAT_IMPL(a, b) a##b

#define CONCAT(a, b) CONCAT_IMPL(a, b)

#define DEF(...) __VA_OPT__(CONCAT(DEF_, COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__))

#define REVERSE(...) __VA_OPT__(CONCAT(REVERSE_, COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__))

#define tuple_t(...) struct { DEF(REVERSE(__VA_ARGS__)) }

#define tuple_t2(...) struct { int count; DEF(REVERSE(__VA_ARGS__)) }

#define make_tuple(...) { __VA_ARGS__ }

#define make_tuple2(...) { ARGS_COUNT(__VA_ARGS__) __VA_OPT__(, __VA_ARGS__) }

#define tuple(...) ((tuple_t(__VA_ARGS__)) make_tuple(__VA_ARGS__))

#define tuple2(...) ((tuple_t2(__VA_ARGS__)) make_tuple2(__VA_ARGS__))

struct { int x; int y; } make_xy(int x, int y) {
  return (typeof(make_xy(0, 0))){ x, y };
}

void test_1(void) {
  let pos = make_xy(2, 1);
  printf("[x: %d, y: %d]\n", pos.x, pos.y);
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
