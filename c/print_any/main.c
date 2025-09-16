#include <stdint.h>
#include <stdio.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

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
  default: TYPE_NONE)

#define TYPE_INFO(var) TYPE_ID(var), (var)

int main(int argc, char** argv) {
  return 0;
}
