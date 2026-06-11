#include "../include/laboratory.h"

laboratory::laboratory(string building, string room_number, int capacity, int equipment_max)
    : room(building, room_number, capacity) {
    this->equipment_count = 0;
    this->equipment_max = equipment_max;
    this->equipment = new string[equipment_max];
}

string laboratory::get_type(){
    return "laboratory";
}

string* laboratory::get_equipment(){
    return equipment;
}

int laboratory::get_equipment_count(){
    return equipment_count;
}

void laboratory::add_equipment(string name){
    if(equipment_count < equipment_max){
        equipment[equipment_count] = name;
        equipment_count++;
    }
}