#ifndef MOB_GUARD
#define MOB_GUARD

#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <dungeon.h>

typedef struct MobStruct {
    int x; //Coordinates of the mob.
    int y;
    int health;
    char symbol;
} Mob;

void mobMove(Mob *monster, Dungeon *dungeon);
void mobAttack(Mob *monster, Dungeon *dungeon); //Add damage capability.

#endif
