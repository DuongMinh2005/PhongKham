#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char tenDangNhap[100];
    char tenBacSi[50];
    int tuoi;
    long maso;
    char diachi[200];
    char chucvu[100];
    char chuyenkhoa[100];
    char kinhnghiem[100];
}BacSi;

void nhapThongTinBacSi(BacSi* nhap){
    printf(".______________________________.\n");
    printf("|     NHAP THONG TIN NHA SI    |\n");
    printf(".______________________________.\n");
    getchar();
    printf("Ten dang nhap: ");
    gets(nhap->tenDangNhap);
    printf("Ten: ");
    gets(nhap->tenBacSi);
    printf("Tuoi: ");
    scanf("%d",&nhap->tuoi);
    printf("Dia chi: ");
    gets(nhap->diachi);
    printf("Ma so: ");
    scanf("%ld",&nhap->maso);
    getchar();
    printf("Chuc vu: ");
    gets(nhap->chucvu);
    printf("Chuyen khoa: ");
    gets(nhap->chuyenkhoa);
    fflush(stdin);
    printf("Kinh nghiem: ");
    gets(nhap->kinhnghiem);

    FILE *file = fopen ("thongtinbacsi.txt","a");
    if(file != NULL){
        fprintf(file,"Ten dang nhap: %s\n", nhap->tenDangNhap);
        fprintf(file, "Ten: %s\n", nhap->tenBacSi);
        fprintf(file, "Tuoi: %d\n", nhap->tuoi);
        fprintf(file, "Ma so: %ld\n", nhap->maso);
        fprintf(file, "Dia chi: %s\n", nhap->diachi);
        fprintf(file, "Chuc vu: %s\n", nhap->chucvu);
        fprintf(file, "Chuyen khoa: %s\n", nhap->chuyenkhoa);
        fprintf(file, "Kinh nghiem: %s\n", nhap->kinhnghiem);
        fprintf(file, "--------------------------------\n");
        fclose(file);
        printf("====NHAP THONG TIN THANH CONG===\n");
    }
    else 
        printf("____KHONG THE MO FILE THONG TIN____\n");
}

void xoaThongTinBacSi(){
        char TenDangNhap[100];
        printf(".______________________________.\n");
        printf("|     XOA THONG TIN NHA SI     |\n");
        printf(".______________________________.\n");
        printf("Nhap ten tai khoan can xoa \n");
        printf("Ten dang nhap: ");
        getchar();
        gets(TenDangNhap);
        TenDangNhap[strcspn(TenDangNhap, "\n")] = '\0';

    FILE *infile = fopen("thongtinbacsi.txt","r");
    FILE *outfile = fopen("tempt.txt","w");
        if( infile == NULL || outfile == NULL){
            printf("____KHONG THE MO FILE THONG TIN____\n");
            if (infile) fclose(infile);
            if (outfile) fclose(outfile);
            return;
        }
        char line[256];
        int found = 0;
        char search_line[150];
        snprintf(search_line, sizeof(search_line),"Ten dang nhap: %s\n", TenDangNhap);

        while(fgets(line,sizeof(line),infile)){
            if(strcmp(line, search_line)==0){
                found = 1;
                for( int i = 0; i < 8; ++i)
                    fgets(line,sizeof(line),infile);
            }
            else{
                fputs(line,outfile);
            }
        }
        fclose(infile);
        fclose(outfile);

        if(found){
            remove("thongtinbacsi.txt");
            rename("tempt.txt","thongtinbacsi.txt");
            printf("===XOA THONG TIN NHA SI THANH CONG===\n");
        }
        else{
            printf("____KHONG TIM THAY TAI KHOAN CAN XOA____\n");
            remove("tempt.txt");
        }
}

