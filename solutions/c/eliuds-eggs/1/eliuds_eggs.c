#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int code) {
  unsigned int MASK = 0x1;

  unsigned int bits = sizeof(unsigned int) * 8;
  unsigned int count = 0;

  for (unsigned int i = 0; i < bits; i++) {
    unsigned int curr_bit = (code >> i) & MASK;

    if (curr_bit == 1) {
      count++;
    }
  }

  return count;
}
