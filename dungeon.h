#ifndef DUNGEON_GUARD
#define DUNGEON_GUARD

#include <stdlib.h>
#include <curses.h>

static char cMap[] = {'.', '#'};

typedef struct TileStruct {
    int x; // x, y coordinates of the tile
    int y;
    char c; // character representation of tile

    int type; // type of tile (empty: 0, wall: 1, trap: 2, etc.)
} Tile;

Tile **make_room(int x, int y, int w, int h, Tile **other_tiles);
Tile **make_corridor(Tile *start_tile, Tile *end_tile, Tile **other_tiles);

#endif
