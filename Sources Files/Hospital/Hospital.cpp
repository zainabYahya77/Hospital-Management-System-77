#include "../../Headers Files/Hospital/Hospital.h"

Hospital::Hospital()
{
}
// Search Helpers

Patient *Hospital::findPatientById(int id)
{
    for (Patient &p : patients)
    {
        if (p.getId() == id)
            return &p;
    }
    return nullptr;
}

Doctor *Hospital::findDoctorById(int id)
{
    for (Doctor &d : doctors)
    {
        if (d.getId() == id)
            return &d;
    }
    return nullptr;
}

Nurse *Hospital::findNurseById(int id)
{
    for (Nurse &n : nurses)
    {
        if (n.getId() == id)
            return &n;
    }
    return nullptr;
}

Room *Hospital::findRoomById(int id)
{
    for (Room &r : rooms)
    {
        if (r.getRoomID() == id)
            return &r;
    }
    return nullptr;
}

Department *Hospital::findDepartmentById(int id)
{
    for (Department &d : departments)
    {
        if (d.getDepartmentID() == id)
            return &d;
    }
    return nullptr;
}

// Existence Checks

bool Hospital::patientExists(int id)
{
    for (const Patient &p : patients)
    {
        if (p.getId() == id)
            return true;
    }
    return false;
}

bool Hospital::doctorExists(int id)
{
    for (const Doctor &d : doctors)
    {
        if (d.getId() == id)
            return true;
    }
    return false;
}

bool Hospital::nurseExists(int id)
{
    for (const Nurse &n : nurses)
    {
        if (n.getId() == id)
            return true;
    }
    return false;
}

bool Hospital::roomExists(int id)
{
    for (const Room &r : rooms)
    {
        if (r.getRoomID() == id)
            return true;
    }
    return false;
}

bool Hospital::departmentExists(int id) const
{
    for (const Department &d : departments)
    {
        if (d.getDepartmentID() == id)
            return true;
    }
    return false;
}

bool Hospital::isRoomAvailable(int room_id)
{
    for (const Room &r : rooms)
    {
        if (r.getRoomID() == room_id)
            return !r.isOccupied();
    }
    return false;
}

// Patient Management

