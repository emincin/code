#ifndef STR_H
#define STR_H
#include <stddef.h>

#ifndef STR_CAPACITY
#define STR_CAPACITY 32
#endif // STR_CAPACITY

typedef struct str_t {
  size_t size;
  size_t capacity;
  char* data;
} Str;

size_t calc_capacity(size_t size);

Str* str_new_cstr_n(const char* buf, size_t len);
Str* str_new_cstr(const char* buf);
Str* str_new_str(const Str* other);
Str* str_new_char_n(char c, size_t n);
Str* str_new_capacity(size_t capacity);
Str* str_new_(void);
size_t str_append_cstr_n(Str* str, const char* buf, size_t len);
size_t str_append_cstr(Str* str, const char* buf);
size_t str_append_str(Str* str, const Str* other);
size_t str_append_char_n(Str* str, char c, size_t n);
size_t str_append_char(Str* str, char c);
Str* str_substr_pos_n(Str* str, size_t pos, size_t len);
Str* str_substr_pos(Str* str, size_t pos);
Str* str_slice_from_to(Str* str, int start, int end);
Str* str_slice_from(Str* str, int start);
size_t str_insert_cstr_n(Str* str, size_t pos, const char* buf, size_t len);
size_t str_insert_cstr(Str* str, size_t pos, const char* buf);
size_t str_resize_n_char(Str* str, size_t new_size, char c);
size_t str_resize_n(Str* str, size_t new_size);
size_t str_expand(Str* str, size_t new_capacity);
size_t str_shrink(Str* str, size_t new_capacity);
void str_print(const Str* str);
void str_println(const Str* str);
void str_clear(Str* str);
void str_reset(Str* str);
void str_delete(Str* str);

Str* short_to_str(short value);
Str* ushort_to_str(unsigned short value);
Str* int_to_str(int value);
Str* uint_to_str(unsigned int value);
Str* long_to_str(long value);
Str* ulong_to_str(unsigned long value);
Str* longlong_to_str(long long value);
Str* ulonglong_to_str(unsigned long long value);
Str* float_to_str(float value);
Str* double_to_str(double value);
Str* ptr_to_str(void* value);

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112)

#ifndef NO_GENERIC
#define HAS_GENERIC 1
#endif // NO_GENERIC

#endif // __STDC_VERSION__

#ifdef HAS_GENERIC

#define CONCAT(a, b) CONCAT_IMPL(a, b)
#define CONCAT_IMPL(a, b) a##b

#define COUNT(...) __VA_OPT__(COUNT_IMPL(__VA_ARGS__, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))
#define COUNT_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, n, ...) n

#define OVERLOAD(name, ...) CONCAT(name, COUNT(__VA_ARGS__))
#define INVOKE_OVERLOAD(name, ...) OVERLOAD(name, __VA_ARGS__)(__VA_ARGS__)

#define str_new_1(a) _Generic((a), \
  int: str_new_capacity, \
  unsigned int: str_new_capacity, \
  long: str_new_capacity, \
  unsigned long: str_new_capacity, \
  long long: str_new_capacity, \
  unsigned long long: str_new_capacity, \
  char*: str_new_cstr, \
  const char*: str_new_cstr, \
  Str*: str_new_str, \
  const Str*: str_new_str, \
  default: NULL \
)(a)

#define str_new_2(a, b) _Generic((a), \
  char*: str_new_cstr_n, \
  const char*: str_new_cstr_n, \
  char: str_new_char_n, \
  int: str_new_char_n, \
  default: NULL \
)(a, b)

#define str_append_2(a, b) _Generic((b), \
  char: str_append_char, \
  int: str_append_char, \
  char*: str_append_cstr, \
  const char*: str_append_cstr, \
  Str*: str_append_str, \
  const Str*: str_append_str, \
  default: NULL \
)(a, b)

#define str_append_3(a, b, c) _Generic((b), \
  char: str_append_char_n, \
  int: str_append_char_n, \
  char*: str_append_cstr_n, \
  const char*: str_append_cstr_n, \
  default: NULL \
)(a, b, c)

#define str_substr_2 str_substr_pos
#define str_substr_3 str_substr_pos_n

#define str_slice_2 str_slice_from
#define str_slice_3 str_slice_from_to

#define str_insert_3 str_insert_cstr
#define str_insert_4 str_insert_cstr_n

#define str_resize_2 str_resize_n
#define str_resize_3 str_resize_n_char

