#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        return 0;
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
    return found;
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

    KhoDuoc k;
    nhapThongTinThuoc(&k);
    inDanhSachTHUOC();
    xoaThongTinThuoc();
    suaThongTinThuoc();
    inDanhSachTHUOC();
    timThongTinThuoc();
    
}

