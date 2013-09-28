#include "mob.h"

/* A mob will go left until it hits a wall, and then right.
 * Needs wall recognition.
 */

void mobMove(Mob *monster, Dungeon *dungeon)
{
    int direction; // 0 - left, 1 - right
        if (direction == 0) {
            if (monster->x > 0) {
                mvaddch(monster->y, --monster->x, monster->symbol);
            }
            else { 
                direction = 1;
                mvaddch(monster->y, ++monster->x, monster->symbol);
            }
        } 
        else {
            if (monster->x < 100) {
                mvaddch(monster->y, ++monster->x, monster->symbol);
            }
            else {
                direction = 0;
                mvaddch(monster->y, --monster->x, monster->symbol);
            }
        }
}

