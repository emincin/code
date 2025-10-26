#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END "\n"
#define SEPARATOR " "
#define FILE_STREAM stdout
#define FLUSH_STREAM false

#define LEFT_BRACE '{'
#define RIGHT_BRACE '}'
#define STRING_CAPACITY 32
#define TEMP_BUFFER_SIZE 32

#define FPRINTSN(fp, s, n) fprintf(fp, "%s", s)
#define FFLUSH(fp) fflush(fp)

#define COLOR_DARK_BLACK      0
#define COLOR_DARK_RED        1
#define COLOR_DARK_GREEN      2
#define COLOR_DARK_YELLOW     3
#define COLOR_DARK_BLUE       4
#define COLOR_DARK_MAGENTA    5
#define COLOR_DARK_CYAN       6
#define COLOR_DARK_WHITE      7
#define COLOR_BRIGHT_BLACK    8
#define COLOR_BRIGHT_RED      9
#define COLOR_BRIGHT_GREEN    10
#define COLOR_BRIGHT_YELLOW   11
#define COLOR_BRIGHT_BLUE     12
#define COLOR_BRIGHT_MAGENTA  13
#define COLOR_BRIGHT_CYAN     14
#define COLOR_BRIGHT_WHITE    15

#define COLOR_BLACK           COLOR_DARK_BLACK
#define COLOR_RED             COLOR_DARK_RED
#define COLOR_GREEN           COLOR_DARK_GREEN
#define COLOR_YELLOW          COLOR_DARK_YELLOW
#define COLOR_BLUE            COLOR_DARK_BLUE
#define COLOR_MAGENTA         COLOR_DARK_MAGENTA
#define COLOR_CYAN            COLOR_DARK_CYAN
#define COLOR_WHITE           COLOR_DARK_WHITE

#define RESET_STYLE "\033[0m"

#define ERR_OK              0
#define ERR_FAIL            1

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
#define TYPE_STRING_PTR               19
#define TYPE_CONST_STRING_PTR         20
#define TYPE_COLOR24                  21
#define TYPE_COLOR24_PTR              22
#define TYPE_CONST_COLOR24_PTR        23

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
#define LAST_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) q
#define LAST_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) r
#define LAST_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) s
#define LAST_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) t
#define LAST_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) u
#define LAST_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) v
#define LAST_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) w
#define LAST_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) x
#define LAST_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) y
#define LAST_26(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) z
#define LAST_27(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A) A
#define LAST_28(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B) B
#define LAST_29(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C) C
#define LAST_30(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D) D
#define LAST_31(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E) E
#define LAST_32(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F) F

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

#define CONCAT_IMPL(a, b) a##b

#define CONCAT(a, b) CONCAT_IMPL(a, b)

#define ARGS_COUNT(...) (0 __VA_OPT__(+ COUNT_ARGS(__VA_ARGS__)))

#define EXPAND(func, ...) __VA_OPT__(CONCAT(EXPAND_, COUNT_ARGS(__VA_ARGS__))(func, __VA_ARGS__))

#define LAST(...) __VA_OPT__(CONCAT(LAST_, COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__))

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
  String*:            TYPE_STRING_PTR, \
  const String*:      TYPE_CONST_STRING_PTR, \
  Color24:            TYPE_COLOR24, \
  Color24*:           TYPE_COLOR24_PTR, \
  const Color24*:     TYPE_CONST_COLOR24_PTR, \
  default:            TYPE_NONE)

#define format_of(x) _Generic((x), \
  _Bool:              "%d", \
  char:               "%c", \
  signed char:        "%hhd", \
  unsigned char:      "%hhu", \
  short:              "%hd", \
  int:                "%d", \
  long:               "%ld", \
  long long:          "%lld", \
  unsigned short:     "%hu", \
  unsigned int:       "%u", \
  unsigned long:      "%lu", \
  unsigned long long: "%llu", \
  float:              "%f", \
  double:             "%f", \
  char*:              "%s", \
  const char*:        "%s", \
  void*:              "%p", \
  const void*:        "%p", \
  default:            "")

#define typeid_value_pair(x) typeid_of(x), (x)

#define dot(x) .x

#define const_of_ptr(x) ((const typeof(*(x))*)(x))

