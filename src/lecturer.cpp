#include "../include/lecturer.h"

lecturer::lecturer(string name, string payroll_id, string department)
    : instructor(name, payroll_id, department) {}

string lecturer::get_type() const {
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