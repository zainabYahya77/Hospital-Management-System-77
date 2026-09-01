#pragma once
#include <bits/stdc++.h>
using namespace std;
class Bill
{
private:
    int BillID;
    int PatientID;

    double DoctorFee;
    double RoomFee;
    double TreatmentFee;
    double MedicineFee;
    double TotalAmount;

public:
    Bill();
    Bill(int bill_id, int patient_id, double doctor_fee, double room_fee,
        double treatment_fee, double medicine_fee, double total_amount);
    int getBillID();
    int getPatientID();

    double getDoctorFee();
    double getRoomFee();
    double getTreatmentFee();
    double getMedicineFee();

    double getTotalAmount();

    void CalculateTotalAmount();
    void display()const;
};