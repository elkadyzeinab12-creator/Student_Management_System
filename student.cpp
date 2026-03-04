#include <bits/stdc++.h>
#include "student.h"
#define GREEN "\033[32m"
#include "course.h"
#include "storage.h"

using namespace std;

void addStudent(vector<Student>& students) {

    Student new_Student;
    cout << "----------------------------<ADD NEW STUDENT>-------------------------------\n";

    cout << "Enter ID (14 digits): ";
    cin >> new_Student.id;

    bool validID = false;
    while (!validID){
        validID = true;
        if (new_Student.id.length() != 14){
            cout << "Error <ID must be 14 numbers!>\n";
            validID = false;
        }
        else {
            for (char c : new_Student.id){
                if (!isdigit(c)) {
                    cout << "Error <ID must contain numbers only!>\n";
                    validID = false;
                    break;
                }
            }
        }
        if (!validID){
            cout << "Enter a valid ID: ";
            cin >> new_Student.id;
        }
    }

    if (findStudentById(students, new_Student.id) != nullptr) {//if user give ID already exists
        cout << " Error: A student with ID ( " << new_Student.id << " ) already exists !";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Name: ";
    getline(cin, new_Student.name);

    cout << "Enter Academic Year: ";
    while (!(cin >> new_Student.year)) { // if the user give input other than numbers

        cout << "Invalid input ! \n"<<"Please , enter a number for Year: ";

        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter Number of Enrolled courses: " ;
    int numEnrolled;
    cin >> numEnrolled;
    for (int i = 0; i < numEnrolled; i++) {
        cout << "Enter Course code : ";
        string course_code;
        cin>> course_code ;
        new_Student.enrolledCourseIds.push_back(course_code);
    }

    students.push_back(new_Student);
    cout << "____________________________________________________________________________\n" ;
    cout <<GREEN<< "                       STUDENT REGISTERED SUCCESSFULLY                       "<<'\n' ;
    cout << "____________________________________________________________________________\n";
    cout << "  Name: " <<  new_Student.name <<  endl;
    cout << "  ID  : " << new_Student.id << endl;
    cout << "  Year: " << new_Student.year << endl;
    cout << "  Number of Enrolled courses: " << new_Student.enrolledCourseIds.size() << endl;
    for (int i = 0; i < new_Student.enrolledCourseIds.size(); i++)
        cout <<"  "<< i+1<<"-"<< new_Student.enrolledCourseIds[i] << endl;

    cout << "____________________________________________________________________________\n";

    activityLog("Added new student with ID:"+new_Student.id);
}


//------------------find student && tell user if he is not found----------------

Student* findStudentById(vector<Student>& students, const string& id) {
    for (auto& s : students)
        if (s.id == id)
            return &s;
    return nullptr;
}
//------------------------------Delete student -----------------------------------
void deleteStudent(vector<Student>& students, vector<Course>& courses) {
    string id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    Student* studentPtr = findStudentById(students, id);
    if (studentPtr != nullptr) {//delete grades with delete student
        for (auto& course : courses) {
            for (auto it = course.grades.begin(); it != course.grades.end(); ) {
                if (it->first == id) {
                    it = course.grades.erase(it);
                } else {
                    ++it;
                }
            }
        }
        cout << "Student and all their grades deleted successfully.\n" ;
        students.erase(students.begin() + (studentPtr - &students[0]));//to get index and do erase
        cout << "_____________________________________________________________________________\n";
        cout << "                       STUDENT DELETED SUCCESSFULLY                        \n";
        cout << "_____________________________________________________________________________\n";
        activityLog("Admin deleted student with ID: " + id);
    }else {
        cout << "Error: Student with ID ( " << id << " ) was not found!\n";

        activityLog("Admin faild to delete student with ID: " + id);
    }
}
//----------------------------------Edit student info-------------------------------
void editStudent(vector<Student>& students) {
    string id;
    cout << "Enter Student ID to edit: ";
    cin >> id;
    Student* sPtr = findStudentById(students, id);
    if (sPtr == nullptr) {
        cout << " Error: Student with ID ( " << id << " ) was not found!\n";
        return;
    }
    int choice;
    do {
        cout << "\n-----------------------< EDIT STUDENT DATA >------------------------\n";
        cout << "Current Data < Name: " << sPtr->name << " > < Year: " << sPtr->year << " >\n";
        cout << "----------------------------------------------------------------------\n";
        cout << "1. Edit Name\n";
        cout << "2. Edit Academic Year\n";
        cout << "3. Save & Exit\n";
        cout << "Enter your choice: ";
        while (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number (1-3): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (choice) {
            case 1:
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter New Name: ";
                getline(cin, sPtr->name);
                cout << "Name updated successfully!\n";
                break;
            case 2:
                cout << "Enter New Academic Year: ";
                while (!(cin >> sPtr->year)) {
                    cout << "Invalid! Please enter a number for Year: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Year updated successfully!\n";
                break;
            case 3:
                cout << "____________________________________________________________________\n";
                cout << "                       CHANGES SAVED SUCCESSFULLY                   \n";
                cout << "____________________________________________________________________\n";
                break;

            default:
                cout << "Invalid choice! Please select 1, 2 or 3\n";
        }
    } while (choice != 3);
    activityLog("Admin Edited student data");
}
//----------------------------------Calculate GPA-----------------------------------

