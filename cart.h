#pragma once
#include <string>
#include "Course.h"
using namespace std;

class Cart
{
private:
    Course* courses;
    string* schedules;
    int count;
    static const double TAX_RATE;

public:
    Cart();
    Cart(const Cart& src);
    Cart& operator=(const Cart& src);
    ~Cart();

    void addCourse(const Course& c);
    void listCourses() const;
    bool isEmpty() const;
    void clear();
    double getTotalWithTax() const;
};
