#include "tile.h"

char char_repr(Tile *tile)
{
    return c_map[(int) tile->type];
}
