#include "Interface.h"
#include <iostream>
#include <sstream>
using namespace std;

Interface::~Interface()
{
}

void Interface::showError(const string& msg)
{
    cout << "  [!] " << msg << endl;
}

int Interface::readChoice(const string& prompt, int min, int max)
{
    string line;
    while (true)
    {
        cout << prompt << " ";
        getline(cin, line);
        stringstream ss(line);
        int value;
        char leftover;
        if ((ss >> value) && !(ss >> leftover) && value >= min && value <= max)
            return value;
        showError("Invalid input. Please try again.");
    }
}

string Interface::readNonEmpty(const string& prompt)
{
    string line;
    while (true)
    {
        cout << prompt << " ";
        getline(cin, line);
        if (!line.empty())
            return line;
        showError("Input cannot be empty. Please try again.");
    }
}

double Interface::readPositivePrice(const string& prompt)
{
    string line;
    while (true)
    {
        cout << prompt << " ";
        getline(cin, line);
        stringstream ss(line);
        double value;
        char leftover;
        if ((ss >> value) && !(ss >> leftover) && value > 0.0)
            return value;
        showError("Please enter a valid positive number.");
    }
}

string Interface::readSchedule(const string& prompt)
{
    string line;
    while (true)
    {
        cout << prompt << " ";
        getline(cin, line);
        if (line == "M/W" || line == "T/R" || line == "W/F")
            return line;
        showError("Schedule must be one of: M/W, T/R, W/F.");
    }
}
