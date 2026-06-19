#include "binary.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_valid_bit(char bit);
bool is_valid_bit(char bit) {
  if (!(bit == '0' || bit == '1'))
    return false;
  return true;
}

int convert(const char *input) {
  unsigned int num_of_bits = strlen(input);

  for (unsigned int i = 0; i < num_of_bits; i++) {
    if (!(is_valid_bit(input[i])))
      return INVALID;
  }

  char *end;

  long output = strtol(input, &end, 2);

  return (int)output;
}
