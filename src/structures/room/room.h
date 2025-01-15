
struct Room;

Room* create_room(int x, int y, int seed);
Room* get_neighbour(Room* room, Direction direction);
Room* link_room(Room* room1, Room* room2, Direction direction);

void destroy_room(Room* room);