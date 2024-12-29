#include <iostream>
#include <string.h>
using namespace std;

struct KhoDuoc{
    string masothuoc;
    string tenthuoc;
    string suatxu;
    string ngaysanxuat;
    string hansudung;
    string tacdung;
    int soluong;
    string dongia;
};

struct ThuocNode{
    KhoDuoc a;
    ThuocNode* next;
};
void InitailizeThuoc(ThuocNode*& a){
    a = NULL;
}
void nhapThongTinThuoc(ThuocNode* & thuoc, KhoDuoc duoc) {
    printf(".______________________________.\n");
    printf("|     NHAP THONG TIN THUOC     |\n");
    printf(".______________________________.\n");
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
    ThuocNode* temp = new ThuocNode;
    temp->a = duoc;
    if (thuoc == NULL)
    {
        thuoc->next = NULL;
        thuoc->a = temp->a;
    }
    else {
        while (thuoc == NULL)
            thuoc = thuoc->next;
        thuoc->next = temp;
    }
};

void xoaThongTinThuoc(ThuocNode* thuoc) {
    printf(".______________________________.\n");
    printf("|      XOA THONG TIN THUOC     |\n");
    printf(".______________________________.\n");
    cout<<"Nhap ma so thuoc: ";
    cin.ignore();
};

void suaThongTinThuoc(ThuocNode* & thuoc, KhoDuoc duoc) {
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
    ThuocNode* temp = new ThuocNode;
    temp->a = duoc;

};

void timThongTinThuoc(ThuocNode* thuoc) {
    printf(".______________________________.\n");
    printf("|   TIM KIEM THONG TIN THUOC   |\n");
    printf(".______________________________.\n");
    cout<<"Nhap ma so thuoc: ";
    string maso;
    getline(cin,maso);
    ThuocNode* temp = new ThuocNode;
    temp->a.masothuoc = maso;
    
    };
void Listthongtinthuoc(ThuocNode* thuoc){
    ThuocNode* temp = new ThuocNode;
    while
}