#pragma once
#include <bits/stdc++.h>
#include "Person.h"
class Employee : public Person
{
protected:
    double base_Salary;
    int shift_Hours;

public:
    Employee();

    Employee(int id,string name,
    double base_Salary,int shift_Hours);

    double getBaseSalary();
    int getShiftHours();

    void setBaseSalary(double base_Salary);
    void setShiftHours(int shift_Hours);

    virtual double calculateSalary()const = 0;

    virtual void display() const;

    virtual ~Employee();
};