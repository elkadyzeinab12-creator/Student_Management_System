#define _HAS_STD_BYTE 0
#include <bits/stdc++.h>
#include "student.h"
#include "course.h"
#include "utils.h"
#include "storage.h"
#include "colors.h"
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;
#define ll long long

vector<Student> all_students ;
vector<Course> all_courses;

void main_menue() {
     cout<<BLUE<<"____________________________________________________________________________\n";
    cout <<"Welcome to our final project\n";
    cout<<"____________________________________________________________________________\n";
    cout<<"Main Menu:\n";
    cout<<"1. STUDENTS MANAGEMENT\n";
    cout<<"2. COURSES MANAGEMENT\n";
    cout<<"3. View Activity Log\n";
    cout<<"0. EXit and save \n"<<RESET;
}
//;///////////////////////////////////////////////////////////////////////////////////////////////
void studManag_menue() {
    cout<<YELLOW<<"____________________________________________________________________________\n";
    cout << "1. Add new student\n";//done
    cout << "2. Delete student\n";//done
    cout << "3. Find student \n";//done
    cout << "4. View Student Report (linear search)\n";//done
    cout << "5. View all students\n";//done
    cout << "6. Edit student data\n";//done
    cout << "7. Record student Grade\n";//done
    cout << "8. Export Student Report to CSV\n";//done
    cout << "9. Register student in course\n";
    cout << "0. Return to the main menu\n"<<RESET;
}
//;///////////////////////////////////////////////////////////////////////////////////////////////
void courseManag_menue() {
    cout<<BG<<"____________________________________________________________________________\n";
    cout << "1. Add new Course\n";//done
    cout << "2. Find Course\n";//done
    cout << "3. View Course Report\n";//done
    cout << "4. View all Courses\n";//done
    cout << "5. Edit Course data\n";//done
    cout << "6. Delete Course\n";//done
    cout << "7. Export Course Report to CSV\n";//done
    cout << "8. Find Course by id or title\n";
    cout << "0. Return to the main menu\n"<<RESET;
}
//;///////////////////////////////////////////////////////////////////////////////////////////////
void isStudentFound() {
    int choice = getIntInput("Enter 1 to get all students in CSV or 2 to get one student : ");
    if (choice == 1) {
        for (auto &c: all_students)
            exportStudentsCSV(&c, all_courses);
        cout << GREEN << "Students CSV Exported SUCCESSFULLY , you can find them in the directory\n" << RESET;
    } else if (choice == 2) {
        bool isstudFound = false;
        string id = getStringInput("Enter Student ID to Export CSV : ");
        for (auto &c: all_students) {
            if (c.id == id) {
                isstudFound = true;
                exportStudentsCSV(&c, all_courses);
                cout << GREEN << "Student CSV Exported SUCCESSFULLY , you can find it in the directory\n" << RESET;
                break;
            }
        }
        if (!isstudFound) cout << red << "Stud Not Found\n" << RESET;
    } else cout << red << "Invalid selection - Please input 1  or 2 \n";
}
//;//////////////////////////////////////////////////////////////////////////////////////////////
void isCourseFound() {
int choice=getIntInput("Enter 1 to get all courses in CSV or 2 to get one course : ");
    if (choice == 1) {

        for (auto& c : all_courses)
            exportCourseCSV(&c,all_students);
        cout<<GREEN<<"Courses CSV Exported SUCCESSFULLY , you can find them in the directory\n"<<RESET;
    }
    else if (choice == 2) {
         bool isCourseFound=false;
        string id=getStringInput("Enter Course ID to Export CSV : ");
        for (auto& c : all_courses) {
            if (c.id == id) {
                isCourseFound=true;
                exportCourseCSV(&c,all_students);
                 cout<<GREEN<<"Course CSV Exported SUCCESSFULLY , you can find it in the directory\n"<<RESET;
                break;
            }
        }
       if (!isCourseFound) cout<<red<<"Course Not Found\n"<<RESET;
    }
    else  cout<<red<<"Invalid selection - Please input 1  or 2 \n";
}
//;/////////////////////////////////////////////////////////////////////////////////////////////
void stud_loop() {
    int selection = -1;
    while (selection != 0) {
        studManag_menue();
        selection = getIntInput("Enter your selection : ");

        switch (selection) {
            case 1:
                //add student
                addStudent(all_courses, all_students);
                break;
            case 2:
                //delete student
                deleteStudent(all_students, all_courses);
                break;
            case 3: {
                //  search student by id
                Student *ptr = findStudentById(all_students, getStringInput("Enter Student ID: "));
                if (ptr != nullptr) {
                    cout << "Student Name: " << PURPLE << ptr->name << "\n" << RESET;
                } else {
                    cout << red << "Error: Student not found!\n" << RESET;
                }
            }
            break;
            case 4:
                //  view  student report
                findStud_by_id_or_name(all_students, all_courses);
            break;
            case 5:
                // view all students
                viewAllStudents(all_students, all_courses);
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
                //export student csv
                isStudentFound();
                break;
            case 9: {
                //Register student in course
                string Student_ID, Course_ID;
                 Student_ID=getStringInput("Enter Student ID: ");
                 Course_ID =getStringInput("Enter Course ID: ");
                Student* sPtr = findStudentById(all_students, Student_ID);
                Course* cPtr = findCourseById(all_courses, Course_ID);
                if (sPtr != nullptr && cPtr != nullptr) {
                    register_Student_in_course(sPtr, cPtr);
                }
                else {
                    if (sPtr == nullptr)
                        cout << red << "Error: Student ID (" << Student_ID << ") not found!" << RESET << '\n';
                    if (cPtr == nullptr)
                        cout << red << "Error: Course ID (" << Course_ID << ") not found!" << RESET << '\n';
                }
                break;
            }
            case 0:
                break;
            default:
                cout << red << "Invalid selection - Please input 1 to 8 only or press 0 to Exit!\n";
        }
    }
}

