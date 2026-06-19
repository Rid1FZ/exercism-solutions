#include "rna_transcription.h"
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna) {
  unsigned int dna_len = strlen(dna);
  char *result_str = calloc(dna_len + 1, sizeof(char));

  unsigned int i = 0;
  for (; i < dna_len; i++) {
    switch (dna[i]) {
    case 'G':
      result_str[i] = 'C';
      break;
    case 'C':
      result_str[i] = 'G';
      break;
    case 'T':
      result_str[i] = 'A';
      break;
    case 'A':
      result_str[i] = 'U';
      break;
    }
  }
  result_str[i] = '\0';

  return result_str;
}
