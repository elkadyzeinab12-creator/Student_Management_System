#include <bits/stdc++.h>
#include "student.h"
#include "course.h"
#include "utils.h"
#define GREEN "\033[32m"
#define red "\033[1;31m"
#define RESET   "\033[0m"
#define BLUE "\033[34m"

using namespace std;

void addCourse(vector<Course>& courses) {

    Course new_Course;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//clear any previous input or enter
    cout << BLUE << "----------------------------< ADD NEW COURSE >-------------------------------\n";
    cout << "Enter Course ID (Ex:CS101): ";
    getline(cin, new_Course.id);

    if (findCourseById(courses, new_Course.id) != nullptr) {
        cout << " Error: Course with code ( " << new_Course.id << " ) already exists!\n";
        return;
    }

    cout << "Enter Course Title: ";
    getline(cin, new_Course.title);

    cout << "Enter Credit Hours (1-4) : "<<RESET;
    while (!(cin >> new_Course.credit_hours) || new_Course.credit_hours <= 0 ||new_Course.credit_hours >4) {
        cout <<red << "Invalid input!\n"<<"Please , Enter valid Credit hours: "<<RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    courses.push_back(new_Course);
    cout <<GREEN<< "____________________________________________________________________________\n";
    cout << "                       COURSE ADDED SUCCESSFULLY                            \n";
    cout << "____________________________________________________________________________\n";
    cout << "  ID: " <<  new_Course.id <<  endl;
    cout << "  Title  : " << new_Course.title << endl;
    cout << "  Credit Hours: " << new_Course.credit_hours << endl;
    cout << "____________________________________________________________________________\n"<<RESET;
}
//-----------------find course && tell user if he is not found--------------------
Course* findCourseById(vector<Course>& courses, const string& id) {
    for (auto& c : courses) {
        if (c.id == id) {
            return &c;
        }
    }
    return nullptr;
}
//------------------------------Record Grade----------------------------------------
void recordGrade(vector<Course>& courses, vector<Student>& students) {
    string courseId = getStringInput("Enter Course ID to record grade: ");
    Course* coursePtr = findCourseById(courses, courseId);
    if (coursePtr == nullptr) {
        cout << red << "Error: Course not found!\n" << RESET;
        return;
    }
    string studentId = getStringInput("Enter Student ID : ");
    Student* studentPtr = findStudentById(students,studentId);
    if (studentPtr == nullptr) {
        cout << red << "Error: Student not found!\n" << RESET;
        return;
    }
    bool enrolled = false;
    for (const string& idcourse : studentPtr->enrolledCourseIds) {
        if (idcourse == courseId) {
            enrolled = true;
            break;
        }
    }
    if (!enrolled) {
        cout << "Error: Student is not enrolled in this course\n";
        return;
    }

    double grade = getDoubleInput("Enter Grade (0 to 100): ");
    if (grade < 0 || grade > 100) {
        cout <<red<< "Invalid grade < Please Enter Grade (0 to 100) >\n"<<RESET;
        return;
    }
    for (auto& gradePair : coursePtr->grades) {
        if (gradePair.first == studentId) {
            cout << "Old Grade: " << gradePair.second << endl;
            gradePair.second = grade; //if we update the grade
            cout <<GREEN<< "____________________________________________________________________\n";
            cout << "                       GRADE UPDATED SUCCESSFULLY                   \n";
            cout << "____________________________________________________________________\n";
            cout << " New Grade: " << gradePair.second << '\n' <<RESET;
            return;
        }
    }
    coursePtr->grades.push_back(make_pair(studentId, grade));
    cout <<GREEN<< "____________________________________________________________________\n";
    cout << "                       GRADE ADDED SUCCESSFULLY                   \n";
    cout << "____________________________________________________________________\n"<<RESET;

}
//------------------------------Print Course Report----------------------------------------
void printCourseReport(vector<Course>& courses, vector<Student>& students) {

}