#define as_print_config_ptr(x) _Generic((x), \
  PrintConfig*: (x), \
  default: NULL)

#define read_from_value(str, value, err) do { \
  char buf[TEMP_BUFFER_SIZE] = { 0 }; \
  const char* fmt = format_of(value); \
  int len = snprintf(buf, sizeof(buf), fmt, value); \
  if (len < 0) { err = ERR_FAIL; break; } \
  bool ok = string_append_sn(str, buf, len); \
  if (!ok) { err = ERR_FAIL; break; } \
  err = ERR_OK; \
} while (0)

#define rgb(r, g, b) ((Color24){ r, g, b })

#define set(...) (&(PrintConfig){ EXPAND(dot, __VA_ARGS__) })

#define format(fmt, ...) \
  format_func(fmt, ARGS_COUNT(__VA_ARGS__) __VA_OPT__(,) EXPAND(typeid_value_pair, __VA_ARGS__))

#define print(...) do { \
  __VA_OPT__( \
    print_func( \
      as_print_config_ptr(LAST(__VA_ARGS__)), \
      COUNT_ARGS(__VA_ARGS__), \
      EXPAND(typeid_value_pair, __VA_ARGS__) \
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

typedef struct color24_t {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} Color24;

typedef struct print_config_t {
  const char* sep;
  const char* end;
  FILE* file;
  bool flush;
} PrintConfig;

typedef struct string_t {
  size_t capacity;
  size_t size;
  char* data;
} String;

String* format_func(const char* fmt, int count, ...);

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
  char* buf = (char*)calloc(capacity + 1, sizeof(char));
  if (buf == NULL) {
    *self = (String){ 0 };
    return;
  }
  self->capacity = capacity;
  self->size = 0;
  self->data = buf;
}

void string_deinit(String* self) {
  assert(self != NULL);
  free(self->data);
  *self = (String){ 0 };
}

String* string_new(size_t capacity) {
  String* self = (String*)malloc(sizeof(String));
  if (self == NULL) {
    return NULL;
  }
  string_init(self, capacity);
  return self;
}

void string_delete(String* self) {
  assert(self != NULL);
  free(self->data);
  free(self);
}

bool string_realloc(String* self, size_t new_capacity) {
  assert(self != NULL);
  char* buf = (char*)realloc(self->data, new_capacity + 1);
  if (buf == NULL) {
    return false;
  }
  if (new_capacity > self->capacity) {
    memset(buf + self->capacity + 1, 0, new_capacity - self->capacity);
  } else if (new_capacity < self->size) {
    buf[new_capacity] = 0;
    self->size = new_capacity;
  }
  self->capacity = new_capacity;
  self->data = buf;
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

bool string_insert_s(String* self, size_t pos, const char* s) {
  assert(self != NULL);
  size_t n = strlen(s);
  return string_insert_sn(self, pos, s, n);
}

bool string_append_sn(String* self, const char* s, size_t n) {
  assert(self != NULL);
  return string_insert_sn(self, self->size, s, n);
}

bool string_append_s(String* self, const char* s) {
  assert(self != NULL);
  size_t n = strlen(s);
  return string_append_sn(self, s, n);
}

size_t read_from_va_list(String* str, int type, va_list* args_ptr) {
  switch (type) {
    case TYPE_NONE:
    {
      return 0;
    }
    case TYPE_BOOL:
    case TYPE_CHAR:
    case TYPE_SCHAR:
    case TYPE_UCHAR:
    case TYPE_SHORT:
    case TYPE_USHORT:
    case TYPE_INT:
    {
      int arg = va_arg(*args_ptr, int);
      int err = 0;
      read_from_value(str, arg, err);
      return sizeof(arg);
    }
    case TYPE_UINT:
    {
      unsigned int arg = va_arg(*args_ptr, unsigned int);
      int err = 0;
      read_from_value(str, arg, err);
      return sizeof(arg);
    }
    case TYPE_LONG:
    {
      long arg = va_arg(*args_ptr, long);
      int err = 0;
      read_from_value(str, arg, err);
      return sizeof(arg);
    }
    case TYPE_ULONG:
    {
      unsigned long arg = va_arg(*args_ptr, unsigned long);
      int err = 0;
      read_from_value(str, arg, err);
      return sizeof(arg);
    }
    case TYPE_LONGLONG:
    {
      long long arg = va_arg(*args_ptr, long long);
      int err = 0;
      read_from_value(str, arg, err);
      return sizeof(arg);
    }
    case TYPE_ULONGLONG:
    {
      unsigned long long arg = va_arg(*args_ptr, unsigned long long);
      int err = 0;
      read_from_value(str, arg, err);
      return sizeof(arg);
    }
    case TYPE_FLOAT:
    case TYPE_DOUBLE:
    {
      double arg = va_arg(*args_ptr, double);
      int err = 0;
      read_from_value(str, arg, err);
      return sizeof(arg);
    }
    case TYPE_STRING:
    case TYPE_CONST_STRING:
    {
      char* arg = va_arg(*args_ptr, char*);
      size_t len = strlen(arg);
      if (len == 0) {
        return 1;
      }
      bool ok = string_append_sn(str, arg, len);
      return len;
    }
    case TYPE_ANY:
    case TYPE_CONST_ANY:
    {
      void* arg = va_arg(*args_ptr, void*);
      int err = 0;
      read_from_value(str, arg, err);
      return sizeof(arg);
    }
    case TYPE_STRING_PTR:
    case TYPE_CONST_STRING_PTR:
    {
      String* arg = va_arg(*args_ptr, String*);
      size_t len = arg->size;
      if (len == 0) {
        return 1;
      }
      bool ok = string_append_sn(str, arg->data, len);
      if (type == TYPE_STRING_PTR) {
        string_delete(arg);
      }
      return len;
    }
    case TYPE_COLOR24:
    {
      Color24 arg = va_arg(*args_ptr, Color24);
      String* temp = format("[R:{} G:{} B:{}]", arg.r, arg.g, arg.b);
      size_t len = temp->size;
      string_append_sn(str, temp->data, len);
      string_delete(temp);
      return len;
    }
    case TYPE_COLOR24_PTR:
    case TYPE_CONST_COLOR24_PTR:
    {
      Color24* arg = va_arg(*args_ptr, Color24*);
      String* temp = format("[R:{} G:{} B:{}]", arg->r, arg->g, arg->b);
      size_t len = temp->size;
      string_append_sn(str, temp->data, len);
      string_delete(temp);
      return len;
    }
  }
  return 0;
}

int format_from_va_list(String* str, const char* fmt, int count, va_list* args_ptr) {
  int arg_index = 0;
  size_t fmtlen = strlen(fmt);
  for (size_t i = 0; i < fmtlen; i++) {
    bool match = false;
    if (fmt[i] == LEFT_BRACE) {
      size_t next_i = i + 1;
      if (next_i < fmtlen && fmt[next_i] == LEFT_BRACE) {
        i = next_i;
      } else {
        for (size_t j = i + 1; j < fmtlen; j++) {
          if (fmt[j] == RIGHT_BRACE) {
            i = j;
            match = true;
            break;
          }
        }
      }
    }
    if (match) {
      if (arg_index < count) {
        int type = va_arg(*args_ptr, int);
        size_t ret = read_from_va_list(str, type, args_ptr);
        arg_index++;
      }
    } else {
      string_append_sn(str, fmt + i, 1);
    }
  }
  return arg_index;
}

void parse_va_list(String* str, const char* sep, int count, va_list args) {
  size_t seplen = strlen(sep);
  for (int i = 0; i < count; i++) {
    int type = va_arg(args, int);
    if (i == 0 && (type == TYPE_STRING || type == TYPE_CONST_STRING)) {
      char* fmt = va_arg(args, char*);
      int ret = format_from_va_list(str, fmt, count - 1, &args);
      i += ret;
    } else {
      size_t ret = read_from_va_list(str, type, &args);
      if (ret == 0) {
        break;
      }
    }
    if (i < count - 1) {
      bool ok = string_append_sn(str, sep, seplen);
    }
  }
}

String* format_func(const char* fmt, int count, ...) {
  String* str = string_new(STRING_CAPACITY);
  va_list args;
  va_start(args, count);
  format_from_va_list(str, fmt, count, &args);
  va_end(args);
  return str;
}

void print_func(PrintConfig* config, int count, ...) {
  const char* sep = SEPARATOR;
  const char* end = END;
  FILE* file = FILE_STREAM;
  bool flush = FLUSH_STREAM;
  if (config) {
    count -= 1;
    if (config->sep) {
      sep = config->sep;
    }
    if (config->end) {
      end = config->end;
    }
    if (config->file) {
      file = config->file;
    }
    if (config->flush) {
      flush = config->flush;
    }
  }
  va_list args;
  va_start(args, count);
  String a = { 0 };
  string_init(&a, STRING_CAPACITY);
  parse_va_list(&a, sep, count, args);
  string_append_s(&a, end);
  if (a.data) {
    FPRINTSN(file, a.data, a.size);
    if (flush) {
      FFLUSH(file);
    }
  }
  string_deinit(&a);
  va_end(args);
}

String* set_cursor_pos(int x, int y) {
  return format("\033[{};{}H", y + 1, x + 1);
}

String* set_fg_idx(int idx) {
  return format("\033[38;5;{}m", idx);
}

String* set_fg_rgb(int r, int g, int b) {
  return format("\033[38;2;{};{};{}m", r, g, b);
}

String* set_fg_color(Color24 color) {
  return set_fg_rgb(color.r, color.g, color.b);
}

String* set_bg_idx(int idx) {
  return format("\033[48;5;{}m", idx);
}

String* set_bg_rgb(int r, int g, int b) {
  return format("\033[48;2;{};{};{}m", r, g, b);
}

String* set_bg_color(Color24 color) {
  return set_bg_rgb(color.r, color.g, color.b);
}

String* set_colors_idx(int fg_idx, int bg_idx) {
  return format("\033[38;5;{};48;5;{}m", fg_idx, bg_idx);
}

String* set_colors_rgb(int fg_r, int fg_g, int fg_b, int bg_r, int bg_g, int bg_b) {
  return format("\033[38;2;{};{};{};48;2;{};{};{}m", fg_r, fg_g, fg_b, bg_r, bg_g, bg_b);
}

String* set_colors_color(Color24 fg_color, Color24 bg_color) {
  return set_colors_rgb(fg_color.r, fg_color.g, fg_color.b, bg_color.r, bg_color.g, bg_color.b);
}

const char* reset_style(void) {
  return RESET_STYLE;
}

void print_256_color_table(void) {
  for (int i = 0; i < 256; i++) {
    char buf[4] = { 0 };
    snprintf(buf, sizeof(buf), "%3d", i);
    print(set_bg_idx(i), buf, reset_style(), set(sep = "", end = ""));
    if ((i + 1) % 16 == 0) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
}

void print_any_test(void) {
  print();
  print("Hello", "Emin", 42, 3.141592);
}

void print_fmt_test(void) {
  print("{} is {}", "Emin", 42);
}

void print_color_test(void) {
  print(set_colors_idx(COLOR_RED, COLOR_WHITE), "REDRUM", reset_style(), set(sep = ""));
  print(set_fg_rgb(102, 255, 178), "Here is Johnny~", reset_style(), set(sep = ""));
}

void test_1(void) {
  print(1, 2, set(sep = "", end = ""));
  print(3, 4, set(sep = "", end = ""));
  print(set_cursor_pos(2, 1), set(end = ""));
  print(set_fg_idx(COLOR_BRIGHT_GREEN), format("{}/{}", 70, 100), reset_style(), set(sep = ""));
}

void test_2(void) {
  String* content = format("{{+} print in {}", "C23");
  print(const_of_ptr(content));
  FILE* file = fopen("test.txt", "wb");
  print(content, set(file = file));
  fclose(file);
}

void test_3(void) {
  Color24 color = rgb(255, 0, 0);
  print(color);
  print(&color);
  print(set_fg_color(color), "MURDER", reset_style(), set(sep = ""));
}

void test(void) {
#ifdef PRINT_ANY_TEST
  print_any_test();
#endif
#ifdef PRINT_FMT_TEST
  print_fmt_test();
#endif
#ifdef PRINT_COLOR_TEST
  print_color_test();
#endif
#ifdef PRINT_256_COLOR_TABLE
  print_256_color_table();
#endif
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
