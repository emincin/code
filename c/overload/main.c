#include <stdio.h>

#define CONCAT(a, b) CONCAT_IMPL(a, b)
#define CONCAT_IMPL(a, b) a##b

#define STR(x) STR_IMPL(x)
#define STR_IMPL(x) #x

int main(int argc, char** argv) {
  return 0;
}
