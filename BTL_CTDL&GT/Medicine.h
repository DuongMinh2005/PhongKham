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
    double dongia;
};

struct MedicineNode{
    Medicine data;
    MedicineNode* next;
};

void InitailizeThuoc(MedicineNode*& a){
    a = NULL;
}
typedef MedicineNode* LinkedListMedicine;
void DeleteMedicine(MedicineNode*& thuoc);
void AddMedicine(MedicineNode*& thuoc, Medicine duoc);
void FixMedicine(MedicineNode*& thuoc, Medicine duoc);
MedicineNode* searchMedicine(MedicineNode* thuoc);
void DisplayMedicine(MedicineNode* thuoc);