#include "nucleotide_count.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESULT_SIZE (32U)

char* count(const char* dna_strand)
{
    struct {
        unsigned int A;
        unsigned int C;
        unsigned int G;
        unsigned int T;
    } c = {0};

    size_t strand_len = strlen(dna_strand);

    char* result = malloc(sizeof(char) * RESULT_SIZE);

    for (size_t i = 0; i < strand_len; i++) {
        switch (dna_strand[i]) {
            case 'A':
                c.A++;
                break;
            case 'C':
                c.C++;
                break;
            case 'G':
                c.G++;
                break;
            case 'T':
                c.T++;
                break;
            default:
                result[0] = '\0';
                return result;
        }
    }

    snprintf(result, sizeof(char) * RESULT_SIZE, "A:%u C:%u G:%u T:%u", c.A, c.C, c.G, c.T);

    return result;
}
