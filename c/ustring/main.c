#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  size_t size;
  size_t capacity;
  char* buffer;
} String;

typedef struct {
  size_t size;
  size_t capacity;
  int* buffer;
} String32;

bool string_alloc(String* str, size_t capacity) {
  if (str == NULL) return false;
  str->size = 0;
  str->capacity = 0;
  str->buffer = NULL;
  if (capacity == 0) return false;
  char* buffer = (char*)calloc(capacity + 1, sizeof(char));
  if (buffer == NULL) {
    return false;
  }
  str->capacity = capacity;
  str->buffer = buffer;
  return true;
}

int main(int argc, char** argv) {
  return 0;
}
