#include "character.h"
#include "mob.h"

#include <unistd.h>
#include <sys.ioctl.h>

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
    monster->symbol = 'U';
    //Monster test end.
    
    //Code to measure terminal window size.
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    mvaddch(player->x, player->y, '@');

    for (;;) {
    
        int c = getch();
        clear();
        playerMove(c, player, w);
        mobMove(monster);
    }
    finish(0);
}

void playerMove(int c, Character *player, struct winsize w)
{
    switch(c)
    {
        case KEY_LEFT:
            if (player->x > 0)
                mvaddch(player->y, --player->x, '@');
            break;
        case KEY_RIGHT:
            if (player->x < w.ws_col)
                mvaddch(player->y, ++player->x, '@');
            break;
        case KEY_UP:
            if (player->y > 0)
                mvaddch(--player->y, player->x, '@');
            break;
        case KEY_DOWN:
            if (player->y < w.ws_row)
                mvaddch(++player->y, player->x, '@');
            break;
    }
}

static void finish(int sig) {
    endwin();

    exit(0);
}
