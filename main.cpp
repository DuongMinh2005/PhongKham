#include <bits/stdc++.h>
using namespace std;

//lưu ý: khi để file text và file code khác thư mục, cần truyền thêm đường dẫn trực tiếp, VD: "D//VScode1//Project2//user.txt"

class Person {
    protected:
        string tenDangNhap;
        string ten;
        int tuoi;
        string diachi;
    public:
        void setTenDangNhap(const string& tenDN) {
            tenDangNhap = tenDN;
        };
        string getTenDangNhap() const {
            return tenDangNhap;
        };
};

class BacSi : public Person {
    private:
        string masoBacSi;
        string chucvu;
        string chuyenkhoa;
        int kinhnghiem;
    public:
        BacSi() {
            tenDangNhap = "";
            ten = "";
            tuoi = 0;
            diachi = "";
            masoBacSi = "";
            chucvu="";
            chuyenkhoa="";
            kinhnghiem =0;
        };
        void nhapThongTinBacSi();
        void xoaThongTinBacSi();
        bool suaThongTinBacSi();
        void timThongTinBacSi();
};

void BacSi::nhapThongTinBacSi() {
        cout << "____NHAP THONG TIN BAC SI____" << endl;
        cout << "Ten dang nhap: ";
        cin.ignore();
        getline(cin, tenDangNhap);
        cout << "Ten: ";
        getline(cin, ten);
        cout << "Tuoi: ";
        cin >> tuoi;
        cin.ignore();
        cout << "Dia chi: ";
        getline(cin, diachi);
        cout << "Ma so: ";
        getline(cin, masoBacSi);
        cout<< "Chuc vu: ";
        getline(cin, chucvu);
        cout<< "Chuyen khoa: ";
        getline(cin, chuyenkhoa);
        cout << "Kinh nghiem: ";
        cin >> kinhnghiem;
        ofstream file("thongtinbacsi.txt", ios::app); 

        if (file.is_open()) {
            file << "Ten dang nhap: " << tenDangNhap << endl;
            file << "Ten: " << ten << endl;
            file << "Tuoi: " << tuoi << endl;
            file << "Dia chi: " << diachi << endl;
            file << "Ma so : " << masoBacSi << endl;
            file << "Chuc vu: " << chucvu << endl;
            file << "Chuyen khoa: "<< chuyenkhoa <<endl;
            file << "Kinh nghiem: "<< kinhnghiem << " nam"<<endl;
            file << "--------------------------------------" << endl;
            file.close();
            cout << "====NHAP THONG TIN THANH CONG===" << endl;
        } else 
            cout << "___KHONG THE MO FILE THONG TIN___" << endl;
};

void BacSi::xoaThongTinBacSi() {
        cout<<"____NHAP TAI KHOAN MUON XOA____"<<endl;
        cout << "Ten dang nhap: ";
        cin.ignore();
        getline(cin, tenDangNhap);
        string line;
        ifstream inFile("thongtinbacsi.txt");
        ofstream outFile("temp.txt");
        if (!inFile.is_open()) {
            cout << "____KHONG THE MO FILE THONG TIN____" << endl;
            return;
        }
        bool found = false;
        string search_line = "Ten dang nhap: " + tenDangNhap;

        while (getline(inFile, line)) {
            if (line == search_line) {
                found = true;
                for (int i = 0; i < 8; ++i) {
                    // Bo qua 8 dong thong tin neu khong lien quan den bac si
                    getline(inFile, line);
                }
            } else {
                // Ghi dong thong tin vao file moi neu dong nay khong can phai xoa 
                outFile << line << endl;
            }
        }

        inFile.close();
        outFile.close();

        if (found) {
            remove("thongtinbacsi.txt");
            rename("temp.txt", "thongtinbacsi.txt");
            cout << "____XOA THONG TIN BAC SI THANH CONG____" << endl;
        } else
            cout << "____KHONG TIM THAY TAI KHOAN CAN XOA____" << endl;
};

