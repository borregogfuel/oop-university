#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP

#include <string>
using namespace std;

class schedule {
    private:
        string day_of_week;
        string start_time;
        string end_time;

    public:
        schedule(string day_of_week, string start_time, string end_time);
        string get_day();
        string get_start();
        string get_end();
        bool overlaps(schedule s);


};

#endif


