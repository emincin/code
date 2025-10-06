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

#endif // STR_H


#ifdef STR_C
#include <stdlib.h>

Str* str_new_capacity(size_t capacity) {
  Str* str = (Str*)malloc(sizeof(Str));
  if (str == NULL) {
    return NULL;
  }
  return str;
clean_up:
  return NULL;
}

#endif // STR_C
