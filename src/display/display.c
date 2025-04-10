#include <stdio.h>
#include "display.h"
#include "../structures/room/room.h"

void display_commands() {
    printf("Commands: up: [k], down: [j], left: [h], right: [l]\n");
}
void display_room(Room* room) {
    printf("Room: (%d,%d)\n", room->coords.x, room->coords.y);
    printf("Seed: %d\n", room->seed);
    if(room->seed % 10 == 0) {
        printf("THERE IS A PORTAL HERE!\n");
        printf("Take it with [p]\n");
    }
    display_commands();
}