#ifndef CHARACTER_GUARD
#define CHARACTER_GUARD

#include <stdlib.h>
#include <curses.h>
#include <signal.h>

typedef struct CharacterStruct {
    int x; //Coordinates of the character.
    int y;
    int health; //HP of the character
    char *name; //Name of the character.

} Character;

void playerMove(int c, Character *player);
void attack(int c, Character *player); //Add damage capabiity.

#endif
