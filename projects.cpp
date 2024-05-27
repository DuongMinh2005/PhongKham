#include <iostream>
#include <cstring>
using namespace std;
class tep_khach_hang{
private:
    string ten;
    int tuoi;
    string dia_chi;
    string trang_thai = "Khong co";
    string don_thuoc;
public:
    void nhap_thong_tin();
    void xuat();
    void tracuu_sk();
    void dat_lich();
    void chuan_doan(string& a);
};
void tep_khach_hang::chuan_doan(string& a){
    trang_thai = a;
}
class date{
private:
    int ngay;
    int thang; 
    int nam;
public:
    void dat_lich();
};
void tep_khach_hang::nhap_thong_tin(){
    cout << "Nhap ho ten: ";
    getline(cin,ten);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cout << "Nhap dia chi: ";
    getline(cin,dia_chi);
}
void tep_khach_hang::xuat(){
    cout << "Thong tin benh nhan:"<< endl;
    cout << "Ho va ten: " << ten << endl;
    cout <<"Tuoi: " << tuoi << endl;
    cout << "Dia chi: " << dia_chi << endl ;
    cout << "Tinh trang suc khoe: " << trang_thai << endl;
}

void date::dat_lich(){
    int a,b,c;
    cout << "Dat lich kham: ";
    cin >> a >> b >> c;
    ngay = a; thang = b; nam = c;
    cout << "Lich da dat: " << a << "/" << b << "/" << c <<endl;
    char c;
back:
    cout << "Ban da chac chan chua? Y/N" ;
    cin >> c;
    switch (c){
    case 'Y': case 'y':
        break;
    case 'N':case 'n':
        break;
    default:
        cout << "Hay an lai" << endl;
        goto back;
        break;
    }
}
