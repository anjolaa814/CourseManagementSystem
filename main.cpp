#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "globals.h"
#include "Department.h"
#include "Course.h"
#include "Interface.h"
#include "AdminInterface.h"
#include "StudentInterface.h"
using namespace std;

Department* StoreDepartments = nullptr;
int TotalDepartments = 0;
const char* csvFile = "courses.csv";

void addDepartmentToStore(const char* name)
{
    Department* bigger = new Department[TotalDepartments + 1];
    for (int i = 0; i < TotalDepartments; i++)
        bigger[i] = StoreDepartments[i];
    bigger[TotalDepartments] = Department(name);
    delete[] StoreDepartments;
    StoreDepartments = bigger;
    TotalDepartments++;
}

static string trim(const string& s)
{
    int start = 0, end = (int)s.size() - 1;
    while (start <= end && isspace((unsigned char)s[start])) start++;
    while (end >= start && isspace((unsigned char)s[end])) end--;
    if (start > end) return "";
    return s.substr(start, end - start + 1);
}

void loadFromCSV()
{
    ifstream in(csvFile);
    if (!in) return;

    string line;
    if (!getline(in, line)) return;
    int deptTotal = atoi(trim(line).c_str());

    for (int d = 0; d < deptTotal; d++)
    {
        if (!getline(in, line)) break;
        stringstream ss(line);
        string deptName, countStr;
        getline(ss, deptName, ',');
        getline(ss, countStr, ',');
        int courseCount = atoi(trim(countStr).c_str());

        addDepartmentToStore(trim(deptName).c_str());
        Department& dept = StoreDepartments[TotalDepartments - 1];

        for (int c = 0; c < courseCount; c++)
        {
            if (!getline(in, line)) break;
            stringstream cs(line);
            string number, name, schedule, priceStr;
            getline(cs, number, ',');
            getline(cs, name, ',');
            getline(cs, schedule, ',');
            getline(cs, priceStr, ',');
            double price = atof(trim(priceStr).c_str());
            dept.addCourse(Course(trim(number), trim(name), trim(schedule), price));
        }
    }
}

void saveToCSV()
{
    ofstream out(csvFile);
    if (!out) return;

    out << TotalDepartments << "\n";
    for (int d = 0; d < TotalDepartments; d++)
    {
        Department& dept = StoreDepartments[d];
        out << dept.getName() << ", " << dept.getCourseCount() << "\n";
        for (int c = 0; c < dept.getCourseCount(); c++)
        {
            Course course = dept.getCourse(c);
            out << course.getNumber() << ", " << course.getName() << ", "
                << course.getSchedule() << ", " << course.getPrice() << "\n";
        }
    }
}

int main()
{
    loadFromCSV();

    while (true)
    {
        cout << "\n====== Course Management System ======\n"
             << "  Student [1]\n"
             << "  Admin [2]\n"
             << "  Exit [3]\n"
             << "Enter your choice [1, 2, 3]: ";
        string line;
        if (!getline(cin, line)) break;

        if (line == "1" || line == "2")
        {
            Interface* ui = nullptr;
            if (line == "1") ui = new StudentInterface();
            else ui = new AdminInterface();

            ui->run();
            delete ui;
        }
        else if (line == "3")
        {
            break;
        }
        else
        {
            cout << "  [!] Invalid input. Please try again.\n";
        }
    }

    delete[] StoreDepartments;
    cout << "Goodbye.\n";
    return 0;
}
