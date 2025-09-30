#include <stdio.h>

#define CONCAT(a, b) CONCAT_IMPL(a, b)
#define CONCAT_IMPL(a, b) a##b

int main(int argc, char** argv) {
  return 0;
}
