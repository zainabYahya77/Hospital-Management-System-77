#pragma once
#include <bits/stdc++.h>
using namespace std;

class Department
{
private:
    int DepartmentID;
    string DepartmentName;

    vector<int> DoctorIDs;
    vector<int> NurseIDs;
    queue<int> WaitingQueue;
public:
    Department();
    Department(int department_id, string department_name);

    int getDepartmentID()const;
    string getDepartmentName();
    int getNextPatientFromQueue();
    
    void setDepartmentName(string department_name);
    void RemoveDoctor(int doctor_id);
    void RemoveNurse(int nurse_id);
    void addPatientToQueue(int patient_id);
    void addDoctor(int doctor_id);
    void addNurse(int nurse_id);
    
    bool hasWaitingPatients();
    
    void display()const;

    ~Department();
};