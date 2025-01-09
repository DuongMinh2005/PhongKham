#include <iostream>
#include <iomanip> // Thư viện để định dạng bảng
#include <string>
using namespace std;
struct Patient;
struct Schedule;
struct Bill;
struct Appointment {
    int appointmentID;                
    string symptom;                   
    string date;
    string time;             
    Patient* patient;                 
};
struct AppointmentNode {
    Appointment appointment_info;    
    AppointmentNode* next;            
};
typedef AppointmentNode* APNode;
typedef AppointmentNode* LinkedListAppointment;

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
typedef ScheduleNode* SCNode;
typedef ScheduleNode* LinkedListSchedule;

struct Medicine {
    string medicineID;
    string name;
    string dosage;
    double price;
};
struct MedicineNode{
    Medicine medicine_info;
    Medicine* next;
};
typedef MedicineNode* MDNode;
typedef MedicineNode* LinkedListMedicine;

struct Bill {
    int billID;
    double totalAmount;
    string date;
    Patient* patient;
    Doctor* doctor;
    Schedule* schedule;
};
struct BillNode {
    Bill bill_info;
    BillNode* next;
};
typedef BillNode* BLNode;
typedef BillNode* LinkedListBill;
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
    string username = "admin";  // Define a username
    string password = "password123";  // Define a password
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
                    Patient* patient) {
    // Tạo một nút mới
    APNode newAppointmentNode = new AppointmentNode;
    
    // Gán thông tin cho lịch hẹn
    newAppointmentNode->appointment_info.appointmentID = appointmentID;
    newAppointmentNode->appointment_info.symptom = symptom;
    newAppointmentNode->appointment_info.date = date;
    newAppointmentNode->appointment_info.time = time;
    newAppointmentNode->appointment_info.patient = patient;

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
void addTimetable(LinkedListTimetable &head, const string &date, const string &time) {
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
void addSchedule(LinkedListSchedule &head, int scheduleID, const string &date, const string &time, Patient *patient, Doctor *doctor, Appointment *appointment) {
    // Tạo một nút mới cho lịch khám
    SCNode newScheduleNode = new ScheduleNode;
    newScheduleNode->schedule_info = {scheduleID, date, time, patient, doctor, appointment};
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
void deleteSchedule(LinkedListSchedule &head, int scheduleID) {
    // Kiểm tra danh sách rỗng
    if (head == nullptr) {
        cout << "The schedule list is empty. Nothing to delete.\n";
        return;
    }

    SCNode current = head;
    SCNode previous = nullptr;

    // Tìm kiếm lịch khám cần xóa
    while (current != nullptr && current->schedule_info.scheduleID != scheduleID) {
        previous = current;
        current = current->next;
    }

    // Kiểm tra nếu không tìm thấy lịch khám
    if (current == nullptr) {
        cout << "No schedule found with ID: " << scheduleID << ".\n";
        return;
    }

    // Xóa lịch khám
    if (previous == nullptr) {
        // Nếu nút cần xóa là nút đầu tiên
        head = current->next;
    } else {
        // Nếu nút cần xóa ở giữa hoặc cuối
        previous->next = current->next;
    }

    delete current; // Giải phóng bộ nhớ
    cout << "Schedule with ID: " << scheduleID << " has been deleted successfully.\n";
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
    addAppointment(head, appointmentID, symptom, date, time, &patient);

    cout << "\nAppointment booked successfully for Patient: " 
         << patient.name << " (ID: " << patient.patientID << ")!\n";
    cout << "Appointment ID: " << appointmentID << "\n";
    cout << "Date: " << date << ", Time: " << time << "\n";
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
    cout << "\n+-------------------------------------------------------------------------------------+\n";
    cout << "| " << setw(5) << "No."
         << " | " << setw(15) << "Appointment ID"
         << " | " << setw(25) << "Symptom/Reason"
         << " | " << setw(12) << "Date"
         << " | " << setw(8) << "Time"
         << " | " << setw(12) << "Patient ID"
         << " |\n";
    cout << "+-------------------------------------------------------------------------------------+\n";

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        count++;
        cout << "| " << setw(5) << count
             << " | " << setw(15) << current->appointment_info.appointmentID
             << " | " << setw(25) << current->appointment_info.symptom
             << " | " << setw(12) << current->appointment_info.date
             << " | " << setw(8) << current->appointment_info.time
             << " | " << setw(12) << current->appointment_info.patient->patientID
             << " |\n";
        current = current->next;
    }

    // Kết thúc bảng
    cout << "+-------------------------------------------------------------------------------------+\n";
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
    cout << "\n+-------------------------------------------------------------------------------------+\n";
    cout << "| " << setw(5) << "No."
         << " | " << setw(15) << "Appointment ID"
         << " | " << setw(25) << "Symptom/Reason"
         << " | " << setw(12) << "Date"
         << " | " << setw(8) << "Time"
         << " |\n";
    cout << "+-------------------------------------------------------------------------------------+\n";

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
                 << " |\n";
        }
        // Di chuyển tới lịch hẹn tiếp theo
        current = current->next;
    }

    // Kết thúc bảng
    cout << "+-------------------------------------------------------------------------------------+\n";

    // Thông báo nếu bệnh nhân không có lịch hẹn
    if (count == 0) {
        cout << "No appointments found for the logged-in patient.\n";
    } else {
        cout << "\nTotal Appointments for Logged-In Patient: " << count << "\n";
    }
}
//hàm view schedule by patient
void viewSchedulesByPatient(LinkedListSchedule head, Patient &patient) {
    // Kiểm tra nếu danh sách lịch khám rỗng
    if (head == nullptr) {
        cout << "No schedules available.\n";
        return;
    }

    SCNode current = head; // Con trỏ duyệt danh sách
    int count = 0;         // Biến đếm số lượng lịch khám của bệnh nhân

    // Tiêu đề bảng
    cout << "\n+--------------------------------------------------------------------------------------------------+\n";
    cout << "| " << setw(5) << "No."
         << " | " << setw(15) << "Schedule ID"
         << " | " << setw(12) << "Date"
         << " | " << setw(8) << "Time"
         << " | " << setw(12) << "Doctor ID"
         << " |\n";
    cout << "+--------------------------------------------------------------------------------------------------+\n";

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        // Kiểm tra nếu lịch khám liên kết với bệnh nhân hiện đang đăng nhập
        if (current->schedule_info.patient->name == patient.name) {
            count++;
            cout << "| " << setw(5) << count
                 << " | " << setw(15) << current->schedule_info.scheduleID
                 << " | " << setw(12) << current->schedule_info.date
                 << " | " << setw(8) << current->schedule_info.time
                 << " | " << setw(12) << current->schedule_info.doctor->doctorID
                 << " |\n";
        }
        // Di chuyển tới lịch khám tiếp theo
        current = current->next;
    }

    // Kết thúc bảng
    cout << "+--------------------------------------------------------------------------------------------------+\n";

    // Thông báo nếu bệnh nhân không có lịch khám
    if (count == 0) {
        cout << "No schedules found for the logged-in patient.\n";
    } else {
        cout << "\nTotal Schedules for Logged-In Patient: " << count << "\n";
    }
}
//hàm view schedule by doctor
void viewSchedulesByDoctor(LinkedListSchedule head, Doctor &doctor) {
    // Kiểm tra nếu danh sách lịch khám rỗng
    if (head == nullptr) {
        cout << "No schedules available.\n";
        return;
    }

    SCNode current = head; // Con trỏ duyệt danh sách
    int count = 0;         // Biến đếm số lượng lịch khám của bác sĩ

    // Tiêu đề bảng
    cout << "\n+--------------------------------------------------------------------------------------------------+\n";
    cout << "| " << setw(5) << "No."
         << " | " << setw(15) << "Schedule ID"
         << " | " << setw(12) << "Date"
         << " | " << setw(8) << "Time"
         << " | " << setw(12) << "Patient ID"
         << " |\n";
    cout << "+--------------------------------------------------------------------------------------------------+\n";

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        // Kiểm tra nếu lịch khám liên kết với bác sĩ hiện đang đăng nhập
        if (current->schedule_info.doctor->name == doctor.name) {
            count++;
            cout << "| " << setw(5) << count
                 << " | " << setw(15) << current->schedule_info.scheduleID
                 << " | " << setw(12) << current->schedule_info.date
                 << " | " << setw(8) << current->schedule_info.time
                 << " | " << setw(12) << current->schedule_info.patient->patientID
                 << " |\n";
        }
        // Di chuyển tới lịch khám tiếp theo
        current = current->next;
    }

    // Kết thúc bảng
    cout << "+--------------------------------------------------------------------------------------------------+\n";

    // Thông báo nếu bác sĩ không có lịch khám
    if (count == 0) {
        cout << "No schedules found for the logged-in doctor.\n";
    } else {
        cout << "\nTotal Schedules for Logged-In Doctor: " << count << "\n";
    }
}
//Hàm view all timetable
void viewDoctorTimetables(LinkedListTimetable head) {
    // Kiểm tra nếu danh sách timetable rỗng
    if (head == nullptr) {
        cout << "No timetables available.\n";
        return;
    }

    TTNode current = head; // Con trỏ duyệt danh sách
    int count = 0;         // Biến đếm số lượng timetable

    // Tiêu đề bảng
    cout << "\n+----------------------------------+\n";
    cout << "| " << setw(5) << "No."
         << " | " << setw(12) << "Date"
         << " | " << setw(8) << "Time"
         << " |\n";
    cout << "+----------------------------------+\n";

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        count++;
        cout << "| " << setw(5) << count
             << " | " << setw(12) << current->timetable_info.date
             << " | " << setw(8) << current->timetable_info.time
             << " |\n";
        current = current->next;
    }

    // Kết thúc bảng
    cout << "+----------------------------------+\n";
    cout << "\nTotal Timetables: " << count << "\n";
}
//hàm view all schedule
void viewAllSchedules(LinkedListSchedule head) {
    // Kiểm tra nếu danh sách lịch khám rỗng
    if (head == nullptr) {
        cout << "No schedules available.\n";
        return;
    }

    SCNode current = head; // Con trỏ duyệt danh sách
    int count = 0;         // Biến đếm số lượng lịch khám

    // Tiêu đề bảng
    cout << "\n+--------------------------------------------------------------------------------------------------+\n";
    cout << "| " << setw(5) << "No."
         << " | " << setw(15) << "Schedule ID"
         << " | " << setw(12) << "Date"
         << " | " << setw(8) << "Time"
         << " | " << setw(12) << "Patient ID"
         << " | " << setw(12) << "Doctor ID"
         << " |\n";
    cout << "+--------------------------------------------------------------------------------------------------+\n";

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        count++;
        cout << "| " << setw(5) << count
             << " | " << setw(15) << current->schedule_info.scheduleID
             << " | " << setw(12) << current->schedule_info.date
             << " | " << setw(8) << current->schedule_info.time
             << " | " << setw(12) << current->schedule_info.patient->patientID
             << " | " << setw(12) << current->schedule_info.doctor->doctorID
             << " |\n";
        current = current->next;
    }

    // Kết thúc bảng
    cout << "+--------------------------------------------------------------------------------------------------+\n";
    cout << "\nTotal Schedules: " << count << "\n";
}