bool BacSi::suaThongTinBacSi() {
    ifstream file("thongtinbacsi.txt");
    ofstream tempfile("temp.txt"); // Tep tam thoi cho du lieu de sua doi

    if (file.is_open() && tempfile.is_open()) {
        string line;
        bool found = false;
        cout << "____SUA THONG TIN BAC SI____" << endl;
        cout << "Vui long nhap ten dang nhap: ";
        cin.ignore();
        getline(cin, tenDangNhap);

      while (getline(file, line)) {
        if (line == "Ten dang nhap: " + tenDangNhap) {   // Tim thay thong tin bac si
            cout << "____NHAP THONG TIN MOI____" << endl;
            cout << "Ten dang nhap: ";
            cin.ignore();
            getline(cin, tenDangNhap);
            cout << "Ten: "; getline(cin, ten);
            cout << "Tuoi: "; cin >> tuoi;
            cin.ignore();
            cout << "Dia chi: "; getline(cin, diachi);
            cout << "Ma so: "; getline(cin, masoBacSi);
            cout<< "Chuc vu: "; getline(cin, chucvu);
            cout<< "Chuyen khoa: "; getline(cin, chuyenkhoa);
            cout << "Kinh nghiem: ";
            cin >> kinhnghiem;
            fflush(stdin);

            tempfile << "Ten dang nhap: " << tenDangNhap << endl;
            tempfile << "Ten: " << ten << endl;
            tempfile << "Tuoi: " << tuoi << endl;
            tempfile << "Dia chi: " << diachi << endl;
            tempfile << "Ma so : " << masoBacSi << endl;
            tempfile << "Chuc vu: " << chucvu << endl;
            tempfile << "Chuyen khoa: "<< chuyenkhoa <<endl;
            tempfile << "Kinh nghiem: "<< kinhnghiem << " nam"<<endl;
            tempfile << "--------------------------------------" << endl;
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
        remove("thongtinbacsi.txt");
        rename("temp.txt", "thongtinbacsi.txt");

        cout << "____SUA THONG TIN THANH CONG____" << endl;
      } else {
        cout << "Khong tim thay bac si voi ten dang nhap: " << tenDangNhap << endl;
        remove("temp.txt");
      }

      return found;
    } else {
      cout << "____KHONG THE MO FILE THONG TIN____" << endl;
      return false;
    }
};

void BacSi::timThongTinBacSi() {
    ifstream file("thongtinbacsi.txt");
    if (!file.is_open()) {
        cout<<"____KHONG THE MO FILE THONG TIN____"<<endl;
    }
    string line;
    string search_line;
    bool found = false;
    cout<<"____TIM KIEM THONG TIN BAC SI____"<<endl;
    cout<<"Nhap ten dang nhap: ";
    cin.ignore();
    getline(cin,search_line);
    while (getline(file,line))
    {
        if (line == "Ten dang nhap: " + search_line) {
            for (int i=0;i<8;i++) {
                getline(file,line);
                cout<< line <<endl;
            }
            found = true;
        }
    }
    if (!found) {
        cout<<"____KHONG TIM THAY THONG TIN BAC SI____"<<endl;
    }
};

class KhoDuoc {
    private:
        string masothuoc;
        string tenthuoc;
        string suatxu;
        string ngaysanxuat;
        string hansudung;
        string tacdung;
        int soluong;
        string dongia;
    public:
        KhoDuoc() {
            masothuoc = "";
            tenthuoc = "";
            suatxu = "";
            ngaysanxuat = "";
            hansudung = "";
            tacdung = "";
            soluong = 0;
            dongia = "";
        };
        void nhapThongTinThuoc();
        void xoaThongTinThuoc();
        bool suaThongTinThuoc();
        void timThongTinThuoc();
        
        void setMaSoThuoc(const string& MSThuoc) {
            masothuoc = MSThuoc;
        };
        string getMaSoThuoc() const {
        return masothuoc;
        };
};

void KhoDuoc::nhapThongTinThuoc() {
    cout<<"____NHAP THONG TIN THUOC____"<<endl;
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
    cout<<"Tac dung: ";
    getline(cin,tacdung);
    cout<<"So luong: ";
    cin>>soluong;fflush(stdin);
    cout<<"Don gia: ";
    getline(cin,dongia);

    ofstream file("thongtinkhoduoc.txt", ios::app);
    if (file.is_open()) {
        
        file<<"Ma so thuoc: "<< masothuoc <<endl;
        file<<"Ten thuoc: "<< tenthuoc <<endl;
        file<<"Noi san xuat: "<< suatxu <<endl;
        file<<"Ngay san xuat: "<< ngaysanxuat <<endl;
        file<<"Han sau dung: "<< hansudung <<endl;
        file<<"Tac dung: "<< hansudung <<endl;
        file<<"So luong: "<< soluong <<endl;
        file<<"Don gia: "<< dongia <<" vnd"<<endl;
        file<<"--------------------------------"<<endl;
        file.close();
        cout<<"____NHAP THONG TIN THANH CONG____"<<endl;
    } else {
        cout<<"____KHONG THE MO FILE THONG TIN____"<<endl;
    }
};

void KhoDuoc::xoaThongTinThuoc() {
    cout<<"____XOA THONG TIN THUOC____"<<endl;
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
        cout<<"____XOA THONG TIN THUOC THANH CONG____"<<endl;
    } else {
        cout<<"____KHONG TIM THAY TAI KHOAN CAN XOA____"<<endl;
    }
};

