#include <iostream>
#include <string.h>
using namespace std;

typedef struct{
    char masothuoc[100];
    char tenthuoc[100];
    char suatxu[100];
    char ngaysanxuat[100];
    char hansudung[100];
    char tacdung[100];
    int soluong;
    char dongia[100];
}KhoDuoc;

struct ThuocNode{
    KhoDuoc a;
    ThuocNode* next;
};
void nhapThongTinThuoc() {
    printf(".______________________________.\n");
    printf("|     NHAP THONG TIN THUOC     |\n");
    printf(".______________________________.\n");
    cout<<"Ma so thuoc: ";
    cin.ignore();
    getline(cin,masothuoc);
    cout<<"Ten thuoc: ";
    getline(cin,tenthuoc);
    cout<<"Noi san xuat: ";
    getline(cin,suatxu);
    cout<<"Ngay san xuat: ";
    getline(cin,ngaysanxuat);
    cout<<"Han su dung: ";
    getline(cin,hansudung);
    cout<<"Tac dung cua thuoc: ";
    getline(cin,tacdung);
    cout<<"So luong: ";
    cin>>soluong;
    cin.ignore();
    cout<<"Don gia: ";
    getline(cin,dongia);

    ofstream file("thongtinkhoduoc.txt", ios::app);
    if (file.is_open()) {
        
        file<<"Ma so thuoc: "<< masothuoc <<endl;
        file<<"Ten thuoc: "<< tenthuoc <<endl;
        file<<"Noi san xuat: "<< suatxu <<endl;
        file<<"Ngay san xuat: "<< ngaysanxuat <<endl;
        file<<"Han sau dung: "<< hansudung <<endl;
        file<<"Tac dung cua thuoc: "<< hansudung <<endl;
        file<<"So luong: "<< soluong <<endl;
        file<<"Don gia: "<< dongia <<" vnd"<<endl;
        file<<"--------------------------------"<<endl;
        file.close();
        printf("====NHAP THONG TIN THANH CONG====\n");
    } else {
        cout<<"____KHONG THE MO FILE THONG TIN____"<<endl;
    }
};

void KhoDuoc::xoaThongTinThuoc() {
    printf(".______________________________.\n");
    printf("|      XOA THONG TIN THUOC     |\n");
    printf(".______________________________.\n");
    cout<<"Nhap ma so thuoc: ";
    cin.ignore();
    getline(cin,masothuoc);
    string line;
    ifstream infile("thongtinkhoduoc.txt");
    ofstream outfile("temp.txt");
    if (!infile.is_open()) {
        cout<<"____KHONG THE MO FILE THONG TIN____";
        return;
    }
    bool found = false;
    string search_line = "Ma so thuoc: " + masothuoc;
    while (getline(infile,line)) {
        if (line == search_line) {
            found = true;
            for(int i=0 ; i<8 ; ++i) 
            {
                getline(infile,line);
            }
        } else {
            outfile << line <<endl;
        }
    }
    infile.close();
    outfile.close();
    if (found) {
        remove("thongtinkhoduoc.txt");
        rename("temp.txt","thongtinkhoduoc.txt");
        printf("===XOA THONG TIN THUOC THANH CONG===\n");
    } else {
        cout<<"____KHONG TIM THAY TAI KHOAN CAN XOA____"<<endl;
    }
};

void KhoDuoc::suaThongTinThuoc() {
    ifstream file("thongtinkhoduoc.txt");
    ofstream tempfile("temp.txt"); // Tep tam thoi cho du lieu de sua doi

    if (file.is_open() && tempfile.is_open()) {
        string line;
        bool found = false;
    printf(".______________________________.\n");
    printf("|      SUA THONG TIN THUOC     |\n");
    printf(".______________________________.\n");
        cout << "Vui long nhap ma so thuoc: ";
        cin.ignore();
        getline(cin, masothuoc);

      while (getline(file, line)) {
        if (line == "Ma so thuoc: " + masothuoc) {   // Tim thay thong tin bac si
            cout << "____NHAP THONG TIN MOI____" << endl;
            cout<<"Ma so thuoc: ";
            getline(cin,masothuoc);
            cout<<"Ten thuoc: ";
            getline(cin,tenthuoc);
            cout<<"Noi san xuat: ";
            getline(cin,suatxu);
            cout<<"Ngay san xuat: ";
            getline(cin,ngaysanxuat);
            cout<<"Han su dung: ";
            getline(cin,hansudung);
            cout<<"Tac dung: ";
            getline(cin,tacdung);
            cout<<"So luong: ";
            cin>>soluong;fflush(stdin);
            cout<<"Don gia: ";
            getline(cin,dongia);
            tempfile<<"Ma so thuoc: "<< masothuoc <<endl;
            tempfile<<"Ten thuoc: "<< tenthuoc <<endl;
            tempfile<<"Noi san xuat: "<< suatxu <<endl;
            tempfile<<"Ngay san xuat: "<< ngaysanxuat <<endl;
            tempfile<<"Han sau dung: "<< hansudung <<endl;
            tempfile<<"Tac dung: "<< hansudung <<endl;
            tempfile<<"So luong: "<< soluong <<endl;
            tempfile<<"Don gia: "<< dongia <<" vnd"<<endl;
            tempfile<<"------------------------------------\n";
          found = true;

          for (int i = 0; i < 8; ++i) {      //Bo qua cac dong thong tin cu
            getline(file, line);
            };
        } else {
            tempfile << line << endl;
        };
      };

      file.close();
      tempfile.close();

      if (found) {
        // Xoa tep goc va doi ten tep tam thoi
        remove("thongtinkhoduoc.txt");
        rename("temp.txt", "thongtinkhoduoc.txt");

        printf("====SUA THONG TIN THANH CONG====\n");
      } else {
        cout << "Khong tim thay thong tin thuoc voi ma so: " << masothuoc << endl;
        remove("temp.txt");
      }
    } else {
      cout << "____KHONG THE MO FILE THONG TIN____" << endl;
    }
};

void KhoDuoc::timThongTinThuoc() {
    ifstream file("thongtinkhoduoc.txt");
    string line;
    string search_line;
    bool found = false;
    printf(".______________________________.\n");
    printf("|   TIM KIEM THONG TIN THUOC   |\n");
    printf(".______________________________.\n");
    cout<<"Nhap ma so thuoc: ";
    cin.ignore();
    getline(cin,search_line);
    
    while (getline(file,line))
    {
        if (line == "Ma so thuoc: " + search_line){
            cout<<"Ma so thuoc: "<<search_line<<endl;
            for (int i=0;i < 8; ++i) {
                getline(file,line);
                cout<< line<<endl;
            };
            found = true;
        };
    };
    file.close();
    if (!found) {
        cout<<"____KHONG TIM THAY THONG TIN THUOC____"<<endl;
    }
};