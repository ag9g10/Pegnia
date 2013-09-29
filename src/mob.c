#include "mob.h"

//Move monster to position (x,y)

void mobMove(Mob *monster, Dungeon *dungeon, int x, int y)
{
    monster->x = x;
    monster->y = y;

    mvaddch(y, x, monster->symbol);
}

void next_move(Mob *monster, Character *player, Dungeon *dungeon) {

    int x = monster->x;
    int y = monster->y;

    if (is_passable(dungeon, x - 1, y) != 0)
        x--;
    mobMove(monster, dungeon, x, y);
}
