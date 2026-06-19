#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <stdint.h>

typedef enum planet {
  MERCURY,
  VENUS,
  EARTH,
  MARS,
  JUPITER,
  SATURN,
  URANUS,
  NEPTUNE,
} planet_t;

// seconds in an earth year (365.25*24*60*60)
#define SEC_IN_YEAR 31557600.0

// relative years (to earth)
#define MERCURY_YEAR 0.2408467
#define VENUS_YEAR 0.61519726
#define EARTH_YEAR 1.0
#define MARS_YEAR 1.8808158
#define JUPITER_YEAR 11.862615
#define STAURN_YEAR 29.447498
#define URANUS_YEAR 84.016846
#define NEPTUNE_YEAR 164.79132

long double age(planet_t planet, int64_t seconds);

#endif
