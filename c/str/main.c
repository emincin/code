#define STR_C
#include "str.h"

void test_1(void) {
  Str* a = str_new_cstr("hi");
  str_append_cstr(a, " from str.h");
  str_print(a); // size:13 capacity:16 data:hi from str.h
  str_delete(a);
}

void test_2(void) {
  Str* a = str_new_char_n('x', 3);
  str_insert_cstr(a, 0, "123");
  str_print(a); // size:6 capacity:8 data:123xxx
  str_delete(a);
}

void test_3(void) {
  Str* a = str_new_cstr_n("123456", 3);
  str_println(a); // size:3 capacity:4 data:123
  str_resize(a, 2, 'x');
  str_println(a); // size:2 capacity:4 data:12
  str_resize(a, 6, 'z');
  str_println(a); // size:6 capacity:8 data:12zzzz
  str_delete(a);
}

#ifdef HAS_GENERIC
void test_generic(void) {
  Str* a = str_new("Generic");
  str_append(a, " is good!");
  Str* b = str_substr(a, 7);
  str_insert(b, 0, "auto");
  str_println(a); // size:16 capacity:16 data:Generic is good!
  str_println(b); // size:13 capacity:16 data:auto is good!
  str_delete(a);
  str_delete(b);
}
#endif // HAS_GENERIC

int main(int argc, char** argv) {
  return 0;
}
