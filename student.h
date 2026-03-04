#ifndef studenth
#define studenth
#include "course.h"
#include <string>
#include <vector>

struct Student {
    std::string id;
    std::string name;
    int year;
    std::vector<std::string> enrolledCourseIds;
};

void addStudent(std::vector<Student>& students);
void editStudent(std::vector<Student>& students);
void deleteStudent(std::vector<Student>& students,std:: vector<Course>& courses);
void viewAllStudents(std::vector<Student>& students);
Student* findStudentById(std::vector<Student>& students, const std::string& id);
void printStudentGPA(std::vector<Student>& students,
                     std::vector<class Course>& courses);

#endif