void Hospital::addPatient()
{
    int id, age;
    string name, gender, phone, disease;

    cout << "Enter Patient ID: ";cin >> id;
    if (id < 0){cout << "Patient ID cannot be negative.\n";return;}

    for(const Patient &p : patients)
    {
        if (p.getId() == id)
        {
            cout << "\n\"Patient ID already exists.\"\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Name: ";getline(cin, name);
    if (name.empty()){cout << "Name cannot be empty.\n";return;}

    cout << "Enter Age: ";cin >> age;
    if (age < 0|| age > 120){cout << "Age cannot be negative.\n";return;}

    cin.ignore();

    cout << "Enter Gender: ";getline(cin, gender);
    if (gender.empty())
    {cout << "Gender cannot be empty.\n";return;}

    cout << "Enter Phone: ";getline(cin, phone);
    if (phone.empty()){cout << "Phone cannot be empty.\n";return;}

    cout << "Enter Disease: ";getline(cin, disease);
    if (disease.empty()){cout << "Disease cannot be empty.\n";return;}

    patients.push_back(Patient(id, name, age, gender, phone, disease));

    cout << "\n\"Patient added successfully.\"\n";
}

void Hospital::searchPatient()
{
    int id;
    cout << "Enter Patient ID: ";cin >> id;
    if (id < 0){cout << "Patient ID cannot be negative.\n";return;}

    Patient *patient = findPatientById(id);
    if (patient == nullptr)
    {
        cout << "Patient not found.\n";
        return;
    }

    patient->display();
}

void Hospital::editPatient()
{
    int id;
    cout << "Enter Patient ID: ";cin >> id;
    if (id < 0){cout << "Patient ID cannot be negative.\n";return;}

    Patient *patient = findPatientById(id);
    if (patient == nullptr)
    {
        cout << "Patient not found.\n";
        return;
    }

    int age;
    string name, gender, phone, disease;

    cin.ignore();

    cout << "Enter New Name: ";getline(cin, name);
    if (name.empty()){cout << "Name cannot be empty.\n";return;}

    cout << "Enter New Age: ";cin >> age;
    if (age < 0 || age > 120){cout << "Age cannot be negative.\n";return;}

    cin.ignore();

    cout << "Enter New Gender: ";getline(cin, gender);
    if (gender.empty()){cout << "Gender cannot be empty.\n";return;}

    cout << "Enter New Phone: ";getline(cin, phone);
    if (phone.empty()){cout << "Phone cannot be empty.\n";return;}

    cout << "Enter New Disease: ";getline(cin, disease);
    if (disease.empty()){cout << "Disease cannot be empty.\n";return;}

    patient->setName(name);
    patient->setAge(age);
    patient->setGender(gender);
    patient->setPhone(phone);
    patient->setDisease(disease);

    cout << "\n\"Patient updated successfully.\"\n";
}

void Hospital::deletePatient()
{
    int id;

    cout << "Enter Patient ID: ";cin >> id;
    if (id < 0){cout << "\"Patient ID cannot be negative.\"\n";return;}

    for (auto it = patients.begin(); it != patients.end(); ++it)
    {
        if (it->getId() == id)
        {
            patients.erase(it);
            cout << "\"Patient deleted successfully.\"\n";
            return;
        }
    }
    cout << "\"Patient not found.\"\n";
}

void Hospital::displayPatients() const
{
    if (patients.empty())
    {
        cout << "No patients found.\n";
        return;
    }
    for (const Patient &p : patients)
        p.display();
}

// Doctor Management

void Hospital::addDoctor()
{
    int id;
    string name;
    double salary;
    int shiftHours;
    string specialization;
    int departmentId;

    cout << "Enter Doctor ID: ";cin >> id;
    if (id < 0){cout << "\n\"Doctor ID cannot be negative.\"\n";return;}
    for (const Doctor &d : doctors)
    {
        if (d.getId() == id)
        {
            cout << "Doctor ID already exists.\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Name: ";getline(cin, name);
    if (name.empty()){cout << "Name cannot be empty.\n";return;}

    cout << "Enter Base Salary: ";cin >> salary;
    if (salary < 0){cout << "Base Salary cannot be negative.\n";return;}

    cout << "Enter Shift Hours: ";cin >> shiftHours;
    if (shiftHours < 0){cout << "Shift Hours cannot be negative.\n";return;}

    cin.ignore();

    cout << "Enter Specialization: ";getline(cin, specialization);
    if (specialization.empty()){cout << "Specialization cannot be empty.\n";return;}

    cout << "Enter Department ID: ";cin >> departmentId;
    if (departmentId < 0){cout << "Department ID cannot be negative.\n";return;}

    doctors.push_back(Doctor(id, name, salary, shiftHours, specialization, true, departmentId));

    findDepartmentById(departmentId)->addDoctor(id);
    cout<<"\n\"Doctor added successfully.\"\n";
}

void Hospital::searchDoctor()
{
    int id;
    cout << "Enter Doctor ID: ";cin >> id;

    Doctor *doctor = findDoctorById(id);
    if (doctor == nullptr)
    {
        cout << "Doctor not found.\n";
        return;
    }

    doctor->display();
}

void Hospital::editDoctor()
{
    int id;
    cout << "Enter Doctor ID: ";cin >> id;

    Doctor *doctor = findDoctorById(id);
    if (doctor == nullptr)
    {
        cout << "Doctor not found.\n";
        return;
    }

    string name, specialization;
    double salary;
    int shiftHours;
    int departmentId;

    cin.ignore();

    cout << "Enter New Name: "; getline(cin, name);
    if (name.empty()){cout << "Name cannot be empty.\n";return;}

    cout << "Enter New Base Salary: ";cin >> salary;
    if (salary < 0){cout << "Base Salary cannot be negative.\n";return;}

    cout << "Enter New Shift Hours: ";cin >> shiftHours;
    if (shiftHours < 0){cout << "Shift Hours cannot be negative.\n";return;}
    
    cin.ignore();

    cout << "Enter New Specialization: ";getline(cin, specialization);
    if (specialization.empty()){cout << "Specialization cannot be empty.\n";return;}
    
    cout << "Enter New Department ID: ";cin >> departmentId;
    if (departmentId < 0){cout << "Department ID cannot be negative.\n";return;}

    if (!departmentExists(departmentId))
    {
        cout << "Department does not exist.\n";
        return;
    }

    doctor->setName(name);
    doctor->setBaseSalary(salary);
    doctor->setShiftHours(shiftHours);
    doctor->setSpecialization(specialization);
    doctor->setDepartmentId(departmentId);

    cout << "Doctor updated successfully.\n";
}

void Hospital::deleteDoctor()
{
    int id;
    cout << "Enter Doctor ID: ";cin >> id;
    if (id < 0){cout << "\n\"Doctor ID cannot be negative.\"\n";return;}

    for (auto it = doctors.begin(); it != doctors.end(); ++it)
    {
        if (it->getId() == id)
        {
            doctors.erase(it);
            cout << "Doctor deleted successfully.\n";
            return;
        }
    }
    cout << "Doctor not found.\n";
}

void Hospital::displayDoctors()
{

    if (doctors.empty()){cout << "No doctors found.\n";return;}
    
    for (const Doctor &d : doctors)d.display();
}

// Nurse Management

void Hospital::addNurse()
{
    int id;
    string name, phone;
    double salary;
    int shiftHours;
    int departmentId;

    cout << "Enter Nurse ID: ";cin >> id;
    if (id < 0){cout << "Nurse ID cannot be negative.\n";return;}

    if (nurseExists(id))
    {
        cout << "Nurse ID already exists.\n";
        return;
    }

    cin.ignore();

    cout << "Enter Name: ";getline(cin, name);
    if (name.empty()){cout << "Name cannot be empty.\n";return;}

    cout << "Enter Phone: ";getline(cin, phone);
    if (phone.empty()){cout << "Phone cannot be empty.\n";return;}

    cout << "Enter Base Salary: ";cin >> salary;
    if (salary < 0){cout << "Base Salary cannot be negative.\n";return;}

    cout << "Enter Shift Hours: ";
    cin >> shiftHours;

    cout << "Enter Department ID: ";
    cin >> departmentId;

    if (!departmentExists(departmentId))
    {
        cout << "Department does not exist.\n";
        return;
    }

    nurses.push_back(Nurse(id, name, salary, shiftHours, phone, departmentId));

    findDepartmentById(departmentId)->addNurse(id);

    cout << "Nurse added successfully.\n";
}

void Hospital::searchNurse()
{
    int id;
    cout << "Enter Nurse ID: ";
    cin >> id;

    Nurse *nurse = findNurseById(id);
    if (nurse == nullptr)
    {
        cout << "Nurse not found.\n";
        return;
    }

    nurse->display();
}

void Hospital::editNurse()
{
    int id;
    cout << "Enter Nurse ID: ";
    cin >> id;

    Nurse *nurse = findNurseById(id);
    if (nurse == nullptr)
    {
        cout << "Nurse not found.\n";
        return;
    }

    string name, phone;
    double salary;
    int shiftHours;
    int departmentId;

    cin.ignore();

    cout << "Enter New Name: ";
    getline(cin, name);

    cout << "Enter New Phone: ";
    getline(cin, phone);

    cout << "Enter New Base Salary: ";
    cin >> salary;

    cout << "Enter New Shift Hours: ";
    cin >> shiftHours;

    cout << "Enter New Department ID: ";
    cin >> departmentId;

    if (!departmentExists(departmentId))
    {
        cout << "Department does not exist.\n";
        return;
    }

    nurse->setName(name);
    nurse->setPhone(phone);
    nurse->setBaseSalary(salary);
    nurse->setShiftHours(shiftHours);
    nurse->setDepartmentId(departmentId);

    cout << "Nurse updated successfully.\n";
}

void Hospital::deleteNurse()
{
    int id;
    cout << "Enter Nurse ID: ";
    cin >> id;

    for (auto it = nurses.begin(); it != nurses.end(); ++it)
    {
        if (it->getId() == id)
        {
            nurses.erase(it);
            cout << "Nurse deleted successfully.\n";
            return;
        }
    }
    cout << "Nurse not found.\n";
}

void Hospital::displayNurses()
{
    if (nurses.empty())
    {
        cout << "No nurses found.\n";
        return;
    }
    for (const Nurse &n : nurses)
        n.display();
}

// Room Management

void Hospital::addRoom()
{
    int id;
    string type, number;

    cout << "Enter Room ID: ";
    cin >> id;

    if (roomExists(id))
    {
        cout << "Room ID already exists.\n";
        return;
    }

    cin.ignore();

    cout << "Enter Room Type: ";
    getline(cin, type);

    cout << "Enter Room Number: ";
    getline(cin, number);

    rooms.push_back(Room(id, type, number, false, -1));

    cout << "Room added successfully.\n";
}

void Hospital::displayRooms()
{
    if (rooms.empty())
    {
        cout << "No rooms found.\n";
        return;
    }
    for (const Room &r : rooms)
        r.display();
}

void Hospital::assignPatientToRoom()
{
    int roomId, patientId;

    cout << "Enter Room ID: ";
    cin >> roomId;

    Room *room = findRoomById(roomId);
    if (room == nullptr)
    {
        cout << "Room not found.\n";
        return;
    }

    cout << "Enter Patient ID: ";
    cin >> patientId;

    if (!patientExists(patientId))
    {
        cout << "Patient not found.\n";
        return;
    }

    if (!room->assignPatient(patientId))
    {
        cout << "Room is already occupied.\n";
        return;
    }

    cout << "Room assigned successfully.\n";
}

void Hospital::releasePatientFromRoom()
{
    int roomId;
    cout << "Enter Room ID: ";
    cin >> roomId;

    Room *room = findRoomById(roomId);
    if (room == nullptr)
    {
        cout << "Room not found.\n";
        return;
    }

    if (!room->releasePatient())
    {
        cout << "Room is already available.\n";
        return;
    }

    cout << "Room released successfully.\n";
}

// Department Management

void Hospital::addDepartment()
{
    int id;
    string name;

    cout << "Enter Department ID: ";
    cin >> id;

    if (departmentExists(id))
    {
        cout << "Department ID already exists.\n";
        return;
    }

    cin.ignore();

    cout << "Enter Department Name: ";
    getline(cin, name);

    departments.push_back(Department(id, name));

    cout << "Department added successfully.\n";
}

void Hospital::displayDepartments()
{
    if (departments.empty())
    {
        cout << "No departments found.\n";
        return;
    }
    for (const Department &d : departments)
        d.display();
}

void Hospital::assignDoctorToDepartment()
{
    int doctorId, departmentId;

    cout << "Enter Doctor ID: ";
    cin >> doctorId;

    Doctor *doctor = findDoctorById(doctorId);
    if (doctor == nullptr)
    {
        cout << "Doctor not found.\n";
        return;
    }

    cout << "Enter Department ID: ";
    cin >> departmentId;

    Department *department = findDepartmentById(departmentId);
    if (department == nullptr)
    {
        cout << "Department not found.\n";
        return;
    }

    doctor->setDepartmentId(departmentId);
    department->addDoctor(doctorId);

    cout << "Doctor assigned successfully.\n";
}

void Hospital::assignNurseToDepartment()
{
    int nurseId, departmentId;

    cout << "Enter Nurse ID: ";
    cin >> nurseId;

    Nurse *nurse = findNurseById(nurseId);
    if (nurse == nullptr)
    {
        cout << "Nurse not found.\n";
        return;
    }

    cout << "Enter Department ID: ";
    cin >> departmentId;

    Department *department = findDepartmentById(departmentId);
    if (department == nullptr)
    {
        cout << "Department not found.\n";
        return;
    }

    nurse->setDepartmentId(departmentId);
    department->addNurse(nurseId);

    cout << "Nurse assigned successfully.\n";
}

// Appointment Management

bool Hospital::isDoctorAvailable(int doctorId, string date, string time) const
{
    Doctor *doctor = const_cast<Hospital *>(this)->findDoctorById(doctorId);

    if (doctor == nullptr)
        return false;

    if (!doctor->isAvailable())
        return false;

    for (const Appointment &a : appointments)
    {
        if (a.getDoctorID() == doctorId &&
            a.getAppointmentDate() == date &&
            a.getAppointmentTime() == time &&
            a.getAppointmentStatus() == "Scheduled")
        {
            return false;
        }
    }

    return true;
}

void Hospital::bookAppointment()
{
    int appointmentId, patientId, doctorId;
    string date, time;

    cout << "Enter Appointment ID: ";
    cin >> appointmentId;

    cout << "Enter Patient ID: ";
    cin >> patientId;

    if (!patientExists(patientId))
    {
        cout << "Patient not found.\n";
        return;
    }

    cout << "Enter Doctor ID: ";
    cin >> doctorId;

    if (!doctorExists(doctorId))
    {
        cout << "Doctor not found.\n";
        return;
    }

    cout << "Enter Date: ";
    cin >> date;

    cout << "Enter Time: ";
    cin >> time;

    if (!isDoctorAvailable(doctorId, date, time))
    {
        cout << "Doctor is not available at this time.\n";
        return;
    }

    appointments.push_back(Appointment(appointmentId, patientId, doctorId, date, time, "Scheduled"));

    cout << "Appointment booked successfully.\n";
}

void Hospital::cancelAppointment()
{
    int id;
    cout << "Enter Appointment ID: ";
    cin >> id;

    for (Appointment &a : appointments)
    {
        if (a.getAppointmentID() == id)
        {
            if (a.getAppointmentStatus() == "Cancelled")
            {
                cout << "Appointment already cancelled.\n";
                return;
            }
            a.cancelAppointment();
            cout << "Appointment cancelled successfully.\n";
            return;
        }
    }
    cout << "Appointment not found.\n";
}

void Hospital::rescheduleAppointment()
{
    int id;
    cout << "Enter Appointment ID: ";
    cin >> id;

    for (Appointment &a : appointments)
    {
        if (a.getAppointmentID() == id)
        {
            if (a.getAppointmentStatus() == "Cancelled")
            {
                cout << "Cannot reschedule cancelled appointment.\n";
                return;
            }

            string date, time;

            cout << "Enter New Date: ";
            cin >> date;

            cout << "Enter New Time: ";
            cin >> time;

            if (!isDoctorAvailable(a.getDoctorID(), date, time))
            {
                cout << "Doctor is not available.\n";
                return;
            }

            a.setAppointmentDate(date);
            a.setAppointmentTime(time);

            cout << "Appointment rescheduled successfully.\n";
            return;
        }
    }
    cout << "Appointment not found.\n";
}

void Hospital::displayAppointments()
{
    if (appointments.empty())
    {
        cout << "No appointments found.\n";
        return;
    }
    for (const Appointment &a : appointments)
        a.display();
}

// Waiting Queue

void Hospital::addTreatmentToQueue()
{
    int patientId, departmentId;

    cout << "Enter Patient ID: ";
    cin >> patientId;

    if (!patientExists(patientId))
    {
        cout << "Patient not found.\n";
        return;
    }

    cout << "Enter Department ID: ";
    cin >> departmentId;

    Department *department = findDepartmentById(departmentId);
    if (department == nullptr)
    {
        cout << "Department not found.\n";
        return;
    }

    department->addPatientToQueue(patientId);

    cout << "Patient added to waiting queue.\n";
}

void Hospital::serveNextPatient()
{
    int departmentId;
    cout << "Enter Department ID: ";
    cin >> departmentId;

    Department *department = findDepartmentById(departmentId);
    if (department == nullptr)
    {
        cout << "Department not found.\n";
        return;
    }

    if (!department->hasWaitingPatients())
    {
        cout << "No patients in queue.\n";
        return;
    }

    int patientId = department->getNextPatientFromQueue();

    cout << "Now serving Patient ID: " << patientId << endl;
}

void Hospital::displayTreatmentQueue() const
{
    int departmentId;
    cout << "Enter Department ID: ";
    cin >> departmentId;

    Department *department = const_cast<Hospital *>(this)->findDepartmentById(departmentId);
    if (department == nullptr)
    {
        cout << "Department not found.\n";
        return;
    }

    department->display();
}

// Treatment Management

void Hospital::addTreatment()
{
    int id, patientId;
    string description;
    double cost;

    cout << "Enter Treatment ID: ";
    cin >> id;

    cout << "Enter Patient ID: ";
    cin >> patientId;

    if (!patientExists(patientId))
    {
        cout << "Patient not found.\n";
        return;
    }

    cin.ignore();

    cout << "Enter Treatment Description: ";
    getline(cin, description);

    cout << "Enter Cost: ";
    cin >> cost;

    treatments.push_back(Treatment(id, patientId, description, cost));

    cout << "Treatment added successfully.\n";
}

void Hospital::displayTreatments() const
{
    if (treatments.empty())
    {
        cout << "No treatments found.\n";
        return;
    }
    for (const Treatment &t : treatments)
        t.display();
}

// Billing

void Hospital::generateBill()
{
    int id, patientId;
    double doctorFee, roomFee, treatmentFee, medicineFee;

    cout << "Enter Bill ID: ";cin >> id;
    if (id < 0){cout << "\n\"Bill ID cannot be negative.\"\n";return;}

    cout << "Enter Patient ID: ";cin >> patientId;
    if (patientId < 0){cout << "\n\"Patient ID cannot be negative.\"\n";return;}

    if (!patientExists(patientId)){return;}

    cout << "Doctor Fee: ";cin >> doctorFee;
    if (doctorFee < 0){cout << "\n\"Doctor Fee cannot be negative.\"\n";return;}
    
    cout << "Room Fee: ";cin >> roomFee;
    if (roomFee < 0){cout << "\n\"Room Fee cannot be negative.\"\n";return;}

    cout << "Treatment Fee: ";cin >> treatmentFee;
    if (treatmentFee < 0){cout << "\n\"Treatment Fee cannot be negative.\"\n";return;}

    cout << "Medicine Fee: ";cin >> medicineFee;
    if (medicineFee < 0){cout << "\n\"Medicine Fee cannot be negative.\"\n";return;}

    double total = doctorFee + roomFee + treatmentFee + medicineFee;
    bills.push_back(Bill(id, patientId, doctorFee, roomFee, treatmentFee, medicineFee, total));

    cout << "\n\"Bill generated successfully.\"\n";
}

void Hospital::displayBills() const
{
    if (bills.empty())
    {
        cout << "No bills found.\n";
        return;
    }
    for (const Bill &b : bills)
        b.display();
}

// Menus

void Hospital::patientMenu()
{
    int choice;
    do
    {
        cout << "\n========== PATIENT MENU ==========\n";
        cout << "1. Add Patient\n";
        cout << "2. Search Patient\n";
        cout << "3. Edit Patient\n";
        cout << "4. Delete Patient\n";
        cout << "5. Display Patients\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addPatient();
            break;
        case 2:
            searchPatient();
            break;
        case 3:
            editPatient();
            break;
        case 4:
            deletePatient();
            break;
        case 5:
            displayPatients();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void Hospital::doctorMenu()
{
    int choice;
    do
    {
        cout << "\n========== DOCTOR MENU ==========\n";
        cout << "1. Add Doctor\n";
        cout << "2. Search Doctor\n";
        cout << "3. Edit Doctor\n";
        cout << "4. Delete Doctor\n";
        cout << "5. Display Doctors\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addDoctor();
            break;
        case 2:
            searchDoctor();
            break;
        case 3:
            editDoctor();
            break;
        case 4:
            deleteDoctor();
            break;
        case 5:
            displayDoctors();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void Hospital::nurseMenu()
{
    int choice;
    do
    {
        cout << "\n========== NURSE MENU ==========\n";
        cout << "1. Add Nurse\n";
        cout << "2. Search Nurse\n";
        cout << "3. Edit Nurse\n";
        cout << "4. Delete Nurse\n";
        cout << "5. Display Nurses\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addNurse();
            break;
        case 2:
            searchNurse();
            break;
        case 3:
            editNurse();
            break;
        case 4:
            deleteNurse();
            break;
        case 5:
            displayNurses();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void Hospital::roomMenu()
{
    int choice;
    do
    {
        cout << "\n========== ROOM MENU ==========\n";
        cout << "1. Add Room\n";
        cout << "2. Display Rooms\n";
        cout << "3. Assign Room\n";
        cout << "4. Release Room\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addRoom();
            break;
        case 2:
            displayRooms();
            break;
        case 3:
            assignPatientToRoom();
            break;
        case 4:
            releasePatientFromRoom();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void Hospital::departmentMenu()
{
    int choice;
    do
    {
        cout << "\n========== DEPARTMENT MENU ==========\n";
        cout << "1. Add Department\n";
        cout << "2. Display Departments\n";
        cout << "3. Assign Doctor\n";
        cout << "4. Assign Nurse\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addDepartment();
            break;
        case 2:
            displayDepartments();
            break;
        case 3:
            assignDoctorToDepartment();
            break;
        case 4:
            assignNurseToDepartment();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void Hospital::appointmentMenu()
{
    int choice;
    do
    {
        cout << "\n========== APPOINTMENT MENU ==========\n";
        cout << "1. Book Appointment\n";
        cout << "2. Cancel Appointment\n";
        cout << "3. Reschedule Appointment\n";
        cout << "4. Display Appointments\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bookAppointment();
            break;
        case 2:
            cancelAppointment();
            break;
        case 3:
            rescheduleAppointment();
            break;
        case 4:
            displayAppointments();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void Hospital::QueryMenu()
{
    int choice;
    do
    {
        cout << "\n========== WAITING QUEUE ==========\n";
        cout << "1. Add Patient To Queue\n";
        cout << "2. Serve Next Patient\n";
        cout << "3. Display Queue\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTreatmentToQueue();
            break;
        case 2:
            serveNextPatient();
            break;
        case 3:
            displayTreatmentQueue();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void Hospital::treatmentMenu()
{
    int choice;
    do
    {
        cout << "\n========== TREATMENT MENU ==========\n";
        cout << "1. Add Treatment\n";
        cout << "2. Display Treatments\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTreatment();
            break;
        case 2:
            displayTreatments();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void Hospital::billingMenu()
{
    int choice;
    do
    {
        cout << "\n========== BILLING MENU ==========\n";
        cout << "1. Generate Bill\n";
        cout << "2. Display Bills\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            generateBill();
            break;
        case 2:
            displayBills();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

// Main Run

void Hospital::run()
{
    int choice;
    do
    {
        cout << "\n\n";
        cout << "========================================\n";
        cout << "       HOSPITAL MANAGEMENT SYSTEM\n";
        cout << "========================================\n";

        cout << "1. Patient Management\n";
        cout << "2. Doctor Management\n";
        cout << "3. Nurse Management\n";
        cout << "4. Room Management\n";
        cout << "5. Department Management\n";
        cout << "6. Appointment Management\n";
        cout << "7. Waiting Queue\n";
        cout << "8. Treatment Management\n";
        cout << "9. Billing\n";
        cout << "0. Exit\n";

        cout << "========================================\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            patientMenu();
            break;
        case 2:
            doctorMenu();
            break;
        case 3:
            nurseMenu();
            break;
        case 4:
            roomMenu();
            break;
        case 5:
            departmentMenu();
            break;
        case 6:
            appointmentMenu();
            break;
        case 7:
            QueryMenu();
            break;
        case 8:
            treatmentMenu();
            break;
        case 9:
            billingMenu();
            break;
        case 0:
            cout << "Thank you for using the system.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}
