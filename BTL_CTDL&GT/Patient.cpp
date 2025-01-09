#include "Patient.h"
#include <iostream>
using namespace std;

void initPatient(LinkedListPatient &H){
    H = NULL;
}

bool EMPTY(LinkedListPatient &H){
    return H == NULL;
}

PatientNode* createPatientNode(const Patient& data){
    PatientNode* newPatientNode = new PatientNode;
    newPatientNode->patient_info = data;
    newPatientNode->next = NULL;
    return newPatientNode;
}

void displayAppointment(LinkedListPatient &H)