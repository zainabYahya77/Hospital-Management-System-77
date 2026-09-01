#include "../../Headers Files/Appointments/Appointment.h"

Appointment::Appointment() : AppointmentID(0), PatientID(0), DoctorID(0), AppointmentDate(""), AppointmentTime(""), AppointmentStatus("")
{
}
Appointment::Appointment(int appointment_id, int patient_id, int doctor_id,
    string appointment_date, string appointment_time, string appointment_status)
    : AppointmentID(appointment_id), PatientID(patient_id), DoctorID(doctor_id), AppointmentDate(appointment_date), AppointmentTime(appointment_time), AppointmentStatus(appointment_status)
{
}
int Appointment::getAppointmentID()
{
    return AppointmentID;
}
int Appointment::getPatientID()
{
    return PatientID;
}
int Appointment::getDoctorID()const
{
    return DoctorID;
}
string Appointment::getAppointmentDate()const
{
    return AppointmentDate;
}
string Appointment::getAppointmentTime()const
{
    return AppointmentTime;
}
string Appointment::getAppointmentStatus()const
{
    return AppointmentStatus;
}
void Appointment::setAppointmentDate(string appointment_date)
{
    AppointmentDate = appointment_date;
}
void Appointment::setAppointmentTime(string appointment_time)
{
    AppointmentTime = appointment_time;
}
void Appointment::setAppointmentStatus(string appointment_status)
{
    AppointmentStatus = appointment_status;
}
void Appointment::cancelAppointment()
{
    AppointmentStatus = "Cancelled";
}
void Appointment::display()const
{
    cout << "===============================" << endl;
    cout << "Appointment Information:" << endl;
    cout << "Appointment ID: " << AppointmentID << endl;
    cout << "Patient ID: " << PatientID << endl;
    cout << "Doctor ID: " << DoctorID << endl;
    cout << "Appointment Date: " << AppointmentDate << endl;
    cout << "Appointment Time: " << AppointmentTime << endl;
    cout << "Appointment Status: " << AppointmentStatus << endl;
    cout << "===============================" << endl;
}