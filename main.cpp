#include <bits/stdc++.h>
using namespace std;

struct Taikhoan {
    string usernameDN;
    string passwordDN;
    int role;    
};

int chonvaitro()
{
    int a;
    cout<<"Ban muon tao tai khoan voi vai tro:"<<endl<<"1: BENH NHAN"<<endl<<"2: BAC SI"<<endl<<"3: QUAN LY"<<endl<<"Hay nhap lua chon:";
    cin>>a; fflush(stdin);
    return a;
};

//lưu ý: khi để file text và file code khác thư mục, cần truyền thêm đường dẫn trực tiếp, VD: "D//VScode1//Project2//user.txt"

void TaoTK()
{
    cout<<"________________________________"<<endl;
    cout<<"|         TAO TAI KHOAN        |"<<endl;
    cout<<"________________________________"<<endl;
    int vaitro;
    vaitro =chonvaitro();
    string usernameTaoTK , passwordTaoTK;
    cout << "Nhap ten dang nhap: ";
    cin >> usernameTaoTK;
    cout<< "Nhap mat khau: ";
    cin >> passwordTaoTK;
    
    ofstream file("user.txt", ios::app);
    if (file.is_open())
        {
            file << usernameTaoTK <<" " << passwordTaoTK << " " << vaitro << endl;
            file.close();
            cout<<"____TAO TAI KHOAN THANH CONG____"<< endl; 
        }
    else 
        cout<<"Khong the mo tep ghi!"<<endl;
};

void suaTK() {
    cout<<"________________________________"<<endl;
    cout<<"|         SUA TAI KHOAN        |"<<endl;
    cout<<"________________________________"<<endl;
    ifstream infile("user.txt");
    ofstream outfile("temp.txt");
    string taikhoan, matkhau, role, line;
    string TK,MK,VT;
    string search_line;
    bool found = false;
    cout<<"Vui long nhap tai khoan: ";
    cin.ignore();
    getline(cin,search_line);
    if (!infile.is_open() || !outfile.is_open()) {
        cout<<"____KHONG THE MO FILE THONG TIN____"<<endl;
    }
    while (infile >> taikhoan >> matkhau >> role){
        if (taikhoan == search_line){
            cout<<"____DA TIM THAY TAI KHOAN CAN SUA____"<<endl;
            cout<<"_____VUI LONG NHAP LAI THONG TIN_____"<<endl;
            cout<<"Ten dang nhap: ";
            cin.ignore();
            getline(cin,TK);
            cout<<"Mat khau: ";
            getline(cin,MK);
            cout<<"Vai tro: ";
            getline(cin,VT);
            getline(infile,line);
            outfile << TK << " "<< MK <<" "<< VT <<" "<<endl;
            found = true;
        }   else {
            outfile << taikhoan << " " << matkhau << " " << role << endl;
        }
    }
    infile.close();
    outfile.close();
    if (found) {
        cout<<"____DA SUA TAI KHOAN THANH CONG____"<<endl;
        remove("user.txt");
        rename("temp.txt","user.txt");
    }
};

void xoaTK() {
    cout<<"________________________________"<<endl;
    cout<<"|         XOA TAI KHOAN        |"<<endl;
    cout<<"________________________________"<<endl;
    ifstream file("user.txt");
    ofstream tempfile("temp.txt");
    string taikhoan, matkhau, role, line;
    string search_line;
    bool found = false;
    cout<<"Vui long nhap tai khoan: ";
    cin.ignore();
    getline(cin,search_line);
    if (!file.is_open()){
        cout<<"____KHONG THE MO FILE THONG TIN____"<<endl;
    }
    while (file >> taikhoan >>matkhau>>role){
        if (taikhoan == search_line){
            getline(file,line);
            found = true;
        } else {
            tempfile<<taikhoan<<" "<<matkhau<<" "<<role<<endl;
        }
    }
    file.close();
    tempfile.close();
    if (found){
        remove("user.txt");
        rename("temp.txt","user.txt");
        cout<<"____XOA TAI KHOAN "<<search_line<<" THANH CONG"<<endl;
    } else {
        cout<<"____KHONG TIM THAY TAI KHOAN TREN____"<<endl;
    }
};

int Dangnhap()
{
    string usernameDN , passwordDN;
    vector<Taikhoan> taikhoan;
    
    cout<<"Vui long nhap ten dang nhap: ";
    cin>>usernameDN; 
    cout<<"Vui long nhap mat khau: ";
    cin>>passwordDN;
    
    ifstream file("user.txt"); 
    if (file.is_open()) {
        string fileUsernameDN , filePasswordDN;
        int role;
        while (file >> fileUsernameDN >> filePasswordDN>>role) {
            Taikhoan TK;
            TK.usernameDN = fileUsernameDN;
            TK.passwordDN = filePasswordDN;
            taikhoan.push_back(TK);
        }
        file.close();

        for (const auto& TK : taikhoan) {
            if (TK.usernameDN == usernameDN && TK.passwordDN == passwordDN){
                return role;}
            } 
        
    } else {
        cout<< "____KHONG THE MO FILE THONG TIN____"<<endl;
    }
    return 0;
};

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

