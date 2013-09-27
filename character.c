#include "character.h"

int main() 
{

    signal(SIGINT, finish);

    initscr();
    keypad(stdscr, TRUE);
    nonl();
    cbreak();
    noecho();

    Character *player = (Character*) malloc (sizeof Character);
    player->x = 1;
    player->y = 1;
    mvaddch(player->x, player->y, '@');

    for (;;) {
    
        int c = getch();
        clear();
        move(c, player);
    }
    return 0;
}

void move(int c, Character *player)
{
    switch(c)
    {
        case KEY_LEFT:
            if (player->x > 0)
                mvaddch(--player->x, player->y, '@');
            break;
        case KEY_RIGHT:
            if (player->x < 100)
                mvaddch(++player->x, player->y, '@');
            break;
        case KEY_UP:
            if (player->y > 0)
                mvaddch(player->x, --player->y, '@');
            break;
        case KEY_DOWN:
            if (player-> < 100)
                mvaddch(player->x,++player->y, '@');
            break;
    }
}
