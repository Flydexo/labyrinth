

struct Room;

Room* create_room(int x, int y);

Room* get_left(Room* room);
Room* get_right(Room* room);
Room* get_up(Room* room);
Room* get_down(Room* room);

void destroy_room(Room* room);