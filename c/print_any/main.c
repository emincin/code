#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <inttypes.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

#define END "\n"
#define SEPARATOR " "

#define TYPE_NONE 0

#define TYPE_I8 1
#define TYPE_I16 2
#define TYPE_I32 3
#define TYPE_I64 4

#define TYPE_U8 5
#define TYPE_U16 6
#define TYPE_U32 7
#define TYPE_U64 8

#define TYPE_FLOAT 9
#define TYPE_DOUBLE 10

#define TYPE_STRING 11
#define TYPE_CSTRING 12

#define TYPE_CHAR 13
#define TYPE_ANY 14

#define TYPE_ID(t) _Generic((t), \
  i8: TYPE_I8,                   \
  i16: TYPE_I16,                 \
  i32: TYPE_I32,                 \
  i64: TYPE_I64,                 \
  u8: TYPE_U8,                   \
  u16: TYPE_U16,                 \
  u32: TYPE_U32,                 \
  u64: TYPE_U64,                 \
  float: TYPE_FLOAT,             \
  double: TYPE_DOUBLE,           \
  char*: TYPE_STRING,            \
  const char*: TYPE_CSTRING,     \
  char: TYPE_CHAR,               \
  void*: TYPE_ANY,               \
  default: TYPE_NONE)

#define TYPE_INFO(var) TYPE_ID(var), (var)

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

#define SELECT( \
  _1, _2, _3, _4, \
  _5, _6, _7, _8, \
  _9, _10, _11, _12, \
  _13, _14, _15, _16, \
  name, ...) name

#define EXPAND_ALL(func, ...) __VA_OPT__( \
  SELECT(__VA_ARGS__, \
    EXPAND_16, EXPAND_15, EXPAND_14, EXPAND_13, \
    EXPAND_12, EXPAND_11, EXPAND_10, EXPAND_9, \
    EXPAND_8, EXPAND_7, EXPAND_6, EXPAND_5, \
    EXPAND_4, EXPAND_3, EXPAND_2, EXPAND_1 \
  )(func, __VA_ARGS__))

#define COUNT_ARGS(...) __VA_OPT__( \
  SELECT(__VA_ARGS__, \
    16, 15, 14, 13, \
    12, 11, 10, 9, \
    8, 7, 6, 5, \
    4, 3, 2, 1 \
  ))

#define print_any(...) do { \
  if (sizeof(#__VA_ARGS__) == 1) printf("\n"); \
  __VA_OPT__(else print_any_func(COUNT_ARGS(__VA_ARGS__), EXPAND_ALL(TYPE_INFO, __VA_ARGS__));) \
} while (0)

void print_any_func(int count, ...) {
  va_list args;
  va_start(args, count);
  for (int i = 0; i < count; i++) {
    bool is_last_arg = (i == count - 1);
    int type = va_arg(args, int);
    if (type == TYPE_STRING || type == TYPE_CSTRING) {
      char* data = va_arg(args, char*);
      if (is_last_arg) {
        printf("%s" END, data);
      } else {
        printf("%s" SEPARATOR, data);
      }
    } else if (type == TYPE_I8 || type == TYPE_I16 || type == TYPE_I32 || type == TYPE_U8 || type == TYPE_U16) {
      int data = va_arg(args, int);
      if (is_last_arg) {
        printf("%d" END, data);
      } else {
        printf("%d" SEPARATOR, data);
      }
    } else if (type == TYPE_U32) {
      u32 data = va_arg(args, u32);
      if (is_last_arg) {
        printf("%u" END, data);
      } else {
        printf("%u" SEPARATOR, data);
      }
    } else if (type == TYPE_I64) {
    } else if (type == TYPE_U64) {
    } else if (type == TYPE_FLOAT || type == TYPE_DOUBLE) {
      double data = va_arg(args, double);
      if (is_last_arg) {
        printf("%f" END, data);
      } else {
        printf("%f" SEPARATOR, data);
      }
    } else if (type == TYPE_ANY) {
      void* data = va_arg(args, void*);
      if (is_last_arg) {
        printf("%p" END, data);
      } else {
        printf("%p" SEPARATOR, data);
      }
    } else if (type == TYPE_CHAR) {
      int data = va_arg(args, int);
      if (is_last_arg) {
        printf("%c" END, data);
      } else {
        printf("%c" SEPARATOR, data);
      }
    } else {
      break;
    }
  }
  va_end(args);
}

int main(int argc, char** argv) {
  return 0;
}
