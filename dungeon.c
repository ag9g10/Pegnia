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

Tile **make_corridor(Tile *start_tile, Tile *end_tile, Tile **other_tiles)
{
    start_tile->type = 0;
    start_tile->c = cMap[start_tile->type];

    int sx = start_tile->x;
    int sy = start_tile->y;
    int ex = end_tile->x;
    int ey = end_tile->y;

    int size = 0;
    size += sx < ex ? ex - sx : sx - ex;
    size += sy < ey ? ey - sy : sy - ey;

    int i, j;
    Tile **tiles = (Tile **) malloc(size * sizeof(Tile *));
    for (i = 0; i < size; ++i)
        tiles[i] = (Tile *) malloc(sizeof(Tile));

    int c = 0;
    int dx = sx < ex ? 1 : -1;
    int dy = sy < ey ? 1 : -1;
    for (i = ex; i != sx; i -= dx) {
        // empty space (actual corridor)
        Tile *tile = tiles[c++];
        tile->x = i, tile->y = sy;
        tile->type = 0;
        tile->c = cMap[tile->type];
    }

    for (i = ey; i != sy; i -= dy) {
        // empty space (actual corridor)
        Tile *tile = tiles[c++];
        tile->x = ex, tile->y = i;
        tile->type = 0;
        tile->c = cMap[tile->type];
    }

    end_tile->type = 0;
    end_tile->c = cMap[end_tile->type];

    return tiles;
}
