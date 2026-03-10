#include <bits/stdc++.h>
#include "student.h"
#include "course.h"
#include "utils.h"
#include "storage.h"
#include "colors.h"

using namespace std;

void addCourse(vector<Course>& courses) {

    Course new_Course;
    cout << BLUE << "----------------------------< ADD NEW COURSE >-------------------------------\n";
   new_Course.id=getStringInput("Enter Course ID (Ex:CS101): ");

    if (findCourseById(courses, new_Course.id) != nullptr) {
        cout << " Error: Course with code ( " << new_Course.id << " ) already exists!\n";
        return;
    }

    new_Course.title=getStringInput("Enter Course Title: ");

    cout << "Enter Credit Hours (1-4) : "<<RESET;
    new_Course.credit_hours = getIntInput("");

    while ( new_Course.credit_hours <= 0 ||new_Course.credit_hours >4) {
        new_Course.credit_hours = getIntInput(string(red) + "Invalid! Enter valid Credit hours (1-4): "  + RESET);
    }
    courses.push_back(new_Course);
    cout <<GREEN<< "____________________________________________________________________________\n";
    cout << "                       COURSE ADDED SUCCESSFULLY                            \n";
    cout << "____________________________________________________________________________\n";
    cout << "  ID: " <<  new_Course.id <<  endl;
    cout << "  Title  : " << new_Course.title << endl;
    cout << "  Credit Hours: " << new_Course.credit_hours << endl;
    cout << "____________________________________________________________________________\n"<<RESET;
    activityLog("Admin added course with ID: "+new_Course.id);

}
//-----------------find course && tell user if he is not found--------------------
Course* findCourseById(const vector<Course>& courses, const string& id) {
    for (auto& c : courses) {
        if (c.id == id) {
            return const_cast<Course*>(&c);
        }
    }
    return nullptr;
}
//------------------------------Record Grade----------------------------------------
void recordGrade(vector<Course>& courses, vector<Student>& students) {
    string courseId = getStringInput("Enter Course ID to record grade: ");
    Course* coursePtr = findCourseById(courses, courseId);
    if (coursePtr == nullptr) {
        cout << red << "Error: Course not found!\n" << RESET;
        return;
    }
    string studentId = getStringInput("Enter Student ID : ");
    Student* studentPtr = findStudentById(students,studentId);
    if (studentPtr == nullptr) {
        cout << red << "Error: Student not found!\n" << RESET;
        return;
    }
    bool enrolled = false;
    for (const string& idcourse : studentPtr->enrolledCourseIds) {
        if (idcourse == courseId) {
            enrolled = true;
            break;
        }
    }
    if (!enrolled) {
        cout <<red<< "Error: Student is not enrolled in this course\n"<<RESET;
        return;
    }

    double grade;
    while (true) {
        grade = getDoubleInput("Enter Grade (0 to 100): ");
        if (grade >= 0 && grade <= 100)
            break;
        cout << red << "Invalid grade! Please enter a value between 0 and 100.\n" << RESET;
    }
    for (auto& gradePair : coursePtr->grades) {
        if (gradePair.first == studentId) {
            cout << "Old Grade: " << gradePair.second << endl;
            gradePair.second = grade; //if we update the grade
            cout <<GREEN<< "____________________________________________________________________\n";
            cout << "                       GRADE UPDATED SUCCESSFULLY                   \n";
            cout << "____________________________________________________________________\n";
            cout << " New Grade: " << gradePair.second << '\n' <<RESET;
            return;
        }
    }
    coursePtr->grades.push_back(make_pair(studentId, grade));
    cout <<GREEN<< "____________________________________________________________________\n";
    cout << "                       GRADE ADDED SUCCESSFULLY                   \n";
    cout << "____________________________________________________________________\n"<<RESET;

    activityLog("new grade was recorded");
}
//------------------------------Print Course Report----------------------------------------
void printCourseReport(vector<Course>& courses, vector<Student>& students) {
    string id = getStringInput("Enter Course ID: ");
    Course* courseptr = findCourseById(courses, id);

    if (courseptr == nullptr) {
        cout << red << "Error: Course not found!\n" << RESET;
        return;
    }
    cout << "____________________________________________________________________\n";
    cout << "                          REPORT FOR COURSE                          \n";
    cout << "____________________________________________________________________\n";
    cout << "      <"<<courseptr->title << "  (" << courseptr->id << ") >         \n";
    if (courseptr->grades.empty()) {
        cout << red <<"No students have been graded for this course yet\n" <<RESET;
    } else {
        cout << "____________________________________________________________________\n";
        courseStatistics(courseptr);
    }
    cout << "____________________________________________________________________\n";
    activityLog("Admin Printed course report");

}
//-----------------------------------DELETE COURSE---------------------------------------
void deleteCourse(vector<Course>& courses, vector<Student>& students) {
    string id = getStringInput("Enter Course ID to delete: ");
    Course* coursePtr = findCourseById(courses, id);

    if (coursePtr != nullptr) {
        for (auto& student : students) {
            auto it = student.enrolledCourseIds.begin();
            while ( it != student.enrolledCourseIds.end() ) {//delete course from enrolled courses
                if (*it == id) {
                    it = student.enrolledCourseIds.erase(it);
                } else {
                    ++it;
                }
            }
        }
        courses.erase(courses.begin() + (coursePtr - &courses[0]));

        cout << GREEN << "____________________________________________________________________\n";
        cout << "            COURSE AND ALL ENROLLMENTS DELETED SUCCESSFULLY          \n";
        cout << "____________________________________________________________________\n" << RESET;
        activityLog("Admin Deleted course with ID: " + id);
    } else {
        cout << red << "Error: Course with ID ( " << id << " ) was not found!\n" << RESET;
        activityLog("Admin faild to delete Course with ID: " + id);
    }
}
//----------------------------------Edit Course info-------------------------------
void editCourse(vector<Course>& courses) {
    string id=getStringInput("Enter Course ID to edit: ");
    Course* cPtr = findCourseById(courses, id);
    if (cPtr == nullptr) {
        cout << red << " Error: Course with ID ( " << id << " ) was not found!\n" << RESET;
        return;
    }

    int choice;
    do {
        cout << "\n-----------------------< EDIT COURSE DATA >------------------------\n";
        cout << "Current Data < Title: " << cPtr->title << " > < Credits: " << cPtr->credit_hours << " >\n";
        cout << "----------------------------------------------------------------------\n";
        cout << "1. Edit Title\n";
        cout << "2. Edit Credit Hours\n";
        cout << "3. Save & Exit\n";
        cout << "Enter your choice: ";

        choice = getIntInput("Enter your choice: ");
        switch (choice) {
            case 1:

               cPtr->title =getStringInput("Enter New Title: ") ;
                cout <<GREEN<< "Title updated successfully!\n"<<RESET;
                break;

            case 2:
             cPtr->credit_hours =getIntInput("Enter New Credit Hours: ") ;
                while ( cPtr->credit_hours <= 0 ||cPtr->credit_hours >4) {
                    cPtr->credit_hours= getIntInput(string(red) + "Invalid! Enter valid Credit hours (1-4): "  + RESET);
                }
                cout << GREEN<<"Credit hours updated successfully!\n";
                break;

            case 3:
                cout << GREEN << "____________________________________________________________________\n";
                cout << "                       CHANGES SAVED SUCCESSFULLY                   \n";
                cout << "____________________________________________________________________\n" << RESET;
                break;

            default:
                cout <<red<< "Invalid choice! Please select 1, 2 or 3\n"<<RESET;
        }
    } while (choice != 3);
    activityLog("Admin Edited information of he Course with Id: "+id);

}
//----------------------------------View All Courses ----------------------------
void viewAllCourses(const vector<Course>& courses) {
    if (courses.empty()) {
        cout << YELLOW<<"\nNo courses registered in the system yet.\n"<<RESET ;
        return;
    }

    cout << "____________________________________________________________________\n";
    cout << "                           VIEW ALL COURSES                         \n";
    cout << "____________________________________________________________________\n";
    cout << left << setw(15) << "Course ID" << setw(30) << "Course Title" << "Credit Hours" << '\n';
    cout << "--------------------------------------------------------------------\n";

    for (const auto& c : courses) {
        cout << left << setw(15) << c.id << setw(30) << c.title << c.credit_hours << '\n';
    }

    cout << "--------------------------------------------------------------------\n";
    cout << " Total Number of Courses: " << courses.size() <<'\n';
    cout << "____________________________________________________________________\n";
    activityLog("Admin printed all courses <on console>");

}
//---------------------------------CourseStatistics---------------------------------
void courseStatistics(Course* courseptr) {
    if (courseptr == nullptr || courseptr->grades.empty()) {
        return;
    }
    vector<double> Grades;
    double sum = 0;

    for (const auto& grade : courseptr->grades) {
        Grades.push_back(grade.second);
        sum += grade.second;
    }
    double mxGrade = findMax(Grades);
    double mnGrade = findMin(Grades);
    double average = sum / Grades.size();
    cout << "Course Statistics:" << '\n';
    cout << "Highest Grade: " << mxGrade << '\n';
    cout << "Lowest Grade:  " << mnGrade << '\n';
    cout << "Average Grade: " << fixed << setprecision(2) << average << '\n';

}
//;///////////////////////////////////////////////////////////////////////////////////
void findCourse_by_id_or_tit(vector<Student>& allStudents, vector<Course>& allCourses) {
    char search='k';
    while (search!='0') {
        bool ok=false;
        search=getCharInput("press # to search Course by ID , * by Title , or 0 to Exit : ");
        if (search=='#'){
            string id = getStringInput("Enter Course ID : ");
            for (auto &c: allCourses) {
                if (c.id == id) {
                    ok=true;
                    Course* courseptr = findCourseById(allCourses, id);
                    cout << "____________________________________________________________________\n";
                    cout << "                          REPORT FOR COURSE                          \n";
                    cout << "____________________________________________________________________\n";
                    cout << "      <"<<courseptr->title << "  (" << courseptr->id << ") >         \n";
                    if (courseptr->grades.empty()) {
                        cout << red <<"No students have been graded for this course yet\n" <<RESET;
                    } else {
                        cout << "____________________________________________________________________\n";
                        courseStatistics(courseptr);
                    }
                    cout << "____________________________________________________________________\n";
                    search = '0';
                    break;
                }
            }
            if (!ok){ cout <<red<< "Course ID does not exists\n"<<RESET;
                break; }

        }
        else if (search=='*') {
            cout << "Enter Course Title : ";
            string Name;
            getline(cin >> ws, Name);
            for (auto &c: allCourses) {
                if (c.title == Name) {
                    ok=true;
                    Course* courseptr = findCourseById(allCourses,c.id);
                    cout << "____________________________________________________________________\n";
                    cout << "                          REPORT FOR COURSE                          \n";
                    cout << "____________________________________________________________________\n";
                    cout << "      <"<<courseptr->title << "  (" << courseptr->id << ") >         \n";
                    if (courseptr->grades.empty()) {
                        cout << red <<"No students have been graded for this course yet\n" <<RESET;
                    } else {
                        cout << "____________________________________________________________________\n";
                        courseStatistics(courseptr);
                    }
                    cout << "____________________________________________________________________\n";
                    search = '0';
                    break;
                }
            }
            if (!ok) {cout <<red<< "Course Title does not exists\n"<<RESET;
                break; }
        }
        else cout <<red<<"invalid input!\n"<<RESET;
        if (search != '0') {
            // cin.clear();
            // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
//-----------------------------------finish :)-----------------------------------------