#include <iostream>
#include <string.h>
#include "Medicine.h"
using namespace std;

MedicineNode* createMedicineNode(const Medicine& data){
    MedicineNode* temp = new MedicineNode;
    temp->next = NULL;
    temp->a = data;
    return temp;
};

void Insert_Med(MedicineNode*& thuoc, Medicine duoc) {
    cout<<"Ma so thuoc: ";
    cin.ignore();
    getline(cin,duoc.masothuoc);
    cout<<"Ten thuoc: ";
    getline(cin,duoc.tenthuoc);
    cout<<"Noi san xuat: ";
    getline(cin,duoc.suatxu);
    cout<<"Ngay san xuat: ";
    getline(cin,duoc.ngaysanxuat);
    cout<<"Han su dung: ";
    getline(cin,duoc.hansudung);
    cout<<"Tac dung cua thuoc: ";
    getline(cin,duoc.tacdung);
    cout<<"So luong: ";
    cin >> duoc.soluong;
    cin.ignore();
    cout<<"Don gia: ";
    getline(cin,duoc.dongia);
    MedicineNode* temp = createMedicineNode(duoc);
    if (thuoc == NULL)
        thuoc->next = temp;
    else {
        while (thuoc == NULL)
            thuoc = thuoc->next;
        thuoc->next = temp;
    }
};

void Delete_Med(MedicineNode*& thuoc) {
    cout<<"Nhap ma so thuoc: ";
    string maso;
    getline(cin,maso);
    cin.ignore();
    MedicineNode* temp = new MedicineNode;
    while (thuoc == NULL){
        if (thuoc->next->a.masothuoc == maso){
            temp = thuoc->next;
            thuoc->next = NULL;
            delete(temp);
        }
        thuoc = thuoc->next;
    }
};

void Fix_Med(MedicineNode*& thuoc, Medicine duoc) {
    printf(".______________________________.\n");
    printf("|      SUA THONG TIN THUOC     |\n");
    printf(".______________________________.\n");
    cout << "Vui long nhap ma so thuoc: ";
    cin.ignore();
    getline(cin, duoc.masothuoc);
    cout << "____NHAP THONG TIN MOI____" << endl;
    cout<<"Ma so thuoc: ";
    getline(cin,duoc.masothuoc);
    cout<<"Ten thuoc: ";
    getline(cin,duoc.tenthuoc);
    cout<<"Noi san xuat: ";
    getline(cin,duoc.suatxu);
    cout<<"Ngay san xuat: ";
    getline(cin,duoc.ngaysanxuat);
    cout<<"Han su dung: ";
    getline(cin,duoc.hansudung);
    cout<<"Tac dung: ";
    getline(cin,duoc.tacdung);
    cout<<"So luong: ";
    cin>>duoc.soluong;
    fflush(stdin);
    cout<<"Don gia: ";
    getline(cin,duoc.dongia);
    MedicineNode* temp = new MedicineNode;
    temp->a = duoc;

};

void Find_Med(MedicineNode* thuoc) {
    cout<<"Nhap ma so thuoc: ";
    string maso;
    getline(cin,maso);
    while (thuoc == NULL){
        if (thuoc->a.masothuoc == maso)
            {
            cout<<"Ma so thuoc: " << thuoc->a.masothuoc;
            cout<<"Ten thuoc: " << thuoc->a.tenthuoc;
            cout<<"Noi san xuat: " << thuoc->a.suatxu;
            cout<<"Ngay san xuat: " << thuoc->a.ngaysanxuat;
            cout<<"Han su dung: " << thuoc->a.hansudung;
            cout<<"Tac dung cua thuoc: " << thuoc->a.tacdung;
            cout<<"So luong: " << thuoc->a.soluong;
            cout<<"Don gia: " << thuoc->a.dongia;
            }
        thuoc = thuoc->next;
    }
};

void List_Med(MedicineNode* thuoc){
    while (thuoc == NULL){
    cout << "------------------------------------------------------------\n";
    cout<<"Ma so thuoc: " << thuoc->a.masothuoc;
    cout<<"Ten thuoc: " << thuoc->a.tenthuoc;
    cout<<"Noi san xuat: " << thuoc->a.suatxu;
    cout<<"Ngay san xuat: " << thuoc->a.ngaysanxuat;
    cout<<"Han su dung: " << thuoc->a.hansudung;
    cout<<"Tac dung cua thuoc: " << thuoc->a.tacdung;
    cout<<"So luong: " << thuoc->a.soluong;
    cout<<"Don gia: " << thuoc->a.dongia;
    thuoc = thuoc->next;    
    cout << "------------------------------------------------------------\n";
    }
}
int main(){

}