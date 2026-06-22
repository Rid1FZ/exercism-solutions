#include "pangram.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/* When tracking 1 bit(from left) for each of the character, our
 * target is to get the number 00000011111111111111111111111111
 * which is equal to 0x3FFFFFFU in hexadecimal. */
#define TARGET_MASK 0x3FFFFFFU

/* We will track if all of the alphabets exists by using a single
 * 32bit integer. Because there are 26 characters, if we use 1 bit
 * for each of the alphabet(starting from left). At the end, we can
 * just compare the final result with TARGET_MASK. */
bool is_pangram(const char* sentence) {
  if (sentence == NULL) return false;

  uint32_t mask = 0x0;
  for (const char* curr_char = sentence; *curr_char != '\0'; curr_char++) {
    char c = *curr_char;

    if (c >= 'a' && c <= 'z')
      mask |= (1U << (c - 'a'));
    else if (c >= 'A' && c <= 'Z')
      mask |= (1U << (c - 'A'));

    if (mask == TARGET_MASK) return true;
  }

  return mask == TARGET_MASK;
}
