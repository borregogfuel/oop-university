#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
using namespace std;

class room{
    private:
        string building;
        string room_number;
        int capacity;

    public:
        room(string building, string room_number, int capacity);
        string get_building();
        string get_room_number();
        int get_capacity();

        virtual string get_type() = 0;

        virtual ~room() = 0;
};

#endif