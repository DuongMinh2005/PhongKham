#include <iostream>
#include <iomanip>
#include <string>



struct Bill {
    int id;               
    int patientId;        
    std::string patientName;  
    std::string doctorName;  
    std::string date;        
    std::string medication;
    double amount;         
    Bill* next;           
};



void addBill(Bill*& billList, int id, int patientId, const std::string& patientName,
    const std::string& doctorName, const std::string& date,
    const std::string& medication, double amount) {
    Bill* newBill = new Bill{ id, patientId, patientName, doctorName, date, medication, amount, nullptr };
    if (!billList) {
        billList = newBill;
    }
    else {
        Bill* temp = billList;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBill;
    }
}




void displayBills(Bill* billList) {
    if (!billList) {
        std::cout << "Không có hóa đơn nào trong hệ thống.\n";
        return;
    }

    // Tiêu đề bảng
    std::cout << std::left
        << std::setw(5) << "ID"
        << std::setw(15) << "Tên BN"
        << std::setw(15) << "Tên BS"
        << std::setw(10) << "Ngày"
        << std::setw(20) << "Thuốc"
        << std::setw(15) << "Tổng Tiền (VND)"
        << "\n";
    std::cout << std::string(80, '-') << "\n";

    // In danh sách hóa đơn
    Bill* temp = billList;
    while (temp) {
        std::cout << std::left
            << std::setw(5) << temp->id
            << std::setw(15) << temp->patientName
            << std::setw(15) << temp->doctorName
            << std::setw(10) << temp->date
            << std::setw(20) << temp->medication
            << std::setw(15) << std::fixed << std::setprecision(2) << temp->amount
            << "\n";
        temp = temp->next;
    }
}


Bill* searchBill(Bill* billList, int id) {
    Bill* temp = billList;
    while (temp) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}



void deleteBill(Bill*& billList, int id) {
    if (!billList) {
        std::cout << "Danh sach hoa don trong.\n";
        return;
    }

    if (billList->id == id) {
        Bill* toDelete = billList;
        billList = billList->next;
        delete toDelete;
        std::cout << "Hoa don voi ID " << id << " da duoc xoa.\n";
        return;
    }

    Bill* temp = billList;
    while (temp->next && temp->next->id != id) {
        temp = temp->next;
    }

    if (temp->next) {
        Bill* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        std::cout << "Hoa don voi ID " << id << " da duoc xoa.\n";
    }
    else {
        std::cout << "Khong tim thay hoa don voi ID " << id << ".\n";
    }
}


double calculateTotalAmount(Bill* billList) {
    double total = 0;
    Bill* temp = billList;
    while (temp) {
        total += temp->amount;
        temp = temp->next;
    }
    return total;
}



void billMenu(Bill*& billList) {
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
        std::cin.ignore(); // Xoa ky tu xuong dong con trong bo dem

        switch (choice) {
        case 1: {// Thêm hóa đơn
            int id, patientId;
            std::string date, patientName, doctorName, medication;
            double amount;

            std::cout << "Nhap ID: ";
            std::cin >> id;
            std::cout << "Nhap Ma BN: ";
            std::cin >> patientId;
            std::cin.ignore(); // Loại bỏ ký tự xuống dòng thừa

            std::cout << "Nhap Ten BN: ";
            std::getline(std::cin, patientName);

            std::cout << "Nhap Ten BS: ";
            std::getline(std::cin, doctorName);

            std::cout << "Nhap Ten Thuoc: ";
            std::getline(std::cin, medication);

            std::cout << "Nhap Ngay: ";
            std::getline(std::cin, date);

            std::cout << "Nhap Tong Tien: ";
            std::cin >> amount;

            addBill(billList, id, patientId, patientName, doctorName, date, medication, amount);
            break;
        }
        case 2:// Hiển thị danh sách hóa đơn
            displayBills(billList);
            break;
        case 3: {// Tìm hóa đơn theo id
            int id;
            std::cout << "Nhap ID hoa don can tim: ";
            std::cin >> id;
            Bill* found = searchBill(billList, id);
            if (found) {
                std::cout << "Hoa don tim thay - ID: " << found->id
                    << ", Ma Benh Nhan: " << found->patientId
                    << ", Ten Benh Nhan:" << found->patientName
                    << ", Ten Bac Si:" << found->doctorName
                    << ", Ten Thuoc:" << found->medication
                    << ", Ngay: " << found->date
                    << ", Tong Tien: " << found->amount << " VND\n";
            }
            else {
                std::cout << "Khong tim thay hoa don voi ID " << id << ".\n";
            }
            break;
        }
        case 4: {// Xóa hóa đơn theo id
            int id;
            std::cout << "Nhap ID hoa don can xoa: ";
            std::cin >> id;
            deleteBill(billList, id);
            break;
        }
        case 5:// Tính tổng tiền
            std::cout << "Tong tien tat ca hoa don: " << calculateTotalAmount(billList) << " VND\n";
            break;
        case 0:// thoát
            std::cout << "Thoat quan li hoa don.\n";
            break;
        default:
            std::cout << "Tuy chon khong hop le. Vui long chon lai hehe.\n";
        }
    } while (choice != 0);
}



int main() {
    Bill* billList = nullptr;

    std::cout << "Nha khoa CR7 chao mung quy khach!\n";
    billMenu(billList);

    return 0;
}
