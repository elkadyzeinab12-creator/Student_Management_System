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
        saveDatabase.open("G:/ICPC/project/cms_db.txt", ios::out);//write

        if (!saveDatabase)
            throw runtime_error("Ccould not open file for saving new data");

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