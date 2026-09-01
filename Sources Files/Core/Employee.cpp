#include "../../Headers Files/Core/Employee.h"

Employee::Employee() : base_Salary(0.0), shift_Hours(0){}   
Employee::Employee(int id, string name, double base_salary, int shift_hours) : Person(id, name)
{
    base_Salary = base_salary;
    shift_Hours = shift_hours;
}

double Employee::getBaseSalary()
{
    return base_Salary;
}

int Employee::getShiftHours()
{
    return shift_Hours;
}

void Employee::setBaseSalary(double salary)
{
    base_Salary = salary;
}

void Employee::setShiftHours(int hours)
{
    shift_Hours = hours;
}

void Employee::display() const
{
    Person::display();
    cout << "Base Salary: " << base_Salary << endl;
    cout << "Shift Hours: " << shift_Hours << endl;
}
Employee::~Employee()
{
}
