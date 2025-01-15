typedef struct Coords {
    int x;
    int y;
} Coords;

typedef enum Direction { LEFT, RIGHT, UP, DOWN } Direction;

typedef struct Room {
    int seed;
    Coords coords;
    struct Room* left;
    struct Room* right;
    struct Room* up;
    struct Room* down;
} Room;

typedef struct Engine {
    Coords player;
    Room* current_room;
} Engine;