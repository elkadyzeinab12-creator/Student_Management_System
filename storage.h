#ifndef storageh
#define storageh
#include <vector>
#include <string>
#include "student.h"
#include "course.h"

void saveDatabase(const std::vector<Student>& students,
                  const std::vector<Course>& courses,
                  const std::string& filename);

void loadDatabase(std::vector<Student>& students,
                  std::vector<Course>& courses,
                  const std::string& filename);
void exportCourseCSV(Course* course, std::vector<Student>& students);
void exportStudentsCSV(Student* student, std::vector<Course>& courses);
void activityLog(const std::string& message);
#endif