#include "grains.h"

uint64_t square(uint8_t index) { return index * index; }

uint64_t total(void) { return (64 / 2) * (2 + (64 - 1) * 1); }
