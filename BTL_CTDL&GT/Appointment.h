#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "Patient.h"
using namespace std;



struct Appointment {
    int appointmentID;                
    string symptom;                   
    string availableTime;               
    Patient* patient;                 
};

// Node của danh sách lịch hẹn
struct AppointmentNode {
    Appointment appointment_info;    
    AppointmentNode* next;            
};
typedef AppointmentNode* APNode;
typedef AppointmentNode* LinkedListAppointment;
    int appointmentIDCounter;     

    // Hàm khởi tạo danh sách
    void initAppointmentList(LinkedListAppointment& head);

    //Hàm kiểm tra danh sách rỗng
    bool isEmpty(LinkedListAppointment& head);
    
    // Hàm thêm lịch hẹn mới
    void addAppointment(LinkedListAppointment& head, Patient* patient);

    // Hàm hiển thị danh sách lịch hẹn
    void displayAppointment(LinkedListAppointment head);

    // Hàm xóa một lịch hẹn theo ID
    void deleteAppointment(LinkedListAppointment& head,int id);
    // Hàm tìm lịch hẹn theo ID
    APNode findAppointmentByID(LinkedListAppointment& head, int id);


#endif // APPOINTMENT_H
