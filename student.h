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
void viewAllStudents(std::vector<Student>& students,std::vector<Course>& courses);
Student* findStudentById(std::vector<Student>& students, const std::string& id);
double calculateGPA(const Student& s, const std::vector<Course>& allCourses);
double GpaCourse(double grade);
#endif
