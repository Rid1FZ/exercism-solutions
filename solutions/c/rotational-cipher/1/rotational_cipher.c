#include "rotational_cipher.h"

#include <stdlib.h>
#include <string.h>

static char cipher_char(char c, uint16_t shift_key)
{
    uint16_t n;

    if (c >= 'a' && c <= 'z') {
        n = (uint16_t)(c - 'a');
        n += shift_key;
        return 'a' + (char)n % 26;
    } else if (c >= 'A' && c <= 'Z') {
        n = (uint16_t)(c - 'A');
        n += shift_key;
        return 'A' + (char)n % 26;
    }

    return c;
}

char* rotate(const char* text, uint16_t shift_key)
{
    size_t text_len = strlen(text);

    char* result = malloc(sizeof(char) * text_len);

    size_t i = 0;
    for (; i < text_len; i++) {
        result[i] = cipher_char(text[i], shift_key);
    }

    result[i] = '\0';

    return result;
}