void suaThongTinBacSi(){
        char TenDangNhap[100];
        BacSi nhap;
        printf(".______________________________.\n");
        printf("|     SUA THONG TIN NHA SI     |\n");
        printf(".______________________________.\n");
        printf("Vui long nhap ten dang nhap: ");
        getchar();
        gets(TenDangNhap);
        TenDangNhap[strcspn(TenDangNhap, "\n")] = '\0';

    FILE *infile = fopen("thongtinbacsi.txt","r");
    FILE *tempfile = fopen("tempt.txt","w");
        if( infile == NULL || tempfile == NULL ){
            printf("____KHONG THE MO FILE THONG TIN____\n");
            return;
        }
        char line[256];
        char search_line[150];
        int found = 0; //flag
        snprintf(search_line,sizeof(search_line),"Ten dang nhap: %s\n",TenDangNhap);

        while(fgets(line,sizeof(line),infile)){
            if(strcmp(line,search_line) == 0){
                found = 1;
                printf("____NHAP LAI THONG TIN MOI____\n");
                printf("Ten dang nhap: ");
                gets(nhap.tenDangNhap);
                printf("Ten: ");
                gets(nhap.tenBacSi);
                printf("Tuoi: ");
                scanf("%d",&nhap.tuoi);
                printf("Ma so: ");
                scanf("%ld",&nhap.maso);
                getchar();
                printf("Dia chi: ");
                gets(nhap.diachi);
                printf("Chuc vu: ");
                gets(nhap.chucvu);
                printf("Chuyen khoa: ");
                gets(nhap.chuyenkhoa);
                printf("Kinh nghiem: ");
                gets(nhap.kinhnghiem);

                fprintf(tempfile,"Ten dang nhap: %s\n", nhap.tenDangNhap);
                fprintf(tempfile, "Ten: %s\n", nhap.tenBacSi);
                fprintf(tempfile, "Tuoi: %d\n", nhap.tuoi);
                fprintf(tempfile, "Ma so: %ld\n", nhap.maso);
                fprintf(tempfile, "Dia chi: %s\n", nhap.diachi);
                fprintf(tempfile, "Chuc vu: %s\n", nhap.chucvu);
                fprintf(tempfile, "Chuyen khoa: %s\n", nhap.chuyenkhoa);
                fprintf(tempfile, "Kinh nghiem: %s\n", nhap.kinhnghiem);
                fprintf(tempfile, "------------------------------------\n");

                for(int i=0; i<8; ++i){
                    fgets(line, sizeof(line),infile);
                }
            }
            else{
                fputs(line,tempfile);
            }
        }
        fclose(infile);
        fclose(tempfile);
        if(found){
            remove("thongtinbacsi.txt");
            rename("tempt.txt","thongtinbacsi.txt");
            printf("====SUA THONG TIN THANH CONG====\n");
        }
        else{
            printf("Khong tim thay thong tin bac si voi ten dang nhap: %s\n", TenDangNhap);
            remove("temp.txt");
        }
}

