#include "utils.h"

/*
 * A method to check whether a tile is passable.
 */
int is_passable(Dungeon *dungeon, int x, int y) {
    if ((dungeon->tiles[x][y]->properties & PASSABLE) != 0)
        return 1;
    return 0;
}
