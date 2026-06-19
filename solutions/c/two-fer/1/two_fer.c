#include "two_fer.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void two_fer(char *buffer, const char *name) {
  if (name == NULL) {
    strncpy(buffer, "One for you, one for me.", (BUFFER_SIZE)-1);
  } else {
    snprintf(buffer, (BUFFER_SIZE)-1, "One for %s, one for me.", name);
  }
}
