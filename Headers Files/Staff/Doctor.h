#pragma once
#include "../Core/Employee.h"

class Doctor : public Employee
{
private:
    string specialization;
    bool Availability;
    int DepartmentId;

public:
    Doctor();
    Doctor(int id, string name, double base_salary, int shift_hours,
    string specialization, bool availability, int department_id);

    string getSpecialization();
    bool isAvailable();
    int getDepartmentId();

    void setSpecialization(string specialization);
    void setAvailability(bool availability);
    void setDepartmentId(int department_id);

    double calculateSalary()const override;

    void display()const;

    ~Doctor();
};


