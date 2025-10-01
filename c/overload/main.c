#include <stdio.h>

#define CONCAT(a, b) CONCAT_IMPL(a, b)
#define CONCAT_IMPL(a, b) a##b

#define STR(x) STR_IMPL(x)
#define STR_IMPL(x) #x

#define COUNT(...) __VA_OPT__(COUNT_IMPL(__VA_ARGS__, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))
#define COUNT_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, n, ...) n

#define NO_PARAM(...) (sizeof(#__VA_ARGS__) == 1)

int main(int argc, char** argv) {
  return 0;
}
