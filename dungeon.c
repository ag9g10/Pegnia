#include "dungeon.h"

#include <stdio.h>

void init(int w, int h)
{
    dungeon = (Dungeon *) malloc(sizeof(Dungeon));

    dungeon->w = w, dungeon->h = h;

    int i, j;
    dungeon->tiles = (Tile ***) malloc(w * sizeof(Tile **));
    for (i = 0; i < w; ++i) {
        dungeon->tiles[i] = (Tile **) malloc(h * sizeof(Tile *));
        for (j = 0; j < h; ++j) {
            dungeon->tiles[i][j] = (Tile *) malloc(sizeof(Tile));
            dungeon->tiles[i][j]->type = WALL;
        }
    }
}

void make_room(int y, int x, int w, int h)
{
    int i, j;
    // check if room has space
    if (x - 1 < 0 || x + w >= dungeon->w || y - 1 < 0 || y + h >= dungeon->h)
        return;
    for (i = x - 1; i <= x + w; ++i)
        for (j = y - 1; j <= y + h; ++j)
            if (dungeon->tiles[i][j]->type != WALL)
                return;

    // build the inside of the room
    Tile *t;
    for (i = x; i < x + w; ++i) {
        for (j = y; j < y + h; ++j) {
            t = dungeon->tiles[i][j];
            t->type = GROUND;
            t->properties |= 1;
        }
    }

    // make the room walls visible
    for (i = x - 1; i <= x + w; ++i) {
        t = dungeon->tiles[i][y - 1];
        t->properties |= 1;
        t = dungeon->tiles[i][y + h];
        t->properties |= 1;
    }
    for (i = y - 1; i <= y + h; ++i) {
        t = dungeon->tiles[x - 1][i];
        t->properties |= 1;
        t = dungeon->tiles[x + w][i];
        t->properties |= 1;
    }
}

void make_corridor(int sx, int sy, int ex, int ey)
{
    // TODO: make this work
    if (dungeon->tiles[sx][sy]->type != WALL)
        return;
    if (dungeon->tiles[ex][ey]->type != WALL)
        return;

    dungeon->tiles[sx][sy]->type = GROUND;
    dungeon->tiles[ex][ey]->type = GROUND;

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
}
