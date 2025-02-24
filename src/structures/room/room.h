
struct Room;

Room* create_room(Coords coord, int seed);
Room* get_neighbour_room(Room* room, Direction direction);
Coords get_neighbour_room_coords(Room* room, Direction direction);
Room* link_room(Room* room1, Room* room2, Direction direction);

void destroy_room(Room* room);