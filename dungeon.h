#ifndef DUNGEON_GUARD
#define DUNGEON_GUARD

#include <stdlib.h>
#include <curses.h>

#include "tile.h"

typedef struct DungeonStruct {
    Tile ***tiles; // tiles of the dungeon

    int w, h;      // size of the dungeon w X h
} Dungeon;

Dungeon *dungeon;

void init(int w, int h);

void make_room(int x, int y, int w, int h);
void make_corridor(int sx, int sy, int ex, int ey);

#endif
