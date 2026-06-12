#include "include/scheduler.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    scheduler s(50, 50, 50);
    int option;

    cout << "=== University Scheduling System ===" << endl;

    while (true) {
        cout << "\n1. Add instructor" << endl;
        cout << "2. Add room" << endl;
        cout << "3. Add course" << endl;
        cout << "4. Assign instructor to course" << endl;
        cout << "5. Assign room to course" << endl;
        cout << "6. List courses" << endl;
        cout << "0. Exit" << endl;
        cout << "Option: ";
        cin >> option;
        cin.ignore();

        if (option == 0) {
            if (!s.all_professors_meet_minimum()) {
                int count;
                instructor** underassigned = s.get_underassigned_professors(count);
                cout << "\nCannot exit: the following professors have less than 2 courses assigned:" << endl;
                for (int i = 0; i < count; i++) {
                    cout << "- " << underassigned[i]->get_name()
                         << " (" << underassigned[i]->get_course_count() << "/2 courses)" << endl;
                }
                delete[] underassigned;
            } else {
                cout << "Goodbye!" << endl;
                break;
            }

        } else if (option == 1) {
            string name, payroll_id, department, type;
            cout << "Name: "; getline(cin, name);
            cout << "Payroll ID: "; getline(cin, payroll_id);
            cout << "Department: "; getline(cin, department);
            cout << "Type (professor/lecturer): "; getline(cin, type);
            instructor* i = s.add_instructor(name, payroll_id, department, type);
            if (i != nullptr) {
                cout << "Instructor added: " << i->get_name() << " (" << i->get_type() << ")" << endl;
            } else {
                cout << "Error: could not add instructor." << endl;
            }

        } else if (option == 2) {
            string building, room_number, type;
            int capacity, equipment_max = 0;
            cout << "Building: "; getline(cin, building);
            cout << "Room number: "; getline(cin, room_number);
            cout << "Capacity: "; cin >> capacity; cin.ignore();
            cout << "Type (classroom/laboratory): "; getline(cin, type);
            if (type == "laboratory") {
                cout << "Max equipment slots: "; cin >> equipment_max; cin.ignore();
            }
            room* r = s.add_room(building, room_number, capacity, type, equipment_max);
            if (r != nullptr) {
                cout << "Room added: " << r->get_room_number() << " (" << r->get_type() << ")" << endl;
            } else {
                cout << "Error: could not add room." << endl;
            }

        } else if (option == 3) {
            string course_code, course_name, department, day, start, end;
            int enrollment;
            cout << "Course code: "; getline(cin, course_code);
            cout << "Course name: "; getline(cin, course_name);
            cout << "Department: "; getline(cin, department);
            cout << "Enrollment: "; cin >> enrollment; cin.ignore();
            cout << "Day (e.g. Monday): "; getline(cin, day);
            cout << "Start time (e.g. 08:00): "; getline(cin, start);
            cout << "End time (e.g. 10:00): "; getline(cin, end);
            schedule sched(day, start, end);
            course* c = s.add_course(course_code, course_name, department, enrollment, sched);
            if (c != nullptr) {
                cout << "Course added: " << c->get_course_code() << " - " << c->get_course_name() << endl;
            } else {
                cout << "Error: could not add course." << endl;
            }

        } else if (option == 4) {
            string course_code, payroll_id;
            cout << "Course code: "; getline(cin, course_code);
            cout << "Instructor payroll ID: "; getline(cin, payroll_id);
            course* c = s.find_course(course_code);
            instructor* i = s.find_instructor(payroll_id);
            if (c == nullptr) { cout << "Course not found." << endl; }
            else if (i == nullptr) { cout << "Instructor not found." << endl; }
            else {
                if (s.assign_instructor_to_course(c, i)) {
                    cout << "Instructor assigned successfully." << endl;
                } else {
                    cout << "Error: could not assign instructor." << endl;
                }
            }

        } else if (option == 5) {
            string course_code, room_number;
            cout << "Course code: "; getline(cin, course_code);
            cout << "Room number: "; getline(cin, room_number);
            course* c = s.find_course(course_code);
            room* r = s.find_room(room_number);
            if (c == nullptr) { cout << "Course not found." << endl; }
            else if (r == nullptr) { cout << "Room not found." << endl; }
            else {
                if (s.assign_room_to_course(c, r)) {
                    cout << "Room assigned successfully." << endl;
                } else {
                    cout << "Error: could not assign room." << endl;
                }
            }

        } else if (option == 6) {
            s.list_courses();

        } else {
            cout << "Invalid option." << endl;
        }
    }

}