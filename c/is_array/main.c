#include <stdio.h>

#define PTR_TEST(expr) _Generic((expr), \
  char*: "char*", \
  char[sizeof(expr)]: "char[]", \
  default: "none" \
)

typedef struct {
  size_t size;
  char* data;
} String;

void ptr_test(void) {
  char buf[32] = { 0 };
  printf("buf: %s\n", PTR_TEST(buf));
  char* ptr = NULL;
  printf("ptr: %s\n", PTR_TEST(ptr));
}

int main(int argc, char** argv) {
  return 0;
}
