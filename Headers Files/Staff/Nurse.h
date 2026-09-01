#pragma once

#include "../Core/Employee.h"
#include <string>
using namespace std;

class Nurse : public Employee
{
private:
    string Phone;
    int DepartmentId;

public:
    Nurse();

    Nurse(int id, string name, double base_salary, int shift_hours, string phone, int department_id);

    string getPhone() const;
    int getDepartmentId() const;

    double calculateSalary() const override;
    void setPhone(string phone);
    void setDepartmentId(int department_id);

    void display() const override;

    ~Nurse();
};