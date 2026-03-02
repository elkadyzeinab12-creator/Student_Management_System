#include <bits/stdc++.h>
#include "student.h"
#include "course.h"
#include "utils.h"

using namespace std;

void addCourse(vector<Course>& courses) {

    Course new_Course;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//clear any previous input or enter
    cout << "----------------------------< ADD NEW COURSE >-------------------------------\n";
    cout << "Enter Course ID (Ex:CS101): ";
    getline(cin, new_Course.id);

    if (findCourseById(courses, new_Course.id) != nullptr) {
        cout << " Error: Course with code ( " << new_Course.id << " ) already exists!\n";
        return;
    }

    cout << "Enter Course Title: ";
    getline(cin, new_Course.title);

    cout << "Enter Credit Hours (1-4) : ";
    while (!(cin >> new_Course.credit_hours) || new_Course.credit_hours <= 0 ||new_Course.credit_hours >4) {
        cout << "Invalid input!\n"<<"Please , Enter valid Credit hours: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    courses.push_back(new_Course);
    cout << "____________________________________________________________________________\n";
    cout << "                       COURSE ADDED SUCCESSFULLY                            \n";
    cout << "____________________________________________________________________________\n";
    cout << "  ID: " <<  new_Course.id <<  endl;
    cout << "  Title  : " << new_Course.title << endl;
    cout << "  Credit Hours: " << new_Course.credit_hours << endl;
    cout << "____________________________________________________________________________\n";
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