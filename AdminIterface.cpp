#include "AdminInterface.h"
#include "globals.h"
#include "Course.h"
#include <iostream>
using namespace std;

void AdminInterface::run()
{
    while (true)
    {
        cout << "\n=== Admin Menu ===\n"
             << "  List Departments [1]\n"
             << "  Add Department [2]\n"
             << "  Add Course to Department [3]\n"
             << "  Save Changes to CSV [4]\n"
             << "  Exit [5]\n";
        int choice = readChoice("Enter your choice [1, 2, 3, 4, 5]:", 1, 5);

        if (choice == 1) listDepartments();
        else if (choice == 2) addDepartment();
        else if (choice == 3) addCourseToDepartment();
        else if (choice == 4) saveChanges();
        else break;
    }
}

void AdminInterface::listDepartments()
{
    if (TotalDepartments == 0)
    {
        cout << "  (no departments yet)\n";
        return;
    }
    cout << "\nDepartments:\n";
    for (int i = 0; i < TotalDepartments; i++)
        cout << "  [" << (i + 1) << "] " << StoreDepartments[i].getName() << "\n";
}

void AdminInterface::addDepartment()
{
    string name = readNonEmpty("Enter department name:");
    addDepartmentToStore(name.c_str());
    cout << "Department added successfully.\n";
}

void AdminInterface::addCourseToDepartment()
{
    if (TotalDepartments == 0)
    {
        cout << "  (no departments yet - add one first)\n";
        return;
    }
    listDepartments();
    int deptNum = readChoice("Enter department number [0 to go back]:", 0, TotalDepartments);
    if (deptNum == 0) return;

    Department& dept = StoreDepartments[deptNum - 1];

    cout << "Courses currently in " << dept.getName() << ":\n";
    if (dept.getCourseCount() == 0) cout << "  (none yet)\n";
    for (int i = 0; i < dept.getCourseCount(); i++)
        cout << "  [" << (i + 1) << "] " << dept.getCourse(i).getName() << "\n";

    string number = readNonEmpty("Enter course number:");
    string cname = readNonEmpty("Enter course name:");
    string schedule = readSchedule("Enter course schedule (M/W, T/R, W/F):");
    double price = readPositivePrice("Enter course price:");

    dept.addCourse(Course(number, cname, schedule, price));
    cout << "Course added successfully.\n";
}

void AdminInterface::saveChanges()
{
    saveToCSV();
    cout << "Changes saved successfully.\n";
}
