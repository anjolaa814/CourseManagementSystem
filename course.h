#pragma once
#include <string>
using namespace std;
 
class Course
{
private:
    string number;
    string name;
    string schedule;
    double price;
 
public:
    Course();
    Course(const string& number, const string& name, const string& schedule, double price);
 
    string getNumber() const;
    string getName() const;
    string getSchedule() const;
    double getPrice() const;
};
 
