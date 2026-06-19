#include "space_age.h"

long double age(planet_t planet, int64_t seconds) {
  switch (planet) {
  case MERCURY:
    return seconds / (MERCURY_YEAR * SEC_IN_YEAR);
    break;
  case VENUS:
    return seconds / (VENUS_YEAR * SEC_IN_YEAR);
    break;
  case EARTH:
    return seconds / (EARTH_YEAR * SEC_IN_YEAR);
    break;
  case MARS:
    return seconds / (MARS_YEAR * SEC_IN_YEAR);
    break;
  case JUPITER:
    return seconds / (JUPITER_YEAR * SEC_IN_YEAR);
    break;
  case SATURN:
    return seconds / (STAURN_YEAR * SEC_IN_YEAR);
    break;
  case URANUS:
    return seconds / (URANUS_YEAR * SEC_IN_YEAR);
    break;
  case NEPTUNE:
    return seconds / (NEPTUNE_YEAR * SEC_IN_YEAR);
    break;
  default:
    return -1;
  }
}
