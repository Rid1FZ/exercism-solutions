#include "allergies.h"

#include <stdbool.h>

#define ALLERGEN_EGG_MASK (0x1U)
#define ALLERGEN_PEANUTS_MASK (0x1U << 1)
#define ALLERGEN_SHELLFISH_MASK (0x1U << 2)
#define ALLERGEN_STRAWBERRIES_MASK (0x1U << 3)
#define ALLERGEN_TOMATOES_MASK (0x1U << 4)
#define ALLERGEN_CHOCOLATE_MASK (0x1U << 5)
#define ALLERGEN_POLLEN_MASK (0x1U << 6)
#define ALLERGEN_CATS_MASK (0x1U << 7)

bool is_allergic_to(allergen_t allergen, int score)
{
    switch (allergen) {
        case ALLERGEN_EGGS:
            return (score & ALLERGEN_EGG_MASK) != 0;
        case ALLERGEN_PEANUTS:
            return (score & ALLERGEN_PEANUTS_MASK) != 0;
        case ALLERGEN_SHELLFISH:
            return (score & ALLERGEN_SHELLFISH_MASK) != 0;
        case ALLERGEN_STRAWBERRIES:
            return (score & ALLERGEN_STRAWBERRIES_MASK) != 0;
        case ALLERGEN_TOMATOES:
            return (score & ALLERGEN_TOMATOES_MASK) != 0;
        case ALLERGEN_CHOCOLATE:
            return (score & ALLERGEN_CHOCOLATE_MASK) != 0;
        case ALLERGEN_POLLEN:
            return (score & ALLERGEN_POLLEN_MASK) != 0;
        case ALLERGEN_CATS:
            return (score & ALLERGEN_CATS_MASK) != 0;
        default:
            return false;
    }
}

allergen_list_t get_allergens(int score)
{
    allergen_list_t list = {
        .allergens = {0},
        .count = 0,
    };

    for (int i = 0; i < ALLERGEN_COUNT; i++) {
        if (is_allergic_to((allergen_t)i, score)) {
            list.allergens[i] = true;
            list.count++;
        }
    }

    return list;
}
