#include "../include/classroom.h"

classroom::classroom(string building, string room_number, int capacity)
    : room(building, room_number, capacity) {}

string classroom::get_type(){
    return "classroom";
}

