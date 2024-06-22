#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>>


struct Taikhoan {
    char usernameDN[50];
    char passwordDN[50];
    int role;    
};

int chonvaitro(){
    int a;
    printf("Ban muon tao tai khoan voi vai tro gi?\n1: Benh Nhan\n2: Bac Si\n3: Quan Li\n");
    scanf("%d", &a);fflush(stdin);
    return a;
}


void TaoTK(){
    printf(".______________________________.\n");
    printf("|         TAO TAI KHOAN        |\n");
    printf(".______________________________.\n");
    int vaitro;
    vaitro = chonvaitro();

    char usernameTaoTK[50], passwordTaoTK[50]; 
    fflush(stdin);
    printf("Nhap ten dang nhap: ");
    fgets(usernameTaoTK, sizeof(usernameTaoTK), stdin);
    printf("Nhap mat khau: ");
    fgets(passwordTaoTK, sizeof(passwordTaoTK), stdin);

    FILE *file = fopen("user.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s %s %d\n", usernameTaoTK, passwordTaoTK, vaitro);
        fclose(file);
        printf("____TAO TAI KHOAN THANH CONG____\n");
    } else
        printf("____KHONG THE MO FILE THONG TIN____\n");
}
void suaTK() {
    printf(".______________________________.\n");
    printf("|         SUA TAI KHOAN        |\n");
    printf(".______________________________.\n");

    FILE *infile = fopen("user.txt", "r");
    FILE *outfile = fopen("temp.txt", "w");

    if (infile == NULL || outfile == NULL) {
        printf("____KHONG THE MO FILE THONG TIN____\n");
        if (infile != NULL) fclose(infile);
        if (outfile != NULL) fclose(outfile);
        return;
    }

    char taikhoan[50], matkhau[50];
    int role;
    char TK[50], MK[50], VT[50];
    char search_line[50];
    int found = 0;

    printf("Vui long nhap tai khoan: ");
    fgets(search_line, sizeof(search_line), stdin);
    search_line[strcspn(search_line, "\n")] = '\0'; 

    while (fscanf(infile, "%s %s %d", taikhoan, matkhau, &role) != EOF) {
        if (strcmp(taikhoan, search_line) == 0 && !found) {
            printf("____DA TIM THAY TAI KHOAN CAN SUA____\n");
            printf("____VUI LONG NHAP LAI THONG TIN____\n");

            printf("Ten dang nhap: ");
            fgets(TK, sizeof(TK), stdin);
            TK[strcspn(TK, "\n")] = '\0'; 
            printf("Mat khau: ");
            fgets(MK, sizeof(MK), stdin);
            MK[strcspn(MK, "\n")] = '\0'; 

            printf("Vai tro: ");
            fgets(VT, sizeof(VT), stdin);
            VT[strcspn(VT, "\n")] = '\0'; 

            fprintf(outfile, "%s %s %d\n", TK, MK, atoi(VT));
            found = 1;
        } else {
            fprintf(outfile, "%s %s %d\n", taikhoan, matkhau, role);
        }
    }

    fclose(infile);
    fclose(outfile);

    if (found) {
        printf("____DA SUA TAI KHOAN THANH CONG____\n");
        remove("user.txt");
        rename("temp.txt", "user.txt");
    } else {
        printf("____KHONG TIM THAY TAI KHOAN TREN____\n");
        remove("temp.txt"); 
    }
}

void xoaTK() {
    printf(".______________________________.\n");
    printf("|         XOA TAI KHOAN        |\n");
    printf(".______________________________.\n");

    FILE *file = fopen("user.txt", "r");
    FILE *tempfile = fopen("temp.txt", "w");

    if (file == NULL || tempfile == NULL) {
        printf("____KHONG THE MO FILE THONG TIN____\n");
        return;
    }

    char taikhoan[50], matkhau[50], role[50];
    char search_line[50];
    bool found = false;

    printf("Vui long nhap tai khoan: ");
    fgets(search_line, sizeof(search_line), stdin);
    search_line[strcspn(search_line, "\n")] = '\0'; // loại bỏ kí tự newline

    while (fscanf(file, "%s %s %s", taikhoan, matkhau, role) != EOF) {
        if (strcmp(taikhoan, search_line) == 0) {
            found = true;
        } else {
            fprintf(tempfile, "%s %s %s\n", taikhoan, matkhau, role);
        }
    }

    fclose(file);
    fclose(tempfile);

    if (found) {
        remove("user.txt");
        rename("temp.txt", "user.txt");
        printf("____XOA TAI KHOAN %s THANH CONG____\n", search_line);
    } else {
        printf("____KHONG TIM THAY TAI KHOAN TREN____\n");
    }
}

