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

Str* str_new_capacity(size_t capacity);
void str_delete(Str* str);

#endif // STR_H


#ifdef STR_C
#include <stdlib.h>

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

void str_delete(Str* str) {
  if (str == NULL) {
    return;
  }
  free(str->data);
  free(str);
}

#endif // STR_C
