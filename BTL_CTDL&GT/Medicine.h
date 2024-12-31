#include <iostream>
#include <string.h>
using namespace std;

struct Medicine{
    string masothuoc;
    string tenthuoc;
    string suatxu;
    string ngaysanxuat;
    string hansudung;
    string tacdung;
    int soluong;
    string dongia;
};

struct MedicineNode{
    Medicine a;
    MedicineNode* next;
};

void InitailizeThuoc(MedicineNode*& a){
    a = NULL;
}

bool is_Med_empty(MedicineNode*);
void Delete_Med(MedicineNode*& thuoc);
void Insert_Med(MedicineNode*& thuoc, Medicine duoc);
void Fix_Med(MedicineNode*& thuoc, Medicine duoc);
void Find_Med(MedicineNode* thuoc);
void List_Med(MedicineNode* thuoc);