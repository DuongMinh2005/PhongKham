#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;
#include "Appointment.h"
#include "Schedule.h"

struct Appointment;
struct Patient{
    string username;
    string patientID;
    string name;
    string age;
    string phone;
    Appointment* appointment;
    Schedule* schedule_doctor;
};
struct PatientNode{
    Patient patient_info;
    PatientNode *next;
};

typedef PatientNode* PNodePatient;
typedef PatientNode* LinkedListPatient;

int appointmentIDCounter = 1;
void initPatient(LinkedListPatient &H);

bool EMPTY(LinkedListPatient &H);

PatientNode* createPatientNode(const Patient& data);

bool isExist_doctorID_BS(LinkedListPatient &H, string PatientID);

Patient inputPatientinfo(LinkedListPatient &H);

void insert(LinkedListPatient &H, Patient &t1);

void display(LinkedListPatient &H);
void displayAppointment(LinkedListPatient &H);
#endif // PATIENT_H
