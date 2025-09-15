#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define INIT {0}

typedef struct {
  int len;
  char* buf;
} String;

void StringInit(String* str) {
  if (str == NULL) return;
  str->buf = NULL;
  str->len = 0;
}

void StringAppend(String* str, const char* s) {
  if (str == NULL) return;
  if (s == NULL) return;
  int len = strlen(s);
  if (len == 0) return;
  int newlen = str->len + len;
  char* newbuf = (char*)realloc(str->buf, newlen + 1);
  if (newbuf == NULL) return;
  memcpy(newbuf + str->len, s, len);
  newbuf[newlen] = 0;
  str->len = newlen;
  str->buf = newbuf;
}

void StringClear(String* str) {
  if (str == NULL) return;
  free(str->buf);
  str->buf = NULL;
  str->len = 0;
}

int main(int argc, char** argv) {
  return 0;
}
