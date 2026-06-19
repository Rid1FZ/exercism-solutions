#include "darts.h"
#include <math.h>

uint8_t score(const coordinate_t position) {
  double radius = sqrt(pow(position.x, 2) + pow(position.y, 2));

  if (radius > 10) {
    return 0;
  } else if (radius > 5) {
    return 1;
  } else if (radius > 1) {
    return 5;
  } else {
    return 10;
  }
}
