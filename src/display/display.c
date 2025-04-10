#include <stdio.h>
#include "display.h"
#include "../structures/room/room.h"

void display_commands() {
    printf("Commands: up: [k], down: [j], left: [h], right: [l]\n");
}
void display_room(Room* room) {
    printf("Room: (%d,%d)\n", room->coords.x, room->coords.y);
    printf("Seed: %d\n", room->seed);
    display_commands();
}