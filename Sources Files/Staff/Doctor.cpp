#include "../../Headers Files/Staff/Doctor.h"

using namespace std;
Doctor::Doctor() : specialization(""), Availability(false), DepartmentId(0)
{
}
Doctor::Doctor(int id, string name, double base_salary, int shift_hours,
        string specialization, bool availability, int department_id)
    : Employee(id, name, base_salary, shift_hours), specialization(specialization), Availability(availability), DepartmentId(department_id)
{
}
string Doctor::getSpecialization()
{
    return specialization;
}
bool Doctor::isAvailable()
{
    return Availability;
}
int Doctor::getDepartmentId()
{
    return DepartmentId;
}
void Doctor::setSpecialization(string specialization)
{
    specialization = specialization;
}
void Doctor::setAvailability(bool availability)
{
    Availability = availability;
}
void Doctor::setDepartmentId(int department_id)
{
    DepartmentId = department_id;
}
double Doctor::calculateSalary()const
{
    double bonus = 0.0;
    if (specialization == "Cardiology")
        bonus = 3000.0;
    else if (specialization == "Surgery")
        bonus = 5000.0;
    else if (specialization == "Neurology")
        bonus = 4000.0;
    else
        bonus = 1500.0;
        double ShiftBonus = shift_Hours * 200;
    return base_Salary + ShiftBonus + bonus;
}

void Doctor::display()const
{
    cout << "===============================" << endl;
    cout << "Doctor Information:" << endl;

    Employee::display();
    cout << "Specialization: " << specialization <<endl;
    cout << "Availability: " << (Availability ? "Available" : "Not Available") << endl;
    cout << "Department ID: " << DepartmentId << endl;

    cout<<"Base Salary: "<<base_Salary<<endl;
    cout<<"Shift Hours: "<<shift_Hours<<endl;

    cout<<"Calculated Salary: "<<calculateSalary()<<endl;

    cout << "===============================" << endl;
}

Doctor::~Doctor()
{
}