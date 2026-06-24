#include "isogram.h"

#include <ctype.h>
#include <stddef.h>
#include <string.h>

#include "isogram.h"

bool is_isogram(const char phrase[])
{
    if (phrase == NULL) return false;

    unsigned int alpha_mask = 0;
    for (size_t i = 0; phrase[i] != '\0'; i++) {
        char curr_char = phrase[i];

        if (!isalpha((unsigned char)curr_char)) {
            continue;
        }

        // Normalize to lowercase offset (0 to 25)
        int bit_position = tolower((unsigned char)curr_char) - 'a';
        unsigned int curr_mask = 1U << bit_position;

        if (alpha_mask & curr_mask) {
            return false;
        }

        alpha_mask |= curr_mask;
    }

    return true;
}