void timThongTinBacSi(){
    FILE* file = fopen("thongtinbacsi.txt","r");
    if(file == NULL){
        printf("____KHONG THE MO FILE THONG TIN____\n");
    }

    char TenDangNhap[100];
    char line[256];
    char search_line[150];
    int found = 0;
    printf(".______________________________.\n");
    printf("|   TIM KIEM THONG TIN NHA SI  |\n");
    printf(".______________________________.\n");
    printf("Nhap ten dang nhap: ");
    getchar();
    gets(TenDangNhap);
    snprintf(search_line, sizeof(search_line),"Ten dang nhap: %s\n",TenDangNhap);

    while(fgets(line,sizeof(line),file)){
        if(strcmp(line, search_line) == 0){
            found = 1;
            printf("%s", line);
            for ( int i = 0 ; i < 8; i++){
                if(fgets(line,sizeof(line),file))
                    printf("%s", line);
            }
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("____KHONG TIM THAY THONG NHA SI____\n");
    }
}

void inThongTinBacSi(){
    printf(".______________________________.\n");
    printf("|       DANH SACH NHA SI       |\n");
    printf(".______________________________.\n");
    FILE *file = fopen("thongtinbacsi.txt","r");
    if( file == NULL){
        printf("____KHONG THE MO FILE THONG TIN NHA SI____\n");
    }
    char line[256];
    while(fgets(line,sizeof(line),file)){
        printf("%s", line);
    }
    fclose(file);
}

typedef struct{
    char tenDangNhap[100];
    char ten[50];
    int tuoi;
    char diachi[200];
    char loaiBenh[100];
    long vienPhi;
}BenhNhan;

void nhapThongTinBenhNhan(BenhNhan* nhap){
    printf(".______________________________.\n");
    printf("|   NHAP THONG TIN BENH NHAN   |\n");
    printf(".______________________________.\n");
    getchar();
    printf("Ten dang nhap: ");
    gets(nhap->tenDangNhap);
    printf("Ten: ");
    gets(nhap->ten);
    printf("Tuoi: ");
    scanf("%d",&nhap->tuoi);
    printf("Dia chi: ");
    getchar();
    gets(nhap->diachi);
    printf("Loai benh: ");
    gets(nhap->loaiBenh);
    printf("Vien phi: ");
    scanf("%ld",&nhap->vienPhi);
    getchar();

    FILE *file = fopen ("thongtinbenhnhan.txt","a");
        if(file != NULL){
            fprintf(file,"Ten dang nhap: %s\n", nhap->tenDangNhap);
            fprintf(file, "Ten: %s\n", nhap->ten);
            fprintf(file, "Tuoi: %d\n", nhap->tuoi);
            fprintf(file, "Dia chi: %s\n", nhap->diachi);
            fprintf(file, "Loai benh: %s\n", nhap->loaiBenh);
            fprintf(file, "Vien phi: %ld\n", nhap->vienPhi);
            fprintf(file, "--------------------------------\n");
            fclose(file);
            printf("====NHAP THONG TIN THANH CONG====\n");
        }
        else {
            printf("___KHONG THE MO FILE THONG TIN___\n");
        }
}

void xoaThongTinBenhNhan(){
        char TenDangNhap[100];
        printf(".______________________________.\n");
        printf("|   XOA THONG TIN BENH NHAN    |\n");
        printf(".______________________________.\n");
        printf("Nhap ten tai khoan can xoa: \n");
        getchar();
        printf("Ten dang nhap: ");
        gets(TenDangNhap);

    FILE *infile = fopen("thongtinbenhnhan.txt","r");
    FILE *outfile = fopen("tempt.txt","w");
        if( infile == NULL || outfile == NULL){
            printf("____KHONG THE MO FILE THONG TIN____\n");
            return;
        }
        char line[256];
        int found=0;
        char search_line[150];
        snprintf(search_line, sizeof(search_line),"Ten dang nhap: %s\n", TenDangNhap);

        while(fgets(line,sizeof(line),infile)){
            if(strcmp(line, search_line)==0){
                found = 1;
                for( int i=0; i<6; ++i)
                    fgets(line,sizeof(line),infile);
            }
            else{
                fputs(line,outfile);
            }
        }
        fclose(infile);
        fclose(outfile);

        if(found){
            remove("thongtinbenhnhan.txt");
            rename("tempt.txt","thongtinbenhnhan.txt");
            printf("====XOA THONG TIN BENH NHAN THANH CONG====\n");
        }
        else{
            printf("____KHONG TIM THAY TAI KHOAN BENH NHAN____\n");
            remove("tempt.txt");
        }
}

void suaThongTinBenhNhan(){
        char TenDangNhap[100];
        BenhNhan nhap;
        printf(".______________________________.\n");
        printf("|    SUA THONG TIN BENH NHAN   |\n");
        printf(".______________________________.\n");
        printf("Vui long nhap ten dang nhap: ");
        getchar();
        gets(TenDangNhap);

    FILE *infile = fopen("thongtinbenhnhan.txt","r");
    FILE *tempfile = fopen("tempt.txt","w");
        if( infile == NULL || tempfile == NULL ){
            printf("____KHONG THE MO FILE THONG TIN____\n");
            return;
        }
        char line[256];
        char search_line[150];
        int found = 0; //flag
        snprintf(search_line,sizeof(search_line),"Ten dang nhap: %s\n",TenDangNhap);

        while(fgets(line,sizeof(line),infile)){
            if(strcmp(line, search_line) == 0){
                found = 1;
                printf("____NHAP LAI THONG TIN CHO BENH NHAN____\n");
                printf("Ten dang nhap: ");
                gets(nhap.tenDangNhap);
                printf("Ten: ");
                gets(nhap.ten);
                printf("Tuoi: ");
                scanf("%d",&nhap.tuoi);
                printf("Dia chi: ");
                getchar();
                gets(nhap.diachi);
                printf("Loai benh: ");
                gets(nhap.loaiBenh);
                printf("Vien phi: ");
                scanf("%ld",&nhap.vienPhi);

                fprintf(tempfile,"Ten dang nhap: %s\n", nhap.tenDangNhap);
                fprintf(tempfile, "Ten: %s\n", nhap.ten);
                fprintf(tempfile, "Tuoi: %d\n", nhap.tuoi);
                fprintf(tempfile, "Dia chi: %s\n", nhap.diachi);
                fprintf(tempfile, "Loai benh: %s\n", nhap.loaiBenh);
                fprintf(tempfile, "Vien phi: %ld\n", nhap.vienPhi);
                fprintf(tempfile, "--------------------------------\n");
                for( int i=0; i<6; ++i){
                    fgets(line, sizeof(line),infile);
                }
            }
            else{
                fputs(line,tempfile);
            }
        }
        fclose(infile);
        fclose(tempfile);
        if(found){
            remove("thongtinbenhnhan.txt");
            rename("tempt.txt","thongtinbenhnhan.txt");
            printf("====SUA THONG TIN BENH NHAN THANH CONG====\n");
        }
        else {
            printf("Khong tim thay thong tin benh nhan voi ten dang nhap: %s\n", TenDangNhap);
            remove("temp.txt");
        }
}

void timThongTinBenhNhan(){
    FILE* file = fopen("thongtinbenhnhan.txt","r");
    if(file == NULL){
        printf("____KHONG THE MO FILE THONG TIN____\n");
    }

    char TenDangNhap[100];
    char line[256];
    char search_line[150];
    int found =0;
    printf(".______________________________.\n");
    printf("| TIM KIEM THONG TIN BENH NHAN |\n");
    printf(".______________________________.\n");
    getchar();
    printf("Nhap ten dang nhap: ");
    gets(TenDangNhap);
    snprintf(search_line, sizeof(search_line),"Ten dang nhap: %s\n",TenDangNhap);

    while(fgets(line,sizeof(line),file)){
        if(strcmp(line, search_line) == 0){
            found = 1;
            printf("%s", line);
            for ( int i = 0 ; i < 6; i++){
                if(fgets(line,sizeof(line),file))
                    printf("%s", line);
            }
            break;
        }
        else
        printf("____KHONG TIM THAY THONG BENH NHAN____\n");
    
    }
    fclose(file);
}

void inThongTinBenhNhan(){
    printf(".______________________________.\n");
    printf("|      DANH SACH BENH NHAN     |\n");
    printf(".______________________________.\n");
    FILE *file = fopen("thongtinbenhnhan.txt","r");
    if( file == NULL){
        printf("____KHONG THE MO FILE THONG TIN BENH NHAN____\n");
    }

    char line[256];

    while(fgets(line,sizeof(line),file)){
        printf("%s", line);
    }
    fclose(file);
}

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

void nhapThongTinThuoc(KhoDuoc *thuoc){
    printf(".______________________________.\n");
    printf("|     NHAP THONG TIN THUOC     |\n");
    printf(".______________________________.\n");
    getchar();
    printf("Ma so thuoc: ");
    fgets(thuoc->masothuoc, sizeof(thuoc->masothuoc), stdin);
    thuoc->masothuoc[strcspn(thuoc->masothuoc, "\n")] = 0;

    printf("Ten thuoc: ");
    fgets(thuoc->tenthuoc, sizeof(thuoc->tenthuoc), stdin);
    thuoc->tenthuoc[strcspn(thuoc->tenthuoc, "\n")] = 0;

    printf("Noi san xuat: ");
    fgets(thuoc->suatxu, sizeof(thuoc->suatxu), stdin);
    thuoc->suatxu[strcspn(thuoc->suatxu, "\n")] = 0;

    printf("Ngay san xuat: ");
    fgets(thuoc->ngaysanxuat, sizeof(thuoc->ngaysanxuat), stdin);
    thuoc->ngaysanxuat[strcspn(thuoc->ngaysanxuat, "\n")] = 0;

    printf("Han su dung: ");
    fgets(thuoc->hansudung, sizeof(thuoc->hansudung), stdin);
    thuoc->hansudung[strcspn(thuoc->hansudung, "\n")] = 0;

    printf("Tac dung cua thuoc: ");
    fgets(thuoc->tacdung, sizeof(thuoc->tacdung), stdin);
    thuoc->tacdung[strcspn(thuoc->tacdung, "\n")] = 0;

    printf("So luong: ");
    scanf("%d", &thuoc->soluong);
    getchar(); 
    printf("Don gia: ");
    fgets(thuoc->dongia, sizeof(thuoc->dongia), stdin);
    thuoc->dongia[strcspn(thuoc->dongia, "\n")] = 0;

    FILE *file = fopen("thongtinkhoduoc.txt", "a");
    if (file != NULL) {
        fprintf(file, "Ma so thuoc: %s\n", thuoc->masothuoc);
        fprintf(file, "Ten thuoc: %s\n", thuoc->tenthuoc);
        fprintf(file, "Noi san xuat: %s\n", thuoc->suatxu);
        fprintf(file, "Ngay san xuat: %s\n", thuoc->ngaysanxuat);
        fprintf(file, "Han su dung: %s\n", thuoc->hansudung);
        fprintf(file, "Tac dung cua thuoc: %s\n", thuoc->tacdung);
        fprintf(file, "So luong: %d\n", thuoc->soluong);
        fprintf(file, "Don gia: %s\n", thuoc->dongia);
        fprintf(file, "------------------------------------\n");
        fclose(file);
        printf("====NHAP THONG TIN THANH CONG====\n");
    } else {
        printf("____KHONG THE MO FILE THONG TIN____\n");
    }
}

void xoaThongTinThuoc(){
    char masothuoc[100];
    printf(".______________________________.\n");
    printf("|      XOA THONG TIN THUOC     |\n");
    printf(".______________________________.\n");
    printf("Nhap ma so thuoc: ");
    getchar();
    fgets(masothuoc,sizeof(masothuoc),stdin);

    FILE *infile = fopen("thongtinkhoduoc.txt","r");
    FILE *outfile = fopen("tempt.txt","w");
        if( infile ==NULL || outfile ==NULL){
            printf("____KHONG THE MO FILE THONG TIN____\n");
            return;
        }
        char line[256];
        int found=0;
        char search_line[256];
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
            printf("===XOA THONG TIN THUOC THANH CONG===\n");
        }
        else{
            printf("____KHONG TIM THAY TAI KHOAN CAN XOA____\n");
            remove("tempt.txt");
        }
}

