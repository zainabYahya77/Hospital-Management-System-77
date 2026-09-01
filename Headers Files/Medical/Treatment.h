#pragma once
#include <bits/stdc++.h>
using namespace std;
class Treatment
{
private:
    int TreatmentID;
    int PatientID;
    
    string Description;
    double Cost;
public:
    Treatment();
    Treatment(int treatment_id, int patient_id, string description, double cost);

    int getTreatmentID()const;
    int getPatientID()const;
    string getDescription()const;
    double getCost()const;

    void setDescription(string description);
    void setCost(double cost);
    void display()const;
};