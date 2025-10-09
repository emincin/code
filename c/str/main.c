#define STR_C
#include "str.h"

void test_1(void) {
  Str* a = str_new_cstr("hi");
  str_append_cstr(a, " from str.h");
  str_print(a);
  str_delete(a);
}

void test_2(void) {
  Str* a = str_new_char_n('x', 3);
  str_insert_cstr(a, 0, "123");
  str_print(a);
  str_delete(a);
}

#ifdef HAS_GENERIC
void test_generic(void) {
  Str* a = str_new("Generic");
  str_append(a, " is good!");
  Str* b = str_substr(a, 7);
  str_insert(b, 0, "auto");
  str_println(a);
  str_println(b);
  str_delete(a);
  str_delete(b);
}
#endif // HAS_GENERIC

int main(int argc, char** argv) {
  return 0;
}
