#define _HAS_STD_BYTE 0
#include <bits/stdc++.h>
#include "student.h"
#include "course.h"
#include "storage.h"

#define GREEN "\033[32m"
#define cyan "\033[36m"
#define RESET   "\033[0m"

using namespace std;

//Save data base "Write"
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
            activityLog("new data was save");
        }

    }

//Load data base "Read"
void loadDatabase(std::vector<Student>& students,
                  std::vector<Course>& courses,
                  const std::string& filename) {
    fstream data_base;
    data_base.open("cms_db.txt", ios::in);//read
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

//Export Course Rport CSV
void exportCourseCSV(Course* course, std::vector<Student>& students) {

    string filename = course->id + ".csv";
     ofstream file(filename);
    if (!file)
        throw runtime_error("CSV report for course: " + course->id);
    if (file.is_open()) {
        file << "Course ID, " << course->id<<"\n";
        file << "Course Title, " << course->title<<"\n";
        file << "__________________________________________________________________________________\n";

        file << "Student ID, Student Name, Grade, Statue\n";

        for (int i = 0 ; i <course->grades.size(); i++) {
            for (int j=0;j<students.size();j++) {
                if (course->grades[i].first == students[j].id) {
                    double grade = course->grades[i].second;
                    string student_name = students[j].name;
                    string student_id = students[j].id;
                    string statue = (grade>=60 ?"pass" :"fail");
                    file <<"/"<< student_id << "/," << student_name << "," << grade <<","<<statue<<"\n";
                }
            }
        }
        file.close();
        activityLog("🔵Exported CSV report for course: " + course->id);
    }
}

//Timestamped Activity Logger
void activityLog(const string& message) {
    ofstream activityLog("system_tracker.log", ios::app);//appand "كنت بحاول اهرب منها طول الوقت"

    if (!activityLog)
        throw runtime_error("could not open file system tracker.log");
    if (activityLog.is_open()) {
        time_t now = time(nullptr);
        char* dt = ctime(&now);
        string timeStr(dt);
        timeStr.pop_back();
        activityLog <<cyan<< "[" << timeStr << "] " << message <<RESET<<endl;
        activityLog.close();
    }
}