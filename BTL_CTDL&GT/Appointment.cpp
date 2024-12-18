#include "Appointment.h"
#include <iostream>
using namespace std;

// Hàm khởi tạo danh sách
AppointmentNode* initAppointmentList(){
    return NULL;
}

// Hàm thêm lịch hẹn mới
void addAppointment(AppointmentNode*& head, Patient* patient) {
    // Tạo thông tin lịch hẹn mới
    Appointment* newAppointment = new Appointment();
    newAppointment->appointmentID = appointmentIDCounter++;
    newAppointment->patient = patient;

    cout << "Nhap trieu chung cua benh nhan: ";
    cin.ignore();
    getline(cin, newAppointment->symptom);

    cout << "Nhap thoi gian ranh cua benh nhan (dd/mm/yyyy hh:mm): ";
    getline(cin, newAppointment->availableTime);

    cout << "Nhap chuyen khoa yeu cau: ";
    getline(cin, newAppointment->requiredSpecialization);

    // Tạo node mới cho lịch hẹn
    AppointmentNode* newNode = new AppointmentNode();
    newNode->appointment_info = newAppointment;
    newNode->next = nullptr;

    // Thêm node vào cuối danh sách
    if (head == nullptr) {
        head = newNode;
    } else {
        AppointmentNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Lich hen da duoc tao thanh cong!\n";
}
//Hàm tìm lịch hẹn theo id
AppointmentNode* findAppointmentByID(AppointmentNode*& head, int id) {
    AppointmentNode* temp = head;

    // Duyệt qua danh sách liên kết
    while (temp != nullptr) {
        if (temp->appointment_info->appointmentID == id) {
            return temp; // Trả về lịch hẹn nếu tìm thấy
        }
        temp = temp->next;
    }

    return nullptr; // Không tìm thấy
}


// Hàm hiển thị danh sách lịch hẹn
void displayAppointments(AppointmentNode* head) {
    if (head == nullptr) {
        cout << "Danh sach lich hen dang trong.\n";
        return;
    }

    AppointmentNode* temp = head;
    cout << "Danh sach lich hen:\n";
    cout << "------------------------------------------------------------\n";
    while (temp != nullptr) {
        Appointment* app = temp->appointment_info;
        cout << "ID Lich Hen: " << app->appointmentID << "\n";
        cout << "Benh nhan: " << app->patient->name << " (ID: " << app->patient->patientID << ")\n";
        cout << "Trieu chung: " << app->symptom << "\n";
        cout << "Thoi gian ranh: " << app->availableTime << "\n";
        cout << "Chuyen khoa yeu cau: " << app->requiredSpecialization << "\n";
        cout << "------------------------------------------------------------\n";
        temp = temp->next;
    }
}

// Hàm xóa lịch hẹn
void deleteAppointment(AppointmentNode*& head,int id) {
    if (head == nullptr) {
        cout << "Danh sach lich hen dang trong.\n";
        return;
    }

    AppointmentNode* temp = head;
    AppointmentNode* prev = nullptr;

    // Tìm và xóa node có ID tương ứng
    while (temp != nullptr && temp->appointment_info->appointmentID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Khong tim thay lich hen co ID: " << id << "\n";
        return;
    }

    if (prev == nullptr) { // Xóa node đầu tiên
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp->appointment_info;
    delete temp;

    cout << "Lich hen co ID " << id << " da duoc xoa thanh cong!\n";
}
