#ifndef STR_H
#define STR_H
#include <stddef.h>

typedef struct str_t {
  size_t size;
  size_t capacity;
  char* data;
} Str;

#endif // STR_H
#ifdef STR_C
#endif // STR_C