#define str_new(...) INVOKE_OVERLOAD(str_new_, __VA_ARGS__)
#define str_append(...) INVOKE_OVERLOAD(str_append_, __VA_ARGS__)
#define str_substr(...) INVOKE_OVERLOAD(str_substr_, __VA_ARGS__)
#define str_slice(...) INVOKE_OVERLOAD(str_slice_, __VA_ARGS__)
#define str_insert(...) INVOKE_OVERLOAD(str_insert_, __VA_ARGS__)
#define str_resize(...) INVOKE_OVERLOAD(str_resize_, __VA_ARGS__)

#define to_str(a) _Generic((a), \
  short: short_to_str, \
  unsigned short: ushort_to_str, \
  int: int_to_str, \
  unsigned int: uint_to_str, \
  long: long_to_str, \
  unsigned long: ulong_to_str, \
  long long: longlong_to_str, \
  unsigned long long: ulonglong_to_str, \
  float: float_to_str, \
  double: double_to_str, \
  void*: ptr_to_str, \
  default: NULL \
)(a)

#endif // HAS_GENERIC

#endif // STR_H


#ifdef STR_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t calc_capacity(size_t size) {
  size_t capacity = 0;
  if (size > 0) {
    capacity = 1;
    while (capacity < size) {
      capacity *= 2;
    }
  }
  return capacity;
}

Str* str_new_cstr_n(const char* buf, size_t len) {
  if (buf == NULL) return NULL;
  size_t capacity = calc_capacity(len);
  Str* str = str_new_capacity(capacity);
  if (str == NULL) {
    return NULL;
  }
  memcpy(str->data, buf, len);
  str->size = len;
  return str;
}

Str* str_new_cstr(const char* buf) {
  if (buf == NULL) return NULL;
  return str_new_cstr_n(buf, strlen(buf));
}

Str* str_new_str(const Str* other) {
  return str_new_cstr_n(other->data, other->size);
}

Str* str_new_char_n(char c, size_t n) {
  size_t capacity = calc_capacity(n);
  Str* str = str_new_capacity(capacity);
  if (str == NULL) {
    return NULL;
  }
  str_append_char_n(str, c, n);
  return str;
}

Str* str_new_capacity(size_t capacity) {
  Str* str = (Str*)malloc(sizeof(Str));
  if (str == NULL) {
    return NULL;
  }
  char* buffer = (char*)calloc(capacity + 1, sizeof(char));
  if (buffer == NULL) {
    goto clean_up;
  }
  str->size = 0;
  str->capacity = capacity;
  str->data = buffer;
  return str;
clean_up:
  free(str);
  return NULL;
}

Str* str_new_(void) {
  return str_new_capacity(STR_CAPACITY);
}

size_t str_append_cstr_n(Str* str, const char* buf, size_t len) {
  return str_insert_cstr_n(str, str->size, buf, len);
}

size_t str_append_cstr(Str* str, const char* buf) {
  if (buf == NULL) return 0;
  return str_append_cstr_n(str, buf, strlen(buf));
}

size_t str_append_str(Str* str, const Str* other) {
  return str_append_cstr_n(str, other->data, other->size);
}

size_t str_append_char_n(Str* str, char c, size_t n) {
  size_t written = 0;
  for (size_t i = 0; i < n; i++) {
    size_t ret = str_append_cstr_n(str, &c, 1);
    if (ret == 0) {
      break;
    }
    written += ret;
  }
  return written;
}

size_t str_append_char(Str* str, char c) {
  return str_append_char_n(str, c, 1);
}

Str* str_substr_pos_n(Str* str, size_t pos, size_t len) {
  if (pos > str->size) return NULL;
  size_t size = pos + len;
  if (size > str->size) {
    size = str->size;
  }
  return str_new_cstr_n(str->data + pos, size - pos);
}

Str* str_substr_pos(Str* str, size_t pos) {
  return str_substr_pos_n(str, pos, str->size - pos);
}

Str* str_slice_from_to(Str* str, int start, int end) {
  int size = (int)str->size;
  if (start < 0) start += size;
  if (end < 0) end += size;
  if (start < 0) start = 0;
  if (end > size) end = size;
  if (end < start) end = start;
  return str_new_cstr_n(str->data + start, (size_t)(end - start));
}

Str* str_slice_from(Str* str, int start) {
  return str_slice_from_to(str, start, (int)str->size);
}

