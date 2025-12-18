#include <stdio.h>

#define let auto

#define type_of(T) typeof(*(T*)0)

#define DEFINE_1(func, var) func(var) item1;
#define DEFINE_2(func, var, ...) DEFINE_1(func, __VA_ARGS__) func(var) item2;
#define DEFINE_3(func, var, ...) DEFINE_2(func, __VA_ARGS__) func(var) item3;
#define DEFINE_4(func, var, ...) DEFINE_3(func, __VA_ARGS__) func(var) item4;
#define DEFINE_5(func, var, ...) DEFINE_4(func, __VA_ARGS__) func(var) item5;
#define DEFINE_6(func, var, ...) DEFINE_5(func, __VA_ARGS__) func(var) item6;
#define DEFINE_7(func, var, ...) DEFINE_6(func, __VA_ARGS__) func(var) item7;
#define DEFINE_8(func, var, ...) DEFINE_7(func, __VA_ARGS__) func(var) item8;
#define DEFINE_9(func, var, ...) DEFINE_8(func, __VA_ARGS__) func(var) item9;
#define DEFINE_10(func, var, ...) DEFINE_9(func, __VA_ARGS__) func(var) item10;
#define DEFINE_11(func, var, ...) DEFINE_10(func, __VA_ARGS__) func(var) item11;
#define DEFINE_12(func, var, ...) DEFINE_11(func, __VA_ARGS__) func(var) item12;
#define DEFINE_13(func, var, ...) DEFINE_12(func, __VA_ARGS__) func(var) item13;
#define DEFINE_14(func, var, ...) DEFINE_13(func, __VA_ARGS__) func(var) item14;
#define DEFINE_15(func, var, ...) DEFINE_14(func, __VA_ARGS__) func(var) item15;
#define DEFINE_16(func, var, ...) DEFINE_15(func, __VA_ARGS__) func(var) item16;
#define DEFINE_17(func, var, ...) DEFINE_16(func, __VA_ARGS__) func(var) item17;
#define DEFINE_18(func, var, ...) DEFINE_17(func, __VA_ARGS__) func(var) item18;
#define DEFINE_19(func, var, ...) DEFINE_18(func, __VA_ARGS__) func(var) item19;
#define DEFINE_20(func, var, ...) DEFINE_19(func, __VA_ARGS__) func(var) item20;
#define DEFINE_21(func, var, ...) DEFINE_20(func, __VA_ARGS__) func(var) item21;
#define DEFINE_22(func, var, ...) DEFINE_21(func, __VA_ARGS__) func(var) item22;
#define DEFINE_23(func, var, ...) DEFINE_22(func, __VA_ARGS__) func(var) item23;
#define DEFINE_24(func, var, ...) DEFINE_23(func, __VA_ARGS__) func(var) item24;
#define DEFINE_25(func, var, ...) DEFINE_24(func, __VA_ARGS__) func(var) item25;
#define DEFINE_26(func, var, ...) DEFINE_25(func, __VA_ARGS__) func(var) item26;
#define DEFINE_27(func, var, ...) DEFINE_26(func, __VA_ARGS__) func(var) item27;
#define DEFINE_28(func, var, ...) DEFINE_27(func, __VA_ARGS__) func(var) item28;
#define DEFINE_29(func, var, ...) DEFINE_28(func, __VA_ARGS__) func(var) item29;
#define DEFINE_30(func, var, ...) DEFINE_29(func, __VA_ARGS__) func(var) item30;
#define DEFINE_31(func, var, ...) DEFINE_30(func, __VA_ARGS__) func(var) item31;
#define DEFINE_32(func, var, ...) DEFINE_31(func, __VA_ARGS__) func(var) item32;

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

#define STR_IMPL(x) (char*)#x

#define STR(x) STR_IMPL(x)

#define DEFINE_FUNC(x) typeof(x)

#define DEFINE(func, ...) __VA_OPT__(CONCAT(DEFINE_, COUNT_ARGS(__VA_ARGS__))(func, __VA_ARGS__))

#define REVERSE(...) __VA_OPT__(CONCAT(REVERSE_, COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__))

#define tuple_t(...) struct { DEFINE(DEFINE_FUNC, REVERSE(__VA_ARGS__)) }

#define tuple_t2(...) struct { size_t count; DEFINE(DEFINE_FUNC, REVERSE(__VA_ARGS__)) }

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
  // make_tuple:
  tuple_t(int, char*) kv = make_tuple(42, "hello");
  printf("%d %s\n", kv.item1, kv.item2);
  // tuple:
  let name = tuple("Emin", "Cin");
  printf("%s %s\n", name.item1, name.item2);
  // tuple2:
  let keywords = tuple2(STR(if), STR(while), STR(for), STR(let), STR(const), STR(fn));
  char** address = (char**)&keywords.item1;
  printf("count: %zu\n", keywords.count);
  for (size_t i = 0; i < keywords.count; i++) {
    printf("item%zu: %s\n", i + 1, address[i]);
  }
}

typedef tuple_t(char*, int, int, int) version_t;

version_t get_version(void) {
  return (version_t) { "1.0.0", 1, 0, 0 };
}

void test_3(void) {
  version_t v = get_version();
  printf("%s [major: %d, minor: %d, patch: %d]\n", v.item1, v.item2, v.item3, v.item4);
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
}

int main(int argc, char** argv) {
  test();
  return 0;
}