// Hàm hủy lịch hẹn theo ID
void cancelAppointment(LinkedListAppointment& appointmentList, Patient& patient) {
    int appointmentID;
    cout << "Nhập ID của lịch hẹn muốn hủy: ";
    cin >> appointmentID;

    deleteAppointment(appointmentList, appointmentID);

    cout << "Không tìm thấy lịch hẹn với ID " << appointmentID << " của bạn.\n";
}
//hàm huỷ lịch khám theo ID
void cancelSchedule(LinkedListSchedule &schedulelist, Patient &patient) {
    int scheduleID;
    cout << "Nhập ID của lịch khám muốn hủy: ";
    cin >> scheduleID;

    deleteSchedule(schedulelist, scheduleID);

    cout << "Không tìm thấy lịch khám với ID " << scheduleID << " của bạn.\n";
}
//Hàm thêm schedule node 
void addScheduleNode(LinkedListSchedule &schedulelist, int scheduleID, const string &date, const string &time, 
                     Patient *patient, Doctor *doctor, Appointment *appointment) {
    // Tạo một nút mới cho lịch khám
    SCNode newScheduleNode = new ScheduleNode;
    newScheduleNode->schedule_info = {scheduleID, date, time, patient, doctor, appointment};
    newScheduleNode->next = nullptr;

    // Thêm nút vào cuối danh sách liên kết
    if (schedulelist == nullptr) {
        // Nếu danh sách rỗng, nút mới trở thành nút đầu tiên
        schedulelist = newScheduleNode;
    } else {
        // Duyệt đến cuối danh sách và thêm nút mới
        SCNode temp = schedulelist;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newScheduleNode;
    }
}
//Hàm tạo lịch khám
void createSchedule(LinkedListSchedule &scheduleList, LinkedListAppointment &appointmentList, 
                    LinkedListDoctor &doctorList, LinkedListPatient &patientList) {

    int appointmentID, scheduleID;
    string date, time;
    Doctor* doctor = nullptr;
    Patient* patient = nullptr;
    AppointmentNode* appointment = nullptr;

    // Nhập Appointment ID để xử lý
    cout << "Enter Appointment ID to process: ";
    cin >> appointmentID;

    // Tìm lịch hẹn theo appointmentID
    APNode appNode = findAppointmentByID(appointmentList, appointmentID);
    if (appNode == nullptr) {
        cout << "Appointment ID not found.\n";
        return;
    }

    appointment = &appNode->appointment_info;
    patient = &(appointment->patient_info);

    // Nhập thông tin lịch khám
    cout << "Enter Schedule ID: ";
    cin >> scheduleID;
    cout << "Enter Date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Enter Time (HH:MM): ";
    cin >> time;

    // Hiển thị danh sách bác sĩ
    cout << "Available Doctors:\n";
    viewDoctorList(doctorList);

    string doctorID;
    cout << "Enter Doctor ID: ";
    cin >> doctorID;

    DTNode doctorNode = findDoctorByID(doctorList, doctorID);
    if (doctorNode == nullptr) {
        cout << "Doctor ID not found.\n";
        return;
    }

    doctor = &(doctorNode->doctor_info);

    // Tạo một nút lịch khám mới
    SCNode newScheduleNode = new ScheduleNode;
    newScheduleNode->schedule_info = {scheduleID, date, time, patient, doctor, appointment};
    newScheduleNode->next = nullptr;  // Đặt next là nullptr vì đây là nút cuối

    // Thêm lịch khám mới vào danh sách lịch khám
    if (scheduleList == nullptr) {
        // Nếu danh sách rỗng, nút mới trở thành nút đầu tiên
        scheduleList = newScheduleNode;
    } else {
        // Duyệt đến cuối danh sách và thêm vào cuối
        SCNode temp = scheduleList;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newScheduleNode;
    }

    // Cập nhật lịch khám cho bệnh nhân
    SCNode patientSchedule = &(patient->schedule);
    if (patientSchedule->next == nullptr) {
        patientSchedule->next = newScheduleNode;
    }

    // Cập nhật lịch khám cho bác sĩ
    SCNode doctorSchedule = &(doctor->schedule);
    if (doctorSchedule->next == nullptr) {
        doctorSchedule->next = newScheduleNode;
    }

    // Xóa lịch hẹn khỏi danh sách chưa xử lý
    deleteAppointment(appointmentList, appointmentID);

    cout << "Schedule created successfully!\n";
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
// Hàm kiểm tra và hiển thị tất cả lịch hẹn chưa được xử lý
void viewPendingAppointments(LinkedListAppointment appointmentList) {
    cout << left << setw(15) << "Appointment ID"
         << setw(20) << "Symptom"
         << setw(15) << "Date"
         << setw(10) << "Time"
         << setw(20) << "Patient Name" << endl;
    cout << string(80, '-') << endl;

    APNode current = appointmentList;
    bool hasPending = false; // Kiểm tra có lịch hẹn chưa xử lý không

    while (current != nullptr) {
        // Kiểm tra bệnh nhân có lịch khám hay chưa
        if (current->appointment_info.patient->schedule.schedule_info.scheduleID == 0) { // Chưa có lịch khám
            cout << left << setw(15) << current->appointment_info.appointmentID
                 << setw(20) << current->appointment_info.symptom
                 << setw(15) << current->appointment_info.date
                 << setw(10) << current->appointment_info.time
                 << setw(20) << current->appointment_info.patient->name << endl;
            hasPending = true;
        }
        current = current->next;
    }

    if (!hasPending) {
        cout << "No pending appointments found.\n";
    }
    cout << string(80, '-') << endl;
}



// Menu bệnh nhân
void patientMenu(LinkedListPatient& patientList, LinkedListAppointment& appointmentlist) {
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
                cout << "Chức năng xem lịch trình đang phát triển.\n";
                break;
            }
            case 7: {
                cout << "\n--- View Bills ---\n";
                cout << "Chức năng xem hóa đơn đang phát triển.\n";
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
                break;
            case 4:
                cout << "\n--- View Schedule of Doctor ---\n";
                break;
            case 5:
                cout << "\n--- View Patients of Doctor ---\n";
                break;
            case 6:
                cout << "Logged out successfully. Exit menu.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
}

// Menu quản lý
void managePatient(LinkedListPatient &patientlist, LinkedListAppointment &appointmentlist){
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
                cout << "Enter the patient ID to select: ";
                cin >> patientID;

                PTNode selectedNode = findPatientByID(patientlist, patientID); // Gọi hàm trả về PTNode

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
                            cout << "Patient Information:\n";
                            cout << "ID: " << selectedPatient->patientID
                                 << ", Name: " << selectedPatient->name
                                 << ", Age: " << selectedPatient->age
                                 << ", Phone: " << selectedPatient->phone << "\n";
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
                            //viewPatientBills(billlist, patientID);
                            break;

                        case 6:
                            //viewPatientBills(billlist, patientID);
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
void manageDoctor(LinkedListDoctor &doctorlist){}
void manageBill(LinkedListBill &billlist){}
void manageMedicine(LinkedListMedicine &medicinelist){}
void manageAppointment(LinkedListAppointment &appointmentlist){
    int choice;
    do {
        cout << "\nAppointment Management Menu:\n";
        cout << "1. View all pending appointments\n";
        cout << "2. Add a new appointment\n";
        cout << "3. Delete an appointment\n";
        cout << "4. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewPendingAppointments(appointmentlist);
                break;
            case 2: {
                int appointmentID;
                string symptom, date, time;
                Patient* patient = new Patient; // Giả sử đã có thông tin bệnh nhân
                cout << "Enter Appointment ID: ";
                cin >> appointmentID;
                cout << "Enter Symptom: ";
                cin.ignore();
                getline(cin, symptom);
                cout << "Enter Date (YYYY-MM-DD): ";
                cin >> date;
                cout << "Enter Time (HH:MM): ";
                cin >> time;

                // Cần gán thông tin cho bệnh nhân
                cout << "Enter Patient Name: ";
                cin.ignore();
                getline(cin, patient->name);
                addAppointment(appointmentlist, appointmentID, symptom, date, time, patient);
                break;
            }
            case 3: {
                int appointmentID;
                cout << "Enter the Appointment ID to delete: ";
                cin >> appointmentID;
                deleteAppointment(appointmentlist, appointmentID);
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
void manageSchedule(LinkedListSchedule &schedulelist, LinkedListAppointment &appointmentlist, LinkedListDoctor &doctorlist, LinkedListPatient &patientlistpatientlist){}
void managerMenu(LinkedListPatient &patientlist, LinkedListDoctor &doctorlist, LinkedListAppointment &appointmentlist, LinkedListSchedule &schedulelist, LinkedListBill &billlist, LinkedListMedicine &medicinelist){
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
                managePatient(patientlist,appointmentlist);
                break;
            case 2:
                manageDoctor(doctorlist);
                break;
            case 3:
                manageBill(billlist);
                break;
            case 4:
                manageMedicine(medicinelist);
                break;
            case 5:
                manageSchedule(schedulelist ,appointmentlist, doctorlist, patientlist);
                break;
            case 6:
                manageAppointment(appointmentlist);
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
    for (int i = 0; i < 10; ++i) {
        patients[i] = createPatient(i + 1);
        cout << "Patient " << i + 1 << ": " << patients[i].name << ", " << patients[i].phone << endl;
        addPatient(patientlist, patients[i].username, patients[i].password, patients[i].patientID, patients[i].name, patients[i].age, patients[i].phone);
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
                patientMenu(patientlist, appointmentlist);
                break;
            case 2:
                doctorMenu(doctorlist);
                break;
            case 3:
                managerMenu(patientlist, doctorlist, appointmentlist, schedulelist, billlist, medicinelist);
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