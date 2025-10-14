#include <stdio.h>

#define PTR_TEST(expr) _Generic((expr), \
  char*: "char*", \
  char[sizeof(expr)]: "char[]", \
  default: "none" \
)

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

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

void array_size_test(void) {
  char buf[32] = { 0 };
  printf("buf - array size: %d\n", (int)ARRAY_SIZE(buf));
  char* ptr = NULL;
  printf("ptr - array size: %d\n", (int)ARRAY_SIZE(ptr));
}

char* get_rvalue(void) {
  return NULL;
}

void is_array_test(void) {
  char buf[32] = { 0 };
  printf("buf is array: %d\n", is_array(buf));
  char* ptr = NULL;
  printf("ptr is array: %d\n", is_array(ptr));
  printf("string literal is array: %d\n", is_array("hello"));
  //is_array(get_rvalue()); // error: cannot take the address of an rvalue
}

int main(int argc, char** argv) {
  return 0;
}
