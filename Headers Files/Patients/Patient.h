#pragma once
#include <bits/stdc++.h>
#include "../Core/Person.h"
class Patient : public Person
{
private:
    int Age;
    string Gender;
    string Phone;
    string Disease;

public:
    Patient();
Patient(int id, string name, int age, string gender, string phone, string disease);    int getAge()const;
    string getGender()const;
    string getPhone()const;
    string getDisease()const;

    void setAge(int age);
    void setGender(string gender);
    void setPhone(string phone);
    void setDisease(string disease);

    void display() const;

    ~Patient();
};
