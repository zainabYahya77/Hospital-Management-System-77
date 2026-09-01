#pragma once
#include <bits/stdc++.h>
using namespace std;
class Appointment
{
private:
    int AppointmentID;
    int PatientID;
    int DoctorID;
    string AppointmentDate;
    string AppointmentTime;
    string AppointmentStatus;

public:
    Appointment();
    Appointment(int appointment_id, int patient_id, int doctor_id,
                string appointment_date, string appointment_time, string appointment_status);

    int getAppointmentID();
    int getPatientID();
    int getDoctorID()const;
    string getAppointmentDate()const;
    string getAppointmentTime()const;
    string getAppointmentStatus()const;

    void setAppointmentDate(string appointment_date);
    void setAppointmentTime(string appointment_time);
    void setAppointmentStatus(string appointment_status);
    void cancelAppointment();
    void display()const;
};