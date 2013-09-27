#ifndef TILE_GUARD
#define TILE_GUARD

enum types { GROUND, WALL };
enum properties { VISIBLE = 1 };

typedef struct TileStruct {
    unsigned int properties; // treat as bitset with properties

    enum types type; // type of tile (empty: 0, ground: 1, wall: 2, trap: 3, etc.)
} Tile;

char char_repr(Tile *tile);

#endif
