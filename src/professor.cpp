#include <climits>
#include "../include/professor.hpp"


string professor::get_type(){
    return "professor";
}

int professor::get_max_courses(){
    return INT_MAX;
}

bool professor::meets_minimum(){
    if(course_count >= 2){
        return true;
    }
    return false;
}