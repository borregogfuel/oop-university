#include "../include/course.h"

course::course(string course_code, string course_name, string department, int enrollment, schedule sched) {
    this->course_code = course_code;
    this->course_name = course_name;
    this->department = department;
    this->enrollment = enrollment;
    this->sched = sched;
    this->instructor_ref = nullopt;
    this->room_ref = nullopt;
}

string course::get_course_code() {
    return course_code;
}

string course::get_course_name() {
    return course_name;
}

string course::get_department() {
    return department;
}

int course::get_enrollment() {
    return enrollment;
}

schedule course::get_schedule() {
    return sched;
}

instructor* course::get_instructor() {
    if (instructor_ref.has_value()) {
        return instructor_ref.value();
    }
    return nullptr;
}

room* course::get_room() {
    if (room_ref.has_value()) {
        return room_ref.value();
    }
    return nullptr;
}

bool course::assign_instructor(instructor* i) {
    if (i == nullptr) {
        instructor_ref = nullopt;  
        return false;
    }
    instructor_ref = i;
    return true;
}

bool course::assign_room(room* r) {
    if (r == nullptr) {
        return false;
    }
    room_ref = r;
    return true;
}