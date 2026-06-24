#include "armstrong_numbers.h"

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_armstrong_number(int candidate)
{
    int temp;

    temp = candidate;
    size_t digits = 0;

    // Edge case: if the digit is 0
    if (temp == 0) digits = 1;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = candidate;
    int armstrong_sum = 0;
    while (temp > 0) {
        unsigned int digit = temp % 10;
        armstrong_sum += (unsigned int)pow(digit, digits);
        temp /= 10;
    }

    return armstrong_sum == candidate;
}
