#pragma once
#include "Department.h"

extern Department* StoreDepartments;
extern int TotalDepartments;
extern const char* csvFile;

void addDepartmentToStore(const char* name);
void loadFromCSV();
void saveToCSV();
