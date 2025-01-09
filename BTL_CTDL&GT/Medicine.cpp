#include <iostream>
#include <string>
#include "Medicine.h"
using namespace std;

// Hàm tạo node mới
MedicineNode* createMedicineNode(const Medicine& data) {
    MedicineNode* temp = new MedicineNode;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

// Thêm thuốc vào danh sách
void AddMedicine(MedicineNode*& head, Medicine duoc) {
    cout << "Ma so thuoc: ";
    cin.ignore();
    getline(cin, duoc.masothuoc);
    cout << "Ten thuoc: ";
    getline(cin, duoc.tenthuoc);
    cout << "Noi san xuat: ";
    getline(cin, duoc.suatxu);
    cout << "Ngay san xuat: ";
    getline(cin, duoc.ngaysanxuat);
    cout << "Han su dung: ";
    getline(cin, duoc.hansudung);
    cout << "Tac dung cua thuoc: ";
    getline(cin, duoc.tacdung);
    cout << "So luong: ";
    cin >> duoc.soluong;
    cin.ignore();
    cout << "Don gia: ";
    cin >> duoc.dongia;

    MedicineNode* temp = createMedicineNode(duoc);
    if (head == nullptr) {
        head = temp;
    } else {
        MedicineNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }
}

// Xóa thuốc khỏi danh sách
void DeleteMedicine(MedicineNode*& head) {
    cout << "Nhap ma so thuoc: ";
    string maso;
    cin.ignore();
    getline(cin, maso);

    MedicineNode* current = head;
    MedicineNode* prev = nullptr;

    while (current != nullptr) {
        if (current->data.masothuoc == maso) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            cout << "Da xoa thuoc." << endl;
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "Khong tim thay thuoc voi ma so: " << maso << endl;
}

// Sửa thông tin thuốc
void FixMedicine(MedicineNode* head) {
    cout << "Nhap ma so thuoc: ";
    string maso;
    cin.ignore();
    getline(cin, maso);

    MedicineNode* current = head;
    while (current != nullptr) {
        if (current->data.masothuoc == maso) {
            cout << "____NHAP THONG TIN MOI____" << endl;
            cin.ignore();
            cout << "Ma so thuoc: ";
            getline(cin, current->data.masothuoc);
            cout << "Ten thuoc: ";
            getline(cin, current->data.tenthuoc);
            cout << "Noi san xuat: ";
            getline(cin, current->data.suatxu);
            cout << "Ngay san xuat: ";
            getline(cin, current->data.ngaysanxuat);
            cout << "Han su dung: ";
            getline(cin, current->data.hansudung);
            cout << "Tac dung: ";
            getline(cin, current->data.tacdung);
            cout << "So luong: ";
            cin >> current->data.soluong;
            cin.ignore();
            cout << "Don gia: ";
            cin >> current->data.dongia;
            cout << "Da sua thong tin thuoc." << endl;
            return;
        }
        current = current->next;
    }

    cout << "Khong tim thay thuoc voi ma so: " << maso << endl;
}

// Tìm kiếm thuốc
MedicineNode* searchMedicine(MedicineNode* head) {
    cout << "Nhap ma so thuoc: ";
    string maso;
    cin.ignore();
    getline(cin, maso);

    MedicineNode* current = head;
    while (current != nullptr) {
        if (current->data.masothuoc == maso) {
            cout << "Ma so thuoc: " << current->data.masothuoc << endl;
            cout << "Ten thuoc: " << current->data.tenthuoc << endl;
            cout << "Noi san xuat: " << current->data.suatxu << endl;
            cout << "Ngay san xuat: " << current->data.ngaysanxuat << endl;
            cout << "Han su dung: " << current->data.hansudung << endl;
            cout << "Tac dung: " << current->data.tacdung << endl;
            cout << "So luong: " << current->data.soluong << endl;
            cout << "Don gia: " << current->data.dongia << endl;
            return current;
        }
        current = current->next;
    }

    cout << "Khong tim thay thuoc voi ma so: " << maso << endl;
    return nullptr
}

// Liệt kê danh sách thuốc
void DisplayMedicine(MedicineNode* head) {
    if (head == nullptr) {
        cout << "Danh sach rong." << endl;
        return;
    }

    MedicineNode* current = head;
    while (current != nullptr) {
        cout << "------------------------------------------------------------\n";
        cout << "Ma so thuoc: " << current->data.masothuoc << endl;
        cout << "Ten thuoc: " << current->data.tenthuoc << endl;
        cout << "Noi san xuat: " << current->data.suatxu << endl;
        cout << "Ngay san xuat: " << current->data.ngaysanxuat << endl;
        cout << "Han su dung: " << current->data.hansudung << endl;
        cout << "Tac dung: " << current->data.tacdung << endl;
        cout << "So luong: " << current->data.soluong << endl;
        cout << "Don gia: " << current->data.dongia << endl;
        current = current->next;
    }
    cout << "------------------------------------------------------------\n";
}

int main() {
    MedicineNode* a;
    Medicine thuoc;
    InitailizeThuoc(a);
    // Test các chức năng
    (a, thuoc);
    AddMedicine(a,thuoc);
    AddMedicine(a,thuoc);
    DeleteMedicine(a);
    DisplayMedicine(a);
    return 0;
}
