#include <stdlib.h>
#include "room.h"

typedef struct Room { int x; int y; Room* left; Room* right; Room* up; Room* down } Room;

Room* create_room(int x, int y) {
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    room->left = NULL;
    room->right = NULL;
    room->up = NULL;
    room->down = NULL;
    return room;
}

Room* get_left(Room* room) {
    return room->left;
}

Room* get_right(Room* room) {
    return room->right;
}

Room* get_up(Room* room) {
    return room->up;
}

Room* get_down(Room* room) {
    return room->down;
}

Room* set_left(Room* room, Room* left) {
    room->left = left;
    return room;
}

void destroy_room(Room* room) {
    free(room);
}