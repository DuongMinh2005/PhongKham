#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;
#include "Appointment.h"

struct Appointment;
struct Patient{
    string username;
    string patientID;
    string name;
    string age;
    string phone;
    Appointment* appointment;

};
struct PatientNode{
    Patient *patient_info;
    PatientNode *next;
};

#endif // PATIENT_H
