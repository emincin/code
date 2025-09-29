#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define CODE_POINT_MIN 0
#define CODE_POINT_MAX 0x10FFFF

#define SURROGATE_MIN 0xD800
#define SURROGATE_MAX 0xDFFF

#define ERR_INVALID_PTR -1
#define ERR_BUF_SIZE_TOO_SMALL -2
#define ERR_INVALID_CODE_POINT -3
#define ERR_INVALID_UTF8_STRING -4

bool in_range(int value, int min, int max) {
  return min <= value && value <= max;
}

bool is_leading_byte(char byte, int index) {
  int test_mask = 0xF8 << (3 - index);
  int match = 0xF0 << (3 - index);
  return (byte & test_mask) == match;
}

char leading_byte(int code_point, int rindex) {
  code_point = code_point >> 6 * rindex;
  int test_mask = 0x1F >> (rindex - 1);
  int set_mask = 0xF0 << (3 - rindex);
  return (char)(code_point & test_mask | set_mask);
}

char continuation_byte(int code_point, int rindex) {
  code_point = code_point >> 6 * rindex;
  int test_mask = 0x3F;
  int set_mask = 0x80;
  return (char)(code_point & test_mask | set_mask);
}

int code_point_to_utf8(int code_point, char* buf, int len) {
  if (!in_range(code_point, CODE_POINT_MIN, CODE_POINT_MAX)) {
    return ERR_INVALID_CODE_POINT;
  }
  if (in_range(code_point, SURROGATE_MIN, SURROGATE_MAX)) {
    return ERR_INVALID_CODE_POINT;
  }
  if (buf == NULL) {
    return ERR_INVALID_PTR;
  }
  if (code_point < 128) {
    int size = 1;
    if (len < size) return ERR_BUF_SIZE_TOO_SMALL;
    buf[0] = (char)code_point;
    return size;
  } else if (code_point < 2048) {
    int size = 2;
    if (len < size) return ERR_BUF_SIZE_TOO_SMALL;
    buf[0] = leading_byte(code_point, size - 1);
    for (int i = 1; i < size; i++) {
      buf[i] = continuation_byte(code_point, size - 1 - i);
    }
    return size;
  } else if (code_point < 65536) {
    int size = 3;
    if (len < size) return ERR_BUF_SIZE_TOO_SMALL;
    buf[0] = leading_byte(code_point, size - 1);
    for (int i = 1; i < size; i++) {
      buf[i] = continuation_byte(code_point, size - 1 - i);
    }
    return size;
  } else {
    int size = 4;
    if (len < size) return ERR_BUF_SIZE_TOO_SMALL;
    buf[0] = leading_byte(code_point, size - 1);
    for (int i = 1; i < size; i++) {
      buf[i] = continuation_byte(code_point, size - 1 - i);
    }
    return size;
  }
}

int utf8_to_code_point(const char* buf, int len) {
  if (buf == NULL) {
    return ERR_INVALID_PTR;
  }
  if (len < 1) {
    return ERR_BUF_SIZE_TOO_SMALL;
  }
  char first_byte = buf[0];
  int code_point = 0;
  int size = 0;
  if ((first_byte & 0x80) == 0) {
    return first_byte;
  } else if (is_leading_byte(first_byte, 1)) {
    size = 2;
  } else if (is_leading_byte(first_byte, 2)) {
    size = 3;
  } else if (is_leading_byte(first_byte, 3)) {
    size = 4;
  } else {
  }
  return code_point;
}

int main(int argc, char** argv) {
  return 0;
}
