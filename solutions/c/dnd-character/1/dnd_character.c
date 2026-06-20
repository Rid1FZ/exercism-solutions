#include "dnd_character.h"
#include <math.h>
#include <stdlib.h>

/* We won't think about 4 dice rolls and taking the largest 3 of those.
 * Because for statistics, it is similar to a random number between
 * 3 (inclusive) and 18 (inclusive).
 */
int ability(void) {
  int min = 3;  // at least 3 1's will be produced by 3 dice rolls
  int max = 18; // at most 3 6's will be produced by 3 dice rolls

  int random_ability = rand() % (max - min + 1) + min;

  return random_ability;
}

int modifier(int score) {
  float score_f = (float)score;
  return (int)floor((score_f - 10.0) / 2.0);
}

dnd_character_t make_dnd_character(void) {
  dnd_character_t character;

  character.strength = ability();
  character.dexterity = ability();
  character.constitution = ability();
  character.intelligence = ability();
  character.wisdom = ability();
  character.charisma = ability();
  character.hitpoints = 10 + modifier(character.constitution);

  return character;
}
