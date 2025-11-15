#ifndef __STRING_T__
#define __STRING_T__

#include <stddef.h>

typedef struct string_t {
  size_t capacity;
  size_t size;
  char* data;
} String;

#endif//__STRING_T__

#if defined(STRING_T_IMPL)
#endif    //STRING_T_IMPL
