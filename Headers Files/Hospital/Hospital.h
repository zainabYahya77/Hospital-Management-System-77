#pragma once

#include "../Patients/Patient.h"
#include "../Staff/Doctor.h"
#include "../Staff/Nurse.h"

#include "../Hospital/Room.h"
#include "../Hospital/Department.h"

#include "../Appointments/Appointment.h"
#include "../Medical/Treatment.h"
#include "../Billing/Bill.h"

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Hospital {
private:
vector<Patient> patients;
vector<Doctor> doctors;
vector<Nurse> nurses;

vector<Room> rooms;
vector<Department> departments;

vector<Appointment> appointments;

vector<Treatment> treatments;
vector<Bill> bills;

//Patient
void addPatient();
void searchPatient();
void editPatient();
void deletePatient();
void displayPatients()const;

//Doctor
void addDoctor();
void searchDoctor();
void editDoctor();
void deleteDoctor();
void displayDoctors();

//Nurse
void addNurse();
void searchNurse();
void editNurse();
void deleteNurse();
void displayNurses();

//Room
void addRoom();
void displayRooms();
void assignPatientToRoom();
void releasePatientFromRoom();

//Department
void addDepartment();
void displayDepartments();

void assignDoctorToDepartment();
void assignNurseToDepartment();

//Appointment
void bookAppointment();
void cancelAppointment();
void rescheduleAppointment();
void displayAppointments();

//Query
void addTreatmentToQueue();
void serveNextPatient();
void displayTreatmentQueue() const;

//Treatment
void addTreatment();
void displayTreatments() const;

//Billing
void generateBill();
void displayBills() const;

//Validation / search
Patient* findPatientById(int patient_id);
Doctor* findDoctorById(int doctor_id);
Nurse* findNurseById(int nurse_id);
Room* findRoomById(int room_id);
Department* findDepartmentById(int department_id);

bool patientExists(int patient_id);
bool doctorExists(int doctor_id);
bool nurseExists(int nurse_id);
bool roomExists(int room_id);
bool departmentExists(int department_id)const;

bool isDoctorAvailable(int doctor_id, string appointment_date, string appointment_time)const;
bool isRoomAvailable(int room_id);

//Menus
void patientMenu();
void doctorMenu();
void nurseMenu();
void roomMenu();
void departmentMenu();
void appointmentMenu();
void treatmentMenu();
void billingMenu();
void QueryMenu();

public:
    Hospital();
    void run();
};