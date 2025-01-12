#include <iostream>
#include "Patient.cpp"
#include "Medicine.cpp"
#include "Doctor.cpp"
#include "Schedule.cpp"
#include "Appointment.cpp"
int main(){
    LinkedListPatient benhnhan;
    LinkedListDoctor bacsi;
    LinkedListMedicine khoduoc;
menu:
        int a;
        cout<<".______________________________."<<endl;
        cout<<"|             MENU             |"<<endl;
        cout<<".______________________________."<<endl;
        cout<<"1.QUAN LY BENH NHAN"<<endl;
        cout<<"2.QUAN LY BAC SI"<<endl;
        cout<<"3.QUAN LY KHO DUOC"<<endl;
        cout<<"4.QUAN LY LICH KHAM"<<endl;
        cout<<"4.DANG XUAT"<<endl;
        cout<<"VUI LONG CHON CHUC NANG: ";
        cin>> a;
        switch (a) {
            case 1:
quanlibenhnhan:
                cout<<".______________________________."<<endl;
                cout<<"|       QUAN LY BENH NHAN      |"<<endl;
                cout<<".______________________________."<<endl;
                cout<<"1.NHAP THONG TIN BENH NHAN"<<endl;
                cout<<"2.XOA THONG TIN BENH NHAN"<<endl;
                cout<<"3.SUA THONG TIN BENH NHAN"<<endl;
                cout<<"4.TIM THONG TIN BENH NHAN"<<endl;
                cout<<"5.XEM DANH SACH BENH NHAN"<<endl;
                cout<<"6.QUAY LAI"<<endl;
                cout<<"VUI LONG CHON CHUC NANG: ";
                int b;
                cin>>b;
                switch (b){
                    case 1:
                        benhnhan.nhapThongTinBenhNhan();
                        break;
                    case 2:
                        benhnhan.xoaThongTinBenhNhan();
                        break;
                    case 3:
                        benhnhan.suaThongTinBenhNhan();
                        break;
                    case 4: 
                        benhnhan.timThongTinBenhNhan();
                        break;
                    case 5:
                        inDanhSachBN();
                        break;
                    case 6:
                        goto menu;
                    default:
                        cout<<"!!!CHUC NANG KHONG PHU HOP!!!"<<endl;
                        cout<<"======VUI LONG CHON LAI======\n\n";
                        goto quanlibenhnhan;
                        break;
                }
                goto quanlibenhnhan;
            case 2:
quanlibacsi:
                cout<<".______________________________."<<endl;
                cout<<"|        QUAN LY BAC SI        |"<<endl;
                cout<<".______________________________."<<endl;
                cout<<"1.NHAP THONG TIN BAC SI"<<endl;
                cout<<"2.XOA THONG TIN BAC SI"<<endl;
                cout<<"3.SUA THONG TIN BAC SI"<<endl;
                cout<<"4.TIM THONG TIN BAC SI"<<endl;
                cout<<"5.XEM DANH SACH BAC SI"<<endl;
                cout<<"6.QUAY LAI"<<endl;
                cout<<"VUI LONG CHON CHUC NANG: ";
                int c;
                cin>>c;
                switch (c){
                    case 1:
                        bacsi.nhapThongTinBacSi();
                        break;
                    case 2:
                        bacsi.xoaThongTinBacSi();
                        break;
                    case 3:
                        bacsi.suaThongTinBacSi();
                        break;
                    case 4: 
                        bacsi.timThongTinBacSi();
                        break;
                    case 5:
                        inDanhSachBS();
                        break;
                    case 6:
                        goto menu;
                    default:
                        cout<<"!!!CHUC NANG KHONG PHU HOP!!!"<<endl;
                        cout<<"======VUI LONG CHON LAI======\n\n";
                        goto quanlibacsi;
                }
                goto quanlibacsi;
            case 3:
quanlikhoduoc:
                cout<<".______________________________."<<endl;
                cout<<"|        QUAN LY KHO DUOC      |"<<endl;
                cout<<".______________________________."<<endl;
                cout<<"1.NHAP THONG TIN THUOC"<<endl;
                cout<<"2.XOA THONG TIN THUOC"<<endl;
                cout<<"3.SUA THONG TIN THUOC"<<endl;
                cout<<"4.TIM THONG TIN THUOC"<<endl;
                cout<<"5.XEM DANH SACH THUOC"<<endl;
                cout<<"6.QUAY LAI"<<endl;
                cout<<"VUI LONG CHON CHUC NANG: ";
                int e;
                cin>>e;
                switch (e){
                    case 1:
                        khoduoc.nhapThongTinThuoc();
                        break;
                    case 2:
                        khoduoc.xoaThongTinThuoc();
                        break;
                    case 3:
                        khoduoc.suaThongTinThuoc();
                        break;
                    case 4: 
                        khoduoc.timThongTinThuoc();
                        break;
                    case 5:
                        inDanhSachTHUOC();
                        break;
                    case 6:
                        goto menu;
                        break;
                    default:
                        cout<<"!!!CHUC NANG KHONG PHU HOP!!!"<<endl;
                        cout<<"======VUI LONG CHON LAI======\n\n";
                        goto quanlikhoduoc;
                        break;
                }
                goto quanlikhoduoc;
                break;
            case 4:
                cout<<"____DANG XUAT THANH CONG____"<<endl;
                return 0;
            default:
                cout<<"!!!CHUC NANG KHONG PHU HOP!!!"<<endl;
                cout<<"======VUI LONG CHON LAI======\n\n";
                goto menu;
    }
}