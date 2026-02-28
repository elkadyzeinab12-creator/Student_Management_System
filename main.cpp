#include <bits/stdc++.h>
#include "student.h"
#include "course.h"

using namespace std;
#define ll long long

vector<Student> all_students ;
vector<Course> all_courses;

void menu_loop () {
    cout<<"____________________________________________________________________________\n";
    cout <<"                        Welcome to our final project                       \n";
    cout<<"____________________________________________________________________________\n";
    cout<<"Main Menu:\n";
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

        int students_number;
        data_base>>students_number;

        for ( int i = 0 ; i < students_number; i++ ) {
            Student student;

            data_base>>student.id;
            data_base.ignore();
          getline(data_base,student.name)  ;
            data_base>>student.year;

               int number_of_courses;
            data_base>>number_of_courses;
            for (int j = 0; j < number_of_courses; j++) {
                string course;
                data_base>>course;
                // add vec for student
                student.enrolledCourseIds.push_back(course);
            }
            all_students.push_back(student);
        }

        int numof_courses;
        data_base>>numof_courses;
        for (int i = 0; i < numof_courses; i++) {
            Course course_code;
            data_base>>course_code.title;
            data_base>>course_code.credit_hours;
            int number_of_gpa;
            data_base>>number_of_gpa;
            for (int j = 0; j < number_of_gpa; j++) {
                string student_id;
                double student_gpa;
                data_base>>student_id>>student_gpa;
                course_code.grades.push_back({student_id, student_gpa});
            }
            all_courses.push_back(course_code);
        }
    data_base.close();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    menu_loop();

}