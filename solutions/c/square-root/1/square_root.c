#include "square_root.h"

/* The method used here is known as Newton's guessing method */
double square_root(uint16_t num)
{
    double guess = num / 2.0;
    double precision = 0.000001;

    if (num == 0) return 0.0;

    while ((guess * guess - num) > precision || (num - guess * guess) > precision) {
        guess = 0.5 * (guess + (num / guess));
    }

    return guess;
}
