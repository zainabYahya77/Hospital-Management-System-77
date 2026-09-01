#include "../../Headers Files/Patients/Patient.h"
Patient::Patient() : Age(0), Gender("Null"), Phone(""), Disease("")
{
}
Patient::Patient(int id, string name, int age, string gender, string phone, string disease) 
: Person(id, name), Age(age), Gender(gender), Phone(phone), Disease(disease)
{
}

int Patient::getAge()const
{
    return Age;
}

string Patient::getGender()const
{
    return Gender;
}

string Patient::getPhone()const
{
    return Phone;
}

string Patient::getDisease()const
{
    return Disease;
}

void Patient::setAge(int age)
{
    Age = age;
}

void Patient::setGender(string gender)
{
    Gender = gender;
}

void Patient::setPhone(string phone)
{
    Phone = phone;
}

void Patient::setDisease(string disease)
{
    Disease = disease;
}

void Patient::display() const
{
    cout << "===============================" << endl;
    cout << "Patient Information:" << endl;
    Person::display();
    cout << "Age: " << Age << endl;
    cout << "Gender: " << Gender << endl;
    cout << "Phone: " << Phone << endl;
    cout << "Disease: " << Disease << endl;
    cout << "===============================" << endl;
}

Patient::~Patient()
{
}