//;///////////////////////////////////////////////////////////////////////////////////////////////
void course_loop() {
     int selection=-1;
     while (selection != 0) {
         courseManag_menue();
         selection = getIntInput("Enter your selection : ");
         switch (selection) {
             case 1:
                 // add course
                 addCourse(all_courses);
                 break;
             case 2: {
                 // search course data
                 Course *ptr = findCourseById(all_courses, getStringInput("Enter course ID : "));
                 if (ptr != nullptr)
                     cout << "Course name : " << PURPLE << ptr->title << "\n" << RESET;

                 else cout << red << "Error: Course not found!\n" << RESET;
             }
             break;
             case 3:
                 printCourseReport(all_courses, all_students);
                 break;
             case 4:
                 //view all courses
                 viewAllCourses(all_courses);
                 break;
             case 5:
                 // Edit course data
                 editCourse(all_courses);
                 break;
             case 6:
                 //delete course
                 deleteCourse(all_courses, all_students);
                 break;
             case 7:
                 //export course csv
                 isCourseFound();
                 break;
             case 8:
                 findCourse_by_id_or_tit(all_students, all_courses);
                 break;
             case 0:
                 break;
             default:
                 cout << red << "Invalid selection - Please input 1 to 7 only or press 0 to Exit!\n";
         }
     }
}
//=========================================================================================================
void run_menuLoop() {
    int choice=-1;
    while (choice != 0) {
        main_menue();
        choice=getIntInput("Enter your choice : ");
        if (choice == 1){
            activityLog("Admin Entered STUDENTS MANAGEMENT");
            stud_loop();}

        else if (choice==2){
            activityLog("Admin Entered COURSES MANAGEMENT");
           course_loop();}
        else if (choice==3) {
            activityLog("Admin Viewed Activity Log");
            ViewActivityLog( "system_tracker.log");
        }

        else if (choice==0) cout<<"Exiting...\n";
        else   cout<<red<<"Invalid selection - Please input 1 to 3 only or press 0 to Exit!\n";
        }
    }
//;///////////////////////////////////////////////////////////////////////////////////////////////

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