void suaThongTinThuoc() {
    char masothuoc[100];
    KhoDuoc thuoc;
    
    printf(".______________________________.\n");
    printf("|      SUA THONG TIN THUOC     |\n");
    printf(".______________________________.\n");
    printf("Vui long nhap ma so thuoc: ");
    getchar();
    fgets(masothuoc, sizeof(masothuoc), stdin);
    masothuoc[strcspn(masothuoc, "\n")] = 0; 

    FILE *infile = fopen("thongtinkhoduoc.txt", "r");
    FILE *tempfile = fopen("tempt.txt", "w");
    
    if (infile == NULL || tempfile == NULL) {
        printf("____KHONG THE MO FILE THONG TIN____\n");
        return ;
    }

    char line[256];
    char search_line[256];
    int found = 0;
    
    snprintf(search_line, sizeof(search_line), "Ma so thuoc: %s", masothuoc);

    while (fgets(line, sizeof(line), infile)) {
        if (strncmp(line, search_line, strlen(search_line)) == 0) { 
            found = 1;
            printf("____NHAP THONG TIN MOI____\n");
            
            printf("Ma so thuoc: ");
            fgets(thuoc.masothuoc, sizeof(thuoc.masothuoc), stdin);
            thuoc.masothuoc[strcspn(thuoc.masothuoc, "\n")] = 0; 

            printf("Ten thuoc: ");
            fgets(thuoc.tenthuoc, sizeof(thuoc.tenthuoc), stdin);
            thuoc.tenthuoc[strcspn(thuoc.tenthuoc, "\n")] = 0;

            printf("Noi san xuat: ");
            fgets(thuoc.suatxu, sizeof(thuoc.suatxu), stdin);
            thuoc.suatxu[strcspn(thuoc.suatxu, "\n")] = 0;

            printf("Ngay san xuat: ");
            fgets(thuoc.ngaysanxuat, sizeof(thuoc.ngaysanxuat), stdin);
            thuoc.ngaysanxuat[strcspn(thuoc.ngaysanxuat, "\n")] = 0;

            printf("Han su dung: ");
            fgets(thuoc.hansudung, sizeof(thuoc.hansudung), stdin);
            thuoc.hansudung[strcspn(thuoc.hansudung, "\n")] = 0;

            printf("Tac dung: ");
            fgets(thuoc.tacdung, sizeof(thuoc.tacdung), stdin);
            thuoc.tacdung[strcspn(thuoc.tacdung, "\n")] = 0;

            printf("So luong: ");
            scanf("%d", &thuoc.soluong);
            getchar();

            printf("Don gia: ");
            fgets(thuoc.dongia, sizeof(thuoc.dongia), stdin);
            thuoc.dongia[strcspn(thuoc.dongia, "\n")] = 0;

           
            fprintf(tempfile, "Ma so thuoc: %s\n", thuoc.masothuoc);
            fprintf(tempfile, "Ten thuoc: %s\n", thuoc.tenthuoc);
            fprintf(tempfile, "Noi san xuat: %s\n", thuoc.suatxu);
            fprintf(tempfile, "Ngay san xuat: %s\n", thuoc.ngaysanxuat);
            fprintf(tempfile, "Han su dung: %s\n", thuoc.hansudung);
            fprintf(tempfile, "Tac dung: %s\n", thuoc.tacdung);
            fprintf(tempfile, "So luong: %d\n", thuoc.soluong);
            fprintf(tempfile, "Don gia: %s\n", thuoc.dongia);
            fprintf(tempfile, "------------------------------------\n");
            
            for (int i = 0; i < 8; ++i) {
                fgets(line, sizeof(line), infile);
            }
        } else {
            fputs(line, tempfile); 
        }
    }
    fclose(infile);
    fclose(tempfile);
    if (found) {
        remove("thongtinkhoduoc.txt");
        rename("tempt.txt", "thongtinkhoduoc.txt");
        printf("====SUA THONG TIN THANH CONG====\n");
    } else {
        printf("Khong tim thay thong tin thuoc voi ma so: %s\n", masothuoc);
        remove("tempt.txt");
    }
    
}

