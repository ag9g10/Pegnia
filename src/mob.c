#include "dungeon.h"
#include "mob.h"

static const int FLAG = 1 << 20;

static void enqueue(int pair);
static int dequeue();
static int is_empty();

static int calc_damage(Mob *monster);
static int is_adjacent_player(Mob *monster);
static int is_adjacent_mob();

static int make_pair(int x, int y);
static int get_x(int pair);
static int get_y(int pair);

int *queue;
int head;
int tail;

//Move monster to position (x,y)
void mob_move(Mob *monster, Dungeon *dungeon, int x, int y)
{
    monster->x = x;
    monster->y = y;

    mvaddch(y, x, monster->symbol);
}

//Attacks the player
void mob_attack(Mob *monster, Dungeon *dungeon)
{
    monster->player->health -= calc_damage(monster);
}

//Random damage calculator - Pending random damage.
static int calc_damage(Mob *monster)
{
    return 1;
}

//Move the mob a step.
void next_move(Mob *monster, Dungeon *dungeon)
{
    int i, j;
    int w = dungeon->w;
    int h = dungeon->h;

    Character *player = monster->player;

    if (is_adjacent_player(monster)) {
        mob_attack(monster, dungeon);
        mob_move(monster, dungeon, monster->x, monster->y);
        return;
    }
        
    //An array to store the move history.
    int **previous;
    previous = (int **) malloc(w*sizeof(int *));

    //Initialization with -1.
    for (i = 0; i < w; ++i) {
        previous[i] = (int *) malloc(h * sizeof(int));
        for (j = 0; j < h; ++j)
            previous[i][j] = -1;
    }

    queue = (int *) malloc (w*h*sizeof(int));
    head = tail = 0;

    //The 2D coordinates will be stored in one 31 bit signed int.
    //The first 10 bits will be for the x-coordinates.
    //The following 10 bits will be for the y-coordinates.
    int x = monster->x;
    int y = monster->y;
    previous[x][y] = FLAG;

    enqueue(make_pair(x, y));
    while (!is_empty()) {
        int pair = dequeue();
        x = get_x(pair);
        y = get_y(pair);

        //Check if player position has been found - Pending
        if (player->x == x && player->y == y)
            break;

        for (i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= dungeon->w || ny < 0 || ny >= dungeon->h)
                continue;
            if (previous[nx][ny] >= 0)
                continue;

            if (is_passable(dungeon, nx, ny) != 0) {
                previous[nx][ny] = pair;
                enqueue(make_pair(nx, ny));
            }
        }
    }

    //Backtrack to find the next block.
    x = player->x;
    y = player->y;
    int temp_x, temp_y;
    while (previous[x][y] != FLAG ) {
        temp_x = x;
        temp_y = y;
        x = get_x(previous[temp_x][temp_y]);
        y = get_y(previous[temp_x][temp_y]);
    }

    // free unneeded memory
    free(queue);
    for (i = 0; i < w; ++i)
        free(previous[i]);
    free(previous);

    mob_move(monster, dungeon, temp_x, temp_y);
}

//Adds x to the queue.
static void enqueue(int x)
{
    queue[head++] = x;
}

//Removes the tail of the queue.
static int dequeue()
{
    int temp_val = queue[tail++];
    return temp_val;
}

//Checks if the queue is empty.
static int is_empty()
{
    return head == tail;
}

static int make_pair(int x, int y)
{
    return x | (y << 10);
}

static int get_x(int pair)
{
    return pair & 1023;
}

static int get_y(int pair)
{
    return (pair >> 10) & 1023;
}

//Check if a player is adjacent.
//An adjacent player (4 directions) will have a distance difference of 1.
static int is_adjacent_player(Mob *monster)
{
    Character *player = monster->player;
    int i;
    for (i = 0; i < 4; ++i) {
        int nx = monster->x + dx[i];
        int ny = monster->y + dy[i];

        if ((player->x == nx) && (player->y == ny))
           return 1;
    }
    return 0;
}

//Check if a mob is adjacent. - Pending
static int is_adjacent_mob() 
{
    return 1;
}
