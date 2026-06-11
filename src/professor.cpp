#include <climits>
#include "../include/professor.h"

professor::professor(string name, string payroll_id, string department)
    : instructor(name, payroll_id, department) {}

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