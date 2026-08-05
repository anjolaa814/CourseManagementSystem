#pragma once
#include "Interface.h"
#include "Cart.h"

class StudentInterface : public Interface
{
private:
    Cart cart;

    void showCartMenu();
    void browseDepartments();
    void listDepartmentCourses(int index);

public:
    void run() override;
};
