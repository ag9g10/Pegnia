#include "generator.h"

static int rand_int(int max_num, int min_num);

void generate(Dungeon *dungeon)
{
    int w = dungeon->w;
    int h = dungeon->h;

    make_room(dungeon, w / 2 - 2, h / 2 - 2, 5, 5, 0);

    int i;
    for (i = 0; i < 5 * w * h; ++i) {
        int x = rand_int(w, 0);
        int y = rand_int(h, 0);

        if (!is_near_empty(dungeon, x, y))
            continue;

        int p_type = rand_int(2, 0);
        if (!p_type) {
            make_random_room(dungeon, x, y);
        } else {
            make_random_corridor(dungeon, x, y);
        }
    }
}

// create rooms/corridors
void make_random_room(Dungeon *dungeon, int x, int y)
{
    int w = dungeon->w;
    int h = dungeon->h;

    int room_w = rand_int(w / 2, 3);
    int room_h = rand_int(h / 2, 3);
    int dir = rand_int(4, 0);

    // make the (x, y) tile a GROUND tile
    if (make_room(dungeon, x + dx[dir], y + dy[dir], room_w, room_h, dir))
        dungeon->tiles[x][y]->type = GROUND;
}

void make_random_corridor(Dungeon *dungeon, int x, int y)
{
    int w = dungeon->w;
    int h = dungeon->h;

    int len = rand_int(min(w / 2, h / 2), 3);
    int dir = rand_int(4, 0);

    // make the (x, y) tile a GROUND tile
    if(make_corridor(dungeon, x + dx[dir], y + dy[dir], len, dir))
        dungeon->tiles[x][y]->type = GROUND;
}

// utility functions
int is_near_empty(Dungeon *dungeon, int x, int y)
{
    int w = dungeon->w;
    int h = dungeon->h;

    int i;
    for (i = 0; i < 4; ++i) {
        if (x + dx[i] < 0 || x + dx[i] >= w || y + dy[i] < 0 || y + dy[i] >= h)
            continue;
        if (dungeon->tiles[x + dx[i]][y + dy[i]]->type == GROUND)
            return 1;
    }
    return 0;
}

static int rand_int(int max_num, int min_num)
{
    double r = genrand_real2();

    return (int) (min_num + r * (max_num - min_num));
}
