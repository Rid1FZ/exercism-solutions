#include "difference_of_squares.h"

unsigned int abs_difference(unsigned int a, unsigned int b);

unsigned int abs_difference(unsigned int a, unsigned int b) {
  if (a > b) {
    return a - b;
  } else {
    return b - a;
  }
}

unsigned int sum_of_squares(unsigned int number) {
  unsigned int result = 0;

  for (unsigned int i = 1; i <= number; i++) {
    result += i * i;
  }

  return result;
}

unsigned int square_of_sum(unsigned int number) {
  unsigned int result = 0;

  for (unsigned int i = 1; i <= number; i++) {
    result += i;
  }

  return result * result;
}

unsigned int difference_of_squares(unsigned int number) {
  return abs_difference(sum_of_squares(number), square_of_sum(number));
}
