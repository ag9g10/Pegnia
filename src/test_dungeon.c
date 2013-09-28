#include "dungeon.h"
#include "tile.h"

#include <signal.h>

#include <character.h>
#include <mob.h>

static void finish(int sig);
void draw_dungeon();

int main()
{
    //Player test
    Character *player;
    player = (Character*) malloc (sizeof (Character));
    player->x = 2;
    player->y = 2;

    signal(SIGINT, finish);

    initscr();
    keypad(stdscr, TRUE);
    nonl();
    cbreak();
    noecho();

    //Monster test

    //Dungeon test
    Dungeon *dungeon;
    dungeon = (Dungeon *) malloc (sizeof (Dungeon));
    init(dungeon, 20, 20);
    make_room(dungeon,1, 1, 10, 5);
    make_room(dungeon,10, 10, 5, 5);
    draw_dungeon(dungeon);

    mvaddch(player->x, player->y, '@');

    for (;;) {
    
        int c = getch();
        clear();
        playerMove(c, player, dungeon);
        //mobMove(monster, dungeon);
    }

    getch();
    finish(0);

    return 0;
}

void draw_dungeon(Dungeon *dungeon)
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
