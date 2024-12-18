#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
using namespace std;
#include "Appointment.h" 
struct Appointment;
struct Doctor{
    string username;
    string doctorID;
    string name;
    string age;
    string phone;
    string specialization;
    Appointment* appointment;
};
struct DoctorNode{
    Doctor* doctor_info;
    DoctorNode* next;
    
};
#endif // DOCTOR_H
