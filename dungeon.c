#include "dungeon.h"

#include <stdio.h>

Tile **make_room(int x, int y, int w, int h, Tile **other_tiles)
{
    //TODO: Check against already existing tiles
    int i, j;
    int c = 0;

    Tile **tiles = (Tile **) malloc(w * h * sizeof(Tile *));
    for (i = 0; i < w * h; ++i)
        tiles[i] = (Tile *) malloc(sizeof(Tile));

    // build the vertical walls
    for (i = x; i < x + w; ++i) {
        Tile *t = tiles[c++];
        t->x = i, t->y = y;
        t->type = 1;

        if (y != y + h - 1) {
            t = tiles[c++];
            t->x = i, t->y = y + h - 1;
            t->type = 1;
        }
    }

    // build the horizontal walls
    for (j = y + 1; j < y + h - 1; ++j) {
        Tile *t = tiles[c++];
        t->x = x, t->y = j;
        t->type = 1;

        if (x != x + w - 1) {
            t = tiles[c++];
            t->x = x + w - 1, t->y = j;
            t->type = 1;
        }
    }

    // build the inside of the room
    for (i = x + 1; i < x + w - 1; ++i)
        for (j = y + 1; j < y + h - 1; ++j) {
            Tile *t = tiles[c++];
            t->x = i, t->y = j;
            t->type = 0;
        }

    for (i = 0; i < c; ++i)
        tiles[i]->c = cMap[tiles[i]->type];

    return tiles;
}
