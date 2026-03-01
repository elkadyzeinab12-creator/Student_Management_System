#include <bits/stdc++.h>
#include "student.h"
#include "course.h"

using namespace std;

void addStudent(vector<Student>& students) {

    Student new_Student;

    cout << "----------------------------<ADD NEW STUDENT>-------------------------------\n";


    cout << "Enter ID: ";
    cin >> new_Student.id;

    while (new_Student.id.length() > 14) { //to ensure id doesn't exceed 14 char
        cout << "Error <ID must not exceed 14 characters !>\n";
        cout << "Enter a valid ID: ";
        cin >> new_Student.id;
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

    students.push_back(new_Student);
    cout << "____________________________________________________________________________\n" ;
    cout << "                       STUDENT REGISTERED SUCCESSFULLY                       "<<'\n' ;
    cout << "____________________________________________________________________________\n";
    cout << "  Name: " <<  new_Student.name <<  endl;
    cout << "  ID  : " << new_Student.id << endl;
    cout << "  Year: " << new_Student.year << endl;
    cout << "____________________________________________________________________________\n";
}

//------------------find student && tell user if he is not found----------------

Student* findStudentById(vector<Student>& students, const string& id) {
    for (auto& s : students)
        if (s.id == id)
            return &s;
    return nullptr;
}
//------------------------------Delete student -----------------------------------
void deleteStudent(vector<Student>& students) {
    string id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    Student* studentPtr = findStudentById(students, id);
    if (studentPtr != nullptr) {
        students.erase(students.begin() + (studentPtr - &students[0]));//to get index and do erase
        cout << "_____________________________________________________________________________\n";
        cout << "                       STUDENT DELETED SUCCESSFULLY                        \n";
        cout << "_____________________________________________________________________________\n";
    }else {
        cout << "Error: Student with ID ( " << id << " ) was not found!\n";
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
}
//---------------------------------Calculate GPA----------------------------------

