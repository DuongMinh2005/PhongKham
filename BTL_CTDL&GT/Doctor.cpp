#include "Doctor.h"
#include <iostream>
using namespace std;

void initDoctor(LinkedListDoctor &H){
    H = NULL;
}

bool EMPTY(LinkedListDoctor &H){
    return H == NULL;
}

DoctorNode* createDoctorNode(const Doctor &doctor_info){
    DoctorNode* newDoctorNode = new DoctorNode;
    newDoctorNode->doctor_info = doctor_info;
    newDoctorNode->next = NULL;
    return newDoctorNode;
}

bool isExit_doctorID_BS(LinkedListDoctor &H, string doctorID){
    PNodeDoctor Q = H;
    while(Q->next != NULL){
        if(Q->doctor_info.doctorID == doctorID){
            return true;
        }
        Q = Q->next;
    }
    return false;
}

Doctor inputDoctorinfo(LinkedListDoctor &H){
    Doctor doctorInfo;
    cout << "Tao ten dang nhap: ";
    getline(cin, doctorInfo.username);

    cout << "Tao doctorID: ";
    do{
        getline(cin, doctorInfo.doctorID);
        if(isExit_doctorID_BS(H, doctorInfo.doctorID)){
            cout << "doctorID da ton tai, vui long nhap lai: ";
        }
    } while(isExit_doctorID_BS(H, doctorInfo.doctorID));

    cout << "name bac si: ";
    getline(cin, doctorInfo.name);

    cout << "Nhap tuoi: ";
    cin >> doctorInfo.age;
    cin.ignore();  // Xóa ký tự xuống dòng còn lại trong buffer

    cout << "Nhap dia chi: ";
    getline(cin, doctorInfo.address);

    cout << "Nhap so dien thoai: ";
    getline(cin, doctorInfo.phone);

    cout << "Nhap kinh nghiem: ";
    getline(cin, doctorInfo.experience);

    return doctorInfo;
}

void insert(LinkedListDoctor &H, Doctor &t1){
    PNodeDoctor newBS = createDoctorNode(t1);
    if(EMPTY(H)){
        H = newBS;
    }
    else{
        PNodeDoctor Q = H;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = newBS;
    }
}

void display(LinkedListDoctor &H){
    if (EMPTY(H)) {
        cout << "The list is empty." << endl;
        return;
    }
    PNodeDoctor P = H;
    int i = 1;
    cout << "----------------DOCTOR LIST----------------" << endl;
    while (P!=NULL){
        cout << "Thong tin bac si: " << i << endl;
        cout << "Ten dang nhap: " << P->doctor_info.username << endl;
        cout << "ID cua bac si: " << P->doctor_info.doctorID << endl;
        cout << "name bac si: " << P->doctor_info.name << endl;
        cout << "tuoi: " << P->doctor_info.age << endl;
        cout << "Dia chi: " << P->doctor_info.address << endl;
        cout << "So dien thoai: " << P->doctor_info.phone << endl;
        cout << "Kinh nghiem: " << P->doctor_info.experience << endl;
        cout << "---------------------------------------------\n";
        P = P->next;
        i++;
    }
}


