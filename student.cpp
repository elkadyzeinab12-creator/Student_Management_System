#include <bits/stdc++.h>
#include "student.h"
#include "colors.h"
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
            cout << red<<"Error <ID must be 14 numbers!>\n"<<RESET;
            validID = false;
        }
        else {
            for (char c : new_Student.id){
                if (!isdigit(c)) {
                    cout <<red<< "Error <ID must contain numbers only!>\n"<<RESET;
                    validID = false;
                    break;
                }
            }
        }
        if (!validID){
            cout <<red<< "Enter a valid ID: "<<RESET;
            cin >> new_Student.id;
        }
    }

    if (findStudentById(students, new_Student.id) != nullptr) {//if user give ID already exists
        cout <<red<< " Error: A student with ID ( " << new_Student.id << " ) already exists !"<<RESET;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Name: ";
    getline(cin, new_Student.name);

    cout << "Enter Academic Year: ";
    while (!(cin >> new_Student.year)) { // if the user give input other than numbers

        cout <<red<< "Invalid input ! \n"<<"Please , enter a number for Year: "<<RESET;

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
    cout <<GREEN<< "                       STUDENT REGISTERED SUCCESSFULLY                       "<<'\n'<<RESET ;
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
        cout <<GREEN<< "Student and all their grades deleted successfully.\n"<<RESET ;
        students.erase(students.begin() + (studentPtr - &students[0]));//to get index and do erase
        cout << "_____________________________________________________________________________\n";
        cout <<GREEN<< "                       STUDENT DELETED SUCCESSFULLY                    \n"<<RESET;
        cout << "_____________________________________________________________________________\n";
        activityLog("Admin deleted student with ID: " + id);
    }else {
        cout << red<<"Error: Student with ID ( " << id << " ) was not found!\n"<<RESET;

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
        cout <<red<< " Error: Student with ID ( " << id << " ) was not found!\n"<<RESET;
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
            cout <<red<< "Invalid input! Please enter a number (1-3): "<<RESET;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (choice) {
            case 1:
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter New Name: ";
                getline(cin, sPtr->name);
                cout <<GREEN<< "Name updated successfully!\n"<<GREEN;
                break;
            case 2:
                cout << "Enter New Academic Year: ";
                while (!(cin >> sPtr->year)) {
                    cout << red<<"Invalid! Please enter a number for Year: "<<RESET;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout <<GREEN<< "Year updated successfully!\n"<<RESET;
                break;
            case 3:
                cout << GREEN<<"____________________________________________________________________\n";
                cout << "                       CHANGES SAVED SUCCESSFULLY                   \n";
                cout << "____________________________________________________________________\n"<<RESET;
                break;

            default:
                cout <<red<< "Invalid choice! Please select 1, 2 or 3\n"<<GREEN;
        }
    } while (choice != 3);
    activityLog("Admin Edited student data");
}
//----------------------------------Calculate GPA-----------------------------------
double GpaCourse(double grade) {//calculate takdeer el madaa
    if (grade >= 90) return 4.0;
    if (grade >= 85) return  3.6;
    if (grade >= 80) return  3.3;
    if (grade >= 75) return  3.0;
    if (grade >= 70) return  2.6;
    if (grade >= 65) return  2.4;
    if (grade >= 60) return  2.2;
    if (grade >= 50) return  2;
    return 0;
}
//;/////////////////////////////////////////////////////////////////////////////////////////////
double calculateGPA(const Student& s, const vector<Course>& allCourses) {//can return value to be used in another situations
    double totalpoints = 0;
    int totalhours = 0;
    for (const auto& course : allCourses) {

        for (const auto& grade : course.grades) {
            if (grade.first == s.id) {
                totalpoints += GpaCourse(grade.second) * course.credit_hours;
                totalhours += course.credit_hours;
                break;
            }
        }
    }
    if (totalhours == 0) return 0;
    return totalpoints / totalhours;
}
//-----------------------------------finish :)-----------------------------------------
