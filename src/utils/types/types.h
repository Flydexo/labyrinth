typedef struct Coords {
    int x;
    int y;
} Coords;

typedef struct Room {
    int seed;
    Coords coords;
    Sides sides;
    Metadata metadata;
} Room;

typedef struct Sides {
    Room* up;
    Room* right;
    Room* down;
    Room* left;
} Sides;

typedef struct Metadata {} Metadata;