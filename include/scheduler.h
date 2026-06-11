#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <iostream>
#include "course.h"
#include "professor.h"
#include "lecturer.h"
#include "instructor.h"
#include "classroom.h"
#include "laboratory.h"

using namespace std;

class scheduler {
    private:
        instructor** instructors;
        int instructor_count;
        int instructor_max;

        room** rooms;
        int room_count;
        int room_max;

        course** courses;
        int course_count;
        int course_max;

    public:
        scheduler(int instructor_max, int room_max, int course_max);
        ~scheduler();

        instructor* add_instructor(string name, string payroll_id, string department, string type);
        room* add_room(string building, string room_number, int capacity, string type, int equipment_max = 0);
        course* add_course(string course_code, string course_name, string department, int enrollment, schedule sched);

        bool assign_instructor_to_course(course* c, instructor* i);
        bool assign_room_to_course(course* c, room* r);
        bool remove_instructor_from_course(course* c);

        bool check_double_booking_instructor(instructor* i, schedule s);
        bool check_double_booking_room(room* r, schedule s);
        bool check_capacity(course* c, room* r);

        bool all_professors_meet_minimum();
        instructor** get_underassigned_professors(int& count);

        course* find_course(string course_code);
        instructor* find_instructor(string payroll_id);
        room* find_room(string room_number);
        void list_courses();
};

#endif