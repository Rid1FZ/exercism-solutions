#include "resistor_color_duo.h"

int color_code(resistor_band_t colors[]) {
  return ((int)colors[0]) * 10 + ((int)colors[1]);
}
