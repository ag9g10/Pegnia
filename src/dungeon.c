#include "dungeon.h"

void init(Dungeon *dungeon, int w, int h)
{
    // free previous tiles of the dungeon
    free_tiles(dungeon);

    // reallocate enough space
    int i, j;
    dungeon->w = w, dungeon->h = h;
    dungeon->tiles = (Tile ***) malloc(w * sizeof(Tile **));
    for (i = 0; i < w; ++i) {
        dungeon->tiles[i] = (Tile **) malloc(h * sizeof(Tile *));
        for (j = 0; j < h; ++j) {
            dungeon->tiles[i][j] = (Tile *) malloc(sizeof(Tile));
            dungeon->tiles[i][j]->type = WALL;
        }
    }
}

void make_room(Dungeon *dungeon, int y, int x, int w, int h)
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
            set_visible(dungeon, i, j);
            set_passable(dungeon, i, j);
        }
    }
}

void make_corridor(Dungeon *dungeon, int sx, int sy, int len, int dir)
{
    if (dungeon->tiles[sx][sy]->type != WALL)
        return;

    int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
    int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

    int i = sx, j = sy;
    int k;
    for (k = 0; k < len; ++k, i += dx[dir], j += dy[dir]) {
        if (dungeon->tiles[i][j]->type != WALL)
            return;
    }

    i = sx, j = sy;
    for (k = 0; k < len; ++k, i += dx[dir], j += dy[dir]) {
        dungeon->tiles[i][j]->type = GROUND;
        set_visible(dungeon, i, j);
    }
}

void set_visible(Dungeon *dungeon, int x, int y)
{
    int dx[] = {0, 1, 0, -1, 0, 1, 1, -1, -1};
    int dy[] = {0, 0, 1, 0, -1, 1, -1, 1, -1};

    int i = 0;
    for (i = 0; i < 9; ++i) {
        dungeon->tiles[x + dx[i]][y + dy[i]]->properties |= VISIBLE;
    }
}

void set_passable(Dungeon *dungeon, int x, int y)
{
    dungeon->tiles[x][y]->properties |= PASSABLE;
}

void free_tiles(Dungeon *dungeon)
{
    int i, j;
    int w = dungeon->w, h = dungeon->h;
    for (i = 0; i < w; ++i) {
        for (j = 0; j < h; ++j) {
            free(dungeon->tiles[i][j]);
        }
        free(dungeon->tiles[i]);
    }
    if (w != 0 || h != 0)
        free(dungeon->tiles);
}

void free_dungeon(Dungeon *dungeon)
{
    free_tiles(dungeon);
    free(dungeon);
}