void timThongTinThuoc() {
    FILE *file = fopen("thongtinkhoduoc.txt", "r");
    if (file == NULL) {
        printf("____KHONG THE MO FILE THONG TIN____\n");
        return;
    }
    int found = 0;
    char masothuoc[100];
    char line[256];
    char search_line[256]; 

    printf(".______________________________.\n");
    printf("|   TIM KIEM THONG TIN THUOC   |\n");
    printf(".______________________________.\n");
    printf("Nhap ma so thuoc: ");
    getchar();
    fgets(masothuoc, sizeof(masothuoc), stdin);
    masothuoc[strcspn(masothuoc, "\n")] = 0; 

    snprintf(search_line, sizeof(search_line), "Ma so thuoc: %s\n", masothuoc);

    while (fgets(line, sizeof(line), file)) {
        if (strcmp(line, search_line) == 0) {
            found = 1;
            printf("%s", line); 

            
            for (int i = 0; i < 7; ++i) {
                if (fgets(line, sizeof(line), file)) {
                    printf("%s", line);
                }
            }
            break;
        }
    }

    fclose(file);
    if (!found) 
        printf("____KHONG TIM THAY THONG TIN THUOC____\n");
}

void inDanhSachTHUOC(){
    printf(".______________________________.\n");
    printf("|       DANH SACH THUOC        |\n");
    printf(".______________________________.\n");
    FILE *file = fopen("thongtinkhoduoc.txt","r");
    if( file == NULL){
        printf("____KHONG THE MO FILE THONG TIN____\n");
    }
    char line[256];

    while(fgets(line,sizeof(line),file)){
        printf("%s", line);
    }
    fclose(file);
}

