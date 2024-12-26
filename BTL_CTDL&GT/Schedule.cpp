#include "Schedule.h"
#include <iostream>
using namespace std;

// Constructor
ScheduleNode* initScheduleList(){
    return NULL;
}
// Kiểm tra điều kiện hợp lệ cho lịch khám
bool isTimeInRange(string time, string range);
bool isScheduleValid(ScheduleNode*& head, AppointmentNode* appointment, Doctor* doctor, string date, string time) {
    // Kiểm tra chuyên khoa
    if (doctor->specialization != appointment->appointment_info->requiredSpecialization) {
        cout << "Loi: Bac si " << doctor->name 
                << " khong phu hop voi chuyen khoa benh nhan yeu cau!\n";
        return false;
    }

    // Kiểm tra thời gian rảnh của bệnh nhân và bác sĩ
    if (!isTimeInRange(time, appointment->appointment_info->availableTime)) {
        cout << "Loi: Thoi gian kham khong nam trong thoi gian ranh cua benh nhan!\n";
        return false;
    }

    // Kiểm tra trùng lịch
    ScheduleNode* temp = head;
    while (temp != nullptr) {
        if (temp->schedule_info->date == date) {
            if (temp->schedule_info->doctor == doctor && temp->schedule_info->time == time) {
                cout << "Loi: Bac si " << doctor->name 
                        << " da co lich kham vao gio nay!\n";
                return false;
            }
            if (temp->schedule_info->patient == appointment->appointment_info->patient) {
                cout << "Loi: Benh nhan " << appointment->appointment_info->patient->name 
                        << " da co lich kham vao gio nay!\n";
                return false;
            }
        }
        temp = temp->next;
    }
    return true;
}
// Kiểm tra thời gian hợp lệ
bool isTimeInRange(string time, string range) {
    int startHour, startMin, endHour, endMin, checkHour, checkMin;
    sscanf(range.c_str(), "%d:%d - %d:%d", &startHour, &startMin, &endHour, &endMin);
    sscanf(time.c_str(), "%d:%d", &checkHour, &checkMin);

    int startTime = startHour * 60 + startMin;
    int endTime = endHour * 60 + endMin;
    int checkTime = checkHour * 60 + checkMin;

    return (checkTime >= startTime && checkTime <= endTime);
}

// Thêm lịch khám mới
void addSchedule(ScheduleNode*& head, AppointmentNode*& appointmentList,int appointmentID, Doctor* doctor, string date, string time) {
    
    // Tìm lịch hẹn trong danh sách lịch hẹn
    AppointmentNode* appointmentNode = findAppointmentByID(appointmentList,appointmentID);
    if (appointmentNode == nullptr) {
        cout << "Loi: Khong tim thay lich hen co ID " << appointmentID << "!\n";
        return;
    }
    // Tạo thông tin lịch khám mới
    Schedule* newSchedule = new Schedule();
    newSchedule->scheduleID = scheduleIDCounter++;
    newSchedule->doctor = doctor;
    newSchedule->patient = appointmentNode->appointment_info->patient;
    newSchedule->date = date;
    newSchedule->time = time;

    // Thêm bệnh nhân vào danh sách của bác sĩ
    //doctor->addPatient(appointment->patient);

    // Tạo node lịch khám mới
    ScheduleNode* newNode = new ScheduleNode;
    newNode->schedule_info = newSchedule;
    newNode->next = nullptr;

    // Thêm node vào cuối danh sách
    if (head == nullptr) {
        head = newNode;
    } else {
        ScheduleNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Xóa lịch hẹn khỏi danh sách lịch hẹn
    deleteAppointment(appointmentList,appointmentID);

    cout << "Lich kham da duoc tao thanh cong!\n";

}

// Hiển thị danh sách lịch khám
void displaySchedules(ScheduleNode *head ) {
    if (head == nullptr) {
        cout << "Danh sach lich kham dang trong.\n";
        return;
    }

    ScheduleNode* temp = head;
    cout << "\nDanh sach lich kham:\n";
    cout << "------------------------------------------------------------\n";
    while (temp != nullptr) {
        Schedule* sch = temp->schedule_info;
        cout << "ID Lich Kham: " << sch->scheduleID << "\n";
        cout << "Benh nhan: " << sch->appointment->patient->name
             << " (ID: " << sch->appointment->patient->patientID << ")\n";
        cout << "Bac si: " << sch->doctor->name << " (Chuyen khoa: " << sch->doctor->specialization << ")\n";
        cout << "Ngay kham: " << sch->date << " | Gio: " << sch->time << "\n";
        cout << "------------------------------------------------------------\n";
        temp = temp->next;
    }
}

// Xóa lịch khám
void deleteSchedule(ScheduleNode*& head,int id) {
    if (head == nullptr) {
        cout << "Danh sach lich kham dang trong.\n";
        return;
    }

    ScheduleNode* temp = head;
    ScheduleNode* prev = nullptr;

    // Tìm và xóa node có ID tương ứng
    while (temp != nullptr && temp->schedule_info->scheduleID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Khong tim thay lich kham co ID: " << id << "\n";
        return;
    }

    if (prev == nullptr) { // Xóa node đầu tiên
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp->schedule_info;
    delete temp;

    cout << "Lich kham co ID " << id << " da duoc xoa thanh cong!\n";
}
