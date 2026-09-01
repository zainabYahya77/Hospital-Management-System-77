#include <bits/stdc++.h>
using namespace std;

class  Person
{
protected:

    int id;
    string name;
public:

    int getId()
    {
        return id;
    }

    Person(int i, string n)
    {
        id = i;
        name = n;
    }
};
class Patient : public Person
{
    int age;
    string disease;
    string gender;
    string phone;

public:
    Patient(string n, int i, int a, string dis, string g, string p) : Person(i, n)
    {
        age = a;
        disease = dis;
        gender = g;
        phone = p;
    }

    void setAge(int a)
    {
        age = a;
    }
    void setDisease(string dis)
    {
        disease = dis;
    }
    void setGender(string g)
    {
        gender = g;
    }
    void setPhone(string p)
    {
        phone = p;
    }
};

class Doctor : public Person
{
    string specialization;
    bool availability;
    double salary;

public:
    Doctor(string n, int i, string sp, bool ava, double s) : Person(i, n)
    {
        specialization = sp;
        availability = ava;
        salary = s;
    }
};

vector<Patient> patients;

void addPatient(string n, int i, int a, string dis, string g, string p)
{
    Patient patient(n, i, a, dis, g, p);
    patients.push_back(patient);
}

void searchPatient(int id)
{
    bool  found = false;
    for (Patient p : patients)
    {
        if (id == p.getId())
        {
            found = true;
            cout << " Patient found" << endl;
        }
    }
    if (found == false)
    {
        cout << " Patient  not found " << endl;
    }
}

void editPatient(int id);

class Nurse
{
    int id;
    string name;
    string phone;
    string shift;
    double salary;
public:
    Nurse(int i = 0, string n = "", string p = "", string sh = "", double s = 0.0)
        : id(i), name(n), phone(p), shift(sh), salary(s)
    {
    }
    int getId() const
    {
        return id;
    }
    string getName() const
    {
        return name;
    }
    string getShift() const
    {
        return shift;
    }
    void setName(string n)
    {
        name = n;
    }
    void setPhone(string p)
    {
        phone = p;
    }
    void setShift(string sh)
    {
        shift = sh;
    }
    void setSalary(double s)
    {
        salary = s;
    }
    void print() const
    {
        cout << "Nurse ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Shift: " << shift << endl;
        cout << "Salary: " << salary << endl;
    }
    string serialize() const
    {
        return to_string(id) + "|" + sanitize(name) + "|" + sanitize(phone) + "|" +
            sanitize(shift) + "|" + to_string(salary);
    }
};

class Room
{
    int id;
    string number;
    string type;
    bool occupied;
    int patientId;
public:
    Room(int i = 0, string num = "", string t = "")
        : id(i), number(num), type(t), occupied(false), patientId(-1)
    {
    }
    int getId() const
    {
        return id;
    }
    string getNumber() const
    {
        return number;
    }
    bool isOccupied() const
    {
        return occupied;
    }
    int getPatientId() const
    {
        return patientId;
    }
    bool assign(int pid)
    {
        if (occupied)
        {
            return false;
        }
        occupied = true;
        patientId = pid;
        return true;
    }
    bool release()
    {
        if (!occupied)
        {
            return false;
        }
        occupied = false;
        patientId = -1;
        return true;
    }
    void print() const
    {
        cout << "Room ID: " << id << endl;
        cout << "Room Number: " << number << endl;
        cout << "Room Type: " << type << endl;
        if (occupied)
        {
            cout << "Status: Occupied" << endl;
            cout << "Patient ID: " << patientId << endl;
        }
        else
        {
            cout << "Status: Available" << endl;
        }
    }
    string serialize() const
    {
        return to_string(id) + "|" + sanitize(number) + "|" + sanitize(type) + "|" +
            (occupied ? "1" : "0") + "|" + to_string(patientId);
    }
};