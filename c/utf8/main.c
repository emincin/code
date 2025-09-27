#include <stdio.h>
#include <stdbool.h>

#define CODE_POINT_MIN 0
#define CODE_POINT_MAX 0x10FFFF

#define SURROGATE_MIN 0xD800
#define SURROGATE_MAX 0xDFFF

#define ERR_UNKNOWN 0
#define ERR_INVALID_CODE_POINT -1

bool in_range(int value, int min, int max) {
  return min <= value && value <= max;
}

int code_point_to_utf8(int code_point, char* buf, int len) {
  if (!in_range(code_point, CODE_POINT_MIN, CODE_POINT_MAX)) {
    return ERR_INVALID_CODE_POINT;
  }
  if (in_range(code_point, SURROGATE_MIN, SURROGATE_MAX)) {
    return ERR_INVALID_CODE_POINT;
  }
  return ERR_UNKNOWN;
}

int main(int argc, char** argv) {
  return 0;
}
