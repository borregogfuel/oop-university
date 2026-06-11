#ifndef LECTURER_HPP
#define LECTURER_HPP

#include "instructor.h"

class lecturer : public instructor {
    public:
        lecturer(string name, string payroll_id, string department);
        int get_max_courses() override;
        string get_type() override;
        bool is_at_limit();
};

#endif