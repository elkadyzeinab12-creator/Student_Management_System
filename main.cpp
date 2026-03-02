#define _HAS_STD_BYTE 0
#include <bits/stdc++.h>
#include "student.h"
#include "course.h"
#include <ranges>
#include "storage.h"
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;
#define ll long long
#define red "\033[1;31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RESET   "\033[0m"

vector<Student> all_students ;
vector<Course> all_courses;

void menu_loop () {
    cout <<BLUE<<"Welcome to our final project\n";
    cout<<"____________________________________________________________________________\n";
    cout<<"Main Menu:\n";
    cout << "1. Add new student\n";
    cout << "2. Delete student\n";
    cout << "3. View student\n";
    cout << "4. View all students\n";
    cout << "5. Edit student data\n";
    cout << "0. Exit\n"<<RESET;
    cout << "Enter your choice : ";
    }

void data_base() {
    fstream data_base;
    data_base.open("cms_db.txt", ios::in);
     if (!data_base)
        throw runtime_error("File not found!");

    if (data_base.is_open()) {

        int students_number;
        data_base>>students_number;

        for ( int i = 0 ; i < students_number; i++ ) {
            Student student;

            data_base>>student.id;
            data_base.ignore();
          getline(data_base,student.name)  ;
            data_base>>student.year;

               int number_of_courses;
            data_base>>number_of_courses;
            for (int j = 0; j < number_of_courses; j++) {
                string course;
                data_base>>course;
                // add vec for student
                student.enrolledCourseIds.push_back(course);
            }
            all_students.push_back(student);
        }
        int numof_courses;
        data_base>>numof_courses;
        // data_base.ignore();
        for (int j = 0; j < numof_courses; j++) {
            data_base >> ws;
            Course course_code;
            getline(data_base,course_code.id);
            getline(data_base,course_code.title);
            data_base>>course_code.credit_hours;
            int number_of_gpa;
            data_base>>number_of_gpa;
            for (int k = 0; k < number_of_gpa; k++) {
                string student_id;
                double student_gpa;
                data_base>>student_id>>student_gpa;
                course_code.grades.push_back({student_id , student_gpa});
            }
            // data_base.ignore();
            all_courses.push_back(course_code);
        }
    data_base.close();
    }

}

void run_menuLoop() {
    ll choice=-1;
    while (choice != 0) {
        menu_loop();
        cin>>choice;
        switch (choice) {
            case 1:
                //add
                addStudent(all_students);
               break;
            case 2:
                //delete
                deleteStudent(all_students);
                break;
            case 3: {
                // or search by id
                cout<<"Enter ID: ";
                string ID;
                cin>>ID;
                Student* ptr = findStudentById(all_students, ID);
                if (ptr != nullptr) {
                    cout << "Student Name: " << ptr->name << "\n";
                } else {
                    cout << "Error: Student not found!\n";
                }
            }
                break;
            case 4:
              //  view all students

              break;
            case 5:
                //edit student data
                editStudent(all_students);
                break;
            case 0: cout << "Exiting...\n";
                break;
            default:
                cout<<red<<"Invalid selection - Please input 1 to 4 only or press 0 to Exit!\n";
        }
    }

}

int main() {

#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
#endif


    try {
        data_base();
        run_menuLoop();
        saveDatabase(all_students,all_courses,"cms_db.txt");
    }
     catch (const exception& e) {
                cerr <<red<< "Caught an exception : " << e.what() << endl;
         cerr<<RESET;
     }
return 0;
}