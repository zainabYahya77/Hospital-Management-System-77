#include "../../Headers Files/Core/Person.h"

Person::Person() : ID(0), Name("")
{
}
Person::Person(int id, const string& name) : ID(id), Name(name)
{
}
int Person::getId() const
{
    return ID;
}
string Person::getName() const
{
    return Name;
}
void Person::setName(const string& name)
{
    this->Name = name;
}

void Person::display() const
{
    cout << "ID: " << ID << " , Name: " << Name << endl;
}

Person::~Person()
{
}