void doiMK() {
    string nhapTK, nhapMK , MKmoi;
nhaplai:
    cout<<"Vui long nhap tai khoan: ";
    cin.ignore();
    getline(cin,nhapTK);
    cout<<"Mat khau: ";
    getline(cin,nhapMK);
    string TK , MK , VT;
    bool found = false;
    ifstream infile("user.txt");
    ofstream outfile("temp.txt");
    if (!infile.is_open() || !outfile.is_open()) {
        cout<<"____KHONG THE MO FILE THONG TIN____"<<endl;
    }
    while (infile >> TK >> MK >> VT) {
        if (nhapTK == TK && nhapMK == MK) {
            cout<<"Vui long nhap mat khau moi: ";
            getline(cin, MKmoi);
            outfile << TK << " " << MKmoi << " " << VT<<endl;
            found = true;
        }else {
            outfile << TK << " " << MK << " " << VT <<endl;
        }
    }
    infile.close();
    outfile.close();
    if (found) {
        remove("user.txt");
        rename("temp.txt","user.txt");
        cout<<"____DOI MAT KHAU THANH CONG____"<<endl;
    } else {
        cout<<"____TAI KHOAN MAT KHAU KHONG CHINH XAC____"<<endl;
        cout<<"____________VUI LONG NHAP LAI_____________"<<endl;
        goto nhaplai;
    }
};

