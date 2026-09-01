#include "../../Headers Files/Hospital/Room.h"
using namespace std;

Room::Room() : RoomID(0), RoomType(""), RoomNumber(""), Occupied(false), PatientID(-1)
{
}
Room::Room(int room_id, string room_type, string room_number, bool occupied, int patient_id)
    : RoomID(room_id), RoomType(room_type), RoomNumber(room_number), Occupied(occupied), PatientID(patient_id)
{
}
int Room::getRoomID() const
{
    return RoomID;
}
string Room::getRoomType() const
{
    return RoomType;
}
string Room::getRoomNumber() const
{
    return RoomNumber;
}
bool Room::isOccupied() const
{
    return Occupied;
}
int Room::getPatientID() const
{
    return PatientID;
}
bool Room::assignPatient(int patient_id)
{
    if (Occupied)
        return false;
    Occupied = true;
    PatientID = patient_id;
    return true;
}
bool Room::releasePatient()
{
    if (!Occupied)
        return false; 
    Occupied = false;
    PatientID = -1;
    return true;
}
void Room::display()const
{
    cout << "===============================" << endl;
    cout << "Room Information:" << endl;
    cout << "Room ID: " << RoomID << endl;
    cout << "Room Type: " << RoomType << endl;
    cout << "Room Number: " << RoomNumber << endl;

    if (Occupied)
    {
        cout << "Status: Occupied" << endl;
        cout << "Patient ID: " << PatientID << endl;
    }
    else
        cout << "Status: Available" << endl;

    cout << "===============================" << endl;
}
Room::~Room()
{
}