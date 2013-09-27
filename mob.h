#ifndef MOB_GUARD
#define MOB_GUARD

#include <stdlib.h>
#include <curses.h>
#include <signal.h>

typedef struct MobStruct {
    int x; //Coordinates of the mob.
    int y;
    int health;
    char symbol;
} Mob;

void mobMove(Mob *monster);
void mobAttack(int c, Mob *monster); //Add damage capability.

#endif
