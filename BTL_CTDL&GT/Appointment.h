#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "Patient.h"
using namespace std;



struct Appointment {
    int appointmentID;                
    string symptom;                   
    string availableTime;             
    string requiredSpecialization;    
    Patient* patient;                 
};

// Node của danh sách lịch hẹn
struct AppointmentNode {
    Appointment appointment_info;    
    AppointmentNode* next;            
};


            
    int appointmentIDCounter;     

    // Hàm khởi tạo danh sách
    AppointmentNode* initAppointmentList();

    // Hàm thêm lịch hẹn mới
    void addAppointment(AppointmentNode*& head, Patient* patient);

    // Hàm hiển thị danh sách lịch hẹn
    void displayAppointments(AppointmentNode* head);

    // Hàm xóa một lịch hẹn theo ID
    void deleteAppointment(AppointmentNode*& head,int id);
    // Hàm tìm lịch hẹn theo ID
    AppointmentNode* findAppointmentByID(AppointmentNode*& head, int id);


#endif // APPOINTMENT_H
