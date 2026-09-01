#pragma once

#include <bits/stdc++.h>
using namespace std;
class Person
{
protected:
    int ID;
    string Name;

public:
    Person();
    Person(int id, string name);

    int getId() const;
    string getName() const;

    void setName(string name);

    virtual void display() const ;

    virtual ~Person();
};
