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

// return success value
int make_room(Dungeon *dungeon, int x, int y, int w, int h, int dir)
{
    w = dx[dir] < 0 ? -w : w;
    h = dy[dir] < 0 ? -h : h;
    int ix = dx[dir] < 0 ? -1 : 1;
    int iy = dy[dir] < 0 ? -1 : 1;

    int i, j;
    // check if room has space
    if (x - ix <= 0 || x - ix >= dungeon->w - 1 ||
            x + w <= 0 || x + w >= dungeon->w - 1)
        return 0;
    if (y - iy <= 0 || y - iy >= dungeon->h - 1 ||
            y + h <= 0 || y + h >= dungeon->h - 1)
        return 0;

    for (i = x - ix; i != x + w + ix; i += ix)
        for (j = y - iy; j != y + h + iy; j += iy)
            if (dungeon->tiles[i][j]->type != WALL)
                return 0;

    // build the inside of the room
    Tile *t;
    for (i = x; i != x + w; i += ix) {
        for (j = y; j != y + h; j += iy) {
            t = dungeon->tiles[i][j];
            t->type = GROUND;
            set_visible(dungeon, i, j);
            set_passable(dungeon, i, j);
        }
    }

    return 1;
}

// return success value
int make_corridor(Dungeon *dungeon, int sx, int sy, int len, int dir)
{
    int w = dungeon->w;
    int h = dungeon->h;

    if (sx < 0 || sx >= w - 1 || sy < 0 || sy >= h - 1)
        return 0;
    if (dungeon->tiles[sx][sy]->type != WALL)
        return 0;

    // left, down, right, up, and diagonal
    int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
    int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

    int k;
    int i = sx, j = sy;
    // check we have space to build corridor
    for (k = 0; k < len; ++k, i += dx[dir], j += dy[dir]) {
        if (i <= 0 || i >= w - 1 || j <= 0 || j >= h - 1)
            return 0;
        if (dungeon->tiles[i][j]->type != WALL)
            return 0;

        if (dx[dir]) {
            if (dungeon->tiles[i][j + 1]->type != WALL)
                return 0;
            if (dungeon->tiles[i][j - 1]->type != WALL)
                return 0;
        } else if (dy[dir]) {
            if (dungeon->tiles[i + 1][j]->type != WALL)
                return 0;
            if (dungeon->tiles[i - 1][j]->type != WALL)
                return 0;
        }
    }

    i = sx, j = sy;
    for (k = 0; k < len; ++k, i += dx[dir], j += dy[dir]) {
        dungeon->tiles[i][j]->type = GROUND;
        set_visible(dungeon, i, j);
        set_passable(dungeon, i, j);
    }

    return 1;
}

void set_visible(Dungeon *dungeon, int x, int y)
{
    int i = 0;
    // tile and all the surrounding tiles are now visible
    dungeon->tiles[x][y]->properties |= VISIBLE;
    for (i = 0; i < 8; ++i) {
        dungeon->tiles[x + dx[i]][y + dy[i]]->properties |= VISIBLE;
    }
}

void set_passable(Dungeon *dungeon, int x, int y)
{
    dungeon->tiles[x][y]->properties |= PASSABLE;
}

// memory cleanup
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
