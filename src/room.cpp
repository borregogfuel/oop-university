#include "../include/room.hpp"

string room::get_building(){
    return building;
}

int room::get_room_number(){
    return room_number;
}

int room::get_capacity(){
    return capacity;
}

room::~room() {}