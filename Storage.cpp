#define _HAS_STD_BYTE 0
#include <bits/stdc++.h>
#include "student.h"
#define GREEN "\033[32m"
#include "course.h"
#include "storage.h"
using namespace std;


void saveDatabase(const std::vector<Student>& students,
                  const std::vector<Course>& courses,
                  const std::string& filename){

        fstream saveDatabase;
        saveDatabase.open("cms_db.txt", ios::out);//write

        if (!saveDatabase)
            throw runtime_error("Could not open file for saving new data");

        if (saveDatabase.is_open()) {

            saveDatabase << students.size() << endl;

            for ( int i = 0 ; i <students.size(); i++ ) {

                saveDatabase<<students[i].id<<endl;
                saveDatabase<<students[i].name<<endl ;
                saveDatabase<<students[i].year<<endl;

                saveDatabase<<students[i].enrolledCourseIds.size()<<endl;
                for (int j = 0; j < students[i].enrolledCourseIds.size(); j++) {
                    saveDatabase<<students[i].enrolledCourseIds[j]<<endl;
                }
            }

            saveDatabase<<courses.size()<<endl;
            for (int i = 0; i < courses.size(); i++) {
                saveDatabase<<courses[i].id<<endl;
                saveDatabase<<courses[i].title<<endl;
                saveDatabase<<courses[i].credit_hours<<endl;
                saveDatabase<<(int)courses[i].grades.size()<<endl;

                for (int j = 0; j <courses[i].grades.size() ; j++) {
                    saveDatabase<<courses[i].grades[j].first<<" "<<courses[i].grades[j].second<<endl;
                }

            }
            saveDatabase.close();
            cout<<GREEN<<"New data saved SUCCESSFULLY\n";
        }

    }

//Load data base
void loadDatabase(std::vector<Student>& students,
                  std::vector<Course>& courses,
                  const std::string& filename) {
    fstream data_base;
    data_base.open("cms_db.txt", ios::in);
    if (!data_base)
        throw runtime_error("File not found!");

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
            students.push_back(student);
        }
        int numof_courses;
        data_base>>numof_courses;
        // data_base.ignore();
        for (int j = 0; j < numof_courses; j++) {
            data_base >> ws;
            Course course_code;
            getline(data_base,course_code.id);
            getline(data_base,course_code.title);
            data_base>>course_code.credit_hours;
            int number_of_gpa;
            data_base>>number_of_gpa;
            for (int k = 0; k < number_of_gpa; k++) {
                string student_id;
                double student_gpa;
                data_base>>student_id>>student_gpa;
                course_code.grades.push_back({student_id , student_gpa});
            }
            // data_base.ignore();
           courses.push_back(course_code);
        }
        data_base.close();
    }

}
