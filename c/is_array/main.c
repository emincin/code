#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

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

#define static_assert_expr(expr, msg) \
  (sizeof( struct { static_assert(expr, msg); char c; } ) > 0)

#define SAFE_ARRAY_SIZE(arr) (ARRAY_SIZE(arr) * \
  static_assert_expr(is_array(arr), #arr " must be an array"))

#define SAFE_STRLEN(s) \
  (SAFE_ARRAY_SIZE(s) > 0 ? ARRAY_SIZE(s) - 1 : 0)

#define SN(s) s, SAFE_STRLEN(s)

typedef struct {
  size_t size;
  char* data;
} String;

void string_init(String* str, const char* s, size_t n) {
  assert(str != NULL);
  assert(s != NULL);
  str->data = (char*)calloc(n + 1, sizeof(char));
  if (str->data == NULL) {
    return;
  }
  memcpy(str->data, s, n);
  str->size = n;
}

void string_deinit(String* str) {
  assert(str != NULL);
  free(str->data);
  *str = (String){ 0 };
}

void string_print(String* str) {
  assert(str != NULL);
  printf("size: %zu data: %s\n", str->size, str->data);
}

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
  //is_array(get_rvalue()); // compile-time error: cannot take the address of an rvalue
}

void safe_array_size_test(int fake_arr[]) {
  int buf[32] = { 0 };
  printf("array size: %d\n", (int)SAFE_ARRAY_SIZE(buf));
  //printf("array size: %d\n", (int)SAFE_ARRAY_SIZE(fake_arr)); // static assertion failed
}

void string_test(void) {
  String a = { 0 };
  string_init(&a, SN("hello"));
  string_print(&a);
  String b = { 0 };
  const char* s = "123";
  //string_init(&b, SN(s)); // static assertion failed
  string_print(&b);
clean_up:
  string_deinit(&a);
  string_deinit(&b);
}

int main(int argc, char** argv) {
  return 0;
}
