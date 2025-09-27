#include <stdio.h>
#include <stdbool.h>

#define ERR_UNKNOWN 0
#define ERR_INVALID_CODE_POINT -1

bool in_range(int value, int min, int max) {
  return min <= value && value <= max;
}

int code_point_to_utf8(int code_point, char* buf, int len) {
  return ERR_UNKNOWN;
}

int main(int argc, char** argv) {
  return 0;
}
