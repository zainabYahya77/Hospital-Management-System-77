#include "../../Headers Files/Staff/Nurse.h"


Nurse::Nurse() : Phone(""), DepartmentId(0)
{
}

Nurse::Nurse(int id, string name, double base_salary,
    int shift_hours, string phone, int department_id)
    : Employee(id, name, base_salary, shift_hours), Phone(phone), DepartmentId(department_id)
{
}
string Nurse::getPhone()const
{
    return Phone;
}
int Nurse::getDepartmentId()const
{
    return DepartmentId;
}
double Nurse::calculateSalary()const 
{
    double shiftBonus = shift_Hours * 100;
    return base_Salary + shiftBonus;
}

void Nurse::setPhone(string phone)
{
    Phone = phone;
}

void Nurse::setDepartmentId(int department_id)
{
    DepartmentId = department_id;
}

void Nurse::display() const
{
    cout << "===============================" << endl;
    cout << "Nurse Information:" << endl;

    Employee::display();

    cout << "Phone: " << Phone << endl;
    cout << "Department ID: " << DepartmentId << endl;
    cout << "Base Salary: " << base_Salary << endl;
    cout << "Shift Hours: " << shift_Hours << endl;
    cout << "Calculated Salary: " << calculateSalary() << endl;
    cout << "===============================" << endl;
}

Nurse::~Nurse()
{
}