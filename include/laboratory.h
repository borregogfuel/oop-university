#ifndef LABORATORY_HPP
#define LABORATORY_HPP

#include "room.h"

class laboratory : public room {
    private:
        string* equipment;
        int equipment_count;
        int equipment_max;

    public:
        laboratory(string building, string room_number, int capacity, int equipment_max);
        string get_type() override;
        string* get_equipment();
        int get_equipment_count();

        void add_equipment(string name);
};

#endif

