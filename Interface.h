#pragma once
#include <string>
using namespace std;

class Interface
{
protected:
    int readChoice(const string& prompt, int min, int max);
    string readNonEmpty(const string& prompt);
    double readPositivePrice(const string& prompt);
    string readSchedule(const string& prompt);
    void showError(const string& msg);

public:
    virtual void run() = 0;
    virtual ~Interface();
};
