#include "character.h"

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

    mvaddch(player->x, player->y, '@');

    for (;;) {
    
        int c = getch();
        clear();
        playerMove(c, player);
    }
    finish(0);
}

void playerMove(int c, Character *player)
{
    switch(c)
    {
        case KEY_LEFT:
            if (player->x > 0)
                mvaddch(player->y, --player->x, '@');
            break;
        case KEY_RIGHT:
            if (player->x < 100)
                mvaddch(player->y, ++player->x, '@');
            break;
        case KEY_UP:
            if (player->y > 0)
                mvaddch(--player->y, player->x, '@');
            break;
        case KEY_DOWN:
            if (player->y < 100)
                mvaddch(++player->y, player->x, '@');
            break;
    }
}

static void finish(int sig) {
    endwin();

    exit(0);
}
