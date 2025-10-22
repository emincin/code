#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END "\n"
#define SEPARATOR " "
#define LEFT_BRACE '{'
#define RIGHT_BRACE '}'
#define STRING_CAPACITY 32
#define PRINT(s) printf("%s", s)

typedef struct print_config_t {
  const char* end;
  const char* sep;
} PrintConfig;

#define as_print_config_ptr(x) _Generic((x), \
  PrintConfig*: (x), \
  default: NULL)

#define CONCAT_IMPL(a, b) a##b
#define CONCAT(a, b) CONCAT_IMPL(a, b)

#define SELECT( \
  _1, _2, _3, _4, \
  _5, _6, _7, _8, \
  _9, _10, _11, _12, \
  _13, _14, _15, _16, \
  name, ...) name

#define COUNT_ARGS(...) __VA_OPT__( SELECT(__VA_ARGS__, \
  16, 15, 14, 13, \
  12, 11, 10, 9, \
  8, 7, 6, 5, \
  4, 3, 2, 1 \
  ))

#define ARGS_COUNT(...) (0 __VA_OPT__(+ COUNT_ARGS(__VA_ARGS__)))

#define TYPE_NONE           0
#define TYPE_BOOL           1
#define TYPE_CHAR           2
#define TYPE_SCHAR          3
#define TYPE_UCHAR          4
#define TYPE_SHORT          5
#define TYPE_INT            6
#define TYPE_LONG           7
#define TYPE_LONGLONG       8
#define TYPE_USHORT         9
#define TYPE_UINT           10
#define TYPE_ULONG          11
#define TYPE_ULONGLONG      12
#define TYPE_FLOAT          13
#define TYPE_DOUBLE         14
#define TYPE_STRING         15
#define TYPE_CONST_STRING   16
#define TYPE_ANY            17
#define TYPE_CONST_ANY      18

#define typeid_of(x) _Generic((x), \
  _Bool:              TYPE_BOOL, \
  char:               TYPE_CHAR, \
  signed char:        TYPE_SCHAR, \
  unsigned char:      TYPE_UCHAR, \
  short:              TYPE_SHORT, \
  int:                TYPE_INT, \
  long:               TYPE_LONG, \
  long long:          TYPE_LONGLONG, \
  unsigned short:     TYPE_USHORT, \
  unsigned int:       TYPE_UINT, \
  unsigned long:      TYPE_ULONG, \
  unsigned long long: TYPE_ULONGLONG, \
  float:              TYPE_FLOAT, \
  double:             TYPE_DOUBLE, \
  char*:              TYPE_STRING, \
  const char*:        TYPE_CONST_STRING, \
  void*:              TYPE_ANY, \
  const void*:        TYPE_CONST_ANY, \
  default:            TYPE_NONE)

#define type_value_pair(x) typeid_of(x), (x)
#define dot(x) .x

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

#define LAST_1(a) a
#define LAST_2(a, b) b
#define LAST_3(a, b, c) c
#define LAST_4(a, b, c, d) d
#define LAST_5(a, b, c, d, e) e
#define LAST_6(a, b, c, d, e, f) f
#define LAST_7(a, b, c, d, e, f, g) g
#define LAST_8(a, b, c, d, e, f, g, h) h
#define LAST_9(a, b, c, d, e, f, g, h, i) i
#define LAST_10(a, b, c, d, e, f, g, h, i, j) j
#define LAST_11(a, b, c, d, e, f, g, h, i, j, k) k
#define LAST_12(a, b, c, d, e, f, g, h, i, j, k, l) l
#define LAST_13(a, b, c, d, e, f, g, h, i, j, k, l, m) m
#define LAST_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) n
#define LAST_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) o
#define LAST_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) p

#define EXPAND(func, ...) __VA_OPT__( \
  CONCAT(EXPAND_, COUNT_ARGS(__VA_ARGS__))(func, __VA_ARGS__))

#define LAST(...) __VA_OPT__(CONCAT(LAST_, COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__))

#define set(...) (&(PrintConfig){ EXPAND(dot, __VA_ARGS__) })

#define print(...) do { \
  __VA_OPT__( \
    print_func( \
      as_print_config_ptr(LAST(__VA_ARGS__)), \
      COUNT_ARGS(__VA_ARGS__), \
      EXPAND(type_value_pair, __VA_ARGS__) \
    ); \
    break; \
  ) \
  print_func(NULL, ARGS_COUNT(__VA_ARGS__)); \
} while (0)

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef struct string_t {
  size_t capacity;
  size_t size;
  char* data;
} String;

size_t calculate_capacity(size_t size) {
  size_t capacity = 0;
  const size_t max = SIZE_MAX;
  if (size > 0) {
    capacity = 1;
    while (capacity < size) {
      if (capacity > max / 2) {
        return max;
      }
      capacity *= 2;
    }
  }
  return capacity;
}

void string_init(String* self, size_t capacity) {
  assert(self != NULL);
  char* buf = (char*)malloc(capacity + 1);
  if (buf == NULL) {
    *self = (String){ 0 };
    return;
  }
  buf[0] = 0;
  self->capacity = capacity;
  self->size = 0;
  self->data = buf;
}

void string_deinit(String* self) {
  assert(self != NULL);
  free(self->data);
  *self = (String){ 0 };
}

bool string_realloc(String* self, size_t new_capacity) {
  assert(self != NULL);
  return true;
}

bool string_insert_sn(String* self, size_t pos, const char* s, size_t n) {
  assert(self != NULL);
  if (pos > self->size) {
    pos = self->size;
  }
  size_t new_size = self->size + n;
  if (new_size > self->capacity) {
    size_t new_capacity = calculate_capacity(new_size);
    bool ok = string_realloc(self, new_capacity);
    if (!ok) {
      return false;
    }
  }
  memmove(self->data + pos + n, self->data + pos, self->size - pos);
  memcpy(self->data + pos, s, n);
  self->size = new_size;
  return true;
}

void print_func(PrintConfig* config, int count, ...) {
  const char* end = END;
  const char* sep = SEPARATOR;
  if (config) {
    if (config->end) {
      end = config->end;
    }
    if (config->sep) {
      sep = config->sep;
    }
  }
  va_list args;
  va_start(args, count);
  String str = { 0 };
  string_init(&str, STRING_CAPACITY);
  for (int i = 0; i < count; i++) {
    int type = va_arg(args, int);
    if (type == TYPE_STRING || type == TYPE_CONST_STRING) {
      char* data = va_arg(args, char*);
    } else {
      break;
    }
  }
  if (str.data) {
    PRINT(str.data);
  }
clean_up:
  string_deinit(&str);
  va_end(args);
}

int main(int argc, char** argv) {
  return 0;
}
