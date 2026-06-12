#include "../include/instructor.h"

instructor::instructor(string name, string payroll_id, string department) {
    this->name = name;
    this->payroll_id = payroll_id;
    this->department = department;
    this->course_count = 0;
}


string instructor::get_name(){
    return name;
}

string instructor::get_payroll_id(){
    return payroll_id;
}

string instructor::get_department(){
    return department;
}

int instructor::get_course_count(){
    return course_count;
}

bool instructor::operator<(const instructor& other){
    if(get_type() == "lecturer" && other.get_type() == "professor"){
        return true;
    }
    if(get_type() == "professor" && other.get_type() == "lecturer"){
        return false;
    }

    return department < other.department;
}

bool instructor::operator>(const instructor& other){
    if(get_type() == "lecturer" && other.get_type() == "professor"){
        return false;
    }

    if(get_type() == "professor" && other.get_type() == "lecturer"){
        return true;
    }

    return department > other.department;
}

bool instructor::operator==(const instructor& other){
    return get_type() == other.get_type() && department == other.department;
}

void instructor::add_course() {
    course_count++;
}

void instructor::remove_course() {
    course_count--;
}

instructor::~instructor() {}
