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

#define TYPE_ID(t) _Generic((t), \
  default: TYPE_NONE)

int main(int argc, char** argv) {
  return 0;
}
