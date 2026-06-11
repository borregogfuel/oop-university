#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "instructor.hpp"


class professor : public instructor {
    public:
        int get_max_courses() override;
        string get_type() override;
        bool meets_minimum();
};

#endif