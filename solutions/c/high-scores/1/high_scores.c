#include "high_scores.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b);

int32_t latest(const int32_t *scores, size_t scores_len) {
  return *(scores + (scores_len - 1));
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
  int32_t pb = 0;

  for (size_t i = 0; i < scores_len; i++) {
    int32_t curr_score = *(scores + i);
    if (curr_score > pb)
      pb = curr_score;
  }

  return pb;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
  if (scores_len == 0 || scores == NULL || output == NULL) {
    return 0;
  }

  int32_t first = INT32_MIN;
  int32_t second = INT32_MIN;
  int32_t third = INT32_MIN;

  for (size_t i = 0; i < scores_len; i++) {
    int32_t current = scores[i];

    if (current > first) {
      third = second;
      second = first;
      first = current;
    } else if (current > second) {
      third = second;
      second = current;
    } else if (current > third) {
      third = current;
    }
  }

  size_t num_of_outputs = (scores_len < 3) ? scores_len : 3;

  if (num_of_outputs > 0)
    output[0] = first;
  if (num_of_outputs > 1)
    output[1] = second;
  if (num_of_outputs > 2)
    output[2] = third;

  return num_of_outputs;
}
