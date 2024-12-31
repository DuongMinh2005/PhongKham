#include "Bill.h"
#include <iomanip> // Thêm iomanip để định dạng đầu ra

void initBill(BillNode& billList) {
    billList = nullptr;
}

void addBill(BillNode& billList) {
    int billID, patientID, doctorID, medicineID, quantity;
    std::string date;

    // Nhập và kiểm tra tính duy nhất của ID hóa đơn
    while (true) {
        std::cout << "Nhap ID Hoa Don: ";
        std::cin >> billID;
        // Kiểm tra xem ID đã tồn tại chưa
        if (searchBill(billList, billID)) {
            std::cout << "ID Hoa Don da ton tai. Vui long nhap ID khac.\n";
        }
        else {
            break;
        }
    }
    std::cout << "Nhap ID Benh Nhan: ";
    std::cin >> patientID;
    std::cout << "Nhap ID Bac Si: ";
    std::cin >> doctorID;
    std::cin.ignore(); // Xóa ký tự xuống dòng thừa

    std::cout << "Nhap Ngay Lap Hoa Don (dd/mm/yyyy): ";
    std::getline(std::cin, date);

    // Tìm kiếm bệnh nhân và bác sĩ
    PatientNode BN = searchPatient(patientID);
    DoctorNode BS = searchDoctor(doctorID);

    // if (!BN || !BS) {
    //     std::cout << "Khong tim thay Benh Nhan hoac Bac Si.\n";
    //     return;
    // }

    // Tạo danh sách thuốc
    MedicineNode* medicineList = nullptr;
    char addMore;
    double totalAmount = 0;

    do {
        // Tìm kiếm thuốc
        MedicineNode* newMedicine = searchMedicine(medicineList);
        std::cout << "Nhap So Luong Thuoc: ";
        std::cin >> quantity;
        
            // Tính tổng tiền cho loại thuốc này
            totalAmount += newMedicine->data.dongia * quantity;
            // Thêm thuốc vào danh sách thuốc
            if (!medicineList) {
                medicineList = newMedicine;
            }
            else {
                MedicineNode* temp = medicineList;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = newMedicine;
            }

        std::cout << "Them thuoc? (y/n): ";
        std::cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    // Tạo hóa đơn mới
    BillNode newBill = new Node{ {billID, date, totalAmount}, BN, BS, medicineList, nullptr };

    // Thêm hóa đơn vào danh sách
    if (!billList) {
        billList = newBill;
    }
    else {
        BillNode temp = billList;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBill;
    }

    std::cout << "Hoa don da duoc them thanh cong!\n";
}


void displayBills(BillNode billList) {
    if (!billList) {
        std::cout << "Khong co hoa don nao trong he thong.\n";
        return;
    }

    while (billList) {
        std::cout << "\nHoa Don ID: " << billList->bill.id << "\n";
        std::cout << "Ngay Lap: " << billList->bill.date << "\n";
        std::cout << "Ten BN: " << billList->BN.patient_info.name << ", Ten BS: " << billList->BS.doctor_info.name << "\n";
        std::cout << "Danh Sach Thuoc:\n";
        std::cout << std::left
            << std::setw(10) << "ID Thuoc"
            << std::setw(20) << "Ten Thuoc"
            << std::setw(10) << "Don Gia"
            << std::setw(10) << "So Luong"
            << std::setw(10) << "Thanh Tien"
            << "\n";
        MedicineNode* temp = billList->medicines;
        while (temp) {
            double subTotal = temp->data.dongia * temp->data.soluong;
            std::cout << std::left
                << std::setw(10) << temp->data.masothuoc
                << std::setw(20) << temp->data.tenthuoc
                << std::setw(10) << temp->data.dongia
                << std::setw(10) << temp->data.soluong
                << std::setw(10) << subTotal
                << "\n";
            temp = temp->next;
        }
        std::cout << "Tong Tien: " << billList->bill.amount << " VND\n";
        billList = billList->next;
    }
}

BillNode searchBill(BillNode billList, int id) {
    BillNode temp = billList;
    while (temp) {
        if (temp->bill.id == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}


void deleteBill(BillNode& billList, int id) {
    if (!billList) {
        std::cout << "Danh sach hoa don trong.\n";
        return;
    }

    if (billList->bill.id == id) {
        BillNode toDelete = billList;
        billList = billList->next;
        delete toDelete;
        std::cout << "Hoa don voi ID " << id << " da duoc xoa.\n";
        return;
    }

    BillNode temp = billList;
    while (temp->next && temp->next->bill.id != id) {
        temp = temp->next;
    }

    if (temp->next) {
        BillNode toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        std::cout << "Hoa don voi ID " << id << " da duoc xoa.\n";
    }
    else {
        std::cout << "Khong tim thay hoa don voi ID " << id << ".\n";
    }
}

double calculateTotalAmount(BillNode billList) {
    double total = 0;
    BillNode temp = billList;
    while (temp) {
        total += temp->bill.amount;
        temp = temp->next;
    }
    return total;
}

void billMenu(BillNode& billList) {
    int choice;
    do {
        std::cout << "\n===== QUAN LY HOA DON PHONG KHAM =====\n";
        std::cout << "1. Them hoa don moi\n";
        std::cout << "2. Hien thi danh sach hoa don\n";
        std::cout << "3. Tim hoa don theo ID\n";
        std::cout << "4. Xoa hoa don theo ID\n";
        std::cout << "5. Tinh Tong Tien\n";
        std::cout << "0. Thoat\n";
        std::cout << "======================================\n";
        std::cout << "Lua chon cua ban: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            // Patient* BN = new Patient{ 1, "Nguyen Van A", 30 };
            // Doctor* BS = new Doctor{ 1, "Dr. Tran", "Dentist" };
            // Medicine* medicine = new Medicine{ 1, "Paracetamol", 5000, 2 };
            // std::string date = "01/01/2024";
            // double amount = 10000;

            // addBill(billList, BN, BS, date, medicine, amount);
            break;
        }
        case 2:
            displayBills(billList);
            break;
        case 3: {
            // int id;
            // std::cout << "Nhap ID hoa don can tim: ";
            // std::cin >> id;
            // BillNode found = searchBill(billList, id);
            // if (found) {
            //     std::cout << "Hoa don tim thay - ID: " << found->bill.id
            //         << ", Ten Benh Nhan: " << found->BN->name
            //         << ", Ten Bac Si: " << found->BS->name
            //         << ", Thuoc: " << found->medicine->name
            //         << ", Ngay: " << found->bill.date
            //         << ", Tong Tien: " << found->bill.amount << " VND\n";
            // }
            // else {
            //     std::cout << "Khong tim thay hoa don voi ID " << id << ".\n";
            // }
            break;
        }
        case 4: {
            int id;
            std::cout << "Nhap ID hoa don can xoa: ";
            std::cin >> id;
            deleteBill(billList, id);
            break;
        }
        case 5:
            std::cout << "Tong tien tat ca hoa don: " << calculateTotalAmount(billList) << " VND\n";
            break;
        case 0:
            std::cout << "Thoat quan li hoa don.\n";
            break;
        default:
            std::cout << "Tuy chon khong hop le. Vui long chon lai.\n";
        }
    } while (choice != 0);
}

int main() {
    BillNode billList = nullptr;

    std::cout << "Nha khoa CR7 chao mung quy khach!\n";
    billMenu(billList);

    return 0;
}
