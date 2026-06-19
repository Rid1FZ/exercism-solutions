#include "hamming.h"
#include <string.h>

#define ERROR_RESULT -1

int compute(const char *lhs, const char *rhs) {
  unsigned int lhs_len = strlen(lhs);
  unsigned int rhs_len = strlen(rhs);

  if (lhs_len != rhs_len)
    return ERROR_RESULT;

  unsigned int count = 0;
  for (unsigned int i = 0; i < lhs_len; i++) {
    if (lhs[i] != rhs[i])
      count++;
  }

  return count;
}
