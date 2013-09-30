#include "dungeon.h"
#include "generator.h"
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
    Mob *monster;
    monster = (Mob *) malloc (sizeof (Mob));
    monster->x = 55;
    monster->y = 13;
    monster->symbol = 'M';
    monster->player = player;

    //Dungeon test
    Dungeon *dungeon;
    dungeon = (Dungeon *) malloc (sizeof (Dungeon));
    init(dungeon, 90, 25);
    generate(dungeon);
    draw_dungeon(dungeon);

    mvaddch(monster->y, monster->x, 'M');
    mvaddch(player->x, player->y, '@');

    for (;;) {

        int c = getch();
        clear();
        draw_dungeon(dungeon);
        playerMove(c, player, dungeon);
        next_move(monster, dungeon);
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
