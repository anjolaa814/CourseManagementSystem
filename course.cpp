#include "Course.h"

Course::Course()
{
    number = "";
    name = "";
    schedule = "";
    price = 0.0;
}

Course::Course(const string& number, const string& name, const string& schedule, double price)
{
    this->number = number;
    this->name = name;
    this->schedule = schedule;
    this->price = price;
}

string Course::getNumber() const { return number; }
string Course::getName() const { return name; }
string Course::getSchedule() const { return schedule; }
double Course::getPrice() const { return price; }
