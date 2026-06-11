#include "../include/laboratory.hpp"

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