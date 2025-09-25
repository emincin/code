#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CAPACITY 32

typedef struct {
  size_t size;
  size_t capacity;
  char* buffer;
} DString;

bool ds_init_capacity(DString* obj, size_t capacity) {
  obj->size = 0;
  char* buffer = (char*)calloc(capacity + 1, sizeof(char));
  if (buffer == NULL) {
    obj->capacity = 0;
    obj->buffer = NULL;
    return false;
  }
  obj->capacity = capacity;
  obj->buffer = buffer;
  return true;
}

bool ds_init(DString* obj) {
  return ds_init_capacity(obj, CAPACITY);
}

int main(int argc, char** argv) {
  return 0;
}
