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

// Node của danh sách lịch hẹn
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
    Appointment* appointment;
    Schedule* schedule;
    Bill* bill;
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
struct Doctor{
    string username;
    string password;
    string doctorID;
    string name;
    string age;
    string phone;
    Schedule* schedule;
    Timetable* timetable;
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

// Hàm kiểm tra danh sách rỗng



// Hàm thêm bệnh nhân vào danh sách
void insertPatient(LinkedListPatient &head, Patient newPatient) {
    PTNode newNode = new PatientNode;
    newNode->patient_info = newPatient;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        PTNode temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Hàm thêm bác sĩ vào danh sách
void insertDoctor(LinkedListDoctor &head, Doctor newDoctor) {
    DTNode newNode = new DoctorNode;
    newNode->doctor_info = newDoctor;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        DTNode temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
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
//Hàm tìm bệnh nhân
Patient* findPatient(LinkedListPatient patientList, const string& patientID) {
    PTNode current = patientList;
    while (current != nullptr) {
        if (current->patient_info.patientID == patientID) {
            return &(current->patient_info);
        }
        current = current->next;
    }
    return nullptr; // Trả về nullptr nếu không tìm thấy bệnh nhân
}
//Hàm xóa bệnh nhân
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

//Hàm hiển thị thông tin bệnh nhân
void displayPatientInfo(Patient& patient){
    cout << "Patient ID: " << patient.patientID << endl;
    cout << "Name: " << patient.name << endl;
    cout << "Age: " << patient.age << endl;
    cout << "Phone: " << patient.phone << endl;
    cout << "-----------------------" << endl;
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

//hàm book appointment

void bookAppointment(LinkedListAppointment& head, Patient& patient) {
    // Tạo lịch hẹn mới
    APNode newAppointmentNode = new AppointmentNode;

    // Nhập thông tin lịch hẹn
    cout << "Enter Appointment ID: ";
    cin >> newAppointmentNode->appointment_info.appointmentID;

    cout << "Enter Symptom/Reason for Appointment: ";
    cin.ignore(); // Loại bỏ bộ nhớ đệm
    getline(cin, newAppointmentNode->appointment_info.symptom);

    cout << "Enter Appointment Date (dd/mm/yyyy): ";
    cin >> newAppointmentNode->appointment_info.date;

    cout << "Enter Appointment Time (hh:mm): ";
    cin >> newAppointmentNode->appointment_info.time;

    // Gán thông tin bệnh nhân
    newAppointmentNode->appointment_info.patient = &patient;

    // Đặt con trỏ tiếp theo của nút mới thành nullptr
    newAppointmentNode->next = nullptr;

    // Thêm nút mới vào danh sách liên kết
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

    cout << "\nAppointment booked successfully for Patient: " 
         << patient.name << " (ID: " << patient.patientID << ")!\n";
    cout << "Appointment ID: " << newAppointmentNode->appointment_info.appointmentID << "\n";
    cout << "Date: " << newAppointmentNode->appointment_info.date 
         << ", Time: " << newAppointmentNode->appointment_info.time << "\n";
}
//hàm view all appointment
void viewAppointmentsByPatient(LinkedListAppointment head, Patient &patient) {

    // Kiểm tra nếu danh sách lịch hẹn rỗng
    if (head == nullptr) {
        cout << "No appointments available.\n";
        return;
    }

    APNode current = head; // Con trỏ duyệt danh sách
    int count = 0; // Biến đếm số lượng lịch hẹn của bệnh nhân

    // Duyệt danh sách liên kết
    while (current != nullptr) {
        // Kiểm tra nếu lịch hẹn liên kết với bệnh nhân hiện đang đăng nhập
        if (current->appointment_info.patient == &patient) {
            count++;
            cout << "\nAppointment #" << count << ":\n";
            cout << "Appointment ID: " << current->appointment_info.appointmentID << "\n";
            cout << "Symptom/Reason: " << current->appointment_info.symptom << "\n";
            cout << "Date: " << current->appointment_info.date << "\n";
            cout << "Time: " << current->appointment_info.time << "\n";
        }
        // Di chuyển tới lịch hẹn tiếp theo
        current = current->next;
    }

    // Thông báo nếu bệnh nhân không có lịch hẹn
    if (count == 0) {
        cout << "No appointments found for the logged-in patient.\n";
    } else {
        cout << "\nTotal Appointments for Logged-In Patient: " << count << "\n";
    }
}


// Hàm hủy lịch hẹn theo ID
void cancelAppointment(LinkedListAppointment& appointmentList, Patient& patient) {
    int appointmentID;
    cout << "Nhập ID của lịch hẹn muốn hủy: ";
    cin >> appointmentID;

    // Duyệt qua danh sách các lịch hẹn để tìm lịch hẹn với ID phù hợp
    APNode prev = nullptr;
    APNode current = appointmentList;

    while (current != nullptr) {
        if (current->appointment_info.appointmentID == appointmentID && current->appointment_info.patient == &patient) {
            // Tìm thấy lịch hẹn của bệnh nhân với ID phù hợp, xóa lịch hẹn đó khỏi danh sách
            if (prev == nullptr) {
                // Lịch hẹn đầu tiên
                appointmentList = current->next;
            } else {
                // Lịch hẹn ở giữa hoặc cuối danh sách
                prev->next = current->next;
            }

            delete current;  // Giải phóng bộ nhớ cho node đã xóa
            cout << "Lịch hẹn với ID " << appointmentID << " đã được hủy thành công.\n";
            return;
        }

        prev = current;
        current = current->next;
    }

    cout << "Không tìm thấy lịch hẹn với ID " << appointmentID << " của bạn.\n";
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
    patient.appointment = nullptr;
    patient.schedule = nullptr;
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
    doctor.schedule = nullptr;
    doctor.timetable = nullptr;
    return doctor;
}



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
        if (current->appointment_info.patient->schedule == nullptr) { // Chưa có lịch khám
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
void doctorMenu() {

    int choice;
    do {
        cout << "\n=== Doctor Menu ===\n";
        cout << "1. View Information\n";
        cout << "2. Edit Information\n";
        cout << "3.View Timetable\n";
        cout << "4. View Schedule\n";
        cout << "5. View Patients\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Viewing schedule...\n";
                break;
            case 2:
                cout << "Updating schedule...\n";
                break;
            case 3:
                cout << "Viewing patients...\n";
                break;
            case 4:
                cout << "Exiting Doctor Menu...\n";
                break;
            case 5:

                break;
            case 6:
                 
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

                Patient* selectedPatient = findPatient(patientlist, patientID);
                if (selectedPatient == nullptr) {
                    cout << "Patient not found!\n";
                    break;
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
                deleteAppointment(appointmentList, appointmentID);
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
    // Vòng lặp để đảm bảo đăng nhập thành công trước khi vào menu
    do {
        if (!loginManager) {
            cout << "Login failed! Please try again.\n";
        }
    } while (!loginManager);
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

    initPatientList(patientlist);
    initDoctorList(doctorlist);
    initAppointmentList(appointmentlist);
    initBillList(billlist);
    initScheduleList(schedulelist);
    initMedicineList(medicinelist);
     // Tạo danh sách 10 bệnh nhân
    Patient patients[10];
    for (int i = 0; i < 10; ++i) {
        patients[i] = createPatient(i + 1);
        cout << "Patient " << i + 1 << ": " << patients[i].name << ", " << patients[i].phone << endl;
        insertPatient(patientlist, patients[i]);
    }

    // Tạo danh sách 10 bác sĩ
    Doctor doctors[10];
    for (int i = 0; i < 10; ++i) {
        doctors[i] = createDoctor(i + 1);
        cout << "Doctor " << i + 1 << ": " << doctors[i].name << ", " << doctors[i].phone << endl;
        insertDoctor(doctorlist, doctors[i]);
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
                doctorMenu();
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