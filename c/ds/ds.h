#ifndef DS_HEADER_FILE
#define DS_HEADER_FILE
#include <stddef.h>

#define DS_CAPACITY 32

typedef struct {
  size_t size;
  size_t capacity;
  char* data;
} ds;

#endif // DS_HEADER_FILE

#ifdef DS_IMPL
#endif
