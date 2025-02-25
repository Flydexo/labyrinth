#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../utils/types/types.h"
#include "./engine.h"
#include "../structures/room/room.h"
#include "../structures/hashtable/hashtable.h"
#include "../utils/math/math.h"
#include "../structures/dynarray/dynarray.h"

int hash(HValue* table, HKey key) {
    Coords k = *(Coords*)key;
    return pow_mod(2, k.x, dyn_size(table))*pow_mod(3,k.y,dyn_size(table)) % dyn_size(table);
}

Engine* create_engine() {
    srand(time(NULL));
    Engine* engine = malloc(sizeof(Engine));
    engine->player.x = 0;
    engine->player.y = 0;
    Coords coords = {0,0};
    engine->current_room = create_room(coords, 0);
    engine->rooms = create_hashtable(hash);
    return engine;
}

// void move_room(Engine* engine,Direction direction) {

//     Room* new_room = get_neighbour_room(engine->current_room, direction);

//     if (new_room == NULL) {

//         Coords new_coords = get_neighbour_room_coords(engine->current_room, direction);

//         if (has_hashtable(engine->rooms, &new_coords)) {
//             new_room = get_hashtable(engine->rooms, &new_coords);
//         } else {
//             new_room = create_room(engine->current_room->coords, rand());
//             set_hashtable(engine->rooms, &new_coords, new_room);
//         }
        
//         link_room(engine->current_room, new_room, direction);

//     }

//     engine->current_room = new_room;

//     // update player coords

// }

int main() {
    printf("Hello World!\n");
    return 0;
}