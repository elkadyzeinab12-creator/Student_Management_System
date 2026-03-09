# Student Management System 

* **Advanced UI:** Added full color support for terminal output using `colors.h` to improve user experience.
* **System Audit Logger:** Implemented a persistence layer that records all user activities in `system_tracker.log`.
* **Student Reports:** Added functionality to view and export student reports (Option 4 & 8).
* **Code Merging:** Successfully integrated and merged team contributions into the master branch.
* **Admin Access:** Use Option 3 in the main menu to view all system actions in real-time with special formatting.

**How to Run**
Follow these steps to ensure the project runs correctly with all its features:

**1. Using CLion (Recommended)**
Open the project folder in CLion.

Important: Go to Run > Edit Configurations and ensure the Working Directory is set to the project root folder. This is necessary for the program to find the database and log files.

Build and Run main.cpp.


**2. Manual Compilation (CLI)**
If you prefer the command line, use the following command:

Bash
g++ main.cpp student.cpp course.cpp Storage.cpp utils.cpp -o StudentSystem
./StudentSystem


** Project Structure**
main.cpp: The entry point and UI logic.

colors.h: Custom header for terminal color support.

Storage.cpp/h: Logic for file handling and data persistence.

cms_db.txt: The main database file.

system_tracker.log: The audit trail for all system activities.

 **Preview**
Note: For the best visual experience, please run the application in a terminal that supports ANSI colors (like VS Code Terminal or modern CMD).
