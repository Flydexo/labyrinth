#include "../structures/hashtable/hashtable.h"
#include "../structures/room/room.h"

typedef struct {
    int x;
    int y;
} Player;

struct Engine {
    Player player;
    Room* current_room;
    Hashtable* rooms;
};
typedef struct Engine Engine;


Engine* create_engine();
void move_room(Engine* engine, Direction direction);