int Dangnhap() {
    char usernameDN[50], passwordDN[50];
    struct Taikhoan taikhoan[100]; 
    int taikhoanCount = 0;

    printf("Vui long nhap ten dang nhap: ");
    fgets(usernameDN, sizeof(usernameDN), stdin);
    usernameDN[strcspn(usernameDN, "\n")] = '\0'; 

    printf("Vui long nhap mat khau: ");
    fgets(passwordDN, sizeof(passwordDN), stdin);
    passwordDN[strcspn(passwordDN, "\n")] = '\0'; 

    FILE *file = fopen("user.txt", "r");
    if (file != NULL) {
        char fileUsernameDN[50], filePasswordDN[50];
        int role;

        while (fscanf(file, "%s %s %d", fileUsernameDN, filePasswordDN, &role) != EOF) {
            strcpy(taikhoan[taikhoanCount].usernameDN, fileUsernameDN);
            strcpy(taikhoan[taikhoanCount].passwordDN, filePasswordDN);
            taikhoan[taikhoanCount].role = role;
            taikhoanCount++;
        }
        fclose(file);

        for (int i = 0; i < taikhoanCount; i++) {
            if (strcmp(taikhoan[i].usernameDN, usernameDN) == 0 && strcmp(taikhoan[i].passwordDN, passwordDN) == 0) {
                return taikhoan[i].role;
            }
        }
    } else {
        printf("____KHONG THE MO FILE THONG TIN____\n");
    }
    return 0;
}

// struct Person {
//     char tenDangNhap[50];
//     char ten[50];
//     int tuoi;
//     char diachi[100];
// };
// void setTenDangNhap(struct Person *person, const char* tenDN) {
//     strcpy(person->tenDangNhap, tenDN);
// }
// char* getTenDangNhap(struct Person *person) {
//     return person->tenDangNhap;
// }

typedef struct thuoc{
    char masothuoc[100];
    char tenthuoc[100];
    char suatxu[100];
    char ngaysanxuat[100];
    char hansudung[100];
    char tacdung[100];
    int soluong;
    char dongia[100];
}KhoDuoc;

void nhapThongTinThuoc(KhoDuoc* thuoc){
    printf("____NHAP THONG TIN THUOC____\n");
    printf("Ma so thuoc: ");
    getchar();
    fgets(thuoc->masothuoc,sizeof(thuoc->masothuoc),stdin);
    printf("Ten thuoc: ");
    fgets(thuoc->tenthuoc, sizeof(thuoc->tenthuoc),stdin);
    printf("Noi san xuat: ");
    fgets(thuoc->suatxu, sizeof(thuoc->suatxu),stdin);
    printf("Ngay san xuat: ");
    fgets(thuoc->ngaysanxuat, sizeof(thuoc->ngaysanxuat), stdin);
    printf("Han su dung :");
    fgets(thuoc->hansudung, sizeof(thuoc->hansudung),stdin);
    printf("Tac dung cua thuoc: ");
    fgets(thuoc->tacdung, sizeof(thuoc->tacdung),stdin);
    printf("So luong: ");
    scanf("%d",&thuoc->soluong);
    printf("Don gia: ");
    getchar();
    fgets(thuoc->dongia,sizeof(thuoc->dongia),stdin);

    FILE *file = fopen ("thongtinkhoduoc.txt","a");
        if(file != NULL){
            fprintf(file,"Ma so thuoc: %s", thuoc->masothuoc);
            fprintf(file, "Ten thuoc: %s", thuoc->tenthuoc);
            fprintf(file, "Noi san xuat: %s", thuoc->suatxu);
            fprintf(file, "Han su dung: %s", thuoc->hansudung);
            fprintf(file, "Tac dung cua thuoc: %s", thuoc->tacdung);
            fprintf(file, "So luong: %d\n", thuoc->soluong);
            fprintf(file, "Don gia: %s", thuoc->dongia);
            fprintf(file, "------------------------------------\n");\
            fclose(file);
            printf("____NHAP THONG TIN THANH CONG____\n");
        }
        else {
            printf("____KHONG THE MO FILE THONG TIN____\n");
        }
}

