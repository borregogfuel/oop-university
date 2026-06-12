#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include <string>
using namespace std;

class instructor {
    private:
        string name;
        string payroll_id;
        string department;

    protected:
        int course_count;
    
    public:

        instructor(string name, string payroll_id, string department);

        string get_name();
        string get_payroll_id();
        string get_department();
        int get_course_count();
        bool operator<(const instructor& other);
        bool operator>(const instructor& other);
        bool operator==(const instructor& other);

        virtual int get_max_courses() = 0;
        virtual string get_type() const = 0;

        virtual ~instructor() = 0;

        void add_course();
        void remove_course();
        


};

#endif