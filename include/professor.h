#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "instructor.h"


class professor : public instructor {
    public:
        professor(string name, string payroll_id, string department);
        int get_max_courses() override;
        string get_type() const override;
        bool meets_minimum();
};

#endif