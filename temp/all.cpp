#include <iostream>
#include <iomanip> // Thư viện để định dạng bảng
#include <string>
using namespace std;
struct Patient;
struct PatientNode;

struct Doctor;
struct DoctorNode;

struct Timetable;
struct TimetableNode;

struct Appointment;
struct AppointmentNode;

struct Schedule;
struct ScheduleNode;

struct Bill;
struct BillNode;

struct Medicine;
struct MedicineNode;

struct Appointment {
    int appointmentID;                
    string symptom;                   
    string date;
    string time;             
    Patient* patient;         
    bool isProcessed;        
};
struct AppointmentNode {
    Appointment appointment_info;    
    AppointmentNode* next;            
};
typedef AppointmentNode* APNode;
typedef AppointmentNode* LinkedListAppointment;

struct Schedule{
    int scheduleID;
    string date;
    string time;
    Patient* patient;
    Doctor* doctor;
    Appointment* appointment;
    bool isCompleted;
};

struct ScheduleNode{
    Schedule schedule_info;
    ScheduleNode* next;
};
typedef ScheduleNode* SCNode;
typedef ScheduleNode* LinkedListSchedule;

struct Medicine {
    int medicineID;        
    string name;            
    string unit;            
    string usage;           
    double price;           
    int stockQuantity;      
    string expiryDate; 
};
struct MedicineNode{
    Medicine medicine_info;
    MedicineNode* next;
};
typedef MedicineNode* MDNode;
typedef MedicineNode* LinkedListMedicine;

struct Bill {
    int billID;                
    string date;               
    double consultationFee;  
    LinkedListMedicine medicines; 
    LinkedListMedicine quantities; 
    double totalAmount;      
    bool isPaid;            
    Patient* patient;
};
struct BillNode {
    Bill bill_info;
    BillNode* next;
};
typedef BillNode* BLNode;
typedef BillNode* LinkedListBill;


struct Patient{
    string username;
    string password;
    string patientID;
    string name;
    string age;
    string phone;
    AppointmentNode appointment;
    ScheduleNode schedule;
    BillNode bill;
};
struct PatientNode{
    Patient patient_info;
    PatientNode *next;
};
typedef PatientNode* PTNode;
typedef PatientNode* LinkedListPatient;

struct Timetable{
    string date;
    string time;
    Doctor* doctor;
};
struct TimetableNode{
    Timetable timetable_info;
    TimetableNode* next;
};
typedef TimetableNode* TTNode;
typedef TimetableNode* LinkedListTimetable;

struct Doctor{
    string username;
    string password;
    string doctorID;
    string name;
    string age;
    string phone;
    ScheduleNode schedule;
    TimetableNode timetable;
};
struct DoctorNode{
    Doctor doctor_info;
    DoctorNode* next;
    
};
typedef DoctorNode* DTNode;
typedef DoctorNode* LinkedListDoctor;



//Hàm tạo danh sách
void initPatientList( LinkedListPatient &patientlist){
    patientlist = NULL;
}
void initDoctorList( LinkedListDoctor &doctorlist){
    doctorlist = NULL;
}
void initAppointmentList( LinkedListAppointment &appointmentlist){
    appointmentlist = NULL;
}
void initScheduleList( LinkedListSchedule &schedulelist){
    schedulelist = NULL;
}
void initMedicineList( LinkedListMedicine &medicinelist){
    medicinelist = NULL;
}
void initBillList(LinkedListBill &billlist){
    billlist = NULL;
}
void initTimetableList(LinkedListTimetable &timetablelist){
    timetablelist = NULL;
}

// Hàm kiểm tra danh sách rỗng

bool isEmpty(LinkedListPatient patientlist){
    return patientlist == NULL;
}
bool isEmpty(LinkedListDoctor doctorlist){
    return doctorlist == NULL;
}
bool isEmpty(LinkedListAppointment appointmentlist){
    return appointmentlist == NULL;
}
bool isEmpty(LinkedListSchedule schedulelist){
    return schedulelist == NULL;
}
bool isEmpty(LinkedListMedicine medicinelist){
    return medicinelist == NULL;
}
bool isEmpty(LinkedListBill billlist){
    return billlist == NULL;
}
bool isEmpty(LinkedListTimetable timetablelist){
    return timetablelist == NULL;
}


//Hàm log in
Patient* loginPatient(LinkedListPatient head) {
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    PTNode current = head;
    while (current != nullptr) {
        if (current->patient_info.username == username && current->patient_info.password == password) {
            cout << "Login successful!\n";
            return &(current->patient_info);
        }
        current = current->next;
    }

    cout << "Incorrect username or password.\n";
    return nullptr;
}
Doctor* loginDoctor(LinkedListDoctor head){
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    DTNode current = head;
    while (current != nullptr) {
        if (current->doctor_info.username == username && current->doctor_info.password == password) {
            cout << "Login successful!\n";
            return &(current->doctor_info);
        }
        current = current->next;
    }

    cout << "Incorrect username or password.\n";
    return nullptr;
}
bool loginManager() {
    string username = "1";  // Define a username
    string password = "1";  // Define a password
    string enteredUsername, enteredPassword;

    cout << "Enter username: ";
    cin >> enteredUsername;
    cout << "Enter password: ";
    cin >> enteredPassword;

    // Check if the entered credentials match the stored credentials
    if (enteredUsername == username && enteredPassword == password) {
        cout << "Login successful!\n";
        return true;  // Login successful
    } else {
        cout << "Incorrect username or password.\n";
        return false;  // Login failed
    }
}
//Hàm tìm bệnh nhân theo id
PTNode findPatientByID(LinkedListPatient patientList, const string& patientID) {
    PTNode current = patientList;
    while (current != nullptr) {
        if (current->patient_info.patientID == patientID) {
            return current; // Trả về nút bệnh nhân nếu tìm thấy
        }
        current = current->next;
    }
    return nullptr; // Trả về nullptr nếu không tìm thấy bệnh nhân
}
//hàm tìm bệnh nhân theo tên

Patient* findPatientByName(LinkedListPatient head, const string& name) {
    while (head) {
        if (head->patient_info.name == name) {
            return &head->patient_info;
        }
        head = head->next;
    }
    return nullptr;
}

//Hàm tìm bác sĩ theo id
DTNode findDoctorByID(LinkedListDoctor &doctorlist, const string &doctorID) {
    DTNode doctorNode = doctorlist;

    // Duyệt qua danh sách bác sĩ để tìm bác sĩ theo doctorID
    while (doctorNode != nullptr) {
        if (doctorNode->doctor_info.doctorID == doctorID) {
            return doctorNode;  // Trả về thông tin bác sĩ nếu tìm thấy
        }
        doctorNode = doctorNode->next;
    }

    // Nếu không tìm thấy bác sĩ
    cout << "Doctor with ID " << doctorID << " not found.\n";
    return nullptr;  // Trả về nullptr nếu không tìm thấy
}
//hàm tìm thuốc theo id
MDNode findMedicineByID(LinkedListMedicine medicinelist, int medicineID) {
    MDNode medicineNode = medicinelist;

    // Duyệt qua danh sách để tìm thuốc theo medicineID
    while (medicineNode != nullptr && medicineNode->medicine_info.medicineID != medicineID) {
        medicineNode = medicineNode->next;
    }

    return medicineNode;  // Trả về nút tìm thấy hoặc nullptr nếu không tìm thấy
}
//Hàm tìm lịch hẹn theo id
APNode findAppointmentByID(LinkedListAppointment appointmentlist, int appointmentID) {
    APNode appNode = appointmentlist;

    // Duyệt qua danh sách để tìm lịch hẹn theo appointmentID
    while (appNode != nullptr && appNode->appointment_info.appointmentID != appointmentID) {
        appNode = appNode->next;
    }

    return appNode;  // Trả về nút tìm thấy hoặc nullptr nếu không tìm thấy
}
//Hàm tìm lịch khám theo id
SCNode findScheduleByID(LinkedListSchedule schedulelist, int scheduleID) {
    SCNode scheduleNode = schedulelist;

    // Duyệt qua danh sách để tìm lịch khám theo scheduleID
    while (scheduleNode != nullptr && scheduleNode->schedule_info.scheduleID != scheduleID) {
        scheduleNode = scheduleNode->next;
    }

    return scheduleNode;  // Trả về nút tìm thấy hoặc nullptr nếu không tìm thấy
}
//hàm tìm bill theo id
BLNode findBillByID(LinkedListBill billlist, int billID) {
    BLNode billNode = billlist;

    // Duyệt qua danh sách để tìm bill theo billID
    while (billNode != nullptr && billNode->bill_info.billID != billID) {
        billNode = billNode->next;
    }

    return billNode;  // Trả về nút tìm thấy hoặc nullptr nếu không tìm thấy
}

