#include <stdlib.h>
#include "../../utils/types/types.h"
#include "room.h"
#include <stdio.h>
#include <limits.h>


Room* create_room(Coords coords, int seed) {
    Room* room = malloc(sizeof(Room));
    Sides* sides = malloc(sizeof(Sides));
    room->coords = coords;
    room->seed = seed;
    room->sides = sides;
    room->sides->left = NULL;
    room->sides->right = NULL;
    room->sides->up = NULL;
    room->sides->down = NULL;
    return room;
}

Room* get_neighbour_room(Room* room, Direction direction) {
    switch (direction) {
        case LEFT:
            return room->sides->left;
        case RIGHT:
            return room->sides->right;
        case UP:
            return room->sides->up;
        case DOWN:
            return room->sides->down;
    }
    return NULL;
}

Coords get_neighbour_room_coords(Room* room, Direction direction) {
    Coords coords;
    switch (direction) {
        case LEFT:
            coords.x = room->coords.x - 1;
            if (coords.x == -1) coords.x = INT_MAX;
            coords.y = room->coords.y;
            break;
        case RIGHT:
            coords.x = room->coords.x + 1;
            if (coords.x == INT_MIN) coords.x = 0;
            coords.y = room->coords.y;
            break;
        case UP:
            coords.x = room->coords.x;
            coords.y = room->coords.y + 1;
            if (coords.y == INT_MIN) coords.y = 0;
            break;
        case DOWN:
            coords.x = room->coords.x;
            coords.y = room->coords.y - 1;
            if (coords.y == -1) coords.y = INT_MAX;
            break;
    }
    return coords;
}

void link_room(Room* room1, Room* room2, Direction direction) {
    switch (direction) {
        case LEFT:
            room1->sides->left = room2;
            room2->sides->right = room1;
            break;
        case RIGHT:
            room1->sides->right = room2;
            room2->sides->left = room1;
            break;
        case UP:
            room1->sides->up = room2;
            room2->sides->down = room1;
            break;
        case DOWN:
            room1->sides->down = room2;
            room2->sides->up = room1;
            break;
    }
}

void destroy_room(Room* room) {
    free(room);
}