void inDanhSachBN() {
    cout<<"________________________________"<<endl;
    cout<<"|     DANH SACH BENH NHAN      |"<<endl;
    cout<<"________________________________"<<endl;
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
    cout<<"________________________________"<<endl;
    cout<<"|       DANH SACH BAC SI       |"<<endl;
    cout<<"________________________________"<<endl;
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
    cout<<"________________________________"<<endl;
    cout<<"|        DANH SACH THUOC       |"<<endl;
    cout<<"________________________________"<<endl;
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
    int role;
    BenhNhan benhnhan;
    BacSi bacsi;
    KhoDuoc khoduoc;
    string usernameDN , passwordDN;
    int vaitro;
    cout<<".________________________________."<<endl;
    cout<<"|             LOGIN              |"<<endl;
    cout<<"|________________________________|"<<endl;
    int choice = 0;
    cout<<"Da co tai khoan? : nhap 1"<<endl<<"Chua co tai khoan? : nhap 0"<<endl;
    cin>>choice; fflush(stdin);
    if(choice==0){
        TaoTK();
    }
tryagain:
    cout<<"Vui long nhap ten dang nhap: ";
    cin>>usernameDN;
    cout<<"Vui long nhap mat khau: ";
    cin>>passwordDN;
    
    ifstream file("user.txt"); 
    if (file.is_open()) {
        string fileUsernameDN , filePasswordDN;
        int vaitro;
        while (file >> fileUsernameDN >> filePasswordDN>>vaitro) {
            if (usernameDN == fileUsernameDN && passwordDN == filePasswordDN){
                role = vaitro;
                file.close();
            }
        }
        
    } else {
        cout<< "____KHONG THE MO FILE THONG TIN____"<<endl;
    }
    
    switch (role) {
        case 1: 
        cout<<"____DANG NHAP THANH CONG VOI VAI TRO BENH NHAN____"<<endl;
        break;
        case 2:
        cout<<"____DANG NHAP THANH CONG VOI VAI TRO BAC SI____"<<endl;
        break;
        case 3: 
        cout<<"____DANG NHAP THANH CONG VOI VAI TRO QUAN LI____"<<endl;
        break;
        default: 
        cout<<"____TAI KHOAN MAT KHAU KHONG CHINH XAC____"<<endl<<"____VUI LONG DANG NHAP LAI____"<<endl;
        goto tryagain;
        break;
    };
    if (role==3)
    {
        menu:
        int a;
        cout<<"________________________________"<<endl;
        cout<<"|             MENU             |"<<endl;
        cout<<"________________________________"<<endl;
        cout<<"1.QUAN LY TAI KHOAN"<<endl;
        cout<<"2.QUAN LY BENH NHAN"<<endl;
        cout<<"3.QUAN LY BAC SI"<<endl;
        cout<<"4.QUAN LY KHO DUOC"<<endl;
        cout<<"5.DANG XUAT"<<endl;
        cout<<"VUI LONG CHON CHUC NANG: ";
        cin>>a;fflush(stdin);
        switch (a) {
            case 1:
quanlitaikhoan:
                cout<<"________________________________"<<endl;
                cout<<"|       QUAN LY TAI KHOAN      |"<<endl;
                cout<<"|______________________________|"<<endl;
                cout<<"1.TAO TAI KHOAN"<<endl;
                cout<<"2.XOA TAI KHOAN"<<endl;
                cout<<"3.SUA TAI KHOAN"<<endl;
                cout<<"4.QUAY LAI"<<endl;
                cout<<"VUI LONG CHON CHUC NANG: ";
                int d;
                cin>>d;fflush(stdin);
                switch (d) {
                    case 1:
                        TaoTK();
                        break;
                    case 2:
                        xoaTK();
                        break;
                    case 3:
                        suaTK();
                        break;
                    case 4:
                        goto menu;
                    default:
                        cout<<"!!!CHUC NANG KHONG PHU HOP!!!"<<endl;
                        cout<<"VUI LONG CHON LAI"<<endl;
                        goto quanlitaikhoan;
                        break;
                }
                goto quanlitaikhoan;
                break;
            case 2:
quanlibenhnhan:
                cout<<"________________________________"<<endl;
                cout<<"|       QUAN LY BENH NHAN      |"<<endl;
                cout<<"|______________________________|"<<endl;
                cout<<"1.NHAP THONG TIN BENH NHAN"<<endl;
                cout<<"2.XOA THONG TIN BENH NHAN"<<endl;
                cout<<"3.SUA THONG TIN BENH NHAN"<<endl;
                cout<<"4.TIM THONG TIN BENH NHAN"<<endl;
                cout<<"5.XEM DANH SACH BENH NHAN"<<endl;
                cout<<"6.QUAY LAI"<<endl;
                cout<<"VUI LONG CHON CHUC NANG: ";
                int b;
                cin>>b;fflush(stdin);
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
                        break;
                    default:
                        cout<<"!!!CHUC NANG KHONG PHU HOP!!!"<<endl;
                        cout<<"VUI LONG CHON LAI"<<endl;
                        goto quanlibenhnhan;
                        break;
                }
                goto quanlibenhnhan;
                break;
            case 3:
quanlibacsi:
                cout<<"________________________________"<<endl;
                cout<<"|        QUAN LY BAC SI        |"<<endl;
                cout<<"________________________________"<<endl;
                cout<<"1.NHAP THONG TIN BAC SI"<<endl;
                cout<<"2.XOA THONG TIN BAC SI"<<endl;
                cout<<"3.SUA THONG TIN BAC SI"<<endl;
                cout<<"4.TIM THONG TIN BAC SI"<<endl;
                cout<<"5.XEM DANH SACH BAC SI"<<endl;
                cout<<"6.QUAY LAI"<<endl;
                cout<<"VUI LONG CHON CHUC NANG: ";
                int c;
                cin>>c;fflush(stdin);
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
                        break;
                    default:
                        cout<<"!!!CHUC NANG KHONG PHU HOP!!!"<<endl;
                        cout<<"VUI LONG CHON LAI"<<endl;
                        goto quanlibacsi;
                        break;
                }
                goto quanlibacsi;
                break;
            case 4:
quanlikhoduoc:
                cout<<"________________________________"<<endl;
                cout<<"|        QUAN LY KHO DUOC      |"<<endl;
                cout<<"________________________________"<<endl;
                cout<<"1.NHAP THONG TIN THUOC"<<endl;
                cout<<"2.XOA THONG TIN THUOC"<<endl;
                cout<<"3.SUA THONG TIN THUOC"<<endl;
                cout<<"4.TIM THONG TIN THUOC"<<endl;
                cout<<"5.XEM DANH SACH THUOC"<<endl;
                cout<<"6.QUAY LAI"<<endl;
                cout<<"VUI LONG CHON CHUC NANG: ";
                int e;
                cin>>e;fflush(stdin);
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
                        cout<<"VUI LONG CHON LAI"<<endl;
                        goto quanlikhoduoc;
                        break;
                }
                goto quanlikhoduoc;
                break;
            case 5:
                usernameDN = "";
                passwordDN = "";
                role=0;
                cout<<"____DANG XUAT THANH CONG____"<<endl;
                goto tryagain;
            default:
                cout<<"!!!CHUC NANG KHONG PHU HOP!!!"<<endl;
        }
    }
    if (role == 1){
menu2:
        int a;
        cout<<"________________________________"<<endl;
        cout<<"|             MENU             |"<<endl;
        cout<<"________________________________"<<endl;
        cout<<"1.XEM THONG TIN CA NHAN"<<endl;
        cout<<"2.DOI MAT KHAU"<<endl;
        cout<<"3.DANG XUAT"<<endl;
        cout<<"VUI LONG CHON CHUC NANG: ";
        cin>>a;fflush(stdin);
        switch (a) {
            case 1:{
                string line;
                    ifstream file("thongtinbenhnhan.txt");
                    if (!file.is_open()) {
                        cout<<"____KHONG THE MO FILE THONG TIN____"<<endl;
                        }
                    while (getline(file,line)){
                        if (line == "Ten dang nhap: " + usernameDN) {
                            cout<<"____THONG TIN CA NHAN____"<<endl;
                                for (int i=0;i<6;i++) {
                                        getline(file,line);
                                        cout<< line <<endl;
                                    }
                                }else {
                                    cout<<"____THONG TIN BENH NHAN KHONG TON TAI____"<<endl;
                                }
                    };
                break;
                }
            case 2:
                doiMK();
                usernameDN = "";
                passwordDN = "";
                role=0;
                goto tryagain;
                break;
            case 3:
                usernameDN="";
                passwordDN="";
                cout<<"____DANG XUAT THANH CONG____"<<endl;
                goto tryagain;
                break;
            
        }goto menu2;
    }
    if (role == 2)
    {
menu3:
        int a;
        cout<<"________________________________"<<endl;
        cout<<"|            MENU             |"<<endl;
        cout<<"________________________________"<<endl;
        cout<<"1.QUAN LI THONG TIN CA NHAN"<<endl;
        cout<<"2.QUAN LI BENH NHAN"<<endl;
        cout<<"3.XEM DANH SACH THUOC"<<endl;
        cout<<"4.DANG XUAT"<<endl;
        cout<<"VUI LONG CHON CHUC NANG: ";
        cin>>a;fflush(stdin);
        switch (a) {
            case 1:{
                cout<<"________________________________"<<endl;
                cout<<"|  QUAN LI THONG TIN CA NHAN   |"<<endl;
                cout<<"________________________________"<<endl;
                cout<<"1.XEM THONG TIN CA NHAN"<<endl;
                cout<<"2.DOI MAT KHAU"<<endl;
                cout<<"3.QUAY LAI"<<endl;
                cout<<"VUI LONG CHON CHUC NANG: ";
                int b;
                cin>>b;fflush(stdin);
                switch (b) {
                    case 1:{
                        string line;
                        ifstream file("thongtinbacsi.txt");
                        if (!file.is_open()) {
                            cout<<"____KHONG THE MO FILE THONG TIN____"<<endl;
                            }
                        while (getline(file,line)){
                            if (line == "Ten dang nhap: " + usernameDN) {
                                    cout<<"____THONG TIN CA NHAN____"<<endl;
                                    for (int i=0;i<8;i++) {
                                        getline(file,line);
                                        cout<< line <<endl;
                                    }
                                }else {
                                    cout<<"____THONG TIN BAC SI KHONG TON TAI____"<<endl;
                                    cout<<"Bam ENTER de quay lai Menu";
                                    char input=cin.get();
                                    if (input == '\n'){
                                        goto menu3;
                                    }
                                }
                        };
                        break;
                    }
                    case 2:
                        doiMK();
                        usernameDN = "";
                        passwordDN = "";
                        role=0;
                        goto tryagain;
                        break;
                    case 3:
                        goto menu3;
                        break;
                    default :
                        cout<<"____CHUC NANG KHONG PHU HOP____"<<endl;
                        goto menu3;
                }
                goto menu3;}
            case 2:
quanlibenhnhan2:
                cout<<"________________________________"<<endl;
                cout<<"|       QUAN LY BENH NHAN      |"<<endl;
                cout<<"________________________________"<<endl;
                cout<<"1.NHAP THONG TIN BENH NHAN"<<endl;
                cout<<"2.XOA THONG TIN BENH NHAN"<<endl;
                cout<<"3.SUA THONG TIN BENH NHAN"<<endl;
                cout<<"4.TIM THONG TIN BENH NHAN"<<endl;
                cout<<"5.XEM DANH SACH BENH NHAN"<<endl;
                cout<<"6.QUAY LAI"<<endl;
                cout<<"VUI LONG CHON CHUC NANG: ";
                int b;
                cin>>b;fflush(stdin);
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
                        goto menu3;
                        break;
                    default:
                        cout<<"!!!CHUC NANG KHONG PHU HOP!!!"<<endl;
                        cout<<"VUI LONG CHON LAI"<<endl;
                        goto quanlibenhnhan;
                        break;
                }
                goto quanlibenhnhan2;
                break;
            case 3: 
                inDanhSachTHUOC();
                goto menu2;
                break;
            case 4:
                usernameDN="";
                passwordDN="";
                cout<<"____DANG XUAT THANH CONG____"<<endl;
                goto tryagain;
            default :
                cout<<"____CHUC NANG KHONG PHU HOP____"<<endl;
                goto menu2;
        }
    }
    return 0;
}; 