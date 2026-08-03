#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "Course.h"
 
class Department {
private:
    char    name[50];
    Course* courses;
    int     courseCount;
 
public:
 
    Department();
    Department(const char* deptName);
 
    Department(const Department& src);
    Department& operator=(const Department& src);
    Department();
 
    void addCourse(const Course& c);
    const char* getName() const;
    int  getCourseCount() const;
    Course getCourse(int index) const;
};
 
#endif
 
