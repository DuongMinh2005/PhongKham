#pragma once
#include <iostream>
#include <string>
#include <iomanip>


struct Bill {
    int id;
    std::string date;
    double amount; // Tổng tiền của hóa đơn
};

struct Node {
    Bill bill;
    PatientNode BN; // Bệnh nhân
    DoctorNode BS;  // Bác sĩ
    MedicineNode* medicines; // Danh sách các loại thuốc
    Node* next;
};

typedef Node* BillNode;

// Khai báo các hàm
void initBill(BillNode& billList);

void addBill(BillNode& billList);

void displayBills(BillNode billList);

BillNode searchBill(BillNode billList, int id);

void deleteBill(BillNode& billList, int id);

double calculateTotalAmount(BillNode billList);

void billMenu(BillNode& billList);
