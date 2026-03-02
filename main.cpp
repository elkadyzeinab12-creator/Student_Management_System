#define _HAS_STD_BYTE 0
#include <bits/stdc++.h>
#include "student.h"
#include "course.h"
#include "utils.h"
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
#define PURPLE "\033[35m"
#define LIGHT_PURPLE "\033[1;35m"
#define cyan "\033[36m"

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
    cout << "6. Add new Course\n";
    cout << "7. View Course data\n";
    cout << "0. Exit\n"<<RESET;
    cout << "Enter your choice : ";
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
                //  search student by id
                Student* ptr = findStudentById(all_students, getStringInput("Enter Student ID: "));
                if (ptr != nullptr) {
                    cout << "Student Name: " <<PURPLE<< ptr->name << "\n"<<RESET;
                } else {
                    cout <<red<< "Error: Student not found!\n"<<RESET;
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
            case 6:
                // add course
                addCourse(all_courses);
                break;
            case 7: {
                // search course data
                Course* ptr = findCourseById(all_courses,getStringInput("Enter course ID : "));
                if (ptr != nullptr)
                    cout<<"Course name : "<<PURPLE<< ptr->title<< "\n"<<RESET;

                else  cout <<red<< "Error: Course not found!\n"<<RESET;
            }
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
        loadDatabase(all_students,all_courses,"cms_db.txt");
        run_menuLoop();
        saveDatabase(all_students,all_courses,"cms_db.txt");
    }
     catch (const exception& e) {
                cerr <<red<< "Caught an exception : " << e.what() << endl;
         cerr<<RESET;
     }
return 0;
}