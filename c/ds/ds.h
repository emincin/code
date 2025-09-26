#ifndef DS_HEADER_FILE
#define DS_HEADER_FILE
#include <stddef.h>
#include <stdlib.h>

#define DS_CAPACITY 32

#define make_ds(capacity) { 0, capacity, calloc(capacity + 1, sizeof(char)) }
#define free_ds(ds) free(ds.data)

typedef struct {
  size_t size;
  size_t capacity;
  char* data;
} ds;

#endif // DS_HEADER_FILE

#ifdef DS_IMPL
#endif
