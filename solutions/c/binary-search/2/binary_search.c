#include "binary_search.h"

const int* binary_search(int value, const int* arr, size_t length)
{
    if (length == 0 || arr == NULL) return NULL;

    size_t mid = length / 2;
    if (*(arr + mid) == value)
        return arr + mid;
    else if (value > *(arr + mid))
        return binary_search(value, arr + mid + 1, mid);
    else
        return binary_search(value, arr, mid);
}
