#ifndef studenth
#define studenth

#include <string>
#include <vector>

struct Student {
    std::string id;
    std::string name;
    int year;
    std::vector<std::string> enrolledCourseIds;
};

void addStudent(std::vector<Student>& students);
Student* findStudentById(std::vector<Student>& students, const std::string& id);
void printStudentGPA(std::vector<Student>& students,
                     std::vector<class Course>& courses);

#endif
