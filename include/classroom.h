#ifndef CLASSROOM_HPP
#define CLASSROOM_HPP

#include "room.h"

class classroom: public room {
    public:
        classroom(string building, string room_number, int capacity);
        string get_type() override;
};

#endif