#include <stdlib.h>
#include "../utils/types/types.h"
#include "room.h"

Room* create_room(Coords coords, int seed) {
    Room* room = malloc(sizeof(Room));
    room->coords = coords;
    room->seed = seed;
    room->left = NULL;
    room->right = NULL;
    room->up = NULL;
    room->down = NULL;
    return room;
}

Room* get_neighbour_room(Room* room, Direction direction) {
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
    return NULL;
}

Coords get_neighbour_room_coords(Room* room, Direction direction) {
    Coords coords;
    switch (direction) {
        case LEFT:
            coords.x = room->coords.x - 1;
            coords.y = room->coords.y;
            break;
        case RIGHT:
            coords.x = room->coords.x + 1;
            coords.y = room->coords.y;
            break;
        case UP:
            coords.x = room->coords.x;
            coords.y = room->coords.y + 1;
            break;
        case DOWN:
            coords.x = room->coords.x;
            coords.y = room->coords.y - 1;
            break;
    }
    return coords;
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