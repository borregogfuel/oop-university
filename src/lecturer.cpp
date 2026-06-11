
#include "../include/lecturer.hpp"

string lecturer::get_type(){
    return "lecturer";
}

int lecturer::get_max_courses(){
    return 3;
}

bool lecturer::is_at_limit(){
    if(course_count >= 3){
        return true;
    }
    return false;
}