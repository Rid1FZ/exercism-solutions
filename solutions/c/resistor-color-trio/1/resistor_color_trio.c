#include "resistor_color_trio.h"

#include <stdint.h>

resistor_value_t color_code(resistor_band_t colors[3])
{
    uint64_t resistance_value = (uint64_t)colors[0] * 10 + colors[1];
    int unit_int = 0;

    for (int i = 0; i < (int)colors[2]; i++) {
        resistance_value *= 10;
    }

    while (resistance_value >= 1000 && unit_int < 4) {
        resistance_value /= 1000;
        unit_int++;
    }

    return (resistor_value_t){
        .value = resistance_value,
        .unit = (resistor_unit_t)unit_int,
    };
}
