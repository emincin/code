#include <stdio.h>
#include <stdbool.h>

#define CODE_POINT_MIN 0
#define CODE_POINT_MAX 0x10FFFF

#define SURROGATE_MIN 0xD800
#define SURROGATE_MAX 0xDFFF

#define ERR_UNKNOWN 0
#define ERR_INVALID_CODE_POINT -1
#define ERR_BUF_SIZE_TOO_SMALL -2

bool in_range(int value, int min, int max) {
  return min <= value && value <= max;
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
  if (code_point < 128) {
    int size = 1;
    if (len < size) return ERR_BUF_SIZE_TOO_SMALL;
    buf[0] = (char)code_point;
    return size;
  }
  return ERR_UNKNOWN;
}

int main(int argc, char** argv) {
  return 0;
}
