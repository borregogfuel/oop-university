#ifndef COURSE_H
#define COURSE_H

#include<iostream>
#include<optional>
#include "instructor.h"
#include "room.h"
#include "schedule.h"


using namespace std;


class course {

    private:
        string course_code;
        string course_name;
        string department;
        int enrollment;
        schedule sched;
        optional<instructor*> instructor_ref;
        optional<room*> room_ref;

    public:
        course(string course_code, string course_name, string department, int enrollment, schedule sched);
        string get_course_code();
        string get_course_name();
        string get_department();
        int get_enrollment();
        schedule get_schedule();
        instructor* get_instructor();
        room* get_room();
        bool assign_instructor(instructor* i);
        bool assign_room(room* r);

};

#endif