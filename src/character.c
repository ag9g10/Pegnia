#include "character.h"
#include "mob.h"

static void finish(int sig);

int main() 
{

    Character *player;
    player = (Character*) malloc (sizeof (Character));
    player->x = 1;
    player->y = 1;
    signal(SIGINT, finish);

    initscr();
    keypad(stdscr, TRUE);
    nonl();
    cbreak();
    noecho();
    
    //Monster test begin.
    Mob *monster;
    monster = (Mob*) malloc (sizeof(Mob));
    monster->x = 5;
    monster->y = 10;
    monster->symbol = 'M';
    //Monster test end.
    
    mvaddch(player->x, player->y, '@');

    for (;;) {
    
        int c = getch();
        clear();
        playerMove(c, player, dungeon);
        mobMove(monster, dungeon);
    }
    finish(0);
}

void playerMove(int c, Character *player, Dungeon *dungeon)
{
    switch(c)
    {
        case KEY_LEFT:
            if (dungeon->tiles[player->x - 1][player->y]->properties & PASSABLE != 0)
                mvaddch(player->y, --player->x, '@');
            break;
        case KEY_RIGHT:
            if (dungeon->tiles[player->x + 1][player->y]->properties & PASSABLE != 0)
                mvaddch(player->y, ++player->x, '@');
            break;
        case KEY_UP:
            if (dungeon->tiles[player->x][player->y - 1]->properties & PASSABLE != 0)
                mvaddch(--player->y, player->x, '@');
            break;
        case KEY_DOWN:
            if (dungeon->tiles[player->x][player->y + 1]->properties & PASSABLE != 0)
                mvaddch(++player->y, player->x, '@');
            break;
    }
}

static void finish(int sig) {
    endwin();

    exit(0);
}
