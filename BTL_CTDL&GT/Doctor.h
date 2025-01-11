#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
using namespace std;
#include "Appointment.h" 
#include "Schedule.h"

struct Schedule;
struct TimeTable{
    string date;
    string time;
    TimeTable* next;
};
struct Doctor{
    string username;
    string doctorID;
    string name;
    string age;
    string phone;
    string address;
    string experience;
    TimeTable* timetable;
    Schedule* schedule;
};
struct DoctorNode{
    Doctor doctor_info;
    DoctorNode* next;
};

typedef DoctorNode* PNodeDoctor;
typedef DoctorNode* LinkedListDoctor;

void initDoctor(LinkedListDoctor &H);

bool EMPTY(LinkedListDoctor &H);

DoctorNode* createDoctorNode(const Doctor& doctor_info);

bool isExist_doctorID_BS(LinkedListDoctor &H, string doctorID);

Doctor inputDoctorinfo(LinkedListDoctor &H);

void insert(LinkedListDoctor &H, Doctor &t1);

void display(LinkedListDoctor &H);

bool isExistTimeTable(LinkedListDoctor &H, string date, string time);

void insertTimeTale(LinkedListDoctor &doctor, string date, string time);
#endif // DOCTOR_H