void xoaThongTinThuoc(){
    char masothuoc[100];
    printf("____XOA THONG TIN THUOC____\n");
    printf("Nhap ma so thuoc: ");
    fflush(stdin);
    fgets(masothuoc,sizeof(masothuoc),stdin);

    FILE *infile = fopen("thongtinkhoduoc.txt","r");
    FILE *outfile = fopen("tempt.txt","w");
        if( infile ==NULL || outfile ==NULL){
            printf("____KHONG THE MO FILE THONG TIN____\n");
            return;
        }
        char line[256];
        int found=0;
        char search_line[150];
        snprintf(search_line, sizeof(search_line),"Ma so thuoc: %s", masothuoc);

        while(fgets(line,sizeof(line),infile)){
            if(strcmp(line, search_line)==0){
                found =1;
                for( int i=0; i<8;++i)
                    fgets(line,sizeof(line),infile);
            }
            else{
                fputs(line,outfile);
            }
        }
        fclose(infile);
        fclose(outfile);

        if( found){
            remove("thongtinkhoduoc.txt");
            rename("tempt.txt","thongtinkhoduoc.txt");
            printf("____XOA THONG TIN THUOC THANH CONG____\n");
        }
        else{
            printf("____KHONG TIM THAY TAI KHOAN CAN XOA____\n");
            remove("tempt.txt");
        }
}

int suaThongTinThuoc(){
    char masothuoc[100];
    KhoDuoc thuoc;
    printf("____SUA THONG TIN THUOC____\n");
    printf("Vui long nhap ma so thuoc: ");
    getchar();
    fgets(masothuoc,sizeof(masothuoc),stdin);

    FILE *infile = fopen("thongtinkhoduoc.txt","r");
    FILE *tempfile = fopen("tempt.txt","w");
    if( infile ==NULL||tempfile == NULL ){
        printf("____KHONG THE MO FILE THONG TIN____\n");
        return 0;
    }
    char line[256];
    char search_line[150];
    int found =0;
    snprintf(search_line,sizeof(search_line),"Ma so thuoc: %s",masothuoc);

    while(fgets(line,sizeof(line),infile)){
        if(strcmp(line,search_line)==0){
            found =1;
            printf("____NHAP THONG TIN MOI____\n");
            printf("Ma so thuoc: ");
            getchar();
            fgets(thuoc.masothuoc,sizeof(thuoc.masothuoc),stdin);
            printf("Ten thuoc: ");
            fgets(thuoc.tenthuoc, sizeof(thuoc.tenthuoc),stdin);
            printf("Noi san xuat: ");
            fgets(thuoc.suatxu,sizeof(thuoc.suatxu),stdin);
            printf("Ngay san xuat: ");
            fgets(thuoc.ngaysanxuat,sizeof(thuoc.ngaysanxuat),stdin);
            printf("Han su dung: ");
            fgets(thuoc.hansudung,sizeof(thuoc.hansudung),stdin);
            printf("Tac dung:");
            fgets(thuoc.tacdung,sizeof(thuoc.tacdung),stdin);
            printf("So luong: ");
            scanf("%d",&thuoc.soluong);
            printf("Don gia: ");
            getchar();
            fgets(thuoc.dongia,sizeof(thuoc.dongia),stdin);

            fprintf(tempfile,"Ma so thuoc: %s",thuoc.masothuoc);
            fprintf(tempfile,"Ten thuoc: %s",thuoc.tenthuoc);
            fprintf(tempfile,"Noi san xuat: %s",thuoc.suatxu);
            fprintf(tempfile,"Ngay san xuat: %s",thuoc.ngaysanxuat);
            fprintf(tempfile,"Han su dung: %s",thuoc.hansudung);
            fprintf(tempfile,"Tac dung: %s",thuoc.tacdung);
            fprintf(tempfile,"So luong; %d",thuoc.soluong);
            fprintf(tempfile,"Don gia: %s",thuoc.dongia);

            for( int i=0; i<8; ++i){
                fgets(line, sizeof(line),infile);
            }
            }else
                    fputs(line,tempfile);
            }
            fclose(infile);
            fclose(tempfile);

            if(found){
                remove("thongtinkhoduoc.txt");
                rename("tempt.txt","thongtinkhoduoc.txt");
                printf("____SUA THONG TIN THANH CONG____\n");
            }
            else{
                printf("Khong tim thay thong tin thuoc voi ma so: %s", masothuoc);
                remove("temp.txt");
            }
         return found;
}

