#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define TYPE_NONE           0
#define TYPE_BOOL           1
#define TYPE_CHAR           2
#define TYPE_SCHAR          3
#define TYPE_UCHAR          4
#define TYPE_SHORT          5
#define TYPE_INT            6
#define TYPE_LONG           7
#define TYPE_LONGLONG       8
#define TYPE_USHORT         9
#define TYPE_UINT           10
#define TYPE_ULONG          11
#define TYPE_ULONGLONG      12
#define TYPE_FLOAT          13
#define TYPE_DOUBLE         14
#define TYPE_STRING         15
#define TYPE_CONST_STRING   16
#define TYPE_ANY            17
#define TYPE_CONST_ANY      18

#define typeid_of(x) _Generic((x), \
  _Bool:              TYPE_BOOL, \
  char:               TYPE_CHAR, \
  signed char:        TYPE_SCHAR, \
  unsigned char:      TYPE_UCHAR, \
  short:              TYPE_SHORT, \
  int:                TYPE_INT, \
  long:               TYPE_LONG, \
  long long:          TYPE_LONGLONG, \
  unsigned short:     TYPE_USHORT, \
  unsigned int:       TYPE_UINT, \
  unsigned long:      TYPE_ULONG, \
  unsigned long long: TYPE_ULONGLONG, \
  float:              TYPE_FLOAT, \
  double:             TYPE_DOUBLE, \
  char*:              TYPE_STRING, \
  const char*:        TYPE_CONST_STRING, \
  void*:              TYPE_ANY, \
  const void*:        TYPE_CONST_ANY, \
  default:            TYPE_NONE)

int main(int argc, char** argv) {
  return 0;
}
