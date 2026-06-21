#include "perfect_numbers.h"
#include <stdint.h>

kind classify_number(int num) {
  if (num < 1)
    return ERROR;

  int sigma = 0;
  for (int i = 1; i <= num / 2; i++) {
    if (num % i == 0)
      sigma += i;
  }

  if (sigma == num)
    return PERFECT_NUMBER;
  else if (sigma > num)
    return ABUNDANT_NUMBER;
  else
    return DEFICIENT_NUMBER;
}
