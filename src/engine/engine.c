#include <stdlib.h>
#include <time.h>
#include "../utils/types/types.h"
#include "engine.h"
#include "../structures/room/room.h"

Engine* create_engine() {
    srand(time(NULL));
    Engine* engine = malloc(sizeof(Engine));
    engine->player.x = 0;
    engine->player.y = 0;
    engine->current_room = create_room(0, 0, 0);
    return engine;
}

void move_room(Engine* engine, enum Direction direction) {

    Room* new_room = get_neighbour(engine->current_room, direction);

    if (new_room == NULL) {

        // check d'abord dans hash table

        new_room = create_room(engine->current_room->coords.x, engine->current_room->coords.y, rand());
        link_room(engine->current_room, new_room, direction);
    }

    engine->current_room = new_room;

}

int main() {

    return 0;
}