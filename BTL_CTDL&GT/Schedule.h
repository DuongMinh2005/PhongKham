#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include "Appointment.h" 
#include "Patient.h"
#include "Doctor.h"
using namespace std;
struct Appointment;
struct AppointmentNode;
struct Patient;
struct Doctor;
struct Schedule{
    int scheduleID;
    string date;
    string time;
    Patient* patient;
    Doctor* doctor;
    Appointment* appointment;
};

struct ScheduleNode{
    Schedule schedule_info;
    ScheduleNode* next;
};
typedef ScheduleNode* SDNode;
typedef ScheduleNode* LinkedListSchedule;

    ScheduleNode* initScheduleList();
    void addSchedule(ScheduleNode*& head,AppointmentNode*& appointmentList,int appointmentID, Doctor* doctor, string date, string time);  
    void deleteSchedule(ScheduleNode*& head, int id);
    // Kiểm tra lịch khám có hợp lệ không
    bool isScheduleValid(ScheduleNode*& head, AppointmentNode* appointment,Doctor* doctor, string date, string time);
    bool isTimeInRange(string time, string range);
    void displaySchedules(ScheduleNode* head);
#endif // SCHEDULE_H