size_t str_insert_cstr_n(Str* str, size_t pos, const char* buf, size_t len) {
  if (buf == NULL || len == 0) return 0;
  if (pos > str->size) {
    pos = str->size;
  }
  size_t new_size = str->size + len;
  if (new_size > str->capacity) {
    size_t new_capacity = calc_capacity(new_size);
    new_capacity = str_expand(str, new_capacity);
    if (new_capacity == 0) {
      return 0;
    }
  }
  memmove(str->data + pos + len, str->data + pos, str->size - pos);
  memcpy(str->data + pos, buf, len);
  str->size = new_size;
  return len;
}

size_t str_insert_cstr(Str* str, size_t pos, const char* buf) {
  if (buf == NULL) return 0;
  return str_insert_cstr_n(str, pos, buf, strlen(buf));
}

size_t str_resize_n_char(Str* str, size_t new_size, char c) {
  if (new_size > str->capacity) {
    size_t new_capacity = calc_capacity(new_size);
    new_capacity = str_expand(str, new_capacity);
    if (new_capacity == 0) {
      return 0;
    }
  }
  if (new_size > str->size) {
    memset(str->data + str->size, c, new_size - str->size);
    str->size = new_size;
  } else if (new_size < str->size) {
    str->data[new_size] = 0;
    str->size = new_size;
  }
  return new_size;
}

size_t str_resize_n(Str* str, size_t new_size) {
  return str_resize_n_char(str, new_size, 0);
}

size_t str_expand(Str* str, size_t new_capacity) {
  if (new_capacity <= str->capacity) return 0;
  char* buffer = (char*)realloc(str->data, new_capacity + 1);
  if (buffer == NULL) {
    return 0;
  }
  memset(buffer + str->size, 0, new_capacity - str->size);
  str->data = buffer;
  str->capacity = new_capacity;
  return new_capacity;
}

size_t str_shrink(Str* str, size_t new_capacity) {
  if (new_capacity >= str->capacity) return 0;
  char* buffer = (char*)realloc(str->data, new_capacity + 1);
  if (buffer == NULL) {
    return 0;
  }
  if (new_capacity < str->size) {
    str->data[new_capacity] = 0;
    str->size = new_capacity;
  }
  str->data = buffer;
  str->capacity = new_capacity;
  return new_capacity;
}

void str_print(const Str* str) {
  printf("size:%zu capacity:%zu data:%s", str->size, str->capacity, str->data);
}

void str_println(const Str* str) {
  printf("size:%zu capacity:%zu data:%s\n", str->size, str->capacity, str->data);
}

void str_clear(Str* str) {
  str->data[0] = 0;
  str->size = 0;
}

void str_reset(Str* str) {
  free(str->data);
  str->data = (char*)calloc(1, sizeof(char));
  str->size = 0;
  str->capacity = 0;
}

void str_delete(Str* str) {
  free(str->data);
  free(str);
}

Str* short_to_str(short value) {
  return int_to_str(value);
}

Str* ushort_to_str(unsigned short value) {
  return int_to_str(value);
}

Str* int_to_str(int value) {
  char buf[32] = { 0 };
  int len = snprintf(buf, sizeof(buf), "%d", value);
  return str_new_cstr_n(buf, len);
}

Str* uint_to_str(unsigned int value) {
  char buf[32] = { 0 };
  int len = snprintf(buf, sizeof(buf), "%u", value);
  return str_new_cstr_n(buf, len);
}

Str* long_to_str(long value) {
  char buf[32] = { 0 };
  int len = snprintf(buf, sizeof(buf), "%ld", value);
  return str_new_cstr_n(buf, len);
}

Str* ulong_to_str(unsigned long value) {
  char buf[32] = { 0 };
  int len = snprintf(buf, sizeof(buf), "%lu", value);
  return str_new_cstr_n(buf, len);
}

Str* longlong_to_str(long long value) {
  char buf[32] = { 0 };
  int len = snprintf(buf, sizeof(buf), "%lld", value);
  return str_new_cstr_n(buf, len);
}

Str* ulonglong_to_str(unsigned long long value) {
  char buf[32] = { 0 };
  int len = snprintf(buf, sizeof(buf), "%llu", value);
  return str_new_cstr_n(buf, len);
}

Str* float_to_str(float value) {
  return double_to_str(value);
}

Str* double_to_str(double value) {
  char buf[32] = { 0 };
  int len = snprintf(buf, sizeof(buf), "%f", value);
  return str_new_cstr_n(buf, len);
}

Str* ptr_to_str(void* value) {
  char buf[32] = { 0 };
  int len = snprintf(buf, sizeof(buf), "%p", value);
  return str_new_cstr_n(buf, len);
}

#endif // STR_C
