#include "character.h"
#include "mob.h"
#include "utils.h"

void playerMove(int c, Character *player, Dungeon *dungeon)
{
    int x = player->x;
    int y = player->y;

    switch(c)
    {
        case KEY_LEFT:
            if (is_passable(dungeon, x - 1, y))
                mvaddch(y, --x, '@');
            break;
        case KEY_RIGHT:
            if (is_passable(dungeon, x + 1, y))
                mvaddch(y, ++x, '@');
            break;
        case KEY_UP:
            if (is_passable(dungeon, x, y - 1))
                mvaddch(--y, x, '@');
            break;
        case KEY_DOWN:
            if (is_passable(dungeon, x, y + 1))
                mvaddch(++y, x, '@');
            break;
    }
}
