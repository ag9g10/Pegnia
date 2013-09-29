#ifndef MOB_GUARD
#define MOB_GUARD

#include <curses.h>

#include "character.h"
#include "dungeon.h"
#include "utils.h"

typedef struct MobStruct {
    int x; //Coordinates of the mob.
    int y;
    int health;
    char symbol;
} Mob;

void mobMove(Mob *monster, Dungeon *dungeon, int x, int y);
void mobAttack(Mob *monster, Dungeon *dungeon); //Add damage capability.

void next_move(Mob *monster, Character *player, Dungeon *dungeon);

#endif
