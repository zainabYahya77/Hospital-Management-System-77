#include "../../Headers Files/Medical/Treatment.h"

Treatment::Treatment() : TreatmentID(0), PatientID(0), Description(""), Cost(0.0)
{
}
Treatment::Treatment(int treatment_id, int patient_id, string description, double cost) : TreatmentID(treatment_id), PatientID(patient_id), Description(description), Cost(cost)
{
}
int Treatment::getTreatmentID()const
{
    return TreatmentID;
}
int Treatment::getPatientID()const
{
    return PatientID;
}
string Treatment::getDescription()const
{
    return Description;
}
double Treatment::getCost()const
{
    return Cost;
}
void Treatment::setDescription(string description)
{
    Description = description;
}
void Treatment::setCost(double cost)
{
    Cost = cost;
}
void Treatment::display() const
{
    cout << "===============================" << endl;
    cout << "Treatment Information:" << endl;
    cout << "Treatment ID: " << TreatmentID << endl;
    cout << "Patient ID: " << PatientID << endl;
    cout << "Description: " << Description << endl;
    cout << "Cost: " << Cost << endl;
    cout << "===============================" << endl;
}
