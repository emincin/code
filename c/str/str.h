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
Str* str_new_();
void str_delete(Str* str);

#endif // STR_H


#ifdef STR_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Str* str_new_cstr_n(const char* buf, size_t len) {
  if (buf == NULL) {
    return NULL;
  }
  size_t capacity = 2;
  while (capacity < len) {
    capacity *= 2;
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

Str* str_new_() {
  return str_new_capacity(STR_CAPACITY);
}

void str_delete(Str* str) {
  if (str == NULL) {
    return;
  }
  free(str->data);
  free(str);
}

#endif // STR_C
