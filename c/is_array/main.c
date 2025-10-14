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

int main(int argc, char** argv) {
  return 0;
}
