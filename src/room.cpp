#include "../include/room.h"

room::room(string building, string room_number, int capacity) {
    this->building = building;
    this->room_number = room_number;
    this->capacity = capacity;
}

string room::get_building(){
    return building;
}

string room::get_room_number(){
    return room_number;
}

int room::get_capacity(){
    return capacity;
}

room::~room() {}