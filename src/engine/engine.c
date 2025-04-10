#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../utils/types/types.h"
#include "./engine.h"
#include "../structures/room/room.h"
#include "../structures/hashtable/hashtable.h"
#include "../utils/math/math.h"
#include "../structures/dynarray/dynarray.h"
#include "../display/display.h"
#include <unistd.h>
#include <poll.h>
#include <stdio.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include "../utils/types/types.h"
#include "../structures/room/room.h"
#include "../structures/hashtable/hashtable.h"

int hash(Hashtable* table, HKey key) {
    Coords k = *(Coords*)key;
    return abs(pow_mod(2, k.x, dyn_size(table->table))*pow_mod(3,k.y,dyn_size(table->table)) % dyn_size(table->table));
}

Engine* create_engine() {
    srand(time(NULL));
    Engine* engine = malloc(sizeof(Engine));
    engine->player.x = 0;
    engine->player.y = 0;
    Coords coords = {0,0};
    engine->current_room = create_room(coords, 0);
    engine->rooms = create_hashtable(hash);
    printf("Engine created!!\n");
    fflush(stdout);
    return engine;
}

void move_room(Engine* engine,Direction direction) {

    Room* new_room = get_neighbour_room(engine->current_room, direction);

    if (new_room == NULL) {

        Coords new_coords = get_neighbour_room_coords(engine->current_room, direction);

        if (has_hashtable(engine->rooms, &new_coords)) {
            new_room = get_hashtable(engine->rooms, &new_coords);
        } else {
            printf("before create room");
            fflush(stdout);
            new_room = create_room(new_coords, rand());
            printf("before hashtable\n");
            fflush(stdout);
            set_hashtable(engine->rooms, &new_coords, new_room);
        }
        
        link_room(engine->current_room, new_room, direction);

    }

    engine->current_room = new_room;

    // update player coords

}

int getch() {
    int acquisition_time = 50 ;
    
    int ch;
    struct termios oldattr, newattr;

    if (tcgetattr(STDIN_FILENO, &oldattr) != 0) {
        perror("tcgetattr");
    }

    newattr = oldattr;

    // Disable canonical mode and echo
    newattr.c_lflag &= ~(ICANON | ECHO);

    // Set VMIN and VTIME to control read behavior
    newattr.c_cc[VMIN] = 1;   // Minimum number of characters to read
    newattr.c_cc[VTIME] = 0;  // Timeout value (0 = no timeout)
    
    if (tcsetattr(STDIN_FILENO, TCSANOW, &newattr) != 0) {
        perror("tcsetattr");
    }
    struct pollfd mypoll = { STDIN_FILENO, POLLIN | POLLPRI };

    // Poll the input
    if (poll(&mypoll, 1, acquisition_time) > 0) {
        ch = getchar();
    } else if (errno != 0) {
        perror("poll");
    }

    // Flush remaining input to avoid characters "remaining"
    tcflush(STDIN_FILENO, TCIFLUSH);

    // Restore the original terminal settings
    if (tcsetattr(STDIN_FILENO, TCSANOW, &oldattr) != 0) {
        perror("tcsetattr");
    }

    return ch; 
}

int main() {
    Engine* engine = create_engine();
    display_room(engine->current_room);
    while (1) {
        int choice = getch();
        
        if (choice == 'q' || choice == 'Q') {
            break;
        } else if(choice == 'k') {
            move_room(engine, UP);
            display_room(engine->current_room);
        } else if(choice == 'j') {
            move_room(engine, DOWN); 
            display_room(engine->current_room);
        } else if(choice == 'h') {
            move_room(engine, LEFT);
            display_room(engine->current_room);
        } else if(choice == 'l') {
            move_room(engine, RIGHT);
            display_room(engine->current_room);
        } else if(choice == 'a') {
            hashtable_stats(engine->rooms);
        }
    }
    
    return 0;
}