#include "../../Headers Files/Hospital/Department.h"

Department::Department() : DepartmentID(0), DepartmentName("")
{
}
Department::Department(int department_id, string department_name)
    : DepartmentID(department_id), DepartmentName(department_name)
{
}
int Department::getDepartmentID()const
{
    return DepartmentID;
}
string Department::getDepartmentName()
{
    return DepartmentName;
}
int Department::getNextPatientFromQueue()
{
    if (WaitingQueue.empty())
        return -1; // No patients in the queue
    int next_patient_id = WaitingQueue.front();
    WaitingQueue.pop();
    return next_patient_id;
}
void Department::setDepartmentName(string department_name)
{
    DepartmentName = department_name;
}
void Department::RemoveDoctor(int doctor_id)
{
    for (auto it = DoctorIDs.begin(); it != DoctorIDs.end(); ++it)
    {
        if (*it == doctor_id)
        {
            DoctorIDs.erase(it);
            return; // Exit after removing the doctor
        }
    }
}
void Department::RemoveNurse(int nurse_id)
{
    for (auto it = NurseIDs.begin(); it != NurseIDs.end(); ++it)
    {
        if (*it == nurse_id)
        {
            NurseIDs.erase(it);
            return; // Exit after removing the nurse
        }
    }
}
void Department::addPatientToQueue(int patient_id)
{
    WaitingQueue.push(patient_id);
}
void Department::addDoctor(int doctor_id)
{
    DoctorIDs.push_back(doctor_id);
}
void Department::addNurse(int nurse_id)
{
    NurseIDs.push_back(nurse_id);
}
bool Department::hasWaitingPatients()
{
    return !WaitingQueue.empty();
}
void Department::display()const
{
    cout << "===============================" << endl;
    cout << "Department Information:" << endl;

    cout << "Department ID: " << DepartmentID << endl;
    cout << "Department Name: " << DepartmentName << endl;
    
    cout << "Doctors in Department: ";
    if (DoctorIDs.empty())
        cout << "None";
    else
    {
        for (int doctor_id : DoctorIDs)
            cout << doctor_id << " ";
    }
    cout << endl;

    cout << "Nurses in Department: ";
    if (NurseIDs.empty())
    cout << "None";
    else
    {
        for (int nurse_id : NurseIDs)
            cout << nurse_id << " ";
    }
    cout << endl;

    cout << "Waiting Patients Queue: "<<WaitingQueue.size()<<" patients waiting." << endl;

    cout << "===============================" << endl;
}
Department::~Department(){}