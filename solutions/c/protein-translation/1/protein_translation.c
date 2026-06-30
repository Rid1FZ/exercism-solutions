#include "protein_translation.h"

#include <stdbool.h>
#include <string.h>

static int cmp_codon(char codon_a[4], char codon_b[4])
{
    return (codon_a[0] == codon_b[0]) && (codon_a[1] == codon_b[1]) && (codon_a[2] == codon_b[2]);
}

static amino_acid_t get_amino_acid(char codon[4])
{
    if (cmp_codon(codon, "AUG"))
        return Methionine;
    else if (cmp_codon(codon, "UUU") || cmp_codon(codon, "UUC"))
        return Phenylalanine;
    else if (cmp_codon(codon, "UUA") || cmp_codon(codon, "UUG"))
        return Leucine;
    else if (cmp_codon(codon, "UCU") || cmp_codon(codon, "UCC") || cmp_codon(codon, "UCA") || cmp_codon(codon, "UCG"))
        return Serine;
    else if (cmp_codon(codon, "UAU") || cmp_codon(codon, "UAC"))
        return Tyrosine;
    else if (cmp_codon(codon, "UGU") || cmp_codon(codon, "UGC"))
        return Cysteine;
    else if (cmp_codon(codon, "UGG"))
        return Tryptophan;
    else if (cmp_codon(codon, "UAA") || cmp_codon(codon, "UAG") || cmp_codon(codon, "UGA"))
        return STOP_CDN;
    else
        return INVALID_CDN;
}

protein_t protein(const char* const rna)
{
    size_t num_of_nucleotides = strlen(rna);
    size_t num_of_codons = num_of_nucleotides / 3;

    protein_t p = {
        .valid = true,
        .count = 0,
    };

    for (size_t i = 0; i < num_of_codons; i++) {
        char codon[4];
        size_t starting_idx = i * 3;

        codon[0] = rna[starting_idx];
        codon[1] = rna[starting_idx + 1];
        codon[2] = rna[starting_idx + 2];
        codon[3] = '\0';

        switch (get_amino_acid(codon)) {
            case STOP_CDN:
                return p;
            case INVALID_CDN:
                p.valid = false;
                return p;
            default:
                p.amino_acids[p.count++] = get_amino_acid(codon);
                break;
        }
    }

    if (num_of_nucleotides % 3 != 0) {
        p.valid = false;
        return p;
    }

    return p;
}
