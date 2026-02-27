#include <bits/stdc++.h>
using namespace std;
#define ll long long



void menu_loop () {
    cout <<"Welcome to our final project\n";
    cout<<"____________________________________________________________________________\n";
    cout << "1. Add new student\n";
    cout << "2. Delete student\n";
    cout << "3. View student\n";
    cout << "4. View all students\n";
    cout << "0. Exit\n";
    cout << "Enter your choice : ";
    }

void data_base() {
    fstream data_base;
    data_base.open("G:/ICPC/project/cms_db.txt", ios::in);

    if (data_base.is_open()) {

        string students_number;
        data_base>>students_number;
        for ( int i = 0 ; i < students_number.length(); i++ ) {
            string id,name,course;
            int lvl,number_of_courses;

            data_base>>id;
            data_base>>name;
            data_base>>lvl;
            data_base>>number_of_courses;

            for (int j = 0; j < number_of_courses; j++) {
                data_base>>course;

            }

        }

    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    menu_loop();



}