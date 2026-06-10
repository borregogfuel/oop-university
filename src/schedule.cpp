#include "../include/schedule.hpp"

string schedule::get_day(){
    return day_of_week;
}

string schedule::get_start(){
    return start_time;
}

string schedule::get_end(){
    return end_time;
}

bool schedule::overlaps(schedule s){
    if(day_of_week == s.day_of_week && start_time < s.end_time && s.start_time < end_time){
        return true;
    }
    return false;
}