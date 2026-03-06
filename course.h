#ifndef courseh
#define courseh

#include <string>
#include <vector>
#include <utility>

struct Course {
    std::string id;
    std::string title;
    int credit_hours;
    std::vector<std::pair<std::string, double>> grades;
};

void addCourse(std::vector<Course>& courses);
Course* findCourseById(const std::vector<Course>& courses, const std::string& id);
void recordGrade(std::vector<Course>& courses,
                 std::vector<class Student>& students);
void printCourseReport(std::vector<Course>& courses,
                       std::vector<class Student>& students);
void viewAllCourses(const std::vector<Course>& courses);
void editCourse(std::vector<Course>& courses);
void courseStatistics(Course* courseptr);
#endif
