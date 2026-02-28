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
