#include <stdlib.h>
#include <time.h>
#include "../utils/types/types.h"
#include "engine.h"
#include "../structures/room/room.h"
#include "../structures/hashtable/hashtable.h"

Engine* create_engine() {
    srand(time(NULL));
    Engine* engine = malloc(sizeof(Engine));
    engine->player.x = 0;
    engine->player.y = 0;
    Coords coords = {0,0};
    engine->current_room = create_room(coords, 0);
    engine->rooms = create_hashtable();
    return engine;
}

void move_room(Engine* engine, enum Direction direction) {

    Room* new_room = get_neighbour_room(engine->current_room, direction);

    if (new_room == NULL) {

        Coords new_coords = get_neighbour_room_coords(engine->current_room, direction);

        if (has_hashtable(engine->rooms, new_coords)) {
            new_room = get_hashtable(engine->rooms, new_coords);
        } else {
            new_room = create_room(engine->current_room->coords, rand());
            set_hashtable(engine->rooms, new_coords, new_room);
        }
        
        link_room(engine->current_room, new_room, direction);

    }

    engine->current_room = new_room;

    // update player coords

}

int main() {

    return 0;
}