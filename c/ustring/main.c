#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_CAPACITY 32

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

bool string_alloc(String* str, size_t capacity);
bool string_init(String* str);
bool string_from_cstr(String* str, const char* s);
bool string_add_cstr(String* str, const char* s);

bool string_alloc(String* str, size_t capacity) {
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

bool string_init(String* str) {
  return string_alloc(str, BUFFER_CAPACITY);
}

bool string_from_cstr(String* str, const char* s) {
  str->size = 0;
  str->capacity = 0;
  str->buffer = NULL;
  if (s == NULL) return false;
  size_t size = strlen(s);
  if (size == 0) return false;
  size_t capacity = 2;
  while (capacity < size) {
    capacity *= 2;
  }
  char* buffer = (char*)calloc(capacity + 1, sizeof(char));
  if (buffer == NULL) {
    return false;
  }
  memcpy(buffer, s, size);
  str->size = size;
  str->capacity = capacity;
  str->buffer = buffer;
  return true;
}

bool string_add_cstr(String* str, const char* s) {
  if (s == NULL) return false;
  size_t size = strlen(s);
  if (size == 0) return false;
  return true;
}

int main(int argc, char** argv) {
  return 0;
}
