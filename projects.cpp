#include <iostream>
#include <cstring>
using namespace std;
class tep_khach_hang{
private:
    string ten;
    int tuoi;
    string dia_chi;
    int ngay;
    int thang;
    int nam;
    string trang_thai = "Khong co";
public:
    void nhap_in4();
    void xuat_in4();
    void dat_lich();
    void chuan_doan(string& a);
};
void tep_khach_hang::nhap_in4(){
    cout << "Nhap ho ten: ";
    getline(cin,ten);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cout << "Nhap dia chi: ";
    getline(cin,dia_chi);
}
void tep_khach_hang::xuat_in4(){
    cout << "Thong tin benh nhan:"<< endl;
    cout << "Ho va ten: " << ten << endl;
    cout <<"Tuoi: " << tuoi << endl;
    cout << "Dia chi: " << dia_chi << endl ;
    cout << "Tinh trang suc khoe: " << trang_thai << endl;
}
void tep_khach_hang::dat_lich(){
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
void tep_khach_hang::chuan_doan(string& a){
    trang_thai = a;
}