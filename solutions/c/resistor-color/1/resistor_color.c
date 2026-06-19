#include "resistor_color.h"

static resistor_band_t all_colors[TOTAL_COLORS];

int color_code(resistor_band_t band) { return (int)band; }

resistor_band_t *colors(void) {
  for (int i = 0; i < TOTAL_COLORS; i++) {
    all_colors[i] = i;
  }

  return all_colors;
}
