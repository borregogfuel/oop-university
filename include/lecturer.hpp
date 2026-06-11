#ifndef LECTURER_HPP
#define LECTURER_HPP

#include "instructor.hpp"

class lecturer : public instructor {
    public:
        int get_max_courses() override;
        string get_type() override;
        bool is_at_limit();
};

#endif