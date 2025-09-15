#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int len;
  char* buf;
} String;

void StringAppend(String* str, const char* s) {
  if (str == NULL) return;
  if (s == NULL) return;
  int len = strlen(s);
  if (len == 0) return;
  int newlen = str->len + len;
}

int main(int argc, char** argv) {
  return 0;
}
