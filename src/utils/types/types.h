typedef struct Coords {
    int x;
    int y;
} Coords;

<<<<<<< Updated upstream
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
    Hashtable* rooms;
} Engine;
=======
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
>>>>>>> Stashed changes
