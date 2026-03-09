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

void addStudent(std::vector<Course>& courses,std::vector<Student>& students);
void editStudent(std::vector<Student>& students);
void deleteStudent(std::vector<Student>& students,std:: vector<Course>& courses);
void viewAllStudents(std::vector<Student>& students,std::vector<Course>& courses);
void printStudentReport(const Student& s, const std:: vector<Course>& allCourses);
Student* findStudentById(std::vector<Student>& students, const std::string& id);
double calculateGPA(const Student& s, const std::vector<Course>& allCourses);
double GpaCourse(double grade);
void findStud_by_id_or_name( std::vector<Student>& allStudents, std::vector<Course>& allCourses);

#endif
