#ifndef CLASSROOM_HPP
#define CLASSROOM_HPP

#include "room.hpp"

class classroom: public room {
    public:
        string get_type() override;
};

#endif