//Hàm hiển thị thông tin bệnh nhân
void displayPatientInfo(Patient& patient) {
    cout << "---------------------------------------------\n";
    cout << "| " << setw(12) << left << "Patient ID" 
         << "| " << setw(20) << left << "Name" 
         << "| " << setw(5) << left << "Age" 
         << "| " << setw(12) << left << "Phone" 
         << " |\n";
    cout << "---------------------------------------------\n";
    cout << "| " << setw(12) << left << patient.patientID 
         << "| " << setw(20) << left << patient.name 
         << "| " << setw(5) << left << patient.age 
         << "| " << setw(12) << left << patient.phone 
         << " |\n";
    cout << "---------------------------------------------\n";
}
//hàm hiển thị thông tin bác sĩ
void displayDoctorInfo(Doctor& doctor) {
    cout << "------------------------------------------------------------\n";
    cout << "| " << setw(12) << left << "Doctor ID" 
         << "| " << setw(20) << left << "Name" 
         << "| " << setw(5) << left << "Age" 
         << "| " << setw(12) << left << "Phone" 
         << " |\n";
    cout << "------------------------------------------------------------\n";
    cout << "| " << setw(12) << left << doctor.doctorID 
         << "| " << setw(20) << left << doctor.name 
         << "| " << setw(5) << left << doctor.age 
         << "| " << setw(12) << left << doctor.phone 
         << " |\n";
    cout << "------------------------------------------------------------\n";
}
//hàm edit thông tin bệnh nhân
void editPatientInfo(Patient& patient) {
    int choice;
    do {
        cout << "\n--- Edit Patient Information ---\n";
        cout << "1. Edit Name\n";
        cout << "2. Edit Age\n";
        cout << "3. Edit Phone\n";
        cout << "4. Edit Password\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // Xóa bộ nhớ đệm để tránh lỗi nhập liệu

        switch (choice) {
            case 1: {
                cout << "Enter new name: ";
                getline(cin, patient.name);
                cout << "Name updated successfully!\n";
                break;
            }
            case 2: {
                cout << "Enter new age: ";
                cin >> patient.age;
                cout << "Age updated successfully!\n";
                break;
            }
            case 3: {
                cout << "Enter new phone: ";
                cin.ignore();
                getline(cin, patient.phone);
                cout << "Phone updated successfully!\n";
                break;
            }
            case 4: {
                cout << "Enter new password: ";
                cin >> patient.password;
                cout << "Password updated successfully!\n";
                break;
            }
            case 5: {
                cout << "Exiting Edit Information Menu.\n";
                break;
            }
            default: {
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
    } while (choice != 5);
}
//Hàm edit thông tin bác sĩ
void editDoctorInfo(Doctor& doctor) {
    int choice;
    do {
        cout << "\n--- Edit Doctor Information ---\n";
        cout << "1. Edit Name\n";
        cout << "2. Edit Age\n";
        cout << "3. Edit Phone\n";
        cout << "4. Edit Password\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // Xóa bộ nhớ đệm để tránh lỗi nhập liệu

        switch (choice) {
            case 1: {
                cout << "Enter new name: ";
                getline(cin, doctor.name);
                cout << "Name updated successfully!\n";
                break;
            }
            case 2: {
                cout << "Enter new age: ";
                cin >> doctor.age;
                cout << "Age updated successfully!\n";
                break;
            }
            case 3: {
                cout << "Enter new phone: ";
                cin.ignore();
                getline(cin, doctor.phone);
                cout << "Phone updated successfully!\n";
                break;
            }
            case 4: {
                cout << "Enter new password: ";
                cin >> doctor.password;
                cout << "Password updated successfully!\n";
                break;
            }
            case 5: {
                cout << "Exiting Edit Information Menu.\n";
                break;
            }
            default: {
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
    } while (choice != 5);
}
//hàm thêm bệnh nhân vào sau( chỉ thực hiện nhiệm vụ thêm vào cuối danh sách)
void addPatient(LinkedListPatient& head, const string& username, const string& password, const string& patientID, const string& name, const string& age, const string& phone) {
    // Tạo một nút mới cho bệnh nhân
    PTNode newPatientNode = new PatientNode;
    newPatientNode->patient_info = {username, password, patientID, name, age, phone, {}, {}, {}};

    // Đặt con trỏ tiếp theo của nút mới là nullptr
    newPatientNode->next = nullptr;

    // Thêm nút vào cuối danh sách liên kết
    if (head == nullptr) {
        // Nếu danh sách rỗng, nút mới trở thành nút đầu tiên
        head = newPatientNode;
    } else {
        // Duyệt đến cuối danh sách và thêm nút mới
        PTNode temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newPatientNode;
    }
}
//hàm thêm hóa đơn vào sau( chỉ thực hiện nhiệm vụ thêm vào cuối danh sách)
void addBill(LinkedListBill& head, int billID, const string& date, double consultationFee, LinkedListMedicine medicines, LinkedListMedicine quantities, double totalAmount, Patient* patient, bool isPaid = false) {
    // Tạo một nút mới cho hóa đơn
    BLNode newBillNode = new BillNode;
    newBillNode->bill_info = {billID, date, consultationFee, medicines, quantities, totalAmount, isPaid, patient};

    // Đặt con trỏ tiếp theo của nút mới là nullptr
    newBillNode->next = nullptr;

    // Thêm nút vào cuối danh sách liên kết
    if (head == nullptr) {
        // Nếu danh sách rỗng, nút mới trở thành nút đầu tiên
        head = newBillNode;
    } else {
        // Duyệt đến cuối danh sách và thêm nút mới
        BLNode temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newBillNode;
    }
}
//hàm thêm thuốc vào danh sách( chỉ thực hiện nhiệm vụ thêm vào cuối danh sách)
void addMedicine(LinkedListMedicine& head, int medicineID, const string& name, const string& unit, const string& usage, double price, int stockQuantity, const string& expiryDate) {
    // Tạo một nút mới cho thuốc
    MDNode newMedicineNode = new MedicineNode;
    newMedicineNode->medicine_info = {medicineID, name, unit, usage, price, stockQuantity, expiryDate};

    // Đặt con trỏ tiếp theo của nút mới là nullptr
    newMedicineNode->next = nullptr;

    // Thêm nút vào cuối danh sách liên kết
    if (head == nullptr) {
        // Nếu danh sách rỗng, nút mới trở thành nút đầu tiên
        head = newMedicineNode;
    } else {
        // Duyệt đến cuối danh sách và thêm nút mới
        MDNode temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newMedicineNode;
    }
}
//hàm thêm bác sĩ vào sau( chỉ thực hiện nhiệm vụ thêm vào cuối danh sách)
void addDoctor(LinkedListDoctor &head, const string &username, const string &password, const string &doctorID, const string &name, const string &age, const string &phone) {
    // Tạo một nút mới cho bác sĩ
    DTNode newDoctorNode = new DoctorNode;
    newDoctorNode->doctor_info = {username, password, doctorID, name, age, phone, {}, {}};

    // Đặt con trỏ tiếp theo của nút mới là nullptr
    newDoctorNode->next = nullptr;

    // Thêm nút vào cuối danh sách liên kết
    if (head == nullptr) {
        // Nếu danh sách rỗng, nút mới trở thành nút đầu tiên
        head = newDoctorNode;
    } else {
        // Duyệt đến cuối danh sách và thêm nút mới
        DTNode temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newDoctorNode;
    }
}
//hàm thêm 1 lịch hẹn vào sau( chỉ thực hiện nhiệm vụ thêm vào cuối danh sách)
void addAppointment(LinkedListAppointment& head, 
                    int appointmentID, 
                    const string& symptom, 
                    const string& date, 
                    const string& time, 
                    Patient* patient, bool isProcessed = false) {
    // Tạo một nút mới
    APNode newAppointmentNode = new AppointmentNode;
    
    // Gán thông tin cho lịch hẹn
    newAppointmentNode->appointment_info.appointmentID = appointmentID;
    newAppointmentNode->appointment_info.symptom = symptom;
    newAppointmentNode->appointment_info.date = date;
    newAppointmentNode->appointment_info.time = time;
    newAppointmentNode->appointment_info.patient = patient;
    newAppointmentNode->appointment_info.isProcessed = false;

    // Đặt con trỏ tiếp theo của nút mới là nullptr
    newAppointmentNode->next = nullptr;

    // Thêm vào danh sách liên kết
    if (head == nullptr) {
        // Nếu danh sách rỗng, nút mới trở thành nút đầu tiên
        head = newAppointmentNode;
    } else {
        // Thêm vào cuối danh sách
        APNode temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newAppointmentNode;
    }

    cout << "Appointment added successfully!\n";
}
//Hàm thêm timetable vào sau( chỉ thực hiện nhiệm vụ thêm vào cuối danh sách)
void addTimetable(LinkedListTimetable &head, const string &date, const string &time, Doctor *doctor) {
    // Tạo một nút mới cho timetable
    TTNode newTimetableNode = new TimetableNode;
    newTimetableNode->timetable_info = {date, time};
    newTimetableNode->next = nullptr;

    // Thêm nút vào cuối danh sách liên kết
    if (head == nullptr) {
        // Nếu danh sách rỗng, nút mới trở thành nút đầu tiên
        head = newTimetableNode;
    } else {
        // Duyệt đến cuối danh sách và thêm nút mới
        TTNode temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newTimetableNode;
    }
}
//hàm thêm 1 lịch khám vào sau( chỉ thực hiện nhiệm vụ thêm vào cuối danh sách)
void addSchedule(LinkedListSchedule &head, int scheduleID, const string &date, const string &time, Patient *patient, Doctor *doctor, Appointment *appointment, bool isCompleted = false) {
    // Tạo một nút mới cho lịch khám
    SCNode newScheduleNode = new ScheduleNode;
    newScheduleNode->schedule_info = {scheduleID, date, time, patient, doctor, appointment, false};
    newScheduleNode->next = nullptr;

    // Thêm nút vào cuối danh sách liên kết
    if (head == nullptr) {
        // Nếu danh sách rỗng, nút mới trở thành nút đầu tiên
        head = newScheduleNode;
    } else {
        // Duyệt đến cuối danh sách và thêm nút mới
        SCNode temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newScheduleNode;
    }
}
//hàm xoá một lịch hẹn( chỉ thực hiện nhiệm vụ xoá lịch hẹn)
void deleteAppointment(LinkedListAppointment& head, int appointmentID) {
    // Kiểm tra danh sách rỗng
    if (head == nullptr) {
        cout << "The appointment list is empty. Nothing to delete.\n";
        return;
    }

    APNode current = head;
    APNode previous = nullptr;

    // Tìm kiếm lịch hẹn cần xóa
    while (current != nullptr && current->appointment_info.appointmentID != appointmentID) {
        previous = current;
        current = current->next;
    }

    // Kiểm tra nếu không tìm thấy lịch hẹn
    if (current == nullptr) {
        cout << "No appointment found with ID: " << appointmentID << ".\n";
        return;
    }

    // Xóa lịch hẹn
    if (previous == nullptr) {
        // Nếu nút cần xóa là nút đầu tiên
        head = current->next;
    } else {
        // Nếu nút cần xóa ở giữa hoặc cuối
        previous->next = current->next;
    }

    delete current; // Giải phóng bộ nhớ
    cout << "Appointment with ID: " << appointmentID << " has been deleted successfully.\n";
}
//hàm xoá một timetable( chỉ thực hiện nhiệm vụ xoá timetable)
void deleteTimetable(LinkedListTimetable &head, const string &date, const string &time) {
    // Kiểm tra danh sách rỗng
    if (head == nullptr) {
        cout << "The timetable list is empty. Nothing to delete.\n";
        return;
    }

    TTNode current = head;
    TTNode previous = nullptr;

    // Tìm kiếm timetable cần xóa
    while (current != nullptr && current->timetable_info.date != date && current->timetable_info.time != time) {
        previous = current;
        current = current->next;
    }

    // Kiểm tra nếu không tìm thấy timetable
    if (current == nullptr) {
        cout << "No timetable found with Date: " << date << " and Time: " << time << ".\n";
        return;
    }

    // Xóa timetable
    if (previous == nullptr) {
        // Nếu nút cần xóa là nút đầu tiên
        head = current->next;
    } else {
        // Nếu nút cần xóa ở giữa hoặc cuối
        previous->next = current->next;
    }

    delete current; // Giải phóng bộ nhớ
    cout << "Timetable with Date: " << date << " and Time: " << time << " has been deleted successfully.\n";
}
//hàm xoá một lịch khám ( chỉ thực hiện nhiệm vụ xoá lịch khám)
void deleteSchedule(LinkedListSchedule& scheduleList, int scheduleID) {
    ScheduleNode* temp = scheduleList;
    ScheduleNode* prev = nullptr;

    while (temp != nullptr && temp->schedule_info.scheduleID != scheduleID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Schedule not found.\n";
        return;
    }

    if (temp->schedule_info.isCompleted) {
        cout << "Warning: Schedule ID " << scheduleID << " has been completed. Are you sure you want to delete it? (y/n): ";
        char confirm;
        cin >> confirm;
        if (confirm != 'y' && confirm != 'Y') {
            cout << "Deletion cancelled.\n";
            return;
        }
    }

    if (prev == nullptr) {
        scheduleList = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Schedule ID " << scheduleID << " deleted successfully.\n";
}

//Hàm xóa bệnh nhân theo id
void deletePatient(LinkedListPatient& patientList, const string& patientID) {
    PTNode current = patientList;
    PTNode previous = nullptr;

    while (current != nullptr) {
        if (current->patient_info.patientID == patientID) {
            if (previous == nullptr) {
                patientList = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            cout << "Patient deleted successfully!\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Patient not found!\n";
}
//hàm xoá doctor theo id
void deleteDoctor(LinkedListDoctor &doctorlist, const string &doctorID) {
    DTNode current = doctorlist;
    DTNode previous = nullptr;

    while (current != nullptr) {
        if (current->doctor_info.doctorID == doctorID) {
            if (previous == nullptr) {
                doctorlist = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            cout << "Doctor deleted successfully!\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Doctor not found!\n";
}
//hàm delete bill
void deleteBill(LinkedListBill &billlist, int billID) {
    BLNode current = billlist;
    BLNode previous = nullptr;

    while (current != nullptr) {
        if (current->bill_info.billID == billID) {
            if (previous == nullptr) {
                billlist = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            cout << "Bill deleted successfully!\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Bill not found!\n";
}
//hàm delete medicine
void deleteMedicine(LinkedListMedicine &medicinelist, int medicineID) {
    MDNode current = medicinelist;
    MDNode previous = nullptr;

    while (current != nullptr) {
        if (current->medicine_info.medicineID == medicineID) {
            if (previous == nullptr) {
                medicinelist = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            cout << "Medicine deleted successfully!\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Medicine not found!\n";
}
//hàm hiển thị danh sách bệnh nhân
void viewPatientList(LinkedListPatient patientList) {
    cout << left << setw(10) << "ID" 
         << setw(20) << "Name" 
         << setw(10) << "Age" 
         << setw(15) << "Phone" << endl;
    cout << string(55, '-') << endl;

    PTNode current = patientList;
    while (current != nullptr) {
        cout << left << setw(10) << current->patient_info.patientID
             << setw(20) << current->patient_info.name
             << setw(10) << current->patient_info.age
             << setw(15) << current->patient_info.phone << endl;
        current = current->next;
    }
    cout << string(55, '-') << endl;
}
//hàm hiển thị danh sách thuốc
void viewMedicineList(LinkedListMedicine medicinelist) {
    cout << left << setw(10) << "ID" 
         << setw(20) << "Name" 
         << setw(10) << "Unit" 
         << setw(15) << "Price" 
         << setw(15) << "Stock" 
         << setw(15) << "Expiry Date" << endl;
    cout << string(85, '-') << endl;

    MDNode current = medicinelist;
    while (current != nullptr) {
        cout << left << setw(10) << current->medicine_info.medicineID
             << setw(20) << current->medicine_info.name
             << setw(10) << current->medicine_info.unit
             << setw(15) << current->medicine_info.price
             << setw(15) << current->medicine_info.stockQuantity
             << setw(15) << current->medicine_info.expiryDate << endl;
        current = current->next;
    }
    cout << string(85, '-') << endl;
}
//hàm hiển thị danh sách bác sĩ
void viewDoctorList(LinkedListDoctor doctorList) {
    cout << left << setw(10) << "ID" 
         << setw(20) << "Name" 
         << setw(10) << "Age" 
         << setw(15) << "Phone" << endl;
    cout << string(55, '-') << endl;

    DTNode current = doctorList;
    while (current != nullptr) {
        cout << left << setw(10) << current->doctor_info.doctorID
             << setw(20) << current->doctor_info.name
             << setw(10) << current->doctor_info.age
             << setw(15) << current->doctor_info.phone << endl;
        current = current->next;
    }
    cout << string(55, '-') << endl;
}


//hàm book appointment
void bookAppointment(LinkedListAppointment& head, Patient& patient) {
    int appointmentID;
    string symptom, date, time;

    // Nhập thông tin lịch hẹn
    cout << "Enter Appointment ID: ";
    cin >> appointmentID;

    cout << "Enter Symptom/Reason for Appointment: ";
    cin.ignore(); // Loại bỏ bộ nhớ đệm
    getline(cin, symptom);

    cout << "Enter Appointment Date (dd/mm/yyyy): ";
    cin >> date;

    cout << "Enter Appointment Time (hh:mm): ";
    cin >> time;

    // Gọi hàm addAppointment để thêm lịch hẹn vào danh sách
    addAppointment(head, appointmentID, symptom, date, time, &patient, false);

    cout << "\nAppointment booked successfully for Patient: " 
         << patient.name << " (ID: " << patient.patientID << ")!\n";
    cout << "Appointment ID: " << appointmentID << "\n";
    cout << "Date: " << date << ", Time: " << time << "\n";
    cout << "Symptom/Reason: " << symptom << "\n";
    cout << "Appointment Status: Pending\n";
}

//hàm view all appointment
void viewAllAppointments(LinkedListAppointment head) {
    // Kiểm tra nếu danh sách lịch hẹn rỗng
    if (head == nullptr) {
        cout << "No appointments available.\n";
        return;
    }

    APNode current = head; // Con trỏ duyệt danh sách
    int count = 0;         // Biến đếm số lượng lịch hẹn

    // Tiêu đề bảng
    cout << "\n+-----------------------------------------------------------------------------------------------+\n";
    cout << "| " << setw(5) << "No."
        << " | " << setw(15) << "Appointment ID"
        << " | " << setw(25) << "Symptom/Reason"
        << " | " << setw(12) << "Date"
        << " | " << setw(8) << "Time"
        << " | " << setw(12) << "Patient ID"
        << " | " << setw(10) << "Status"
        << " |\n";
    cout << "+-----------------------------------------------------------------------------------------------+\n";

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        count++;
        cout << "| " << setw(5) << count
            << " | " << setw(15) << current->appointment_info.appointmentID
            << " | " << setw(25) << current->appointment_info.symptom
            << " | " << setw(12) << current->appointment_info.date
            << " | " << setw(8) << current->appointment_info.time
            << " | " << setw(12) << current->appointment_info.patient->patientID
            << " | " << setw(10) << (current->appointment_info.isProcessed ? "Processed" : "Pending")
            << " |\n";
        current = current->next;
    }
    cout << "+-----------------------------------------------------------------------------------------------+\n";
    cout << "\nTotal Appointments: " << count << "\n";
}
//Hàm view appointment by patient
void viewAppointmentsByPatient(LinkedListAppointment head, Patient &patient) {

    // Kiểm tra nếu danh sách lịch hẹn rỗng
    if (head == nullptr) {
        cout << "No appointments available.\n";
        return;
    }

    APNode current = head; // Con trỏ duyệt danh sách
    int count = 0;         // Biến đếm số lượng lịch hẹn của bệnh nhân

    // Tiêu đề bảng
    cout << "\n+-----------------------------------------------------------------------------------------------+\n";
    cout << "| " << setw(5) << "No."
        << " | " << setw(15) << "Appointment ID"
        << " | " << setw(25) << "Symptom/Reason"
        << " | " << setw(12) << "Date"
        << " | " << setw(8) << "Time"
        << " | " << setw(10) << "Status"
        << " |\n";
    cout << "+-----------------------------------------------------------------------------------------------+\n";

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        // Kiểm tra nếu lịch hẹn liên kết với bệnh nhân hiện đang đăng nhập
        if (current->appointment_info.patient->name == patient.name) {
            count++;
            cout << "| " << setw(5) << count
                << " | " << setw(15) << current->appointment_info.appointmentID
                << " | " << setw(25) << current->appointment_info.symptom
                << " | " << setw(12) << current->appointment_info.date
                << " | " << setw(8) << current->appointment_info.time
                << " | " << setw(10) << (current->appointment_info.isProcessed ? "Processed" : "Pending")
                << " |\n";
        }
        current = current->next;
    }
    cout << "+-------------------------------------------------------------------------------------+\n";

    // Thông báo nếu bệnh nhân không có lịch hẹn
    if (count == 0) {
        cout << "No appointments found for the logged-in patient.\n";
    } else {
        cout << "\nTotal Appointments for Logged-In Patient: " << count << "\n";
    }
}
//hàm view bill by patient
void viewBillsByPatient(LinkedListBill head, Patient &patient) {
    // Kiểm tra nếu danh sách hóa đơn rỗng
    if (head == nullptr) {
        cout << "No bills available.\n";
        return;
    }

    BLNode current = head; // Con trỏ duyệt danh sách
    int count = 0;         // Biến đếm số lượng hóa đơn của bệnh nhân

    // Tiêu đề bảng
    cout << "\n+--------------------------------------------------------------------------------------------------+\n";
    cout << "| " << setw(5) << "No."
         << " | " << setw(10) << "Bill ID"
         << " | " << setw(12) << "Date"
         << " | " << setw(15) << "Consultation Fee"
         << " | " << setw(15) << "Total Amount"
         << " | " << setw(10) << "Status"
         << " |\n";
    cout << "+--------------------------------------------------------------------------------------------------+\n";

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        // Kiểm tra nếu hóa đơn liên kết với bệnh nhân hiện đang đăng nhập
        if (current->bill_info.patient->name == patient.name) {
            count++;
            cout << "| " << setw(5) << count
                 << " | " << setw(10) << current->bill_info.billID
                 << " | " << setw(12) << current->bill_info.date
                 << " | " << setw(15) << current->bill_info.consultationFee
                 << " | " << setw(15) << current->bill_info.totalAmount
                 << " | " << setw(10) << (current->bill_info.isPaid ? "Paid" : "Pending")
                 << " |\n";
        }
        current = current->next;
    }

    // Kết thúc bảng
    cout << "+--------------------------------------------------------------------------------------------------+\n";

    // Thông báo nếu bệnh nhân không có hóa đơn
    if (count == 0) {
        cout << "No bills found for the logged-in patient.\n";
    } else {
        cout << "\nTotal Bills for Logged-In Patient: " << count << "\n";
    }
}
//hàm view schedule by patient
void viewSchedulesByPatient(LinkedListSchedule head, const Patient& patient) {
    // Kiểm tra nếu danh sách lịch khám rỗng
    if (head == nullptr) {
        cout << "No schedules available.\n";
        return;
    }

    ScheduleNode* current = head; // Con trỏ duyệt danh sách
    int count = 0;               // Biến đếm số lượng lịch khám của bệnh nhân

    // Tiêu đề bảng
    cout << "\n+--------------------------------------------------------------------------------------------------+\n";
    cout << "| " << setw(5) << "No."
         << " | " << setw(15) << "Schedule ID"
         << " | " << setw(12) << "Date"
         << " | " << setw(8) << "Time"
         << " | " << setw(12) << "Status"
         << " |\n";
    cout << "+--------------------------------------------------------------------------------------------------+\n";

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        // Kiểm tra nếu lịch khám liên kết với bệnh nhân hiện tại
        if (current->schedule_info.patient == &patient) {
            count++;
            cout << "| " << setw(5) << count
                 << " | " << setw(15) << current->schedule_info.scheduleID
                 << " | " << setw(12) << current->schedule_info.date
                 << " | " << setw(8) << current->schedule_info.time
                 << " | " << setw(12) << (current->schedule_info.isCompleted ? "Completed" : "Pending")
                 << " |\n";
        }
        // Di chuyển tới lịch khám tiếp theo
        current = current->next;
    }

    // Kết thúc bảng
    cout << "+--------------------------------------------------------------------------------------------------+\n";

    // Thông báo nếu bệnh nhân không có lịch khám
    if (count == 0) {
        cout << "No schedules found for the patient.\n";
    } else {
        cout << "\nTotal Schedules for Patient \"" << patient.name << "\": " << count << "\n";
    }
}

//hàm view schedule by doctor
void viewSchedulesByDoctor(LinkedListSchedule head, const Doctor& doctor) {
    // Kiểm tra nếu danh sách lịch khám rỗng
    if (head == nullptr) {
        cout << "No schedules available.\n";
        return;
    }

    ScheduleNode* current = head; // Con trỏ duyệt danh sách
    int count = 0;               // Biến đếm số lượng lịch khám của bác sĩ

    // Tiêu đề bảng
    cout << "\n+---------------------------------------------------------------------------------------------------------+\n";
    cout << "| " << setw(5) << "No."
         << " | " << setw(15) << "Schedule ID"
         << " | " << setw(12) << "Date"
         << " | " << setw(8) << "Time"
         << " | " << setw(12) << "Patient ID"
         << " | " << setw(12) << "Status"
         << " |\n";
    cout << "+---------------------------------------------------------------------------------------------------------+\n";

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        // Kiểm tra nếu lịch khám liên kết với bác sĩ hiện tại
        if (current->schedule_info.doctor == &doctor) {
            count++;
            cout << "| " << setw(5) << count
                 << " | " << setw(15) << current->schedule_info.scheduleID
                 << " | " << setw(12) << current->schedule_info.date
                 << " | " << setw(8) << current->schedule_info.time
                 << " | " << setw(12) << current->schedule_info.patient->patientID
                 << " | " << setw(12) << (current->schedule_info.isCompleted ? "Completed" : "Pending")
                 << " |\n";
        }
        // Di chuyển tới lịch khám tiếp theo
        current = current->next;
    }

    // Kết thúc bảng
    cout << "+---------------------------------------------------------------------------------------------------------+\n";

    // Thông báo nếu bác sĩ không có lịch khám
    if (count == 0) {
        cout << "No schedules found for the doctor.\n";
    } else {
        cout << "\nTotal Schedules for Doctor \"" << doctor.name << "\": " << count << "\n";
    }
}

//Hàm view all timetable
void viewDoctorTimetables(LinkedListTimetable head, Doctor &doctor) {
    // Kiểm tra nếu danh sách timetable rỗng
    if (head == nullptr) {
        cout << "No timetables found for this doctor.\n";
        return;
    }

    TTNode current = head; // Con trỏ duyệt danh sách
    int count = 0;         // Biến đếm số lượng timetable của bác sĩ

    // Tiêu đề bảng
    cout << "\nTimetables for Doctor: " << doctor.name << " (ID: " << doctor.doctorID << ")\n";
    cout << "+----------------------------------+\n";
    cout << "| " << setw(5) << "No."
         << " | " << setw(12) << "Date"
         << " | " << setw(8) << "Time"
         << " |\n";
    cout << "+----------------------------------+\n";

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        // Kiểm tra nếu lịch trình thuộc về bác sĩ
        if (current->timetable_info.doctor->doctorID == doctor.doctorID) {
            count++;
            cout << "| " << setw(5) << count
                 << " | " << setw(12) << current->timetable_info.date
                 << " | " << setw(8) << current->timetable_info.time
                 << " |\n";
        }
        current = current->next;
    }

    // Kết thúc bảng
    cout << "+----------------------------------+\n";

    // Thông báo nếu không có timetable nào cho bác sĩ
    if (count == 0) {
        cout << "No timetables found for this doctor.\n";
    } else {
        cout << "\nTotal Timetables: " << count << "\n";
    }
}
//hàm view patient by doctor
void viewPatientsByDoctor(LinkedListSchedule head, Doctor &doctor) {
    // Kiểm tra nếu danh sách lịch khám rỗng
    if (head == nullptr) {
        cout << "No patients for this doctor.\n";
        return;
    }

    SCNode current = head; // Con trỏ duyệt danh sách
    int count = 0;         // Biến đếm số lượng bệnh nhân của bác sĩ

    // Tiêu đề bảng
    cout << "\nPatients for Doctor: " << doctor.name << " (ID: " << doctor.doctorID << ")\n";
    cout << "+----------------------------------+\n";
    cout << "| " << setw(5) << "No."
         << " | " << setw(12) << "Patient ID"
         << " | " << setw(20) << "Patient Name"
         << " |\n";
    cout << "+----------------------------------+\n";

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        // Kiểm tra nếu lịch khám liên kết với bác sĩ
        if (current->schedule_info.doctor->doctorID == doctor.doctorID) {
            count++;
            cout << "| " << setw(5) << count
                 << " | " << setw(12) << current->schedule_info.patient->patientID
                 << " | " << setw(20) << current->schedule_info.patient->name
                 << " |\n";
        }
        // Di chuyển tới lịch khám tiếp theo
        current = current->next;
    }

    // Kết thúc bảng
    cout << "+----------------------------------+\n";

    // Thông báo nếu bác sĩ không có bệnh nhân
    if (count == 0) {
        cout << "No patients found for this doctor.\n";
    } else {
        cout << "\nTotal Patients: " << count << "\n";
    }
}


//hàm view all schedule
void viewAllSchedules(LinkedListSchedule head) {
    // Kiểm tra nếu danh sách lịch khám rỗng
    if (head == nullptr) {
        cout << "No schedules available.\n";
        return;
    }

    ScheduleNode* current = head; // Con trỏ duyệt danh sách
    int count = 0;               // Biến đếm số lượng lịch khám

    // Tiêu đề bảng
    cout << "\n+----------------------------------------------------------------------------------------------------------------+\n";
    cout << "| " << setw(5) << "No."
         << " | " << setw(15) << "Schedule ID"
         << " | " << setw(12) << "Date"
         << " | " << setw(8) << "Time"
         << " | " << setw(12) << "Patient ID"
         << " | " << setw(12) << "Doctor ID"
         << " | " << setw(12) << "Status"
         << " |\n";
    cout << "+----------------------------------------------------------------------------------------------------------------+\n";

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        count++;
        cout << "| " << setw(5) << count
             << " | " << setw(15) << current->schedule_info.scheduleID
             << " | " << setw(12) << current->schedule_info.date
             << " | " << setw(8) << current->schedule_info.time
             << " | " << setw(12) << current->schedule_info.patient->patientID
             << " | " << setw(12) << current->schedule_info.doctor->doctorID
             << " | " << setw(12) << (current->schedule_info.isCompleted ? "Completed" : "Pending")
             << " |\n";
        current = current->next;
    }

    // Kết thúc bảng
    cout << "+----------------------------------------------------------------------------------------------------------------+\n";
    cout << "\nTotal Schedules: " << count << "\n";
}

//hàm view all bill
void viewAllBills(LinkedListBill head) {
    // Kiểm tra nếu danh sách hóa đơn rỗng
    if (head == nullptr) {
        cout << "No bills available.\n";
        return;
    }

    BLNode current = head; 
    int count = 0;        

    // Tiêu đề bảng
    cout << "\n+--------------------------------------------------------------------------------------------------+\n";
    cout << "| " << setw(5) << "No."
         << " | " << setw(10) << "Bill ID"
         << " | " << setw(12) << "Date"
         << " | " << setw(15) << "Consultation Fee"
         << " | " << setw(15) << "Total Amount"
         << " | " << setw(10) << "Status"
         << " |\n";
    cout << "+--------------------------------------------------------------------------------------------------+\n";

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        count++;
        cout << "| " << setw(5) << count
             << " | " << setw(10) << current->bill_info.billID
             << " | " << setw(12) << current->bill_info.date
             << " | " << setw(15) << current->bill_info.consultationFee
             << " | " << setw(15) << current->bill_info.totalAmount
             << " | " << setw(10) << (current->bill_info.isPaid ? "Paid" : "Pending")
             << " |\n";
        current = current->next;
    }

    // Kết thúc bảng
    cout << "+--------------------------------------------------------------------------------------------------+\n";
    cout << "\nTotal Bills: " << count << "\n";
}
//hàm cancel appointment
void cancelAppointment(LinkedListAppointment& appointmentList, Patient& patient) {
    int appointmentID;
    AppointmentNode* selectedAppointment = nullptr;

    do {
        cout << "Enter the ID of the appointment you want to cancel: ";
        cin >> appointmentID;

        selectedAppointment = findAppointmentByID(appointmentList, appointmentID); // Tìm lịch hẹn

        if (selectedAppointment == nullptr) {
            cout << "No appointment found with ID " << appointmentID << ". Please try again.\n";
        }
    } while (selectedAppointment == nullptr);

    // Nếu tìm thấy lịch hẹn, thực hiện hủy
    deleteAppointment(appointmentList, appointmentID);
    cout << "Appointment with ID " << appointmentID << " has been successfully canceled.\n";
}

//hàm split time
void splitTimeRange(const string& time, string& startTime, string& endTime) {
    size_t dashPos = time.find(" - ");
    if (dashPos != string::npos) {
        startTime = time.substr(0, dashPos);
        endTime = time.substr(dashPos + 3); // Bỏ qua " - "
    } else {
        startTime = "";
        endTime = "";
    }
}
//Hàm tính tổng hóa đơn
double calculateTotalBill(Bill* bill) {
    if (bill == nullptr) {
        cout << "Invalid bill.\n";
        return 0.0;
    }

    double totalMedicineCost = 0.0;

    // Duyệt qua danh sách thuốc trong hóa đơn
    MDNode temp = bill->medicines;
    while (temp != nullptr) {
        double medicineCost = temp->medicine_info.price * temp->medicine_info.stockQuantity;
        totalMedicineCost += medicineCost;
        temp = temp->next;
    }

    // Tổng số tiền hóa đơn = phí khám bệnh + tổng tiền thuốc
    double totalBill = bill->consultationFee + totalMedicineCost;

    // Hiển thị chi tiết
    cout << "Consultation Fee: " << bill->consultationFee << " VND\n";
    cout << "Total Medicine Cost: " << totalMedicineCost << " VND\n";
    cout << "Total Bill Amount: " << totalBill << " VND\n";

    return totalBill;
}

//hàm check time
bool isTimeConflictWithDoctorTimetable(Doctor& doctor, const string& date, const string& time, 
                                       LinkedListTimetable& timetableList) {
    string newStartTime, newEndTime;
    splitTimeRange(time, newStartTime, newEndTime); // Tách thời gian mới nhập vào

    TTNode current = timetableList;
    while (current != nullptr) {
        if (current->timetable_info.doctor == &doctor && current->timetable_info.date == date) {
            string existingTime = current->timetable_info.time;
            string existingStartTime, existingEndTime;

            splitTimeRange(existingTime, existingStartTime, existingEndTime); // Tách thời gian đã lưu

            // Kiểm tra trùng khoảng thời gian
            if (newStartTime < existingEndTime && newEndTime > existingStartTime) {
                return true; // Trùng thời gian
            }
        }
        current = current->next;
    }
    return false; // Không trùng
}

//Hàm tạo lịch khám
void createSchedule(LinkedListSchedule& scheduleList, LinkedListAppointment& appointmentList,
                    LinkedListDoctor& doctorList, LinkedListPatient& patientList,
                    LinkedListTimetable& timetableList) {

    int appointmentID, scheduleID;
    string date, time;
    Doctor* doctor = nullptr;
    Patient* patient = nullptr;

    // Nhập Appointment ID để xử lý
    cout << "Enter Appointment ID to process: ";
    cin >> appointmentID;

    // Tìm lịch hẹn theo appointmentID
    APNode appNode = findAppointmentByID(appointmentList, appointmentID);
    if (appNode == nullptr) {
        cout << "Appointment ID not found.\n";
        return;
    }

    // Lấy thông tin bệnh nhân từ lịch hẹn
    Appointment* appointment = &(appNode->appointment_info);
    patient = appointment->patient;

    if (patient == nullptr) {
        cout << "Patient information is missing in the appointment.\n";
        return;
    }

    // Nhập thông tin lịch khám
    cout << "Enter Schedule ID: ";
    cin >> scheduleID;

    bool timeConflict = false;

    // Hiển thị danh sách bác sĩ
    cout << "Available Doctors:\n";
    viewDoctorList(doctorList);
    do {
        cout << "Enter Date (YYYY-MM-DD): ";
        cin >> date;
        cin.ignore(); // Bỏ qua ký tự xuống dòng còn sót trong bộ đệm
        cout << "Enter Time (HH:MM - HH:MM): ";
        getline(cin, time);
        DTNode doctorNode = nullptr;
        string doctorID;

        do {
            cout << "Enter Doctor ID: ";
            cin >> doctorID;

            // Tìm bác sĩ theo ID
            doctorNode = findDoctorByID(doctorList, doctorID);
            if (doctorNode == nullptr) {
                cout << "Doctor ID not found. Please try again.\n";
            }
        } while (doctorNode == nullptr);
        doctor = &(doctorNode->doctor_info);

        // Kiểm tra trùng thời gian
        timeConflict = isTimeConflictWithDoctorTimetable(*doctor, date, time, timetableList);
        if (timeConflict) {
            cout << "The selected date and time conflict with the doctor's timetable. "
                    "Please choose another time or doctor.\n";
        }
    } while (timeConflict);

    // Tạo một node lịch khám mới
    SCNode newScheduleNode = new ScheduleNode{
        {scheduleID, date, time, patient, doctor, appointment}, nullptr};

    // Thêm lịch khám vào danh sách lịch khám
    if (scheduleList == nullptr) {
        scheduleList = newScheduleNode;
    } else {
        SCNode temp = scheduleList;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newScheduleNode;
    }
    newScheduleNode->next = nullptr;

    // Cập nhật lịch khám cho bệnh nhân
    if (patient->schedule.next == nullptr) {
        patient->schedule.next = newScheduleNode;
    } else {
        SCNode temp = patient->schedule.next;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newScheduleNode;
    }

    // Cập nhật lịch khám cho bác sĩ
    if (doctor->schedule.next == nullptr) {
        doctor->schedule.next = newScheduleNode;
    } else {
        SCNode temp = doctor->schedule.next;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newScheduleNode;
    }

    // Cập nhật trạng thái của lịch hẹn
    appointment->isProcessed = true;

    // Cập nhật Timetable của bác sĩ
    TTNode newTimetableNode = new TimetableNode{
        {date, time, doctor}, nullptr};

    if (timetableList == nullptr) {
        timetableList = newTimetableNode;
    } else {
        TTNode temp = timetableList;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newTimetableNode;
    }

    cout << "Schedule created successfully!\n";
}

//Hàm tạo hóa đơn
void createBill(LinkedListBill& billList, LinkedListMedicine& medicineList, LinkedListPatient& patientList, LinkedListSchedule& scheduleList) {
    Bill newBill;

    // 1. Nhập ID lịch khám
    ScheduleNode* scheduleNode = nullptr;
    while (!scheduleNode) {
        int scheduleID;
        cout << "Enter Schedule ID: ";
        cin >> scheduleID;

        scheduleNode = findScheduleByID(scheduleList, scheduleID);
        if (!scheduleNode) {
            cout << "Schedule not found. Please try again.\n";
        } else if (scheduleNode->schedule_info.isCompleted) {
            cout << "This schedule has already been completed. Cannot create another bill.\n";
            scheduleNode = nullptr;
        }
    }

    // 2. Liên kết lịch khám và bệnh nhân
    newBill.patient = scheduleNode->schedule_info.patient;
    cout << "Creating bill for schedule of patient: " << newBill.patient->name << "\n";

    // 3. Nhập thông tin cơ bản của hóa đơn
    cout << "Enter Bill ID: ";
    cin >> newBill.billID;
    cout << "Enter Date (DD/MM/YYYY): ";
    cin.ignore();
    getline(cin, newBill.date);
    cout << "Enter Consultation Fee: ";
    cin >> newBill.consultationFee;

    // 4. Thêm danh sách thuốc vào hóa đơn
    newBill.medicines = nullptr;
    newBill.quantities = nullptr;
    while (true) {
        cout << "Available Medicines:\n";
        viewMedicineList(medicineList);

        int medicineID, quantity;
        cout << "Enter Medicine ID (or -1 to finish): ";
        cin >> medicineID;
        if (medicineID == -1) break;

        MedicineNode* medicineNode = findMedicineByID(medicineList, medicineID);
        if (!medicineNode) {
            cout << "Medicine not found. Please try again.\n";
            continue;
        }

        cout << "Enter Quantity: ";
        cin >> quantity;
        if (quantity > medicineNode->medicine_info.stockQuantity) {
            cout << "Not enough stock. Available: " << medicineNode->medicine_info.stockQuantity << "\n";
            continue;
        }

        // Cập nhật kho thuốc
        medicineNode->medicine_info.stockQuantity -= quantity;

        // Thêm thuốc và số lượng vào danh sách thuốc của hóa đơn
        addMedicine(newBill.medicines, 
                    medicineNode->medicine_info.medicineID, 
                    medicineNode->medicine_info.name, 
                    medicineNode->medicine_info.unit, 
                    medicineNode->medicine_info.usage, 
                    medicineNode->medicine_info.price, 
                    quantity, 
                    medicineNode->medicine_info.expiryDate);
    }

    // 5. Tính tổng tiền hóa đơn
    newBill.totalAmount = calculateTotalBill(&newBill);

    // 6. Nhập trạng thái thanh toán
    char isPaidInput;
    cout << "Is the bill paid? (y/n): ";
    cin >> isPaidInput;
    newBill.isPaid = (isPaidInput == 'y' || isPaidInput == 'Y');

    // 7. Lưu hóa đơn vào danh sách
    addBill(billList, newBill.billID, newBill.date, newBill.consultationFee, newBill.medicines, newBill.quantities, newBill.totalAmount, newBill.patient, newBill.isPaid);

    // 8. Cập nhật trạng thái lịch khám
    scheduleNode->schedule_info.isCompleted = true;

    // 9. Hiển thị hóa đơn
    cout << "Bill created successfully for schedule ID: " << scheduleNode->schedule_info.scheduleID << "\n";
}

// Hàm tạo bệnh nhân
Patient createPatient(int id) {
    Patient patient;
    patient.username = "patient" + to_string(id);
    patient.password = "password" + to_string(id);
    patient.patientID = "P" + to_string(id);
    patient.name = "Patient Name " + to_string(id);
    patient.age = to_string(20 + id);
    patient.phone = "12345678" + to_string(id);

    // Khởi tạo các thành phần nội tại
    patient.appointment = AppointmentNode(); // Khởi tạo mặc định
    patient.schedule = ScheduleNode();       // Khởi tạo mặc định
    patient.bill = BillNode();               // Khởi tạo mặc định

    return patient;
}

// Hàm tạo cuộc hẹn
// Appointment createAppointment(int id, Patient& patient) {
//     Appointment appointment;
//     appointment.appointmentID = id;
//     appointment.symptom = "Symptom " + to_string(id);
//     appointment.date = "01/01/2025";
//     appointment.time = "10:00 AM";
//     appointment.patient = &patient;
//     appointment.isProcessed = false;
//     return appointment;
// }

// Hàm tạo bác sĩ
Doctor createDoctor(int id) {
    Doctor doctor;
    doctor.username = "doctor" + to_string(id);
    doctor.password = "password" + to_string(id);
    doctor.doctorID = "D" + to_string(id);
    doctor.name = "Doctor Name " + to_string(id);
    doctor.age = to_string(30 + id);
    doctor.phone = "87654321" + to_string(id);

    // Khởi tạo các thành phần nội tại
    doctor.schedule = ScheduleNode();     // Khởi tạo mặc định
    doctor.timetable = TimetableNode();  // Khởi tạo mặc định

    return doctor;
}


// Menu bệnh nhân
void patientMenu(LinkedListPatient& patientList, LinkedListAppointment& appointmentlist, LinkedListSchedule& schedulelist, LinkedListBill& billlist) {
    Patient* loggedinPatient = nullptr;

    // Vòng lặp để đảm bảo đăng nhập thành công trước khi vào menu
    do {
        loggedinPatient = loginPatient(patientList);
        if (!loggedinPatient) {
            cout << "Login failed! Please try again.\n";
        }
    } while (!loggedinPatient);

    int choice;
    do {
        cout << "\n=== Patient Menu ===\n";
        cout << "1. View Information\n";
        cout << "2. Edit Information\n";
        cout << "3. Book Appointment\n";
        cout << "4. View All Appointments\n";
        cout << "5. Cancel Appointment\n";
        cout << "6. View Schedules\n";
        cout << "7. View Bills\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\n--- Patient Information ---\n";
                displayPatientInfo(*loggedinPatient);
                break;
            }
            case 2: {
                cout << "\n--- Edit Information ---\n";
                editPatientInfo(*loggedinPatient);
                break;
            }
            case 3: {
                cout << "\n--- Book Appointment ---\n";
                bookAppointment(appointmentlist, *loggedinPatient);
                break;
            }
            case 4: {
                cout << "\n--- View All Appointments ---\n";
                viewAppointmentsByPatient(appointmentlist, *loggedinPatient);
                break;
            }
            case 5: {
                cout << "\n--- Cancel Appointment ---\n";
                cancelAppointment(appointmentlist, *loggedinPatient);
                break;
            }
            case 6: {
                cout << "\n--- View Schedules ---\n";
                viewSchedulesByPatient(schedulelist, *loggedinPatient);
                break;
            }
            case 7: {
                cout << "\n--- View Bills ---\n";
                viewBillsByPatient(billlist, *loggedinPatient);
                break;
            }
            case 8: {
                cout << "Logged out successfully. Exit menu.\n";
                break;
            }
            default: {
                cout << "Invalid selection. Please try again.\n";
                break;
            }
        }
    } while (choice != 8);
}


// Menu bác sĩ
void doctorMenu(LinkedListDoctor& doctorlist) {
    Doctor* loggedinDoctor = nullptr;

    // Vòng lặp để đảm bảo đăng nhập thành công trước khi vào menu
    do {
        loggedinDoctor = loginDoctor(doctorlist);
        if (!loggedinDoctor) {
            cout << "Login failed! Please try again.\n";
        }
    } while (!loggedinDoctor);
    int choice;
    do {
        cout << "\n=== Doctor Menu ===\n";
        cout << "1. View Information\n";
        cout << "2. Edit Information\n";
        cout << "3. View Timetable\n";
        cout << "4. View Schedule\n";
        cout << "5. View Patients\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "\n--- Doctor Information ---\n";
                displayDoctorInfo(*loggedinDoctor);
                break;
            case 2: 
                cout << "\n--- Edit Information ---\n";
                editDoctorInfo(*loggedinDoctor);
                break;
            case 3:
                cout << "\n--- View Timetable of Doctor ---\n";
                viewDoctorTimetables(loggedinDoctor->timetable.next, *loggedinDoctor);
                break;
            case 4:
                cout << "\n--- View Schedule of Doctor ---\n";
                viewSchedulesByDoctor(loggedinDoctor->schedule.next, *loggedinDoctor);
                break;
            case 5:
                cout << "\n--- View Patients of Doctor ---\n";
                viewPatientsByDoctor(loggedinDoctor->schedule.next, *loggedinDoctor);
                break;
            case 6:
                cout << "Logged out successfully. Exit menu.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);
}

// Menu quản lý
void managePatient(LinkedListPatient &patientlist, LinkedListAppointment &appointmentlist, LinkedListSchedule &schedulelist, LinkedListBill &billlist) {
    int choice;
    do {
        cout << "\nManage Patients:\n";
        cout << "1. View patient list\n";
        cout << "2. Select a patient\n";
        cout << "3. Go back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewPatientList(patientlist);
                break;

            case 2: {
                string patientID;
                PTNode selectedNode = nullptr;

                do {
                    cout << "Enter the patient ID to select: ";
                    cin >> patientID;

                    selectedNode = findPatientByID(patientlist, patientID); // Gọi hàm trả về PTNode

                    if (selectedNode == nullptr) {
                        cout << "No patient found with ID " << patientID << ". Please try again.\n";
                    }
                } while (selectedNode == nullptr);

                // Lấy con trỏ đến thông tin bệnh nhân
                Patient* selectedPatient = &selectedNode->patient_info;
                if (selectedNode != nullptr) {
                     
                    // Bây giờ bạn có thể sử dụng selectedPatient
                        cout << "Selected Patient: " << selectedPatient->name << endl;
                } else {
                    Patient* selectedPatient = NULL;
                        cout << "Patient not found." << endl;
                }

                int subChoice;
                do {
                    cout << "\nSelected Patient: " << selectedPatient->name << "\n";
                    cout << "1. View patient information\n";
                    cout << "2. Edit patient information\n";
                    cout << "3. Delete patient\n";
                    cout << "4. View appointments for this patient\n";
                    cout << "5. View schedules for this patient\n";
                    cout << "6. View bills for this patient\n";
                    cout << "7. Go back\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            displayPatientInfo(*selectedPatient);
                            break;

                        case 2:
                            editPatientInfo(*selectedPatient);
                            break;

                        case 3:
                            deletePatient(patientlist, patientID);
                            subChoice = 7; // Thoát sau khi xóa
                            break;

                        case 4:
                            viewAppointmentsByPatient(appointmentlist,*selectedPatient);
                            break;

                        case 5:
                            viewSchedulesByPatient(schedulelist, *selectedPatient);
                            break;

                        case 6:
                            viewBillsByPatient(billlist, *selectedPatient);
                            break;

                        case 7:
                            cout << "Returning to the patient management menu...\n";
                            break;

                        default:
                            cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                } while (subChoice != 7);
                break;
            }

            case 3:
                cout << "Returning to the main menu...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);

}
void manageDoctor(LinkedListDoctor &doctorlist, LinkedListSchedule &schedulelist, LinkedListTimetable &timetablelist) {
    int choice;
    do {
        cout << "\nManage Doctors:\n";
        cout << "1. View doctor list\n";
        cout << "2. Select a doctor\n";
        cout << "3. Go back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Hiển thị danh sách bác sĩ
                viewDoctorList(doctorlist);
                break;

            case 2: {
                string doctorID;
                DTNode selectedNode = nullptr;

                do {
                    cout << "Enter the doctor ID to select: ";
                    cin >> doctorID;

                    selectedNode = findDoctorByID(doctorlist, doctorID); // Gọi hàm trả về DTNode

                    if (selectedNode == nullptr) {
                        cout << "No doctor found with ID " << doctorID << ". Please try again.\n";
                    }
                } while (selectedNode == nullptr);
                if (selectedNode != nullptr) {
                    Doctor* selectedDoctor = &selectedNode->doctor_info;

                    int subChoice;
                    do {
                        cout << "\nSelected Doctor: " << selectedDoctor->name << "\n";
                        cout << "1. View doctor information\n";
                        cout << "2. Edit doctor information\n";
                        cout << "3. Delete doctor\n";
                        cout << "4. View schedules for this doctor\n";
                        cout << "5. View timetable for this doctor\n";
                        cout << "6. View patients for this doctor\n";
                        cout << "7. Go back\n";
                        cout << "Enter your choice: ";
                        cin >> subChoice;

                        switch (subChoice) {
                            case 1: // Xem thông tin bác sĩ
                                cout << "Doctor Information:\n";
                                displayDoctorInfo(*selectedDoctor);
                                break;

                            case 2: // Sửa thông tin bác sĩ
                                editDoctorInfo(*selectedDoctor);
                                break;

                            case 3: // Xóa bác sĩ
                                deleteDoctor(doctorlist, doctorID);
                                cout << "Doctor deleted successfully.\n";
                                subChoice = 6; // Thoát menu con sau khi xóa
                                break;

                            case 4: // Xem lịch khám của bác sĩ
                                viewSchedulesByDoctor(schedulelist, *selectedDoctor);
                                break;

                            case 5: // Xem thời khóa biểu của bác sĩ
                                viewDoctorTimetables(timetablelist, *selectedDoctor);
                                break;
                            
                            case 6: // Xem danh sách bệnh nhân của bác sĩ
                                viewPatientsByDoctor(schedulelist, *selectedDoctor);
                                break;

                            case 7: // Quay lại menu chính
                                cout << "Returning to the doctor management menu...\n";
                                break;

                            default:
                                cout << "Invalid choice. Please try again.\n";
                                break;
                        }
                    } while (subChoice != 7);

                } else {
                    cout << "Doctor not found. Please try again.\n";
                }
                break;
            }

            case 3: // Quay lại menu chính
                cout << "Returning to the main menu...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

void manageBill(LinkedListBill &billlist, LinkedListMedicine &medicinelist, LinkedListPatient &patientlist, LinkedListSchedule &schedulelist) {
    int choice;
    do {
        cout << "\nBill Management Menu:\n";
        cout << "1. View all bills\n";
        cout << "2. Add a new bill\n";
        cout << "3. Delete a bill\n";
        cout << "4. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewAllBills(billlist);
                break;
            case 2:
                createBill(billlist, medicinelist, patientlist, schedulelist);
                break;
            case 3: {
                int billID;
                BillNode* selectedBill = nullptr;

                do {
                    cout << "Enter the Bill ID to delete: ";
                    cin >> billID;

                    selectedBill = findBillByID(billlist, billID); // Tìm hóa đơn trong danh sách

                    if (selectedBill == nullptr) {
                        cout << "No bill found with ID " << billID << ". Please try again.\n";
                    }
                } while (selectedBill == nullptr);
                deleteBill(billlist, billID);
                break;
            }
            case 4:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}
void manageMedicine(LinkedListMedicine &medicinelist){
    int choice;
    do {
        cout << "\nMedicine Management Menu:\n";
        cout << "1. View all medicines\n";
        cout << "2. Add a new medicine\n";
        cout << "3. Delete a medicine\n";
        cout << "4. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewMedicineList(medicinelist);
                break;
            case 2: {
                int medicineID;
                string name, unit, usage, expiryDate;
                double price;
                int stockQuantity;
                cout << "Enter Medicine ID: ";
                cin >> medicineID;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Unit: ";
                cin >> unit;
                cout << "Enter Usage: ";
                cin.ignore();
                getline(cin, usage);
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Stock Quantity: ";
                cin >> stockQuantity;
                cout << "Enter Expiry Date (YYYY-MM-DD): ";
                cin >> expiryDate;
                addMedicine(medicinelist, medicineID, name, unit, usage, price, stockQuantity, expiryDate);
                break;
            }
            case 3: {
                int medicineID;
                MedicineNode* selectedMedicine = nullptr;

                do {
                    cout << "Enter the Medicine ID to delete: ";
                    cin >> medicineID;

                    selectedMedicine = findMedicineByID(medicinelist, medicineID); // Tìm thuốc

                    if (selectedMedicine == nullptr) {
                        cout << "No medicine found with ID " << medicineID << ". Please try again.\n";
                    }
                } while (selectedMedicine == nullptr);

                deleteMedicine(medicinelist, medicineID);
                break;
            }
            case 4:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}
void manageAppointment(LinkedListAppointment &appointmentlist, LinkedListPatient &patientList) {
    int choice;
    do {
        cout << "\nAppointment Management Menu:\n";
        cout << "1. View all appointments\n";
        cout << "2. Add a new appointment\n";
        cout << "3. Delete an appointment\n";
        cout << "4. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewAllAppointments(appointmentlist);
                break;
            case 2: {
                int appointmentID;
                string symptom, date, time;
                cout << "Enter Appointment ID: ";
                cin >> appointmentID;
                cin.ignore(); // Clear buffer
                
                cout << "Enter Symptom: ";
                getline(cin, symptom);
                
                cout << "Enter Date (YYYY-MM-DD): ";
                cin >> date;
                
                cout << "Enter Time (HH:MM): ";
                cin >> time;

                // Lấy thông tin bệnh nhân
                string patientName, patientID;
                PTNode patientNode = nullptr; // Giả sử PTNode là kiểu struct hoặc class chứa thông tin bệnh nhân

                do {
                    cout << "Enter Patient Name: ";
                    cin.ignore();
                    getline(cin, patientName);
                    
                    cout << "Enter Patient ID: ";
                    cin >> patientID;

                    patientNode = findPatientByID(patientList, patientID);
                    if (patientNode == nullptr) {
                        cout << "Patient not found. Please try again.\n";
                    }
                } while (patientNode == nullptr);

                Patient* patient1 = &patientNode->patient_info;

                addAppointment(appointmentlist, appointmentID, symptom, date, time, patient1, false);
                break;
            }
            case 3: {
                int appointmentID;
                AppointmentNode* selectedAppointment = nullptr;

                do {
                    cout << "Enter the Appointment ID to delete: ";
                    cin >> appointmentID;

                    selectedAppointment = findAppointmentByID(appointmentlist, appointmentID); // Tìm lịch hẹn

                    if (selectedAppointment == nullptr) {
                        cout << "No appointment found with ID " << appointmentID << ". Please try again.\n";
                    }
                } while (selectedAppointment == nullptr);
                deleteAppointment(appointmentlist, appointmentID);
                break;
            }
            case 4:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

}
void manageSchedule(LinkedListSchedule &schedulelist, LinkedListAppointment &appointmentlist, LinkedListDoctor &doctorlist, 
                    LinkedListPatient &patientlist, LinkedListTimetable &timetablelist) {
    int choice;
    do {
        cout << "\nSchedule Management Menu:\n";
        cout << "1. View all schedules\n";
        cout << "2. Add a new schedule\n";
        cout << "3. Delete a schedule\n";
        cout << "4. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewAllSchedules(schedulelist);
                break;
            case 2:
                createSchedule(schedulelist, appointmentlist, doctorlist, patientlist, timetablelist);
                break;
            case 3: {
                int scheduleID;
                ScheduleNode* selectedSchedule = nullptr;

                do {
                    cout << "Enter the Schedule ID to delete: ";
                    cin >> scheduleID;

                    selectedSchedule = findScheduleByID(schedulelist, scheduleID); // Tìm lịch trình

                    if (selectedSchedule == nullptr) {
                        cout << "No schedule found with ID " << scheduleID << ". Please try again.\n";
                    }
                } while (selectedSchedule == nullptr);
                deleteSchedule(schedulelist, scheduleID);
                break;
            }
            case 4:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}
void managerMenu(LinkedListPatient &patientlist, LinkedListDoctor &doctorlist, LinkedListAppointment &appointmentlist,
                 LinkedListSchedule &schedulelist, LinkedListBill &billlist, LinkedListMedicine &medicinelist,
                 LinkedListTimetable &timetablelist) {
    bool isLoggedIn = false;

    // Vòng lặp để đảm bảo đăng nhập thành công trước khi vào menu
    do {
        isLoggedIn = loginManager();
        if (!isLoggedIn) {
            cout << "Login failed! Please try again.\n";
        }
    } while (!isLoggedIn);
     int choice;
    do {
        cout << "Welcome to the manager menu:\n";
        cout << "1. Manage Patients\n";
        cout << "2. Manage Doctors\n";
        cout << "3. Manage Bills\n";
        cout << "4. Manage Medicines\n";
        cout << "5. Manage Schedules\n";
        cout << "6. Manage Appointments\n";
        cout << "7. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                managePatient(patientlist,appointmentlist, schedulelist, billlist);
                break;
            case 2:
                manageDoctor(doctorlist, schedulelist, timetablelist);
                break;
            case 3:
                manageBill(billlist, medicinelist, patientlist, schedulelist);
                break;
            case 4:
                manageMedicine(medicinelist);
                break;
            case 5:
                manageSchedule(schedulelist ,appointmentlist, doctorlist, patientlist, timetablelist);
                break;
            case 6:
                manageAppointment(appointmentlist, patientlist);
                break;
            case 7:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while (choice != 7);

}

int main(){
    LinkedListPatient patientlist;
    LinkedListDoctor doctorlist;
    LinkedListAppointment appointmentlist;
    LinkedListSchedule schedulelist;
    LinkedListBill billlist;
    LinkedListMedicine medicinelist;
    LinkedListTimetable timetablelist;
    initPatientList(patientlist);
    initDoctorList(doctorlist);
    initAppointmentList(appointmentlist);
    initBillList(billlist);
    initScheduleList(schedulelist);
    initMedicineList(medicinelist);
    initTimetableList(timetablelist);

     // Tạo danh sách 10 bệnh nhân
    Patient patients[10];
    LinkedListAppointment appointmentList = nullptr;
    for (int i = 0; i < 10; ++i) {
        patients[i] = createPatient(i + 1);
        cout << "Patient " << i + 1 << ": " << patients[i].name << ", " << patients[i].phone << endl;
        addPatient(patientlist, patients[i].username, patients[i].password, patients[i].patientID, patients[i].name, patients[i].age, patients[i].phone);
        // addAppointment(appointmentList, i + 1, "Symptom " + to_string(i + 1), "01/01/2025", "10:00 AM", &patients[i]);
    }

    // Tạo danh sách 10 bác sĩ
    Doctor doctors[10];
    for (int i = 0; i < 10; ++i) {
        doctors[i] = createDoctor(i + 1);
        cout << "Doctor " << i + 1 << ": " << doctors[i].name << ", " << doctors[i].phone << endl;
        addDoctor(doctorlist, doctors[i].username, doctors[i].password, doctors[i].doctorID, doctors[i].name, doctors[i].age, doctors[i].phone);
    }


    int choice;
    do {
        cout << "\nWelcome to the Clinic Management System\n";
        cout << "1. Patient\n2. Doctor\n3. Manager\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                patientMenu(patientlist, appointmentList, schedulelist, billlist);
                break;
            case 2:
                doctorMenu(doctorlist);
                break;
            case 3:
                managerMenu(patientlist, doctorlist, appointmentList, schedulelist, billlist, medicinelist, timetablelist);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);


    return 0;
}