void timThongTinThuoc(){
    FILE *file = fopen("thongtinkhoduoc.txt","r");
    if(file == NULL){
        printf("____KHONG THE MO FILE THONG TIN____\n");
        
    }

    char masothuoc[100];
    char line[256];
    char search_line[150];
    int found =0;
    printf("____TIM KIEM THONG TIN THUOC____\n");
    printf("Nhap ma so thuoc: ");
    getchar();
    fgets(masothuoc,sizeof(masothuoc),stdin);
    snprintf(search_line, sizeof(search_line),"Ma so thuoc: %s",masothuoc);

    while(fgets(line,sizeof(line),stdin)){
        if(strcmp(line, search_line)==0){
            found =1;
            printf("%s", line);
            for ( int i =0 ; i<8;++i){
                if(fgets(line,sizeof(line),stdin))
                    printf("%s", line);
            }
            break;
        }
        
    }
    fclose(file);

    if (!found) {
        printf("____KHONG TIM THAY THONG TIN THUOC____\n");
    }
}


void inDanhSachThuoc(){
    FILE *file = fopen("thongtinkhoduoc.txt","r");
    if( file == NULL){
        printf("____KHONG THE MO FILE THONG TIN____\n");
    }

    char line[256];
    printf("____DANH SACH THUOC____\n");

    while(fgets(line,sizeof(line),file)){
        printf("%s", line);
    }
    fclose(file);
}
int main(){
    int role;
    // BenhNhan benhnhan;
    // BacSi bacsi;
    KhoDuoc khoduoc;
    char usernameDN;
    char passwordDN;
    int vaitro;
    printf(".________________________________.\n");
    printf("|             LOGIN              |\n");
    printf(".________________________________.\n");
    int choice = 0;
    printf("Da co tai khoan? : nhap 1\nChua co tai khoan? : nhap 0\n");
    scanf("%d",&choice);
    if(choice==0)
        TaoTK();
tryagain:
    printf("Vui long nhap ten dang nhap: \n");
    scanf("%s",&usernameDN);
    printf("Vui long nhap mat khau: \n");
    scanf("%s",&passwordDN);
    
    FILE *file = fopen("user.txt", "r");
    if (file != NULL) {
        char fileUsernameDN[100], filePasswordDN[100];
        int vaitro;
        while (fscanf(file,"%s %s %d", fileUsernameDN, filePasswordDN, &vaitro) != EOF) {
            if (strcmp(usernameDN, fileUsernameDN) == 0 && strcmp(passwordDN, filePasswordDN) == 0) {
                role = vaitro;
                fclose(file);
            }
        }
    } else
        printf( "____KHONG THE MO FILE THONG TIN____\n");
    switch (role) 
    {
        case 1: 
        printf("____DANG NHAP THANH CONG VOI VAI TRO BENH NHAN____\n");
        break;
        case 2:
        printf("____DANG NHAP THANH CONG VOI VAI TRO NHA SI____\n");
        break;
        case 3: 
        printf("____DANG NHAP THANH CONG VOI VAI TRO QUAN LI____\n");
        break;
        default: 
        printf("____TAI KHOAN MAT KHAU KHONG CHINH XAC____\n____VUI LONG DANG NHAP LAI____\n");
        goto tryagain;
        break;
    };
    if (role==3)
    {
menu:
        int a;
        printf(".______________________________.\n");
        printf("|             MENU             |\n");
        printf(".______________________________.\n");
        printf("1.QUAN LY TAI KHOAN\n");
        printf("2.QUAN LY BENH NHAN\n");
        printf("3.QUAN LY NHA SI\n");
        printf("4.QUAN LY KHO DUOC\n");
        printf("5.DANG XUAT\n");
        printf("VUI LONG CHON CHUC NANG: ");
        scanf("%d",&a);
        switch (a) {
            case 1:
quanlitaikhoan:
                printf(".______________________________.\n");
                printf("|       QUAN LY TAI KHOAN      |\n");
                printf(".______________________________.\n");
                printf("1.TAO TAI KHOAN\n");
                printf("2.XOA TAI KHOAN\n");
                printf("3.SUA TAI KHOAN\n");
                printf("4.QUAY LAI\n");
                printf("VUI LONG CHON CHUC NANG: ");
                int d;
                scanf("%d",&d);
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
                        printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                        printf("======VUI LONG CHON LAI======\n\n");
                        goto quanlitaikhoan;
                        break;
                }
                goto quanlitaikhoan;
            case 2:
quanlibenhnhan:
                printf(".______________________________.\n");
                printf("|       QUAN LY BENH NHAN      |\n");
                printf(".______________________________.\n");
                printf("1.NHAP THONG TIN BENH NHAN\n");
                printf("2.XOA THONG TIN BENH NHAN\n");
                printf("3.SUA THONG TIN BENH NHAN\n");
                printf("4.TIM THONG TIN BENH NHAN\n");
                printf("5.XEM DANH SACH BENH NHAN\n");
                printf("6.QUAY LAI\n");
                printf("VUI LONG CHON CHUC NANG: ");
                int b;
                scanf("%d",&b);
                switch (b){
                    case 1:
                        nhapThongTinBenhNhan();
                        break;
                    case 2:
                        xoaThongTinBenhNhan();
                        break;
                    case 3:
                        suaThongTinBenhNhan();
                        break;
                    case 4: 
                        timThongTinBenhNhan();
                        break;
                    case 5:
                        inDanhSachBN();
                        break;
                    case 6:
                        goto menu;
                    default:
                        printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                        printf("======VUI LONG CHON LAI======\n");
                        goto quanlibenhnhan;
                        break;
                }
                goto quanlibenhnhan;
            case 3:
quanlibacsi:
                printf(".______________________________.\n");
                printf("|        QUAN LY NHA SI        |\n");
                printf(".______________________________.\n");
                printf("1.NHAP THONG TIN NHA SI\n");
                printf("2.XOA THONG TIN NHA SI\n");
                printf("3.SUA THONG TIN NHA SI\n");
                printf("4.TIM THONG TIN NHA SI\n");
                printf("5.XEM DANH SACH NHA SI\n");
                printf("6.QUAY LAI\n");
                printf("VUI LONG CHON CHUC NANG: ");
                int c;
                scanf("%d",&c);
                switch (c){
                    case 1:
                        nhapThongTinBacSi();
                        break;
                    case 2:
                        xoaThongTinBacSi();
                        break;
                    case 3:
                        suaThongTinBacSi();
                        break;
                    case 4: 
                        timThongTinBacSi();
                        break;
                    case 5:
                        inDanhSachBS();
                        break;
                    case 6:
                        goto menu;
                        break;
                    default:
                        printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                        printf("======VUI LONG CHON LAI======\n");
                        goto quanlibacsi;
                }
                goto quanlibacsi;
            case 4:
quanlikhoduoc:
                printf(".______________________________.\n");
                printf("|        QUAN LY KHO DUOC      |\n");
                printf(".______________________________.\n");
                printf("1.NHAP THONG TIN THUOC\n");
                printf("2.XOA THONG TIN THUOC\n");
                printf("3.SUA THONG TIN THUOC\n");
                printf("4.TIM THONG TIN THUOC\n");
                printf("5.XEM DANH SACH THUOC\n");
                printf("6.QUAY LAI\n");
                printf("VUI LONG CHON CHUC NANG: ");
                int e;
                scanf("%d",&e);
                switch (e){
                    case 1:
                        nhapThongTinThuoc(&khoduoc);
                        break;
                    case 2:
                        xoaThongTinThuoc();
                        break;
                    case 3:
                        suaThongTinThuoc();
                        break;
                    case 4: 
                        timThongTinThuoc();
                        break;
                    case 5:
                        inDanhSachTHUOC();
                        break;
                    case 6:
                        goto menu;
                        break;
                    default:
                        printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                        printf("======VUI LONG CHON LAI======\n");
                        goto quanlikhoduoc;
                        break;
                }
                goto quanlikhoduoc;
                break;
            case 5:
                usernameDN = "";
                passwordDN = "";
                role=0;
                printf("____DANG XUAT THANH CONG____\n");
                goto tryagain;
            default:
                printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                goto menu;
                break;
        }
    }
    if (role == 1){
menu2:
        int a;
        printf(".______________________________.\n");
        printf("|             MENU             |\n");
        printf(".______________________________.\n");
        printf("1.XEM THONG TIN CA NHAN\n");
        printf("2.DOI MAT KHAU\n");
        printf("3.DANG XUAT\n");
        printf("VUI LONG CHON CHUC NANG: ");
        scanf("%d",&a);
        switch (a) {
            case 1:

                char line[50];
                FILE *file = fopen("thongtinbenhnhan.txt", "r");
                if (!file) {
                printf("____KHONG THE MO FILE THONG TIN____\n");
                }

                while (fgets(line, sizeof(line), file)) {
                    line[strcspn(line, "\n")] = 0; // Xóa ký tự newline ở cuối dòng
                    if (strncmp(line, "Ten dang nhap: ", 15) == 0 && strcmp(line + 15, usernameDN) == 0) {
                    printf("____THONG TIN CA NHAN____\n");
                    for (int i = 0; i < 6; i++) {
                        if (fgets(line, sizeof(line), file))
                        printf("%s", line);
                    }
                    } else 
                        printf("____THONG TIN BENH NHAN KHONG TON TAI____\n");
                }
                fclose(file);
                break;
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
                printf("____DANG XUAT THANH CONG____\n");
                goto tryagain;
                break;
            
        }goto menu2;
    }
    if (role == 2)
    {
menu3:
        int a;
        printf("._____________________________.\n");
        printf("|            MENU             |\n");
        printf("._____________________________.\n");
        printf("1.QUAN LI THONG TIN CA NHAN\n");
        printf("2.QUAN LI BENH NHAN\n");
        printf("3.XEM DANH SACH THUOC\n");
        printf("4.DANG XUAT\n");
        printf("VUI LONG CHON CHUC NANG: ");
        scanf("%d",&a);
        switch (a) {
            case 1:{
                printf(".______________________________.\n");
                printf("|  QUAN LI THONG TIN CA NHAN   |\n");
                printf(".______________________________.\n");
                printf("1.XEM THONG TIN CA NHAN\n");
                printf("2.DOI MAT KHAU\n");
                printf("3.QUAY LAI\n");
                printf("VUI LONG CHON CHUC NANG: ");
                int b;
                scanf("%d",&b);
                switch (b) {
                    case 1:
                        char line[50];
                        FILE *file = fopen("thongtinbacsi.txt", "r");
                        if (!file) 
                            printf("____KHONG THE MO FILE THONG TIN____\n");

                        while (fgets(line, sizeof(line), file)) {
                            line[strcspn(line, "\n")] = 0; // Xóa ký tự newline ở cuối dòng
                            if (strncmp(line, "Ten dang nhap: ", 15) == 0 && strcmp(line + 15, usernameDN) == 0) {
                                printf("____THONG TIN CA NHAN____\n");
                            for (int i = 0; i < 8; i++) {
                                if (fgets(line, sizeof(line), file))
                                    printf("%s", line);
                                }
                            } else {
                                printf("____THONG TIN NHA SI KHONG TON TAI____\n");
                                printf("Bam ENTER de quay lai Menu\n");
                                int input = getchar();
                                if (input == '\n')
                                    goto menu3;
                            }
                        }
                        fclose(file);
                        break;
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
                        printf("____CHUC NANG KHONG PHU HOP____\n");
                        goto menu3;
                }
                goto menu3;
            }
            case 2:
quanlibenhnhan2:
                printf(".______________________________.\n");
                printf("|       QUAN LY BENH NHAN      |\n");
                printf(".______________________________.\n");
                printf("1.NHAP THONG TIN BENH NHAN\n");
                printf("2.XOA THONG TIN BENH NHAN\n");
                printf("3.SUA THONG TIN BENH NHAN\n");
                printf("4.TIM THONG TIN BENH NHAN\n");
                printf("5.XEM DANH SACH BENH NHAN\n");
                printf("6.QUAY LAI\n");
                printf("VUI LONG CHON CHUC NANG: ");
                int b;
                scanf("%d",&b);
                switch (b){
                    case 1:
                        nhapThongTinBenhNhan();
                        break;
                    case 2:
                        xoaThongTinBenhNhan();
                        break;
                    case 3:
                        suaThongTinBenhNhan();
                        break;
                    case 4: 
                        timThongTinBenhNhan();
                        break;
                    case 5:
                        inDanhSachBN();
                        break;
                    case 6:
                        goto menu3;
                    default:
                        printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                        printf("======VUI LONG CHON LAI======\n");
                        goto quanlibenhnhan;
                }
                goto quanlibenhnhan2;
                break;
            case 3: 
                inDanhSachTHUOC();
                goto menu2;
            case 4:
                usernameDN="";
                passwordDN="";
                printf("____DANG XUAT THANH CONG____\n");
                goto tryagain;
            default :
                printf("____CHUC NANG KHONG PHU HOP____\n");
                goto menu2;
        }
    }
    return 0;
}; 