int main(){
    BenhNhan benhnhan;
    BacSi bacsi;
    KhoDuoc khoduoc;
menu:
        
        printf(".______________________________.\n");
        printf("|             MENU             |\n");
        printf(".______________________________.\n");
        printf("1.QUAN LY BENH NHAN\n");
        printf("2.QUAN LY NHA SI\n");
        printf("3.QUAN LY KHO DUOC\n");
        printf("4.DANG XUAT\n");
        printf("VUI LONG CHON CHUC NANG: ");
        int a;
        scanf("%d",&a);
        switch (a) {
            case 1:
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
                        nhapThongTinBenhNhan(&benhnhan);
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
                        inThongTinBenhNhan();
                        break;
                    case 6:
                        goto menu;
                    default:
                        printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                        printf("======VUI LONG CHON LAI======\n\n");
                        goto quanlibenhnhan;
                        break;
                }
                goto quanlibenhnhan;
            case 2:
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
                        nhapThongTinBacSi(&bacsi);
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
                        inThongTinBacSi();
                        break;
                    case 6:
                        goto menu;
                        break;
                    default:
                        printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                        printf("======VUI LONG CHON LAI======\n\n");
                        goto quanlibacsi;
                }
                goto quanlibacsi;
            case 3:
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
                        printf("======VUI LONG CHON LAI======\n\n");
                        goto quanlikhoduoc;
                        break;
                }
                goto quanlikhoduoc;
                break;
            case 4:
                printf("____DANG XUAT THANH CONG____\n");
                return 0;
            default:
                printf("!!!CHUC NANG KHONG PHU HOP!!!\n");
                printf("======VUI LONG CHON LAI======\n\n");
                goto menu;
        }
        return 0;
    }
    
