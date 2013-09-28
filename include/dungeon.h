#ifndef DUNGEON_GUARD
#define DUNGEON_GUARD

#include <stdlib.h>

#include "tile.h"

static const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
static const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

typedef struct DungeonStruct {
    Tile ***tiles; // tiles of the dungeon

    int w, h;      // size of the dungeon w X h
} Dungeon;

void init(Dungeon *dungeon, int w, int h);

int make_room(Dungeon *dungeon, int x, int y, int w, int h, int dir);
int make_corridor(Dungeon *dungeon, int sx, int sy, int len, int dir);

// utility functions
void set_visible(Dungeon *dungeon, int x, int y);
void set_passable(Dungeon *dungeon, int x, int y);

// memory functions
void free_tiles(Dungeon *dungeon);
void free_dungeon(Dungeon *dungeon);

#endif
