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

bool ds_init_capacity(DString* obj, size_t capacity);
bool ds_init(DString* obj);
void ds_deinit(DString* obj);
DString* ds_new_capacity(size_t capacity);
DString* ds_new();
void ds_delete(DString* ptr);

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

void ds_deinit(DString* obj) {
  obj->size = 0;
  obj->capacity = 0;
  if (obj->buffer) {
    free(obj->buffer);
    obj->buffer = NULL;
  }
}

DString* ds_new_capacity(size_t capacity) {
  DString* ptr = (DString*)malloc(sizeof(DString));
  if (ptr == NULL) {
    return NULL;
  }
  if (!ds_init_capacity(ptr, capacity)) {
    goto clean_up;
  }
  return ptr;
clean_up:
  free(ptr);
  return NULL;
}

DString* ds_new() {
  return ds_new_capacity(CAPACITY);
}

void ds_delete(DString* ptr) {
  if (!ptr) {
    return;
  }
  if (ptr->buffer) {
    free(ptr->buffer);
  }
  free(ptr);
}

int main(int argc, char** argv) {
  return 0;
}
