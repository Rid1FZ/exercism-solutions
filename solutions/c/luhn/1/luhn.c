#include "luhn.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool luhn(const char* num)
{
    if (num == NULL) return false;

    size_t num_len = strlen(num);
    if (num_len <= 1) return false;

    size_t digit_count = 0;
    int sum = 0;
    bool is_even = false;

    const char* p = num + num_len - 1;
    while (p >= num) {
        char curr_char = *p--;
        if (curr_char == ' ') continue;
        if (!(curr_char >= '0' && curr_char <= '9')) return false;

        int digit_int = (int)(curr_char - '0');
        if (is_even) {
            digit_int *= 2;
            if (digit_int > 9) digit_int -= 9;
        }

        sum += digit_int;
        digit_count++;
        is_even = !is_even;
    }

    if (digit_count <= 1) return false;

    return sum % 10 == 0;
}
