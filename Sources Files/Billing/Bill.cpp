#include "../../Headers Files/Billing/Bill.h"
Bill::Bill(): BillID(0), PatientID(-1), DoctorFee(0.0), RoomFee(0.0), TreatmentFee(0.0), MedicineFee(0.0), TotalAmount(0.0)
{
}
Bill::Bill(int bill_id, int patient_id, double doctor_fee, double room_fee, double treatment_fee, double medicine_fee, double total_amount)
    : BillID(bill_id), PatientID(patient_id), DoctorFee(doctor_fee), RoomFee(room_fee), TreatmentFee(treatment_fee), MedicineFee(medicine_fee), TotalAmount(total_amount)
{
    CalculateTotalAmount();
}
int Bill::getBillID()
{
    return BillID;
}
int Bill::getPatientID()
{
    return PatientID;
}
double Bill::getDoctorFee()
{
    return DoctorFee;
}
double Bill::getRoomFee()
{
    return RoomFee;
}
double Bill::getTreatmentFee()
{
    return TreatmentFee;
}
double Bill::getMedicineFee()
{
    return MedicineFee;
}
double Bill::getTotalAmount()
{
    return TotalAmount;
}
void Bill::CalculateTotalAmount()
{
    TotalAmount = DoctorFee + RoomFee + TreatmentFee + MedicineFee;
}
void Bill::display()const
{
    cout << "===============================" << endl;
    cout << "Bill Information:" << endl;

    cout << "Bill ID: " << BillID << endl;
    cout << "Patient ID: " << PatientID << endl;
    cout << "Doctor Fee: " << DoctorFee << endl;
    cout << "Room Fee: " << RoomFee << endl;
    cout << "Treatment Fee: " << TreatmentFee << endl;
    cout << "Medicine Fee: " << MedicineFee << endl;
    cout<<"--------------------------------" << endl;
    cout << "Total Amount: " << TotalAmount << endl;
    cout << "===============================" << endl;
}

