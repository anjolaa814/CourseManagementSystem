#include "StudentInterface.h"
#include "globals.h"
#include "Course.h"
#include <iostream>
using namespace std;

void StudentInterface::run()
{
    while (true)
    {
        cout << "\n=== Student Menu ===\n"
             << "  Show Cart [1]\n"
             << "  Browse Departments [2]\n"
             << "  Exit [3]\n";
        int choice = readChoice("Enter your choice [1, 2, 3]:", 1, 3);

        if (choice == 1) showCartMenu();
        else if (choice == 2) browseDepartments();
        else break;
    }
}

void StudentInterface::showCartMenu()
{
    while (true)
    {
        cout << "\n=== Cart ===\n"
             << "  List Courses [1]\n"
             << "  Checkout [2]\n"
             << "  Return to Main Menu [3]\n";
        int choice = readChoice("Enter your choice [1, 2, 3]:", 1, 3);

        if (choice == 1)
        {
            if (cart.isEmpty()) cout << "  (cart is empty)\n";
            else cart.listCourses();
        }
        else if (choice == 2)
        {
            if (!cart.isEmpty())
            {
                cout << "Thank you for your purchase.\n";
                cart.clear();
                return;
            }
            else
            {
                cout << "No courses in the cart.\n";
            }
        }
        else
        {
            return;
        }
    }
}

void StudentInterface::browseDepartments()
{
    while (true)
    {
        if (TotalDepartments == 0)
        {
            cout << "  (no departments yet)\n";
            return;
        }
        cout << "\nDepartments:\n";
        for (int i = 0; i < TotalDepartments; i++)
            cout << "  [" << (i + 1) << "] " << StoreDepartments[i].getName() << "\n";

        cout << "  List Courses of a Department [1]\n"
             << "  Go Back to Main Menu [2]\n";
        int choice = readChoice("Enter your choice [1, 2]:", 1, 2);
        if (choice == 2) return;

        int deptNum = readChoice("Enter department number [0 to go back]:", 0, TotalDepartments);
        if (deptNum == 0) continue;
        listDepartmentCourses(deptNum - 1);
    }
}

void StudentInterface::listDepartmentCourses(int index)
{
    Department& dept = StoreDepartments[index];
    while (true)
    {
        cout << "\nCourses in " << dept.getName() << ":\n";
        if (dept.getCourseCount() == 0) cout << "  (no courses yet)\n";
        for (int i = 0; i < dept.getCourseCount(); i++)
        {
            Course c = dept.getCourse(i);
            cout << "  [" << (i + 1) << "] " << c.getNumber() << " - " << c.getName()
                 << " | " << c.getSchedule()
                 << " | $" << c.getPrice() << " per course\n";
        }

        cout << "  Add to Cart a Course [1]\n"
             << "  Go Back to Browse Departments Menu [2]\n";
        int choice = readChoice("Enter your choice [1, 2]:", 1, 2);
        if (choice == 2) return;

        if (dept.getCourseCount() == 0)
        {
            cout << "  (nothing to add)\n";
            continue;
        }
        int courseNum = readChoice("Enter course number to buy [0 to go back]:", 0, dept.getCourseCount());
        if (courseNum == 0) continue;

        cart.addCourse(dept.getCourse(courseNum - 1));
        cout << "Course added to cart.\n";
    }
}
