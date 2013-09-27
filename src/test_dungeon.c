#include "dungeon.h"
#include "tile.h"

#include <signal.h>

static void finish(int sig);
void draw_dungeon();

int main()
{
    signal(SIGINT, finish);

    initscr();
    keypad(stdscr, TRUE);
    nonl();
    cbreak();
    noecho();

    init(20, 20);
    make_room(1, 1, 10, 5);
    make_room(10, 10, 5, 5);
    draw_dungeon(20, 20);

    getch();
    finish(0);

    return 0;
}

void draw_dungeon()
{
    int i, j;

    for (i = 0; i < dungeon->w; ++i)
        for (j = 0; j < dungeon->h; ++j) {
            if (dungeon->tiles[i][j]->properties & VISIBLE)
                mvaddch(j, i, char_repr(dungeon->tiles[i][j]));
        }
}

static void finish(int sig)
{
    endwin();

    exit(0);
}
