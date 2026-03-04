#define _HAS_STD_BYTE 0
#include <bits/stdc++.h>
#include "student.h"
#include "course.h"
#include "utils.h"
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
    cout<<BLUE<<"____________________________________________________________________________\n";
    cout <<"Welcome to our final project\n";
    cout<<"____________________________________________________________________________\n";
    cout<<"Main Menu:\n";
    cout << "1. Add new student\n";//done
    cout << "2. Delete student\n";//done
    cout << "3. Find student \n";//done
    cout << "4. View Student Report\n";
    cout << "5. View all students\n";
    cout << "6. Edit student data\n";//done
    cout << "7. Record student in a course\n";//done
    cout << "8. Add new Course\n";//done
    cout << "9.  Find Course\n";//done
    cout << "10. View Course Report\n";//done
    cout << "11. View all Courses\n";
    cout << "12. Edit Course data\n";
    cout << "13. delete course\n";
    cout << "14. Export Course Report to CSV\n";//done "still avrage, highst and lowest grade and student number"
    cout << "15. Export Student Report to CSV\n";
    cout << "0. Exit\n"<<RESET;
    cout << "Enter your choice : ";
    }

void isCourseFound() {
    for (auto& c : all_courses) {
       exportCourseCSV(&c,all_students);
        }
}

void run_menuLoop() {
    ll choice=-1;
    while (choice != 0) {
        menu_loop();
        cin>>choice;
        switch (choice) {
            case 1:
                //add student
                addStudent(all_students);
               break;
            case 2:
                //delete tudent
                deleteStudent(all_students, all_courses);
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
              //  view  student report

              break;
            case 5:
                // view all students

                break;
            case 6:
                //edit student data
                editStudent(all_students);
                break;
            case 7:
                //record student to course
                 recordGrade(all_courses, all_students);
                break;
            case 8:
                // add course
                addCourse(all_courses);
                break;
            case 9: {
                // search course data
                Course* ptr = findCourseById(all_courses,getStringInput("Enter course ID : "));
                if (ptr != nullptr)
                    cout<<"Course name : "<<PURPLE<< ptr->title<< "\n"<<RESET;

                else  cout <<red<< "Error: Course not found!\n"<<RESET;
            }
                break;
            case 10:
                printCourseReport(all_courses, all_students);
                break;
            case 11:
                //view all courses
                break;
            case 12:
                // Edit course data
                break;
            case 13:
                //delete course
            case 14:
                //export course csv
                isCourseFound();
                break;
            case 15:
                //export student csv

            case 0: cout << "Exiting...\n";
                break;
            default:
                cout<<red<<"Invalid selection - Please input 1 to 10 only or press 0 to Exit!\n";
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