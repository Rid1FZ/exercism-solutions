#include "reverse_string.h"

#include <stdlib.h>
#include <string.h>

char* reverse(const char* text)
{
    size_t text_len = strlen(text);

    char* result = malloc(sizeof(char) * (text_len + 1));

    const char* p = text + (text_len - 1);
    char* r = result;
    while (p >= text) *(r++) = *(p--);

    *r = '\0';

    return result;
}
