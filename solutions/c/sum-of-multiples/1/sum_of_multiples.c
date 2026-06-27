#include "sum_of_multiples.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

static bool do_contain(const unsigned int* array, size_t count, unsigned int num)
{
    for (size_t i = 0; i < count; i++)
        if (array[i] == num) return true;

    return false;
}

uint64_t sum(const unsigned int* factors, size_t number_of_factors, unsigned int limit)
{
    size_t possible_multiples = 0;

    for (size_t i = 0; i < number_of_factors; i++) {
        if (factors[i] == 0) continue;
        possible_multiples += (limit / factors[i]);
    }

    if (possible_multiples == 0) return 0;

    unsigned int* multiples = malloc(possible_multiples * sizeof(unsigned int));
    if (!multiples) return 0;

    size_t count = 0;

    for (size_t i = 0; i < number_of_factors; i++) {
        if (factors[i] == 0) continue;

        for (unsigned int j = 1;; j++) {
            uint64_t m = (uint64_t)factors[i] * j;
            if (m >= limit) break;

            if (!do_contain(multiples, count, (unsigned int)m)) multiples[count++] = (unsigned int)m;
        }
    }

    uint64_t total_sum = 0;
    for (size_t i = 0; i < count; i++) total_sum += multiples[i];

    free(multiples);
    return total_sum;
}
