#include "Cart.h"
#include <iostream>
#include <iomanip>
using namespace std;

const double Cart::TAX_RATE = 0.13;

Cart::Cart()
{
    courses = nullptr;
    schedules = nullptr;
    count = 0;
}

Cart::Cart(const Cart& src)
{
    count = src.count;
    if (count > 0)
    {
        courses = new Course[count];
        schedules = new string[count];
        for (int i = 0; i < count; i++)
        {
            courses[i] = src.courses[i];
            schedules[i] = src.schedules[i];
        }
    }
    else
    {
        courses = nullptr;
        schedules = nullptr;
    }
}

Cart& Cart::operator=(const Cart& src)
{
    if (this != &src)
    {
        delete[] courses;
        delete[] schedules;
        count = src.count;
        if (count > 0)
        {
            courses = new Course[count];
            schedules = new string[count];
            for (int i = 0; i < count; i++)
            {
                courses[i] = src.courses[i];
                schedules[i] = src.schedules[i];
            }
        }
        else
        {
            courses = nullptr;
            schedules = nullptr;
        }
    }
    return *this;
}

Cart::~Cart()
{
    delete[] courses;
    delete[] schedules;
}

void Cart::addCourse(const Course& c)
{
    Course* biggerC = new Course[count + 1];
    string* biggerS = new string[count + 1];
    for (int i = 0; i < count; i++)
    {
        biggerC[i] = courses[i];
        biggerS[i] = schedules[i];
    }
    biggerC[count] = c;
    biggerS[count] = c.getSchedule();
    delete[] courses;
    delete[] schedules;
    courses = biggerC;
    schedules = biggerS;
    count++;
}

void Cart::listCourses() const
{
    for (int i = 0; i < count; i++)
    {
        cout << "  [" << (i + 1) << "] "
             << courses[i].getNumber() << " - " << courses[i].getName()
             << " | " << schedules[i]
             << " | $" << fixed << setprecision(2) << courses[i].getPrice()
             << endl;
    }
    cout << "  Total (incl. 13% tax): $" << fixed << setprecision(2) << getTotalWithTax() << endl;
}

bool Cart::isEmpty() const { return count == 0; }

void Cart::clear()
{
    delete[] courses;
    delete[] schedules;
    courses = nullptr;
    schedules = nullptr;
    count = 0;
}

double Cart::getTotalWithTax() const
{
    double subtotal = 0.0;
    for (int i = 0; i < count; i++)
        subtotal += courses[i].getPrice();
    return subtotal + subtotal * TAX_RATE;
}

