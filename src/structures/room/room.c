#include <stdlib.h>
#include "../utils/types/types.h"
#include "room.h"

Room* create_room(int x, int y, int seed) {
    Room* room = malloc(sizeof(Room));
    room->coords.x = x;
    room->coords.y = y;
    room->seed = seed;
    room->left = NULL;
    room->right = NULL;
    room->up = NULL;
    room->down = NULL;
    return room;
}

Room* get_neighbour(Room* room, Direction direction) {
    switch (direction) {
        case LEFT:
            return room->left;
        case RIGHT:
            return room->right;
        case UP:
            return room->up;
        case DOWN:
            return room->down;
    }
}

Room* link_room(Room* room1, Room* room2, Direction direction) {
    switch (direction) {
        case LEFT:
            room1->left = room2;
            room2->right = room1;
            break;
        case RIGHT:
            room1->right = room2;
            room2->left = room1;
            break;
        case UP:
            room1->up = room2;
            room2->down = room1;
            break;
        case DOWN:
            room1->down = room2;
            room2->up = room1;
            break;
    }
}

void destroy_room(Room* room) {
    free(room);
}