#ifndef TYPES_H
#define TYPES_H

typedef struct Coords {
    int x;
    int y;
} Coords;

typedef struct Metadata {} Metadata;

typedef struct Room Room;

typedef struct Sides Sides;

struct Room {
    int seed;
    Coords coords;
    Sides* sides;
    Metadata metadata;
};

struct Sides {
    Room* up;
    Room* right;
    Room* down;
    Room* left;
};
#endif