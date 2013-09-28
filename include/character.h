#ifndef CHARACTER_GUARD
#define CHARACTER_GUARD

#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <dungeon.h>

typedef struct CharacterStruct {
    int x; //Coordinates of the character.
    int y;
    int health; //HP of the character
    char *name; //Name of the character.

} Character;

void playerMove(int c, Character *player, Dungeon *dungeon);
void attack(int c, Character *player, Dungeon *dungeon); //Add damage capabiity.

#endif
