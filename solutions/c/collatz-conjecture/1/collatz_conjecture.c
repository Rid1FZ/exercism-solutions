#include "collatz_conjecture.h"
#include <stdbool.h>

bool iseven(int);
bool isodd(int);

bool iseven(int num) { return num % 2 == 0; }
bool isodd(int num) { return !iseven(num); }

int steps(int start) {
  if (start <= 0) {
    return ERROR_VALUE;
  }

  unsigned int total_steps = 0;
  int curr_number = start;
  while (curr_number != 1) {
    if (iseven(curr_number)) {
      curr_number /= 2;
    } else {
      curr_number = (curr_number * 3) + 1;
    }
    total_steps += 1;
  }

  return total_steps;
}
