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
    return name < other.name;
}

bool instructor::operator>(const instructor& other){
    return name > other.name;
}

bool instructor::operator==(const instructor& other){
    return name == other.name;
}

instructor::~instructor() {}
