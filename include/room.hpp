#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
using namespace std;

class room{
    private:
        string building;
        int room_number;
        int capacity;

    public:
        string get_building();
        int get_room_number();
        int get_capacity();

        virtual string get_type() = 0;

        virtual ~room() = 0;
};

#endif