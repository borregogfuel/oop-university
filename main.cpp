#include <iostream>
#include "include/schedule.hpp"
#include "include/professor.hpp"
#include "include/lecturer.hpp"
#include "include/classroom.hpp"
#include "include/laboratory.hpp"

using namespace std;

int main() {
    // prueba schedule
    schedule s1, s2;
    cout << "=== Schedule ===" << endl;

    // prueba professor
    professor p;
    cout << "=== Professor ===" << endl;
    cout << "Type: " << p.get_type() << endl;
    cout << "Max courses: " << p.get_max_courses() << endl;
    cout << "Meets minimum: " << p.meets_minimum() << endl;

    // prueba lecturer
    lecturer l;
    cout << "=== Lecturer ===" << endl;
    cout << "Type: " << l.get_type() << endl;
    cout << "Max courses: " << l.get_max_courses() << endl;
    cout << "Is at limit: " << l.is_at_limit() << endl;

    // prueba classroom
    classroom c;
    cout << "=== Classroom ===" << endl;
    cout << "Type: " << c.get_type() << endl;

    // prueba laboratory
    laboratory lab;
    cout << "=== Laboratory ===" << endl;
    cout << "Type: " << lab.get_type() << endl;

    return 0;
}