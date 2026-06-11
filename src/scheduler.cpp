#include "../include/scheduler.h"

scheduler::scheduler(int instructor_max, int room_max, int course_max) {
    this->instructor_max = instructor_max;
    this->instructor_count = 0;
    this->instructors = new instructor*[instructor_max];

    this->room_max = room_max;
    this->room_count = 0;
    this->rooms = new room*[room_max];

    this->course_max = course_max;
    this->course_count = 0;
    this->courses = new course*[course_max];
}

scheduler::~scheduler() {
    for (int i = 0; i < instructor_count; i++) {
        delete instructors[i];
    }
    delete[] instructors;

    for (int i = 0; i < room_count; i++) {
        delete rooms[i];
    }
    delete[] rooms;

    for (int i = 0; i < course_count; i++) {
        delete courses[i];
    }
    delete[] courses;
}

instructor* scheduler::add_instructor(string name, string payroll_id, string department, string type) {
    if (instructor_count >= instructor_max) return nullptr;
    instructor* i;
    if (type == "professor") {
        i = new professor(name, payroll_id, department);
    } else {
        i = new lecturer(name, payroll_id, department);
    }
    instructors[instructor_count++] = i;
    return i;
}

room* scheduler::add_room(string building, string room_number, int capacity, string type, int equipment_max) {
    if (room_count >= room_max) return nullptr;
    room* r;
    if (type == "classroom") {
        r = new classroom(building, room_number, capacity);
    } else {
        r = new laboratory(building, room_number, capacity, equipment_max);
    }
    rooms[room_count++] = r;
    return r;
}

course* scheduler::add_course(string course_code, string course_name, string department, int enrollment, schedule sched) {
    if (course_count >= course_max) return nullptr;
    course* c = new course(course_code, course_name, department, enrollment, sched);
    courses[course_count++] = c;
    return c;
}

bool scheduler::check_double_booking_instructor(instructor* i, schedule s) {
    for (int j = 0; j < course_count; j++) {
        if (courses[j]->get_instructor() == i) {
            if (courses[j]->get_schedule().overlaps(s)) {
                return true;
            }
        }
    }
    return false;
}

bool scheduler::check_double_booking_room(room* r, schedule s) {
    for (int j = 0; j < course_count; j++) {
        if (courses[j]->get_room() == r) {
            if (courses[j]->get_schedule().overlaps(s)) {
                return true;
            }
        }
    }
    return false;
}

bool scheduler::check_capacity(course* c, room* r) {
    return c->get_enrollment() <= r->get_capacity();
}

bool scheduler::assign_instructor_to_course(course* c, instructor* i) {
    if (i == nullptr or c == nullptr) return false;

    instructor* current = c->get_instructor();
    if (current != nullptr) {
        if (*i > *current) {
            remove_instructor_from_course(c);
        } else {
            return false;
        }
    }

    if (i->get_type() == "lecturer") {
        lecturer* l = (lecturer*)i;
        if (l->is_at_limit()) return false;
    }

    if (check_double_booking_instructor(i, c->get_schedule())) return false;

    c->assign_instructor(i);
    i->add_course();
    return true;
}

bool scheduler::assign_room_to_course(course* c, room* r) {
    if (r == nullptr or c == nullptr) return false;
    if (!check_capacity(c, r)) return false;
    if (check_double_booking_room(r, c->get_schedule())) return false;
    c->assign_room(r);
    return true;
}

bool scheduler::remove_instructor_from_course(course* c) {
    instructor* current = c->get_instructor();
    if (current == nullptr) return false;
    current->remove_course();
    c->assign_instructor(nullptr);
    return true;
}

bool scheduler::all_professors_meet_minimum() {
    for (int i = 0; i < instructor_count; i++) {
        if (instructors[i]->get_type() == "professor") {
            professor* p = (professor*)instructors[i];
            if (!p->meets_minimum()) return false;
        }
    }
    return true;
}

instructor** scheduler::get_underassigned_professors(int& count) {
    count = 0;
    for (int i = 0; i < instructor_count; i++) {
        if (instructors[i]->get_type() == "professor") {
            professor* p = (professor*)instructors[i];
            if (!p->meets_minimum()) count++;
        }
    }
    instructor** result = new instructor*[count];
    int index = 0;
    for (int i = 0; i < instructor_count; i++) {
        if (instructors[i]->get_type() == "professor") {
            professor* p = (professor*)instructors[i];
            if (!p->meets_minimum()) result[index++] = instructors[i];
        }
    }
    return result;
}