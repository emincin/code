#include <stdio.h>
#include <math.h>

#define NO_PARAM(...) (sizeof(#__VA_ARGS__) == 1)

#define STR(x) STR_IMPL(x)
#define STR_IMPL(x) #x

#define CONCAT(a, b) CONCAT_IMPL(a, b)
#define CONCAT_IMPL(a, b) a##b

#define COUNT(...) __VA_OPT__(COUNT_IMPL(__VA_ARGS__, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))
#define COUNT_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, n, ...) n

#define OVERLOAD(name, ...) CONCAT(name, COUNT(__VA_ARGS__))
#define INVOKE_OVERLOAD(name, ...) OVERLOAD(name, __VA_ARGS__)(__VA_ARGS__)

#define EXPAND_1(func, var) func(var)
#define EXPAND_2(func, var, ...) func(var), EXPAND_1(func, __VA_ARGS__)
#define EXPAND_3(func, var, ...) func(var), EXPAND_2(func, __VA_ARGS__)
#define EXPAND_4(func, var, ...) func(var), EXPAND_3(func, __VA_ARGS__)
#define EXPAND_5(func, var, ...) func(var), EXPAND_4(func, __VA_ARGS__)
#define EXPAND_6(func, var, ...) func(var), EXPAND_5(func, __VA_ARGS__)
#define EXPAND_7(func, var, ...) func(var), EXPAND_6(func, __VA_ARGS__)
#define EXPAND_8(func, var, ...) func(var), EXPAND_7(func, __VA_ARGS__)
#define EXPAND_9(func, var, ...) func(var), EXPAND_8(func, __VA_ARGS__)
#define EXPAND_10(func, var, ...) func(var), EXPAND_9(func, __VA_ARGS__)
#define EXPAND_11(func, var, ...) func(var), EXPAND_10(func, __VA_ARGS__)
#define EXPAND_12(func, var, ...) func(var), EXPAND_11(func, __VA_ARGS__)
#define EXPAND_13(func, var, ...) func(var), EXPAND_12(func, __VA_ARGS__)
#define EXPAND_14(func, var, ...) func(var), EXPAND_13(func, __VA_ARGS__)
#define EXPAND_15(func, var, ...) func(var), EXPAND_14(func, __VA_ARGS__)
#define EXPAND_16(func, var, ...) func(var), EXPAND_15(func, __VA_ARGS__)

#define EXPAND(func, ...) __VA_OPT__(OVERLOAD(EXPAND_, __VA_ARGS__)(func, __VA_ARGS__))

#define NONAME_FUNC(ret, ...) ((ret (*)(EXPAND(typeof, __VA_ARGS__)))0)

#define FUNC_CASE(func) typeof(&(func)) : func

#define FIRST_ARG(a, ...) a

typedef struct {
  double x;
  double y;
} vec2;

typedef struct {
  double x;
  double y;
  double z;
} vec3;

vec2 make_vec2(double x, double y) {
  return (vec2){ x, y };
}

vec3 make_vec3(double x, double y, double z) {
  return (vec3){ x, y, z };
}

double length_d2(double x, double y) {
  return sqrt(x * x + y * y);
}

double length_d3(double x, double y, double z) {
  return sqrt(x * x + y * y + z * z);
}

double length_i2(int x, int y) {
  return length_d2(x, y);
}

double length_i3(int x, int y, int z) {
  return length_d3(x, y, z);
}

double length_vec2(vec2 a) {
  return length_d2(a.x, a.y);
}

double length_vec3(vec3 a) {
  return length_d3(a.x, a.y, a.z);
}

#define length(...) _Generic(NONAME_FUNC(double, __VA_ARGS__), \
  FUNC_CASE(length_d2), \
  FUNC_CASE(length_d3), \
  FUNC_CASE(length_i2), \
  FUNC_CASE(length_i3), \
  FUNC_CASE(length_vec2), \
  FUNC_CASE(length_vec3) \
)(__VA_ARGS__)

typedef struct {
  int x;
  int y;
} Point;

Point add_point_point(Point a, Point b) {
  return (Point){ a.x + b.x, a.y + b.y };
}

int add_int_int(int a, int b) {
  return a + b;
}

#define add_2(a, b) _Generic((a), \
  int: _Generic((b), int: add_int_int, default: NULL), \
  Point: _Generic((b), Point: add_point_point, default: NULL) \
)(a, b)

#define add(...) INVOKE_OVERLOAD(add_, __VA_ARGS__)

void print_int(int a) {
  printf("%d\n", a);
}

void print_point(Point a) {
  printf("[%d %d]\n", a.x, a.y);
}

void print_double(double a) {
  printf("%f\n", a);
}

void print_int_int(int a, int b) {
  printf("Position: (%d, %d)\n", a, b);
}

void print_int_string(int a, const char* b) {
  printf("[Length: %d Data: %s]\n", a, b);
}

#define print_1(a) _Generic((a), \
  int: print_int, \
  Point: print_point, \
  double: print_double \
)(a)

#define print_2(a, b) _Generic((a), \
  int: _Generic((b), int: print_int_int, char*: print_int_string, const char*: print_int_string, default: NULL) \
)(a, b)

#define print(...) INVOKE_OVERLOAD(print_, __VA_ARGS__)

int main(int argc, char** argv) {
  return 0;
}
