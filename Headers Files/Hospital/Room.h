#pragma once
#include <bits/stdc++.h>
using namespace std;

class Room
{
private:
    int RoomID;
    string RoomType;
    string RoomNumber;
    bool Occupied;
    int PatientID;
public:
    Room();
    Room(int room_id, string room_type, string room_number, bool occupied, int patient_id);

    int getRoomID()const;
    string getRoomType()const;
    string getRoomNumber()const;
    bool isOccupied()const;
    int getPatientID()const;

    bool assignPatient(int patient_id);
    bool releasePatient();

    void display()const;

    ~Room();
};