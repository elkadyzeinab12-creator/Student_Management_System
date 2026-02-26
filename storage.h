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
#endif