#include "Department.h"
#include <cstring>

void Department::setName(const char* n)
{
    strncpy(name, n, DNAME_LEN);
    name[DNAME_LEN] = '\0';
}

Department::Department()
{
    name[0] = '\0';
    courses = nullptr;
    courseCount = 0;
}

Department::Department(const char* deptName)
{
    setName(deptName);
    courses = nullptr;
    courseCount = 0;
}

Department::Department(const Department& src)
{
    setName(src.name);
    courseCount = src.courseCount;
    if (courseCount > 0)
    {
        courses = new Course[courseCount];
        for (int i = 0; i < courseCount; i++)
            courses[i] = src.courses[i];
    }
    else
    {
        courses = nullptr;
    }
}

Department& Department::operator=(const Department& src)
{
    if (this != &src)
    {
        delete[] courses;
        setName(src.name);
        courseCount = src.courseCount;
        if (courseCount > 0)
        {
            courses = new Course[courseCount];
            for (int i = 0; i < courseCount; i++)
                courses[i] = src.courses[i];
        }
        else
        {
            courses = nullptr;
        }
    }
    return *this;
}

Department::~Department()
{
    delete[] courses;
}

void Department::addCourse(const Course& c)
{
    Course* bigger = new Course[courseCount + 1];
    for (int i = 0; i < courseCount; i++)
        bigger[i] = courses[i];
    bigger[courseCount] = c;
    delete[] courses;
    courses = bigger;
    courseCount++;
}

const char* Department::getName() const { return name; }
int Department::getCourseCount() const { return courseCount; }
Course Department::getCourse(int index) const { return courses[index]; }
