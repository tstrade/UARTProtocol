#include "char2binary.h"

#include <string.h>

int *convertString(int *dest, char *src) {
  int size = strlen(src);
  int c = 0;
  int character;
  unsigned short mask = 0x01;

  for (int i = 0; i < size; i++) {
    character = (int)src[i];
    for (int j = 7; j >= 0; j--) {
      dest[c++] = (((unsigned)character >> j) & mask);
    }
  }
  return dest;
}
