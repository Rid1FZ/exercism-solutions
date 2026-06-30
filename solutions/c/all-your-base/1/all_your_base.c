#include "all_your_base.h"

#include <stdint.h>
#include <string.h>

#define RESULT_ERR (-1)

static int64_t to_base_10(const int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base, size_t input_length)
{
    int64_t result = 0;
    for (size_t i = 0; i < input_length; i++) {
        if (digits[i] < 0 || digits[i] >= input_base) return RESULT_ERR;

        if (result > (INT64_MAX - digits[i]) / input_base) return RESULT_ERR;

        result = result * input_base + digits[i];
    }
    return result;
}

static size_t to_base_n(int8_t digits[DIGITS_ARRAY_SIZE], uint64_t base_10, int16_t output_base)
{
    if (base_10 == 0) {
        digits[0] = 0;
        return 1;
    }

    size_t output_digits = 0;
    uint64_t temp = base_10;
    while (temp > 0) {
        output_digits++;
        temp /= output_base;
    }

    if (output_digits > DIGITS_ARRAY_SIZE) return 0;

    for (int32_t i = output_digits - 1; i >= 0; i--) {
        digits[i] = base_10 % output_base;
        base_10 /= output_base;
    }

    return output_digits;
}

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base, int16_t output_base, size_t input_length)
{
    if (input_base <= 1 || output_base <= 1 || input_length == 0) {
        memset(digits, 0, DIGITS_ARRAY_SIZE);
        return 0;
    }

    int64_t base_10 = to_base_10(digits, input_base, input_length);
    memset(digits, 0, DIGITS_ARRAY_SIZE);
    if (base_10 == RESULT_ERR)
        return 0;
    else
        return to_base_n(digits, base_10, output_base);
}
