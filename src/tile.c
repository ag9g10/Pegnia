#include "tile.h"

static char c_map[] = {'.', '#'};

char char_repr(Tile *tile)
{
    return c_map[(int) tile->type];
}
