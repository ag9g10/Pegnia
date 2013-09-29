#ifndef UTILS_GUARD 
#define UTILS_GUARD 

#include <stdlib.h>
#include <dungeon.h>

int is_passable(Dungeon *dungeon, int x, int y);

typedef struct PairStruct {
    int x, y;
} Pair;

#endif
