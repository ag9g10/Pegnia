#ifndef GUARD_GENERATOR
#define GUARD_GENERATOR

#include "dungeon.h"
#include "mt19937ar.h"
#include "p_math.h"

void generate(Dungeon *dungeon);

// create rooms/corridors
void make_random_room(Dungeon *dungeon, int x, int y);
void make_random_corridor(Dungeon *dungeon, int x, int y);

// utility functions
int is_near_empty(Dungeon *dungeon, int x, int y);

#endif
