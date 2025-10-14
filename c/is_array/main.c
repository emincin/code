#include <stdio.h>

#define PTR_TEST(expr) _Generic((expr), \
  char*: "char*", \
  char[sizeof(expr)]: "char[]", \
  default: "none" \
)

#define is_array(x) _Generic(&(x), \
  typeof(*(x)) (*)[]: 1, \
  default: 0 \
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

char* get_rvalue(void) {
  return NULL;
}

void is_array_test(void) {
  char buf[32] = { 0 };
  printf("buf is array: %d\n", is_array(buf));
  char* ptr = NULL;
  printf("ptr is array: %d\n", is_array(ptr));
  //is_array(get_rvalue()); // error: cannot take the address of an rvalue
}

int main(int argc, char** argv) {
  return 0;
}