bool KhoDuoc::suaThongTinThuoc() {
    ifstream file("thongtinkhoduoc.txt");
    ofstream tempfile("temp.txt"); // Tep tam thoi cho du lieu de sua doi

    if (file.is_open() && tempfile.is_open()) {
        string line;
        bool found = false;
        cout << "____SUA THONG TIN THUOC____" << endl;
        cout << "Vui long nhap ma so thuoc: ";
        cin.ignore();
        getline(cin, masothuoc);

      while (getline(file, line)) {
        if (line == "Ma so thuoc: " + masothuoc) {   // Tim thay thong tin bac si
            cout << "____NHAP THONG TIN MOI____" << endl;
            cout<<"____NHAP THONG TIN THUOC____"<<endl;
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
            tempfile<<"--------------------------------"<<endl;
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

        cout << "____SUA THONG TIN THANH CONG____" << endl;
      } else {
        cout << "Khong tim thay thong tin thuoc voi ma so: " << masothuoc << endl;
        remove("temp.txt");
      }

      return found;
    } else {
      cout << "____KHONG THE MO FILE THONG TIN____" << endl;
      return false;
    }
};

void KhoDuoc::timThongTinThuoc() {
    ifstream file("thongtinkhoduoc.txt");
    string line;
    string search_line;
    bool found = false;
    cout<<"____TIM KIEM THONG TIN THUOC____"<<endl;
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




class BenhNhan : public Person {
private:
    string loaiBenh;
    double vienPhi;
public:
    BenhNhan() {
        tenDangNhap = "";
        ten = "";
        tuoi = 0;
        diachi = "";
        loaiBenh = "";
        vienPhi = 0.0;
    }
    void xoaThongTinBenhNhan();
    void nhapThongTinBenhNhan();
    bool suaThongTinBenhNhan();
    void timThongTinBenhNhan();
};

void BenhNhan::xoaThongTinBenhNhan() {
        cout<<"Nhap ten tai khoan can xoa."<<endl;
        cout << "Ten dang nhap: ";
        cin.ignore();
        getline(cin, tenDangNhap);
        string line;
        ifstream inFile("thongtinbenhnhan.txt");
        ofstream outFile("temp.txt");

        if (!inFile.is_open()) {
            cout << "Khong the mo file de doc." << endl;
            return;
        }

        bool found = false;
        string search_line = "Ten dang nhap: " + tenDangNhap;

        while (getline(inFile, line)) {
            if (line == search_line) {
                found = true;
                for (int i = 0; i < 6; ++i) {
                    // Bo qua 6 dong thong tin neu khong lien quan den benh nhan 
                    getline(inFile, line);
                }
            } else {
                // Ghi dong th�ng tin v�o file moi neu dong nay khong can phai xoa 
                outFile << line << endl;
            }
        }

        inFile.close();
        outFile.close();

        if (found) {
            remove("thongtinbenhnhan.txt");
            rename("temp.txt", "thongtinbenhnhan.txt");
            cout << "Da xoa thong tin cua benh nhan khoi file." << endl;
        } else {
            cout << "Khong tim thay thong tin cua benh nhan trong file." << endl;
        }
};

void BenhNhan::nhapThongTinBenhNhan() {
        cout << "____NHAP THONG TIN BENH NHAN____" << endl;
        cout << "Ten dang nhap: ";
        cin.ignore();
        getline(cin, tenDangNhap);
        cout << "Ten: ";
        getline(cin, ten);
        cout << "Tuoi: ";
        cin >> tuoi;
        cin.ignore();
        cout << "Dia chi: ";
        getline(cin, diachi);
        cout << "Loai benh: ";
        getline(cin, loaiBenh);
        cout << "Vien phi: ";
        cin >> vienPhi;
        ofstream file("thongtinbenhnhan.txt", ios::app); 

        if (file.is_open()) {
            file << "Ten dang nhap: " << tenDangNhap << endl;
            file << "Ten: " << ten << endl;
            file << "Tuoi: " << tuoi << endl;
            file << "Dia chi: " << diachi << endl;
            file << "Loai benh: " << loaiBenh << endl;
            file << "Vien phi: " << vienPhi <<" vnd"<< endl;
            file << "--------------------------------------" << endl;
            file.close();
            cout << "____NHAP THONG TIN THANH CONG____" << endl;
        } else {
            cout << "___KHONG THE MO FILE THONG TIN___" << endl;
        }
};

bool BenhNhan::suaThongTinBenhNhan() {
    ifstream file("thongtinbenhnhan.txt");
    ofstream tempFile("temp.txt"); // T?p t?m th?i cho d? li?u d� s?a d?i

    if (file.is_open() && tempFile.is_open()) {
        cout<<"____SUA THONG TIN BENH NHAN____"<<endl;
        string line;
        bool found = false;
        cout << "Vui long nhap ten dang nhap: ";
        cin.ignore();
        getline(cin, tenDangNhap);

      while (getline(file, line)) {
        if (line == "Ten dang nhap: " + tenDangNhap) {
            // Tim thay thong tin benh nhan
            cout << "Nhap thong tin moi cho benh nhan:" << endl;
            cout << "Nhap thong tin benh nhan:" << endl;
            cout << "Ten dang nhap: ";
            cin.ignore();
            getline(cin, tenDangNhap);
            cout << "Ten: ";
            getline(cin, ten);
            cout << "Tuoi: ";
            cin >> tuoi;
            cin.ignore(); 
            cout << "Dia chi: ";
            getline(cin, diachi);
            cout << "Loai benh: ";
            getline(cin, loaiBenh);
            cout << "Vien phi: ";
            cin >> vienPhi;
            cin.ignore();      

            tempFile << "Ten dang nhap: " << tenDangNhap << endl;
            tempFile << "Ten: " << ten << endl;
            tempFile << "Tuoi: " << tuoi << endl;
            tempFile << "Dia chi: " << diachi << endl;
            tempFile << "Loai benh: " << loaiBenh << endl;
            tempFile << "Vien phi: " << vienPhi << endl;
            tempFile << "--------------------------------------" << endl;
            found = true;

            // B? qua c�c d�ng cu
            for (int i = 0; i < 6; ++i) {
                getline(file, line);
            }
        } else {
          tempFile << line << endl;
        }
      }

      file.close();
      tempFile.close();

      if (found) {
        // Xoa tep goc va doi ten tep tam thoi
        remove("thongtinbenhnhan.txt");
        rename("temp.txt", "thongtinbenhnhan.txt");

        cout << "Thong tin benh nhan da duoc sua thanh cong." << endl;
      } else {
        cout << "Khong tim thay benh nhan voi ten dang nhap: " << tenDangNhap << endl;
        remove("temp.txt");
      }

      return found;
    } else {
      cout << "Loi mo file de sua thong tin." << endl;
      return false;
    }
};

void BenhNhan::timThongTinBenhNhan() {
    ifstream file("thongtinbenhnhan.txt");
    if (!file.is_open()) {
        cout<<"____KHONG THE MO FILE THONG TIN____"<<endl;
    }
    string line;
    string search_line;
    bool found = false;
    cout<<"____TIM KIEM THONG TIN BENH NHAN____"<<endl;
    cout<<"Nhap ten dang nhap: ";
    cin.ignore();
    getline(cin,search_line);
    while (getline(file,line))
    {
        if (line == "Ten dang nhap: " + search_line) {
            for (int i=0;i<6;i++) {
                getline(file,line);
                cout<< line <<endl;
            }
            found = true;
        }
    }
    if (!found) {
        cout<<"____KHONG TIM THAY THONG TIN BENH NHAN____"<<endl;
    }
};

void inDanhSachBN() {
    cout<<".______________________________."<<endl;
    cout<<"|     DANH SACH BENH NHAN      |"<<endl;
    cout<<".______________________________."<<endl;
    string line;
    ifstream file("thongtinbenhnhan.txt");
    if (!file.is_open()) {
        cout<<"____KHONG THE MO FILE THONG TIN____"<<endl;
    }
    while (getline(file,line)) {
        cout<< line <<endl;
    }
};

void inDanhSachBS() {
    cout<<".______________________________."<<endl;
    cout<<"|       DANH SACH BAC SI       |"<<endl;
    cout<<".______________________________."<<endl;
    string line;
    ifstream file("thongtinbacsi.txt");
    if (!file.is_open()) {
        cout<<"____KHONG THE MO FILE THONG TIN____"<<endl;
    }
    while (getline(file,line)) {
        cout<< line <<endl;
    }
};

void inDanhSachTHUOC() {
    cout<<".______________________________."<<endl;
    cout<<"|        DANH SACH THUOC       |"<<endl;
    cout<<".______________________________."<<endl;
    string line;
    ifstream file("thongtinkhoduoc.txt");
    if (!file.is_open()) {
        cout<<"____KHONG THE MO FILE THONG TIN____"<<endl;
    }
    while (getline(file,line)) {
        cout<< line <<endl;
    }
};

int main(){
    BenhNhan benhnhan;
    BacSi bacsi;
    KhoDuoc khoduoc;
menu:
        int a;
        cout<<".______________________________."<<endl;
        cout<<"|             MENU             |"<<endl;
        cout<<".______________________________."<<endl;
        cout<<"1.QUAN LY BENH NHAN"<<endl;
        cout<<"2.QUAN LY BAC SI"<<endl;
        cout<<"3.QUAN LY KHO DUOC"<<endl;
        cout<<"4.DANG XUAT"<<endl;
        cout<<"VUI LONG CHON CHUC NANG: ";
        cin>>a;
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