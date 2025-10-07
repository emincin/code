#ifndef STR_H
#define STR_H
#include <stddef.h>

#ifndef STR_CAPACITY
#define STR_CAPACITY 32
#endif

typedef struct str_t {
  size_t size;
  size_t capacity;
  char* data;
} Str;

Str* str_new_cstr_n(const char* buf, size_t len);
Str* str_new_cstr(const char* buf);
Str* str_new_capacity(size_t capacity);
Str* str_new_(void);
void str_delete(Str* str);
size_t str_append_cstr_n(Str* str, const char* buf, size_t len);
size_t str_append_cstr(Str* str, const char* buf);
void str_clear(Str* str);
void str_reset(Str* str);

#endif // STR_H


#ifdef STR_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Str* str_new_cstr_n(const char* buf, size_t len) {
  if (buf == NULL) {
    return NULL;
  }
  size_t capacity = 0;
  if (len > 0) {
    capacity = 1;
    while (capacity < len) {
      capacity *= 2;
    }
  }
  Str* str = str_new_capacity(capacity);
  if (str == NULL) {
    return NULL;
  }
  memcpy(str->data, buf, len);
  str->size = len;
  return str;
}

Str* str_new_cstr(const char* buf) {
  if (buf == NULL) {
    return NULL;
  }
  return str_new_cstr_n(buf, strlen(buf));
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

void str_delete(Str* str) {
  if (str == NULL) {
    return;
  }
  free(str->data);
  free(str);
}

size_t str_append_cstr_n(Str* str, const char* buf, size_t len) {
  if (buf == NULL || len == 0) return 0;
  size_t new_size = str->size + len;
  if (new_size > str->capacity) {
    size_t new_capacity = str->capacity;
    while (new_capacity < new_size) {
      new_capacity *= 2;
    }
    char* buffer = (char*)realloc(str->data, new_capacity + 1);
    if (buffer == NULL) {
      return 0;
    }
    memset(buffer + str->size, 0, new_capacity + 1 - str->size);
    str->data = buffer;
    str->capacity = new_capacity;
  }
  memcpy(str->data + str->size, buf, len);
  str->size = new_size;
  return len;
}

size_t str_append_cstr(Str* str, const char* buf) {
  if (buf == NULL) return 0;
  return str_append_cstr_n(str, buf, strlen(buf));
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

#endif // STR_C
