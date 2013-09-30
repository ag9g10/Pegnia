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
    Character *player;
} Mob;

void mobMove(Mob *monster, Dungeon *dungeon, int x, int y);
void mobAttack(Mob *monster, Dungeon *dungeon); //Add damage capability.

void next_move(Mob *monster, Dungeon *dungeon);

#endif
